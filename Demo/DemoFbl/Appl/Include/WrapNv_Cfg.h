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
 *  02.01.00   2016-03-11  Rie     -                Fixed macros/defines for EepM use-case
 *                                 -                Update to new interface
 *  02.02.00   2016-07-05  Rie     ESCAN00090830    Added support for no NV driver use-case
 *  02.02.01   2016-09-06  Rie     ESCAN00091757    Fixed MISRA findings
 *  02.02.02   2016-10-17  Rie     ESCAN00092351    Configure used FEE functions
 *  02.03.00   2017-09-19  Rie     ESCAN00094172    No changes
 *                                 ESCAN00095574    Added support for EA
 *  02.04.00   2017-11-29  Rie     ESCAN00096851    No changes
 *                                 ESCAN00097590    Added constants for Record ID check
 *                                 ESCAN00097591    No changes
 *  02.04.01   2018-01-11  Rie     ESCAN00097944    No changes
 *                                 ESCAN00097953    No changes
 *  02.05.00   2018-02-08  Rie     ESCAN00097770    Specify call cycle for main functions
 *********************************************************************************************************************/

#ifndef __WRAPNV_CFG_H__
#define __WRAPNV_CFG_H__

/***********************************************************************************************************************
 *  CONFIGURATION SWITCHES
 **********************************************************************************************************************/

#if defined( WRAPNV_USECASE_FEE )
#else
#  define WRAPNV_USECASE_FEE
#endif

#if defined( WRAPNV_USECASE_FEE )
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

# include "Std_Types.h"
# include "MemIf_Types.h"
# if defined( WRAPNV_USECASE_FEE )
#  include "Fls.h"
#  include "Fee_30_SmallSector.h"
# endif /* WRAPNV_USECASE_* */
# include "fbl_inc.h"

/**********************************************************************************************************************
 *  CONFIGURATION DEFINES
 *********************************************************************************************************************/

# if defined( WRAPNV_USECASE_FEE )
/** Prefix of a NV block */
#  define WRAPNV_BLOCK_PREFIX(value)         FeeConf_FeeBlockConfiguration_ ## value /* PRQA S 0342 */ /* MD_WrapNv_0342 */
/** Function called in synchronous API while waiting for the job to be finished. Also used to get a millisecond cycle. */
#  define WRAPNV_TRIGGER_FCT()               ((FblRealTimeSupport() & FBL_TM_TRIGGERED) == FBL_TM_TRIGGERED)
/** Configure whether the Fee/Fls should be initialized during WrapNv initialization */
#  define WRAPNV_ENABLE_MEM_INITIALIZATION
# endif /* WRAPNV_USECASE_* */

/** Maximum size of all NV blocks */
# define WRAPNV_MAX_BLOCK_LENGTH             0x100u

/** Main function call cycle
 *   0 = Polling
 *  >0 = Millisecond cycle call
 */
# if defined( WRAPNV_USECASE_FEE )
#  define WRAPNV_HWDRV_CYCLE_MAINFUNCTION    0u       /**< Call cylce for HWDRV (Fls/Eep) */
#  define WRAPNV_MEMDRV_CYCLE_MAINFUNCTION   0u       /**< Call cylce for MEMDRV (Fee/Ea) */
# endif

# if defined( WRAPNV_USECASE_FEE )
/** FLS function abstraction */
#  define WRAPNV_HWDRV_INIT                  Fls_Init
#  define WRAPNV_HWDRV_MAINFUNCTION          Fls_MainFunction
/** FLS configuration set used by NV-Wrapper */
#  define WRAPNV_HWDRV_INIT_PARAMETER        FlsConfigSet

/** FEE function abstraction */
#  define WRAPNV_MEMDRV_INIT                 Fee_30_SmallSector_Init
#  define WRAPNV_MEMDRV_GETSTATUS            Fee_30_SmallSector_GetStatus
#  define WRAPNV_MEMDRV_GETJOBRESULT         Fee_30_SmallSector_GetJobResult
#  define WRAPNV_MEMDRV_MAINFUNCTION         Fee_30_SmallSector_MainFunction
#  define WRAPNV_MEMDRV_READ                 Fee_30_SmallSector_Read
#  define WRAPNV_MEMDRV_WRITE                Fee_30_SmallSector_Write
#  define WRAPNV_MEMDRV_INVALIDATEBLOCK      Fee_30_SmallSector_InvalidateBlock
#  define WRAPNV_MEMDRV_CANCEL               Fee_30_SmallSector_Cancel

# endif
#endif

/***********************************************************************************************************************
 *  COMPATIBILITY DEFINES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  DEFINES
 *********************************************************************************************************************/

/*
*                                          DESCRIPTION
*
*   Memory Layout
*   |
*   +-- ProgReqFlag                        Programming request flag
*   |
*   +-- ResetResponseFlag                  Reset response flag
*   |
*   +-- ValidityFlags                      Logical block validity flags
*   |
*   +-- ApplValidity                       Application validity flag
*   |
*   +-- ApplUpdate                         Application update flag
*   |
*   +-- SecAccessDelayFlag                 Security Access Delay flag
*   |
*   +-- SecAccessInvalidCount              Security Access Invalid count
*   |
*   +-- DcmDslRxTesterSourceAddr           Connection for reset response
*   |
*   +-- ProgrammingStatus                  Programming Status Informationn
*   |
*   +-- DiagnosticVersion                  Diagnostic Version of DID F110h
*   |
*   +-- VehicleManufEcuSwNumber            DID F188 - Vehicle Manufacturer ECU Software Number
*   |
*   +-- EbomEcuPartNumber                  DID F132 - EBOM ECU Part Number
*   |
*   +-- CoDePEcuPartNumber                 DID F187 - CoDeP ECU Part Number
*   |
*   +-- ExhaustRegulationTan               DID F196 - Exhaust Regulation or Type Approval Number
*   |
*   +-- 2 x Metadata                       Metadata information for each logical block
*   |   |
*   |   +-- Fingerprint                    Download fingerprint
*   |   |
*   |   +-- ProgCounter                    Successful reprogramming attempts
*   |   |
*   |   +-- ProgAttempts                   Reprogramming attempts
*   |   |
*   |   +-- CRCValue                       CRC total of logical block
*   |   |
*   |   +-- CRCStart                       Start address of CRC total
*   |   |
*   |   +-- CRCLength                      Length of CRC total
*   |   |
*   |   +-- SoftwareIdentification         DID F181 or F182 - Application Software- or Application Data Identification
*   |   |
*   |   +-- SwEbomPartNumber               DID F122 - Software EBOM Part Number
*   |   |
*   |   +-- MemoryStatus                   Memory status; erased, programmed
*/

/* Size defines ************************************************************** */
#define kEepSizeProgReqFlag                  0x01U
#define kEepSizeResetResponseFlag            0x01U
# if defined( kEepSizeValidityFlags )
# else
#  define kEepSizeValidityFlags           0x01U
# endif
//#define kEepSizeValidityFlags                0x01U
/* vadnra compatibility with fbl_apnv.h*/
#define kEepSizeApplValidity                 0x01U
#define kEepSizeApplUpdate                   0x01U
#define kEepSizeSecAccessDelayFlag           0x01U
#define kEepSizeSecAccessInvalidCount        0x01U
#define kEepSizeDcmDslRxTesterSourceAddr     0x02U
#define kEepSizeProgrammingStatus            0x02U
#define kEepSizeDiagnosticVersion            0x02U
#define kEepSizeFblGeneral                   (kEepSizeProgReqFlag + kEepSizeResetResponseFlag + kEepSizeValidityFlags + kEepSizeApplValidity + kEepSizeApplUpdate + kEepSizeSecAccessDelayFlag + kEepSizeSecAccessInvalidCount + kEepSizeDcmDslRxTesterSourceAddr + kEepSizeProgrammingStatus + kEepSizeDiagnosticVersion)

#define kEepSizeVehicleManufEcuSwNumber      0x0BU
#define kEepSizeEbomEcuPartNumber            0x0AU
#define kEepSizeCoDePEcuPartNumber           0x0BU
#define kEepSizeExhaustRegulationTan         0x06U
#define kEepSizeFblDid                       (kEepSizeVehicleManufEcuSwNumber + kEepSizeEbomEcuPartNumber + kEepSizeCoDePEcuPartNumber + kEepSizeExhaustRegulationTan)

#define kEepSizeFingerprint                  0x0DU
#define kEepSizeProgCounter                  0x02U
#define kEepSizeProgAttempts                 0x02U
#define kEepSizeCRCValue                     0x01U
#define kEepSizeCRCStart                     0x01U
#define kEepSizeCRCLength                    0x01U
#define kEepSizeSoftwareIdentification       0x0DU
#define kEepSizeSwEbomPartNumber             0x0BU
#define kEepSizeMemoryStatus                 0x01U
#define kEepSizeFblMetaData                  (kEepSizeFingerprint + kEepSizeProgCounter + kEepSizeProgAttempts + kEepSizeCRCValue + kEepSizeCRCStart + kEepSizeCRCLength + kEepSizeSoftwareIdentification + kEepSizeSwEbomPartNumber + kEepSizeMemoryStatus)

/* Address defines *********************************************************** */
#define kEepAddressProgReqFlag               0u
#define kEepAddressResetResponseFlag         (kEepAddressProgReqFlag + kEepSizeProgReqFlag)
#define kEepAddressValidityFlags             (kEepAddressResetResponseFlag + kEepSizeResetResponseFlag)
#define kEepAddressApplValidity              (kEepAddressValidityFlags + kEepSizeValidityFlags)
#define kEepAddressApplUpdate                (kEepAddressApplValidity + kEepSizeApplValidity)
#define kEepAddressSecAccessDelayFlag        (kEepAddressApplUpdate + kEepSizeApplUpdate)
#define kEepAddressSecAccessInvalidCount     (kEepAddressSecAccessDelayFlag + kEepSizeSecAccessDelayFlag)
#define kEepAddressDcmDslRxTesterSourceAddr  (kEepAddressSecAccessInvalidCount + kEepSizeSecAccessInvalidCount)
#define kEepAddressProgrammingStatus         (kEepAddressDcmDslRxTesterSourceAddr + kEepSizeDcmDslRxTesterSourceAddr)
#define kEepAddressDiagnosticVersion         (kEepAddressProgrammingStatus + kEepSizeProgrammingStatus)

#define kEepAddressVehicleManufEcuSwNumber   0u
#define kEepAddressEbomEcuPartNumber         (kEepAddressVehicleManufEcuSwNumber + kEepSizeVehicleManufEcuSwNumber)
#define kEepAddressCoDePEcuPartNumber        (kEepAddressEbomEcuPartNumber + kEepSizeEbomEcuPartNumber)
#define kEepAddressExhaustRegulationTan         (kEepAddressCoDePEcuPartNumber + kEepSizeCoDePEcuPartNumber)

#define kEepAddressFingerprint               0u
#define kEepAddressProgCounter               (kEepAddressFingerprint + kEepSizeFingerprint)
#define kEepAddressProgAttempts              (kEepAddressProgCounter + kEepSizeProgCounter)
#define kEepAddressCRCValue                  (kEepAddressProgAttempts + kEepSizeProgAttempts)
#define kEepAddressCRCStart                  (kEepAddressCRCValue + kEepSizeCRCValue)
#define kEepAddressCRCLength                 (kEepAddressCRCStart + kEepSizeCRCStart)
#define kEepAddressSoftwareIdentification    (kEepAddressCRCLength + kEepSizeCRCLength)
#define kEepAddressSwEbomPartNumber          (kEepAddressSoftwareIdentification + kEepSizeSoftwareIdentification)
#define kEepAddressMemoryStatus              (kEepAddressSwEbomPartNumber + kEepSizeSwEbomPartNumber)


/* FblGeneral */
#define WRAPNV_DATASET_FBLGENERAL                     1u
#define WRAPNV_RECORD_ID_PROGREQFLAG                  (0u)
#define WRAPNV_RECORD_ID_RESETRESPONSEFLAG            (WRAPNV_RECORD_ID_PROGREQFLAG + 1u)
#define WRAPNV_RECORD_ID_VALIDITYFLAGS                (WRAPNV_RECORD_ID_RESETRESPONSEFLAG + 1u)
#define WRAPNV_RECORD_ID_APPLVALIDITY                 (WRAPNV_RECORD_ID_VALIDITYFLAGS + 1u)
#define WRAPNV_RECORD_ID_APPLUPDATE                   (WRAPNV_RECORD_ID_APPLVALIDITY + 1u)
#define WRAPNV_RECORD_ID_SECACCESSDELAYFLAG           (WRAPNV_RECORD_ID_APPLUPDATE + 1u)
#define WRAPNV_RECORD_ID_SECACCESSINVALIDCOUNT        (WRAPNV_RECORD_ID_SECACCESSDELAYFLAG + 1u)
#define WRAPNV_RECORD_ID_DCMDSLRXTESTERSOURCEADDR     (WRAPNV_RECORD_ID_SECACCESSINVALIDCOUNT + 1u)
#define WRAPNV_RECORD_ID_PROGRAMMINGSTATUS            (WRAPNV_RECORD_ID_DCMDSLRXTESTERSOURCEADDR + 1u)
#define WRAPNV_RECORD_ID_DIAGNOSTICVERSION            (WRAPNV_RECORD_ID_PROGRAMMINGSTATUS + 1u)

/* FblDid */
#define WRAPNV_DATASET_FBLDID                         1u
#define WRAPNV_RECORD_ID_VEHICLEMANUFECUSWNUMBER      (WRAPNV_RECORD_ID_DIAGNOSTICVERSION + 1u)
#define WRAPNV_RECORD_ID_EBOMECUPARTNUMBER            (WRAPNV_RECORD_ID_VEHICLEMANUFECUSWNUMBER + 1u)
#define WRAPNV_RECORD_ID_CODEPECUPARTNUMBER           (WRAPNV_RECORD_ID_EBOMECUPARTNUMBER + 1u)
#define WRAPNV_RECORD_ID_EXHAUSTREGULATIONTAN         (WRAPNV_RECORD_ID_CODEPECUPARTNUMBER + 1u)

/* FblMetaData */
#define WRAPNV_DATASET_FBLMETADATA                    4u
#define WRAPNV_RECORD_ID_FINGERPRINT                  (WRAPNV_RECORD_ID_EXHAUSTREGULATIONTAN + 1u)
#define WRAPNV_RECORD_ID_PROGCOUNTER                  (WRAPNV_RECORD_ID_FINGERPRINT + 1u)
#define WRAPNV_RECORD_ID_PROGATTEMPTS                 (WRAPNV_RECORD_ID_PROGCOUNTER + 1u)
#define WRAPNV_RECORD_ID_CRCVALUE                     (WRAPNV_RECORD_ID_PROGATTEMPTS + 1u)
#define WRAPNV_RECORD_ID_CRCSTART                     (WRAPNV_RECORD_ID_CRCVALUE + 1u)
#define WRAPNV_RECORD_ID_CRCLENGTH                    (WRAPNV_RECORD_ID_CRCSTART + 1u)
#define WRAPNV_RECORD_ID_SOFTWAREIDENTIFICATION       (WRAPNV_RECORD_ID_CRCLENGTH + 1u)
#define WRAPNV_RECORD_ID_SWEBOMPARTNUMBER             (WRAPNV_RECORD_ID_SOFTWAREIDENTIFICATION + 1u)
#define WRAPNV_RECORD_ID_MEMORYSTATUS                 (WRAPNV_RECORD_ID_SWEBOMPARTNUMBER + 1u)

#define WRAPNV_RECORD_ID_MAX                          (WRAPNV_RECORD_ID_MEMORYSTATUS)

/***********************************************************************************************************************
 *  TYPEDEFS
 **********************************************************************************************************************/

/** Specifies how the NV block is configured */
typedef enum
{
   WRAPNV_RECORDACCESS_STRUCTURED = 0u,      /**< NV block consists of several elements */
   WRAPNV_RECORDACCESS_SINGLE                /**< NV block consists of a single element */
} tWrapNvRecordAccess;

/** NV block configuration structure */
typedef struct
{
   tWrapNvRecordAccess blockDataAccess;      /**< Access variat to the NV block */
   uint16 blockNumber;                       /**< Number of NV block */
   uint16 blockLength;                       /**< Length of NV block */
   uint16 blockMaxDatasets;                  /**< Maximum datasets alloweed for the NV block */
   P2CONST(uint8, AUTOMATIC, WRAPNV_CONST) blockDefaultValue;           /**< Default value for NV block */
} tWrapNvBlockTbl;

/** NV record configuration structure */
typedef struct
{
   uint16 recordDataOffset;                  /**< Offset in NV block to the data */
   uint16 recordDataLength;                  /**< Length of data inside the NV block */
   P2CONST(tWrapNvBlockTbl, AUTOMATIC, WRAPNV_CONST) recordBlockPtr;    /**< Pointer to the NV block */
} tWrapNvRecordTbl;

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

extern CONST(tWrapNvRecordTbl, WRAPNV_CONST) kWrapNvRecordTbl[];
extern CONST(uint16, WRAPNV_CONST) kWrapNvNrOfBlock;
extern CONST(uint16, WRAPNV_CONST) kWrapNvNrOfRecord;

/***********************************************************************************************************************
 *  ACCESS MACROS
 **********************************************************************************************************************/

/* FblGeneral */
#define ApplFblNvReadProgReqFlag(buf)                 WrapNv_ReadSync(WRAPNV_RECORD_ID_PROGREQFLAG, 0u, (buf))
#define ApplFblNvWriteProgReqFlag(buf)                WrapNv_WriteSync(WRAPNV_RECORD_ID_PROGREQFLAG, 0u, (buf))

#define ApplFblNvReadResetResponseFlag(buf)           WrapNv_ReadSync(WRAPNV_RECORD_ID_RESETRESPONSEFLAG, 0u, (buf))
#define ApplFblNvWriteResetResponseFlag(buf)          WrapNv_WriteSync(WRAPNV_RECORD_ID_RESETRESPONSEFLAG, 0u, (buf))

#define ApplFblNvReadValidityFlags(buf)               WrapNv_ReadSync(WRAPNV_RECORD_ID_VALIDITYFLAGS, 0u, (buf))
#define ApplFblNvWriteValidityFlags(buf)              WrapNv_WriteSync(WRAPNV_RECORD_ID_VALIDITYFLAGS, 0u, (buf))

#define ApplFblNvReadApplValidity(buf)                WrapNv_ReadSync(WRAPNV_RECORD_ID_APPLVALIDITY, 0u, (buf))
#define ApplFblNvWriteApplValidity(buf)               WrapNv_WriteSync(WRAPNV_RECORD_ID_APPLVALIDITY, 0u, (buf))

#define ApplFblNvReadApplUpdate(buf)                  WrapNv_ReadSync(WRAPNV_RECORD_ID_APPLUPDATE, 0u, (buf))
#define ApplFblNvWriteApplUpdate(buf)                 WrapNv_WriteSync(WRAPNV_RECORD_ID_APPLUPDATE, 0u, (buf))

#define ApplFblNvReadSecAccessDelayFlag(buf)          WrapNv_ReadSync(WRAPNV_RECORD_ID_SECACCESSDELAYFLAG, 0u, (buf))
#define ApplFblNvWriteSecAccessDelayFlag(buf)         WrapNv_WriteSync(WRAPNV_RECORD_ID_SECACCESSDELAYFLAG, 0u, (buf))

#define ApplFblNvReadSecAccessInvalidCount(buf)       WrapNv_ReadSync(WRAPNV_RECORD_ID_SECACCESSINVALIDCOUNT, 0u, (buf))
#define ApplFblNvWriteSecAccessInvalidCount(buf)      WrapNv_WriteSync(WRAPNV_RECORD_ID_SECACCESSINVALIDCOUNT, 0u, (buf))

#define ApplFblNvReadDcmDslRxTesterSourceAddr(buf)    WrapNv_ReadSync(WRAPNV_RECORD_ID_DCMDSLRXTESTERSOURCEADDR, 0u, (buf))
#define ApplFblNvWriteDcmDslRxTesterSourceAddr(buf)   WrapNv_WriteSync(WRAPNV_RECORD_ID_DCMDSLRXTESTERSOURCEADDR, 0u, (buf))

#define ApplFblNvReadProgrammingStatus(buf)           WrapNv_ReadSync(WRAPNV_RECORD_ID_PROGRAMMINGSTATUS, 0u, (buf))
#define ApplFblNvWriteProgrammingStatus(buf)          WrapNv_WriteSync(WRAPNV_RECORD_ID_PROGRAMMINGSTATUS, 0u, (buf))

#define ApplFblNvReadDiagnosticVersion(buf)           WrapNv_ReadSync(WRAPNV_RECORD_ID_DIAGNOSTICVERSION, 0u, (buf))
#define ApplFblNvWriteDiagnosticVersion(buf)          WrapNv_WriteSync(WRAPNV_RECORD_ID_DIAGNOSTICVERSION, 0u, (buf))

/* DID */
#define ApplFblNvReadVehicleManufEcuSwNumber(buf)     WrapNv_ReadSync(WRAPNV_RECORD_ID_VEHICLEMANUFECUSWNUMBER, 0u, (buf))
#define ApplFblNvWriteVehicleManufEcuSwNumber(buf)    WrapNv_WriteSync(WRAPNV_RECORD_ID_VEHICLEMANUFECUSWNUMBER, 0u, (buf))

#define ApplFblNvReadEbomEcuPartNumber(buf)           WrapNv_ReadSync(WRAPNV_RECORD_ID_EBOMECUPARTNUMBER, 0u, (buf))
#define ApplFblNvWriteEbomEcuPartNumber(buf)          WrapNv_WriteSync(WRAPNV_RECORD_ID_EBOMECUPARTNUMBER, 0u, (buf))

#define ApplFblNvReadCoDePEcuPartNumber(buf)          WrapNv_ReadSync(WRAPNV_RECORD_ID_CODEPECUPARTNUMBER, 0u, (buf))
#define ApplFblNvWriteCoDePEcuPartNumber(buf)         WrapNv_WriteSync(WRAPNV_RECORD_ID_CODEPECUPARTNUMBER, 0u, (buf))

#define ApplFblNvReadExhaustRegulationTan(buf)        WrapNv_ReadSync(WRAPNV_RECORD_ID_EXHAUSTREGULATIONTAN, 0u, (buf))
#define ApplFblNvWriteExhaustRegulationTan(buf)       WrapNv_WriteSync(WRAPNV_RECORD_ID_EXHAUSTREGULATIONTAN, 0u, (buf))

/* FblMetaData */
#define ApplFblNvReadFingerprint(idx, buf)            WrapNv_ReadSync(WRAPNV_RECORD_ID_FINGERPRINT, (idx), (buf))
#define ApplFblNvWriteFingerprint(idx, buf)           WrapNv_WriteSync(WRAPNV_RECORD_ID_FINGERPRINT, (idx), (buf))

#define ApplFblNvReadProgCounter(idx, buf)            WrapNv_ReadSync(WRAPNV_RECORD_ID_PROGCOUNTER, (idx), (buf))
#define ApplFblNvWriteProgCounter(idx, buf)           WrapNv_WriteSync(WRAPNV_RECORD_ID_PROGCOUNTER, (idx), (buf))

#define ApplFblNvReadProgAttempts(idx, buf)           WrapNv_ReadSync(WRAPNV_RECORD_ID_PROGATTEMPTS, (idx), (buf))
#define ApplFblNvWriteProgAttempts(idx, buf)          WrapNv_WriteSync(WRAPNV_RECORD_ID_PROGATTEMPTS, (idx), (buf))

#define ApplFblNvReadCRCValue(idx, buf)               WrapNv_ReadSync(WRAPNV_RECORD_ID_CRCVALUE, (idx), (buf))
#define ApplFblNvWriteCRCValue(idx, buf)              WrapNv_WriteSync(WRAPNV_RECORD_ID_CRCVALUE, (idx), (buf))

#define ApplFblNvReadCRCStart(idx, buf)               WrapNv_ReadSync(WRAPNV_RECORD_ID_CRCSTART, (idx), (buf))
#define ApplFblNvWriteCRCStart(idx, buf)              WrapNv_WriteSync(WRAPNV_RECORD_ID_CRCSTART, (idx), (buf))

#define ApplFblNvReadCRCLength(idx, buf)              WrapNv_ReadSync(WRAPNV_RECORD_ID_CRCLENGTH, (idx), (buf))
#define ApplFblNvWriteCRCLength(idx, buf)             WrapNv_WriteSync(WRAPNV_RECORD_ID_CRCLENGTH, (idx), (buf))

#define ApplFblNvReadSoftwareIdentification(idx, buf)    WrapNv_ReadSync(WRAPNV_RECORD_ID_SOFTWAREIDENTIFICATION, (idx), (buf))
#define ApplFblNvWriteSoftwareIdentification(idx, buf)   WrapNv_WriteSync(WRAPNV_RECORD_ID_SOFTWAREIDENTIFICATION, (idx), (buf))

#define ApplFblNvReadSwEbomPartNumber(idx, buf)       WrapNv_ReadSync(WRAPNV_RECORD_ID_SWEBOMPARTNUMBER, (idx), (buf))
#define ApplFblNvWriteSwEbomPartNumber(idx, buf)      WrapNv_WriteSync(WRAPNV_RECORD_ID_SWEBOMPARTNUMBER, (idx), (buf))

#define ApplFblNvReadMemoryStatus(idx, buf)           WrapNv_ReadSync(WRAPNV_RECORD_ID_MEMORYSTATUS, (idx), (buf))
#define ApplFblNvWriteMemoryStatus(idx, buf)          WrapNv_WriteSync(WRAPNV_RECORD_ID_MEMORYSTATUS, (idx), (buf))

#endif /* __WRAPNV_CFG_H__ */

/***********************************************************************************************************************
 *  END OF FILE: WRAPNV_CFG.H
 **********************************************************************************************************************/
