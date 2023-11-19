/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file          
 *  \brief        Boot manager application routines
 *
 *  \note         Please note, that this file contains a collection of callback functions to be used with the
 *                Flash Bootloader. These functions may influence the behavior of the bootloader in principle.
 *                Therefore, great care must be taken to verify the correctness of the implementation.
 *                The contents of the originally delivered files are only examples resp. implementation proposals.
 *                With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                admissible by law or statute.
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2015 by Vector Informatik GmbH.                                                  All rights reserved.
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
 *  Christian Baeuerle            CB            Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2015-02-28  CB                       First implementation
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include <string.h>

#include "fbl_apbm.h"
#include "fbl_bm.h"

#if defined( FBL_BM_ENABLE_VERIFICATION )
#include "sec_crc.h"
#endif

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLAPI_BM_VERSION != 0x0200u ) || \
    ( FBLAPI_BM_RELEASE_VERSION != 0x00u )
# error "Error in fbl_apbm.c: Source and header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *   GLOBAL DATA
 **********************************************************************************************************************/
#define FBL_BM_START_SEC_CONST
#include "MemMap.h"

V_MEMROM0 V_MEMROM1_FAR tBmCheckListEntry V_MEMROM2_FAR bmCheckList[] =
{
   /* Check if FBL is valid */
   {
       ApplBmIsValidFbl
      ,ApplBmStartFbl
      ,BmTargetFbl
   },

   /* Check if FBL-Updater is valid */
   {
       ApplBmIsValidFblUpdater
      ,ApplBmStartFblUpdater
      ,BmTargetUpdater
   }
};

/* Size of previous CheckList */

V_MEMROM0 V_MEMROM1_FAR vuint8 V_MEMROM2_FAR kBmNrOfCheckEntries = sizeof(bmCheckList) / sizeof(bmCheckList[0]);
#define FBL_BM_STOP_SEC_CONST
#include "MemMap.h"

#define FBL_BM_START_SEC_CODE
#include "MemMap.h"

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

static tFblResult ApplBmReadMemory(tBmAddress sourceAddress, V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * buffer, tBmLength length);
#if defined( FBL_BM_ENABLE_VERIFICATION )
static SecM_StatusType ApplBmVerification( tBmAddress checkAddress, tBmLength checkLength, SecM_CRCType checkValue );
#endif

/***********************************************************************************************************************
 *   FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  ApplBmReadMemory
 **********************************************************************************************************************/
/*! \brief       Function reads the requested number of bytes from the given address
 **********************************************************************************************************************/
static tFblResult ApplBmReadMemory(tBmAddress sourceAddress, V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * buffer, tBmLength length)
{
   (void)memcpy((void *)(buffer),(V_MEMROM2 void *)(sourceAddress),(size_t)(length));
   return kFblOk;
}

#if defined( FBL_BM_ENABLE_VERIFICATION )
/***********************************************************************************************************************
 *  ApplBmVerification
 **********************************************************************************************************************/
/*! \brief       Implementation of a verification algorithm
 *  \details     This function verifies a given address range
 **********************************************************************************************************************/
static SecM_StatusType ApplBmVerification( tBmAddress checkAddress, tBmLength checkLength, SecM_CRCType checkValue )
{
   SecM_StatusType   result;
   SecM_CRCParamType crcParam;
   SecM_LengthType   currentVerifyCount;
   vuint8            crcBuffer[SEC_VERIFY_BYTES];

   /* Initialize Crc-parameters */
   crcParam.crcState          = SEC_CRC_INIT;
   crcParam.crcSourceBuffer   = crcBuffer;
   crcParam.wdTriggerFct      = V_NULL;

   result = SecM_ComputeCRC(&crcParam);

   crcParam.crcState = SEC_CRC_COMPUTE;

   while (checkLength > 0)
   {
      /* ToDo: Watchdog */

      /* Number of bytes to handle in this pass */
      currentVerifyCount = (checkLength > SEC_VERIFY_BYTES) ? (SecM_LengthType)SEC_VERIFY_BYTES : (SecM_LengthType)checkLength;

      /* Copy data from memory to RAM buffer*/
      (void)ApplBmReadMemory( checkAddress, crcBuffer, currentVerifyCount);

      crcParam.crcByteCount = currentVerifyCount;
      result |= SecM_ComputeCRC(&crcParam);

      checkLength -= currentVerifyCount;
      checkAddress += currentVerifyCount;
   }
   crcParam.crcState = SEC_CRC_FINALIZE;
   (void)SecM_ComputeCRC(&crcParam);

   if (checkValue != crcParam.currentCRC)
   {
      result = SECM_NOT_OK;
   }

   return result;
}
#endif

/***********************************************************************************************************************
 *  ApplBmInit
 **********************************************************************************************************************/
/*! \brief       General bootmanager initilization function
 *  \details     This function is called before any other bootmanager activity is performed
 **********************************************************************************************************************/
void ApplBmInit( void )
{
}

/***********************************************************************************************************************
 *  ApplBmFatalError
 **********************************************************************************************************************/
/*! \brief       Function is called when no valid bootloader/application/updater has been found.
 *  \param[in]   errorCode 
 **********************************************************************************************************************/
void ApplBmFatalError( vuint8 errorCode )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)errorCode;
#endif
   while(1)
   {
      ;
   }
}

/***********************************************************************************************************************
 *  ApplBmExtProgRequest
 **********************************************************************************************************************/
/*! \brief       Check if application has set the reprogramming request flag
 *  \param[in]   handle Indicates type of target application
 *  \return      The return value is used by the boot procedure to determine if the FBL has to be started 
 *                for reprogramming
 **********************************************************************************************************************/
tFblResult ApplBmExtProgRequest( tBmTargetHandle handle )
{
   return kFblFailed;
}

/***********************************************************************************************************************
 *  ApplBmIsValidFblUpdater
 **********************************************************************************************************************/
/*! \brief       Check if updater is valid
 *  \param[in]   handle Indicates type of target application
 *  \return      The return value is used by the boot procedure to determine if the corresponding application can be 
 *                started.
 **********************************************************************************************************************/
tFblResult ApplBmIsValidFblUpdater( tBmTargetHandle handle )
{
   return kFblFailed;
}

/***********************************************************************************************************************
 *  ApplBmStartFblUpdater
 **********************************************************************************************************************/
/*! \brief       Start of updater
 *  \pre         Validity of updater must have been checked before call
 **********************************************************************************************************************/
void ApplBmStartFblUpdater( tBmTargetHandle handle )
{
}

/***********************************************************************************************************************
 *  ApplBmIsValidApplication
 **********************************************************************************************************************/
/*! \brief       Check if application is valid
 *  \param[in]   handle Indicates type of target application
 *  \return      The return value is used by the boot procedure to determine if the corresponding application can be 
 *                started.
 **********************************************************************************************************************/
tFblResult ApplBmIsValidApplication( tBmTargetHandle handle )
{
   return kFblFailed;
}

/***********************************************************************************************************************
 *  ApplBmStartApplication
 **********************************************************************************************************************/
/*! \brief       ApplBmStartApplication
 *  \pre         Validitiy status of application has been checked before call.
 **********************************************************************************************************************/
void ApplBmStartApplication( tBmTargetHandle handle )
{
}

/***********************************************************************************************************************
 *  ApplBmIsValidFbl
 **********************************************************************************************************************/
/*! \brief       Check if FBL is valid
 *  \param[in]   handle Indicates type of target application
 *  \return      The return value is used by the boot procedure to determine if the corresponding application can be 
 *                started.
 **********************************************************************************************************************/
tFblResult ApplBmIsValidFbl( tBmTargetHandle handle )
{
   tFblResult     result;
   tBmInfoHeader  localBmInfoHeader;

   /* Read boot manager information structure of FBL */
   result = ApplBmReadMemory((tBmAddress)FBL_BM_FblBmInfoHdrAddr, (vuint8 *)&localBmInfoHeader, sizeof(tBmInfoHeader) );

   /* Check if magic flag is at the expected address */
   if ((result == kFblOk) && (localBmInfoHeader.bmHdrMagicFlag == 0x12345678u))
   {
      /* ToDo: Check FBL presence pattern */

      /* Check if target handle matches */
      if (localBmInfoHeader.bmTargetHandle != handle)
      {
         result = kFblFailed;
      }
      else
      {
#if defined( FBL_BM_ENABLE_VERIFICATION )
         /* Verify FBL */
         if (localBmInfoHeader.bmCheckLength > 0)
         {
            /* CRC verification is performed when a given check length is not 0. */
            if (ApplBmVerification(localBmInfoHeader.bmCheckStartAddress, localBmInfoHeader.bmCheckLength, 
                  (SecM_CRCType)localBmInfoHeader.bmCheckValue) != SECM_OK)
            {
               result = kFblFailed;
            }
            else
            {
               result = kFblOk;
            }
         }
#else
         result = kFblOk;
#endif /* FBL_BM_ENABLE_VERIFICATION */
      }
   }
   else
   {
      result = kFblFailed;
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplBmStartFbl
 **********************************************************************************************************************/
/*! \brief       Start Flash-Bootloader
 *  \param[in]   handle Indicates type of target application
 *  \pre         Bootloader must be valid
 **********************************************************************************************************************/
void ApplBmStartFbl( tBmTargetHandle handle )
{
   tResetVect fblEntryPoint;

   fblEntryPoint = ((tBmInfoHeader *)FBL_BM_FblBmInfoHdrAddr)->bmHdrEntryPoint;
   fblEntryPoint(); 

   /* Code below is never reached */
}

#define FBL_BM_STOP_SEC_CODE
#include "MemMap.h"

/***********************************************************************************************************************
 *  END OF FILE: FBL_BMTYPES.H
 **********************************************************************************************************************/
