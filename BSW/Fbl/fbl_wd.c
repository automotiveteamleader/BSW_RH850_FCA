/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Watchdog functions
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
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
 *  Achim Strobelt                Ach           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  03.00.00   2018-02-09  Ach     ESCAN00097885    Rework configuration
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLWD_VERSION != 0x0300u ) || \
    ( FBLWD_RELEASE_VERSION != 0x00u )
# error "Error in fbl_wd.c: Source and header file are inconsistent!"
#endif

#if ( FBLWD_VERSION != _FBLWD_VERSION ) || \
    ( FBLWD_RELEASE_VERSION != _FBLWD_RELEASE_VERSION )
# error "Error in fbl_wd.c: Source and v_ver.h are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

# if !defined( kFblGenericEventMargin )
#  define kFblGenericEventMargin (kFblDiagTimeP2Star/2u) /**< Default value for P2 retransmit timings. */
# endif

# define PerformGenericEventAction()         \
   {                                         \
      if (GetRcrRpInProgress()               \
          )                                  \
      {                                      \
         FblCwRetransmitRP();                \
         SetP2Timer(kFblDiagTimeP2Star);     \
      }                                      \
   }  /* PRQA S 3453 */ /* MD_MSR_19.7 */

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

V_MEMRAM0 V_MEMRAM1 vuint16 V_MEMRAM2 P2Timer;     /**< P2 timeout timer, mapped to wdGenericEventTimer in header file */
V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 WDInitFlag;   /**< Watchdog initialized flag */

#if defined( FBL_WATCHDOG_ON )
V_MEMRAM0 V_MEMRAM1 tWdTime V_MEMRAM2 WDTimer;     /**< Counts timer events until next watchdog triggering */

#endif

/***********************************************************************************************************************
 *  EXTERNAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblInitWatchdog
 **********************************************************************************************************************/
/*! \brief      Initialize module
 *  \return     Reports if initialization was successful.
 **********************************************************************************************************************/
#define FBLWD_INIT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
void V_API_NEAR FblInitWatchdog( void )
{
   wdGenericEventTimer = 0x00u;
   SetWDInit();

#if defined( FBL_DEF_ENABLE_NON_KB_MAIN )
   ApplFblWDInit();
#endif /* FBL_DEF_ENABLE_NON_KB_MAIN */
}
#define FBLWD_INIT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  FblLookForWatchdogVoid
 **********************************************************************************************************************/
/*! \brief       Polling of watchdog during longer operations.
 *  \details     This function executes watchdog and timer handling code from RAM. Depending on the Bootloader
 *               configuration, additionally some communication tasks can be handled by this function. The return
 *               value of FblLookForWatchdog() is not returned by this function so it could be used by libraries which
 *               expect a void return value.
 *  \pre         Watchdog code was copied to RAM, watchdog handling is initialized.
 **********************************************************************************************************************/
#define FBLWD_RAMCODE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
void V_API_NEAR FblLookForWatchdogVoid( void )
{
   (void)FblLookForWatchdog();
}
#define FBLWD_RAMCODE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  FblLookForWatchdog
 **********************************************************************************************************************/
/*! \brief       Polling of watchdog during longer operations.
 *  \details     This function executes watchdog and timer handling code from RAM. Depending on the Bootloader
 *               configuration, additionally some communication tasks can be handled by this function.
 *  \pre         Watchdog code was copied to RAM, watchdog handling is initialized.
 *  \return      FBL_NO_TRIGGER if no timer/watchdog expired, FBL_TM_TRIGGERED if the millisecond timer expired,
 *               FBL_WD_TRIGGERED if watchdog handling code was called.
 **********************************************************************************************************************/
#define FBLWD_RAMCODE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
vuint8 V_API_NEAR FblLookForWatchdog( void )
{
   vuint8 retValue = FBL_NO_TRIGGER;

   if (GetWDInit()) /* Check if watchdog already initialized */
   {
      if (FblTimerGet() != 0x00u)   /* PRQA S 0303 */ /* MD_FblSfr_MemoryMappedRegister */
      {
         FblTimerReset(); /* PRQA S 0303 */ /* MD_FblSfr_MemoryMappedRegister */
         retValue |= FBL_TM_TRIGGERED;

         if (wdGenericEventTimer > 0x00u)
         {
            wdGenericEventTimer--;
            if (wdGenericEventTimer < kFblGenericEventMargin)
            {
               /* PRQA S 0303 1 */ /* MD_FblSfr_MemoryMappedRegister */
               PerformGenericEventAction(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
            }
         }

# if defined( FBL_WATCHDOG_ON )
         if (WDTimer != 0x00u)
         {
            WDTimer--;
            if (WDTimer == 0x00u)
            {
               ApplFblWDTrigger();
               WDTimer = FBL_WATCHDOG_TIME;
               retValue |= FBL_WD_TRIGGERED;
            }
         }
# endif /* FBL_WATCHDOG_ON */

         /* Check if the FBL or FD (erase/write) is active */
         if (0u != FblCwIsTimerTaskAllowed())
         {
            /* the FBL is active, this task can now be called e.g. from the FLASH */
            FblCwTimerTask();
         }

# if defined( FBL_WD_TIMER_TASK )
         /* Execute configurable timer task
            Task is not active until timer and watchdog have been initialized
            Has to be executed from RAM or a lock mechanism needs to be implemented in macro to prevent execution while flash
            operations are active  */
         FBL_WD_TIMER_TASK();
# endif /* FBL_WD_TIMER_TASK */
      } /* if (FblTimerGet() != 0x00u) */
   } /* if (GetWDInit()) */

   /* Check if the FBL or FD (erase/write) is active */
   if (0u != FblCwIsStateTaskAllowed())
   {
      /* the FBL is active, this task can now be called e.g. from FLASH */
      FblCwStateTask();
   }

# if defined( FBL_WD_STATE_TASK )
   /* Execute configurable state task
      Task is active immediately and will be executed on every function call
      Has to be executed from RAM or a lock mechanism needs to be implemented in macro to prevent execution while flash
      operations are active  */
   FBL_WD_STATE_TASK();
# endif /* FBL_WD_STATE_TASK */

   return retValue;
}  /* PRQA S 6080 */ /* MD_MSR_STMIF */
#define FBLWD_RAMCODE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  END OF FILE: FBL_WD.C
 **********************************************************************************************************************/
