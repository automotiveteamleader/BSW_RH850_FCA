/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        FBL updater callback routines
 *
 *  \note         Please note, that this file contains a collection of callback functions to be used with the
 *                FBL Updater. These functions may influence the behavior of the updater in principle.
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
 *  Joern Herwig                  JHg           Vector Informatik GmbH
 *  Marco Riedl                   Rie           Vector Informatik GmbH
 *  Quetty Palacios               QPs           Vector Informatik GmbH
 *  Daniel Moessner               DlM           Vector Informatik GmbH
 *  Christian Baeuerle            CB            Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2016-07-22  JHg     -                Initial release
 *  01.01.00   2016-08-18  Rie     ESCAN00091517    Added callback ApplTrcvrNormalMode
 *  01.02.00   2016-09-29  QPs     ESCAN00092111    Added callback functions for LIN
 *  01.03.00   2016-10-14  DlM     ESCAN00092339    Added callout function ApplFblUpdTrcvrNormalMode()
 *  01.03.01   2016-10-20  Rie     ESCAN00092406    No changes
 *  01.03.02   2017-05-10  Rie     ESCAN00095098    Modified comments
 *  01.04.00   2017-07-13  JHg     ESCAN00095882    No changes
 *  01.05.00   2017-08-29  CB      ESCAN00096451    Support for DaVinci Configurator
 *  01.06.00   2018-04-13  JHg     ESCAN00098562    Support ASR 4.3 DET API
 *                         JHg     ESCAN00098985    Added ComM callouts
 **********************************************************************************************************************/

#define UPD_AP

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "upd_ap.h"
#include "upd_main.h"
#include "fbl_inc.h"
# include "Det.h"
# if (DET_ENABLED == STD_ON)
#   include "Can.h"
#   include "CanTp.h"
# endif

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLUPD_AP_VERSION != 0x0106u ) || \
    ( FBLUPD_AP_RELEASE_VERSION != 0x00u )
# error "Error in upd_ap.c: Source and Header file are inconsistent!"
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

/*-- Processing hook functions ---------------------------------------------------------------------------------------*/

/***********************************************************************************************************************
 *  ApplFblUpdInit
 **********************************************************************************************************************/
/*! \brief        First hook function of the update process
 *  \details      In case communication is required during update: start the communication stack here
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdInit( void )
{
   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblUpdSendResponse
 **********************************************************************************************************************/
/*! \brief        Send pending response (RCR-RP)
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdSendResponse( void )
{
   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblUpdPrepareErase
 **********************************************************************************************************************/
/*! \brief        Pre-erase hook (e.g. invalidate FBL for reset-safe operation)
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdPrepareErase( void )
{
   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblUpdFinalizeErase
 **********************************************************************************************************************/
/*! \brief        Post-erase hook
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdFinalizeErase( void )
{
   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblUpdPrepareProgram
 **********************************************************************************************************************/
/*! \brief        Pre-programming hook
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdPrepareProgram( void )
{
   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblUpdFinalizeProgram
 **********************************************************************************************************************/
/*! \brief        Pre-programming hook
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdFinalizeProgram( void )
{
   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblUpdFinalizeVerify
 **********************************************************************************************************************/
/*! \brief        Hook function when the verification was successful
 *  \details      Additional flash operations possible after code verification (e.g. TriCore: write BMIHD)
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdFinalizeVerify( void )
{
   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblUpdInvalidateUpdater
 **********************************************************************************************************************/
/*! \brief        Callback function to invalidate the updater/application
 *  \details      Update validity information of e.g. NV-data
 *  \return       Result of operation
 *                   kFblOk when operation was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdInvalidateUpdater( void )
{
   return kFblOk;
}

#define FBL_UPD_AP_RAMCODE_START_SEC_CODE
#include "MemMap.h"
/***********************************************************************************************************************
 *  ApplFblUpdRemoveAndReset
 **********************************************************************************************************************/
/*! \brief        Last callback function in the update process. This function shall not return.
 *  \details      Removes (invalidates) the updater/application if required and performs a reset.
 *                The function has to be located in RAM when the whole updater should get erased
 *                (this also affects the functionality that is used within this function).
 *  \return       Should never return
 **********************************************************************************************************************/
tFblResult ApplFblUpdRemoveAndReset( void )
{
   FBL_UPD_CALLOUT_RESET_VFP();
   FBL_UPD_CALLOUT_RESET();

   while (1)
   {
      ;
   }

   return kFblFailed;
}
#define FBL_UPD_AP_RAMCODE_STOP_SEC_CODE
#include "MemMap.h"

/*-- Segment handling hook functions ---------------------------------------------------------------------------------*/

/***********************************************************************************************************************
 *  ApplFblUpdGetSegment
 **********************************************************************************************************************/
/*! \brief        Get segment of new FBL referenced by given index
 *  \param[in]    index Index of referenced segment
 *  \param[out]   pSegment Pointer resulting segment information
 *  \return       Result of operation
 *                   kFblOk when referenced segment is available
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdGetSegment( vuintx index, V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegment )
{
   tFblResult result;

   result = kFblFailed;

   if (index < 1u)
   {
      /* Initialize single example segment */
      pSegment->source  = 0x10000u;
      pSegment->target  = 0x0000u;
      pSegment->length  = 0x1000u;

      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblUpdAdjustSegmentProgram
 **********************************************************************************************************************/
/*! \brief        Adjust segments for programming / verification operation
 *  \param[in,out]   pSegmentList Pointer to segment list, first entry contains input segment
 *  \param[in,out]   pSegmentCount Input: Size of segment list
 *                      Output: Number of resulting segments
 *  \return       Result of operation
 *                   kFblOk when segment adjustment was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdAdjustSegmentProgram( V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentList,
   V_MEMRAM1 vuintx V_MEMRAM2 V_MEMRAM3 * pSegmentCount )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)pSegmentList;
#endif
   /* No adjustment performed */
   *pSegmentCount = 1u;

   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblUpdAdjustSegmentValidity
 **********************************************************************************************************************/
/*! \brief        Adjust segments for validation operation
 *  \param[in,out]   pSegmentList Pointer to segment list, first entry contains input segment
 *  \param[in,out]   pSegmentCount Input: Size of segment list
 *                      Output: Number of resulting segments
 *  \return       Result of operation
 *                   kFblOk when segment adjustment was successful
 *                   kFblFailed otherwise
 **********************************************************************************************************************/
tFblResult ApplFblUpdAdjustSegmentValidity( V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentList,
   V_MEMRAM1 vuintx V_MEMRAM2 V_MEMRAM3 * pSegmentCount )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)pSegmentList;
#endif
   /* No special handling for validity range */
   *pSegmentCount = 0u;

   return kFblOk;
}

/*-- Updater callout functions ---------------------------------------------------------------------------------------*/

/***********************************************************************************************************************
 *  ApplFblUpdInitPowerOn
 ***********************************************************************************************************************/
/*! \brief        Initialization callout
 ***********************************************************************************************************************/
void ApplFblUpdInitPowerOn( void )
{
   FBL_UPD_CALLOUT_INIT_POWER_ON_HW();
   FBL_UPD_CALLOUT_INIT_POWER_ON_OEM();
}

/***********************************************************************************************************************
 *  ApplFblUpdSetVfp
 ***********************************************************************************************************************/
/*! \brief        Callout to enable programming voltage
 ***********************************************************************************************************************/
void ApplFblUpdSetVfp( void )
{
}

/***********************************************************************************************************************
*  ApplFblUpdResetVfp
***********************************************************************************************************************/
/*! \brief        Callout to disable programming voltage
 ***********************************************************************************************************************/
void ApplFblUpdResetVfp( void )
{
}

/***********************************************************************************************************************
 *  ApplFblUpdReset
 ***********************************************************************************************************************/
/*! \brief        Callout to perform reset
 ***********************************************************************************************************************/
void ApplFblUpdReset( void )
{
}

/***********************************************************************************************************************
 *  ApplFblUpdTrcvrNormalMode
 **********************************************************************************************************************/
/*! \brief       Activate transceiver if necessary (e.g. pin configuration ENABLE = 1, _STDBY = 1)
 **********************************************************************************************************************/
void ApplFblUpdTrcvrNormalMode( void )
{
}

/***********************************************************************************************************************
 *  ApplFblUpdPrepareResponsePending
 ***********************************************************************************************************************/
/*! \brief        Callout to prepare buffer with response pending (RCR-RP) message
 ***********************************************************************************************************************/
void ApplFblUpdPrepareResponsePending(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pResponse)
{
   /* Prepare RCR-RP for service EcuReset */
   pResponse[0u] = 0x7Fu;
   pResponse[1u] = 0x11u;
   pResponse[2u] = 0x78u;
}

/*-- Other callout functions -----------------------------------------------------------------------------------------*/

/***********************************************************************************************************************
 *  ApplTrcvrNormalMode
 **********************************************************************************************************************/
/*! \brief       Activate transceiver if necessary (e.g. pin configuration ENABLE = 1, _STDBY = 1)
 **********************************************************************************************************************/
void ApplTrcvrNormalMode( void )
{
   /* Leave this function empty */
}

/***********************************************************************************************************************
 *  ApplFblCanBusOff
 **********************************************************************************************************************/
/*! \brief       This call-back function is called if the CAN controller enters bus-off state.
 **********************************************************************************************************************/
void ApplFblCanBusOff( void )
{
}

#if defined( FBL_ENABLE_ASSERTION )
/***********************************************************************************************************************
 *  ApplFblFatalError
 **********************************************************************************************************************/
/*! \brief       Will be called in case of an urecoverable error
 **********************************************************************************************************************/
void ApplFblFatalError( FBL_DECL_ASSERT_EXTENDED_INFO(vuint8 errorCode) )
{
   /* Change this variable in debugger in order to return to caller */
   volatile vuint8 stayInWhile = 1u;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)errorCode;
#endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   while (0u != stayInWhile)
   {
      (void)FblLookForWatchdog();
   }
}
#endif /* FBL_ENABLE_ASSERTION */

# define FBL_UPD_AP_RAMCODE_START_SEC_CODE
# include "MemMap.h"

# if (DET_ENABLED == STD_ON)
/***********************************************************************************************************************
 *  ApplFbl_DetEntryHandler
 **********************************************************************************************************************/
/*! \brief       Called by DET module to check if a DET error is intended bootloader behavior or not.
 *  \param[in]   ModuleId Code number of the encountered assertion
 *  \param[in]   InstanceId Name of the affected module (Only if extended info is enabled)
 *  \param[in]   ApiId Line number where the assertion occurred (Only if extended info is enabled)
 *  \param[in]   ErrorId Line number where the assertion occurred (Only if extended info is enabled)
 *  \return      Report if error should be handed over to DET or not
 **********************************************************************************************************************/
#  if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
FUNC(Std_ReturnType, DET_CODE) ApplFbl_DetEntryHandler( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId )
#  else
FUNC(boolean, DET_APPL_CODE) ApplFbl_DetEntryHandler( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId )
#  endif /* DET_AR_RELEASE_ */
{
#  if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
   Std_ReturnType result = E_OK;
   Std_ReturnType ignoreResult = E_NOT_OK;
#  else
   boolean result = FALSE;
   boolean ignoreResult = TRUE;
#  endif /* DET_AR_RELEASE_ */

   switch (ModuleId)
   {
      case CANTP_MODULE_ID:
      {
         switch (ErrorId)
         {
            /* CAN TP errors which can be triggered from outside shouldn't trigger a DET. */
            case CANTP_E_INVALID_RX_BUFFER:
            case CANTP_E_INVALID_RX_LENGTH:
            case CANTP_E_INVALID_TATYPE:
            case CANTP_E_INVALID_FRAME_TYPE:
            case CANTP_E_RX_TIMEOUT_AR:
            case CANTP_E_RX_TIMEOUT_BR:
            case CANTP_E_RX_TIMEOUT_CR:
            case CANTP_E_RX_INVALID_SN:
            case CANTP_E_RX_WFTMAX:
            case CANTP_E_RX_RESTART:
            case CANTP_E_NO_ERROR:
            {
               result = ignoreResult;
               break;
            }
            default:
            {
               break;
            }
         }
         break;
      }
      case CAN_MODULE_ID:
      {
         switch (ErrorId)
         {
            case CAN_E_DATALOST:
            {
               result = ignoreResult;
               break;
            }
            default:
            {
               break;
            }
         }
      }
      default:
      {
         /* Unknown module. Keep error. */
         break;
      }
   }

   return result;
}
# endif /* DET_ENABLED == STD_ON */

# if defined( FBLCW_MODULE_COMM ) && ( FBLCW_MODULE_COMM == STD_ON )
/***********************************************************************************************************************
 *  ApplFbl_ComM_SilentComModeEntered
 **********************************************************************************************************************/
/*! \brief       Indication that silent communication mode has been entered
 *  \param[in]   channel ComM channel index
 **********************************************************************************************************************/
FUNC(void, FBLCW_CODE) ApplFbl_ComM_SilentComModeEntered( NetworkHandleType channel )
{
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)channel;
#  endif
}

/***********************************************************************************************************************
 *  ApplFbl_ComM_NoComModeEntered
 **********************************************************************************************************************/
/*! \brief       Indication that no communication mode has been entered
 *  \param[in]   channel ComM channel index
 **********************************************************************************************************************/
FUNC(void, FBLCW_CODE) ApplFbl_ComM_NoComModeEntered( NetworkHandleType channel )
{
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)channel;
#  endif
}

/***********************************************************************************************************************
 *  ApplFbl_ComM_FullComModeEntered
 **********************************************************************************************************************/
/*! \brief       Indication that full communication mode has been entered
 *  \param[in]   channel ComM channel index
 **********************************************************************************************************************/
FUNC(void, FBLCW_CODE) ApplFbl_ComM_FullComModeEntered( NetworkHandleType channel )
{
#  if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)channel;
#  endif
}
# endif /* FBLCW_MODULE_COMM == STD_ON */

# define FBL_UPD_AP_RAMCODE_STOP_SEC_CODE
# include "MemMap.h"

/***********************************************************************************************************************
 *  END OF FILE: UPD_AP.C
 **********************************************************************************************************************/
