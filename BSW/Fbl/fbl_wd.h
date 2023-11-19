/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Header file for the watchdog functions
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

#ifndef __FBL_WD_H__
#define __FBL_WD_H__

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblWd CQComponent : Implementation */
#define FBLWD_VERSION            0x0300u
#define FBLWD_RELEASE_VERSION    0x00u

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Return values of LookForWatchdog */
/* Indicates its internal action    */
#define FBL_NO_TRIGGER     0x00u    /* No action performed (just watching the timer) */
#define FBL_WD_TRIGGERED   0x03u    /* Watchdog has been triggered */
#define FBL_TM_TRIGGERED   0x02u    /* Timer has expired and was re-triggered */

/* Macros for watchdog initialization */
#define GetWDInit()        (WDInitFlag == 0x01u)
#define SetWDInit()        (WDInitFlag = 0x01u)
#define ClrWDInit()        (WDInitFlag = 0x00u)

/* Map wdGenericEventTimer to P2 timeout timer */
# define wdGenericEventTimer P2Timer
/* Define P2Timer access macros */
# define GetP2Timer()       (P2Timer)
# define SetP2Timer(val)    (P2Timer = (val))
# define ClrP2Timer()       (P2Timer = 0x00u)

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

V_MEMRAM0 extern V_MEMRAM1 vuint16 V_MEMRAM2 P2Timer;
V_MEMRAM0 extern V_MEMRAM1 vuint8 V_MEMRAM2 WDInitFlag;

#if defined( FBL_WATCHDOG_ON )
# if ( FBL_WATCHDOG_TIME > 255u )
typedef vuint16 tWdTime;
# else
typedef vuint8 tWdTime;
# endif

V_MEMRAM0 extern V_MEMRAM1 tWdTime V_MEMRAM2 WDTimer;
#endif /* FBL_WATCHDOG_ON */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLWD_INIT_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
void V_API_NEAR FblInitWatchdog ( void );
#define FBLWD_INIT_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define FBLWD_RAMCODE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
void V_API_NEAR FblLookForWatchdogVoid( void );
#define FBLWD_RAMCODE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define FBLWD_RAMCODE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
vuint8 V_API_NEAR FblLookForWatchdog( void );
#define FBLWD_RAMCODE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* __FBL_WD_H__ */

/***********************************************************************************************************************
 *  END OF FILE: FBL_WD.H
 **********************************************************************************************************************/
