/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: CanIf
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701374A
 *    License Scope : The usage is restricted to CBD1800284_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanIf_Lcfg.c
 *   Generation Time: 2018-07-26 12:56:48
 *           Project: DemoFbl - Version 1.0
 *          Delivery: CBD1800284_D00
 *      Tool Version: DaVinci Configurator (beta) 5.17.51 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

#define CANIF_LCFG_SOURCE

/* PRQA S 0850 EOF */ /* MD_MSR_19.8 */
/* PRQA S 0857 EOF */ /* MD_CanIf_1.1_NumberOfMacroDefinitions */
/* PRQA S 0779 EOF */ /* MD_CanIf_5.1 */
/* PRQA S 0777 EOF */ /* MD_CanIf_5.1 */
/* PRQA S 1330, 1334 EOF */ /* MD_CanIf_16.4, MD_CanIf_16.4 */

/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
/** 
  \brief  Required external files.
*/ 

#include "CanIf_Cfg.h"

 /*  CanTp Header Files  */ 
#include "CanTp_Cfg.h"
#include "CanTp_Cbk.h"
 /*  CDD Header Files  */ 
#include "CanIf_Cdd.h"


#define CANIF_START_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/**********************************************************************************************************************
  \var  Prototypes of callback functions
**********************************************************************************************************************/

/** 
  \brief  Tx confirmation functions.
*/



/** 
  \brief  Rx indication functions.
*/





#define CANIF_STOP_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/**********************************************************************************************************************
  ComStackLib
**********************************************************************************************************************/
/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanIf_BusOffNotificationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr = FblCw_ControllerBusOff;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CanIfCtrlId2MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_CanIfCtrlId2MappedTxBuffersConfig
  \brief  CAN controller configuration - mapped Tx-buffer(s).
  \details
  Element                          Description
  MappedTxBuffersConfigEndIdx      the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
  MappedTxBuffersConfigStartIdx    the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfig[1] = {
    /* Index    MappedTxBuffersConfigEndIdx                                                            MappedTxBuffersConfigStartIdx                                                                  Referable Keys */
  { /*     0 */                         1UL  /* /ActiveEcuC/CanIf/Can/CT_DemoFBL_Fca_SLP5_01db1962 */,                           0UL  /* /ActiveEcuC/CanIf/Can/CT_DemoFBL_Fca_SLP5_01db1962 */ }   /* [/ActiveEcuC/CanIf/Can/CT_DemoFBL_Fca_SLP5_01db1962] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr = FblCw_ControllerModeIndication;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MailBoxConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MailBoxConfig
  \brief  Mailbox table.
  \details
  Element                 Description
  CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst              "First" PDU mapped to mailbox.
  PduIdLast               "Last" PDU mapped to mailbox.
  TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig
  TxBufferHandlingType
  MailBoxType             Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[2] = {
    /* Index    CtrlStatesIdx                                                            PduIdFirst                           PduIdLast                           TxBufferCfgIdx                                                                                        TxBufferHandlingType                     MailBoxType                    Referable Keys */
  { /*     0 */           0UL  /* /ActiveEcuC/CanIf/Can/CT_DemoFBL_Fca_SLP5_01db1962 */,         0U  /* Unused, TxPduId 0 */,        0U  /* Unused, TxPduId 1 */,                                    0UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_eac1789b */, CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID, CANIF_TxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/CN_DemoFBL_Fca_SLP5_01db1962_Tx] */
  { /*     1 */           0UL  /* /ActiveEcuC/CanIf/Can/CT_DemoFBL_Fca_SLP5_01db1962 */,         0U  /* RxPduId */          ,        3U  /* RxPduId  */         , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex1 */                                          , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxBasicCANMailbox }   /* [/ActiveEcuC/Can/CanConfigSet/CN_DemoFBL_Fca_SLP5_01db1962_Rx_Ext] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MappedTxBuffersConfig
  \brief  Mapped Tx-buffer(s)
  \details
  Element             Description
  MailBoxConfigIdx    the index of the 1:1 relation pointing to CanIf_MailBoxConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_MappedTxBuffersConfigType, CANIF_CONST) CanIf_MappedTxBuffersConfig[1] = {
    /* Index    MailBoxConfigIdx                                                                            Referable Keys */
  { /*     0 */              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_DemoFBL_Fca_SLP5_01db1962_Tx */ }   /* [/ActiveEcuC/CanIf/Can/CT_DemoFBL_Fca_SLP5_01db1962] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxIndicationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_RxIndicationFctList
  \brief  Rx indication functions table.
  \details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_RxIndicationFctListType, CANIF_CONST) CanIf_RxIndicationFctList[2] = {
    /* Index    RxIndicationFct                                           RxIndicationLayout                                                            Referable Keys */
  { /*     0 */  { (CanIf_SimpleRxIndicationFctType)NULL_PTR }          , CanIf_SimpleRxIndicationLayout    /* PRQA S 313 */ /* MD_CanIf_11.1 */ },  /* [NULL_PTR] */
  { /*     1 */  { (CanIf_SimpleRxIndicationFctType)CanTp_RxIndication }, CanIf_AdvancedRxIndicationLayout  /* PRQA S 313 */ /* MD_CanIf_11.1 */ }   /* [CanTp_RxIndication] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfig
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  Dlc                       Data length code.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
  MsgType                   Type of CAN message: *CAN (both 2.0 or FD), *FD_CAN (only FD), *NO_FD_CAN (only 2.0).
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[4] = {
    /* Index    RxPduCanId                                                                                RxPduMask                                                                   UpperPduId                                      Dlc  RxIndicationFctListIdx                            MsgType                         Comment                                                                                      Referable Keys */
  { /*     0 */ 0x98DBFEF2UL  /* Functional_CAN_FD_Tp_oDemoFBL_Fca_SLP5_Rx_3abd61be, only FD-PDU */     , 0xDFFFFFFFUL  /* Functional_CAN_FD_Tp_oDemoFBL_Fca_SLP5_Rx_3abd61be */    , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_271757d8    ,  8U,                    1UL  /* CanTp_RxIndication */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: Functional_CAN_FD_Tp_oDemoFBL_Fca_SLP5_Rx_3abd61be, CanId: 0x18dbfef2]     */  /* [CanIfConf_CanIfRxPduCfg_Functional_CAN_FD_Tp_oDemoFBL_Fca_SLP5_Rx_3abd61be] */
  { /*     1 */ 0x98DBFEF1UL  /* Functional_CAN_20_Tp_oDemoFBL_Fca_SLP5_Rx_3abd61be, only 2.0-PDU */    , 0x9FFFFFFFUL  /* Functional_CAN_20_Tp_oDemoFBL_Fca_SLP5_Rx_3abd61be */    , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_0f47f63e    ,  8U,                    1UL  /* CanTp_RxIndication */, CANIF_MSG_TYPE_NO_FD_CAN },  /* [PDU: Functional_CAN_20_Tp_oDemoFBL_Fca_SLP5_Rx_3abd61be, CanId: 0x18dbfef1]     */  /* [CanIfConf_CanIfRxPduCfg_Functional_CAN_20_Tp_oDemoFBL_Fca_SLP5_Rx_3abd61be] */
  { /*     2 */ 0x98DAC7F2UL  /* Demo_0_CAN_FD_Request_Tp_oDemoFBL_Fca_SLP5_Rx_3abd61be, only FD-PDU */ , 0x9FFFFFFFUL  /* Demo_0_CAN_FD_Request_Tp_oDemoFBL_Fca_SLP5_Rx_3abd61be */, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_9121fb27    ,  8U,                    1UL  /* CanTp_RxIndication */, CANIF_MSG_TYPE_FD_CAN    },  /* [PDU: Demo_0_CAN_FD_Request_Tp_oDemoFBL_Fca_SLP5_Rx_3abd61be, CanId: 0x18dac7f2] */  /* [CanIfConf_CanIfRxPduCfg_Demo_0_CAN_FD_Request_Tp_oDemoFBL_Fca_SLP5_Rx_3abd61be] */
  { /*     3 */ 0x98DAC7F1UL  /* Demo_0_CAN_20_Request_Tp_oDemoFBL_Fca_SLP5_Rx_3abd61be, only 2.0-PDU */, 0x9FFFFFFFUL  /* Demo_0_CAN_20_Request_Tp_oDemoFBL_Fca_SLP5_Rx_3abd61be */, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_595562da,  8U,                    1UL  /* CanTp_RxIndication */, CANIF_MSG_TYPE_NO_FD_CAN }   /* [PDU: Demo_0_CAN_20_Request_Tp_oDemoFBL_Fca_SLP5_Rx_3abd61be, CanId: 0x18dac7f1] */  /* [CanIfConf_CanIfRxPduCfg_Demo_0_CAN_20_Request_Tp_oDemoFBL_Fca_SLP5_Rx_3abd61be] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueConfig
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE
  \details
  Element                                             Description
  TxBufferPrioByCanIdBaseIdx                          the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase
  TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx      the end index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusLength      the number of relations pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx    the start index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueConfigType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueConfig[1] = {
    /* Index    TxBufferPrioByCanIdBaseIdx                                                                TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx                                                                TxBufferPrioByCanIdByteQueueMappedTxPdusLength                                                                TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx                                                                      Referable Keys */
  { /*     0 */                        0UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_eac1789b */,                                            2UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_eac1789b */,                                            2UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_eac1789b */,                                              0UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_eac1789b */ }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_eac1789b] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE: Mapped Tx-PDUs
  \details
  Element           Description
  TxPduConfigIdx    the index of the 1:1 relation pointing to CanIf_TxPduConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus[2] = {
    /* Index    TxPduConfigIdx                                                                                                      Referable Keys */
  { /*     0 */            0UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be */ },  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_eac1789b] */
  { /*     1 */            1UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be */ }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_eac1789b] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_TxConfirmationFctList
  \brief  Tx confirmation functions table.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxConfirmationFctType, CANIF_CONST) CanIf_TxConfirmationFctList[2] = {
  /* Index     TxConfirmationFctList                      Referable Keys */
  /*     0 */ (CanIf_TxConfirmationFctType)NULL_PTR ,  /* [NULL_PTR] */
  /*     1 */ CanTp_TxConfirmation                     /* [CanTp_TxConfirmation] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfig
  \brief  Tx-PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle ID (8bit / 16bit).
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  Dlc                         Data length code.
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfig[2] = {
    /* Index    CanId         UpperLayerTxPduId                               CtrlStatesIdx                                                            Dlc                                MailBoxConfigIdx                                                                      TxConfirmationFctListIdx                                    Comment                                                                    Referable Keys */
  { /*     0 */ 0xD8DAF2C7UL, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_9121fb27,           0UL  /* /ActiveEcuC/CanIf/Can/CT_DemoFBL_Fca_SLP5_01db1962 */, 64U  /* PduLength + Paddings,  */,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_DemoFBL_Fca_SLP5_01db1962_Tx */,                      1UL  /* CanTp_TxConfirmation */ },  /* [PDU: Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  { /*     1 */ 0x98DAF1C7UL, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_595562da    ,           0UL  /* /ActiveEcuC/CanIf/Can/CT_DemoFBL_Fca_SLP5_01db1962 */,  8U  /* PduLength + Paddings,  */,              0UL  /* /ActiveEcuC/Can/CanConfigSet/CN_DemoFBL_Fca_SLP5_01db1962_Tx */,                      1UL  /* CanTp_TxConfirmation */ }   /* [PDU: Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduQueueIndex
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduQueueIndex
  \brief  Indirection table: Tx-PDU handle ID to corresponding Tx buffer handle ID. NOTE: Only BasicCAN Tx-PDUs have a valid indirection into the Tx buffer.
  \details
  Element                          Description
  TxQueueIdx                       the index of the 0:1 relation pointing to CanIf_TxQueue
  TxQueueIndex2DataStartStopIdx    the index of the 0:1 relation pointing to CanIf_TxQueueIndex2DataStartStop
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxPduQueueIndexType, CANIF_CONST) CanIf_TxPduQueueIndex[2] = {
    /* Index    TxQueueIdx                                                                                                TxQueueIndex2DataStartStopIdx                                                                                                      Comment                                                                                              Referable Keys */
  { /*     0 */        0UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be */,                           0UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be */ },  /* [Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be, BasicCAN TxPdu with Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be, /ActiveEcuC/CanIf/Can/CT_DemoFBL_Fca_SLP5_01db1962] */
  { /*     1 */        1UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be */,                           1UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be */ }   /* [Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be, BasicCAN TxPdu with Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be, /ActiveEcuC/CanIf/Can/CT_DemoFBL_Fca_SLP5_01db1962] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueueIndex2DataStartStop
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueueIndex2DataStartStop
  \details
  Element                Description
  TxQueueDataEndIdx      the end index of the 0:n relation pointing to CanIf_TxQueueData
  TxQueueDataLength      the number of relations pointing to CanIf_TxQueueData
  TxQueueDataStartIdx    the start index of the 0:n relation pointing to CanIf_TxQueueData
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxQueueIndex2DataStartStopType, CANIF_CONST) CanIf_TxQueueIndex2DataStartStop[2] = {
    /* Index    TxQueueDataEndIdx                                                                                                TxQueueDataLength                                                                                                TxQueueDataStartIdx                                                                                                      Comment                                                                       Referable Keys */
  { /*     0 */              64UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be */,              64UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be */,                 0UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be */ },  /* [Tx-PDU: Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  { /*     1 */              72UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be */,               8UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be */,                64UL  /* /ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be */ }   /* [Tx-PDU: Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlStates
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlStates
  \details
  Element     Description
  CtrlMode    Controller mode.
  PduMode     PDU mode state.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/CanIf/Can/CT_DemoFBL_Fca_SLP5_01db1962] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdBase
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdBase
  \brief  Variable declaration - Tx-buffer: PRIO_BY_CANID as byte/bit-queue. Stores at least the QueueCounter.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanIf_TxBufferPrioByCanIdBaseUType, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBase;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CanIfBufferCfg_eac1789b] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueue
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueue
  \brief  Variable declaration - Tx byte queue.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanIf_TxQueueUType, CANIF_VAR_NOINIT) CanIf_TxQueue;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*     1 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueueData
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueueData
  \brief  Variable declaration - Tx queue data.
*/ 
#define CANIF_START_SEC_VAR_FAST_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanIf_TxQueueDataUType, CANIF_VAR_NOINIT_FAST) CanIf_TxQueueData;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*     1 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*     2 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*     3 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*     4 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*     5 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*     6 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*     7 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*     8 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*     9 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    10 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    11 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    12 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    13 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    14 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    15 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    16 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    17 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    18 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    19 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    20 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    21 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    22 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    23 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    24 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    25 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    26 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    27 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    28 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    29 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    30 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    31 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    32 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    33 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    34 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    35 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    36 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    37 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    38 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    39 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    40 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    41 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    42 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    43 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    44 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    45 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    46 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    47 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    48 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    49 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /* Index        Referable Keys  */
  /*    50 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    51 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    52 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    53 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    54 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    55 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    56 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    57 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    58 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    59 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    60 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    61 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    62 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    63 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    64 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    65 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    66 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    67 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    68 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    69 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    70 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */
  /*    71 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be] */

#define CANIF_STOP_SEC_VAR_FAST_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



