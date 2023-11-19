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
#ifndef __FBL_APBM_H__
#define __FBL_APBM_H__

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblApi_Bm CQComponent : Implementation */
#define FBLAPI_BM_VERSION              0x0200u
#define FBLAPI_BM_RELEASE_VERSION      0x00u

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_bm.h"

/***********************************************************************************************************************
 *   GLOBAL DATA
 **********************************************************************************************************************/

V_MEMROM0 extern  V_MEMROM1_FAR tBmCheckListEntry V_MEMROM2_FAR bmCheckList[];
V_MEMROM0 extern  V_MEMROM1_FAR vuint8 V_MEMROM2_FAR kBmNrOfCheckEntries;

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define FBL_BM_START_SEC_CODE
#include "MemMap.h"

void ApplBmInit( void );
void ApplBmFatalError( vuint8 erroCode );

tFblResult ApplBmIsValidFblUpdater( tBmTargetHandle handle);
void ApplBmStartFblUpdater( tBmTargetHandle handle);

tFblResult ApplBmIsValidApplication( tBmTargetHandle handle);
void ApplBmStartApplication( tBmTargetHandle handle);

tFblResult ApplBmExtProgRequest( tBmTargetHandle handle);
tFblResult ApplBmIsValidFbl( tBmTargetHandle handle);
void ApplBmStartFbl( tBmTargetHandle handle);

#define FBL_BM_STOP_SEC_CODE
#include "MemMap.h"

#endif   /* __FBL_APBM_H__ */
/***********************************************************************************************************************
 *  END OF FILE: FBL_APBM.H
 **********************************************************************************************************************/

