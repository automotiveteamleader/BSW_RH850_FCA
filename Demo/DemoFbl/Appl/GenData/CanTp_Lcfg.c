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
 *            Module: CanTp
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701374A
 *    License Scope : The usage is restricted to CBD1800284_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanTp_Lcfg.c
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

#define CANTP_LCFG_SOURCE

/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* -----------------------------------------------------------------------------
    &&&~ Include files
 ----------------------------------------------------------------------------- */

#include "CanTp_Lcfg.h"
#include "CanIf.h"
#include "PduR_CanTp.h"
/* -----------------------------------------------------------------------------
    &&&~ Data definitions
 ----------------------------------------------------------------------------- */



/**********************************************************************************************************************
 *  LOCAL DATA
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
 *  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanTp_RxPduMap
**********************************************************************************************************************/
/** 
  \var    CanTp_RxPduMap
  \details
  Element                Description
  RxSduCfgIndEndIdx      the end index of the 0:n relation pointing to CanTp_RxSduCfgInd
  RxSduCfgIndStartIdx    the start index of the 0:n relation pointing to CanTp_RxSduCfgInd
  TxSduCfgIndEndIdx      the end index of the 0:n relation pointing to CanTp_TxSduCfgInd
  TxSduCfgIndStartIdx    the start index of the 0:n relation pointing to CanTp_TxSduCfgInd
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanTp_RxPduMapType, CANTP_CONST) CanTp_RxPduMap[4] = {
    /* Index    RxSduCfgIndEndIdx  RxSduCfgIndStartIdx  TxSduCfgIndEndIdx                     TxSduCfgIndStartIdx                    */
  { /*     0 */                1U,                  0U,                                   1U,                                     0U },
  { /*     1 */                2U,                  1U,                                   2U,                                     1U },
  { /*     2 */                3U,                  2U, CANTP_NO_TXSDUCFGINDENDIDXOFRXPDUMAP, CANTP_NO_TXSDUCFGINDSTARTIDXOFRXPDUMAP },
  { /*     3 */                4U,                  3U, CANTP_NO_TXSDUCFGINDENDIDXOFRXPDUMAP, CANTP_NO_TXSDUCFGINDSTARTIDXOFRXPDUMAP }
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfg
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfg
  \details
  Element                     Description
  CanIfTxFcPduId          
  PduRRxSduId             
  RxPduId                 
  TxFcPduConfirmationPduId
  BlockSize               
  CanType                 
  NAr                     
  NCr                     
  RxMaxPayloadLength      
  RxTaType                
  TxSduCfgIdx                 the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanTp_RxSduCfgType, CANTP_CONST) CanTp_RxSduCfg[4] = {
    /* Index    CanIfTxFcPduId                                                                   PduRRxSduId                                                    RxPduId                                     TxFcPduConfirmationPduId                        BlockSize  CanType                        NAr  NCr   RxMaxPayloadLength  RxTaType                             TxSduCfgIdx                           Comment                       Referable Keys */
  { /*     0 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_SRC_Can_PT_Functional_CAN_FD_eac1789b    , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_271757d8, CANTP_INVALID_HDL                             ,        8U, CANTP_CANFD_CANTYPEOFRXSDUCFG, 11U,  11U,                63U, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [RxNSdu_0c51c5f0] */  /* [RxNSdu_0c51c5f0, 3] */
  { /*     1 */ CANTP_INVALID_HDL                                                              , PduRConf_PduRSrcPdu_SRC_Can_PT_Functional_CAN_20_eac1789b    , CanTpConf_CanTpRxNPdu_CanTpRxNPdu_0f47f63e, CANTP_INVALID_HDL                             ,        8U, CANTP_CAN20_CANTYPEOFRXSDUCFG, 11U,  11U,                 7U, CANTP_FUNCTIONAL_RXTATYPEOFRXSDUCFG, CANTP_NO_TXSDUCFGIDXOFRXSDUCFG },  /* [RxNSdu_195dc61f] */  /* [RxNSdu_195dc61f, 2] */
  { /*     2 */ CanIfConf_CanIfTxPduCfg_Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be, PduRConf_PduRSrcPdu_SRC_Can_PT_Demo_0_CAN_20_Request_eac1789b, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_17d55594, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_17d55594,        0U, CANTP_CAN20_CANTYPEOFRXSDUCFG, 21U, 101U,                 7U,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,                             0U },  /* [RxNSdu_702373df] */  /* [RxNSdu_702373df, 0] */
  { /*     3 */ CanIfConf_CanIfTxPduCfg_Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be, PduRConf_PduRSrcPdu_SRC_Can_PT_Demo_0_CAN_FD_Request_eac1789b, CanTpConf_CanTpRxNPdu_CanTpRxNPdu_9121fb27, CanTpConf_CanTpTxFcNPdu_CanTpTxFcNPdu_9121fb27,        0U, CANTP_CANFD_CANTYPEOFRXSDUCFG, 21U, 101U,                63U,   CANTP_PHYSICAL_RXTATYPEOFRXSDUCFG,                             1U }   /* [RxNSdu_d566c89d] */  /* [RxNSdu_d566c89d, 1] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduCfgInd
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduCfgInd
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanTp_RxSduCfgIndType, CANTP_CONST) CanTp_RxSduCfgInd[4] = {
  /* Index    RxSduCfgInd      Referable Keys */
  /*     0 */          2U,  /* [0] */
  /*     1 */          3U,  /* [1] */
  /*     2 */          1U,  /* [2] */
  /*     3 */          0U   /* [3] */
};
#define CANTP_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxSduSnv2Hdl
**********************************************************************************************************************/
/** 
  \var    CanTp_RxSduSnv2Hdl
  \details
  Element        Description
  RxSduCfgIdx    the index of the 0:1 relation pointing to CanTp_RxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanTp_RxSduSnv2HdlType, CANTP_CONST) CanTp_RxSduSnv2Hdl[4] = {
    /* Index    RxSduCfgIdx        Comment */
  { /*     0 */          0U },  /* [RxNSdu_0c51c5f0] */
  { /*     1 */          1U },  /* [RxNSdu_195dc61f] */
  { /*     2 */          2U },  /* [RxNSdu_702373df] */
  { /*     3 */          3U }   /* [RxNSdu_d566c89d] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfg
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfg
  \details
  Element                   Description
  CanIfTxPduId          
  PduRTxSduId           
  RxFcPduId             
  TxPduConfirmationPduId
  CanType               
  RxSduCfgIdx               the index of the 0:1 relation pointing to CanTp_RxSduCfg
  TxMaxPayloadLength    
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanTp_TxSduCfgType, CANTP_CONST) CanTp_TxSduCfg[2] = {
    /* Index    CanIfTxPduId                                                                     PduRTxSduId                                                      RxFcPduId                                       TxPduConfirmationPduId                      CanType                        RxSduCfgIdx  TxMaxPayloadLength        Comment                       Referable Keys */
  { /*     0 */ CanIfConf_CanIfTxPduCfg_Demo_0_CAN_20_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be, PduRConf_PduRDestPdu_DST_Can_PT_Demo_0_CAN_20_Response_eac1789b, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_595562da, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_595562da, CANTP_CAN20_CANTYPEOFTXSDUCFG,          2U,                 7U },  /* [TxNSdu_92a41219] */  /* [TxNSdu_92a41219, 0] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_Demo_0_CAN_FD_Response_Tp_oDemoFBL_Fca_SLP5_Tx_3abd61be, PduRConf_PduRDestPdu_DST_Can_PT_Demo_0_CAN_FD_Response_eac1789b, CanTpConf_CanTpRxFcNPdu_CanTpRxFcNPdu_d3c985a1, CanTpConf_CanTpTxNPdu_CanTpTxNPdu_d3c985a1, CANTP_CANFD_CANTYPEOFTXSDUCFG,          3U,                63U }   /* [TxNSdu_662a6d46] */  /* [TxNSdu_662a6d46, 1] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduCfgInd
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduCfgInd
  \brief  the indexes of the 1:1 sorted relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanTp_TxSduCfgIndType, CANTP_CONST) CanTp_TxSduCfgInd[2] = {
  /* Index    TxSduCfgInd      Referable Keys */
  /*     0 */          0U,  /* [0] */
  /*     1 */          1U   /* [1] */
};
#define CANTP_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSduSnv2Hdl
**********************************************************************************************************************/
/** 
  \var    CanTp_TxSduSnv2Hdl
  \details
  Element        Description
  TxSduCfgIdx    the index of the 0:1 relation pointing to CanTp_TxSduCfg
*/ 
#define CANTP_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanTp_TxSduSnv2HdlType, CANTP_CONST) CanTp_TxSduSnv2Hdl[2] = {
    /* Index    TxSduCfgIdx        Comment */
  { /*     0 */          0U },  /* [TxNSdu_92a41219] */
  { /*     1 */          1U }   /* [TxNSdu_662a6d46] */
};
#define CANTP_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_CalcBS
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanTp_CalcBSType, CANTP_VAR_NOINIT) CanTp_CalcBS[4];
#define CANTP_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_RxState
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanTp_RxStateType, CANTP_VAR_NOINIT) CanTp_RxState[4];
#define CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxSemaphores
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanTp_TxSemaphoreType, CANTP_VAR_NOINIT) CanTp_TxSemaphores[2];
#define CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanTp_TxState
**********************************************************************************************************************/
#define CANTP_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanTp_TxStateType, CANTP_VAR_NOINIT) CanTp_TxState[2];
#define CANTP_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
 * FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/




