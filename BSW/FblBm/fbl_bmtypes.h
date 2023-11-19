/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file          
 *  \brief        Common bootmanager types for boot manager, FBL and Application
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
#ifndef __FBL_BM_TYPES_H__
#define __FBL_BM_TYPES_H__

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#define FBLMAIN_BM_TYPES_VERSION              0x0200u
#define FBLMAIN_BM_TYPES_RELEASE_VERSION      0x00u

/***********************************************************************************************************************
 *  TYPES
 **********************************************************************************************************************/

typedef void V_CALLBACK_NEAR (* tResetVect)(void);
typedef tFblAddress tBmAddress;
typedef tFblLength tBmLength;

typedef enum tagBmTargetHandle
{
   BmTargetNone,
   BmTargetFbl,
   BmTargetUpdater,
   BmTargetApplication,
   BmTargetProgRequest
}tBmTargetHandle;

typedef enum tagBmTypeOfValidation
{
   BmValidNone,
   BmValidPrescencePattern,
   BmValidFlag
}tBmTypeOfValidation;

typedef struct tagBmInfoHeader
{
   vuint32              bmHdrMagicFlag;
   tResetVect           bmHdrEntryPoint;
   tBmTargetHandle      bmTargetHandle;
   tBmTypeOfValidation  bmTypeOfValidation;
   tBmAddress           bmPresPatternAddr;
#if defined( FBL_BM_ENABLE_VERIFICATION )
   /* Bootmanager verification data */
   tBmAddress           bmCheckStartAddress;
   tBmLength            bmCheckLength;
   vuint32              bmCheckValue;
#endif
}tBmInfoHeader;

#endif /* __FBL_BM_TYPES_H__ */

/***********************************************************************************************************************
 *  END OF FILE: FBL_BMTYPES.H
 **********************************************************************************************************************/

