/* Kernbauer Version: 1.12 Konfiguration: FBL Erzeugungsgangnummer: 1 */

/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Application dependent routines
 *
 *  \note          Please note, that this file contains a collection of callback functions to be used with the
 *                 Flash Bootloader. These functions may influence the behavior of the bootloader in principle.
 *                 Therefore, great care must be taken to verify the correctness of the implementation.
 *                 The contents of the originally delivered files are only examples resp. implementation proposals.
 *                 With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                 Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                 admissible by law or statute.
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
 *  --------------------------------------------------------------------------------------------------------------------
 *  00.01.00   2018-01-11  CB      -                Initial Implementation
 *  00.95.00   2018-07-11  CB      -                Pre Release
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY (kbFbl_apAPI.c)
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  00.90.00   2003-12-10  CB                       First implementation
 *  00.91.00   2004-01-08  CB                       Decryption/decompression interface changed
 *                         CB                       Parameters for ApplFblVerifyChecksum changed
 *  01.00.00   2004-02-24  CB                       Release
 *  01.01.00   2004-03-24  Rr                       Added new functions
 *  01.02.00   2004-03-25  WM                       Minor changes and enhancements for new OEM
 *  01.03.00   2004-04-23  WM                       Added watchdog trigger functions
 *                         ACP                      Added ApplFblSecurityStatus
 *                         AMN                      Added ApplFblIsValidFlashBlock, and ApplFblReadBlock
 *  01.04.00   2004-05-07  CB                       Added ApplCanBusOff, ApplCanWakeUp
 *  01.05.00   2004-05-19  CB                       Minor changes
 *  01.06.00   2004-06-30  MHz                      No changes
 *  01.07.00   2004-07-22  CB                       Added ApplFblReadEcuIdentification,
 *                                                  ApplFblStoreTesterCode, ApplFblStoreProgrammingDate
 *  01.08.00   2004-08-06  WM                       Added ApplFblRWSecurityAccessDelayFlag
 *  01.09.00   2004-09-09  Rr                       Minor changes for ApplFblCanBusOff
 *  01.10.00   2004-09-16  WM                       Added PRE and POST section for ApplFblWDTrigger
 *  01.11.00   2004-10-25  AP      ESCAN00010007    Adaption to support Vector
 *                                                  component OSEK NM
 *  01.12.00   2004-12-23  AMN                      Changed prototype of ApplFblWriteDataById
 *                                                  Added an ifdef to ApplFblCanParamInit
 *                                                  Added function ApplFblPBLConfigSet
 *                                                  Corrected the paramters in ApplFblRWProgCounter
 *                                                  Define name changes PBL->CAN
 *                         ACP                      Version check reworked
 *                         CB                       Added fingerprint functions
 *  01.13.00   2005-01-14  CB                       Added several API functions
 *  01.14.00   2005-03-22  WM      ESCAN00011595    MISRA warnings
 *  01.15.00   2005-09-29  WM                       _PRE_ and _POST_ section for ApplFblWDTriggerEnd
 *                                                  V_VER.H consistency check added
 *  01.16.00   2005-12-08  WM      ESCAN00014594    FblApSrcApplFblTpParamInit token
 *                                                  added for TPMC
 *  01.17.00   2006-02-28  AMN                      Added ApplFblCopyToRAM and ApplFblIsValidAppInRAM
 *  01.18.00   2006-03-24  QPs                      Added ApplFblGetSubNodeRxCanId for Gateway
 *                                                  implementation
 *  01.19.00   2006-04-25  CB      ESCAN00015917    Return value added for
 *                                                  ApplFblInvalidateBlock
 *                         WM      ESCAN00015960    ApplFblVerifySegmentChecksum added
 *                         Ls                       added KBTok_FblApSrcApplFblCheckProgDependencies
 *                         QPs     ESCAN00016110    Added ApplCanBusOff for the Gateway
 *                         CB      ESCAN00016144    Return value added for
 *                                                  ApplFblInitDecryption
 *                         CB      ESCAN00016147    ApplFblStoreBootSwIdent added
 *                                 ESCAN00016171    ApplFblSetSecAccessDelayFlag,
 *                                                  ApplFblGetSecAccessDelayFlag and
 *                                                  ApplFblClrSecAccessDelayFlag added
 *  01.20.00   2006-05-18  ACP     ESCAN00016438    Added kStartupPreInit/PostInit
 *                                                  definition for new ApplFblStartup() parameter
 *  01.21.00   2006-06-29  FHE                      No changes
 *  01.22.00   2006-07-24  JHg                      Added V_CALLBACK_NEAR to watchdog trigger
 *                         CB      ESCAN00017003    Added ApplFblProgrammingStateChanged
 *                         AMN                      Added ApplFblValidateFile
 *                                                  Added a token to reference local prototypes
 *                                                  from the OEM layer
 *  01.23.00   2006-08-28  JHg                      Added token for additional watchdog functions
 *                         AMN     ESCAN00017479    Modified the API of the
 *                                                  ApplFblValidateApp for Misra compliance
 *                                                  Removed ApplFblIsValidFlashBlock because it's
 *                                                  not used anymore
 *  01.24.00   2006-12-06  FHE     ESCAN00018639    Added ApplFblCheckConditions
 *  01.25.00   2007-02-07  Hp      ESCAN00019129    Add support for CCP in the bootloader
 *                                                  Add PreHandler and presence-pattern support.
 *  01.26.00   2007-03-30  WM      ESCAN00020175    Added ApplFblCheckProgPreconditions
 *  01.27.00   2007-07-06  JHg                      Return value added to ApplFblDecryption and
 *                                                  ApplFblDeinitDecryption
 *  01.28.00   2007-07-27  Ls      ESCAN00022542    FBL_ENABLE_PRE_WDINIT_COMMENT added
 *  01.29.00   2008-03-07  Ci      ESCAN00014726    FBL_COPY_CODE_TO_RAM_ON_STARTUP
 *                                                  renamed to FBL_ENABLE_COPY..
 *                         Hp      ESCAN00014726    Support for memmap and FBL_ENABLE_COPY_CODE_TO_RAM_ON_STARTUP
 *                                                  to map ApplFblWDTrigger and ApplFblWDTriggerEnd to special location
 *                         JHg                      Update CAN driver Tx confirmation routines to RI 1.4 API
 *                         Hp      ESCAN00025029    Support Vector decompression module (optional)
 *  01.30.00   2008-03-28  JHg     ESCAN00025354    Remove COMMENT restriction from FBL_ENABLE_PRE_WDINIT
 *                                                  If enabled watchdog will be already initalized in ApplFblInit
 *                                 ESCAN00025355    FBL_ENABLE_PRE_TIMERINIT added
 *                                                  If enabled timer will be already initalized in ApplFblInit
 *  01.31.00   2008-06-13  Ci      ESCAN00025071    Extended function description of
 *                                                  ApplFblStartup() with kStartupStayInBoot
 *                                 ESCAN00027445    Added support for configurations
 *                                                  with multiple CAN channels
 *  01.32.00   2008-09-10  JHg     ESCAN00029860    Moved PRE_WDINIT and PRE_TIMERINIT to fbl_main
 *  01.33.00   2008-10-15  FHe     ESCAN00030640    Added support for VAG spec 1.2.1
 *  01.34.00   2009-03-13  JHg     ESCAN00032180    Added support for multichannel configurations
 *                                                  to ApplCanTxObjStart, ApplCanTxObjConfirmed
 *                                                  Updated description of ApplCanMsgReceived
 *                         FHe                      Restored old format of ApplFblCheckProgConditions
 *                         Ci      ESCAN00033475    Added gateway specific callback
 *                                                  functions (Gw_Route support)
 *  01.35.00   2009-03-12  QPs     ESCAN00033801    Added communication wrapper specific
 *                                                  callback functions
 *  01.36.00   2009-07-21  QPs     ESCAN00035282    Added DC SLP10 extension:
 *                                                  ApplFblControlFailSafeReaction
 *                         AWh     ESCAN00036825    Inconsistent return value type between
 *                                                  ReadDataByCommonId prototype and implementation
 *  01.37.00   2009-08-31  AWh     ESCAN00037405    No changes
 *                         QPs     ESCAN00037479    Added FrTrcv specific callback functions
 *  01.38.00   2009-09-18  Tbe     ESCAN00037856    Added Ethernet/DoIP specific
 *                                                  callback functions
 *  01.39.00   2009-12-02  Ci      ESCAN00038917    Adapted prototype of
 *                                                  ApplFblFatalError()
 *                                 ESCAN00038918    Added support for validation
 *                                                  struct handling
 *                                 ESCAN00038919    Added callback for flash erased
 *                                                  detection
 *  01.40.00   2010-02-15  Ci      ESCAN00040663    Enhanced flash erased detection
 *                                                  interface
 *                         Ci      ESCAN00040852    Replaced decryption interface by
 *                                                  data processing API
 *  01.41.00   2010-07-08  MVi     ESCAN00043736    Remove pragmas when memmap is used
 *                         Ci      ESCAN00043863    Added function ApplCanTpConfirmation
 *                         QPs     ESCAN00043896    Added support for LIN bootloader
 *  01.42.00   2010-07-23  CB      ESCAN00044299    Default implementation of decompression
 *  01.43.00   2010-09-15  Ci      ESCAN00044991    Added new Gw_Route API functions
 *  01.44.00   2010-12-10  MVi     ESCAN00047478    Enhanced flash erased detection interface
 *                                 ESCAN00047482    Added routine control succeeded interface
 *  01.45.00   2011-02-03  Ach     ESCAN00048191    Use normal fixed addressing without TPMC
 *  01.46.00   2011-07-14  Ci      ESCAN00052149    Adapted Gw_Route task interface
 *  01.47.00   2011-11-25  Hp      ESCAN00052787    Extend support for PresencePatterns
 *  01.48.00   2011-12-14  AWh     ESCAN00055586    Extend Api with ApplFblInvalidateApp function
 *  01.49.00   2012-02-14  Ach     ESCAN00056341    Added ApplFblStartApplication() function
 *  01.50.00   2012-02-22  Ach     ESCAN00052787    Extend support for PresencePatterns
 *                         MVi     ESCAN00056833    Extend support for PresencePatterns (HMC)
 *                                 ESCAN00056834    No changes
 *                         CB      ESCAN00056642    Added ApplFblCanPlatformToPhysChannel()
 *  01.51.00   2012-03-23  QPs     ESCAN00057230    Extend support for FlexRay
 *                         Ach     ESCAN00057636    Remove local memSegment variables
 *                         CB      ESCAN00057670    Added Suspend Programming API
 *  01.52.00   2012-03-30  QPs     ESCAN00058040    No changes
 *  01.53.00   2012-08-16  MVi     ESCAN00060433    Support for PresencePatterns
 *                                                  with 256 byte segment size
 *  01.54.00   2012-12-06  AWh     ESCAN00061619    Moved presence pattern macros to header
 *                         Ach     ESCAN00062912    Adapted comments to use Doxygen
 *  01.55.00   2013-01-24  Ach     ESCAN00064406    Support return value IO_E_ERASED for presence pattern
 *                         JHg     ESCAN00064421    Added callback ApplFblOnTransitionSession
 *                                 ESCAN00064437    Added callback ApplFblStateTask
 *  01.56.00   2013-02-08  ASe     ESCAN00064889    Reworked comments
 *  01.57.00   2014-01-21  ASe     ESCAN00072931    Fixed compiler warning (HMC)
 *  01.58.00   2014-02-24  MVi     ESCAN00073549    Removed HMC exceptions to support new mtab header
 *  01.58.01   2014-04-03  ASe     ESCAN00074701    Fixed comments
 *  01.59.00   2014-07-16  QPs     ESCAN00077127    Extend support for LIN
 *  01.60.00   2014-08-25  Dod     ESCAN00078033    Add callbacks ApplFblMemPreWrite/Erase and ApplFblGetLogBlkHash
 *  01.61.00   2015-01-13  Ach     ESCAN00080481    Change visibility of ApplFblChkModulePresence()
 *  01.62.00   2015-05-12  CB      ESCAN00082959    Added functions to read and store the TP target address
 *  01.63.00   2015-05-27  CB      ESCAN00083167    Additional callback functions for status backup
 *  01.64.00   2015-09-14  Ci      ESCAN00084704    Removed data processing default implementation
 *                         QPs     ESCAN00085203    Added callback ApplFblCheckTesterSourceAddr
 *  01.64.01   2015-12-15  TnS     ESCAN00087100    Moved initialization for Timer Interrupt use case to FblWd
 *  01.65.00   2016-01-11  ASe     ESCAN00087324    Presence pattern handling fails on word-addressed platforms
 *                         Rr      ESCAN00087414    Extend Renault SLP3 specific API for reading light LogZone
 *  01.66.00   2016-02-25  TnS     ESCAN00088471    MISRA related code changes
 *  01.67.00   2016-03-07  MVi     ESCAN00088759    Added ApplFblIsValidBlock
 *  01.68.00   2016-03-17  Shs     ESCAN00088957    No changes
 *  01.69.00   2016-05-09  HRf     ESCAN00089907    Encapsulate FlexRay specific code in ApplFblCwWakeUp()
 *  01.70.00   2016-05-17  Rie     ESCAN00090027    Performed MISRA analysis
 *  01.71.00   2016-06-27  Ach     ESCAN00090683    Support configuration switch FBL_CW_ENABLE_MULTIPLE_NODES
 *  01.72.00   2016-07-15  DlM     ESCAN00090996    Added function for programming voltage check
 *  01.73.00   2016-08-02  Ach     ESCAN00091282    Added ApplFblGetVerificationData()
 *  01.74.00   2016-08-24  Rie     ESCAN00091646    Added ApplFblCheckFuncTargetAddr()
 *  01.75.00   2016-10-04  CEl     ESCAN00092168    Added ApplFblSetLogBlkHash()
 *  01.76.00   2016-12-01  Ach     ESCAN00093116    Added length parameter to ApplFblGetVerificationData()
 *  01.77.00   2017-02-07  Ach     ESCAN00093891    Added constant definition for common data structure
 *  01.77.01   2017-06-22  Rie     ESCAN00095595    Fixed evaluation of the presence pattern
 *  01.78.00   2017-07-04  CB      ESCAN00095725    Added functions to read and write the segment list in NV-memory
 *                         CEl     ESCAN00095744    Added ApplFblStartSeperationTime()
 *  01.79.00   2017-07-31  Ach     ESCAN00096124    Add interface to handle DET callouts
 *  01.80.00   2017-08-08  Rie     ESCAN00096215    Added support for latest TpLin
 *  01.81.00   2017-09-13  Ach     ESCAN00096636    Add interface definition for ApplDiagUserRoutine
 *  01.82.00   2017-10-09  Ach     ESCAN00096961    ApplFbl_DetEntryHandler() uses wrong interface definition
 *  01.83.00   2017-12-20  Ach     ESCAN00097821    Added interface to handle DcmDslRxTesterSourceAddress
 *  01.84.00   2018-03-14  DKl     ESCAN00098320    Added StreamOutput callbacks
 *                                 ESCAN00098695    Add interface to handle ComM status changes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  REVISION HISTORY (KbFbl_apOem.c)
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  00.01.00   2018-01-11  CB      -                Initial Implementation
 *  00.95.00   2018-07-11  CB      -                Pre Release
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"
#include "applfbl.h"

# include "Det.h"
# if (DET_ENABLED == STD_ON)
#   include "Can.h"
#   include "CanTp.h"
# endif

#if ( FBLKBAPI_FCA_VERSION != 0x0095u ) || \
    ( FBLKBAPI_FCA_RELEASE_VERSION != 0x00u )
# error "Error in fbl_apXX.c: Source and Header file are inconsistent!"
#endif

#if ( FBLKBAPI_FCA_VERSION != _FBLKBAPI_OEM_VERSION ) || \
    ( FBLKBAPI_FCA_RELEASE_VERSION != _FBLKBAPI_OEM_RELEASE_VERSION )
# error "Error in fbl_apXX.c: Source and v_ver.h are inconsistent!"
#endif

#if ( FBLKBAPI_VERSION != 0x0184u ) || \
    ( FBLKBAPI_RELEASE_VERSION != 0x00u )
# error "Error in FBL_APxx.C: Source and header file are inconsistent!"
#endif
#if ( FBLKBAPI_VERSION != _FBLKBAPI_VERSION ) || \
    ( FBLKBAPI_RELEASE_VERSION != _FBLKBAPI_RELEASE_VERSION )
# error "Error in FBL_APxx.C: Source and V_VER.H are inconsistent!"
#endif

#if ( FBLKBAPI_FRAME_FCA_VERSION != 0x0095u ) || \
    ( FBLKBAPI_FRAME_FCA_RELEASE_VERSION != 0x00u )
# error "Error in fbl_ap.c: Source and header file are inconsistent!"
#endif

#if ( FBLKBAPI_FRAME_FCA_VERSION != _FBLKBAPI_FRAME_OEM_VERSION )
# error "Error in fbl_apxx.c: Source and v_ver.h are inconsistent!"
#endif
#if ( FBLKBAPI_FRAME_FCA_RELEASE_VERSION != _FBLKBAPI_FRAME_OEM_RELEASE_VERSION )
# error "Error in fbl_apxx.c: Source and v_ver.h are inconsistent!"
#endif

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

 /* Logical block table dependency and validity check configuration */
/* PRQA S 3453 TAG_FblApNv_3453_2 */ /* MD_CBD_19.7 */
/** System must consist of at least two logical blocks to activate dependency check */
# define FBL_MIN_BLOCKS_FOR_DEPENDENCY    2u
/** First logical block number of the application */
# define FBL_START_LBT_APP                0u
/* PRQA L:TAG_FblAp_3453_2 */

/* Security seed response status defines */
#define kSeedAlreadyRequested             0x00u    /**< Seed sent out, but no key received */
#define kNewSeedRequest                   0x01u    /**< No seed sent out, new seed should be sent */

/* Configure Seed/Key implementation in callback file */

#if defined( FBL_ENABLE_DATA_PROCESSING )
# if !defined( GetOemProcessingModeSupported )
/* Accept compression and encryption */
#  define GetOemProcessingModeSupported(m) (GetOemCompressionMode((m)) || GetOemEncryptionMode((m)))
# endif /* GetOemProcessingModeSupported */

# if !defined( GetOemCompressionMode )
#  if defined( FBL_ENABLE_COMPRESSION_MODE )
/* Accept compression routine "1" */
#   define GetOemCompressionMode(m) (((m) & kDiagFmtCompressionMask) == 0x10)
#  else
/* No compression routine supported */
#   define GetOemCompressionMode(m) (0 != 0)
#  endif /* FBL_ENABLE_COMPRESSION_MODE */
# endif /* GetOemCompressionMode */

# if !defined( GetOemEncryptionMode )
#  if defined( FBL_ENABLE_ENCRYPTION_MODE )
/* Accept encryption routine "1" */
#    define GetOemEncryptionMode(m) (((m) & kDiagFmtEncryptionMask) == 0x01)
#  else
/* No encryption routine supported */
#   define GetOemEncryptionMode(m) (0 != 0)
#  endif /* FBL_ENABLE_ENCRYPTION_MODE */
# endif /* GetOemEncryptionMode */
#endif /* FBL_ENABLE_DATA_PROCESSING */

/* Static_seed indicates if a previously generated and stored seed shall be reused upon a repeated request  *
 * Static_seed == false is currently not implemented                                                        */
#define Static_seed                       0x01u

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

 /* The following constant is used by the HW/SW compatibility check. *
 * This value has to be replaced by the ECU-specific data.         */
V_MEMROM0 static V_MEMROM1 vuint8 V_MEMROM2 HardwareCompatibilityVersion[2] = {0x00u,0x12u};

#if defined( FBL_ENABLE_COMMON_DATA )
# define FBLCOMMONDATA_START_SEC_CONST
# include "memmap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
/* Common data structure definition                                        *
 * This information is shared with the application and has to be adapted   *
 * to ECU specific values. The data is also used in DIDs supported by the  *
 * Bootloader. */
V_MEMROM0 V_MEMROM1_FAR tFblCommonData V_MEMROM2_FAR fblCommonData =
{
   /* F10D - Diagnostic Specification Information */
   /* CS.00100 Version     CS00101 Version   CS.00102 Version  CS-00099 Version  */     
   {  0x91u,               0x32,             0x42,             0x51  },
   
   /* F110 data - Diagnostic Veriant*/
   { 0x00u, 0x01u},

   /* F110 data - Software Defintion Number */
   { 0x00u, 0x01u},

   /* F110 data - Supplier ID */
   { 0x00u, 0x0D},

   /* F190 VIN Original */
   {'V', 'I', 'N', '_', 'O', 'R', 'I', 'G', 'I', 'N', 'A', 'L', '1', '2', '3', '4' },
   
   /* F191  Vehicle Manufacturer ECUHardware Number */
   {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},

   /* F192 Supplier Manufacturer ECU Hardware Part Number */
   {0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20},

   /* F193 Supplier Manufacturer ECU Hardware Version Number */
   { 0x01 },
   
   /* F180  Boot Software Version information */
   { 0x18, 0x27, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20 },

   /* F154 Hardware Supplier Identification */
   { 0x01, 0x02 },

   /* F155 Software Supplier Identification */
   { 0x00, 0x01 },

   /* F1A4 */
   { 0x00u, 0x01 },

   /* Standard Bootloader software information (BCD encoded)               *
    * Information is provided with the bootloader delivery.                */
   { 
     (vuint8)(FBL_VERSION>>8), (vuint8)FBL_VERSION, (vuint8)FBL_RELEASE_VERSION,
     0u, 0u,
     0u, 0u,
     0u
   },
};
# define FBLCOMMONDATA_STOP_SEC_CONST
# include "memmap.h"
#endif /* FBL_ENABLE_COMMON_DATA */

#if defined( FBL_ENABLE_MULTIPLE_NODES ) || \
    defined( FBL_CW_ENABLE_MULTIPLE_NODES )
V_MEMRAM0 V_MEMRAM1 vuint8 V_MEMRAM2 fblEcuHandle;
#endif

#define FBL_SHUTDOWNSTATUS_START_SEC_VAR
#include "memmap.h"
V_MEMRAM0 V_MEMRAM1 tFblShutdownStatus V_MEMRAM2 fblShutdownStatus;
#define FBL_SHUTDOWNSTATUS_STOP_SEC_VAR
#include "memmap.h"

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

V_MEMRAM0 static V_MEMRAM1 SecM_SeedType V_MEMRAM2 secSeedInput;     /**< Initial seed value */
V_MEMRAM0 static V_MEMRAM1 SecM_SeedType V_MEMRAM2 seed;             /**< Current seed value */
V_MEMRAM0 static V_MEMRAM1 vuint8 V_MEMRAM2 securitySeedResponse;    /**< Seed response status */

#if defined( FBL_ENABLE_VECTOR_HW )
vuint16 flashlight;
#endif

/***********************************************************************************************************************
 *  EXTERNAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *   GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  ApplFblInit
 **********************************************************************************************************************/
/*! \brief       Function is called before any other FBL initialization
 **********************************************************************************************************************/
void ApplFblInit( void )
{
   /* Initialize EEPROM-Driver */
   (void)EepromDriver_InitSync(V_NULL);

   /* Init Seed response status */
   securitySeedResponse = kNewSeedRequest;

}

/***********************************************************************************************************************
 *  ApplFblStartup
 **********************************************************************************************************************/
/*! \brief       Bootloader initialization callback
 *  \details     This function is called during the Bootloader initialization if the application software is
 *               not started. It can be used to perform initializations which are not needed if the application
 *               software is started. Please note that the function is called several times with different
 *               initposition values. Timer and hardware can be accessed in post-init phase only.
 *  \param[in]   initposition Initialization state of Bootloader.
 **********************************************************************************************************************/
void ApplFblStartup( vuint8 initposition )
{
   switch (initposition)
   {
      case (kFblInitPreCallback | kFblInitBaseInitialization):
      {
         break;
      }
      case (kFblInitPreCallback | kFblInitFblCommunication):
      {
         break;
      }
      case (kFblInitPreCallback | kFblInitFblFinalize):
      {
         break;
      }
      case (kFblInitPostCallback | kFblInitBaseInitialization):
      {
         /* Basic hardware initialization */
         ApplFblInit();
         break;
      }
      case (kFblInitPostCallback | kFblInitFblCommunication):
      {
         break;
      }
      case (kFblInitPostCallback | kFblInitFblFinalize):
      {
         break;
      }
      default:
      {
         assertFblInternal(0u, kFblSysAssertParameterOutOfRange);
         break;
      }
   }
}

/***********************************************************************************************************************
 *  ApplFblCheckProgConditions
 **********************************************************************************************************************/
/*! \brief       This function is called after receiving the service request sessionControl ProgrammingSession to check
 *               the programming conditions like reprogramming counter, ambient temperature, programming voltage, etc.
 *  \return      If all conditions are correct, the function returns kFblOk, otherwise kFblFailed.
 **********************************************************************************************************************/
tFblResult ApplFblCheckProgConditions( void )
{
#if defined( FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS )
   vuint16 diagRespDataLen;
#endif /* FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS */
   tFblResult result;

   result = kFblOk;

#if defined( FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS )
   diagRespDataLen = 3;
#endif /* FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS */

#if defined( FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS )
   /* Transmit response message:*/
   DiagProcessingDone(diagRespDataLen);
#endif /* FBL_DIAG_ENABLE_CHECK_PROGRAMMING_PRECONDITIONS */

  return result;
}

/***********************************************************************************************************************
 *  ApplFblCheckConditions
 **********************************************************************************************************************/
/*! \brief         Check conditions for diagnostic services
 *  \details       This function is called for each diagnostic service.
 *  \param[in,out] pbDiagData Pointer to diagnostic data buffer
 *  \param[in]     diagReqDataLen The request data length
 *  \return        kFblOk or kFblFailed
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
tFblResult ApplFblCheckConditions( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)pbDiagData;
   (void)diagReqDataLen;
#endif

   /* Parse Service IDs */

   /*
   switch (diagServiceCurrent)
   {
      case kDiagSidDiagnosticSessionControl:
      {
         if (...)
         {
            DiagNRCConditionsNotCorrect();
            return kFblFailed;
         }

         break;
      }
      case kDiagSidEcuReset:
      {
         break;
      }
      case kDiagSidReadDataByIdentifier:
      {
         break;
      }
      case kDiagSidSecurityAccess:
      {
         break;
      }
      case kDiagSidCommunicationControl:
      {
         break;
      }
      case kDiagSidWriteDataByIdentifier:
      {
         break;
      }
      case kDiagSidRoutineControl:
      {
         break;
      }
      case kDiagSidRequestDownload:
      {
         break;
      }
      case kDiagSidTransferData:
      {
         break;
      }
      case kDiagSidRequestTransferExit:
      {
         break;
      }
      case kDiagSidTesterPresent:
      {
         break;
      }
      case kDiagSidControlDTCSetting:
      {
         break;
      }
      default:
      {
         break;
      }
   }
   */

   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblCheckHwSwCompatibility
 **********************************************************************************************************************/
/*! \brief       Check if current logical block is compatible with hardware
 *  \pre         Logical block has to be valid
 *  \param[in]   blockIdx Index of logical block
 *  \return      Status of hardware-software compatibility check
 **********************************************************************************************************************/
vuint8 ApplFblCheckHwSwCompatibility( vuint8 blockIdx )
{
   vuint8 compatibilityListLength;
   FBL_ADDR_TYPE pCompatibilityField;
   vuint8 versionBuffer[2];
   vuint8 listIndex;
   vuint8 returnValue;

   /* Preset values */
   listIndex = 0u;
   returnValue = kDiagCheckCompatibilitySwHw;

   /* Get address of compatibility list */
   pCompatibilityField = (ApplFblGetModuleHeaderAddress(blockIdx) + kApplInfoOffsetHwCompatibilityCounter );

   /* Read length of compatibility list */
   (void)FblReadProm(pCompatibilityField, &compatibilityListLength, 1);
   pCompatibilityField += kApplInfoSizeHwCompatibilityCount;

   /* Compare compatibility list to hardware compatibility version */
   while ((listIndex < compatibilityListLength) && (returnValue == kDiagCheckCompatibilitySwHw))
   {
      (void)FblReadProm(pCompatibilityField, versionBuffer, 2);
      if ((versionBuffer[0] == HardwareCompatibilityVersion[0]) &&
          (versionBuffer[1] == HardwareCompatibilityVersion[1]))
      {
         returnValue = kDiagCheckCompatibilityOk;
      }
      pCompatibilityField += 2;
      listIndex++;
   }

   return returnValue;
}

/***********************************************************************************************************************
 *  ApplFblCheckSwSwCompatibility
 **********************************************************************************************************************/
/*! \brief       Check if logical blocks are compatible
 *  \return      Status of software-software compatibility check
 **********************************************************************************************************************/
vuint8 ApplFblCheckSwSwCompatibility( void )
{
#if ( FBL_MTAB_NO_OF_BLOCKS < FBL_MIN_BLOCKS_FOR_DEPENDENCY )
   /* Only one block, no inconsistency possible */
   return kDiagCheckCompatibilityOk;
#else
   vuint8 idx;
   vuint8 actualVersion[2];
   vuint8 referenceVersion[2];
   vuint8 validityFlags[kEepSizeValidityFlags];
   vuint8 result;

   result = kDiagCheckCompatibilityOk;

   /* Read validity flags */
   if (ApplFblNvReadValidityFlags(validityFlags) != kFblOk)
   {
      /* Report internal error */
      result = kDiagCheckCompatibilityFailed;
   }

   if (result == kDiagCheckCompatibilityOk)
   {
      /* Read first application version from application */
      (void)FblReadProm(ApplFblGetModuleHeaderAddress(FBL_START_LBT_APP) + kApplInfoOffsetSwCompatibility,
                        (vuint8 *)&referenceVersion, kApplInfoSizeSwCompatibility);
   
      idx = FBL_START_LBT_APP + 1u;
      while ((idx < FblLogicalBlockTable.noOfBlocks) && (result == kDiagCheckCompatibilityOk))
      {
         /* Check is performed for valid logical blocks only. If an optional block  *
          * is not valid, the compatibility status will be ignored.                 */
         if ((validityFlags[idx >> 3u] & (vuint8)(1u << (idx & 7u))) == 0u)
         {
            /* Check if module version matches */
            (void)FblReadProm(ApplFblGetModuleHeaderAddress(idx) + kApplInfoOffsetSwCompatibility,
                              (vuint8 *)&actualVersion, kApplInfoSizeSwCompatibility);
            if ((referenceVersion[0] != actualVersion[0]) ||
                (referenceVersion[1] != actualVersion[1]))
            {
               /* Inconsistency found */
               result = kDiagCheckCompatibilitySwSw;
            }
         }
         idx++;
      }
   }

   /* All blocks successfully checked */
   return result;
#endif /* FBL_MTAB_NO_OF_BLOCKS < FBL_MIN_BLOCKS_FOR_DEPENDENCY */
}  /* PRQA S 2006 */ /* MD_CBD_14.7 */

/***********************************************************************************************************************
 *  ApplFblCheckProgDependencies
 **********************************************************************************************************************/
/*! \brief       Check if programming dependencies are given
 *  \return      Status of programming dependencies (OEM specific)
 **********************************************************************************************************************/
vuint8 ApplFblCheckProgDependencies( void )
{
   vuint8 result;
   vuintx idx;

   vuint8 validityFlags[kEepSizeValidityFlags];

   /* Initialize variables */
   result = kDiagCheckCompatibilityOk;

   /* Mandatory logical blocks must be valid. Otherwise, they cannot be consistent. */
   /* Read validity flags */
   if (ApplFblNvReadValidityFlags(validityFlags) != kFblOk)
   {
      result = kDiagCheckCompatibilityFailed;   /* General failure - validity flags couldn't be read */
   }

   if (result == kDiagCheckCompatibilityOk)
   {
      /* Check if all (mandatory) logical blocks are valid */
      for (idx = 0u; idx < kEepSizeValidityFlags; idx++)
      {
         if ((validityFlags[idx] & FblLogicalBlockTable.assignFlags[idx]) != 0u)
         {
            result = kDiagCheckCompatibilityBlockMissing;   /* Failure - at least one logical block is missing */
            break;
         }
      }
   }

   /* Check compatibility between valid logical blocks and bootloader */
   if (result == kDiagCheckCompatibilityOk)
   {
      /* Check Sw/Sw compatibility */
      result = ApplFblCheckSwSwCompatibility();
   }

   if (result == kDiagCheckCompatibilityOk)
   {
      /* Check Hw/Sw-compatibility of all programmed logical blocks */

      idx = FBL_START_LBT_APP;
      while( (idx < FblLogicalBlockTable.noOfBlocks && (result == kDiagCheckCompatibilityOk)) )
      {
         /* Check if block is programmed */
         if ((validityFlags[idx >> 3u] & (vuint8)(1 << (idx & 7u))) == 0u)
         {
            result = ApplFblCheckHwSwCompatibility((vuint8)idx);
         }
         idx++;
      }
   }

   /* If required, additional checks can be added here */

   return result;
}

/***********************************************************************************************************************
 *  ApplTrcvrNormalMode
 **********************************************************************************************************************/
/*! \brief       Activate transceiver if necessary (e.g. pin configuration ENABLE = 1, _STDBY = 1)
 **********************************************************************************************************************/
void ApplTrcvrNormalMode( void )
{
}

/***********************************************************************************************************************
 *  ApplTrcvrSleepMode
 **********************************************************************************************************************/
/*! \brief       Turn off the transceiver to enter sleep mode (e.g. pin configuration ENABLE = 1, _STDBY = 0)
 **********************************************************************************************************************/
void ApplTrcvrSleepMode( void )
{
}

/***********************************************************************************************************************
 *  ApplFblSetVfp
 **********************************************************************************************************************/
/*! \brief       Function is called when the FBL enters programming mode.
 *  \details     Port bits have to be set so that the required programming voltage is available.
 **********************************************************************************************************************/
void ApplFblSetVfp( void )
{
}

/***********************************************************************************************************************
 *  ApplFblResetVfp
 **********************************************************************************************************************/
/*! \brief       This function is called when the programming is done.
 **********************************************************************************************************************/
void ApplFblResetVfp( void )
{
}

/***********************************************************************************************************************
 *  ApplFblReset
 **********************************************************************************************************************/
/*! \brief       This function performs a reset.
 *  \details     The function will wait until the reset is performed. Please note: This function will
 *               never return to the calling code.
 **********************************************************************************************************************/
void ApplFblReset( void )
{
   /* Set flag for regular shutdown */
   ApplFblSetShutdownStatus(kFblShutdownStatusNormal);

}

# define FBLAP_RAMCODE_START_SEC_CODE
# include "MemMap.h"   /* PRQA S 5087 *//* MD_MSR_19.1 */
/***********************************************************************************************************************
 *  ApplFblSecuritySeedInit
 **********************************************************************************************************************/
/*! \brief       Initialize seed values.
 *  \return      Status of seed initialization
 **********************************************************************************************************************/
vuint8 ApplFblSecuritySeedInit( void )
{
   /* Initialize seed values */
   secSeedInput.seedY += secSeedInput.seedX;
   secSeedInput.seedX = FblGetTimerValue();

   return kFblOk;
}
# define FBLAP_RAMCODE_STOP_SEC_CODE
# include "MemMap.h"   /* PRQA S 5087 *//* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  ApplFblSecuritySeed
 **********************************************************************************************************************/
/*! \brief       This function is called when the tester requests the security seed.
 *  \return      Status of seed generation
 **********************************************************************************************************************/
vuint8 ApplFblSecuritySeed( void )
{
   vuint8 result;

   result = kFblOk;

   /* Last seed is repeated if it was already sent to tester */

   if (securitySeedResponse != kSeedAlreadyRequested)
   {
      /* Ensure that seed has been initialized */
      while ((0u == secSeedInput.seedX) || (0u == secSeedInput.seedY))
      {
         (void)ApplFblSecuritySeedInit();
      }

      /* Generate seed */
      if (SECM_OK == SecM_GenerateSeed(&secSeedInput))
      {
         /* Save last seed */
         seed = secSeedInput;
      }
      else
      {
         result = kFblFailed;
      }
   }

   /* Write seed value into DiagBuffer */
   if (kFblOk == result)
   {
      FblMemSetInteger(SEC_SEED_LENGTH, seed.seedX, &DiagBuffer[kDiagFmtSeedKeyStart]);

      /* Set seed status to seed requested */
      securitySeedResponse = kSeedAlreadyRequested;
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblSecurityKey
 **********************************************************************************************************************/
/*! \brief       This function is called when the security key has been received from tester
 *  \return      Status of key verification
 **********************************************************************************************************************/
vuint8 ApplFblSecurityKey( void )
{
   vuint8 result;

   SecM_KeyType key;

   /* Initialize variables */
   result = kFblFailed;

   /* Key received => New seed can be requested */
   securitySeedResponse = kNewSeedRequest;

   /* Check key from tester */
   key = FblMemGetInteger(SEC_KEY_LENGTH, &DiagBuffer[kDiagFmtSeedKeyStart]);
   if (SECM_OK == SecM_CompareKey(key, seed))
   {
      /* Key bytes are accepted */
      result = kFblOk;
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblSecurityInit
 **********************************************************************************************************************/
/*! \brief       Initialize security module.
 *  \return      Status of security module initialization
 **********************************************************************************************************************/
vuint8 ApplFblSecurityInit( void )
{
   secSeedInput.seedX = 0u;
   secSeedInput.seedY = 0u;

   return kFblOk;
}

#if defined( FBL_ENABLE_DATA_PROCESSING )
/***********************************************************************************************************************
 *  ApplFblInitDataProcessing
 **********************************************************************************************************************/
/*! \brief         This function is called to initialize the application specific data processing function.
 *  \param[in,out] procParam Processing parameter data structure
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblInitDataProcessing( tProcParam * procParam )
{
   /* Example implementation. Data not processed at all. */
   tFblResult result;

   result = kFblOk;

   return result;
}

/***********************************************************************************************************************
 *  ApplFblDataProcessing
 **********************************************************************************************************************/
/*! \brief         Data processing function.
 *  \pre           Data processing has to be initialized by call of ApplFblInitDataProcessing
 *  \param[in,out] procParam Processing parameter data structure
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblDataProcessing( tProcParam * procParam )
{
   /* Example implementation. Data not processed at all. */
   tFblResult result;

   result = kFblOk;

   /* Calculate output length. Length will not change */
   if (procParam->dataLength > procParam->dataOutMaxLength)
   {
      procParam->dataOutLength = procParam->dataOutMaxLength;
   }
   else
   {
      procParam->dataOutLength = procParam->dataLength;
   }

   /* Update actually consumed length */
   procParam->dataLength = procParam->dataOutLength;

   /* Copy data from input to output buffer. */
   FblLookForWatchdogVoid();
   (void)MEMCPY(procParam->dataOutBuffer, procParam->dataBuffer, procParam->dataOutLength);

   return result;
}

/***********************************************************************************************************************
 *  ApplFblDeinitDataProcessing
 **********************************************************************************************************************/
/*! \brief         Deinitialize data processing function.
 *  \pre           Data processing has to be initialized by call of ApplFblInitDataProcessing
 *  \param[in,out] procParam Processing parameter data structure
 *  \return        kFblOk/kFblFailed
 **********************************************************************************************************************/
tFblResult ApplFblDeinitDataProcessing( tProcParam * procParam )
{
   /* Example implementation. Data not processed at all. */
   tFblResult result;

   /* Conclude data processing in last round */
   result = ApplFblDataProcessing(procParam);

   return result;
}
#endif /* FBL_ENABLE_DATA_PROCESSING */

#if defined( FBL_ENABLE_APPL_TASK ) || \
    defined( FBL_ENABLE_APPL_TIMER_TASK )
/***********************************************************************************************************************
 *  ApplFblTask
 **********************************************************************************************************************/
/*! \brief       1ms user task.
 *  \details     This function is called every millisecond if the Bootloader is in idle state. It is not called during
 *               flash operations.
 **********************************************************************************************************************/
void ApplFblTask( void )
{

}
#endif /* FBL_ENABLE_APPL_TASK || FBL_ENABLE_APPL_TIMER_TASK */

#if defined( FBL_ENABLE_APPL_TASK ) ||\
    defined( FBL_ENABLE_APPL_STATE_TASK )
/***********************************************************************************************************************
 *  ApplFblStateTask
 **********************************************************************************************************************/
/*! \brief       Background user task.
 *  \details     This function is polled if the Bootloader is in idle state. It is not called during flash operations.
 **********************************************************************************************************************/
void ApplFblStateTask( void )
{
}
#endif /* FBL_ENABLE_APPL_TASK || FBL_ENABLE_APPL_STATE_TASK */

#if defined( FBL_ENABLE_MULTIPLE_NODES ) || \
    defined( FBL_ENABLE_CAN_CONFIGURATION) || \
    defined( FBL_CW_ENABLE_MULTIPLE_NODES )
/***********************************************************************************************************************
 *  ApplFblCanParamInit
 **********************************************************************************************************************/
/*! \brief       Overwrite default CAN parameters
 *  \details     This function is called before CAN controller initialization so that default initialization values
 *               can be overridden according to the boot mode.
 *               If this function is empty, the default/reset settings are used to initialize the CAN controller.
 *  \pre         fblCanIdTable has to be initialized with default/reset
 **********************************************************************************************************************/
void ApplFblCanParamInit( void )
{
   vuint8 currentEcu = 1;

   /* This is only an example:      */
   /* currentEcu = GetCurrentEcu(); */

   if (FblMainGetStartFromAppl())
   {
      /* At this position, it is possible to read CAN init parameters from
       * EEPROM, which have been programmed by the ECU application before
       * the FBL was started. */
   }
   switch (currentEcu)
   {
      case 0:
      {
         fblEcuHandle = FBL_ECU_HDLE_Demo;
         break;
      }
      case 1:
      {
         fblEcuHandle = FBL_ECU_HDLE_DemoExtIDs;
         break;
      }
   }
}
#endif

/***********************************************************************************************************************
 *  ApplFblCanBusOff
 **********************************************************************************************************************/
/*! \brief       This call-back function is called if the CAN controller enters bus-off state.
 **********************************************************************************************************************/
void ApplFblCanBusOff( void )
{
   /* Bus off detected, issue ECU reset */
   ApplFblReset();
}

#if defined( FBL_ENABLE_SLEEPMODE )
/***********************************************************************************************************************
 *  ApplFblBusSleep
 **********************************************************************************************************************/
/*! \brief       Indicates transition to bus silence.
 *  \details     By calling this function the FBL indicates the application
 *               that the bootloader can go to sleep (bus silence, no diagnostic requests).
 **********************************************************************************************************************/
void ApplFblBusSleep( void )
{

#if defined( FBL_WATCHDOG_ON )
   /* Wait for watchdog to be triggered */
   while (FblLookForWatchdog() != FBL_WD_TRIGGERED)
   {
      ;
   }
#endif

   /* ToDo: Shutdown of CAN and ECU */
   {
      /* Put transceiver in sleepmode, power down */
      ApplTrcvrSleepMode();

      /* ToDo: Wait for power down, check for wakeup request */
      while(1)
      {
         ;
      }
   }
   /* Wakeup request received, generate reset */
   ApplFblReset();
}
#endif /* FBL_ENABLE_SLEEPMODE */

/***********************************************************************************************************************
 *  ApplFblStartApplication
 **********************************************************************************************************************/
/*! \brief       This function is called to start the application.
 *  \details     Please note: The function will never return because control is handed over to the application.
 *  \pre         Application validity has been checked, Application is valid
 **********************************************************************************************************************/
void ApplFblStartApplication( void )
{
   /* Start application */
   JSR_APPL();

#if defined( FBL_ENABLE_SYSTEM_CHECK )
   /* Code should never be reached */
   while (1)
   {
      ;
   }
#endif /* FBL_ENABLE_SYSTEM_CHECK */
}

/***********************************************************************************************************************
 *  ApplFblSetShutdownStatus
 **********************************************************************************************************************/
/*! \brief       This callback sets the shutdown status to be able to determine on startup if a normal or abnormal 
 *               shutdown occured. 
 *  \param[in]   status New shutdown status
 **********************************************************************************************************************/
void ApplFblSetShutdownStatus(tFblShutdownStatus status)
{
   fblShutdownStatus = status;
}

/***********************************************************************************************************************
 *  ApplFblGetShutdownStatus
 **********************************************************************************************************************/
/*! \brief       This callback returns the current shutdown status 
 *  \return      Shutdown status
 **********************************************************************************************************************/
tFblShutdownStatus ApplFblGetShutdownStatus(void)
{
   return fblShutdownStatus;
}

/***********************************************************************************************************************
 *  ApplFblClrShutdownStatus
 **********************************************************************************************************************/
/*! \brief       Sets the shutdown status to abnormal (default) 
 *  \return      Shutdown status
 **********************************************************************************************************************/
void ApplFblClrShutdownStatus(void)
{
   fblShutdownStatus = kFblShutdownStatusAbnormal;
}

#if defined( FBL_ENABLE_ASSERTION )
/***********************************************************************************************************************
 *  ApplFblFatalError
 **********************************************************************************************************************/
/*! \brief       If the bootloader assertions are enabled, this function will be called in case an invalid bootloader
 *               state is encountered.
 *  \param[in]   errorCode Code number of the encountered assertion
 *  \param[in]   module Name of the affected module (Only if extended info is enabled)
 *  \param[in]   line Line number where the assertion occurred (Only if extended info is enabled)
 **********************************************************************************************************************/
void ApplFblFatalError( FBL_DECL_ASSERT_EXTENDED_INFO(vuint8 errorCode) )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)errorCode;  /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif

   /* TODO: This feature should be activated in development only. Please make sure this
            function isn't called in production code and assertions are disabled in GENy
            (set "Project State" to "Production (default)" or "Production (reduced tests)".
   */
   while (1)
   {
      ;
   }
}
#endif

#if (DET_ENABLED == STD_ON)
/***********************************************************************************************************************
 *  ApplFbl_DetEntryHandler
 **********************************************************************************************************************/
/*! \brief       Called by DET module to check if a DET error is intended bootloader behavior or not.
 *  \param[in]   ModuleId Code number of the encountered assertion
 *  \param[in]   InstanceId Name of the affected module (Only if extended info is enabled)
 *  \param[in]   ApiId Line number where the assertion occurred (Only if extended info is enabled)
 *  \param[in]   ErrorId Line number where the assertion occurred (Only if extended info is enabled)
 *  \return      Report if error should be handed over to DET or not (E_OK or FALSE depending on interface)
 **********************************************************************************************************************/
# if ((DET_AR_RELEASE_MAJOR_VERSION >= 4u) && (DET_AR_RELEASE_MINOR_VERSION >= 3u))
FUNC(Std_ReturnType, DET_CODE) ApplFbl_DetEntryHandler( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId )
# else
FUNC(boolean, DET_APPL_CODE) ApplFbl_DetEntryHandler( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId )
# endif
{
   Std_ReturnType result = E_OK;

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
               result = E_NOT_OK;
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
               result = E_NOT_OK;
               break;
            }
            default:
            {
               break;
            }
         }
         break;
      }
      default:
      {
         /* Unknown module. Keep error. */
         break;
      }
   }

   return result;
}
#endif

/* module specific MISRA deviations:

   MD_FblKbApi_3201:
      Reason: Configuration or platform specific dependent unreachable code.
      Risk: Incorrect behavior depend on settings.
      Prevention: No prevention required.

   MD_FblKbApi_3325:
      Reason: This control expression is always true or false depend on configuration aspect and used platform specific
              implementation.
      Risk: Incorrect behavior depend on settings.
      Prevention: No prevention required.

   MD_FblKbApi_3353:
      Reason: Variable is set in an other function via call-by-reference.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApi_3673:
      Reason: Function is part of the bootloader API which provides the possibility to influence the bootloader behavior
              by modifying the output parameters. The provided default implementation of the function doesn't
              necessarily make use of all available parameters.
      Risk: The parameter value might be changed unintentionally, thus causing malfunction in the calling instance.
      Prevention: Provide detailed information about the API and its usage in the user documentation.

   MD_FblKbApiOem_3199:
      Reason: Value assignment is done but assigned value is not used in all configurations.
      Risk: Adds an possibly unused assignment which could result in a compiler warning.
      Prevention: Ignore compiler warning if observed.

   MD_FblKbApiOem_3315:
      Reason: Example code shows how the function can be implemented and is therefore left empty.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiOem_3425:
      Reason: The WrapNv call uses the ternary operator to remap the return value of IO_E_OK to kFblOk. As both of
       them are defined to the value zero the remapping has no side affects.
      Risk: No identifiable risk.
      Prevention: No prevention required.

   MD_FblKbApiOem_3355_3358:
      Reason: Code is shared between different configurations. In other configurations,
              the result of the comparison/logical operation is not invariant.
      Risk: No identifiable risk.
      Prevention: No prevention required.

*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_AP.C
 **********************************************************************************************************************/
