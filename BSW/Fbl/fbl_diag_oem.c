/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Diagnostic services supported in boot mode
 *                 Declaration of functions, variables, and constants
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
 *  Christian Bäuerle             CB            Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  00.01.00   2018-01-11  CB      -                Initial implementation 
 *  00.95.00   2018-07-11  CB      -                Pre Release
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Common Bootloader includes */
#include "fbl_inc.h"
/* Core Diagnostic interface and global symbols */
#include "fbl_diag_core.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* Diagnostic OEM module version check */
#if ((FBLDIAG_14229_FCA_VERSION != 0x0095u) || \
     (FBLDIAG_14229_FCA_RELEASE_VERSION != 0x00u))
# error "Error in fbl_diag_oem.c: Source and header file are inconsistent!"
#endif
#if(( FBLDIAG_14229_FCA_VERSION != _FBLDIAG_OEM_VERSION ) || \
    ( FBLDIAG_14229_FCA_RELEASE_VERSION != _FBLDIAG_OEM_RELEASE_VERSION ))
# error "Error in fbl_diag_oem.c: Source and v_ver.h are inconsistent!"
#endif

/***********************************************************************************************************************
 *  TYPE DEFINITIONS
 **********************************************************************************************************************/

#if defined( FBL_DIAG_ENABLE_FLASHDRV_ROM )
/** Structure to initialize flash drivers from ROM */
typedef struct tagFlashDriverInitData
{
   V_MEMROM1 vuint8 V_MEMROM2 V_MEMROM3 * sourceBuffer;  /**< Flash driver image source buffer */
   V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * destBuffer;    /**< Flash driver destination buffer */
   vuint32 copySize;                                     /**< Size of data to be copied */
   vuint8 decryptValue;                                  /**< Value to decrypt XOR-encrypted driver */
} tFlashDriverInitData;
#endif /* FBL_DIAG_ENABLE_FLASHDRV_ROM */

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( FBL_DIAG_FLASH_CODE_BASE_ADDR )
/* Allow to override the flashCode base address for certain platforms.
 * Example: For word-addressed platforms the download address of the flash driver is going to be virtual, i.e. twice
 *          the physical address. For those platforms the base address can be overwritten in a user configuration file. */
#else
# define FBL_DIAG_FLASH_CODE_BASE_ADDR    ((tFblAddress)flashCode)
#endif

#if defined( FBL_ENABLE_UNALIGNED_DATA_TRANSFER )
   /* Report full diagnostic buffer size */
# define FBL_DIAG_RESPONSE_BUFFER_SIZE FBL_DIAG_BUFFER_LENGTH
#else
   /* Calculate buffer size so that a multiple of the diagnostic bufffer size + 2 is reported */
# define FBL_DIAG_RESPONSE_BUFFER_SIZE ((((FBL_DIAG_SEGMENT_SIZE - 1u) ^ 0xFFFFFFFFu) & (FBL_DIAG_BUFFER_LENGTH - 2u)) + 2u)
#endif /* FBL_ENABLE_UNALIGNED_DATA_TRANSFER */

#if( FBL_DIAG_RESPONSE_BUFFER_SIZE >= 0x1000000u )
# define FBL_DIAG_RESPONSE_BUFFER_LFI 4u
#elif( FBL_DIAG_RESPONSE_BUFFER_SIZE >= 0x10000u )
# define FBL_DIAG_RESPONSE_BUFFER_LFI 3u
#else
# define FBL_DIAG_RESPONSE_BUFFER_LFI 2u
#endif

#if !defined( FBL_DIAG_BOOT_TIMOUT_COUNTER )
# define FBL_DIAG_BOOT_TIMOUT_COUNTER     25u         /**< Bootloader application start timeout [ms], < 255ms */
#endif

#if !defined( kFblDiagAddrFormat )
# define kFblDiagAddrFormat               4u
#endif
#if !defined( kFblDiagLengthFormat )        
# define kFblDiagLengthFormat             4u
#endif

/***********************************************************************************************************************
 *  State handling
 **********************************************************************************************************************/
/* Download sequence states */
#define FblDiagSetSecurityKeyAllowed()    SetFblDiagState( kFblDiagStateSecurityKeyAllowed )
#define FblDiagClrSecurityKeyAllowed()    ClrFblDiagState( kFblDiagStateSecurityKeyAllowed )
#define FblDiagSetSecurityUnlock()        SetFblDiagState( kFblDiagStateSecurityUnlock )
#define FblDiagClrSecurityUnlock()        ClrFblDiagState( kFblDiagStateSecurityUnlock )
#define FblDiagSetLogBlockHashRequested() SetFblDiagState( kFblDiagStateLogBlockHashRequested )
#define FblDiagClrLogBlockHashRequested() ClrFblDiagState( kFblDiagStateLogBlockHashRequested )
#define FblDiagSetFingerprintValid()      SetFblDiagState( kFblDiagStateFingerprintValid )
#define FblDiagClrFingerprintValid()      ClrFblDiagState( kFblDiagStateFingerprintValid )
#define FblDiagSetEraseSucceeded()        SetFblDiagState( kFblDiagStateEraseSucceeded )
#define FblDiagClrEraseSucceeded()        ClrFblDiagState( kFblDiagStateEraseSucceeded )
#define FblDiagSetTransferDataAllowed()   SetFblDiagState( kFblDiagStateTransferDataAllowed )
#define FblDiagClrTransferDataAllowed()   ClrFblDiagState( kFblDiagStateTransferDataAllowed )
#define FblDiagSetTransferDataSucceeded() SetFblDiagState( kFblDiagStateTransferDataSucceeded )
#define FblDiagClrTransferDataSucceeded() ClrFblDiagState( kFblDiagStateTransferDataSucceeded )
#define FblDiagSetChecksumAllowed()       SetFblDiagState( kFblDiagStateChecksumAllowed )
#define FblDiagClrChecksumAllowed()       ClrFblDiagState( kFblDiagStateChecksumAllowed )
#define FblDiagSetFlashDriverPresent()    SetFblDiagState( kFblDiagStateFlashDriverPresent )
#define FblDiagClrFlashDriverPresent()    ClrFblDiagState( kFblDiagStateFlashDriverPresent )

#define FblDiagSetBootTimeoutActive()     SetFblDiagState( kFblDiagStateIdxBootTimeoutActive )
#define FblDiagClrBootTimeoutActive()     ClrFblDiagState( kFblDiagStateIdxBootTimeoutActive )

/***********************************************************************************************************************
 *  Local constants
 **********************************************************************************************************************/
#define kDiagInitSequenceNum     ((vuint8) 0x01u)

#if defined( FBL_DIAG_ENABLE_FLASHDRV_ROM )
# if !defined( FLASH_DRIVER_INIT_DATA )
/** Initialization data for default flash driver. If additional drivers should be initialized, please overwrite macro. */
#  define FLASH_DRIVER_INIT_DATA {{flashDrvBlk0, flashCode, FLASHDRV_BLOCK0_LENGTH, FLASHDRV_DECRYPTVALUE}}
# endif
#endif /* FBL_DIAG_ENABLE_FLASHDRV_ROM */

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/* Diagnostic service help functions */
static void FblDiagSessionControlParamInit(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static vuint8 FblDiagDownloadCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* Erase help functions */
#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
static tFlashStatus FblDiagGetEraseState( void );
#endif
static tFblResult FblDiagEraseBlock( V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 *pBlockDescriptor );
static tFblResult FblDiagCheckErasePreconditions(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pbDiagData,
                                                 V_MEMRAM1 tFblAddress V_MEMRAM2 V_MEMRAM3 * pEraseAddress,
                                                 V_MEMRAM1 tFblLength V_MEMRAM2 V_MEMRAM3 * pEraseLength);
static tFblResult FblDiagCheckProgAttemptCounter(V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 *pBlockDescriptor);
static tFblResult FblDiagPrepareFlashDriver( void );
/* Request download help functions */
static tFblResult FblDiagCheckRequestDownloadPreconditions(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pbDiagData,
                                                           V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo);
#if defined( FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD )
static tFblResult FblDiagCheckForFlashDriverDownload(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pDownloadBlockNr,
                                                     V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo);
static tFblResult FblDiagCheckFlashDriverDownload(V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo);
#endif /* FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD */
static tFblResult FblDiagCheckFlashMemoryDownload(V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo);
static tFblResult FblDiagPrepareFirstDownloadSegment(V_MEMRAM1 tFblMemBlockInfo V_MEMRAM2 V_MEMRAM3 * pBlockInfo,
                                                     V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo,
                                                     vuint8 tempBlockNr);

/* NRC handler functions */
static tFblResult FblDiagProcessSubfunctionNrc(vuint32 serviceErrorMask);
static tFblResult FblDiagProcessServiceNrc(vuint32 serviceErrorMask);
static tFblResult FblDiagProcessRoutineNrc(vuint32 serviceErrorMask);

/* Session handling */
static tFblResult FblDiagDefaultSessionMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagProgrammingSessionMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagExtendedSessionMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagTesterPresentMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* Reset */
static tFblResult FblDiagEcuResetMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* DID handling */
static tFblResult FblDiagDataByIdLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagReadDataByIdMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagWriteDataByIdMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* Security access */
static tFblResult FblDiagSecurityAccessLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagSecAccessSeedMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagSecAccessKeyMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagSecAccessSeedAuthPrgMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagSecAccessKeyAuthPrgMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* Communication control / DTC handling - not supported in bootloader, see CS.00102 Flash Service overview */
static tFblResult FblDiagClearDiagnosticInformation(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagReadDtcByStatusMask(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* Routine control */
static tFblResult FblDiagRCStartBootBlockHashMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRCStartApplBlockHashMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRCStartDataBlockHashMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

#if defined( FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS )
static tFblResult FblDiagRCStartCheckProgPreCondMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
#endif /* FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS */

static tFblResult FblDiagRCStartCheckProgramLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRCStartCheckProgramMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

static tFblResult FblDiagRCStartEraseMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRCStartCheckProgDepMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/* Data transfer */
static tFblResult FblDiagRequestDownloadLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagRequestDownloadMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagTransferDataLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagTransferDataMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);
static tFblResult FblDiagReqTransferExitMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

static tFblResult FblDiagCommonBlockHashMainHandler(vuint8 blockType, vuint8 *pbDiagData);

/* Service pre-handler functions */
static tFblResult FblDiagDefaultPreHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen);

/***********************************************************************************************************************
 *  LOCAL CONSTANTS
 **********************************************************************************************************************/

#if defined( FBL_DIAG_ENABLE_FLASHDRV_ROM )
/** List of flash driver source and destination buffers to be initialized. */ /* PRQA S 3218 1 */ /* MD_FblDiag_3218 */
V_MEMROM0 static V_MEMROM1 tFlashDriverInitData V_MEMROM2 kFlashDriverInitData[] = FLASH_DRIVER_INIT_DATA;
#endif /* FBL_DIAG_ENABLE_FLASHDRV_ROM */

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

/** Current block sequence counter */
V_MEMRAM0 static V_MEMRAM1 vuint8               V_MEMRAM2      currentSequenceCnt;
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
/** Invalid key counter */
V_MEMRAM0 static V_MEMRAM1 vuint8               V_MEMRAM2      secSendKeyInvalid;   /* PRQA S 3218 */ /* MD_FblDiag_3218 */
#endif

/* Segment handling variables */
/** Verification information to be transmitted to security module */
V_MEMRAM0 static V_MEMRAM1 SecM_VerifyParamType       V_MEMRAM2 verifyParam;
/** Download segment information. Used for gap fill and data verification. */
V_MEMRAM0 static V_MEMRAM1 FL_SegmentInfoType         V_MEMRAM2 downloadSegments[SWM_DATA_MAX_NOAR];  /* PRQA S 3218 */ /* MD_FblDiag_3218 */
#if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
/** Verification information to be transmitted to security module - pipelined verification */
V_MEMRAM0 static V_MEMRAM1 SecM_SignatureParamType    V_MEMRAM2 pipeSigParam; /* PRQA S 3218 */ /* MD_FblDiag_3218 */
/** Length of already verified data */
V_MEMRAM0 static V_MEMRAM1 vuint32                    V_MEMRAM2 pipeSigDataLength;  /* PRQA S 3218 */ /* MD_FblDiag_3218 */
#endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */

/* Download handling variables */
/** Transfer block information */
V_MEMRAM0 static V_MEMRAM1 tBlockDescriptor     V_MEMRAM2      downloadBlockDescriptor;
/** Number of remaining transfer bytes */
V_MEMRAM0 static V_MEMRAM1 tFblLength           V_MEMRAM2      transferRemainder;
/** Block sequence counter */
V_MEMRAM0 static V_MEMRAM1 vuint8               V_MEMRAM2      expectedSequenceCnt;

/* Boot timeout handling */
/** Boot timeout counter */
V_MEMRAM0 static V_MEMRAM1 vuintx               V_MEMRAM2      bootTimeoutCounter;

# if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
V_MEMRAM0 static V_MEMRAM1 tFlashStatus         V_MEMRAM2      erasedStatus;
#endif

/***********************************************************************************************************************
 *  Diagnostic handler function call table
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Subfunction table configuration
 **********************************************************************************************************************/

/** Sub-function defintion for Default Session (01) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableDsc_DefaultSession[] = { kDiagSubDefaultSession };
/** Sub-function defintion for Programming Session (02) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableDsc_ProgSession[] = { kDiagSubProgrammingSession };
/** Sub-function defintion for Extended Session (03) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableDsc_ExtendedSession[] = { kDiagSubExtendedDiagSession };

/** Sub-function definition for Diagnostic Session Control service (10) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableSessionControl[] =
{
   /* Default Session (01) */
   {
      kFblDiagSubtableDsc_DefaultSession,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest),
      kDiagRqlDiagnosticSessionControl,
      (tFblDiagLengthCheck)0u,
      FblDiagDefaultSessionMainHandler
   },
   /* Programming Session (02) */
   {
      kFblDiagSubtableDsc_ProgSession,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest),
      kDiagRqlDiagnosticSessionControl,
      (tFblDiagLengthCheck)0u,
      FblDiagProgrammingSessionMainHandler
   },
   /* Extended Session (03) */
   {
      kFblDiagSubtableDsc_ExtendedSession,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionFunctionalRequest),
      kDiagRqlDiagnosticSessionControl,
      (tFblDiagLengthCheck)0u,
      FblDiagExtendedSessionMainHandler
   }
};

/** Sub-function definition for Hard Reset sub-function (01) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableEcuReset_HardReset[] = { kDiagSubHardReset };

/** Sub-function definition for ECU Reset service (11) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableEcuReset[] =
{
   /* Hard Reset (01) */
   {
      kFblDiagSubtableEcuReset_HardReset,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest),
      kDiagRqlEcuReset,
      (tFblDiagLengthCheck)0u,
      FblDiagEcuResetMainHandler
   }
};

/** ReadDTC subfunction ID table */
/** Sub-function definition for ReadDTC - Report DTC by Status Mask (xx) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableReadDtcInfo_ReadDtcByStatusMask[] = { kDiagSubReportDTCByStatusMask };

/** Sub-function definition for ReadDTC service (19) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableReadDtcInfo[] =
{
   {
      kFblDiagSubtableReadDtcInfo_ReadDtcByStatusMask,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest),
      kDiagRqlReadDtcByStatusMask,
      (tFblDiagLengthCheck)0u,
      FblDiagReadDtcByStatusMask
   }
};

/** Sub-function definition for Request Seed sub-function (01) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableSecAccess_Seed[] = { kFblDiagSubRequestSeed };
/** Sub-function definition for Send Key sub-function (02) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableSecAccess_Key[] = { kFblDiagSubSendKey };
/** Sub-function definition for Request Seed sub-function (0x11) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableSecAccess_SeedAuthPrg[] = { kFblDiagSubRequestSeed_AuthPrg };
/** Sub-function definition for Send Key sub-function (0x12) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableSecAccess_KeyAuthPrg[] = { kFblDiagSubSendKey_AuthPrg };

/** Sub-function definition for Security Access service (27) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableSecAccess[] =
{
   /* Request Seed (01) */
   {
      kFblDiagSubtableSecAccess_Seed,
      (kFblDiagOptionSessionProgramming),
      kDiagRqlSecurityAccessSeed,
      (tFblDiagLengthCheck)0u,
      FblDiagSecAccessSeedMainHandler
   },
   /* Send Key (02) */
   {
      kFblDiagSubtableSecAccess_Key,
      (kFblDiagOptionSessionProgramming),
      kDiagRqlSecurityAccessKey,
      (tFblDiagLengthCheck)0u,
      FblDiagSecAccessKeyMainHandler
   },

   /* Request Seed - authenticated reprogramming (0x11) */
   {
      kFblDiagSubtableSecAccess_SeedAuthPrg,
      (kFblDiagOptionSessionProgramming),
      kDiagRqlSecurityAccessSeedAuthPrg,
      (tFblDiagLengthCheck)0u,
      FblDiagSecAccessSeedAuthPrgMainHandler
   },
   /* Send Key - authenticated reprogramming (0x12) */
   {
      kFblDiagSubtableSecAccess_KeyAuthPrg,
      (kFblDiagOptionSessionProgramming),
      kDiagRqlSecurityAccessKeyAuthPrg,
      (tFblDiagLengthCheck)0u,
      FblDiagSecAccessKeyAuthPrgMainHandler
   }

};

/** Sub-function / RID definition for Boot Logical Block Hash (01D000) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartBootBlockHash[] = { kDiagSubStartRoutine, kDiagRoutineIdBootLogicalBlockHashHigh, kDiagRoutineIdBootLogicalBlockHashLow };

/** Sub-function / RID definition for Application Logical Block Hash (01D003) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartApplBlockHash[] = { kDiagSubStartRoutine, kDiagRoutineIdApplSwLogicalBlockHashHigh, kDiagRoutineIdApplSwLogicalBlockHashLow };

/** Sub-function / RID definition for Application Logical Block Hash (01D004) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartDataBlockHash[] = { kDiagSubStartRoutine, kDiagRoutineIdApplDataLogicalBlockHashHigh, kDiagRoutineIdApplDataLogicalBlockHashLow };

/** Sub-function / RID definition for Application Logical Block Hash (01D002) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartProgPreCond[] = { kDiagSubStartRoutine, kDiagRoutineIdCheckProgPreCondHigh, kDiagRoutineIdCheckProgPreCondLow };

/** Sub-function / RID definition for checksum verification (01F000) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartCheckProgram[] = { kDiagSubStartRoutine, kDiagRoutineIdCheckProgramHigh, kDiagRoutineIdCheckProgramLow };

/** Sub-function / RID definition for erase memory request (01FF00) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartErase[] = { kDiagSubStartRoutine, kDiagRoutineIdEraseMemoryHigh, kDiagRoutineIdEraseMemoryLow };

/** Sub-function / RID definition for check programming dependencies request (01FF01) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableRC_StartCheckProgDep[] = { kDiagSubStartRoutine, kDiagRoutineIdCheckProgDepHigh, kDiagRoutineIdCheckProgDepLow };

/** Sub-function / RID defintion for Routine Control service (31) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableRoutine[] =
{
   /* Boot Logical Block Hash (01D000) */
   {
      kFblDiagSubtableRC_StartBootBlockHash,
      (kFblDiagOptionSessionProgramming | kFblDiagOptionSecuredService),
      kDiagRqlRoutineControlLogicalBlockHash,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartBootBlockHashMainHandler
   },

   /* Application Logical Block Hash (01D003) */
   {
      kFblDiagSubtableRC_StartApplBlockHash,
      (kFblDiagOptionSessionProgramming | kFblDiagOptionSecuredService),
      kDiagRqlRoutineControlLogicalBlockHash,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartApplBlockHashMainHandler
   },

   /* Application Data Logical Block Hash (01D004) */
   {
      kFblDiagSubtableRC_StartDataBlockHash,
      (kFblDiagOptionSessionProgramming | kFblDiagOptionSecuredService),
      kDiagRqlRoutineControlLogicalBlockHash,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartDataBlockHashMainHandler
   },

#if defined( FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS )
   /* Check programming pre-conditions (010D002) */
   {
      kFblDiagSubtableRC_StartProgPreCond,
      (kFblDiagOptionSessionDefault | kFblDiagOptionFunctionalRequest),
      kDiagRqlRoutineControlProgPreCond,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartCheckProgPreCondMainHandler
   },
#endif
   /* Check Program request (01F000) */
   {
      kFblDiagSubtableRC_StartCheckProgram,
      (kFblDiagOptionSessionProgramming | kFblDiagOptionSecuredService),
      kDiagRqlRoutineControlCheckProgram,
      FblDiagRCStartCheckProgramLengthCheck,
      FblDiagRCStartCheckProgramMainHandler
   },

   /* Erase memory request (01FF00) */
   {
      kFblDiagSubtableRC_StartErase,
      (kFblDiagOptionSessionProgramming | kFblDiagOptionSecuredService),
      kDiagRqlRoutineControlEraseRoutine,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartEraseMainHandler
   },
   /* Check programming dependencies (01FF01) */
   {
      kFblDiagSubtableRC_StartCheckProgDep,
      (kFblDiagOptionSessionProgramming | kFblDiagOptionSecuredService),
      kDiagRqlRoutineControlCheckProgDep,
      (tFblDiagLengthCheck)0u,
      FblDiagRCStartCheckProgDepMainHandler
   }
};

/** Sub-function definition for Zero sub-function (00) */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 kFblDiagSubtableTesterPresent_ZeroSubfunction[] = { kDiagSubTesterPresent };

/** Sub-function definition for Tester Present service (3E) */
V_MEMROM0 static V_MEMROM1 tFblDiagServiceSubTable V_MEMROM2 kFblDiagSubtableTesterPresent[] =
{
   /* Zero sub-function (00) */
   {
      kFblDiagSubtableTesterPresent_ZeroSubfunction,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest),
      kDiagRqlTesterPresent,
      (tFblDiagLengthCheck)0u,
      FblDiagTesterPresentMainHandler
   }
};

/***********************************************************************************************************************
 *  Main service table configuration
 **********************************************************************************************************************/

/** Table of supported diagnostic servcies */
V_MEMROM0 V_MEMROM1 tFblDiagServiceTable V_MEMROM2 kFblDiagServiceTable[] =
{
   /* Diagnostic Session Control (10) */
   {
      kDiagSidDiagnosticSessionControl,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionServiceIsSubfunction | kFblDiagOptionFunctionalRequest),
      kDiagRqlDiagnosticSessionControl,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableSessionControl),
      ARRAY_SIZE(kFblDiagSubtableDsc_DefaultSession),
      kFblDiagSubtableSessionControl,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSubfunctionNrc,
      FblDiagDefaultPostHandler
   },
   /* ECU Reset (11) */
   {
      kDiagSidEcuReset,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionServiceIsSubfunction | kFblDiagOptionFunctionalRequest),
      kDiagRqlEcuReset,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableEcuReset),
      ARRAY_SIZE(kFblDiagSubtableEcuReset_HardReset),
      kFblDiagSubtableEcuReset,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSubfunctionNrc,
      FblDiagDefaultPostHandler
   },

   /* Read DTC Information (19) */
   {
      kDiagSidReadDTCInformation,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionServiceIsSubfunction | kFblDiagOptionFunctionalRequest),
      kDiagRqlServiceWithSubfunction,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableReadDtcInfo),
      ARRAY_SIZE(kFblDiagSubtableReadDtcInfo_ReadDtcByStatusMask),
      kFblDiagSubtableReadDtcInfo,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSubfunctionNrc,
      FblDiagDefaultPostHandler
   },
   /* Read Data by Identifier (22) */
   {
      kDiagSidReadDataByIdentifier,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionFunctionalRequest),
      kDiagRqlReadDataByIdentifier,
      FblDiagDataByIdLengthCheck,
      0u,
      0u,
      (tFblDiagServiceSubTable*)V_NULL,
      FblDiagDefaultPreHandler,
      FblDiagReadDataByIdMainHandler,
      FblDiagProcessServiceNrc,
      FblDiagDefaultPostHandler
   },
   /* Security Access (27) */
   {
      kDiagSidSecurityAccess,
      (kFblDiagSecurityAccessSessionMask | kFblDiagOptionServiceIsSubfunction),
      kDiagRqlServiceWithSubfunction,
      FblDiagSecurityAccessLengthCheck,
      ARRAY_SIZE(kFblDiagSubtableSecAccess),
      ARRAY_SIZE(kFblDiagSubtableSecAccess_Seed),
      kFblDiagSubtableSecAccess,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSubfunctionNrc,
      FblDiagDefaultPostHandler
   },
   /* Write Data by Identifier (2E) */
   {
      kDiagSidWriteDataByIdentifier,
      (kFblDiagOptionSessionProgramming),
      kDiagRqlWriteDataByIdentifier,
      FblDiagDataByIdLengthCheck,
      0u,
      0u,
      (tFblDiagServiceSubTable*)V_NULL,
      FblDiagDefaultPreHandler,
      FblDiagWriteDataByIdMainHandler,
      FblDiagProcessServiceNrc,
      FblDiagDefaultPostHandler
   },
   /* Routine Control (31) */
   {
      kDiagSidRoutineControl,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionProgramming | kFblDiagOptionServiceIsSubfunction | kFblDiagOptionFunctionalRequest),
      kDiagRqlRoutineControl,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableRoutine),
      ARRAY_SIZE(kFblDiagSubtableRC_StartCheckProgram),
      kFblDiagSubtableRoutine,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessRoutineNrc,
      FblDiagDefaultPostHandler
   },
   /* Request Download (34) */
   {
      kDiagSidRequestDownload,
      (kFblDiagOptionSessionProgramming | kFblDiagOptionSecuredService),
      kDiagRqlRequestDownload,
      FblDiagRequestDownloadLengthCheck,
      0u,
      0u,
      (tFblDiagServiceSubTable*)V_NULL,
      FblDiagDefaultPreHandler,
      FblDiagRequestDownloadMainHandler,
      FblDiagProcessServiceNrc,
      FblDiagDefaultPostHandler
   },
   /* Transfer Data (36) */
   {
      kDiagSidTransferData,
      (kFblDiagOptionSessionProgramming | kFblDiagOptionSecuredService),
      kDiagRqlTransferData,
      FblDiagTransferDataLengthCheck,
      0u,
      0u,
      (tFblDiagServiceSubTable*)V_NULL,
      FblDiagDefaultPreHandler,
      FblDiagTransferDataMainHandler,
      FblDiagProcessServiceNrc,
      FblDiagDefaultPostHandler
   },
   /* Request Transfer Exit (37) */
   {
      kDiagSidRequestTransferExit,
      (kFblDiagOptionSessionProgramming | kFblDiagOptionSecuredService),
      kDiagRqlRequestTransferExit,
      (tFblDiagLengthCheck)0u,
      0u,
      0u,
      (tFblDiagServiceSubTable*)V_NULL,
      FblDiagDefaultPreHandler,
      FblDiagReqTransferExitMainHandler,
      FblDiagProcessServiceNrc,
      FblDiagDefaultPostHandler
   },
   /* Tester Present (3E) */
   {
      kDiagSidTesterPresent,
      (kFblDiagOptionSessionDefault | kFblDiagOptionSessionExtended | kFblDiagOptionSessionProgramming | kFblDiagOptionServiceIsSubfunction | kFblDiagOptionFunctionalRequest),
      kDiagRqlTesterPresent,
      (tFblDiagLengthCheck)0u,
      ARRAY_SIZE(kFblDiagSubtableTesterPresent),
      ARRAY_SIZE(kFblDiagSubtableTesterPresent_ZeroSubfunction),
      kFblDiagSubtableTesterPresent,
      FblDiagDefaultPreHandler,
      (tFblDiagMainHandler)0u,
      FblDiagProcessSubfunctionNrc,
      FblDiagDefaultPostHandler
   },
   {
      kDiagSidClearDiagInfo,
      (kFblDiagOptionSessionDefault),
      kDiagRqlClearDiagInfo,
      (tFblDiagLengthCheck)0u,
      0u,
      0u,
      (tFblDiagServiceSubTable*)V_NULL,
      FblDiagDefaultPreHandler,
      FblDiagClearDiagnosticInformation,
      FblDiagProcessServiceNrc,
      FblDiagDefaultPostHandler
   },
};

/** Size of service table */
V_MEMROM0 V_MEMROM1 vuintx V_MEMROM2 kSizeOfServiceTable = ARRAY_SIZE(kFblDiagServiceTable);

/***********************************************************************************************************************
 *  Service support functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblDiagDownloadCheck
 **********************************************************************************************************************/
/*! \brief       Verify the downloaded data.
 *  \details     Uses the configured security module to verify if the download has been done correctly and
 *               the data is allowed to be downloaded. Also calculates CRC total if enabled.
 *  \pre         Logical block or flash driver has to be downloaded completely.
 *  \param[in]   pbDiagData Pointer to data in the diagBuffer (without SID).
 *  \param[in]   diagReqDataLen Length of data (without SID).
 *  \return      Verification result supplied by the security module.
 **********************************************************************************************************************/
static vuint8 FblDiagDownloadCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblMemBlockVerifyData verifyData;
   SecM_StatusType verifyErrorCode;
   vuint8 result;

   /* Length is not explicitly submitted - use (request length - sub-parameter and routine ID length) */

#if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
   verifyData.verifyDataPipe.length = diagReqDataLen - 3u;
   verifyData.verifyDataPipe.data = (V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 *)&pbDiagData[kDiagLocFmtRoutineStatus];
#endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */

#if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT )
   verifyData.verifyDataOutput.length = diagReqDataLen - 3u;
   verifyData.verifyDataOutput.data = (V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 *)&pbDiagData[kDiagLocFmtRoutineStatus];
#endif /* FBL_MEM_ENABLE_VERIFY_OUTPUT */

   /* Call verification routine */
   if (FblMemRemapStatus(FblMemBlockVerify(&verifyData, &verifyErrorCode)) != kFblMemStatus_Ok)
   {
      if (verifyErrorCode == SECM_OK)
      {
         /* If no verification error code is provided, return general error */
         result = kDiagCheckVerificationFailed;
      }
      else
      {
         result = verifyErrorCode;
      }
   }
   else
   {
      result = kDiagCheckVerificationOk;
   }

   if (result == kDiagCheckVerificationOk)
   {
      if (FblDiagGetTransferTypeFlash())
      {
         (void)FblRealTimeSupport();
#if defined( SEC_ENABLE_CRC_TOTAL )
         (void)ApplFblWriteCRCTotal(&downloadBlockDescriptor,
                                    (vuint32)verifyParam.blockStartAddress,
                                    (vuint32)verifyParam.blockLength,
                                    (vuint32)verifyParam.crcTotal
                                   );
#endif /* SEC_ENABLE_CRC_TOTAL */

         /* Call validation function to inform application */
         if (ApplFblValidateBlock(downloadBlockDescriptor) != kFblOk)
         {
            result = kDiagCheckVerificationFailed;
         }
         else
         {
            /* Increment programming success counter */
            (void)ApplFblIncProgCounts(downloadBlockDescriptor);
         }
      }
#if defined( FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD )
      else /* Download of flash driver */
      {
         /* Send response pending for flash driver initialization */
         DiagExRCRResponsePending(kForceSendRpIfNotInProgress);

         /* Mark flash driver as present */
         FblDiagSetFlashDriverPresent();

         if (FblDiagPrepareFlashDriver() == kFblOk)
         {
            /* Expect download of application next */
            FblDiagSetTransferTypeFlash();
         }
         else
         {
            /* Flash driver initialization failed */
            result = kDiagCheckVerificationFailed;
         }
      }
#endif /* FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD */
   }

   return result;
}

#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
/***********************************************************************************************************************
 *  FblDiagGetEraseState
 **********************************************************************************************************************/
/*! \brief       This function checks if the current logical block is erased.
 *  \details     If the memoryStatus flag indicates
 *               "erased", an additional user callback is called in order to
 *               make sure, that the erase routine actually can be omitted.
 *  \return      kFlashErased if block is already erased, kFlashNotErased if block is not erased
 **********************************************************************************************************************/
static tFlashStatus FblDiagGetEraseState( void )
{
   tFlashStatus status;
   vuint8 memoryStatus;

   status = kFlashNotErased;

   /* Check if the memory status flag indicates "erased" */
   if (ApplFblReadMemoryStatus(downloadBlockDescriptor.blockNr, &memoryStatus) == kFblOk)
   {
      if (memoryStatus == kDiagMemStatErased )
      {
         /* Invoke callback */
         status = ApplFblGetBlockErased(downloadBlockDescriptor);
      }
   }
   return status;
}
#endif   /* FBL_ENABLE_FLASH_ERASED_DETECTION */

/***********************************************************************************************************************
 *  FblDiagEraseBlock
 **********************************************************************************************************************/
/*! \brief       Erase selected block
 *  \details     Prepare data structure for FblLib_Mem and erase block
 *  \pre         Flash driver initialized, erase pre-conditions have been checked
 *  \param[in]   pBlockDescriptor Pointer to block descriptor structure
 *  \return      Erase result
 **********************************************************************************************************************/
static tFblResult FblDiagEraseBlock( V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 *pBlockDescriptor )
{
   tFblResult result;
   tFblMemBlockInfo blockInfo;
#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
   vuint8 memoryStatus;
#endif

   /* Initialize download block descriptor continued */
   *pBlockDescriptor = FblLogicalBlockTable.logicalBlock[pBlockDescriptor->blockNr];

   /* Initialize block structure for FblLib_Mem */
   blockInfo.targetAddress = pBlockDescriptor->blockStartAddress;
   blockInfo.targetLength = pBlockDescriptor->blockLength;
   blockInfo.logicalAddress = pBlockDescriptor->blockStartAddress;
   blockInfo.logicalLength = pBlockDescriptor->blockLength;

   /* Start erase by FblLib_Mem */
   if (
#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
         (erasedStatus == kFlashErased) ||  /* PRQA S 3415, 3353 */ /* MD_FblDiag_3415, MD_FblDiag_3353 */
#endif
         (FblMemRemapStatus(FblMemBlockEraseIndication(&blockInfo)) == kFblMemStatus_Ok)
      )     
   {
      /* Erase succeeded */
      FblDiagSetEraseSucceeded();

#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
      erasedStatus = kFlashErased;
      memoryStatus = kDiagMemStatErased;
#endif
      /* After erase, the first segment of a logical block will be downloaded */
# if defined( FBL_ENABLE_PRESENCE_PATTERN )
      /* Adjust the size of the logical block according to presence pattern size. */
      (void)ApplFblAdjustLbtBlockData(pBlockDescriptor);
# endif /* FBL_ENABLE_PRESENCE_PATTERN */

      /* Initialize segment counter */
      FblDiagSegmentInit();

      result = kFblOk;
   }
   else
   {
      /* Erase failed */    
#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
      erasedStatus = kFlashNotErased;
      memoryStatus = kDiagMemStatProgrammed;
#endif
      FblDiagClrEraseSucceeded();
      result = kFblFailed;
   }

#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
   /* Update memory status in NVM */
   result |= ApplFblWriteMemoryStatus(pBlockDescriptor->blockNr, &memoryStatus);
#endif
   return result;
}

/***********************************************************************************************************************
 *  FblDiagCheckErasePreconditions
 **********************************************************************************************************************/
/*! \brief         Verify that all erase preconditions are fulfilled
 *  \pre           Fingerprint is available, memory driver initialized.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[out]    pEraseAddress Start address of erase area
 *  \param[out]    pEraseLength Length of erase area
 *  \return        kFblOk: Preconditions fulfilled; kFblFailed: Preconditions not fulfilled
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblDiag_3673 */
static tFblResult FblDiagCheckErasePreconditions(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pbDiagData,
                                                 V_MEMRAM1 tFblAddress V_MEMRAM2 V_MEMRAM3 * pEraseAddress,
                                                 V_MEMRAM1 tFblLength V_MEMRAM2 V_MEMRAM3 * pEraseLength)
{
   tFblResult result;

   if (!FblDiagGetFingerprintValid())
   {
      DiagNRCConditionsNotCorrect();
      result = kFblFailed;
   }
   else if (FblDiagPrepareFlashDriver() != kFblOk)
   {
      DiagNRCConditionsNotCorrect();
      result = kFblFailed;
   }
   else
   {
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagPrepareFlashDriver
 **********************************************************************************************************************/
/*! \brief         Prepare flash driver for usage
 *  \return        Preparation result
 **********************************************************************************************************************/
static tFblResult FblDiagPrepareFlashDriver( void )
{
   tFblResult result;
   tFlashErrorCode flashErrorCode;
#if defined( FBL_DIAG_ENABLE_FLASHDRV_ROM )
   vuintx flashDriverIndex;
   vuint32 byteIndex;
   V_MEMROM1 tFlashDriverInitData V_MEMROM2 V_MEMROM3 * flashDriverInitData;
#endif /* FBL_DIAG_ENABLE_FLASHDRV_ROM */

   /* Initialize variable */
   result = kFblFailed;

   if (!FblDiagGetMemDriverInitialized())
   {
#if defined( FBL_DIAG_ENABLE_FLASHDRV_ROM )
      /* Use flash driver from image in case no driver has been downloaded */
      if (!FblDiagGetFlashDriverPresent())
      {
         /* Copy data of all configured flash drivers */
         for (flashDriverIndex = 0u; flashDriverIndex < ARRAY_SIZE(kFlashDriverInitData); flashDriverIndex++)
         {
            flashDriverInitData = &kFlashDriverInitData[flashDriverIndex];

            /* Check if target buffer is big enough for data */
            if (flashDriverInitData->copySize > FLASH_SIZE)
            {
               /* Data doesn't fit into buffer. Assumes that all buffers are configured to the same size
                * if more than one buffer is used.
               */
               FblErrStatSetError(FBL_ERR_FLASHCODE_EXCEEDS_MEMORY);
               break;
            }
            
            for (byteIndex = 0u; byteIndex < flashDriverInitData->copySize; byteIndex++)
            {
               flashDriverInitData->destBuffer[byteIndex] = (flashDriverInitData->decryptValue ^ flashDriverInitData->sourceBuffer[byteIndex]);
               if ((byteIndex & 0xFFu) == 0x00u)
               {
                  FblLookForWatchdogVoid();
               }
            }
         }
         /* Data copied */
         FblDiagSetFlashDriverPresent();
      }
#endif /* FBL_DIAG_ENABLE_FLASHDRV_ROM */

      if (FblDiagGetFlashDriverPresent())
      {
         /* Initialize version */
         FblErrStatSetFlashDrvVersion();  /* PRQA S 3109 */ /* MD_FblDiag_3109 */

         /* Turn on programming voltage (if necessary) */
         ApplFblSetVfp();

         /* Initialze memory drivers */
         FblCwSetOfflineMode();
         /* Check version and initialize flash driver */
         flashErrorCode = MemDriver_InitSync(V_NULL);
         FblCwSetOnlineMode();

         if (flashErrorCode == IO_E_OK)
         {
            FblDiagSetMemDriverInitialized();
            result = kFblOk;
         }
         else
         {
            FblErrStatSetError(FBL_ERR_FLASHCODE_INIT_FAILED);
            FblErrStatSetFlashDrvError(flashErrorCode);
         }
      }
   }
   else
   {
      /* Flash driver already initialized */
      result = kFblOk;
   }

   return result;
}  /* PRQA S 6080 */ /* MD_MSR_STMIF */

/***********************************************************************************************************************
 *  FblDiagCheckProgAttemptCounter
 **********************************************************************************************************************/
/*! \brief         Check if programming attempt counter allows another programming cycle
 *  \pre           Response pending processing has been started, block has been selected
 *  \param[in]     pBlockDescriptor Pointer to current download block descriptor
 *  \return        kFblOk: Programming allowed; kFblFailed: Programming not allowed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblDiag_3673 */
static tFblResult FblDiagCheckProgAttemptCounter(V_MEMRAM1 tBlockDescriptor V_MEMRAM2 V_MEMRAM3 *pBlockDescriptor)
{
   tFblResult result;
   vuint16 progAttempts;

   /* Initialize variables */
   result = kFblOk;

   /* Initialize variables */
   if (ApplFblGetProgAttempts(*pBlockDescriptor, &progAttempts) != kFblOk)
   {
      /* Programming attempt counter couldn't be read. Use 0 as default value. */
      progAttempts = 0u;
   }

   /* Check if logical block does not restrict the number of programming attempts */
   if (ApplFblGetPromMaxProgAttempts(pBlockDescriptor->blockNr) != 0u)
   {
      /* Check logical block programming attempts */
      if (progAttempts >= ApplFblGetPromMaxProgAttempts(pBlockDescriptor->blockNr))
      {
         /* Logical block cannot be programmed anymore */
         FblErrStatSetError(FBL_ERR_FLASH_PROG_CONDITIONS);
         DiagNRCConditionsNotCorrect();
         result = kFblFailed;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagCheckRequestDownloadPreconditions
 **********************************************************************************************************************/
/*! \brief         Verify that all request download preconditions are fulfilled
 *  \pre           Fingerprint is available
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[out]    pSegmentInfo FblLib_Mem segment information for this download
 *  \return        kFblOk: Preconditions fulfilled; kFblFailed: Preconditions not fulfilled
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblDiag_3673 */
static tFblResult FblDiagCheckRequestDownloadPreconditions(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pbDiagData,
                                                           V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo)
{
   tFblResult result;

   vuint8  lengthFormat;
   vuint8  addrFormat;

   /* Initialize variables */
   pSegmentInfo->logicalAddress = 0u;
   pSegmentInfo->logicalLength = 0u;
   pSegmentInfo->targetAddress = 0u;
   pSegmentInfo->targetLength = 0u;

   /* Get length and address format from message */
   lengthFormat = (vuint8)((pbDiagData[kDiagLocFmtFormatOffset] & 0xF0u) >> 4u);
   addrFormat = (vuint8) (pbDiagData[kDiagLocFmtFormatOffset] & 0x0Fu);
   /* Read compression and encryption method */
   pSegmentInfo->dataFormat = (tFblMemDfi)pbDiagData[kDiagLocFmtSubparam];

   /* Check address and length format */
   if (  (addrFormat == 0u) || (lengthFormat == 0u) || (addrFormat != kFblDiagAddrFormat) 
      || (lengthFormat != kFblDiagLengthFormat))
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
   else if ((FblDiagGetTransferDataAllowed()) || (!FblDiagGetFingerprintValid()))
   {
      DiagNRCConditionsNotCorrect();
      result = kFblFailed;
   }
#if defined( FBL_ENABLE_DATA_PROCESSING )
# if defined( FBL_ENABLE_ENCRYPTION_MODE )
# else
   /* No encrypted data supported */
   else if (FblDiagGetEncryptionMode(pSegmentInfo->dataFormat) != kDiagSubNoEncryption)
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
# endif /* FBL_ENABLE_ENCRYPTION_MODE */
# if defined( FBL_ENABLE_COMPRESSION_MODE )
# else
   /* No compressed data supported */
   else if (FblDiagGetCompressionMode(pSegmentInfo->dataFormat) != kDiagSubNoCompression)
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
# endif /* FBL_ENABLE_COMPRESSION_MODE */
#else
   else if (pSegmentInfo->dataFormat != kDiagSubNoDataProcessing)
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
#endif /* FBL_ENABLE_DATA_PROCESSING */
   else
   {
      /* Get memoryAddress */
      pSegmentInfo->logicalAddress = FblMemGetInteger(addrFormat, &(pbDiagData[kDiagLocFmtAddrOffset]));
      /* Get memorySize */
      pSegmentInfo->logicalLength = FblMemGetInteger(lengthFormat, &(pbDiagData[kDiagLocFmtAddrOffset + addrFormat]));

      result = kFblOk;
   }

   return result;
}

#if defined( FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD )
/***********************************************************************************************************************
 *  FblDiagCheckForFlashDriverDownload
 **********************************************************************************************************************/
/*! \brief         Check if a flash driver or application should be downloaded
 *  \pre           Download precondition check succeeded
 *  \param[in,out] pDownloadBlockNr Logical index of verification routine for this download
 *  \param[out]    pSegmentInfo FblLib_Mem segment information for this download
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
static tFblResult FblDiagCheckForFlashDriverDownload(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * pDownloadBlockNr,
                                                     V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo)
{
   tFblResult result;

   /* Initialize variables */
   result = kFblOk;

# if defined( FLASHCODE_RELOCATABLE ) || \
     defined( FLASH_DRIVER_RELOCATABLE )
   /* For relocatable drivers: If erase succeeded state is set, assume a data download
      is performed. Otherwise, a driver download is assumed. This enables downloads to
      logical blocks starting with address 0x00 in combination with relocatable flash
      drivers.
   */
   if ((pSegmentInfo->logicalAddress == 0u) && (!FblDiagGetEraseSucceeded()))
# else
   if (pSegmentInfo->logicalAddress == FBL_DIAG_FLASH_CODE_BASE_ADDR) /* PRQA S 0306 */ /* MD_FblDiag_0306 */
# endif /* FLASHCODE_RELOCATABLE || FLASH_DRIVER_RELOCATABLE */
   {
      /* Download of flash driver requested */
      FblDiagClrFlashDriverPresent();
      /* Deinit flash driver in case it is already initialized */
      if (FblDiagGetMemDriverInitialized())
      {
         DiagExRCRResponsePending(kForceSendRpIfNotInProgress);
         FblDiagClrMemDriverInitialized();
         (void)MemDriver_DeinitSync(V_NULL);
      }
      /* Download of flash driver requested */
      FblDiagClrTransferTypeFlash();
      pSegmentInfo->type = kFblMemType_RAM;

      /* Verification routine of first logical block used for flash driver */
      *pDownloadBlockNr = 0u;
   }
   else
   {
      /* Check if erased logical block and requested address match */
      if (    (FblGetBlockNrFromAddress(pSegmentInfo->logicalAddress, pSegmentInfo->logicalLength, pDownloadBlockNr) != kFblOk)
            || (*pDownloadBlockNr != downloadBlockDescriptor.blockNr))
      {
            /* Requested download block does not match erased block */
            DiagNRCRequestOutOfRange();
            result = kFblFailed;
      }
      else
      {
         /* Download of data requested */
         FblDiagSetTransferTypeFlash();

         /* Set target memory type for download */
         pSegmentInfo->type = kFblMemType_ROM;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagCheckFlashDriverDownload
 **********************************************************************************************************************/
/*! \brief         Check if the download request matches the flash driver buffer
 *  \param[in,out] pSegmentInfo FblLib_Mem segment information for this download
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
static tFblResult FblDiagCheckFlashDriverDownload(V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo)
{
   tFblResult result;

   /* Initialize target address. This address is used to store the downloaded data */
#if defined( FLASHCODE_RELOCATABLE ) || \
    defined( FLASH_DRIVER_RELOCATABLE )
   pSegmentInfo->targetAddress = FBL_DIAG_FLASH_CODE_BASE_ADDR; /* PRQA S 0306 */ /* MD_FblDiag_0306 */
#else
   pSegmentInfo->targetAddress = pSegmentInfo->logicalAddress;
#endif /* FLASHCODE_RELOCATABLE || FLASH_DRIVER_RELOCATABLE */

   /* Store download length */
   pSegmentInfo->targetLength = pSegmentInfo->logicalLength;

   /* Check if flash driver fits into flash driver buffer */ /* PRQA S 0306 1 */ /* MD_FblDiag_0306 */
   if (FblCheckRangeContained(pSegmentInfo->targetAddress, pSegmentInfo->targetLength, FBL_DIAG_FLASH_CODE_BASE_ADDR, FLASH_SIZE) == kFblOk)
   {
      /* Initialize segment counter */
      FblDiagSegmentInit();
      /* Copy data and address of first segment to initialize downloadHeader */
      (void)FblDiagSegmentNext();

      result = kFblOk;
   }
   else
   {
      FblErrStatSetError(FBL_ERR_FLASHCODE_EXCEEDS_MEMORY);
      DiagNRCRequestOutOfRange();

      result = kFblFailed;
   }

   return result;
}
#endif /* FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD */

/***********************************************************************************************************************
 *  FblDiagCheckFlashMemoryDownload
 **********************************************************************************************************************/
/*! \brief         Check if the download request matches the erased logical block
 *  \param[in,out] pSegmentInfo FblLib_Mem segment information for this download
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
static tFblResult FblDiagCheckFlashMemoryDownload(V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo)
{
   FL_SegmentInfoType * segment;

   tFblResult result;

   /* Initialize variables */
   result = kFblOk;

   /* Memory driver has to be available */
   if (!FblDiagGetMemDriverInitialized())
   {
      DiagNRCUploadDownloadNotAccepted();
      result = kFblFailed;
   }
   /* Memory has to be erased in case of first segment in logical block */
   else if ((segmentCount == 0u) && (!FblDiagGetEraseSucceeded()))
   {
      DiagNRCUploadDownloadNotAccepted();
      result = kFblFailed;
   }
   /* Verify addresses (address must be in the area described by downloadBlockDescriptor)
      * this check requires EraseRoutine, because this initializes downloadBlockDescriptor */
   else if (   (FblCheckRangeContained(pSegmentInfo->logicalAddress,
                                       pSegmentInfo->logicalLength,
                                       downloadBlockDescriptor.blockStartAddress,
                                       downloadBlockDescriptor.blockLength) != kFblOk)
            || ( transferRemainder == 0u)
            )
   {
      FblErrStatSetError(FBL_ERR_LBT_ADDR_MISMATCH);
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }
   else
   {
      if (FblDiagSegmentNext() == kSwmOutOfRange)
      {
         FblErrStatSetError(FBL_ERR_TOO_MANY_SEGMENTS_IN_MODULE);
         DiagNRCRequestOutOfRange();
         result = kFblFailed;
      }
      else
      {
         /* Store address/length information of RequestDownload for flash operation */
         pSegmentInfo->targetAddress = pSegmentInfo->logicalAddress;
         pSegmentInfo->targetLength = pSegmentInfo->logicalLength;

         /* Check if requested segment overlaps with previously downloaded data */
         if (segmentCount > 1u)
         {
            /* Download second segment */
            segment = &verifyParam.segmentList.segmentInfo[segmentCount - 2u];

            if (   (pSegmentInfo->targetAddress <= segment->transferredAddress)
                || ((pSegmentInfo->targetAddress - segment->transferredAddress) < segment->length)
               )
            {
               /* New segment is not in order or overlaps previous one */
               DiagNRCRequestOutOfRange();
               result = kFblFailed;
            }
         }
      }
   }

   return result;
}  /* PRQA S 6080 */ /* MD_MSR_STMIF */

/***********************************************************************************************************************
 *  FblDiagPrepareFirstDownloadSegment
 **********************************************************************************************************************/
/*! \brief         Add block structure to FblLib_Mem data
 *  \param[out]    pBlockInfo Logical block information data provided to FblLib_Mem
 *  \param[in]     pSegmentInfo Segment information of requested download
 *  \param[in]     tempBlockNr Logical index of verification routine for this download
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
/* PRQA S 3673 3 */ /* MD_FblDiag_3673 */
static tFblResult FblDiagPrepareFirstDownloadSegment(V_MEMRAM1 tFblMemBlockInfo V_MEMRAM2 V_MEMRAM3 * pBlockInfo,
                                                     V_MEMRAM1 tFblMemSegmentInfo V_MEMRAM2 V_MEMRAM3 * pSegmentInfo,
                                                     vuint8 tempBlockNr)
{
   tFblResult result;
   tFblDiagNrc libMemResult;

   /* Initialize variables */
   result = kFblOk;

   /* Info: Flash driver uses verification routines of first logical block */
#if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT )
   pBlockInfo->verifyRoutineOutput.function = (tFblMemVerifyFctOutput)(FblLogicalBlockTable.logicalBlock[tempBlockNr].verifyOutput); /* PRQA S 0313 */ /* MD_FblDiag_0313 */
   pBlockInfo->verifyRoutineOutput.param = (V_MEMRAM1 tFblMemVerifyParamOutput V_MEMRAM2 V_MEMRAM3 *)&verifyParam;
#endif /* FBL_MEM_ENABLE_VERIFY_OUTPUT */

#if defined( FBL_MEM_ENABLE_VERIFY_PIPELINED )
   /* Configure pipelined verification */
   pBlockInfo->verifyRoutinePipe.function = (tFblMemVerifyFctInput)(FblLogicalBlockTable.logicalBlock[tempBlockNr].verifyPipelined); /* PRQA S 0313 */ /* MD_FblDiag_0313 */
   pBlockInfo->verifyRoutinePipe.param = (V_MEMRAM1 tFblMemVerifyParamInput V_MEMRAM2 V_MEMRAM3 *)&pipeSigParam;
   /* Force use of internal workspace */
   pipeSigParam.currentHash.sigResultBuffer = (SecM_ResultBufferType)V_NULL;  /* PRQA S 0306 */ /* MD_FblDiag_0306 */
   pipeSigParam.currentHash.length = 0u;
   pipeSigParam.currentDataLength = &pipeSigDataLength;
#endif /* FBL_MEM_ENABLE_VERIFY_PIPELINED */

   pBlockInfo->segmentList = &verifyParam.segmentList;
   pBlockInfo->maxSegments = SWM_DATA_MAX_NOAR;
   verifyParam.segmentList.segmentInfo = downloadSegments;

   /* Prepare block data structure */
   if( FblDiagGetTransferTypeFlash())
   {
      pBlockInfo->targetAddress = downloadBlockDescriptor.blockStartAddress;
      pBlockInfo->targetLength = downloadBlockDescriptor.blockLength;
      pBlockInfo->logicalAddress = downloadBlockDescriptor.blockStartAddress;
      pBlockInfo->logicalLength = downloadBlockDescriptor.blockLength;

      pBlockInfo->readFct = (tFblMemVerifyReadFct)FblReadProm;
   }
#if defined( FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD )
   else
   {
      pBlockInfo->targetAddress = pSegmentInfo->targetAddress;
      pBlockInfo->targetLength = pSegmentInfo->targetLength;
      pBlockInfo->logicalAddress = pSegmentInfo->logicalAddress;
      pBlockInfo->logicalLength = pSegmentInfo->logicalLength;

      pBlockInfo->readFct = (tFblMemVerifyReadFct)FblReadRam;
   }
#endif /* FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD */

   /* Add block to FblLib_Mem state machine */
   libMemResult = FblMemRemapStatus(FblMemBlockStartIndication(pBlockInfo));
   /* Check if FblLib_Mem reported an error */
   if (libMemResult != kDiagErrorNone)
   {
      FblDiagSetError(libMemResult);
      result = kFblFailed;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagSessionControlParamInit
 **********************************************************************************************************************/
/*! \brief         Initialization of session control request response.
 *  \param[in,out] pbDiagData Pointer to data in the diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Data length (without SID).
 **********************************************************************************************************************/
static void FblDiagSessionControlParamInit(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;   /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif

   /* Reset internal states */
   FblDiagClrPreconditionsChecked();
   FblDiagClrSecurityKeyAllowed();
   FblDiagClrSecurityUnlock();
   FblDiagClrFingerprintValid();
   FblDiagClrEraseSucceeded();
   FblDiagClrTransferDataAllowed();
   FblDiagClrTransferDataSucceeded();
   FblDiagClrChecksumAllowed();

   /* Reset variables */
   transferRemainder = 0u;
   /* Initialize flash driver download handling */
   FblDiagClrTransferTypeFlash();

   /* Initialize segment counter */
   FblDiagSegmentInit();

   /* Initialize security module */
   (void)ApplFblSecurityInit();

   /* Prepare diagnostic response */
   pbDiagData[kDiagLocFmtSubparam + 1u] = (vuint8)((kDiagSessionTimingP2 >> 8u) & 0xFFu);
   pbDiagData[kDiagLocFmtSubparam + 2u] = (vuint8)(kDiagSessionTimingP2 & 0xFFu);
   pbDiagData[kDiagLocFmtSubparam + 3u] = (vuint8)((kDiagSessionTimingP2Star >> 8u) & 0xFFu);
   pbDiagData[kDiagLocFmtSubparam + 4u] = (vuint8)(kDiagSessionTimingP2Star & 0xFFu);
}

/***********************************************************************************************************************
 *  FblDiagOemInitPowerOn
 **********************************************************************************************************************/
/*! \brief       Initialize module variables
 **********************************************************************************************************************/
void FblDiagOemInitPowerOn(void)
{
   expectedSequenceCnt = 0;
}

/***********************************************************************************************************************
 *  FblDiagOemPostInit
 **********************************************************************************************************************/
/*! \brief       Finish OEM specific initialization tasks
 **********************************************************************************************************************/
void FblDiagOemPostInit(void)
{
   /* Activate boot timeout counter in case an application software could be started */
   if (FblMainGetApplicationValid())
   {
      FblDiagSetBootTimeoutActive();
      bootTimeoutCounter = FBL_DIAG_BOOT_TIMOUT_COUNTER;
   }
}

/***********************************************************************************************************************
 *  FblDiagOemTimerTask
 **********************************************************************************************************************/
/*! \brief       This function handles the FBL Bootloader timeout
 *  \details     When a timeout occurs the startup code of the FBL is executed. Has to be executed from RAM
 *               if diagnostic functionality should be maintained while flashing, e.g. if pipelined programming
 *               is enabled.
 **********************************************************************************************************************/
void FblDiagOemTimerTask(void)
{
   /* Check if timer should be decremented */
   if (FblDiagGetBootTimeoutActive())
   {
      if (bootTimeoutCounter > 0u)
      {
         bootTimeoutCounter--;
      }
      else
      {
         /* Boot timeout counter expired. Start application */
         /* Deinitialize communication wrapper */
#if( FBL_CW_API_REFERENCE_VERSION_MAJOR == 0x02u )
         FblCw_Deinit();
#else
         FblCwDeinit();
#endif
# if defined( FBL_WATCHDOG_ON )
         /* Synchronize watchdog before application start */
         ApplFblWDLong();
# endif /* FBL_WATCHDOG_ON */
         /* Stop timer to avoid a timer interrupt
            after application start */
         FblTimerStopp();  /* PRQA S 3109 */ /* MD_MSR_14.3 */

         /* Start application code */
         ApplFblStartApplication();
      }
   }
}

/***********************************************************************************************************************
 *  FblDiagProcessServiceNrc
 **********************************************************************************************************************/
/*! \brief       This routine maps service check errors to NRCs
 *  \details     The checks done against the service table can be mapped to NRCs here. This function can be
 *               used as default NRC handler for services without sub-table entry.
 *  \param[in]   serviceErrorMask Error bit mask of table check
 *  \return      kFblOk/kFblFailed
 **********************************************************************************************************************/
static tFblResult FblDiagProcessServiceNrc(vuint32 serviceErrorMask)
{
   tFblResult result;

   /* Initialize variables */
   result = kFblOk;

   /* Check if service should be supported functionally and drop support if not */
   if ((serviceErrorMask & kFblDiagServiceNoFuncSupport) != 0u)
   {
      DiagSetNoResponse();
   }
   else
   {
      /* Service supported in active session? */
      if ((serviceErrorMask & kFblDiagServiceSessionFailure) == kFblDiagServiceSessionFailure)
      {
         DiagNRCServiceNotSupportedInActiveSession();
      }
      /* Minimum length check on service level */
      else if ((serviceErrorMask & kFblDiagServiceMinLenFailure) == kFblDiagServiceMinLenFailure)
      {
         DiagNRCIncorrectMessageLengthOrInvalidFormat();
      }
      /* Check for security access */
      else if ((serviceErrorMask & kFblDiagServiceSecAccessFailure) == kFblDiagServiceSecAccessFailure)
      {
         DiagNRCSecurityAccessDenied();
      }
      /* Pending length checks */
      else if ((serviceErrorMask & kFblDiagServiceLenFailure) == kFblDiagServiceLenFailure)
      {
         DiagNRCIncorrectMessageLengthOrInvalidFormat();
      }
      else if ((serviceErrorMask & kFblDiagServicePrehandlerFailure) == kFblDiagServicePrehandlerFailure)
      {
         /* Set default NRC if no NRC has been set in callout function. */
         if (DiagGetError() == kDiagErrorNone)
         {
            DiagNRCConditionsNotCorrect();
         }
      }
      /* Remaining, uncovered errors */
      else
      {
         DiagNRCGeneralReject();
      }
   }

   return result;
}  /* PRQA S 6080 */ /* MD_MSR_STMIF */

/***********************************************************************************************************************
 *  FblDiagProcessSubfunctionNrc
 **********************************************************************************************************************/
/*! \brief       This routine maps service check errors to NRCs
 *  \details     The checks done against the service table can be mapped to NRCs here. This function can be
 *               used as default NRC handler for services with sub-functions.
 *  \param[in]   serviceErrorMask Error bit mask of table check
 *  \return      kFblOk/kFblFailed
 **********************************************************************************************************************/
static tFblResult FblDiagProcessSubfunctionNrc(vuint32 serviceErrorMask)
{
   tFblResult result;

   /* Initialize variables */
   result = kFblOk;

   /* Check if service should be supported functionally and drop support if not */
   if ((serviceErrorMask & (kFblDiagServiceNoFuncSupport | kFblDiagSubNoFuncSupport)) != 0u)
   {
      DiagSetNoResponse();
   }
   else
   {
      /* Service supported in active session? */
      if ((serviceErrorMask & kFblDiagServiceSessionFailure) == kFblDiagServiceSessionFailure)
      {
         DiagNRCServiceNotSupportedInActiveSession();
      }
      /* Minimum length check on service level */
      else if ((serviceErrorMask & kFblDiagServiceMinLenFailure) == kFblDiagServiceMinLenFailure)
      {
         DiagNRCIncorrectMessageLengthOrInvalidFormat();
      }
      /* Check if sub-function is supported */
      else if ((serviceErrorMask & kFblDiagSubfunctionNotFound) == kFblDiagSubfunctionNotFound)
      {
#if defined( FBL_ENABLE_USERSUBFUNCTION )
         /* Subfunction not found in check
          * Call user handler to manage its own subfunction */
         FblDiagSetRcrRpAllowed();
         ApplDiagUserSubFunction(&DiagBuffer[kDiagFmtSubparam], DiagDataLength);
#else
         DiagNRCSubFunctionNotSupported();
#endif /* FBL_ENABLE_USERSUBFUNCTION */
      }
      /* Check if sub-parameter is supported */
      else if ((serviceErrorMask & kFblDiagSubparamNotFound) == kFblDiagSubparamNotFound)
      {
         DiagNRCRequestOutOfRange();
      }
      /* Check for security access (service level and sub-function level) */
      else if ((serviceErrorMask & (kFblDiagServiceSecAccessFailure | kFblDiagSubfuncSecAccessFailure | kFblDiagSubparamSecAccessFailure)) != 0u)
      {
         DiagNRCSecurityAccessDenied();
      }
      /* Pending length checks */
      else if ((serviceErrorMask & (kFblDiagServiceLenFailure | kFblDiagSubMinLenFailure | kFblDiagSubLenFailure)) != 0u)
      {
         DiagNRCIncorrectMessageLengthOrInvalidFormat();
      }
      /* Subfunction session check */
      else if ((serviceErrorMask & (kFblDiagSubfuncSessionFailure | kFblDiagSubparamSessionFailure)) != 0u)
      {
         DiagNRCSubfunctionNotSupportedInActiveSession();
      }
      else if ((serviceErrorMask & kFblDiagServicePrehandlerFailure) == kFblDiagServicePrehandlerFailure)
      {
         /* Set default NRC if no NRC has been set in callout function. */
         if (DiagGetError() == kDiagErrorNone)
         {
            DiagNRCConditionsNotCorrect();
         }
      }
      /* Remaining, uncovered errors */
      else
      {
         DiagNRCGeneralReject();
      }
   }

   return result;
}  /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  FblDiagProcessRoutineNrc
 **********************************************************************************************************************/
/*! \brief       This routine maps service check errors to NRCs
 *  \details     The checks done against the service table can be mapped to NRCs here. This function can
 *               be used as a NRC hanler for the routine control service.
 *  \param[in]   serviceErrorMask Error bit mask of table check
 *  \return      kFblOk/kFblFailed
 **********************************************************************************************************************/
static tFblResult FblDiagProcessRoutineNrc(vuint32 serviceErrorMask)
{
   tFblResult result;

   /* Initialize variables */
   result = kFblOk;

   /* Check if service should be supported functionally and drop support if not */
   if ((serviceErrorMask & (kFblDiagServiceNoFuncSupport | kFblDiagSubNoFuncSupport)) != 0u)
   {
      DiagSetNoResponse();
   }
   else
   {
      /* Service supported in active session? */
      if ((serviceErrorMask & kFblDiagServiceSessionFailure) == kFblDiagServiceSessionFailure)
      {
         DiagNRCServiceNotSupportedInActiveSession();
      }
      /* Minimum length check on service level */
      else if ((serviceErrorMask & kFblDiagServiceMinLenFailure) == kFblDiagServiceMinLenFailure)
      {
         DiagNRCIncorrectMessageLengthOrInvalidFormat();
      }
      /* Check if sub-parameter is supported */
      else if ((serviceErrorMask & kFblDiagSubparamNotFound) == kFblDiagSubparamNotFound)
      {
#if defined( FBL_ENABLE_USERROUTINE )
         /* Subfunction not found in check
          * Call user handler to manage its own subfunction */
         FblDiagSetRcrRpAllowed();
         ApplDiagUserRoutine(&DiagBuffer[kDiagFmtSubparam], DiagDataLength);
#else
         DiagNRCRequestOutOfRange();
#endif /* FBL_ENABLE_USERSUBFUNCTION */
      }
      /* Check if sub-function is supported */
      else if ((serviceErrorMask & kFblDiagSubfunctionNotFound) == kFblDiagSubfunctionNotFound)
      {
#if defined( FBL_ENABLE_USERSUBFUNCTION )
         /* Subfunction not found in check
          * Call user handler to manage its own subfunction */
         FblDiagSetRcrRpAllowed();
         ApplDiagUserSubFunction(&DiagBuffer[kDiagFmtSubparam], DiagDataLength);
#else
         DiagNRCSubFunctionNotSupported();
#endif /* FBL_ENABLE_USERSUBFUNCTION */
      }
      /* Check for security access (service level and sub-function level) */
      else if ((serviceErrorMask & (kFblDiagServiceSecAccessFailure | kFblDiagSubfuncSecAccessFailure | kFblDiagSubparamSecAccessFailure)) != 0u)
      {
         DiagNRCSecurityAccessDenied();
      }
      /* Pending length checks */
      else if ((serviceErrorMask & (kFblDiagServiceLenFailure | kFblDiagSubMinLenFailure | kFblDiagSubLenFailure)) != 0u)
      {
         DiagNRCIncorrectMessageLengthOrInvalidFormat();
      }
      /* Subfunction session check */
      else if ((serviceErrorMask & (kFblDiagSubfuncSessionFailure | kFblDiagSubparamSessionFailure)) != 0u)
      {
         DiagNRCSubfunctionNotSupportedInActiveSession();
      }
      else if ((serviceErrorMask & kFblDiagServicePrehandlerFailure) == kFblDiagServicePrehandlerFailure)
      {
         /* Set default NRC if no NRC has been set in callout function. */
         if (DiagGetError() == kDiagErrorNone)
         {
            DiagNRCConditionsNotCorrect();
         }
      }
      /* Remaining, uncovered errors */
      else
      {
         DiagNRCGeneralReject();
      }
   }

   return result;
}  /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  Diagnostic main handler service functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblDiagDefaultSessionMainHandler
 **********************************************************************************************************************/
/*! \brief         Default session request service handler.
 *  \param[in,out] pbDiagData Pointer to data in diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Data length (without SID).
 *  \return        Result: Always kFblOk.
 **********************************************************************************************************************/
static tFblResult FblDiagDefaultSessionMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
   vuint8 responseFlag;
#endif /* FBL_ENABLE_REPONSE_AFTER_RESET */

   if (FblDiagGetProgrammingSession())
   {
      /* Request bootloader reset */
      FblDiagSetWaitEcuReset();   /* PRQA S 3109 */ /* MD_FblDiag_3109 */

#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
      /* Send response pending before reset */
      DiagExRCRResponsePending(kForceSendResponsePending);

      /* Set flag for response after reset */
      responseFlag = RESET_RESPONSE_SDS_REQUIRED;
      (void)ApplFblWriteResetResponseFlag(&responseFlag);   /* PRQA S 3425 */ /* MD_FblDiag_3425 */
      /* Save target address */
      if (FblCwSaveResponseAddress() != kFblOk) /* PRQA S 3325 */ /* MD_MSR_14.1 */
      {  /* PRQA S 3201 */ /* MD_MSR_14.1 */
         /* If clause is necessary here to process return value or macro. However,
          * there is currently no strategy to handle this error. */
      }
#else
      /* Prepare response and reset states */
      FblDiagSessionControlParamInit(pbDiagData, diagReqDataLen);
      /* Send response */
      DiagProcessingDone(kDiagRslDiagnosticSessionControl);
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET */
      FblDiagSetEcuResetFctFinished();
   }
   else
   {
      /* Change to default session without issuing a reset */
      FblDiagSetDefaultSession();   /* PRQA S 3109 */ /* MD_FblDiag_3109 */

      /* Prepare response and reset states */
      FblDiagSessionControlParamInit(pbDiagData, diagReqDataLen);
      /* Send response */
      DiagProcessingDone(kDiagRslDiagnosticSessionControl);
   }

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagExtendedSessionMainHandler
 **********************************************************************************************************************/
/*! \brief         Extended session request service handler.
 *  \param[in,out] pbDiagData Pointer to data in diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Data length (without SID).
 *  \return        Result: Always kFblOk.
 **********************************************************************************************************************/
static tFblResult FblDiagExtendedSessionMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   /* Change to extended session */
   FblDiagSetExtendedSession();  /* PRQA S 3109 */ /* MD_FblDiag_3109 */

   /* Prepare response and reset states */
   if (FblDiagGetPreconditionsChecked())
   {  
      FblDiagSessionControlParamInit(pbDiagData, diagReqDataLen);
      FblDiagSetPreconditionsChecked();
   }
   else
   {
      FblDiagSessionControlParamInit(pbDiagData, diagReqDataLen);
   }

   /* Send response */
   DiagProcessingDone(kDiagRslDiagnosticSessionControl);

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagProgrammingSessionMainHandler
 **********************************************************************************************************************/
/*! \brief         Programming session request service handler.
 *  \param[in,out] pbDiagData Pointer to data in diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Data length (without SID).
 *  \return        Result: kFblOk if reprogramming conditions are fulfilled, kFblFailed if not.
 **********************************************************************************************************************/
static tFblResult FblDiagProgrammingSessionMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

   /* Check of programming preconditions done? */
#if defined( FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS )
   if ((!FblDiagGetPreconditionsChecked()) && (!FblMainGetStartFromAppl()))
#else
   if (ApplFblCheckProgConditions() != kFblOk)
#endif /* FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS */
   {
      /* Check of programming preconditions failed */
      FblErrStatSetError(FBL_ERR_FLASH_PROG_CONDITIONS);
      DiagNRCConditionsNotCorrect();
      result = kFblFailed;
   }
   else
   {
      /* Check of programming preconditions succeeded - switch to programming session */
      result = kFblOk;

      /* Change to programming session */
      FblDiagSetProgrammingSession();  /* PRQA S 3109 */ /* MD_FblDiag_3109 */

      /* Prepare response and reset states */
      FblDiagSessionControlParamInit(pbDiagData, diagReqDataLen);
      /* Send response */
      DiagProcessingDone(kDiagRslDiagnosticSessionControl);
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagEcuResetMainHandler
 **********************************************************************************************************************/
/*! \brief         Function manages the EcuReset service request
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        Result: Always kFblOk.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblDiag_3673 */
static tFblResult FblDiagEcuResetMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
   vuint8 responseFlag;
#endif /* FBL_ENABLE_REPONSE_AFTER_RESET */

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 2 */ /* MD_MSR_14.2 */
   (void)diagReqDataLen;
   (void)pbDiagData;
#endif

   /* Request bootloader reset */
   FblDiagSetWaitEcuReset();   /* PRQA S 3109 */ /* MD_FblDiag_3109 */

#if defined( FBL_ENABLE_RESPONSE_AFTER_RESET )
   /* Send response pending before reset */
   DiagExRCRResponsePending(kForceSendResponsePending);

   /* Set flag for response after reset */
   responseFlag = RESET_RESPONSE_ECURESET_REQUIRED;
   (void)ApplFblWriteResetResponseFlag(&responseFlag);   /* PRQA S 3425 */ /* MD_FblDiag_3425 */
   /* Save target address */
   if (FblCwSaveResponseAddress() != kFblOk) /* PRQA S 3325 */ /* MD_MSR_14.1 */
   {  /* PRQA S 3201 */ /* MD_MSR_14.1 */
      /* If clause is necessary here to process return value or macro. However,
       * there is currently no strategy to handle this error. */
   }
#else
   /* Send response */
   DiagProcessingDone(kDiagRslEcuReset);
#endif /* FBL_ENABLE_RESPONSE_AFTER_RESET */
   FblDiagSetEcuResetFctFinished();

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagSecurityAccessLengthCheck
 **********************************************************************************************************************/
/*! \brief         Lenght check function for Security Access service.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Length of data (without SID).
 *  \return        kFblOk: Length check OK; kFblFailed: Length check failed
 **********************************************************************************************************************/
static tFblResult FblDiagSecurityAccessLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen) /* PRQA S 3673 */ /* MD_FblDiag_3673 */
{
   vuint8 result;

   /* Initialize return value */
   result = kFblOk;

   if (pbDiagData[0] == kFblDiagSubSendKey)
   {
      if (diagReqDataLen != kDiagRqlSecurityAccessKey)
      {
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
         /* If a security key is expected but the request length is not correct, set delay flag    *
            * in NV-memory but do not activate delay timer.                                          */
         if (FblDiagGetSecurityKeyAllowed())
         {
            /* New seed must be requested */
            FblDiagClrSecurityKeyAllowed();

            /* Send response pending for following NV-access */
            DiagExRCRResponsePending(kForceSendRpIfNotInProgress);

            /* Read invalid access counter */
            if (ApplFblReadSecAccessInvalidCount(&secSendKeyInvalid) != kFblOk)
            {
               /* If read failed set default value */
               secSendKeyInvalid = (kSecMaxInvalidKeys - 1u);
            }
   
            secSendKeyInvalid++;

            (void)ApplFblWriteSecAccessInvalidCount(&secSendKeyInvalid);
         }
#endif
         /* Send NRC 0x13 - incorrectMessageLength */
         result = kFblFailed;
      }
   }
   return result;
}

/***********************************************************************************************************************
 *  FblDiagSecAccessSeedMainHandler
 **********************************************************************************************************************/
/*! \brief         Request Seed request main handler.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagSecAccessSeedMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;   /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif

   /* Initialize variables */
   result = kFblOk;

#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
   /* Check if security level is locked (delay counter is active) */
   if (GetSecurityAccessDelay() > 0u)
   {
      DiagNRCRequiredTimeDelayNotExpired();
      result = kFblFailed;
   }
#endif /* FBL_ENABLE_SEC_ACCESS_DELAY */

   if (result == kFblOk)
   {
      /* Check if security level is already active */
      if (FblDiagGetSecurityUnlock())
      {
         vuintx i;

         /* ECU is already unlocked, send zero seed */
         for (i = 0; i < kSecSeedLength; i++)
         {
            pbDiagData[kDiagLocFmtSeedKeyStart + i] = 0x00u;
         }
      }
      else
      {
         /* Generate seed by application function */
         if (ApplFblSecuritySeed() == kFblOk)
         {
            /* Accept security key next */
            FblDiagSetSecurityKeyAllowed();
         }
         else
         {
            /* Error occurred during seed computation */
            FblErrStatSetError(FBL_ERR_SEED_GENERATION_FAILED);
            DiagNRCConditionsNotCorrect();
            result = kFblFailed;
         }
      }
   }

   /* Send positive response if seed was computed correctly */
   if (result == kFblOk)
   {
      DiagProcessingDone(kDiagRslSecurityAccessSeed);
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagSecAccessKeyMainHandler
 **********************************************************************************************************************/
/*! \brief         Send Key request main handler.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblDiag_3673 */
static tFblResult FblDiagSecAccessKeyMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 2 */ /* MD_MSR_14.2 */
   (void)diagReqDataLen;
   (void)pbDiagData;
#endif

   /* Check preconditions for key processing */
   if (    (!FblDiagGetSecurityKeyAllowed())
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
        || (GetSecurityAccessDelay() > 0u)
#endif /* FBL_EANBLE_SECURITY_ACCESS_DELAY */
      )
   {
      DiagNRCRequestSequenceError();
      result = kFblFailed;
   }
   else
   {
      /* Send response pending */
      DiagExRCRResponsePending(kForceSendResponsePending);

      /* No second key allowed for this seed */
      FblDiagClrSecurityKeyAllowed();

      /* Check security access key in application function */
      if (ApplFblSecurityKey() == kFblOk)
      {
         /* Security access successful */
         FblDiagSetSecurityUnlock();
         result = kFblOk;
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
         /* Reset invalid counter */
         secSendKeyInvalid = 0u;
         /* Reset flags in non-volatile memory */
         (void)ApplFblClrSecAccessDelayFlag();
         (void)ApplFblWriteSecAccessInvalidCount(&secSendKeyInvalid);
#endif /* FBL_ENABLE_SEC_ACCESS_DELAY */
      }
      else
      {
         result = kFblFailed;
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
         /* Read invalid access counter */
         if (ApplFblReadSecAccessInvalidCount(&secSendKeyInvalid) != kFblOk)
         {
            /* If read failed set default value */
            secSendKeyInvalid = (kSecMaxInvalidKeys - 1u);
         }

         secSendKeyInvalid++;

         if (secSendKeyInvalid >= kSecMaxInvalidKeys)
         {
            /* Too many invalid security attempts, enable security access delay */
            SetSecurityAccessDelay();
            (void)ApplFblSetSecAccessDelayFlag();

            DiagNRCExceedNumberOfAttempts();
         }
         else
         {
            /* Write counter to non-volatile memory */
            (void)ApplFblWriteSecAccessInvalidCount(&secSendKeyInvalid);

            DiagNRCInvalidKey();
         }
#else
         DiagNRCInvalidKey();
#endif /* FBL_ENABLE_SEC_ACCESS_DELAY */
      }
   }

   if (result == kFblOk)
   {
      DiagProcessingDone(kDiagRslSecurityAccessKey);
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagSecAccessSeedAuthPrgMainHandler
 **********************************************************************************************************************/
/*! \brief         Request Seed request main handler for authenticated reprogramming.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagSecAccessSeedAuthPrgMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;   /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif

   /* Initialize variables */
   result = kFblOk;

#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
   /* Check if security level is locked (delay counter is active) */
   if (GetSecurityAccessDelay() > 0u)
   {
      DiagNRCRequiredTimeDelayNotExpired();
      result = kFblFailed;
   }
#endif /* FBL_ENABLE_SEC_ACCESS_DELAY */

   if (result == kFblOk)
   {
      /* Check if security level is already active */
      if (FblDiagGetSecurityUnlock())
      {
         vuintx i;

         /* ECU is already unlocked, send zero seed */
         for (i = 0; i < kSecSeedLength; i++)
         {
            pbDiagData[kDiagLocFmtSeedKeyStart + i] = 0x00u;
         }
      }
      else
      {
         /* Generate seed by application function */
         if (ApplFblSecuritySeed() == kFblOk)
         {
            /* Accept security key next */
            FblDiagSetSecurityKeyAllowed();
         }
         else
         {
            /* Error occurred during seed computation */
            FblErrStatSetError(FBL_ERR_SEED_GENERATION_FAILED);
            DiagNRCConditionsNotCorrect();
            result = kFblFailed;
         }
      }
   }

   /* Send positive response if seed was computed correctly */
   if (result == kFblOk)
   {
      DiagProcessingDone(kDiagRslSecurityAccessSeed);
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagSecAccessKeyAuthPrgMainHandler
 **********************************************************************************************************************/
/*! \brief         Send Key request main handler.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblDiag_3673 */
static tFblResult FblDiagSecAccessKeyAuthPrgMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 2 */ /* MD_MSR_14.2 */
   (void)diagReqDataLen;
   (void)pbDiagData;
#endif

   /* Check preconditions for key processing */
   if (    (!FblDiagGetSecurityKeyAllowed())
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
        || (GetSecurityAccessDelay() > 0u)
#endif /* FBL_EANBLE_SECURITY_ACCESS_DELAY */
      )
   {
      DiagNRCRequestSequenceError();
      result = kFblFailed;
   }
   else
   {
      /* Send response pending */
      DiagExRCRResponsePending(kForceSendResponsePending);

      /* No second key allowed for this seed */
      FblDiagClrSecurityKeyAllowed();

      /* Check security access key in application function */
      if (ApplFblSecurityKey() == kFblOk)
      {
         /* Security access successful */
         FblDiagSetSecurityUnlock();
         result = kFblOk;
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
         /* Reset invalid counter */
         secSendKeyInvalid = 0u;
         /* Reset flags in non-volatile memory */
         (void)ApplFblClrSecAccessDelayFlag();
         (void)ApplFblWriteSecAccessInvalidCount(&secSendKeyInvalid);
#endif /* FBL_ENABLE_SEC_ACCESS_DELAY */
      }
      else
      {
         result = kFblFailed;
#if defined( FBL_ENABLE_SEC_ACCESS_DELAY )
         /* Read invalid access counter */
         if (ApplFblReadSecAccessInvalidCount(&secSendKeyInvalid) != kFblOk)
         {
            /* If read failed set default value */
            secSendKeyInvalid = (kSecMaxInvalidKeys - 1u);
         }

         secSendKeyInvalid++;

         if (secSendKeyInvalid >= kSecMaxInvalidKeys)
         {
            /* Too many invalid security attempts, enable security access delay */
            SetSecurityAccessDelay();
            (void)ApplFblSetSecAccessDelayFlag();

            DiagNRCExceedNumberOfAttempts();
         }
         else
         {
            /* Write counter to non-volatile memory */
            (void)ApplFblWriteSecAccessInvalidCount(&secSendKeyInvalid);

            DiagNRCInvalidKey();
         }
#else
         DiagNRCInvalidKey();
#endif /* FBL_ENABLE_SEC_ACCESS_DELAY */
      }
   }

   if (result == kFblOk)
   {
      DiagProcessingDone(kDiagRslSecurityAccessKey);
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagDataByIdLengthCheck
 **********************************************************************************************************************/
/*! \brief         Read/WriteDataByIdentifier service dynamic length check.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Length of data (without SID).
 *  \return        kFblOk: Length check OK; kFblFailed: Length check failed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblDiag_3673 */
static tFblResult FblDiagDataByIdLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 2 */ /* MD_MSR_14.2 */
   (void)pbDiagData;
   (void)diagReqDataLen;
#endif

   /* Nothing to do here. Length check should be done in corresponding user callback function. */
   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagWriteDataByIdMainHandler
 **********************************************************************************************************************/
/*! \brief         WriteDataByIdentifier service, handling of fingerprint and identification data.
 *  \pre           Request only accepted after successful security access procedure.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID).
 *  \param[in]     diagReqDataLen Length of data (without SID).
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagWriteDataByIdMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;
   vuint16 dataIdentifier;
   vuint8 blockIndex;
   vuint8 blockType;

   dataIdentifier = ((vuint16)((vuint16)pbDiagData[kDiagLocFmtDataIdHigh] << 8u)) | ((vuint16)pbDiagData[kDiagLocFmtDataIdLow]);
   if (     (dataIdentifier != kFblDiagDidBootSwFingerprintWrite) 
      &&    (dataIdentifier != kFblDiagDidApplSwFingerprintWrite) 
      &&    (dataIdentifier != kFblDiagDidApplDataFingerprintWrite))
   {
      /* Call user callout function for non-fingerprint DIDs */
      result = ApplFblWriteDataByIdentifier(pbDiagData, diagReqDataLen); 
   }
   else
   {
      result = kFblOk;
      blockIndex = 0xFFu;
      blockType = kBlockTypeNone;

      /* Check request length */
      if (diagReqDataLen != kDiagRqlWriteDataByIdentifierFingerPrint)
      {
         DiagNRCIncorrectMessageLengthOrInvalidFormat();
         result = kFblFailed;
      }
      
      if (result == kFblOk)
      {
         /* Check if logical block number is valid */
         if (pbDiagData[kDiagLocFmtDataRecord] >= FBL_MTAB_NO_OF_BLOCKS)
         {
            /* Unsupported logical block number */
            DiagNRCRequestOutOfRange();
            result = kFblFailed;
         }
      }

      if (result == kFblOk)
      {
         /* Logical block hash must be checked prior to the fingerprint */
         if (!FblDiagGetLogBlockHashRequested())
         {
            DiagNRCConditionsNotCorrect();
            result = kFblFailed;
         }
      }

      if (result == kFblOk)
      {
         {
            switch(dataIdentifier)
            {
               case kFblDiagDidBootSwFingerprintWrite:
               {
                  blockType = kBlockTypeBoot;
                  break;
               }

               case kFblDiagDidApplSwFingerprintWrite:
               {
                  blockType = kBlockTypeCode;
                  break;
               }

               case kFblDiagDidApplDataFingerprintWrite:
               {
                  blockType = kBlockTypeData;
                  break;
               }

               default:
               {
                  blockType = kBlockTypeNone;
                  result = kFblFailed;
                  break;
               }
            }
         }
      }

      if (result == kFblOk)
      {
         blockIndex = pbDiagData[kDiagLocFmtDataRecord];

         /* Initialize error status block number */
         FblErrStatSetBlockNr(blockIndex);

         /* Check block type of logical block configuration */
         if (FblLogicalBlockTable.logicalBlock[blockIndex].blockType == blockType)
         {
            result = FblDiagCheckProgAttemptCounter((tBlockDescriptor *)(&FblLogicalBlockTable.logicalBlock[blockIndex]));
            if (result == kFblOk)
            {
               /* Store fingerprint */
               result = ApplFblStoreFingerprint(&pbDiagData[kDiagLocFmtDataRecord + 1u]);
            }
            else
            {
               /* Reached maximum number of programming attempts - reject programming attempt */
               DiagNRCGeneralProgrammingFailure();
            }
         }
         else
         {
            /* Unsupported logical block type */
            DiagNRCRequestOutOfRange();
            result = kFblFailed;
         }
      }

      /* Init block descriptor */
      if (result == kFblOk)
      {
         /* Initialize blockdescriptor with currently active logical block*/
         downloadBlockDescriptor = FblLogicalBlockTable.logicalBlock[blockIndex];

         /* Fingerprint accepted */
         FblDiagSetFingerprintValid();     
      }
   }

   if (DiagGetError() != kDiagErrorNone)
   {
      /* NRC already set - do nothing */
      result = kFblFailed;
   }
   else
   {
      /* Send positive response */
      DiagProcessingDone(kDiagRslWriteDataByIdentifier);
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagRCStartBootBlockHash - StartRoutine-CalcChecsum
 **********************************************************************************************************************/
/*! \brief       Run the hash calculation prior to the flash download.
 *  \param[in]   pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]   diagReqDataLen Length of data (without SID)
 *  \return      kFblOk:     service processed successfully (goto next state)
 *               kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStartBootBlockHashMainHandler (vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* parameter not used */
   (void)diagReqDataLen; /* PRQA S 3112 */ /* MD_FblDiag_3112 */
#endif

   return FblDiagCommonBlockHashMainHandler(kBlockTypeBoot, pbDiagData); 
}

/***********************************************************************************************************************
 *  FblDiagRCStartBootBlockHash - StartRoutine-CalcChecsum
 **********************************************************************************************************************/
/*! \brief       Run the hash calculation prior to the flash download.
 *  \param[in]   pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]   diagReqDataLen Length of data (without SID)
 *  \return      kFblOk:     service processed successfully (goto next state)
 *               kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStartApplBlockHashMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* parameter not used */
   (void)diagReqDataLen; /* PRQA S 3112 */ /* MD_FblDiag_3112 */
#endif

   return FblDiagCommonBlockHashMainHandler(kBlockTypeCode, pbDiagData); 
}

/***********************************************************************************************************************
 *  FblDiagRCStartBootBlockHash - StartRoutine-CalcChecsum
 **********************************************************************************************************************/
/*! \brief       Run the hash calculation prior to the flash download.
 *  \param[in]   pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]   diagReqDataLen Length of data (without SID)
 *  \return      kFblOk:     service processed successfully (goto next state)
 *               kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStartDataBlockHashMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* parameter not used */
   (void)diagReqDataLen; /* PRQA S 3112 */ /* MD_FblDiag_3112 */
#endif

   return FblDiagCommonBlockHashMainHandler(kBlockTypeData, pbDiagData); 
}

#if defined( FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS )
/***********************************************************************************************************************
 *  FblDiagRCStartCheckProgPreCondMainHandler
 **********************************************************************************************************************/
/*! \brief         Check Programming Preconditions service function
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblDiag_3673 */
static tFblResult FblDiagRCStartCheckProgPreCondMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 2 */ /* MD_MSR_14.2 */
   (void)pbDiagData;
   (void)diagReqDataLen;
# endif

   /* Clear status variables */
   FblDiagClrFingerprintValid();

   /* Check for preconditions - response should be prepared in callback function */
   if (ApplFblCheckProgPreconditions(pbDiagData, diagReqDataLen) == kFblOk)
   {
      FblDiagSetPreconditionsChecked();
   }
   else
   {
      FblDiagClrPreconditionsChecked();
   }

   /* DiagProcessingDone is called from callback function */
   return kFblOk;
}
#endif /* FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS */

/***********************************************************************************************************************
 *  FblDiagRCStartCheckProgramLengthCheck
 **********************************************************************************************************************/
/*! \brief         Routine Control - Check Program length check
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: Length of check program request is OK; kFblFailed: Length check failed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblDiag_3673 */
static tFblResult FblDiagRCStartCheckProgramLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

   if ( diagReqDataLen == kDiagRqlRoutineControlCheckProgram)
   {
      result = kFblOk;
   }
   else
   {
      result = kFblFailed;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagRCStartCheckProgramMainHandler
 **********************************************************************************************************************/
/*! \brief         Routine Control - Check Program.
 *  \pre           Data to be checked has been downloaded to the corresponding memory.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStartCheckProgramMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblDiagNrc serviceNrc;
   vuint8 checkResult;
   tFblResult result;

   /* Initialize variables */
   serviceNrc = kDiagErrorNone;
   checkResult = kDiagCheckVerificationFailed;

   /* Check state flags */
   if (    (!FblDiagGetFingerprintValid())
        || (!FblDiagGetTransferDataSucceeded())
        || (!FblDiagGetChecksumAllowed())
      )
   {
      serviceNrc = kDiagNrcConditionsNotCorrect;
   }

   if (serviceNrc == kDiagErrorNone)
   {

      /* Invoke LibMem block end indication */
      serviceNrc = FblMemRemapStatus(FblMemBlockEndIndication());
   }

   if (serviceNrc == kDiagErrorNone)
   {
      /* Watchdog and response pending handling */
      (void)FblRealTimeSupport();

      /* Do verification */
#if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT )
      (void)SecM_InitVerification(V_NULL);
#endif /* FBL_MEM_ENABLE_VERIFY_OUTPUT */
      checkResult = FblDiagDownloadCheck(pbDiagData, diagReqDataLen);
#if defined( FBL_MEM_ENABLE_VERIFY_OUTPUT )
      (void)SecM_DeinitVerification(V_NULL);
#endif /* FBL_MEM_ENABLE_VERIFY_OUTPUT */
   }
   else
   {
      /* Prepare NRC possibly set before */
      FblDiagSetError(serviceNrc);
   }

   if (DiagGetError() != kDiagErrorNone)
   {
      /* NRC already set - do nothing */
      result = kFblFailed;
   }
   else
   {
      /* No NRC set - submit positive response */
      pbDiagData[kDiagLocFmtRoutineStatus] = checkResult;
      DiagProcessingDone(kDiagRslRoutineControlCheckRoutine);
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagRCStartEraseMainHandler
 **********************************************************************************************************************/
/*! \brief         Routine Control - Erase Memory.
 *  \pre           Fingerprint is available, memory driver initialized.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStartEraseMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblAddress memoryAddress;
   tFblLength memorySize;

   tFblResult result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;   /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif

   /* Verify all erase preconditions are fulfilled */
   result = FblDiagCheckErasePreconditions(pbDiagData, &memoryAddress, &memorySize);

   if (result == kFblOk)
   {
      /* Send response pending in case of long NV accesses */
      DiagExRCRResponsePending(kForceSendResponsePending);

      /* Invalidate logical block to be erased */
      if (ApplFblInvalidateBlock(downloadBlockDescriptor) != kFblOk)
      {
         /* Block could not be invalidated or programming attempt counter could not be stored */
         DiagNRCConditionsNotCorrect();
         result = kFblFailed;
      }
   }

   if (result == kFblOk)
   {
      (void)FblRealTimeSupport();

#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
      /* Determine the flash memory status               *
       * Programming attempt counter increment only if   *
       * flash is not erased.                            */
      erasedStatus = FblDiagGetEraseState();

      if (erasedStatus == kFlashNotErased)
#endif
      {
         /* Increase programming attempt counter */
         if (ApplFblIncProgAttempts(downloadBlockDescriptor) != kFblOk)
         {
            DiagNRCConditionsNotCorrect();
            result = kFblFailed;
         }
      }
   }

   if (result == kFblOk)
   {
      result = FblDiagEraseBlock(&downloadBlockDescriptor);
      if (result == kFblOk)
      {
         /* Update Programming Status */
         (void)ApplFblProgStatusEraseUpdate(kDiagProgStatEraseSucceeded);

         /* Prepare positive response */
         pbDiagData[kDiagLocFmtRoutineStatus] = kDiagEraseMemoryOk;
      }
      else
      {
         /* Update Programming Status */
         (void)ApplFblProgStatusEraseUpdate(kDiagProgStatEraseFailed_General);

         /* Prepare positive response with error code*/
         pbDiagData[kDiagLocFmtRoutineStatus] = kDiagEraseMemoryFailed;
      }
   }

   /* Send positive response in case no NRC is set */
   if (DiagGetError() == kDiagErrorNone)
   {
      DiagProcessingDone(kDiagRslRoutineControlEraseRoutine);
   }

   return result;
}  /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

/***********************************************************************************************************************
 *  FblDiagRCStartCheckProgDepMainHandler
 **********************************************************************************************************************/
/*! \brief         Check program dependencies
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRCStartCheckProgDepMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;
   vuint8 dependencyStatus;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;   /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif

   if (!FblDiagGetLogBlockHashRequested())
   {
      DiagNRCConditionsNotCorrect();
      result = kFblFailed;
   }
   else
   {
      /* Call function to check programming dependencies */
      dependencyStatus = ApplFblCheckProgDependencies();
      
      if (dependencyStatus == kDiagCheckCompatibilityOk )
      {
         if (ApplFblValidateApp() != kFblOk )
         {
            dependencyStatus = kDiagCheckCompatibilityFailed;
         }
      }

      if (dependencyStatus == kDiagCheckCompatibilityOk )
      {
         DiagProcessingDone(kDiagRslRoutineControlCheckRoutine);
         result = kFblOk;
      }
      else
      {
         DiagNRCGeneralProgrammingFailure();
         result = kFblFailed;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagRequestDownloadLengthCheck
 **********************************************************************************************************************/
/*! \brief         Request download length check
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: Length of check request is OK; kFblFailed: Length check failed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblDiag_3673 */
static tFblResult FblDiagRequestDownloadLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

   vuint8 addrFormat;
   vuint8 lengthFormat;

   /* Get length and address format from message */
   lengthFormat = (vuint8)((pbDiagData[kDiagLocFmtFormatOffset] & 0xF0u) >> 4u);
   addrFormat   = (vuint8)(pbDiagData[kDiagLocFmtFormatOffset] & 0x0Fu);

   /* Check length of request against calculated length */
   if(diagReqDataLen != (kDiagRqlRequestDownload + lengthFormat + addrFormat))
   {
      result = kFblFailed;
   }
   else
   {
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagRequestDownloadMainHandler
 **********************************************************************************************************************/
/*! \brief         Request download service function
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagRequestDownloadMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblMemBlockInfo blockInfo;
   tFblMemSegmentInfo segmentInfoLocal;
   tFblResult result;
   tFblDiagNrc libMemResult;
   vuint8 verifyBlockNr;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;   /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif

   /* Initialize variables */
   segmentInfoLocal.logicalAddress = 0u;
   segmentInfoLocal.logicalLength = 0u;
   verifyBlockNr = 0u;

   /* Verify all programming preconditions are fulfilled. Get address and length (logical) from request */
   result = FblDiagCheckRequestDownloadPreconditions(pbDiagData, &segmentInfoLocal);

#if defined( FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD )
   /* Flash Driver download? */
   if (result == kFblOk)
   {
      result = FblDiagCheckForFlashDriverDownload(&verifyBlockNr, &segmentInfoLocal);
   }
#else
   FblDiagSetTransferTypeFlash();
   segmentInfoLocal.type = kFblMemType_ROM;
#endif /* FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD */

   if (result == kFblOk)
   {
      /* Get length from request */
      transferRemainder = segmentInfoLocal.logicalLength;

      /* Initialize error status address */
      FblErrStatSetAddress(segmentInfoLocal.logicalAddress);

      /* Init expected sequence counter for TransferData */
      expectedSequenceCnt = kDiagInitSequenceNum;
      /* Init current sequence counter for TransferData */
      currentSequenceCnt = kDiagInitSequenceNum;

      /* Prepare download of application or flash driver. Target addresses are valid after these calls */
      if (FblDiagGetTransferTypeFlash())
      {
         result = FblDiagCheckFlashMemoryDownload(&segmentInfoLocal);
      }
#if defined( FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD )
      else
      {
         result = FblDiagCheckFlashDriverDownload(&segmentInfoLocal);
      }
#endif /* FBL_DIAG_ENABLE_FLASHDRV_DOWNLOAD */
   }

   /* First download segment */
   if ((result == kFblOk) && (segmentCount <= 1u))
   {
      result = FblDiagPrepareFirstDownloadSegment(&blockInfo, &segmentInfoLocal, verifyBlockNr);
      pbDiagData = FblDiagMemGetActiveBuffer(); /* PRQA S 3198 */ /* MD_FblDiag_319x */
   }

   /* Add segment data to FblLib_Mem */
   if (result == kFblOk)
   {
      /* Indicate start of new segment */
      libMemResult = FblMemRemapStatus(FblMemSegmentStartIndication(&segmentInfoLocal));
      pbDiagData = FblDiagMemGetActiveBuffer();
      if (libMemResult == kDiagErrorNone)
      {
         /* Init expected sequence counter for TransferData */
         expectedSequenceCnt = kDiagInitSequenceNum;
         /* Init current sequence counter for TransferData */
         currentSequenceCnt = kDiagInitSequenceNum;

         /* Now allow reception of TransferData */
         FblDiagSetTransferDataAllowed();
         FblDiagClrTransferDataSucceeded();
         FblDiagClrChecksumAllowed();

         /* Prepare response */
         pbDiagData[kDiagLocFmtSubparam] = (FBL_DIAG_RESPONSE_BUFFER_LFI << 4u);
         FblMemSetInteger(FBL_DIAG_RESPONSE_BUFFER_LFI, FBL_DIAG_RESPONSE_BUFFER_SIZE, &pbDiagData[kDiagLocFmtSubparam + 1u]);

         DiagProcessingDone(kDiagRslRequestDownload + FBL_DIAG_RESPONSE_BUFFER_LFI);
      }
      else
      {
         /* Set NRC provided by FblLib_Mem */
         FblDiagSetError(libMemResult);
         result = kFblFailed;
      }
   }

   return result;
}  /* PRQA S 6050 */ /* MD_MSR_STCAL */

/***********************************************************************************************************************
 *  FblDiagTransferDataLengthCheck
 **********************************************************************************************************************/
/*! \brief         Transfer data length check
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: Length of transfer data service is OK; kFblFailed: Length check failed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblDiag_3673 */
static tFblResult FblDiagTransferDataLengthCheck(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;       /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif

   if ((diagReqDataLen <= (kDiagRqlTransferData)) || (diagReqDataLen > (tTpDataType)(FBL_DIAG_RESPONSE_BUFFER_SIZE - 1u)))
   {
      /* Requested transfer length is larger than indicated data length */
      FblDiagClrTransferDataAllowed();
      result = kFblFailed;
   }
   else
   {
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagTransferDataMainHandler
 **********************************************************************************************************************/
/*! \brief         TransferData service function;
 *  \pre           TransferData must be enabled by RequestDownload service
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblDiag_3673 */
static tFblResult FblDiagTransferDataMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;
   tFblDiagNrc libMemResult;
   tFblLength transferDataLength;
#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
   vuint8 memoryStatus;
#endif

   if (!FblDiagGetTransferDataAllowed())
   {
      DiagNRCRequestSequenceError();
      result = kFblFailed;
   }
   /* Check if the requested sequence number is expected */
   else if (pbDiagData[kDiagLocFmtSubparam] != expectedSequenceCnt)
   {
      /* Check if sequence number corresponds to a retransmission of the last message */
      if (pbDiagData[kDiagLocFmtSubparam] == currentSequenceCnt)
      {
         /* Repetition of last transferData request
          * Simply send a positive response without loading data to memory */
         DiagProcessingDone(kDiagRslTransferData);
         result = kFblOk;
      }
      else /* Sequence number is not for a retry */
      {
         /* Send a WrongSequenceError */
         DiagNRCWrongBlockSequenceCounter();
         result = kFblFailed;
      }
   }
   else
   {
      result = kFblOk;
      /* Length without sequence counter byte */
      transferDataLength = diagReqDataLen - 1u;

#if defined( FBL_ENABLE_FLASH_ERASED_DETECTION )
      if (erasedStatus == kFlashErased)
      {
         erasedStatus = kFlashNotErased;
         memoryStatus = kDiagMemStatProgrammed;

         /* Update memory status in NVM just before flash programming starts */
         if (ApplFblWriteMemoryStatus(downloadBlockDescriptor.blockNr, &memoryStatus) != kFblOk)
         {
            DiagNRCConditionsNotCorrect();
            result = kFblFailed;
         }
      }
#endif
      if (result == kFblOk)
      {
         /* Indicate data to FblLib_Mem */
         FblDiagClrEraseSucceeded();
         libMemResult = FblMemRemapStatus(FblMemDataIndication(DiagBuffer, kDiagFmtDataOffset, transferDataLength));

         /* Caution: Depending on configuration, DiagBuffer pointer may change. */
         pbDiagData = FblDiagMemGetActiveBuffer(); /* PRQA S 3199 */ /* MD_FblDiag_319x */
         if (libMemResult == kDiagErrorNone)
         {
            /* Memorize current counter */
            currentSequenceCnt = expectedSequenceCnt;
            /* Sequence counter value of next transferData request
             * Note: We do not rely on an implicit 8-bit caused overflow at 256, which does not happen on certain platforms */
            expectedSequenceCnt = ((expectedSequenceCnt + 1u) & 0xFFu);

            DiagProcessingDone(kDiagRslTransferData);
            result = kFblOk;
         }
         else
         {
            FblDiagSetError(libMemResult);
            FblDiagClrTransferDataAllowed();
            result = kFblFailed;
         }
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagReqTransferExitMainHandler
 **********************************************************************************************************************/
/*! \brief         RequestTransferExit service function
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblDiag_3673 */
static tFblResult FblDiagReqTransferExitMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;
   tFblDiagNrc libMemResult;
   tFblLength  totalProgramLength;  /* Total number of programmed bytes */

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 2 */ /* MD_MSR_14.2 */
   (void)pbDiagData;
   (void)diagReqDataLen;
#endif

   /* Do sequence and parameter checks */
   if (!FblDiagGetTransferDataAllowed())
   {
      DiagNRCRequestSequenceError();
      result = kFblFailed;
   }
   else
   {
      FblDiagClrTransferDataAllowed();

      /* Finalize programming of current segment */
      libMemResult = FblMemRemapStatus((FblMemSegmentEndIndication(&totalProgramLength)));
      pbDiagData = FblDiagMemGetActiveBuffer(); /* PRQA S 3199 */ /* MD_FblDiag_319x */

      if (libMemResult == kDiagErrorNone)
      {
         /* RequestTransferExit was successful */
         FblDiagSetTransferDataSucceeded();
         FblDiagSetChecksumAllowed();
         DiagProcessingDone(kDiagRslRequestTransferExit);
         result =  kFblOk;
      }
      else
      {
         /* Set return value of FblLib_Mem as NRC */
         FblDiagSetError(libMemResult);
         result = kFblFailed;
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagTesterPresentMainHandler
 **********************************************************************************************************************/
/*! \brief         FblTesterPresent service function.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblDiag_3673 */
static tFblResult FblDiagTesterPresentMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */ /* PRQA S 3112 2 */ /* MD_MSR_14.2 */
   (void)pbDiagData;
   (void)diagReqDataLen;
#endif

   DiagProcessingDone(kDiagRslTesterPresent);

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagReadDataByIdMainHandler
 **********************************************************************************************************************/
/*! \brief         ReadDataByIdentifier service function
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 *********************************************************************************************************************/
static tFblResult FblDiagReadDataByIdMainHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   ApplFblReadDataByIdentifier(pbDiagData, diagReqDataLen);

   return kFblOk;
}

/***********************************************************************************************************************
 *  FblDiagCommonBlockHashMainHandler
 **********************************************************************************************************************/
/*! \brief       Run the hash calculation prior to the flash download for all block types.
 *  \param[in]   pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]   diagReqDataLen Length of data (without SID)
 *  \return      kFblOk:     service processed successfully (goto next state)
 *               kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagCommonBlockHashMainHandler(vuint8 blockType, vuint8 *pbDiagData)
{
   vuint8 blockIndex;  
   tFblResult result;

   result = kFblOk;

   /* Check if logical block number is valid */
   if (pbDiagData[kDiagLocFmtRoutineStatus] >= FBL_MTAB_NO_OF_BLOCKS)  // ToDo: no of boot blocks
   {
      /* Unsupported logical block number */
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }

   if (result == kFblOk)
   {
      blockIndex = pbDiagData[kDiagLocFmtRoutineStatus];

      /* Initialize error status block number */
      FblErrStatSetBlockNr(blockIndex);

      /* Check block type of logical block configuration */
      if (FblLogicalBlockTable.logicalBlock[blockIndex].blockType == blockType)
      {
         /* Get hash of requested logical block */
         if (ApplFblGetBlockHash(blockIndex, &pbDiagData[kDiagLocFmtRoutineStatus]) != kFblOk)
         {
            DiagNRCConditionsNotCorrect();
            result = kFblFailed;
         }
      }
      else
      {
         /* Logical block type is not correct for this block number */
         DiagNRCRequestOutOfRange();
         result = kFblFailed;
      }
   }

   if (result == kFblOk)
   {
      /* Logical block hash successfully requested - set flag to permit next step */
      FblDiagSetLogBlockHashRequested();

      /* Send positive response */
      DiagProcessingDone(kDiagRslRoutineControlCalcBlockHash);
   }
   return result;
}

/***********************************************************************************************************************
 *  FblDiagClearDiagnosticInformation
 **********************************************************************************************************************/
/*! \brief         FblDiagClearDiagnosticInformation service function
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 *********************************************************************************************************************/
static tFblResult FblDiagClearDiagnosticInformation(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   tFblResult result;

   /* Accept this request to avoid a negative response when the application is not valid after download */
   if (  (pbDiagData[kDiagLocFmtSubparam] == 0xFFu)
      && (pbDiagData[kDiagLocFmtSubparam + 1u] == 0xFFu)
      && (pbDiagData[kDiagLocFmtSubparam + 2u] == 0xFFu))
   {
      DiagProcessingDone(kDiagRslClearDiagInfo);
      result = kFblOk;
   }
   else
   {
      DiagNRCRequestOutOfRange();
      result = kFblFailed;
   }

   return result;
}

/***********************************************************************************************************************
 *  FblDiagReadDtcByStatusMask
 **********************************************************************************************************************/
/*! \brief         Read DTC by status mask service function.
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 **********************************************************************************************************************/
static tFblResult FblDiagReadDtcByStatusMask(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   /* Call user function to read DTCs from memory */
   return ApplFblReportDTCByStatusMask(pbDiagData, diagReqDataLen);
}

/***********************************************************************************************************************
 * Diagnostic pre handler service functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  FblDiagDefaultPreHandler
 **********************************************************************************************************************/
/*! \brief         Pre-handler function to call ApplFblCheckConditions()
 *  \param[in,out] pbDiagData Pointer to the data in the diagBuffer (without SID)
 *  \param[in]     diagReqDataLen Length of data (without SID)
 *  \return        kFblOk: service processed successfully (goto next state), kFblFailed: Service processing failed.
 *********************************************************************************************************************/
static tFblResult FblDiagDefaultPreHandler(vuint8 *pbDiagData, tCwDataLengthType diagReqDataLen)
{
   return ApplFblCheckConditions(pbDiagData, diagReqDataLen);
}

/***********************************************************************************************************************
 * Diagnostic post handler service functions
 **********************************************************************************************************************/

/* Start section to execute code from RAM */
#define FBLDIAG_RAMCODE_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/***********************************************************************************************************************
 *  FblDiagDefaultPostHandler
 **********************************************************************************************************************/
/*! \brief       Can be used to switch to next state AFTER successful transmission of the service, e.g. EcuReset.
 *  \param[in]   postParam Parameter indicating service response.
 **********************************************************************************************************************/
void FblDiagDefaultPostHandler( vuint8 postParam )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)postParam;  /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif
   if(FblDiagGetDefaultSession())
   {
      FblCwResetResponseAddress();
   }

   /* Valid UDS request processed. Stop application boot timeout counter */
   if ((postParam == kDiagPostPosResponse) || (postParam == kDiagPostNoResponse))
   {
      /* Check if this post handler is called because of response after reset */
      if (GetFblMainState( kFblMainStateStartFromReset ))
      {
         ClrFblMainState( kFblMainStateStartFromReset );
      }
      else
      {
         /* Real message received */
         FblDiagClrBootTimeoutActive();
      }
   }
   /* Activate S3 timeout in case an application software is present even in default session */
   if ((postParam != kDiagPostRcrRp) && (FblMainGetApplicationValid()))
   {
      ResetTesterTimeout();
   }

}
/* Stop section to execute code from RAM */
#define FBLDIAG_RAMCODE_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  END OF FILE: FBL_DIAG_OEM.C
 **********************************************************************************************************************/

