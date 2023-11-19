/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Flash Driver for Renesas RH850 devices with Rv40 flash
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Robert Schaeffner             Rr            Vector Informatik GmbH
 *  Christian Baeuerle            CB            Vector Informatik GmbH
 *  Philip Lapczynski             pla           Vector North America, Inc.
 *  Quetty Palacios               QPs           Vector Informatik GmbH
 *  Dennis O'Donnell              Dod           Vector North America, Inc.
 *  Joern Herwig                  JHg           Vector Informatik GmbH
 *  Christopher Elkins            CEl           Vector North America, Inc.
 *  Joseph Benczarski             Jbi           Vector North America, Inc.
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id          Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  00.90.00   2012-12-18  Rr      ESCAN00063782      Initial version
 *  01.00.00   2013-06-13  CB                         Release
 *  01.01.00   2013-04-01  Rr      ESCAN00072829      Deactivate lock bits handling for flashing
 *  01.02.00   2014-10-23  Rr      ESCAN00076004      Added extended user area support
 *                                                    Added reset vector API to support bootloader updater access
 *                         pla     ESCAN00078538      Added support for IAR compiler
 *  01.02.01   2014-12-08  Rr                         No changes
 *  01.03.00   2015-02-17  Rr      ESCAN00075954      Improved watchdog handling during erase
 *  01.04.00   2015-04-30  QPs     ESCAN00082788      Added support for Renesas compiler
 *  01.05.00   2016-02-26  Dod     ESCAN00085713      Added support for P1x-C FAL library
 *  01.06.00   2016-03-18  QPs     ESCAN00088975      Added support for secondary driver
 *  01.07.00   2017-09-07  JHg     ESCAN00096568      Pass affected core for reset vector change
 *                         JHg     ESCAN00095084      No changes
 *  01.08.00   2017-09-11  CEl     ESCAN00096620      Support reset vector update for flash lib S53
 *  01.09.00   2017-12-13  Jbi     ESCAN00097251      Added support for option byte programming
 *                                 ESCAN00097740      Fixed Reset Vector API switch for secondary driver use-case.
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "flashdrv.h"

#include "r_typedefs.h"
# include "fal_cfg.h"
# include "r_fal_types.h"
# include "r_fal_global.h"
# include "r_fal.h"
# include "r_fal_env.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ((FBLDRVFLASH_RH850RV40HIS_VERSION != 0x0109u)          || \
     (FBLDRVFLASH_RH850RV40HIS_RELEASE_VERSION != 0x00u))
# error "Error in flashdrv.c: Source and header file versions are inconsistent!!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/
/* Re-map FAL */
# define FLASH_SELFID(n) (*(volatile tFlashUint32*)(0xFFA08000ul + ((n)*0x04u))) /**< SELFID Register */  /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define FLASH_CFPEID(n) (*(volatile tFlashUint32*)(0xFFA08060ul + ((n)*0x04u))) /**< CFPEID Register */  /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define FLASH_DFPEID(n) (*(volatile tFlashUint32*)(0xFFA08080ul + ((n)*0x04u))) /**< DFPEID Register */  /* PRQA S 3453 */ /* MD_MSR_19.7 */
/* Re-map library commands */
# define FLASHLIB_CMD_PREPARE_ENV          R_FAL_CMD_PREPARE_ENV
# define FLASHLIB_CMD_CODEF_ERASE          R_FAL_CMD_CODEF_ERASE
# define FLASHLIB_CMD_CODEF_WRITE          R_FAL_CMD_CODEF_WRITE
# define FLASHLIB_CMD_WRITE_CFGAREA        R_FAL_CMD_CODEF_WRITE_CFGAREA
# define FLASHLIB_CMD_READ_CFGAREA         R_FAL_CMD_CODEF_READ_CFGAREA
/* Re-map library status values */
# define FLASHLIB_OK                       R_FAL_OK
# define FLASHLIB_BUSY                     R_FAL_BUSY
/* Re-map library functions */
# define FlashLibInit                      R_FAL_Init
# define FlashLibExecute                   R_FAL_Execute
# define FlashLibHandler                   R_FAL_Handler
# define FlashLibEnLockbit                 R_FAL_Enable_Lockbit
# define FlashLibDisLockbit                R_FAL_Disable_Lockbit
/* Configuration area address offsets */
# define FLASHLIB_CFGAREA_RESET_VECTOR     0x60u

/* Maximum number of cores supported by reset vector API */
#define FLASH_MAX_CORES_RESET_VECTOR      4u

/* Number of Option Byte Registers */
#define FLASH_NUM_OPTIONBYTES             8u

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/** Flash driver header */
typedef struct tagFlashHeader
{
   tFlashUint8    version;             /**< Version of downloaded flash driver      */
   tFlashUint8    reserved;            /**< Reserved for future use                 */
   tFlashUint8    maskType;            /**< Flash cell mask type                    */
   tFlashUint8    CPUType;             /**< Microcontroller type                    */
   tFlashFct      flashInitFct;        /**< Function pointer to init function       */
   tFlashFct      flashDeinitFct;      /**< Function pointer to de-init function    */
   tFlashFct      flashEraseFct;       /**< Function pointer to erase function      */
   tFlashFct      flashWriteFct;       /**< Function pointer to write function      */
#if defined( FLASH_ENABLE_SET_RESETVECTOR_API )
   tFlashFct      flashSetResetFct;    /**< Function pointer to set reset vector    */
#endif /* FLASH_ENABLE_SET_RESETVECTOR_API */
} tFlashHeader; /* PRQA S 3448 */ /* MD_DrvFlash_3448 */

/* Re-map FAL */
typedef r_fal_request_t    tFlashLibRequest;

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/* Flash API functions */
/* PRQA S 3447 12 */ /* MD_DrvFlash_3447 */
void ExpFlashInit ( tFlashParam * flashParam );
void ExpFlashDeinit ( tFlashParam * flashParam );
void ExpFlashErase ( tFlashParam * flashParam );
void ExpFlashWrite ( tFlashParam * flashParam );
#if defined( FLASH_ENABLE_SET_RESETVECTOR_API )
void ExpFlashSetResetVector ( tFlashParam * flashParam );
#endif /* FLASH_ENABLE_SET_RESETVECTOR_API */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/* Other functions */
void AsmDummy( void ); /* PRQA S 3447 */ /* MD_DrvFlash_3447_AsmDummy */
void FblDrvFlashSaveCurFblBasePtr( void ); /* PRQA S 3408 */ /* MD_DrvFlash_3408_AssemberFunction */
void FblDrvFlashSetCurFlashDrvBasePtr( void ); /* PRQA S 3408 */ /* MD_DrvFlash_3408_AssemberFunction */
void FblDrvFlashRestoreCurFblBasePtr( void ); /* PRQA S 3408 */ /* MD_DrvFlash_3408_AssemberFunction */
tFlashUint8 FblDrvFlashCallWatchdog( tFlashUint8 (* wdTriggerFct)(void) ); /* PRQA S 3408 */ /* MD_DrvFlash_3408_AssemberFunction */
static tFlashUint8 FblDrvFlashHandleWD( void );

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

# define NOINIT
# define BREL

/* remember the location of the structure */
BREL NOINIT tFlashParam* pflashParam; /* PRQA S 3408 */ /* MD_DrvFlash_3408 */

/* Local copy of FBL base pointer */
BREL NOINIT unsigned int currentFblGP; /* PRQA S 3408 */ /* MD_DrvFlash_3408 */ /* PRQA S 5013 */ /* MD_DrvFlash_5013 */
BREL NOINIT unsigned int currentFblTP; /* PRQA S 3408 */ /* MD_DrvFlash_3408 */ /* PRQA S 5013 */ /* MD_DrvFlash_5013 */
BREL NOINIT unsigned int currentFblEP; /* PRQA S 3408 */ /* MD_DrvFlash_3408 */ /* PRQA S 5013 */ /* MD_DrvFlash_5013 */

/* PRQA S 3116 LBL_3116 */ /* MD_DrvFlash_3116 */

# pragma ghs startdata
# pragma ghs section rodata=".signature"

/** Flash Driver header */
const tFlashHeader flashHeader = /* PRQA S 3408 */ /* MD_DrvFlash_3408_tFlashHeader */
{
   FLASH_DRIVER_VERSION_INTERFACE,
   0x00u,
   FLASH_DRIVER_VERSION_MASKTYPE,
   FLASH_DRIVER_VERSION_MCUTYPE,
   &ExpFlashInit,
   &ExpFlashDeinit,
   &ExpFlashErase,
   &ExpFlashWrite
#if defined( FLASH_ENABLE_SET_RESETVECTOR_API )
  ,&ExpFlashSetResetVector
#endif /* FLASH_ENABLE_SET_RESETVECTOR_API */
};

# pragma ghs section rodata=default
# pragma ghs enddata

/* PRQA L:LBL_3116 */

/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  AsmDummy
 **********************************************************************************************************************/
/*! \brief         Dummy function to support inline assembler
 *  \details       This function realize 3 functions for context switching between bootloader and flash driver context.
 **********************************************************************************************************************/
void AsmDummy( void ) /* PRQA S 3219 */ /* MD_DrvFlash_3219 */
{
#pragma asm
--/* This function copies the current contents of the register EP             */
--/* into a local copy. This is necessary, because the FBL it self needs to  */
--/* have different values for them since the code was linked with a different*/
--/* mapping.                                                                 */
_FblDrvFlashSaveCurFblBasePtr:
--/* Save r19 on to the stack */
  addi -4,sp,sp
  st.w r19,0[sp]
--/* Store current ep,tp and gp pointer from FBL */
  movhi hi(_currentFblEP),zero,r19
  movea lo(_currentFblEP),r19,r19
  st.w ep,0[r19]
  movhi hi(_currentFblGP),zero,r19
  movea lo(_currentFblGP),r19,r19
  st.w gp,0[r19]
  movhi hi(_currentFblTP),zero,r19
  movea lo(_currentFblTP),r19,r19
  st.w r5,0[r19]
--/* Restore r19 from Stack */
  ld.w 0[sp],r19
  addi 4,sp,sp
  jmp [lp]

--/* This function changes the values of the ep,gp and tp registers to the values*/
--/* used by the flash code. After this function call, the access to global and  */
--/* local variables is possible.                                                */
_FblDrvFlashSetCurFlashDrvBasePtr:
--/* Set ep, tp and gp from flash code */
   -- Initialisation of the global pointer
   movhi hi(___ghsbegin_sdabase+0x8000),zero,gp
   movea lo(___ghsbegin_sdabase+0x8000),gp,gp
   -- Initialisation of the r5 for SDA optimization
   movhi hi(___ghsbegin_rosdata+0x8000),zero,r5
   movea lo(___ghsbegin_rosdata+0x8000),r5,r5
   -- Initialisation of the ep pointer
   movhi hi(___ghsbegin_tdata),zero,ep
   movea lo(___ghsbegin_tdata),ep,ep
   jmp [lp]

--/* This function restores the context of the registers GP,TP and EP to the     */
--/* values which are used by the flash boot loader.                             */
_FblDrvFlashRestoreCurFblBasePtr:
--/* Save r19 on to the stack */
  addi -4,sp,sp
  st.w r19,0[sp]
--/* Restore current ep pointer from FBL */
  movhi hi(_currentFblEP),zero,r19
  movea lo(_currentFblEP),r19,r19
  ld.w 0[r19],ep
  movhi hi(_currentFblTP),zero,r19
  movea lo(_currentFblTP),r19,r19
  ld.w 0[r19],r5
  movhi hi(_currentFblGP),zero,r19
  movea lo(_currentFblGP),r19,r19
  ld.w 0[r19],gp
--/* Restore r19 from Stack */
  ld.w 0[sp],r19
  addi 4,sp,sp
  jmp [lp]
--/* The following function will call the application watchdog function. */
--/* Since the application watchdog function is build with the flash     */
--/* boot loader and not with the flash code, the FBL context of the     */
--/* registers GP,TP and EP must be restored.                            */
_FblDrvFlashCallWatchdog:
--/* Save link pointer because function is called afterwards. */
  addi -4,sp,sp
  st.w lp,0[sp]
--/* The function may access global variables. For this it is necessary to  */
--/* have the related base pointers set correct. So restore the FBL values. */
  jarl _FblDrvFlashRestoreCurFblBasePtr,lp
--/* Restore link pointer from stack. */
  ld.w 0[sp],lp
  addi 4,sp,sp
--/* Now call the watchdog function. Please note, that the function will not */
--/* Return to this point. The function will direct return to the TriggerC   */
--/* function! The restore of the flash code base pointer will also be done  */
--/* there.                                                                  */
  jmp [r6]
#pragma endasm
}

/***********************************************************************************************************************
 *  FblDrvFlashHandleWD
 **********************************************************************************************************************/
/*! \brief         Watchdog function call wrapper
 *  \details       This function realize context switching for calling watchdog function in bootloader context.
 *  \return        Return value of bootloader watchdog function.
 **********************************************************************************************************************/
static tFlashUint8 FblDrvFlashHandleWD( void )
{
   tFlashUint8 tmp;

   tmp = FblDrvFlashCallWatchdog(pflashParam->wdTriggerFct);
   /* Switch to the current valid values of EP,TP and GP */
   FblDrvFlashSetCurFlashDrvBasePtr();

   return tmp;
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  ExpFlashInit
 **********************************************************************************************************************/
/*! \brief         Flash driver initialization
 *  \details       This function initializes the flash driver after download.
 *  \pre           Flash driver present in RAM.
 *  \param[in,out] *flashParam Flash parameter structure
 **********************************************************************************************************************/
void ExpFlashInit ( tFlashParam * flashParam )
{
   tFlashLibRequest libRequest; /* Command structure to access flash library */
   tFlashUint32 index;

   /* Switch to the current valid base pointer(s) */
   FblDrvFlashSaveCurFblBasePtr();
   FblDrvFlashSetCurFlashDrvBasePtr();

   flashParam->errorCode = kFlashInitFailed;

   /* Store the location of flashStruct */
   pflashParam = flashParam;

   /* Report version of downloaded flash driver to Bootloader */
   flashParam->majorVersion         = FLASH_DRIVER_VERSION_MAJOR;
   flashParam->minorVersion         = FLASH_DRIVER_VERSION_MINOR;
   flashParam->patchLevel           = FLASH_DRIVER_VERSION_PATCH;

   for (index = 0u; index < FLASH_AUTH_ID_LENGTH; index++)
   {
      /* Self-ID authentication */
      FLASH_SELFID(index) = flashParam->selfAuthID[index]; /* PRQA S 303 */ /* MD_DrvFlash_0303 */
      /* Code Flash P/E ID authentication */
      FLASH_CFPEID(index) = flashParam->cfpeAuthID[index]; /* PRQA S 303 */ /* MD_DrvFlash_0303 */
      /* Data Flash P/E ID authentication */
      FLASH_DFPEID(index) = flashParam->dfpeAuthID[index]; /* PRQA S 303 */ /* MD_DrvFlash_0303 */
   }

   /* Initialize flash library */
   FlashLibInit(flashParam->frequencyMHz);
   {
      /* prepare environment */
      libRequest.command_enu = FLASHLIB_CMD_PREPARE_ENV;
      FlashLibExecute(&libRequest);
      while (FLASHLIB_BUSY == libRequest.status_enu)
      {
         (void)FblDrvFlashHandleWD();
         FlashLibHandler();
      }
   }

   if (FLASHLIB_OK == libRequest.status_enu)
   {
      /* disable lock bits */
      FlashLibDisLockbit();
   }

   if (FLASHLIB_OK != libRequest.status_enu)
   {
      flashParam->errorCode = kFlashInitFailed | (((tFlashUint16)(libRequest.status_enu)) << 8);
   }
   else
   {
      flashParam->errorCode = kFlashOk;
   }

   /* Switch back to the context of the FBL */
   FblDrvFlashRestoreCurFblBasePtr();
} /* PRQA S 6050 */ /* MD_DrvFlash_6050 */

/***********************************************************************************************************************
 *  ExpFlashDeinit
 **********************************************************************************************************************/
/*! \brief         Flash driver de-initialization
 *  \details       This function de-initializes the flash driver after download.
 *  \pre           Flash driver initialized.
 *  \param[in,out] flashParam Flash parameter structure
 **********************************************************************************************************************/
void ExpFlashDeinit ( tFlashParam * flashParam )
{

   /* Switch to the current valid base pointer(s) */
   FblDrvFlashSaveCurFblBasePtr();
   FblDrvFlashSetCurFlashDrvBasePtr();

   /* Enable lock bits */
   flashParam->errorCode = kFlashOk;
   FlashLibEnLockbit();

   /* Switch back to the context of the FBL */
   FblDrvFlashRestoreCurFblBasePtr();
}

/***********************************************************************************************************************
 *  ExpFlashErase
 **********************************************************************************************************************/
/*! \brief         Flash driver erase function.
 *  \details       This function erases a given flash area.
 *  \pre           Flash driver initialized.
 *  \param[in,out] flashParam Flash parameter structure
 **********************************************************************************************************************/
void ExpFlashErase ( tFlashParam * flashParam )
{
   tFlashLibRequest libRequest; /* Command structure to access flash library */

   /* Switch to the current valid base pointer(s) */
   FblDrvFlashSaveCurFblBasePtr();
   FblDrvFlashSetCurFlashDrvBasePtr();

   /* Store the location of flashStruct */
   pflashParam = flashParam;

   /* Initialize flash error code and error address */
   flashParam->errorCode = kFlashOk;
   flashParam->errorAddress = flashParam->address;
   {
      libRequest.command_enu = FLASHLIB_CMD_CODEF_ERASE;
      libRequest.startAdd_u32 = pflashParam->address;
      libRequest.bytesCnt_u32 = pflashParam->length;

      FlashLibExecute(&libRequest);
      while (FLASHLIB_BUSY == libRequest.status_enu)
      {
         (void)FblDrvFlashHandleWD();
         FlashLibHandler();
      }

      if (FLASHLIB_OK != libRequest.status_enu)
      {
         flashParam->errorCode = kFlashEraseFailed | (((tFlashUint16)(libRequest.status_enu)) << 8u);
      }
      else
      {
         flashParam->errorCode = kFlashOk;
      }
   }

   /* Switch back to the context of the FBL */
   FblDrvFlashRestoreCurFblBasePtr();
}

/***********************************************************************************************************************
 *  ExpFlashWrite
 **********************************************************************************************************************/
/*! \brief         Flash driver write function
 *  \details       This function writes data to flash memory.
 *  \pre           Flash driver initialized, write area has to be erased.
 *  \param[in,out] flashParam Flash parameter structure
 **********************************************************************************************************************/
void ExpFlashWrite ( tFlashParam * flashParam )
{
   tFlashLibRequest libRequest; /* Command structure to access flash library */

   /* Switch to the current valid base pointer(s) */
   FblDrvFlashSaveCurFblBasePtr();
   FblDrvFlashSetCurFlashDrvBasePtr();

   /* Store the location of flashStruct */
   pflashParam = flashParam;
   /* Load current flash position into error address. */
   flashParam->errorAddress = flashParam->address;
   flashParam->errorCode = kFlashOk;

   libRequest.command_enu   = FLASHLIB_CMD_CODEF_WRITE;
   libRequest.bufferAdd_u32 = (tFlashUint32) &(pflashParam->data[0u]); /* PRQA S 306 */ /* MD_DrvFlash_0306 */
   libRequest.startAdd_u32  = pflashParam->address;
   libRequest.bytesCnt_u32  = pflashParam->length;

   FlashLibExecute(&libRequest);
   while (FLASHLIB_BUSY == libRequest.status_enu)
   {
      (void)FblDrvFlashHandleWD();
      FlashLibHandler();
   }

   if (FLASHLIB_OK != libRequest.status_enu)
   {
      flashParam->errorCode = kFlashWriteFailed | (((tFlashUint16)(libRequest.status_enu)) << 8u);
   }
   else
   {
      flashParam->errorCode = kFlashOk;
   }

   /* Switch back to the context of the FBL */
   FblDrvFlashRestoreCurFblBasePtr();
}

#if defined( FLASH_ENABLE_SET_RESETVECTOR_API )
/***********************************************************************************************************************
 *  ExpFlashSetResetVector
 **********************************************************************************************************************/
/*! \brief         Flash driver API extension to set reset vector
 *  \details       This function sets reset vector.
 *  \pre           Flash driver initialized
 *  \param[in,out] flashParam Flash parameter structure
 **********************************************************************************************************************/
void ExpFlashSetResetVector ( tFlashParam * flashParam )
{
   tFlashLibRequest libRequest;              /* Command structure to access flash library */
   tFlashUint32 resetVectorArray[4u];   /* Reset vector structure required by flash library */

   /* Switch to the current valid base pointer(s) */
   FblDrvFlashSaveCurFblBasePtr();
   FblDrvFlashSetCurFlashDrvBasePtr();

   /* Store the location of flashStruct */
   pflashParam = flashParam;
   /* Load current flash position into error address. */
   flashParam->errorAddress = flashParam->address;
   flashParam->errorCode = kFlashOk;

   /* Core index within valid range? */
   if (flashParam->length >= FLASH_MAX_CORES_RESET_VECTOR)
   {
      flashParam->errorCode = kFlashWriteInvalidParam;
   }
   else
   {
      /* Get current reset vector configuration */
      libRequest.command_enu   = FLASHLIB_CMD_READ_CFGAREA;
      libRequest.startAdd_u32  = FLASHLIB_CFGAREA_RESET_VECTOR;
      libRequest.bufferAdd_u32 = (tFlashUint32) &(resetVectorArray);  /* PRQA S 306 */ /* MD_DrvFlash_0306 */

      FlashLibExecute(&libRequest);
      while (FLASHLIB_BUSY == libRequest.status_enu)
      {
         (void)FblDrvFlashHandleWD();
         FlashLibHandler();
      }

      if (FLASHLIB_OK == libRequest.status_enu)
      {
         /* Set reset vector for given core */
         resetVectorArray[flashParam->length] = flashParam->address;

         /* Set updated value */
         libRequest.command_enu   = FLASHLIB_CMD_WRITE_CFGAREA;
         libRequest.startAdd_u32  = FLASHLIB_CFGAREA_RESET_VECTOR;
         libRequest.bufferAdd_u32 = (tFlashUint32) &(resetVectorArray);  /* PRQA S 306 */ /* MD_DrvFlash_0306 */

         FlashLibExecute(&libRequest);
         while (FLASHLIB_BUSY == libRequest.status_enu)
         {
            (void)FblDrvFlashHandleWD();
            FlashLibHandler();
         }
      }

      if (FLASHLIB_OK != libRequest.status_enu)
      {
         flashParam->errorCode = kFlashWriteFailed | (((tFlashUint16)(libRequest.status_enu)) << 8);
      }
      else
      {
         flashParam->errorCode = kFlashOk;
      }
   }

   /* Switch back to the context of the FBL */
   FblDrvFlashRestoreCurFblBasePtr();
}
#endif /* FLASH_ENABLE_SET_RESETVECTOR_API */

/**********************************************************************************************************************
 *  MISRA
 *********************************************************************************************************************/

/* Module specific MISRA deviations:

   MD_DrvFlash_0554:
      Reason: Function is defined in assembly language.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_DrvFlash_0303:
      Reason: Hardware access need pointer as volatile.
      Risk: Access of unknown memory.
      Prevention: Runtime tests.

   MD_DrvFlash_0306:
      Reason: Flash library requires reference to buffer to be stored as unsigned 32-bit value instead
       of pointer type.
      Risk: The size of integer required to hold the result of a pointer cast is implementation defined.
      Prevention: 32 bit handles all current use-cases. Pay special attention when 64 bit ECUs are introduced.

   MD_DrvFlash_3116:
      Reason: Pragmas are compiler specific. This is an hardware and compiler specific module.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_DrvFlash_3219:
      Reason: Function is required for definition of inline assembler functions.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_DrvFlash_3408:
      Reason: Declaration of variables is not in a header file although it is used in a definition or declaration 
              with external linkage. The variables are accessed from inline assembly and can be optimized out if
              they are declared as static variables.  The compiler may not recognize them as being used if they
              are declared statically.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_DrvFlash_3408_tFlashHeader:
      Reason: Declaration of typedef 'tFlashHeader' is not in a header file although it is used in a definition or
              declaration with external linkage. The flashHeader is accessed from the outside using a dedicated set
              of macros and functions.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_DrvFlash_3408_AssemberFunction:
      Reason: Declaration of functions is not in a header file although it is used in a definition or declaration 
              with external linkage. The functions are defined in inline assembly and can be optimized out if
              they are declared as static functions.  The compiler may not recognize them as being used if they
              are declared statically.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_DrvFlash_3447:
      Reason: The function has external linkage but its declaration is not in a header file. The address of the function
              is stored in the flashHeader structure. We do not want the compiler to discard these functions.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_DrvFlash_3447_AsmDummy:
      Reason: Function is required for definition of inline assembler functions.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_DrvFlash_3448:
      Reason: Declaration of typedef 'tFlashHeader' is not in a header file although it is used in a definition or
              declaration with external linkage. The flashHeader is accessed from the outside using a dedicated set
              of macros and functions.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_DrvFlash_5013:
      Reason: Flashdriver should compile without any external dependencies, so typedefs of FBL are not being used.
              Additional typedefs only for flash driver are unnecessary.
      Risk: Size of types is not apparent for programmer.
      Prevention: Programmer has to keep sizes of types in mind for corresponding platform.

   MD_DrvFlash_6050:
     Reason: A typical approach to reduce STCAL is deeper nesting of functions. This approach is not followed due to
             higher voted requirements for minimized stack and runtime usage applied on the code.
     Risk: Understandability and testability might become too complex due to fan-out to many functions. 
     Prevention: Design and code review + clearly structured and commented code.
*/

/***********************************************************************************************************************
 *  END OF FILE: FLASHDRV.C
 **********************************************************************************************************************/
