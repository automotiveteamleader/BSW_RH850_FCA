/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        OEM-specific wrapper for FEE access
 *  -------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/*********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Marco Riedl                   Rie           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2016-02-05  Rie     -                Initial version
 *  02.01.00   2016-03-11  Rie     -                Update to new interface
 *  02.02.00   2016-07-05  Rie     ESCAN00090830    No changes
 *  02.02.01   2016-09-06  Rie     ESCAN00091757    No changes
 *  02.02.02   2016-10-17  Rie     ESCAN00092351    No changes
 *  02.03.00   2017-09-19  Rie     ESCAN00094172    No changes
 *                                 ESCAN00095574    No changes
 *  02.04.00   2017-11-29  Rie     ESCAN00096851    No changes
 *                                 ESCAN00097590    Added constants for Record ID check
 *                                 ESCAN00097591    No changes
 *  02.04.01   2018-01-11  Rie     ESCAN00097944    No changes
 *                                 ESCAN00097953    No changes
 *  02.05.00   2018-02-08  Rie     ESCAN00097770    No changes
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "WrapNv.h"

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

# define WRAPNV_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

CONST(tWrapNvBlockTbl, WRAPNV_CONST) kWrapNvBlockTbl[] =
{
   /* FblGeneral */
   {
      WRAPNV_RECORDACCESS_STRUCTURED,
      WRAPNV_BLOCK_PREFIX(FblGeneral),
      kEepSizeFblGeneral,
      WRAPNV_DATASET_FBLGENERAL,
      NULL_PTR
   },
   /* FblDid */
   {
      WRAPNV_RECORDACCESS_STRUCTURED,
      WRAPNV_BLOCK_PREFIX(FblDid),
      kEepSizeFblDid,
      WRAPNV_DATASET_FBLDID,
      NULL_PTR
   },
   /* FblMetadata */
   {
      WRAPNV_RECORDACCESS_STRUCTURED,
      WRAPNV_BLOCK_PREFIX(FblMetaData),
      kEepSizeFblMetaData,
      WRAPNV_DATASET_FBLMETADATA,
      NULL_PTR
   }
};

CONST(tWrapNvRecordTbl, WRAPNV_CONST) kWrapNvRecordTbl[] =
{
   /* FblGeneral */
   {
      kEepAddressProgReqFlag,
      kEepSizeProgReqFlag,
      &kWrapNvBlockTbl[0u]
   },
   {
      kEepAddressResetResponseFlag,
      kEepSizeResetResponseFlag,
      &kWrapNvBlockTbl[0u]
   },
   {
      kEepAddressValidityFlags,
      kEepSizeValidityFlags,
      &kWrapNvBlockTbl[0u]
   },
   {
      kEepAddressApplValidity,
      kEepSizeApplValidity,
      &kWrapNvBlockTbl[0u]
   },
   {
      kEepAddressApplUpdate,
      kEepSizeApplUpdate,
      &kWrapNvBlockTbl[0u]
   },
   {
      kEepAddressSecAccessDelayFlag,
      kEepSizeSecAccessDelayFlag,
      &kWrapNvBlockTbl[0u]
   },
   {
      kEepAddressSecAccessInvalidCount,
      kEepSizeSecAccessInvalidCount,
      &kWrapNvBlockTbl[0u]
   },
   {
      kEepAddressDcmDslRxTesterSourceAddr,
      kEepSizeDcmDslRxTesterSourceAddr,
      &kWrapNvBlockTbl[0u]
   },
   {
      kEepAddressProgrammingStatus,
      kEepSizeProgrammingStatus,
      &kWrapNvBlockTbl[0u]
   },
   {
      kEepAddressDiagnosticVersion,
      kEepSizeDiagnosticVersion,
      &kWrapNvBlockTbl[0u]
   },

   /* FblDid */
   {
      kEepAddressVehicleManufEcuSwNumber,
      kEepSizeVehicleManufEcuSwNumber,
      &kWrapNvBlockTbl[1u]
   },
   {
      kEepAddressEbomEcuPartNumber,
      kEepSizeEbomEcuPartNumber,
      &kWrapNvBlockTbl[1u]
   },
   {
      kEepAddressCoDePEcuPartNumber,
      kEepSizeCoDePEcuPartNumber,
      &kWrapNvBlockTbl[1u]
   },
   {
      kEepAddressExhaustRegulationTan,
      kEepSizeExhaustRegulationTan,
      &kWrapNvBlockTbl[1u]
   },

   /* FblMetaData */
   {
      kEepAddressFingerprint,
      kEepSizeFingerprint,
      &kWrapNvBlockTbl[2u]
   },
   {
      kEepAddressProgCounter,
      kEepSizeProgCounter,
      &kWrapNvBlockTbl[2u]
   },
   {
      kEepAddressProgAttempts,
      kEepSizeProgAttempts,
      &kWrapNvBlockTbl[2u]
   },
   {
      kEepAddressCRCValue,
      kEepSizeCRCValue,
      &kWrapNvBlockTbl[2u]
   },
   {
      kEepAddressCRCStart,
      kEepSizeCRCStart,
      &kWrapNvBlockTbl[2u]
   },
   {
      kEepAddressCRCLength,
      kEepSizeCRCLength,
      &kWrapNvBlockTbl[2u]
   },
   {
      kEepAddressSoftwareIdentification,
      kEepSizeSoftwareIdentification,
      &kWrapNvBlockTbl[2u]
   },
   {
      kEepAddressSwEbomPartNumber,
      kEepSizeSwEbomPartNumber,
      &kWrapNvBlockTbl[2u]
   },
   {
      kEepAddressMemoryStatus,
      kEepSizeMemoryStatus,
      &kWrapNvBlockTbl[2u]
   }
};

CONST(uint16, WRAPNV_CONST) kWrapNvNrOfBlock = sizeof(kWrapNvBlockTbl) / sizeof(kWrapNvBlockTbl[0u]);
CONST(uint16, WRAPNV_CONST) kWrapNvNrOfRecord = sizeof(kWrapNvRecordTbl) / sizeof(kWrapNvRecordTbl[0u]);

# define WRAPNV_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  END OF FILE: WRAPNV_CFG.C
 **********************************************************************************************************************/
