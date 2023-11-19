/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Application information header for Bootloader test
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
 *
 *  \par Note
 *  \verbatim
 *  Please note, that this file contains a collection of callback functions to be used with the Flash Bootloader.
 *  These functions may influence the behavior of the bootloader in principle.
 *  Therefore, great care must be taken to verify the correctness of the implementation.
 *
 *  The contents of the originally delivered files are only examples resp. implementation proposals.
 *  With regard to the fact that these functions are meant for demonstration purposes only, Vector Informatik´s
 *  liability shall be expressly excluded in cases of ordinary negligence, to the extent admissible by law or statute.
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
 *  01.00.00   2018-07-11  CB                       Initial Implementation
 **********************************************************************************************************************/

#ifndef __APPLFBL_H__
#define __APPLFBL_H__

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#define FBL_APPL_DATA_FCA_VERSION           0x0100u
#define FBL_APPL_DATA_FCA_RELEASE_VERSION   0x00u


/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#define kApplInfoSizeLogBlockHash                  20u      /**< Size of logical block hash */
#define kApplInfoSizeLogHashPadding                12u      /**< Number of padding bytes behind the block hash */
#define kApplInfoSizeSwEbomPartNumber              11u      /**<            */
#define kApplInfoSizeEbomEcuPartNumber             10u
#define kApplInfoSizeCodepEcuPartNumber            11u
#define kApplInfoSizeVehicleManEcuSwNumber         11u
#define kApplInfoSizeExhaustRegulationTan           6u
#define kApplInfoSizeSoftwareIdentification        13u

#define kApplInfoSizeSwCompatibility                2u       /**< Size of software compatibility information */
#define kApplInfoSizeHwCompatibilityCount           1u       /**< Size of hardware compatibility counter */
#define kApplInfoSizeHwCompatibility                2u       /**< Size of hardware compatibility information */
#define kApplInfoNumberHwCompatibilityEntries       3u       /**< Number of hardware compatibility field entries */

/* Offsets to start address of structure */
#define kApplInfoOffsetLogBlockHash                0u
#define kApplInfoOffsetLogHashPadding              (kApplInfoOffsetLogBlockHash          + kApplInfoSizeLogBlockHash          )
#define kApplInfoOffsetSwEbomPartNumber            (kApplInfoOffsetLogHashPadding        + kApplInfoSizeLogHashPadding        )
#define kApplInfoOffsetEbomEcuPartNumber           (kApplInfoOffsetSwEbomPartNumber      + kApplInfoSizeSwEbomPartNumber      )
#define kApplInfoOffsetCodepEcuPartNumber          (kApplInfoOffsetEbomEcuPartNumber     + kApplInfoSizeEbomEcuPartNumber     )
#define kApplInfoOffsetVehicleManEcuSwNumber       (kApplInfoOffsetCodepEcuPartNumber    + kApplInfoSizeCodepEcuPartNumber    )
#define kApplInfoOffsetExhaustRegulationTan        (kApplInfoOffsetVehicleManEcuSwNumber + kApplInfoSizeVehicleManEcuSwNumber )
#define kApplInfoOffsetSoftwareIdentification      (kApplInfoOffsetExhaustRegulationTan  + kApplInfoSizeExhaustRegulationTan  )

#define kApplInfoOffsetSwCompatibility             (kApplInfoOffsetSoftwareIdentification+ kApplInfoSizeSoftwareIdentification)
#define kApplInfoOffsetHwCompatibilityCounter      (kApplInfoOffsetSwCompatibility       + kApplInfoSizeSwCompatibility       )
#define kApplInfoOffsetHwCompatibilityField        (kApplInfoOffsetHwCompatibilityCounter+ kApplInfoSizeHwCompatibilityCounter)


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/* Application identification header structure */
typedef struct tagApplInfoHeader
{
   /* D000, D003, D004 - Logical block hash */
   vuint8 blockHash[kApplInfoSizeLogBlockHash];

   /* Padding bytes to ease setting of block hash by external tool */ 
   vuint8 blockHashPadding[kApplInfoSizeLogHashPadding];

   /* F122 - S/W EBOM Part Number */
   vuint8 swEbomPartNumber[kApplInfoSizeSwEbomPartNumber];

   /* F132 - EBOM ECU Part Number */
   vuint8 ebomEcuPartNumber[kApplInfoSizeEbomEcuPartNumber];

   /* F187 - CODEP ECU Part Number*/
   vuint8 codepEcuPartNumber[kApplInfoSizeCodepEcuPartNumber];

   /* F188 - Vehicle Manufacturer ECU Software Number */
   vuint8 vehicleManEcuSwNumber[kApplInfoSizeVehicleManEcuSwNumber];

   /* F196 - Exhaust Regulation or Type Approval Number (Erotan) */
   vuint8 exhaustRegulationTan[kApplInfoSizeExhaustRegulationTan];

   /* F181, F182 - Application Software / Data Identifiction */
   vuint8 softwareIdentification[kApplInfoSizeSoftwareIdentification];

   /* Compatibility information for RoutineControl -checkProgrammingDependencies service */
   /* Software compatibility information */
   vuint8 SwCompatibilityField[kApplInfoSizeSwCompatibility];

   /* Number of compatible hardware verions */
   vuint8 hwCompatibilityCount; 

   /* List of compatible hardware versions */
   vuint8 hwCompatibilityField[kApplInfoSizeHwCompatibility * kApplInfoNumberHwCompatibilityEntries];

}tApplInfoHeader;

# define APPL_FBL_INFO_HEADER_START_SEC_CONST
# include "memmap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
V_MEMROM0 extern V_MEMROM1 tApplInfoHeader V_MEMROM2 applIdentHeader;
# define APPL_FBL_INFO_HEADER_STOP_SEC_CONST
# include "memmap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif  /* __APPLFBL_H__ */

/***********************************************************************************************************************
 *  END OF FILE: APPLFBL.H
 **********************************************************************************************************************/

