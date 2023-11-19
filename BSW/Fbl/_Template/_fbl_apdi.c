/* Kernbauer Version: 1.12 Konfiguration: FBL Erzeugungsgangnummer: 1 */

/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief         Application dependent diagnostic routines
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

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLKBAPI_FRAMEDIAG_FCA_VERSION != 0x0095u ) || \
    ( FBLKBAPI_FRAMEDIAG_FCA_RELEASE_VERSION != 0x00u )
# error "Error in fbl_apdi.c: Source and header file are inconsistent!"
#endif

#if ( FBLKBAPI_FRAMEDIAG_FCA_VERSION != _FBLKBAPI_FRAMEDIAG_OEM_VERSION )
# error "Error in fbl_apdi.c: Source and v_ver.h are inconsistent!"
#endif
#if ( FBLKBAPI_FRAMEDIAG_FCA_RELEASE_VERSION != _FBLKBAPI_FRAMEDIAG_OEM_RELEASE_VERSION )
# error "Error in fbl_apdi.c: Source and v_ver.h are inconsistent!"
#endif

/***********************************************************************************************************************
 *  LOCAL VARIABLES
 **********************************************************************************************************************/

 /***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Compatibility define */
#if !defined( kDiagRslReadDataByIdentifier )
# define kDiagRslReadDataByIdentifier kDiagRslWriteDataByIdentifier
#endif

#define kDiagDidOffset                                    2u

/* Programming preconditions */
#define kProgPrecondEngineSpeed                          0x01u
#define kProgPrecondInputShaftRpm                        0x03u
#define kProgPrecondOutputShaftRpm                       0x04u
#define kProgPrecondVehicleSpeed                         0x05u
#define kProgPrecondControlIsActive                      0x06u
#define kProgPrecondIgnitionOnRequired                   0x07u
#define kProgPrecondIgnitionOff                          0x09u
#define kProgPrecondLowBatteryVoltage                    0x0Au
#define kProgPrecondHighTemerature                       0x0Bu
#define kProgPrecondLowTemperature                       0x0Cu
#define kProgPrecondHighBatteryVoltage                   0x0Du

/***********************************************************************************************************************
 *  LOCAL DATA
 **********************************************************************************************************************/

V_MEMROM0 static V_MEMROM1_FAR vuint8 V_MEMROM2_FAR fblSupportedPreconditions[] =
{
   kProgPrecondEngineSpeed,
   kProgPrecondInputShaftRpm,
   kProgPrecondOutputShaftRpm,
   kProgPrecondVehicleSpeed,
   kProgPrecondControlIsActive,
   kProgPrecondIgnitionOnRequired,
   kProgPrecondIgnitionOff,
   kProgPrecondLowBatteryVoltage,
   kProgPrecondHighTemerature,
   kProgPrecondLowTemperature
};

#define kFblNoOfSupportedPrecond (sizeof(fblSupportedPreconditions) / sizeof(vuint8))

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

static tFblResult ApplFblReadProgAttemptCounter(vuint8 *targetBuffer, vuint32 blockType);
static tFblResult ApplFblReadEcuDiagnosticIdentification(vuint8 *targetBuffer);
static tFblResult ApplFblReadVehicleManufEcuHwNumber(vuint8 *targetBuffer);

/***********************************************************************************************************************
 *  Local FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  ApplFblReadProgAttemptCounter
 **********************************************************************************************************************/
/*! \brief         Read programming attempt counter for each logical block
 *  \details       This function copies the current programming attempt counter (2 bytes) and the max. number of
 *                 supported programming attempts (2 bytes) of each logical block of the given type.
 *  \param[in]     targetBuffer Pointer to diag reponse buffer 
 *  \param[in]     blockType Boot/code/data block
 *  \return        kFblOk Data copied successfully kFblFailed if NV read access failed 
 **********************************************************************************************************************/
static tFblResult ApplFblReadProgAttemptCounter(vuint8 *targetBuffer, vuint32 blockType)
{
   vuint8 currentProgAttempts[2];
   vuint16 blockIdx;
   vuint16 targetIdx;
   tFblResult result;

   targetIdx = 0u;
   result = kFblOk;

   if (blockType == kBlockTypeBoot)
   {
      /* Programming attempt counter */
      targetBuffer[targetIdx] = 0u;
      targetBuffer[targetIdx + 1u] = 0u;

      /* Maximum number of programming attempts */
      targetBuffer[targetIdx + 2u] = 0u;
      targetBuffer[targetIdx + 3u] = 0u;     
   }
   else
   {
      for(blockIdx = 0; blockIdx < FBL_MTAB_NO_OF_BLOCKS; blockIdx++)
      {
         if (FblLogicalBlockTable.logicalBlock[blockIdx].blockType == blockType)
         {
            result |= ApplFblNvReadProgAttempts(blockIdx, currentProgAttempts);

            /* Current programming attempt counter */
            targetBuffer[targetIdx] = currentProgAttempts[0u];
            targetBuffer[targetIdx + 1u] = currentProgAttempts[1u];

            /* Maximum number of programming attempts from logical block table configuration */
            targetBuffer[targetIdx + 2u] = (vuint8)((FblLogicalBlockTable.logicalBlock[blockIdx].maxProgAttempts >> 8u) & 0xFFu);
            targetBuffer[targetIdx + 3u] = (vuint8)(FblLogicalBlockTable.logicalBlock[blockIdx].maxProgAttempts & 0xFFu);

            targetIdx += 4u;
         }
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  ApplFblReadEcuDiagnosticIdentification
 **********************************************************************************************************************/
/*! \brief         Copy the requested ECU Diagnostic Information into the targetBuffer
 *  \details       This function is called for the ReadDataByIdentifier - F110h DID. The requested data is provided
 *                 from NVM and from common data structure.
 *  \param[in]     targetBuffer Pointer to diag reponse buffer 
 *  \return        kFblOk Data copied successfully kFblFailed if NV read access failed
 **********************************************************************************************************************/
static tFblResult ApplFblReadEcuDiagnosticIdentification(vuint8 *targetBuffer)
{
   tFblResult result;
   vuint8 idx;

   idx = 0u;

   /* Read Diagnostic Variant (2 bytes) */
   targetBuffer[idx] = fblCommonData.diagnosticVariant [0];
   idx++;
   targetBuffer[idx] = fblCommonData.diagnosticVariant [1];
   idx++;

   /* Read Diagnostiv Version (4 bytes) */
   result = ApplFblNvReadDiagnosticVersion(&targetBuffer[idx]);
   idx += 4u;

   /* Read Flash Definition Number (FDN) (2 bytes) */
   targetBuffer[idx] = fblCommonData.swDefinitonNumber[0];
   idx++;
   targetBuffer[idx] = fblCommonData.swDefinitonNumber[1];
   idx++;

   /* Read Supplier ID (2 bytes) */
   targetBuffer[idx] = fblCommonData.supplierId[0];
   idx++;
   targetBuffer[idx] = fblCommonData.supplierId[1];

   return result;
}

/***********************************************************************************************************************
 *  ApplFblReadVehicleManufEcuHwNumber
 **********************************************************************************************************************/
/*! \brief         Copy the requested Vehicle Manufacturer ECU Hardware Number into the targetBuffer
 *  \details       This function is called for the ReadDataByIdentifier - F191h DID
 *  \param[in]     targetBuffer Pointer to diag reponse buffer 
 *  \return        kFblOk Data copied successfully
 **********************************************************************************************************************/
static tFblResult ApplFblReadVehicleManufEcuHwNumber(vuint8 *targetBuffer)
{
   vuint8 idx;

   for(idx = 0u; idx < kDiagRslDidVehicleManufECUHwNo; idx++)
   {                       
      targetBuffer[idx] = fblCommonData.VehicleManufEcuHwNumber[idx];
   }

   return kFblOk;
}

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  ApplDiagUserService
 **********************************************************************************************************************/
/*! \brief         Call-back function for user diagnostic services. pbDiagData points to subfunction.
 *  \details       This function is called when a diagnostic service has been received that is not managed by the FBL
 *                 itself -> can be managed by user.
 *  \param[in,out] pbDiagData Pointer to diag service data (after SID!)
 *  \param[in]     diagReqDataLen Service data length (without SID!)
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
void ApplDiagUserService( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;  /* PRQA S 3112 */ /* MD_MSR_14.2 */
   (void)diagReqDataLen;  /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif /* V_ENABLE_USE_DUMMY_STATEMENT */

   switch (diagServiceCurrent)
   {
      default:
      {
         DiagNRCServiceNotSupported();
         break;
      }
   }  /* PRQA S 3315 */ /* MD_FblKbApiOem_3315 */
}

/***********************************************************************************************************************
 *  ApplDiagUserSubFunction
 **********************************************************************************************************************/
/*! \brief         Call-back function for user diagnostic services. pbDiagData points to subfunction.
 *  \details       This function is called when the bootloader manages the diagnostic service, but the sub-parameter
 *                 is unknown -> subparameter of the service can be managed by user.
 *  \param[in,out] pbDiagData Pointer to diag service data (after SID!)
 *  \param[in]     diagReqDataLen Service data length (without SID!!)
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
void ApplDiagUserSubFunction( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)pbDiagData;  /* PRQA S 3112 */ /* MD_MSR_14.2 */
   (void)diagReqDataLen;  /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif

   /* If you want to support different sub functions, add appropriate code */
   switch (diagServiceCurrent)
   {
      default:
      {
         DiagNRCSubFunctionNotSupported();
         break;
      }
   }  /* PRQA S 3315 */ /* MD_FblKbApiOem_3315 */
}

/***********************************************************************************************************************
 *  ApplFblCheckProgPreconditions
 **********************************************************************************************************************/
/*! \brief         This function is called by the diagnostic module to check the programming preconditions.
 *  \param[in,out] pbDiagData Pointer to diagnostic data buffer
 *  \param[in]     diagReqDataLen The request data length
 *  \return        If all conditions are correct, the function returns kFblOk, otherwise kFblFailed.
 **********************************************************************************************************************/
tFblResult ApplFblCheckProgPreconditions( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
   vuint8   unfullfilledCnt;
   vuint8   idx;

   /* Counter for unfulfilled preconditions */
   unfullfilledCnt = 0u;

   /* Check all preconditions                                                 *
    * Return all preconditions that are not fulfilled according to 09010-02   */
   for (idx = 0u ; idx < kFblNoOfSupportedPrecond ; idx++)
   {
      switch (fblSupportedPreconditions[idx])
      {
         case kProgPrecondEngineSpeed:

            /* Example: Test if programming preconditions are fulfilled */
            /*
            if (preCondition != OK)
            {
               ** Copy code of unfulfilled precondition into response message **
               pbDiagData[kDiagLocFmtStartPreCond+unfullfilledCnt] = kProgPrecondEngineSpeed;
               unfullfilledCnt++;
            }
            */

            break;
         case kProgPrecondInputShaftRpm:
            break;
         case kProgPrecondOutputShaftRpm:
            break;
         case kProgPrecondVehicleSpeed:
            break;
         case kProgPrecondControlIsActive:
            break;
         case kProgPrecondIgnitionOnRequired:
            break;
         case kProgPrecondIgnitionOff:
            break;
         case kProgPrecondLowBatteryVoltage:
            break;
         case kProgPrecondHighTemerature:
            break;
         case kProgPrecondLowTemperature:
            break;
         default:

            break;
      }
   }

   /* tbd */
   /* Set Number of Programming Conditions */
   pbDiagData[kDiagLocFmtNrOfPrecond] = unfullfilledCnt;

   DiagProcessingDone(4 + unfullfilledCnt);  /* Always send positive response */
   return kFblOk;
}

/***********************************************************************************************************************
 *  ApplFblReadDataByIdentifier
 **********************************************************************************************************************/
/*! \brief         ReadDataByIdentifier service function.
 *  \param[in,out] pbDiagData Pointer to diag service data (after SID!)
 *  \param[in]     diagReqDataLen Service data length (without SID!)
 **********************************************************************************************************************/
void ApplFblReadDataByIdentifier( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
   typedef struct {
      vuint16   did;
      vuint16   maxSize;
   } tDid;

   static V_MEMROM1 tDid V_MEMROM2 didTable[] =
   {
      /* Data identifier , record length */
      { kFblDiagDidVehicleNetworkSecurityStatus , kDiagRslDidVehicleNetworkSecurityStatus },
      { kFblDiagDidOdometerHighResolution       , kDiagRslDidOdometerHighResolution       },
      { kFblDiagDidOdometer                     , kDiagRslDidOdometer                     },
      { kFblDiagDidOdometerContentLastPrg       , kDiagRslDidOdometerContentLastPrg       },
      { kFblDiagDidBootSwProgAttemptCounter     , kDiagRslDidBootSwProgAttemptCounter     },
      { kFblDiagDidProgrammingStatus            , kDiagRslDidProgrammingStatus            },
      { kFblDiagDidApplSwReprogAttemptCounter   , kBlockTypeCodeNoOfBlocks * kDiagRslDidApplSwReprogAttemptCounter      },
      { kFblDiagDidApplDataReprogAttemptCounter , kBlockTypeDataNoOfBlocks * kDiagRslDidApplDataReprogAttemptCounter    },
      { kFblDiagDidDiagnosticSpecInfo           , kDiagRslDidDiagnosticSpecInfo           },
      { kFblDiagDidEcuDiagIdentification        , kDiagRslDidEcuDiagIdentification        },
      { kFblDiagDidEcuIdentificationHwPartNo    , kDiagRslDidEcuIdentificationHwPartNo    },
      { kFblDiagDidSwEbomPartNo                 , kDiagRslDidSwEbomPartNo                 },
      { kFblDiagDidEbomEcuPartNo                , kDiagRslDidEbomEcuPartNo                },
      { kFblDiagDidHardwareSupplierId           , kDiagRslDidHardwareSupplierId           },
      { kFblDiagDidSoftwareSupplierId           , kDiagRslDidSoftwareSupplierId           },
      { kFblDiagDidVehicleIdentification        , kDiagRslDidVehicleIdentification        },
      { kFblDiagDidBootSwVersionInfo            , 1u + ( kBlockTypeBootNoOfBlocks * kDiagRslDidBootSwVersionInfo)       },
      { kFblDiagDidApplSwIdentification         , 1u + ( kBlockTypeCodeNoOfBlocks * kDiagRslDidApplSwIdentification)    },
      { kFblDiagDidApplDataIdentification       , 1u + ( kBlockTypeDataNoOfBlocks * kDiagRslDidApplDataIdentification)  },
      { kFblDiagDidActiveDiagSessDid            , kDiagRslDidActiveDiagSessDid            },
      { kFblDiagDidCodepEcuPartNo               , kDiagRslDidCodepEcuPartNo               },
      { kFblDiagDidVehicleManufEcuSwNo          , kDiagRslDidVehicleManufEcuSwNo          },
      { kFblDiagDidEcuSerialNumber              , kDiagRslDidEcuSerialNumber              },
      { kFblDiagDidVinOriginal                  , kDiagRslDidVinOriginal                  },
      { kFblDiagDidVehicleManufECUHwNo          , kDiagRslDidVehicleManufECUHwNo          }, /* F191 */ 
      { kFblDiagDidSupplierManufECUHwPartNo     , kDiagRslDidSupplierManufECUHwPartNo     }, /* F192 */ 
      { kFblDiagDidSupplierManufECUHwVersionNo  , kDiagRslDidSupplierManufECUHwVersionNo  }, /* F193 */ 
      { kFblDiagDidSupplierManufECUSwPartNo      , kDiagRslDidSupplierManufECUSwPartNo    },
      { kFblDiagDidSupplierManufECUSwVersionNo  , kDiagRslDidSupplierManufECUSwVersionNo  },
      { kFblDiagDidExRegOrTypeApprovalNo        , kDiagRslDidExRegOrTypeApprovalNo        },
      { kFblDiagDidSystemIdentificationData     , kDiagRslDidSystemIdentificationData     },
      { kFblDiagDidVectorDeliveryId             , kDiagRslDidVectorDeliveryId             },
      { kFblDiagDidAlgorithmIdNumberReprog      , kDiagRslDidAlgorithmIdNumberReprog      },
      { kFblDiagDidVinCurrent                   , kDiagRslDidVinCurrent                   },
      { kFblDiagDidBootSwFingerprintRead        , kDiagRslDidBootSwFingerprintRead        }, // ## ToDo Boot / Code / Data blocks 
      { kFblDiagDidApplSwFingerprintRead        , kDiagRslDidApplSwFingerprintRead        },
      { kFblDiagDidApplDataFingerprintRead      , kDiagRslDidApplDataFingerprintRead      }
   };

   vuint16 diagRespDataLen;

   vuint16 didIdx;
   vuint16 outIdx;
   vuint16 outIdxAdd;
   vuint16 currentDid;
   vuint16 didNo;
   vuint8  didBuffer[(FBL_MAX_DID_COUNT << 1u)];
   vuint16 i, j;
   vuint8* diagData;

   tFblResult result;
   vuint16 idx;

   /* Check diagnostic request length */
   if (   (diagReqDataLen < kDiagRqlReadDataByIdentifier)
       || ((diagReqDataLen % 2u) != 0u)
      )
   {
      DiagNRCIncorrectMessageLengthOrInvalidFormat();
      return;
   }

   /* If necessary this check could be used to
    * ensure a prior security access. It could
    * also be used for certain data identifiers. */
   /*
   if (!GetSecurityUnlock())
   {
      DiagNRCSecurityAccessDenied();
      return;
   }
   */

   didNo = (diagReqDataLen / 2u);

   if (didNo > FBL_MAX_DID_COUNT)
   {
      DiagNRCRequestOutOfRange();
      return;
   }

   for (i = 0u; i < diagReqDataLen; i++)
   {
      didBuffer[i] = pbDiagData[i];
   }

   outIdx = 0u;
   didIdx = 0u;
   i = 0u;
   result = kFblOk; 
   while((i < didNo) && (result == kFblOk))
   {
      currentDid =  ((vuint16)didBuffer[didIdx]) << 8u;
      currentDid |= (vuint16)didBuffer[didIdx + 1u];

      diagData = &pbDiagData[outIdx];

      diagData[0] = didBuffer[didIdx];
      diagData[1] = didBuffer[didIdx + 1u];

      didIdx += 2u;

      outIdxAdd = 0u;
      for (j = 0u; j < (sizeof(didTable)/sizeof(tDid)); j++)
      {
         if (didTable[j].did == currentDid)
         {
            outIdxAdd = didTable[j].maxSize + kDiagRslReadDataByIdentifier;
            break;
         }
      }

      if (outIdxAdd != 0u)
      {
         /* Check if response still fits into diag buffer */
         if ((outIdx + outIdxAdd) > (FBL_DIAG_BUFFER_LENGTH - 1u))
         {
            DiagNRCRequestOutOfRange();
            return;
         }

         switch (currentDid)
         {
            case kFblDiagDidVehicleNetworkSecurityStatus :
            {
               /* ToDo: Copy diagnostic data if required */
               break;
            }

            case kFblDiagDidOdometerHighResolution       :
            {
               /* ToDo: Copy diagnostic data if required */
               break;
            }

            case kFblDiagDidOdometer                     :
            {
               /* ToDo: Copy diagnostic data if required */
               break;
            }

            case kFblDiagDidOdometerContentLastPrg       :
            {
               /* ToDo: Copy diagnostic data if required */
               break;
            }

            /* 2003 */
            case kFblDiagDidBootSwProgAttemptCounter     :
            {
               result = ApplFblReadProgAttemptCounter(&diagData[kDiagDidOffset], kBlockTypeBoot);
               break;
            }

            /* 2010 - Programming status */
            case kFblDiagDidProgrammingStatus            :
            {
               result = ApplFblNvReadProgrammingStatus(&diagData[kDiagDidOffset]);

               /* Mask "running in boot" flag */
               diagData[kDiagDidOffset] &= FblInvert8Bit(kDiagProgStatMode);
               break;
            }

            /* 201A */
            case kFblDiagDidApplSwReprogAttemptCounter   :
            {
               result = ApplFblReadProgAttemptCounter(&diagData[kDiagDidOffset], kBlockTypeCode);
               break;
            }

            /* 201B */
            case kFblDiagDidApplDataReprogAttemptCounter :
            {
               result = ApplFblReadProgAttemptCounter(&diagData[kDiagDidOffset], kBlockTypeData);
               break;
            }

            /* F10D */
            case kFblDiagDidDiagnosticSpecInfo           :
            {
               for (idx = 0u; idx < kDiagRslDidDiagnosticSpecInfo; idx++)
               {
                  diagData[kDiagDidOffset + idx] = fblCommonData.diagSpecInfo[idx];
               }
               break;
            }

            /* F110 */
            case kFblDiagDidEcuDiagIdentification        :
            {
               result = ApplFblReadEcuDiagnosticIdentification(&diagData[kDiagDidOffset]);
               break;
            }

            /* F112 */
            case kFblDiagDidEcuIdentificationHwPartNo    :
            {
               /* ToDo: Copy diagnostic data if required */
               for (idx = 0u; idx < kDiagRslDidEcuIdentificationHwPartNo ; idx++)
               {
                  diagData[kDiagDidOffset + idx] = 0x20u;
               }
               break;
            }

            /* F122 */
            case kFblDiagDidSwEbomPartNo                 :
            {
               /* ToDo: Check if this DID is supported */

               /* Iterate over the logical block table and report part number of all blocks */
               for(idx = 0u; idx < FBL_MTAB_NO_OF_BLOCKS; idx++)
               {
                  result |= ApplFblNvReadSwEbomPartNumber(idx, &diagData[kDiagDidOffset + idx * kDiagRslDidSwEbomPartNo]);
               }

               break;
            }

            /* F132 */
            case kFblDiagDidEbomEcuPartNo                :
            {
               result = ApplFblNvReadEbomEcuPartNumber(&diagData[kDiagDidOffset]);
               break;
            }

            /* F154 */
            case kFblDiagDidHardwareSupplierId           :
            {
               didBuffer[kDiagDidOffset] = fblCommonData.HwSupplierId[0];
               didBuffer[kDiagDidOffset + 1u] = fblCommonData.HwSupplierId[1];

               break;
            }

            /* F155 */
            case kFblDiagDidSoftwareSupplierId           :
            {
               didBuffer[kDiagDidOffset] = fblCommonData.swSupplierId[0];
               didBuffer[kDiagDidOffset + 1u] = fblCommonData.swSupplierId[1];
               break;
            }

            /* F158 */
            case kFblDiagDidVehicleIdentification        :
            {
               /* ToDo: Copy VIN */
               for (idx = 0; idx < kDiagRslDidVehicleIdentification; idx++)
               {
                  diagData[kDiagDidOffset + idx] = 0x20u;                 
               }
               break;
            }

            /* F180 */
            case kFblDiagDidBootSwVersionInfo            :
            {
               /* Number of boot software logical blocks */
               diagData[2] = 1u;

               for (idx = 0u; idx < kDiagRslDidBootSwVersionInfo; idx++)
               {
                  diagData[kDiagDidOffset + 1u + idx] = fblCommonData.bootSoftwareVersionInformation[idx];                 
               }
               break;
            }

            /* F181 */
            case kFblDiagDidApplSwIdentification         :
            {
               /* Number of application software logical blocks */
               diagData[2] = kBlockTypeCodeNoOfBlocks;

               /* Iterate over the logical block table and report the code block fingerprints */
               for(idx = 0u; idx < FBL_MTAB_NO_OF_BLOCKS; idx++)
               {
                  if (FblLogicalBlockTable.logicalBlock[idx].blockType == kBlockTypeCode)
                  {
                     result |= ApplFblNvReadSoftwareIdentification(idx, &diagData[3u + idx * kDiagRslDidApplSwIdentification]);
                  }
               }
               break;
            }

            /* F182 */
            case kFblDiagDidApplDataIdentification       :
            {
               /* Number of application software logical blocks */
               diagData[2] = kBlockTypeDataNoOfBlocks;

               /* Iterate over the logical block table and report the code block fingerprints */
               for(idx = 0u; idx < FBL_MTAB_NO_OF_BLOCKS; idx++)
               {
                  if (FblLogicalBlockTable.logicalBlock[idx].blockType == kBlockTypeData)
                  {
                     result |= ApplFblNvReadSoftwareIdentification(idx, &diagData[3u + idx * kDiagRslDidApplSwIdentification]);
                  }
               }
               break;
            }

            /* F186 */
            case kFblDiagDidActiveDiagSessDid            :
            {
               /* Active diagnostic session */
               if (GetDiagProgrammingSession())
               {
                  diagData[kDiagDidOffset] = kDiagSubProgrammingSession;
               }
               else if (GetDiagExtendedSession())
               {
                  diagData[kDiagDidOffset] = kDiagSubExtendedDiagSession;
               }
               else
               {
                  diagData[kDiagDidOffset] = kDiagSubDefaultSession;
               }

               /* Active Diagnostic Session of ECU - (0: Application, 1: Boot)*/
               diagData[kDiagDidOffset + 1u] = kDiagProgStatMode; 

               break;
            }

            /* F187 */
            case kFblDiagDidCodepEcuPartNo               :
            {
               result = ApplFblNvReadCoDePEcuPartNumber(&diagData[kDiagDidOffset]);
               break;
            }

            /* F188 */
            case kFblDiagDidVehicleManufEcuSwNo          :
            {
               result = ApplFblNvReadVehicleManufEcuSwNumber(&diagData[kDiagDidOffset]);
               break;
            }

            /* F18C */
            case kFblDiagDidEcuSerialNumber              :
            {
               /* ToDo: Copy ECU Serial Number */
               for (idx = 0; idx < kDiagRslDidEcuSerialNumber; idx++)
               {
                  diagData[kDiagDidOffset + idx] = 0x00u;                 
               }
               break;
            }

            /* F190 */
            case kFblDiagDidVinOriginal                  :
            {
               /* ToDo: Copy VIN Original */
               for (idx = 0; idx < kDiagRslDidVinCurrent; idx++)
               {
                  diagData[kDiagDidOffset + idx] = 0x20u;                 
               }
               break;
            }
            
            /* F191 */ 
            case kFblDiagDidVehicleManufECUHwNo          :
            {
               result = ApplFblReadVehicleManufEcuHwNumber(&diagData[kDiagDidOffset]);
               break;
            }

            /* F192 */
            case kFblDiagDidSupplierManufECUHwPartNo      :
            {
               for (idx = 0; idx < kDiagRslDidSupplierManufECUHwPartNo; idx++)
               {
                  diagData[2u + idx] = fblCommonData.SuppManEcuHwPartNumber[idx];
               }
               break;
            }

            /* F193 */
            case kFblDiagDidSupplierManufECUHwVersionNo   :
            {
               diagData[2u] = fblCommonData.SuppManEcuHwVersionNumber[0];
               break;
            }

            /* F194 */
            case kFblDiagDidSupplierManufECUSwPartNo     :
            {
               /* ToDo: Check if this item shall be update after application download */
               for (idx = 0; idx < kDiagRslDidSupplierManufECUSwPartNo; idx++)
               {
                  diagData[2u + idx] = 0x20u;
               }

               break;
            }

            /* F195 */
            case kFblDiagDidSupplierManufECUSwVersionNo  :
            {
               diagData[2] = 0x55;
               diagData[3] = 0x55;
               break;
            }

            /* F196 */
            case kFblDiagDidExRegOrTypeApprovalNo        :
            {
               for (idx = 0; idx < kDiagRslDidExRegOrTypeApprovalNo; idx++)
               {
                  diagData[2u + idx] = 0xAAu;
               }
               break;
            }

            /* F1A0 */
            case kFblDiagDidSystemIdentificationData     :
            {
               idx = kDiagDidOffset;
               result |= ApplFblNvReadCoDePEcuPartNumber(&diagData[idx]); /* F187 */
               idx += kDiagRslDidCodepEcuPartNo;
               result |= ApplFblNvReadEbomEcuPartNumber(&diagData[idx]);  /* F132 */
               idx += kDiagRslDidEbomEcuPartNo;
               result |= ApplFblReadVehicleManufEcuHwNumber(&diagData[idx]); /* F191 */
               idx += kDiagRslDidVehicleManufECUHwNo;

               /* ToDo: Copy VIN Current */
               for (j = 0; j < kDiagRslDidVinCurrent; j++)                          /* F1B0 */
               {
                  diagData[idx + j] = 0x20u;                 
               }
               idx += kDiagRslDidVinCurrent;

               result |= ApplFblReadEcuDiagnosticIdentification(&diagData[idx]);
               break;
            }

            /* F1A2 */
            case kFblDiagDidVectorDeliveryId             :
            {
               /* BSW (3 bytes) */
               diagData[2u + 0u] = 0x20u;
               diagData[2u + 1u] = 0x00u;
               diagData[2u + 2u] = 0x00u;

               /* CBD (4 bytes)*/
               diagData[2u + 3u] = 0x17u;
               diagData[2u + 4u] = 0x00u;
               diagData[2u + 5u] = 0x06u;
               diagData[2u + 6u] = 0x90u;

               /* Vector Delivery Number (1 byte) */
               diagData[2u + 7u] = 0x01u;

               /* ASR Revision (1 byte)*/
               diagData[2u + 8u] = 0x04u;

               /* SLP (1 byte)*/
               diagData[2u + 9u] = 0x05u;
               break;
            }

            /* F1A4 */
            case kFblDiagDidAlgorithmIdNumberReprog      :
            {
               diagData[kDiagDidOffset] = fblCommonData.algorithmIdNumber[0];
               diagData[kDiagDidOffset + 1u] = fblCommonData.algorithmIdNumber[1];
               break;
            }

            /* F1B0 */
            case kFblDiagDidVinCurrent                   :
            {
               /* ToDo: Copy VIN Current */
               for (idx = 0; idx < kDiagRslDidVinCurrent; idx++)
               {
                  diagData[kDiagDidOffset + idx] = 0x20u;                 
               }
               break;
            }

            /* F1B3 */
            case kFblDiagDidBootSwFingerprintRead        :
            {
               diagData[2] = 1; /* Boot Fingerprint for one module */
               diagData[3] = 0u;   /* Block number */

               diagData[4] = 18u;   /* Programming Year */
               diagData[5] = 6u;    /* Programming Month */
               diagData[6] = 6u;    /* Programming Day */

               for (j = 0u; j < 10u; j++)
               {
                  diagData[7u + j] = 0x20u;  /* Fill diagnostic tool serial number with spaces */
               }

               break;
            }

            /* F1B4 */
            case kFblDiagDidApplSwFingerprintRead        :
            {
               /* Number of application software blocks */
               diagData[2] = kBlockTypeCodeNoOfBlocks;   

               /* Iterate over the logical block table and report the code block fingerprints */
               for(j = 0u; j < FBL_MTAB_NO_OF_BLOCKS; j++)
               {
                  if (FblLogicalBlockTable.logicalBlock[j].blockType == kBlockTypeCode)
                  {
                     diagData[3u + j * kDiagRslDidBootSwFingerprintRead] = (vuint8)FblLogicalBlockTable.logicalBlock[j].blockNr; 
                     result |= ApplFblNvReadFingerprint(j, &diagData[4u + j * kDiagRslDidBootSwFingerprintRead]); 
                  }
               }
               break;
            }

            case kFblDiagDidApplDataFingerprintRead      :
            {
               /* Number of application data blocks */
               diagData[2] = kBlockTypeDataNoOfBlocks;   

               /* Iterate over the logical block table and report the data block fingerprints */
               for(j = 0u; j < FBL_MTAB_NO_OF_BLOCKS; j++)
               {
                  if (FblLogicalBlockTable.logicalBlock[j].blockType == kBlockTypeCode)
                  {
                     diagData[3u + j * kDiagRslDidBootSwFingerprintRead] = (vuint8)FblLogicalBlockTable.logicalBlock[j].blockNr; 
                     result |= ApplFblNvReadFingerprint(j, &diagData[4u + j * kDiagRslDidBootSwFingerprintRead]); 
                  }
               }
               break;
            }

            default:
            {
               break;
            }
         } /* switch (currentDid) */
         i++;
         outIdx += outIdxAdd;
      } /* if (outIdxAdd != 0u) */
   }

   if (result != kFblOk)
   {
      /* Data could not be read successfully from NVM */
      DiagNRCConditionsNotCorrect();
   }
   else if (outIdx == 0u)
   {
      DiagNRCRequestOutOfRange();
   }
   else
   {
      /* No error occured - send positive response */
   }

   diagRespDataLen = outIdx;

   /* Transmit response message:
    * If a negative response has to be transmitted, the length parameter is
    * ignored. In case of a positive response, the length parameter does not
    * include the service id. */
   DiagProcessingDone(diagRespDataLen);
}  /* PRQA S 2006, 6010, 6030 */ /* MD_MSR_14.7, MD_MSR_STPTH, MD_MSR_STCYC */

/***********************************************************************************************************************
 *  ApplDiagWriteDataByIdentifier
 **********************************************************************************************************************/
/*! \brief         WriteDataByIdentifier service function.
 *  \param[in,out] pbDiagData Pointer to diag service data (after SID!)
 *  \param[in]     diagReqDataLen Service data length (without SID!)
 *  \return        kFblOk: WriteDataByIdentifer was successful, KFblFailed: WriteDataByIdentifier failed.
 **********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_FblKbApi_3673 */
vuint8 ApplFblWriteDataByIdentifier( vuint8 * pbDiagData, tTpDataType diagReqDataLen )
{
   /* Two-byte routine identifier */
   vuint16 diagFmtDataId;
   vuint8 result;

#if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   /* Parameters not used: avoid compiler warning */
   (void)diagReqDataLen;  /* PRQA S 3112 */ /* MD_MSR_14.2 */
#endif

   /* Initialize variables */
   result = kFblOk;

   /* Read two-byte routineControlId (minimum length already checked) */
   diagFmtDataId =  (vuint16)pbDiagData[0] << 8;
   diagFmtDataId |= (vuint16)pbDiagData[1];  /* PRQA S 3199 */ /* MD_FblKbApiOem_3199 */

   switch (diagFmtDataId)
   {
      default:
      {
         DiagNRCRequestOutOfRange();
         result = kFblFailed;
         break;
      }
   }  /* PRQA S 3315 */ /* MD_FblKbApiOem_3315 */

   return result;
}

/***********************************************************************************************************************
 *  ApplFblReportDTCByStatusMask
 **********************************************************************************************************************/
/*! \brief         Read DTC by status mask service function
 *  \param[in,out] pbDiagData Pointer to diag service data (after service ID)
 *  \param[in]     diagReqDataLen Service data length (without service ID)
 *  \return        Read result
 **********************************************************************************************************************/
tFblResult ApplFblReportDTCByStatusMask( vuint8* pbDiagData, tTpDataType diagReqDataLen )
{
   tFblResult result;

   vuint16 diagRespDataLen;
   vuint8 dtcMask;

   /* Output pointer */
   vuint8* diagData;

   result = kFblOk;

   /* Initialize Response data length */
   diagRespDataLen = 0x02u;
   dtcMask = pbDiagData[1u];
   diagData = &pbDiagData[2u];

   if (ApplFblGetApplStatus() == kApplValid)
   {
      /* If the application is valid send response with no DTCs */
      pbDiagData[1u] = 0xFFu; 
   }
   else
   {
      if ((kDiagDtcStatus & dtcMask) != 0x00u)
      {
         diagData[0] = (vuint8)((kDiagDtc_NotProgrammedCodeInternal >> 16u) & 0xFFu);
         diagData[1] = (vuint8)((kDiagDtc_NotProgrammedCodeInternal >> 8u) & 0xFFu);
         diagData[2] = (vuint8)(kDiagDtc_NotProgrammedCodeInternal & 0xFFu);
         diagData[3] = kDiagDtcStatus;

         diagRespDataLen += 4; 
      }
   }

   DiagProcessingDone(diagRespDataLen);
   return result;
}

#if defined( FBL_ENABLE_DEBUG_STATUS )
/***********************************************************************************************************************
 *  ApplFblInitErrStatus
 **********************************************************************************************************************/
/*! \brief       Initialize error status information.
 **********************************************************************************************************************/
void ApplFblInitErrStatus( void )
{
   errStatFlashDrvVersion[0] = 0;
   errStatFlashDrvVersion[1] = 0;
   errStatFlashDrvVersion[2] = 0;
   errStatFlashDrvErrorCode = 0;
   errStatErrorCode = 0;
   errStatFblStates = 0;
   errStatLastServiceId = 0;
   errStatDescriptor.blockNr = 0;
   errStatDescriptor.blockStartAddress = 0;
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
 *  END OF FILE: FBL_APDI.C
 **********************************************************************************************************************/
