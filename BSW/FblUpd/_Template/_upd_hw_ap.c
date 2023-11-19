/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         FBL updater callout routines - Platform specific for RH850
 *
 *  \note          Please note, that this file contains a collection of callback functions to be used with the
 *                 FBL Updater. These functions may influence the behavior of the updater in principle.
 *                 Therefore, great care must be taken to verify the correctness of the implementation.
 *                 The contents of the originally delivered files are only examples resp. implementation proposals.
 *                 With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                 Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                 admissible by law or statute.
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
 *  Sebastian Loos                Shs           Vector Informatik GmbH
 *  Andreas Wenckebach            AWh           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2016-07-27  Shs     -                Initial release
 *  01.00.01   2016-09-01  Shs     ESCAN00091707    Reworked function names, added ApplFblUpdHwInit()
 *  01.01.00   2017-12-01  AWh     ESCAN00097661    Support for flashdriver Api >= 01.07.00
 **********************************************************************************************************************/

#define UPD_AP_HW

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "upd_hw_ap.h"
#include "fbl_inc.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLUPD_AP_RH850_VERSION != 0x0101u ) || \
    ( FBLUPD_AP_RH850_RELEASE_VERSION != 0x00u )
# error "Error in upd_ap_hw.c: Source and Header file are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  ApplFblUpdHwInit
 **********************************************************************************************************************/
/*! \brief       Callback function to initialize hardware specifics
 **********************************************************************************************************************/
void ApplFblUpdHwInit( void ) /* PRQA S 1503 */ /* MD_FblUpd_Ap_Rh850_1503_HwInit */
{
   /* TODO:
    *
    * Initialize the hardware, e.g. PLL, communication port pins, watchdog, timer, ...
    *
    * ATTENTION: If the PLL init is not done in a proper way, the updater will not be reset safe.
    *  -> compare ESCAN00096588: Updater is not reset safe without initializing the PLL [will not get fixed]
    */

#if defined( FBL_UPD_HW_INIT_RH850_PROVIDED )
#else
# error "TODO: Implement ApplFblUpdHwInit() and add commented define FBL_UPD_HW_INIT_RH850_PROVIDED in upd_hw_cfg.h afterwards."
#endif /* FBL_UPD_HW_INIT_RH850_PROVIDED */
}

/***********************************************************************************************************************
 *  ApplFblUpdHwSetVfp
 **********************************************************************************************************************/
/*! \brief       Function is called when the FBL enters programming mode.
 *  \details     Port bits have to be set so that the required programming voltage is available.
 **********************************************************************************************************************/
void ApplFblUpdHwSetVfp( void )
{
   /* Turn on flash programming voltage (VFP) */
   /* FLMD0 Handling:
      The FLMD0 can be handled by internal pull up (default) or external pin.
      How the FLMD0 has to be handled depends on the external wiring/circuit.
      Please keep in mind that a connected NWIRE debugger or FP5 use/drive this wire, too.
      Please check the controller data sheet for further details
   */
   /* PRQA S 0303 TAG_MD_FblUpd_Ap_Rh850_0303_SFR_SetVfp */ /* MD_FblUpd_Ap_Rh850_0303_SFR */
   FBL_PROT_WRITE_FLMDCNT(0x01u);  /* PRQA S 3109 */ /* MD_MSR_14.3 */
   /* PRQA L: TAG_MD_FblUpd_Ap_Rh850_0303_SFR_SetVfp */
}

/***********************************************************************************************************************
 *  ApplFblUpdHwResetVfp
 **********************************************************************************************************************/
/*! \brief       This function is called when the programming is done.
 **********************************************************************************************************************/
void ApplFblUpdHwResetVfp( void )
{
   /* Turn off flash programming voltage (VFP) */
   /* PRQA S 0303 TAG_MD_FblUpd_Ap_Rh850_0303_SFR_ResetVfp */ /* MD_FblUpd_Ap_Rh850_0303_SFR */
   FBL_PROT_WRITE_FLMDCNT(0x00u);  /* PRQA S 3109 */ /* MD_MSR_14.3 */
   /* PRQA L: TAG_MD_FblUpd_Ap_Rh850_0303_SFR_ResetVfp */
}

/***********************************************************************************************************************
 *  ApplFblUpdHwReset
 **********************************************************************************************************************/
/*! \brief       This function performs a reset.
 *  \details     The function will wait until the reset is performed. Please note: This function will
 *               never return to the calling code.
 **********************************************************************************************************************/
void ApplFblUpdHwReset( void )
{
   /* Cause software reset */
   /* PRQA S 0303 TAG_MD_FblUpd_Ap_Rh850_0303_SFR_Reset */ /* MD_FblUpd_Ap_Rh850_0303_SFR */
   FBL_SW_RESET(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
   /* PRQA L: TAG_MD_FblUpd_Ap_Rh850_0303_SFR_Reset */
}

#if defined( FLASH_ENABLE_SET_RESETVECTOR_API )
/***********************************************************************************************************************
 *  ApplFblUpdHwPrepareErase
 **********************************************************************************************************************/
/*! \brief        Pre-erase hook (e.g. invalidate FBL for reset-safe operation)
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdHwPrepareErase( void )
{
   tFblResult result;
   vuint32 updResetVect;

   updResetVect = (vuint32) (FBL_UPD_UPDATER_RESET_VECTOR_ADDR);

   /* Assertion to avoid invalid linkage: Reset Vector must be multiple of 0x200 */
   assertFblInternal(((updResetVect & 0x1FFu) == 0u), kFblSysAssertParameterOutOfRange); /* PRQA S 2214 */ /* MD_FblUpd_Ap_Rh850_2214_Assertion */

   memDrvDeviceActive = kMioDeviceFlash;
   /* TODO by customer: Set reset vector for second core when necessary */
   if (IO_E_OK ==  FlashDriver_SetResetVector((IO_PositionType) updResetVect, FBL_UPD_RESET_VECTOR_CORE))
   {
      result = kFblOk;
   }
   else
   {
      result = kFblFailed;
   }
   memDrvDeviceActive = kMioDeviceIdle;
   return result;
}

/***********************************************************************************************************************
 *  tFblResult ApplFblUpdHwFinalizeVerify( void )
 **********************************************************************************************************************/
/*! \brief        Hook function when the verification was successful
 *  \details      Additional flash operations possible after code verification (e.g. TriCore: write BMIHD)
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdHwFinalizeVerify( void )
{
   tFblResult result;

# if ( ((FBL_UPD_FBL_RESET_VECTOR_ADDR) & 0x1FFu) != 0u )
#  error "FBL_UPD_FBL_RESET_VECTOR_ADDR has to be aligned to multiples of 0x200"
# endif

   memDrvDeviceActive = kMioDeviceFlash;
   /* TODO by customer: Set reset vector for second core when necessary */
   if (IO_E_OK == FlashDriver_SetResetVector ((IO_PositionType) FBL_UPD_FBL_RESET_VECTOR_ADDR, FBL_UPD_RESET_VECTOR_CORE))
   {
      result = kFblOk;
   }
   else
   {
      result = kFblFailed;
   }
   memDrvDeviceActive = kMioDeviceIdle;
   return result;
}
#endif /* defined(FLASH_ENABLE_SET_RESETVECTOR_API) */

/***********************************************************************************************************************
 *  CONFIGURATION CHECKS
 **********************************************************************************************************************/

#if ( FBLDRVFLASH_RH850RV40HIS_VERSION < 0x0107 )
# error "FlashDriver_SetResetVector Api of this module uses parameter only introduced in later version of flashdriver"
#endif /* FBLDRVFLASH_RH850RV40HIS_VERSION  >= 0x0107 */

#if ( !defined( FLASH_ENABLE_SET_RESETVECTOR_API ) )
# error "TODO You have to configure FLASH_ENABLE_SET_RESETVECTOR_API or implement an alternative for a Reset Safe updater"
#endif /* !defined( FLASH_ENABLE_SET_RESETVECTOR_API )*/

/***********************************************************************************************************************
 *  MISRA DEVIATIONS
 **********************************************************************************************************************/
/* module specific MISRA deviations:
   MD_FblUpd_Ap_Rh850_0303_SFR:
      Reason:     Casting of integer to pointer type is required due to memory mapped registers.
      Risk:       The size of integer required to hold the result of a pointer cast is implementation defined.
      Prevention: The size of the respective integer data type which holds the address value is adapted on a hardware
                  specific basis.

   MD_FblUpd_Ap_Rh850_2214_Assertion:
      Reason:     This is an assertion macro used only for debugging in development (FBL_ENABLE_ASSERTION). There should
                  be no need to extend the amount of statements, so the current usage is accepted.
      Risk:       Unintended debugging code behavior could result, through adding further statements,
      Prevention: A comment is in place to avoid that further statements are added to the if condition.

   MD_FblUpd_Ap_Rh850_1503_HwInit:
      Reason:     This function is being called. This is a false finding (through upd_ap.c->ApplFblUpdInitPowerOn()).
      Risk:       -
      Prevention: -

*/

/***********************************************************************************************************************
 *  END OF FILE: UPD_HW_AP.C
 **********************************************************************************************************************/
