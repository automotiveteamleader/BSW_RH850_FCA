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
 *            Module: PduR
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701374A
 *    License Scope : The usage is restricted to CBD1800284_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Lcfg.c
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

#define PDUR_LCFG_SOURCE

/**********************************************************************************************************************
 * MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */
/* PRQA S 0612 EOF */ /* MD_MSR_1.1 */


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"

#if(PDUR_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/* Include headers with callbacks */
#include "PduR_CanTp.h"
#include "PduR_Dcm.h"


/**********************************************************************************************************************
 * LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA
 *********************************************************************************************************************/
/* \trace SPEC-663, SPEC-661 */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  PduR_IfRoutingStateTable
**********************************************************************************************************************/
/** 
  \var    PduR_IfRoutingStateTable
  \brief  Contains state transition for Communication Interface routings
  \details
  Element                                   Description
  NextState_For_Init_If_Routing_State   
  NextState_For_Wait_For_RxIndication   
  NextState_For_Wait_For_TriggerTransmit
  NextState_For_Wait_For_TxConfirmation 
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_IfRoutingStateTableType, PDUR_CONST) PduR_IfRoutingStateTable[4] = {
    /* Index    NextState_For_Init_If_Routing_State                                                     NextState_For_Wait_For_RxIndication                                                     NextState_For_Wait_For_TriggerTransmit                                                     NextState_For_Wait_For_TxConfirmation                                                    */
  { /*     0 */    PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE,    PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE,                                                                                       0UL,                                                                                      0UL },
  { /*     1 */ PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE, PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE, PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE,                                                                                      0UL },
  { /*     2 */    PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE, PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE,  PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE, PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE },
  { /*     3 */    PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE,  PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE,                                                                                       0UL,  PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_MmRom
**********************************************************************************************************************/
/** 
  \var    PduR_MmRom
  \brief  Module manager: Contains all function pointers of the bordering modules.
  \details
  Element                       Description
  MaskedBits                    contains bitcoded the boolean data of PduR_LoTpOfMmRom, PduR_UpTpOfMmRom
  UpTpCopyRxDataFctPtr          Transport protocol CopyRxData function pointers
  UpTpCopyTxDataFctPtr          Transport protocol CopyTxData function pointers
  UpTpStartOfReceptionFctPtr    Transport protocol StartOfReception function pointers
  UpTpTpRxIndicationFctPtr      Transport protocol TpRxIndication function pointers
  UpTpTpTxConfirmationFctPtr    Transport protocol TpTxConfimation function pointers
  LoTpTransmitFctPtr            Lower layer Tp transmit function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_MmRomType, PDUR_CONST) PduR_MmRom[2] = {
    /* Index    MaskedBits  UpTpCopyRxDataFctPtr  UpTpCopyTxDataFctPtr  UpTpStartOfReceptionFctPtr  UpTpTpRxIndicationFctPtr  UpTpTpTxConfirmationFctPtr  LoTpTransmitFctPtr        Referable Keys */
  { /*     0 */      0x02U, NULL_PTR            , NULL_PTR            , NULL_PTR                  , NULL_PTR                , NULL_PTR                  , CanTp_Transmit     },  /* [/ActiveEcuC/PduR/CanTp] */
  { /*     1 */      0x01U, Dcm_CopyRxData      , Dcm_CopyTxData      , Dcm_StartOfReception      , Dcm_TpRxIndication      , Dcm_TpTxConfirmation      , NULL_PTR           }   /* [/ActiveEcuC/PduR/Dcm] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmDestRom
**********************************************************************************************************************/
/** 
  \var    PduR_RmDestRom
  \brief  PduR RoutiongPathManager destPdu Table
  \details
  Element        Description
  RoutingType    Type of the Routing (API Forwarding, Gateway).
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_RmDestRomType, PDUR_CONST) PduR_RmDestRom[6] = {
    /* Index    RoutingType                                                 Comment                                                               Referable Keys */
  { /*     0 */ PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: DST_Can_PT_Demo_0_CAN_20_Request_eac1789b]  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Demo_0_CAN_20_Request_eac1789b/SRC_Can_PT_Demo_0_CAN_20_Request_eac1789b, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Demo_0_CAN_20_Request_eac1789b/DST_Can_PT_Demo_0_CAN_20_Request_eac1789b] */
  { /*     1 */ PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: DST_Can_PT_Demo_0_CAN_20_Response_eac1789b] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Demo_0_CAN_20_Response_eac1789b/SRC_Can_PT_Demo_0_CAN_20_Response_eac1789b, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Demo_0_CAN_20_Response_eac1789b/DST_Can_PT_Demo_0_CAN_20_Response_eac1789b] */
  { /*     2 */ PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: DST_Can_PT_Demo_0_CAN_FD_Request_eac1789b]  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Demo_0_CAN_FD_Request_eac1789b/SRC_Can_PT_Demo_0_CAN_FD_Request_eac1789b, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Demo_0_CAN_FD_Request_eac1789b/DST_Can_PT_Demo_0_CAN_FD_Request_eac1789b] */
  { /*     3 */ PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: DST_Can_PT_Demo_0_CAN_FD_Response_eac1789b] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Demo_0_CAN_FD_Response_eac1789b/SRC_Can_PT_Demo_0_CAN_FD_Response_eac1789b, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Demo_0_CAN_FD_Response_eac1789b/DST_Can_PT_Demo_0_CAN_FD_Response_eac1789b] */
  { /*     4 */ PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: DST_Can_PT_Functional_CAN_20_eac1789b]      */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Functional_CAN_20_eac1789b/SRC_Can_PT_Functional_CAN_20_eac1789b, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Functional_CAN_20_eac1789b/DST_Can_PT_Functional_CAN_20_eac1789b] */
  { /*     5 */ PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM }   /* [PduRDestPdu: DST_Can_PT_Functional_CAN_FD_eac1789b]      */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Functional_CAN_FD_eac1789b/SRC_Can_PT_Functional_CAN_FD_eac1789b, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Functional_CAN_FD_eac1789b/DST_Can_PT_Functional_CAN_FD_eac1789b] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmGDestRom
**********************************************************************************************************************/
/** 
  \var    PduR_RmGDestRom
  \brief  PduR RoutiongPathManager global destPdu Table
  \details
  Element                  Description
  DestHnd                  handle to be used as parameter for the StartOfReception, CopyRxData, Transmit or RxIndication function call.
  MmRomIdx                 the index of the 1:1 relation pointing to PduR_MmRom
  PduRDestPduProcessing    Is Processing Type of destination PDU.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_RmGDestRomType, PDUR_CONST) PduR_RmGDestRom[6] = {
    /* Index    DestHnd                                                                                          MmRomIdx  PduRDestPduProcessing                                   Comment                                                                                                     Referable Keys */
  { /*     0 */ DcmConf_DcmDslProtocolRx_PT_Demo_0_CAN_20_Request_PP_Demo_0_CAN_20_Request_Rx_eac1789b_411010d2,       1U, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM },  /* [Globale PduRDestPdu: PT_Demo_0_CAN_20_Request_PP_Demo_0_CAN_20_Request_Rx_eac1789b_411010d2]   */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_Demo_0_CAN_20_Request_PP_Demo_0_CAN_20_Request_Rx_eac1789b_411010d2] */
  { /*     1 */                                                           CanTpConf_CanTpTxNSdu_TxNSdu_92a41219,       0U, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM },  /* [Globale PduRDestPdu: PT_Demo_0_CAN_20_Response_PP_Demo_0_CAN_20_Response_Tx_eac1789b_411010d2] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_Demo_0_CAN_20_Response_PP_Demo_0_CAN_20_Response_Tx_eac1789b_411010d2] */
  { /*     2 */ DcmConf_DcmDslProtocolRx_PT_Demo_0_CAN_FD_Request_PP_Demo_0_CAN_FD_Request_Rx_eac1789b_411010d2,       1U, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM },  /* [Globale PduRDestPdu: PT_Demo_0_CAN_FD_Request_PP_Demo_0_CAN_FD_Request_Rx_eac1789b_411010d2]   */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_Demo_0_CAN_FD_Request_PP_Demo_0_CAN_FD_Request_Rx_eac1789b_411010d2] */
  { /*     3 */                                                           CanTpConf_CanTpTxNSdu_TxNSdu_662a6d46,       0U, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM },  /* [Globale PduRDestPdu: PT_Demo_0_CAN_FD_Response_PP_Demo_0_CAN_FD_Response_Tx_eac1789b_411010d2] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_Demo_0_CAN_FD_Response_PP_Demo_0_CAN_FD_Response_Tx_eac1789b_411010d2] */
  { /*     4 */         DcmConf_DcmDslProtocolRx_PT_Functional_CAN_20_PP_Functional_CAN_20_Rx_eac1789b_411010d2,       1U, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM },  /* [Globale PduRDestPdu: PT_Functional_CAN_20_PP_Functional_CAN_20_Rx_eac1789b_411010d2]           */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_Functional_CAN_20_PP_Functional_CAN_20_Rx_eac1789b_411010d2] */
  { /*     5 */         DcmConf_DcmDslProtocolRx_PT_Functional_CAN_FD_PP_Functional_CAN_FD_Rx_eac1789b_411010d2,       1U, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM }   /* [Globale PduRDestPdu: PT_Functional_CAN_FD_PP_Functional_CAN_FD_Rx_eac1789b_411010d2]           */  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_Functional_CAN_FD_PP_Functional_CAN_FD_Rx_eac1789b_411010d2] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmSrcRom
**********************************************************************************************************************/
/** 
  \var    PduR_RmSrcRom
  \brief  PduR RoutiongManager SrcPdu Table
  \details
  Element            Description
  MmRomIdx           the index of the 1:1 relation pointing to PduR_MmRom
  RmDestRomLength    the number of relations pointing to PduR_RmDestRom
  SrcHnd             handle to be used as parameter for the TxConfirmation or TriggerTransmit function call.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_RmSrcRomType, PDUR_CONST) PduR_RmSrcRom[6] = {
    /* Index    MmRomIdx  RmDestRomLength  SrcHnd                                                                                                   Comment                                                              Referable Keys */
  { /*     0 */       0U,              1U,                                                                          PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: SRC_Can_PT_Demo_0_CAN_20_Request_eac1789b]  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Demo_0_CAN_20_Request_eac1789b/SRC_Can_PT_Demo_0_CAN_20_Request_eac1789b] */
  { /*     1 */       1U,              1U, DcmConf_DcmDslProtocolTx_PT_Demo_0_CAN_20_Response_PP_Demo_0_CAN_20_Response_Tx_eac1789b_411010d2 },  /* [PduRSrcPdu: SRC_Can_PT_Demo_0_CAN_20_Response_eac1789b] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Demo_0_CAN_20_Response_eac1789b/SRC_Can_PT_Demo_0_CAN_20_Response_eac1789b] */
  { /*     2 */       0U,              1U,                                                                          PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: SRC_Can_PT_Demo_0_CAN_FD_Request_eac1789b]  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Demo_0_CAN_FD_Request_eac1789b/SRC_Can_PT_Demo_0_CAN_FD_Request_eac1789b] */
  { /*     3 */       1U,              1U, DcmConf_DcmDslProtocolTx_PT_Demo_0_CAN_FD_Response_PP_Demo_0_CAN_FD_Response_Tx_eac1789b_411010d2 },  /* [PduRSrcPdu: SRC_Can_PT_Demo_0_CAN_FD_Response_eac1789b] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Demo_0_CAN_FD_Response_eac1789b/SRC_Can_PT_Demo_0_CAN_FD_Response_eac1789b] */
  { /*     4 */       0U,              1U,                                                                          PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: SRC_Can_PT_Functional_CAN_20_eac1789b]      */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Functional_CAN_20_eac1789b/SRC_Can_PT_Functional_CAN_20_eac1789b] */
  { /*     5 */       0U,              1U,                                                                          PDUR_NO_SRCHNDOFRMSRCROM }   /* [PduRSrcPdu: SRC_Can_PT_Functional_CAN_FD_eac1789b]      */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Functional_CAN_FD_eac1789b/SRC_Can_PT_Functional_CAN_FD_eac1789b] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmTransmitFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_RmTransmitFctPtr
  \brief  Internal routing manager Transmit functions.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_RmTransmitFctPtrType, PDUR_CONST) PduR_RmTransmitFctPtr[1] = {
  /* Index     RmTransmitFctPtr                  Referable Keys */
  /*     0 */ PduR_RmTp_Transmit_MultiDest    /* [PduR_RmTp_Transmit_MultiDest] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RxTp2Dest
**********************************************************************************************************************/
/** 
  \var    PduR_RxTp2Dest
  \brief  This table contains all routing information to perform the Rx handling of a Tp Routing. Used in the PduR_&lt;LLTp&gt;_StartOfReception, PduR_&lt;LLTp&gt;_CopyRxData and PduR_&lt;LLTp&gt;_RxIndication.
  \details
  Element        Description
  RmSrcRomIdx    the index of the 0:1 relation pointing to PduR_RmSrcRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_RxTp2DestType, PDUR_CONST) PduR_RxTp2Dest[4] = {
    /* Index    RmSrcRomIdx        Referable Keys */
  { /*     0 */          0U },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Demo_0_CAN_20_Request_eac1789b/SRC_Can_PT_Demo_0_CAN_20_Request_eac1789b] */
  { /*     1 */          2U },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Demo_0_CAN_FD_Request_eac1789b/SRC_Can_PT_Demo_0_CAN_FD_Request_eac1789b] */
  { /*     2 */          4U },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Functional_CAN_20_eac1789b/SRC_Can_PT_Functional_CAN_20_eac1789b] */
  { /*     3 */          5U }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Functional_CAN_FD_eac1789b/SRC_Can_PT_Functional_CAN_FD_eac1789b] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Tx2Lo
**********************************************************************************************************************/
/** 
  \var    PduR_Tx2Lo
  \brief  Contains all informations to route a Pdu from a upper layer to a lower layer module, or to cancel a transmission
  \details
  Element                Description
  RmSrcRomIdx            the index of the 0:1 relation pointing to PduR_RmSrcRom
  RmTransmitFctPtrIdx    the index of the 1:1 relation pointing to PduR_RmTransmitFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_Tx2LoType, PDUR_CONST) PduR_Tx2Lo[2] = {
    /* Index    RmSrcRomIdx  RmTransmitFctPtrIdx        Referable Keys */
  { /*     0 */          1U,                  0U },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Demo_0_CAN_20_Response_eac1789b/SRC_Can_PT_Demo_0_CAN_20_Response_eac1789b] */
  { /*     1 */          3U,                  0U }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/Can_PT_Demo_0_CAN_FD_Response_eac1789b/SRC_Can_PT_Demo_0_CAN_FD_Response_eac1789b] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TxTp2Src
**********************************************************************************************************************/
/** 
  \var    PduR_TxTp2Src
  \brief  This table contains all routing information to perform the Tx handling of a transport protocol routing, Used in the &lt;LoTp&gt;_CopyTxData and &lt;LoTp&gt;_TxConfirmation
  \details
  Element          Description
  RmGDestRomIdx    the index of the 1:1 relation pointing to PduR_RmGDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(PduR_TxTp2SrcType, PDUR_CONST) PduR_TxTp2Src[2] = {
    /* Index    RmGDestRomIdx        Referable Keys */
  { /*     0 */            1U },  /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_Demo_0_CAN_20_Response_PP_Demo_0_CAN_20_Response_Tx_eac1789b_411010d2] */
  { /*     1 */            3U }   /* [/ActiveEcuC/EcuC/EcucPduCollection/PT_Demo_0_CAN_FD_Response_PP_Demo_0_CAN_FD_Response_Tx_eac1789b_411010d2] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Initialized
**********************************************************************************************************************/
/** 
  \var    PduR_Initialized
  \brief  Initialization state of PduR. TRUE, if PduR_Init() has been called, else FALSE
*/ 
#define PDUR_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(PduR_InitializedType, PDUR_VAR_ZERO_INIT) PduR_Initialized = FALSE;
#define PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


#define PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_19.1 */

#if(PDUR_USE_INIT_POINTER == STD_ON)
P2CONST(PduR_PBConfigType, PDUR_VAR_ZERO_INIT, PDUR_PBCFG) PduR_ConfigDataPtr = (const PduR_PBConfigType *) NULL_PTR;
#endif

#define PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
#define PDUR_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* Upper Layer Interface APIs */

/**********************************************************************************************************************
 * PduR_DcmTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call upper layer Transmit function. 
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_DcmTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info)
{
  Std_ReturnType retVal = E_NOT_OK;
  
#if (PDUR_TX2LO == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_UpTransmit(id, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_TX, PDUR_E_INVALID_REQUEST);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return retVal;
}


/* Communication Interface APIs */


/* Transport Protocol APIs */

/**********************************************************************************************************************
 * PduR_CanTpStartOfReception
 *********************************************************************************************************************/
 /*!
 * \internal
 * - call transport protocoll StartOfReception function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpStartOfReception(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, PduLengthType TpSduLength, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr) /* COV_PDUR_WRAPPER_FUNC */
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;

#if (PDUR_RXTP2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_LoTpStartOfReception(id, info, TpSduLength, bufferSizePtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_SOR, PDUR_E_INVALID_REQUEST);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(TpSduLength);    /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */

  return retVal;
}


/**********************************************************************************************************************
 * PduR_CanTpCopyRxData
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general CopyRxData.
 * \endinternal
 *********************************************************************************************************************/
/* PRQA S 3673 1 */ /* MD_PduR_3673_AsrProto */
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyRxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr) /* COV_PDUR_WRAPPER_FUNC */
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;
  
#if (PDUR_RXTP2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_LoTpCopyRxData(id, info, bufferSizePtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_CPYRX, PDUR_E_INVALID_REQUEST);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(bufferSizePtr);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  
  return retVal;
}


/**********************************************************************************************************************
 * PduR_CanTpCopyTxData
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general CopyTxData.
 * \endinternal
 *********************************************************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CanTpCopyTxData(PduIdType id, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info, P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr) /* COV_PDUR_WRAPPER_FUNC */
{
  BufReq_ReturnType retVal = BUFREQ_E_NOT_OK;
  
#if(PDUR_TXTP2SRC == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_LoTpCopyTxData(id, info, retry, availableDataPtr); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_CPYTX, PDUR_E_INVALID_REQUEST);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(retry);  /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(availableDataPtr);       /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  
  return retVal;
}


/**********************************************************************************************************************
 * PduR_CanTpRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * - call Tp RxIndication function.
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanTpRxIndication(PduIdType id, Std_ReturnType result) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_RXTP2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoTpRxIndication(id, result);
#else
  PduR_Det_ReportError(PDUR_FCT_TPRXIND, PDUR_E_INVALID_REQUEST);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
}


/**********************************************************************************************************************
 * PduR_CanTpTxConfirmation
 *********************************************************************************************************************/
/*!
 * \internal
 * - call Tp TxConfirmation function 
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanTpTxConfirmation(PduIdType id, Std_ReturnType result) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_TXTP2SRC == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoTpTxConfirmation(id, result);
#else
  PduR_Det_ReportError(PDUR_FCT_TPTXCFM, PDUR_E_INVALID_REQUEST);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(result); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /* lint -e{438} */
}


/* CancelReceive global without UseTag API */

/* ChangeParameter global without UseTag  API */

/* Communication Interface / Transport Protocol APIs */

/* Communication Interface / Transport Protocol APIs */

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/


#define PDUR_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR
    \DESCRIPTION    The API is called with an Id and a pointer.
                    The API call is forwarded using a function pointer which is read using ComStackLib macros.
                    
    \COUNTERMEASURE \N The function pointer is read using the passed Id (and ComStackLib macros). 
                       The Id is a SNV provided by the lower layer. 
                       It is checked at runtime if it is in the valid range.
                       The pointer is provided by the lower layer and is assumed to be valid. It is passed as is to the corresponding function. 

  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_ONLY
    \DESCRIPTION    The API is called with an Id.
                    The API call is forwarded using a function pointer which is read using ComStackLib macros.
                    
    \COUNTERMEASURE \R The function pointer is read using the passed Id (and ComStackLib macros). 
                       The Id is a SNV provided by the lower layer. 
                       It is checked at runtime if it is in the valid range.
                       
  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY
    \DESCRIPTION    The API call is forwarded to an internal function.
    \COUNTERMEASURE \N The parameter are checked in the called function.

 SBSW_JUSTIFICATION_END */
 
 /* COV_JUSTIFICATION_BEGIN
 
  \ID COV_PDUR_WRAPPER_FUNC
    \ACCEPT X
    \REASON Each neighbouring module call the same internal function. The call is covered by an other module. 
    
  \ID COV_PDUR_RX_OR_TX_ONLY_CONFIG
    \ACCEPT TX
    \REASON The API is mandatory if this Bsw module exists. In case of Rx or Tx only configs the API call is not forwarded to the internal function. 
 
 COV_JUSTIFICATION_END */
 

/**********************************************************************************************************************
 * END OF FILE: PduR_Lcfg.c
 *********************************************************************************************************************/

