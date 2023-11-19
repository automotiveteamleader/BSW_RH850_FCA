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
 *            Module: FblCw
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701374A
 *    License Scope : The usage is restricted to CBD1800284_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: FblCw_Lcfg.c
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


#define FBLCW_LCFG_SOURCE
/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0779 EOF */ /* MD_CSL_0779 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#include "fbl_inc.h"
#include "FblCw_Lcfg.h"
#include "PduR_Dcm.h"

#include "Can.h"
#include "CanIf.h"
#include "CanTp.h"
#include "Det.h"
#include "NvM.h"
#include "PduR.h"


/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  FblCw_CanIfCtrlInfo
**********************************************************************************************************************/
/** 
  \var    FblCw_CanIfCtrlInfo
  \brief  DefinitionRef: /[ANY]/CanIf/CanIfCtrlDrvCfg/CanIfCtrlCfg
*/ 
#define FBLCW_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(FblCw_CanIfCtrlInfoType, FBLCW_CONST) FblCw_CanIfCtrlInfo[1] = {
  /* Index     CanIfCtrlInfo                                            Referable Keys */
  /*     0 */  CanIfConf_CanIfCtrlCfg_CT_DemoFBL_Fca_SLP5_01db1962   /* [/ActiveEcuC/CanIf/Can/CT_DemoFBL_Fca_SLP5_01db1962] */
};
#define FBLCW_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslConnectionInfo
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslConnectionInfo
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection
  \details
  Element          Description
  PayloadLimit     DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslPayloadLimit
  Controller       controller handle
  TxRemotePduId    DefinitionRef: /[ANY]/PduR/PduRRoutingTables/PduRRoutingTable/PduRRoutingPath/PduRSrcPdu based symbolic name value
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(FblCw_DcmDslConnectionInfoType, FBLCW_CONST) FblCw_DcmDslConnectionInfo[2] = {
    /* Index    PayloadLimit  Controller                                           TxRemotePduId                                                         Referable Keys */
  { /*     0 */ 0x00000FFFUL, CanIfConf_CanIfCtrlCfg_CT_DemoFBL_Fca_SLP5_01db1962, PduRConf_PduRSrcPdu_SRC_Can_PT_Demo_0_CAN_FD_Response_eac1789b },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/TN_Tester_FD_TN_Demo_0_CAN29_FD_Ch0_DemoFBL_Fca_SLP5_CAN] */
  { /*     1 */ 0x00000FFFUL, CanIfConf_CanIfCtrlCfg_CT_DemoFBL_Fca_SLP5_01db1962, PduRConf_PduRSrcPdu_SRC_Can_PT_Demo_0_CAN_20_Response_eac1789b }   /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/TN_Tester_TN_Demo_0_CAN29_Ch0_DemoFBL_Fca_SLP5_CAN] */
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_DcmDslProtocolRxInfo
**********************************************************************************************************************/
/** 
  \var    FblCw_DcmDslProtocolRxInfo
  \brief  DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRx
  \details
  Element                    Description
  AddrType                   DefinitionRef: /MICROSARFBL/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/DcmDslConnection/DcmDslMainConnection/DcmDslProtocolRx/DcmDslProtocolRxAddrType
  DcmDslConnectionInfoIdx    the index of the 1:1 relation pointing to FblCw_DcmDslConnectionInfo
*/ 
#define FBLCW_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(FblCw_DcmDslProtocolRxInfoType, FBLCW_CONST) FblCw_DcmDslProtocolRxInfo[4] = {
    /* Index    AddrType                                         DcmDslConnectionInfoIdx        Referable Keys */
  { /*     0 */   FBLCW_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      0U },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/TN_Tester_FD_TN_Demo_0_CAN29_FD_Ch0_DemoFBL_Fca_SLP5_CAN/DcmDslMainConnection/PT_Demo_0_CAN_FD_Request_PP_Demo_0_CAN_FD_Request_Rx_eac1789b_411010d2] */
  { /*     1 */ FBLCW_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      0U },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/TN_Tester_FD_TN_Demo_0_CAN29_FD_Ch0_DemoFBL_Fca_SLP5_CAN/DcmDslMainConnection/PT_Functional_CAN_FD_PP_Functional_CAN_FD_Rx_eac1789b_411010d2] */
  { /*     2 */   FBLCW_PHYSICAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      1U },  /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/TN_Tester_TN_Demo_0_CAN29_Ch0_DemoFBL_Fca_SLP5_CAN/DcmDslMainConnection/PT_Demo_0_CAN_20_Request_PP_Demo_0_CAN_20_Request_Rx_eac1789b_411010d2] */
  { /*     3 */ FBLCW_FUNCTIONAL_ADDRTYPEOFDCMDSLPROTOCOLRXINFO,                      1U }   /* [/ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslProtocol/DcmDslProtocolRow/TN_Tester_TN_Demo_0_CAN29_Ch0_DemoFBL_Fca_SLP5_CAN/DcmDslMainConnection/PT_Functional_CAN_20_PP_Functional_CAN_20_Rx_eac1789b_411010d2] */
};
#define FBLCW_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  FblCw_Initialized
**********************************************************************************************************************/
/** 
  \var    FblCw_Initialized
  \brief  Initialization state of the Dcm. TRUE, if Dcm_Init() has been called, else FALSE.
*/ 
#define FBLCW_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(FblCw_InitializedType, FBLCW_VAR_ZERO_INIT) FblCw_Initialized = FALSE;
#define FBLCW_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
#define FBL_CW_FULL_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_19.1 */

/**********************************************************************************************************************
  FblCw_EcuMInit
**********************************************************************************************************************/
/*! \internal
 *- #10 Initialize the Memory of all BSW modules.
 *- #20 Initialize all BSW modules.
    \endinternal
**********************************************************************************************************************/
FUNC(void, FBLCW_CODE) FblCw_EcuMInit(void)
{
  CanIf_InitMemory();
  CanTp_InitMemory();
  Can_InitMemory();
  Det_InitMemory();
  PduR_InitMemory();



#if(FBLCW_USE_INIT_POINTER == STD_ON)
  if(FblCw_ConfigDataPtr == FblCw_Config_Ptr)
#endif
  {
    /* INIT_ZERO */
    Det_Init(Det_Config_Ptr);

    /* INIT_ONE_EARLY */

    /* INIT_ONE */

    /* INIT_ONE_LATE */

    /* INIT_TWO_COM */
    PduR_Init(PduR_Config_Ptr);

    /* INIT_TWO_DRV */
    Can_Init(Can_Config_Ptr);

    /* INIT_TWO_IF */
    CanIf_Init(CanIf_Config_Ptr);

    /* INIT_TWO_MCAL */

    /* INIT_TWO_NM */

    /* INIT_TWO_POST_NVMREADALL */

    /* INIT_TWO_SM */

    /* INIT_TWO_SYS */
    NvM_Init();

    /* INIT_TWO_TP */
    CanTp_Init(CanTp_Config_Ptr);

    /* INIT_TWO_TRCV */

    /* INIT_THREE */

  }
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

#define FBL_CW_FULL_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */   /* MD_MSR_19.1 */
/**********************************************************************************************************************
  END OF FILE: FblCw_Lcfg.c
**********************************************************************************************************************/

