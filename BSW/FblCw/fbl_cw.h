/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  fbl_cw.h
 *      Project:  FblWrapperCom_PduR
 *       Module:  Implementation
 *    Generator:  CFG5
 *
 *  Description:  Fbl Communication wrapper layer for MICROSAR ASR4
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Joern Herwig                  JHg           Vector Informatik GmbH
 *  Achim Strobelt                Ach           Vector Informatik GmbH
 *  Gunnar Meiss                  visms         Vector Informatik GmbH
 *  Christian Baeuerle            viscb         Vector Informatik GmbH
 *  Dennis O'Donnell              Dod           Vector North America, Inc.
 *  Andreas Wenckebach            AWh           Vector Informatik GmbH
 *  Robert Schaeffner             Rr            Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  05.00.00   2017-07-16  visms   STORYC-1890      Support PostBuildSelectable
 *             2017-08-03  viscb   STORYC-2089      Support TP Change, Read and Reset Parameter
 *  05.01.00   2017-08-06  JHg     ESCAN00096563    Resolved compiler warning
 *                         JHg     ESCAN00096564    Added FblCwGetResponseAddress API function
 *                         JHg     ESCAN00096565    Set FBL_CW_ENABLE_MULTIPLE_CONNECTIONS for multi connection configuration
 *                                                  Do not call ApplFblRead/WriteTpTargetAddr for single connection use-case
 *  05.01.01   2017-10-05  Ach     ESCAN00096903    Response after reset is not sent correctly
 *  05.01.02   2017-10-12  Ach     ESCAN00097011    Communication is not locked to one specific tester
 *  05.02.00   2017-12-20  Ach     ESCAN00096979    FblCw_ResetParameter writes initial block size into STmin parameter
 *                                 ESCAN00097001    Rework address handling in transitions between bootloader and application
 *  05.03.00   2018-01-22  Dod     ESCAN00098086    Support J1939 Network Management
 *                                 ESCAN00098087    Support J1939 Baudrate Detection
 *                         Ach     ESCAN00098145    Compile error in case no functional connection is configured
 *                         AWh     ESCAN00098162    Allow config of condition defining accepted RxPdus for active connection
 *  05.04.00   2018-03-14  MVi     ESCAN00097553    Added support for ComM, CanSM, CanNm
 *                         Ach     ESCAN00098643    Support decline of requests on additional connections
 *  05.04.01   2018-03-27  Rr      ESCAN00098834    Fixed return value handling in FblCwPrepareResponseAddress
 *  05.04.02   2018-05-15  Ach     ESCAN00099337    Provide empty interface for FblCw_ResetParameter()
 *                                 ESCAN00099407    Transceiver is not initialized
 *  05.04.03   2018-06-13  Ach     ESCAN00099675    Stay in boot status variable is not initialize
 *********************************************************************************************************************/

#ifndef __FBL_CW_H__
# define __FBL_CW_H__

/**********************************************************************************************************************
 *  VERSION
 *********************************************************************************************************************/
# define FBLWRAPPERCOM_PDUR_VERSION           0x0504u
# define FBLWRAPPERCOM_PDUR_RELEASE_VERSION   0x03u

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "ComStack_Types.h"
# include "Dcm_Cbk.h"
# include "FblCw_Cfg.h"
# include "FblCw_Lcfg.h"

/**********************************************************************************************************************
 *  DEFINES
 *********************************************************************************************************************/

/**
  \defgroup  FblCwIdentification FblCw Identification
  \brief  Vendor and module identification of this implementation.
  \{
*/
# define FBLCW_VENDOR_ID              30U              /**< the vendor ID of this implementation. */
# define FBLCW_MODULE_ID              255U             /**< the module ID of this implementation. */
/**
  \}
*/

/**
  \defgroup  FblCwARReleaseVersion FblCw AUTOSAR release version number
  \brief  Version number of AUTOSAR release on which the appropriate implementation is based on.
  \{
*/
# define FBLCW_AR_RELEASE_MAJOR_VERSION       4U
# define FBLCW_AR_RELEASE_MINOR_VERSION       0U
# define FBLCW_AR_RELEASE_REVISION_VERSION    3U
/**
  \}
*/

/**
  \defgroup  FblCwDetErrorCodes FblCw Det Error Codes
  \brief  FblCw development error IDs.
  \{
*/
# define FBLCW_E_NO_ERROR                    0U /**< this code is used to detect that no error occurred. Det_ReportError() is not called.  */
# define FBLCW_E_PARAM                       1U /**< the API service has been with a wrong parameter. */
# define FBLCW_E_UNINIT                      2U /**< the API service has been called before FblCw was initialized with FblCw_Init() or after a call to FblCw_DeInit() */
# define FBLCW_E_PARAM_POINTER               3U /**< the API service has been called with a not expected NULL pointer */
# define FBLCW_E_INIT_FAILED                 4U /**< the API service has been when FblCw was already initialized. */
/**
  \}
*/

/**
  \defgroup  FblCwApiIds FblCw Module Service Identifiers
  \brief  Unique identifier of a FblCw module service.
  \{
*/
# define FBLCW_APIID_INIT                      0U
# define FBLCW_APIID_STARTOFRECEPTION          1U
# define FBLCW_APIID_COPYRXDATA                2U
# define FBLCW_APIID_COPYTXDATA                3U
# define FBLCW_APIID_TPRXINDICATION            4U
# define FBLCW_APIID_TPTXCONFIRMATION          5U
/**
  \}
*/

/* Reference interface version */
/** Major interface version identifies incompatible changes */
# define FBL_CW_API_REFERENCE_VERSION_MAJOR      0x02u
/** Minor interface version identifies backward compatible changes */
# define FBL_CW_API_REFERENCE_VERSION_MINOR      0x00u
/** Release interface version identifies cosmetic changes */
# define FBL_CW_API_REFERENCE_VERSION_RELEASE    0x00u

# if defined( kFblCwTxPendingTimeout )
# else
/** Retry timeout for transmission */
#  if( FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
#   define kFblCwTxPendingTimeout           (5000u / FBL_REPEAT_CALL_CYCLE)
#  else
#   define kFblCwTxPendingTimeout           (100u / FBL_REPEAT_CALL_CYCLE)
#  endif
# endif
# if defined( kFblCwMaxWaitTime )
# else
/** Wait time for transmission in case response pending is in progress */
#  if ( FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
#   define kFblCwMaxWaitTime                (1000u / FBL_REPEAT_CALL_CYCLE)
#  else
#   define kFblCwMaxWaitTime                (10u / FBL_REPEAT_CALL_CYCLE)
#  endif
# endif
/** Default value for CanIf mode switch timeout */
# if defined( kFblCwTxModeSwitchTimeout )
# else
/** Wait time for CanIf mode switch */
#  define kFblCwTxModeSwitchTimeout        (100u / FBL_REPEAT_CALL_CYCLE)
# endif

/** Default waiting time for shutdown callback */
# if defined (kFblCwShutdownWaitTime)
# else
#  define kFblCwShutdownWaitTime           (4500u / FBL_REPEAT_CALL_CYCLE)
# endif

/* Flag if a call to Timer or State Task is currently allowed
   Commonly this is used e.g. to prevent a call to the tasks if a flash operation
   is currently in progress and the tasks cannot be called, because they are complex and in ROM.
   But this configuration is mandatory for RCR-RP handling when the MSR communcation stack is used. */

/* All Task code is in RAM */
# define FblCwIsTimerTaskAllowed()        0x01u
# define FblCwIsStateTaskAllowed()        0x01u

/** This define indicates task locks are handled by ComWrapper */
# define FBL_CW_LOCKS_TASKS
/** This define indicates task locks are handled by ComWrapper (compatibility variant) */
# define FBLCW_LOCKS_TASKS

/* Call parameter type for reset cases */
/** This define will be used in case of regular ECU reset e.g. after 11 01 */
# define kFblCwResetEcuRegularCase         0x00u
/** This define will be used in case of non-regular reset of the diagnostic e.g.: Timeout, EcuReset with SuppressPosRsp */
# define kFblCwResetEcuTesterTimeout       0x01u

/* Macros for compatibility */
# define FblCwSetOfflineMode()
# define FblCwSetOnlineMode()

/** Re-map CwTransmit to CwCanTransmit, because response type is not required here */
# define FblCwTransmit(data, length, type) FblCwPduTransmit((data), (length)) /* PRQA S 3453 */ /* MD_MSR_19.7 */

# if ( FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
/** Re-map FblCwShutdownRequest to FblCwPduShutdownRequest, because reset case is not needed here */
#  define FblCwShutdownRequest(a)           FblCwPduShutdownRequest() /* PRQA S 3453 */ /* MD_MSR_19.7 */
# else
/* Shutdown request from Diag-layer to Com-Wrapper */
#  define FblCwShutdownRequest(a)          FblSetShutdownRequest() /* PRQA S 3453 */    /* MD_MSR_19.7 */
# endif

/* Parameter CallType for FblCwTransmit. Not used, but included for compatibility */
# define kFblCwTxCallPosResponse           0x00u
# define kFblCwTxCallNegResponse           0x01u
# define kFblCwTxCallFailedResponse        0x02u
# define kFblCwTxCallRcrRp                 0x03u
# define kFblCwTxCallNoResponse            0x04u

/* Parameter for FblDiagConfirmation and FblDiagTxErrorIndication */
# define kFblCwMsgTypeNormal               0x00u   /**< Default response */
# define kFblCwMsgTypeRcrRp                0x03u   /**< Response pending message */

/** Length of the RCRP messages */
# define kFblCwRcrRpMsgLength              0x03u

/* Macros for compatibility */
# define FblCwDiscardReception()
# define FblCwSetTxInit()
# define FblCwSetRxBlock()

# if ( FBLCW_MODULE_FRSM == STD_ON )
/* Macros for detection of wake-up event */
#  define FblCwGetWakeUpEvent()           (0x01u == cwWakeUpFlag)
#  define FblCwSetWakeUpEvent()           (cwWakeUpFlag = 0x01u)
#  define FblCwClrWakeUpEvent()           (cwWakeUpFlag = 0x00u)
# endif

# if ( FBLCW_MODULE_COMM == STD_OFF )
/* ComM indications for DCM */
#  define Dcm_ComM_FullComModeEntered(a)
#  define Dcm_ComM_SilentComModeEntered(a)
#  define Dcm_ComM_NoComModeEntered(a)
# endif

# if (FBLCW_CHANGE_PARAMETER == STD_OFF)
#  define FblCw_ResetParameter() kFblOk
# endif

# if (FblCw_GetSizeOfDcmDslConnectionInfo() > 1u)
/** More than one connection configured */
#  define FBL_CW_ENABLE_MULTIPLE_CONNECTIONS
# endif

# if (FBLCW_DECLINED_REQUESTS == STD_ON)
#  define kFblCwNumberOfRequests (kFblCwMaxNumDeclinedRequests + 1u)
#  define FBL_CW_ENABLE_DECLINED_REQUESTS
# else
#  define kFblCwNumberOfRequests 1u
# endif
# define FBL_CW_MAIN_REQUEST_INDEX 0u

/**********************************************************************************************************************
 *  CONSISTENCY CHECK
 *********************************************************************************************************************/
# if ( FBLCW_KEY_SLOT_MODE == STD_ON )
#  if ( FBLCW_USE_INIT_POINTER == STD_ON)
#   error "FBLCW_KEY_SLOT_MODE is not supported if FBLCW_USE_INIT_POINTER is used!"
#  endif
#  if !defined (FBLCW_NW_STATUS_PDU)
#   error "Define the FBLCW_NW_STATUS_PDU in the user config file! At this point the handle ID of the FrIfLPdu of the first slot shall be configured."
#  endif
# endif

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/** Data type for CW length information */
typedef PduLengthType tCwDataLengthType;
typedef tCwDataLengthType tTpDataType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define FBLCW_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

/**********************************************************************************************************************
  FblCw_InitMemory
**********************************************************************************************************************/
/*! \brief    The function initializes variables, which cannot be initialized with the startup code.
    \details  -
    \context  TASK
    \synchronous TRUE
    \reentrant   FALSE
    \pre      FblCw_Init() is not called yet.
**********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_InitMemory(void);

/**********************************************************************************************************************
  FblCw_Init
**********************************************************************************************************************/
/*! \brief    This service initializes internal and external interfaces and variables of the MICROSAR FBLCW layer
              for the further processing.
    \details  -
    \param    config  NULL_PTR if FBLCW_USE_INIT_POINTER is STD_OFF
                      Pointer to the FblCw configuration data if FBLCW_USE_INIT_POINTER is STD_ON
    \context  TASK
    \warning  FblCw_Init shall not pre-empt any FblCw function.
              The rest of the system must guarantee that FblCw_Init is not called in such a way.
    \synchronous TRUE
    \reentrant   FALSE
    \pre      FblCw_InitMemory() has to be executed previously, if the startup code does not initialize variables.
    \pre      FblCw is not in initialized state.
**********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_Init(P2CONST(FblCw_ConfigType, AUTOMATIC, FBLCW_INIT_DATA) config);

/**********************************************************************************************************************
  FblCw_Deinit
**********************************************************************************************************************/
/*! \brief    By a call to ComDeInit FblCw is put into an not initialized state.
    \details  -
    \context  TASK
    \warning  FblCw_Deinit shall not pre-empt any FblCw function.
              The rest of the system must guarantee that FblCw_DeInit is not called in such a way.
    \synchronous TRUE
    \reentrant   FALSE
    \pre      -
**********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_Deinit(void);

/**********************************************************************************************************************
 *  FblCwIdleTask
 *********************************************************************************************************************/
/*! \brief       Communication wrapper idle task function
 *  \details     The function polls the communication channels, it also executes some pending actions,
 *               which could not fulfilled in the event function.
 *               Note, that the order of polling is a design decision: Error-Task, TX-Task, RX-Task.
 *  \pre         CW is initialized
 *********************************************************************************************************************/
void FblCwIdleTask(void);

/**********************************************************************************************************************
 *  FblCwTimerTask
 *********************************************************************************************************************/
/*! \brief       Communication wrapper timer task function
 *  \detail      Typically called with a 1 ms cycle time
 *  \pre         CW is initialized
 *********************************************************************************************************************/
void FblCwTimerTask(void);

/**********************************************************************************************************************
 *  FblCwStateTask
 *********************************************************************************************************************/
/*! \brief       Polling of CAN/FlexRay receive messages and message confirmation
 *  \pre         CW is initialized
 *********************************************************************************************************************/
void FblCwStateTask(void);

/**********************************************************************************************************************
 *  FblCwPduTransmit
 *********************************************************************************************************************/
/*! \brief       Schedule data for transmission.
 *  \param[in]   data Pointer to transmit data
 *  \param[in]   length Length of data
 *  \pre         CW is initialized
 *********************************************************************************************************************/
void FblCwPduTransmit(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * data, tCwDataLengthType length);

# if (FBLCW_DECLINED_REQUESTS == STD_ON)
/**********************************************************************************************************************
 *  FblCwPduTransmitDeclinedRequest
 *********************************************************************************************************************/
/*! \brief       Schedule data for transmission.
 *  \param[in]   data Pointer to transmit data
 *  \param[in]   length Length of data
 *  \param[in]   connectionIndex Connection index of declined messages
 *  \pre         CW is initialized
 *********************************************************************************************************************/
void FblCwPduTransmitDeclinedRequest(V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * data, tCwDataLengthType length, vuint8 connectionIndex);
# endif

/**********************************************************************************************************************
 *  FblCwTransmitRP
 *********************************************************************************************************************/
/*! \brief       Transmit given data buffer with RCR-RP
 *  \pre         CW is initialized
 *  \param[in]   data Pointer to the data to be transmitted
 *********************************************************************************************************************/
void FblCwTransmitRP(const V_MEMRAM1 vuint8 V_MEMRAM2 V_MEMRAM3 * data);

/**********************************************************************************************************************
 *  FblCwRetransmitRP
 *********************************************************************************************************************/
/*! \brief       Transmit the stored response pending buffer
 *  \pre         CW is initialized, FblCwTransmitRP executed before
 *********************************************************************************************************************/
void FblCwRetransmitRP(void);

/**********************************************************************************************************************
 *  FblCwTxSetTargetAddress
**********************************************************************************************************************/
/*! \brief       Prepare response address.
 *  \param[in]   targetAddress  Target node addressed in response
**********************************************************************************************************************/
void FblCwTxSetTargetAddress(FblCw_DcmDslConnectionInfoIterType targetAddress);

/**********************************************************************************************************************
 *  FblCwTxGetTargetAddress
**********************************************************************************************************************/
/*! \brief       Get active response address / connection.
 *  \return      Active response address / connection
**********************************************************************************************************************/
FblCw_DcmDslConnectionInfoIterType FblCwGetResponseAddress(void);

/**********************************************************************************************************************
 *  FblCwResetResponseAddress
 *********************************************************************************************************************/
/*! \brief       Reset response address / connection to default value
 *********************************************************************************************************************/
void FblCwResetResponseAddress(void);

/**********************************************************************************************************************
 *  FblCwPrepareResponseAddress
 *********************************************************************************************************************/
/*! \brief       Read target address from NV-memory and prepare response address
 *  \return      kFblOk if setting response address was successful, kFblFailed otherwise
 *********************************************************************************************************************/
tFblResult FblCwPrepareResponseAddress(void);

/**********************************************************************************************************************
 *  FblCwSaveResponseAddress
 *********************************************************************************************************************/
/*! \brief       Save response address to NV-memory
 *  \return      kFblOk if address was successfully store, kFblFailed otherwise
 *********************************************************************************************************************/
tFblResult FblCwSaveResponseAddress(void);

# if ( FBLCW_BAUDRATE_SWITCH == STD_ON )
/**********************************************************************************************************************
 *  FblCwCheckBaudrate
 *********************************************************************************************************************/
/*! \brief       Check whether requested baud rate is supported for active connection
 *  \param[in]   baudrate  Requested baud rate (in kBaud)
 *  \return      kFblOk if baud rate is supported for active connection, kFblFailed otherwise
 *********************************************************************************************************************/
tFblResult FblCwCheckBaudrate(vuint32 baudrate);

/**********************************************************************************************************************
 *  FblCwSwitchBaudrate
 *********************************************************************************************************************/
/*! \brief       Switch baud rate of active connection
 *  \param[in]   baudrate Requested baud rate (in kBaud)
 *  \return      kFblOk if baud rate was successfully switched, kFblFailed otherwise
 *********************************************************************************************************************/
tFblResult FblCwSwitchBaudrate(vuint32 baudrate);
# endif

/**********************************************************************************************************************
 *  FblCwResetRxBlock
 *********************************************************************************************************************/
/*! \brief       Reset transport layer called by DiagResponseProcessor
 *********************************************************************************************************************/
void FblCwResetRxBlock(void);

/**********************************************************************************************************************
 *  FblCwGetPayloadLimit
 *********************************************************************************************************************/
/*! \brief       Get payload limit of active connection
 *  \return      Payload limit of active connection in bytes
 *********************************************************************************************************************/
tCwDataLengthType FblCwGetPayloadLimit(void);

# if (FBLCW_CHANGE_PARAMETER == STD_ON)
/**********************************************************************************************************************
 *  FblCw_ChangeParameter
 *********************************************************************************************************************/
/*! \brief      This API function is used to change transport layer parameters
 *  \param[in]  parameter Parameter type that shall be changed
 *  \param[in]  value New value of given parameter type
 *  \pre        CW is initialized and active
 *********************************************************************************************************************/
FUNC(tFblResult, FBLCW_CODE) FblCw_ChangeParameter(TPParameterType parameter, uint16 value);

/**********************************************************************************************************************
 *  FblCw_ResetParameter
 *********************************************************************************************************************/
/*! \brief      This API function is used to reset transport layer parameters to default values
 *  \pre        CW is initialized and active
 *********************************************************************************************************************/
FUNC(tFblResult, FBLCW_CODE) FblCw_ResetParameter(void);

/**********************************************************************************************************************
 *  FblCw_ReadParameter
 *********************************************************************************************************************/
/*! \brief      This API function is used to read transport layer parameters
 *  \param[in]  parameter Parameter type that shall be read
 *  \param[out] value Reference of parameter value
 *  \pre        CW is initialized and active
 *********************************************************************************************************************/
FUNC(tFblResult, FBLCW_CODE) FblCw_ReadParameter(TPParameterType parameter, uint16 * value);
# endif

# if ( FBLCW_EXISTS_ETH_BUSTYPEOFDCMDSLCONNECTIONINFO == STD_ON )
/**********************************************************************************************************************
  FblCwPduShutdownRequest
**********************************************************************************************************************/
/*! \brief      Shutdown all connections to prepare for reset
**********************************************************************************************************************/
void FblCwPduShutdownRequest(void);
# endif

# if ( FBLCW_MODULE_COMM == STD_ON )
/**********************************************************************************************************************
 *  Dcm_ComM_NoComModeEntered()
 *********************************************************************************************************************/
/*! \brief          ComM call-back for entering no communication mode.
 *  \details        This call informs the DCM module about a ComM mode change to COMM_NO_COMMUNICATION.
 *  \param[in]      networkId    The communication channel on which this state is now active
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) Dcm_ComM_NoComModeEntered(NetworkHandleType channel);

/**********************************************************************************************************************
 *  Dcm_ComM_SilentComModeEntered()
 *********************************************************************************************************************/
/*! \brief          ComM callback for entering silent communication mode.
 *  \details        This call informs the DCM module about a ComM mode change to COMM_SILENT_COMMUNICATION.
 *  \param[in]      networkId    The communication channel on which this state is now active
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) Dcm_ComM_SilentComModeEntered(NetworkHandleType channel);

/**********************************************************************************************************************
 *  Dcm_ComM_FullComModeEntered()
 *********************************************************************************************************************/
/*! \brief          ComM callback for entering full communication mode.
 *  \details        This call informs the DCM module about a ComM mode change to COMM_FULL_COMMUNICATION.
 *  \param[in]      networkId    The communication channel on which this state is now active
 *********************************************************************************************************************/
FUNC(void, FBLCW_CODE) Dcm_ComM_FullComModeEntered(NetworkHandleType channel);
# endif

# define FBLCW_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */  /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *  GLOBAL DATA DECLARATIONS
 *********************************************************************************************************************/
# if(FBLCW_USE_INIT_POINTER == STD_ON)
#  define FBLCW_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern P2CONST(FblCw_ConfigType, FBLCW_VAR_ZERO_INIT, FBLCW_PBCFG) FblCw_ConfigDataPtr;

#  define FBLCW_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
# endif

#endif

/**********************************************************************************************************************
 *  END OF FILE: FBL_CW.H
 *********************************************************************************************************************/
