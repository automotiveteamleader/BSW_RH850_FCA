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
 *  01.02.00   2016-09-29  QPs     ESCAN00092111    No changes
 *  01.03.00   2016-10-14  DlM     ESCAN00092339    Added callout function ApplFblUpdTrcvrNormalMode()
 *  01.03.01   2016-10-20  Rie     ESCAN00092406    Added function declaration of ApplFblUpdAdjustSegmentValidity()
 *  01.03.02   2017-05-10  Rie     ESCAN00095098    Modified comments
 *  01.04.00   2017-07-13  JHg     ESCAN00095882    Updated interface version
 *  01.05.00   2017-08-29  CB      ESCAN00096451    No changes
 *  01.06.00   2018-04-13  JHg     ESCAN00098562    No changes
 *                         JHg     ESCAN00098985    Added ComM callouts
 **********************************************************************************************************************/

#ifndef __UPD_AP_H__
#define __UPD_AP_H__

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblUpd_Ap CQComponent : Implementation */
#define FBLUPD_AP_VERSION              0x0106u
#define FBLUPD_AP_RELEASE_VERSION      0x00u

/* Interface version */
/** Major interface version identifies incompatible changes */
#define FBL_UPD_AP_API_VERSION_MAJOR      0x01u
/** Minor interface version identifies backward compatible changes */
#define FBL_UPD_AP_API_VERSION_MINOR      0x02u
/** Release interface version identifies cosmetic changes */
#define FBL_UPD_AP_API_VERSION_RELEASE    0x00u

/***********************************************************************************************************************
*  INCLUDES
**********************************************************************************************************************/

#include "upd_types.h"
#include "upd_cfg.h"
#include "upd_hw_ap.h"
#include "upd_oem_ap.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/*-- Processing hook functions ---------------------------------------------------------------------------------------*/

void ApplFblUpdInitPowerOn( void );
void ApplFblUpdSetVfp( void );
void ApplFblUpdResetVfp( void );
void ApplFblUpdReset( void );
void ApplFblUpdTrcvrNormalMode( void );

/*-- Segment handling hook functions ---------------------------------------------------------------------------------*/

tFblResult ApplFblUpdGetSegment( vuintx index, V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegment );
tFblResult ApplFblUpdAdjustSegmentProgram( V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentList,
   V_MEMRAM1 vuintx V_MEMRAM2 V_MEMRAM3 * pSegmentCount );
tFblResult ApplFblUpdAdjustSegmentValidity( V_MEMRAM1 tFblUpdSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentList,
   V_MEMRAM1 vuintx V_MEMRAM2 V_MEMRAM3 * pSegmentCount );

/*-- Updater callout functions ---------------------------------------------------------------------------------------*/

tFblResult ApplFblUpdInit( void );
tFblResult ApplFblUpdSendResponse( void );
tFblResult ApplFblUpdPrepareErase( void );
tFblResult ApplFblUpdFinalizeErase( void );
tFblResult ApplFblUpdPrepareProgram( void );
tFblResult ApplFblUpdFinalizeProgram( void );
tFblResult ApplFblUpdFinalizeVerify( void );
tFblResult ApplFblUpdInvalidateUpdater( void );

#define FBL_UPD_AP_RAMCODE_START_SEC_CODE
#include "MemMap.h"
tFblResult ApplFblUpdRemoveAndReset( void );
#define FBL_UPD_AP_RAMCODE_STOP_SEC_CODE
#include "MemMap.h"

void ApplFblUpdPrepareResponsePending( V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pResponse );

/*-- Other callout functions -----------------------------------------------------------------------------------------*/

void ApplTrcvrNormalMode( void );
void ApplFblCanBusOff( void );
#if defined( FBL_ENABLE_ASSERTION )
void ApplFblFatalError( FBL_DECL_ASSERT_EXTENDED_INFO(vuint8 errorCode) );
#endif /* FBL_ENABLE_ASSERTION */

# if defined( FBLCW_MODULE_COMM ) && ( FBLCW_MODULE_COMM == STD_ON )
#  define FBL_UPD_AP_RAMCODE_START_SEC_CODE
#  include "MemMap.h"
FUNC(void, FBLCW_CODE) ApplFbl_ComM_SilentComModeEntered( NetworkHandleType channel );
FUNC(void, FBLCW_CODE) ApplFbl_ComM_NoComModeEntered( NetworkHandleType channel );
FUNC(void, FBLCW_CODE) ApplFbl_ComM_FullComModeEntered( NetworkHandleType channel );
#  define FBL_UPD_AP_RAMCODE_STOP_SEC_CODE
#  include "MemMap.h"
# endif /* FBLCW_MODULE_COMM == STD_ON */

#endif /* __UPD_AP_H__ */

/***********************************************************************************************************************
 *  END OF FILE: UPD_AP.H
 **********************************************************************************************************************/
