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
 *              File: FblCw_Cfg.h
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


#if !defined (FBLCW_CFG_H)
# define FBLCW_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0779 EOF */ /* MD_CSL_0779 */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
# include "ComStack_Types.h"

/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#ifndef DCM_USE_DUMMY_FUNCTIONS
#define DCM_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef DCM_USE_DUMMY_STATEMENT
#define DCM_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef DCM_DUMMY_STATEMENT
#define DCM_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef DCM_DUMMY_STATEMENT_CONST
#define DCM_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef DCM_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define DCM_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef DCM_ATOMIC_VARIABLE_ACCESS
#define DCM_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef DCM_PROCESSOR_RH850_1374
#define DCM_PROCESSOR_RH850_1374
#endif
#ifndef DCM_COMP_GREENHILLS
#define DCM_COMP_GREENHILLS
#endif
#ifndef DCM_GEN_GENERATOR_MSR
#define DCM_GEN_GENERATOR_MSR
#endif
#ifndef DCM_CPUTYPE_BITORDER_LSB2MSB
#define DCM_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef DCM_CONFIGURATION_VARIANT_PRECOMPILE
#define DCM_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef DCM_CONFIGURATION_VARIANT_LINKTIME
#define DCM_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef DCM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define DCM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef DCM_CONFIGURATION_VARIANT
#define DCM_CONFIGURATION_VARIANT DCM_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef DCM_POSTBUILD_VARIANT_SUPPORT
#define DCM_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define FBLCW_DUMMY_STATEMENT(v)         DCM_DUMMY_STATEMENT(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#define FBLCW_DEV_ERROR_DETECT           STD_OFF  /**< /ActiveEcuC/Dcm/DcmConfigSet/DcmGeneral[0:DcmDevErrorDetect] */
#define FBLCW_DEV_ERROR_REPORT           STD_OFF  /**< /ActiveEcuC/Dcm/DcmConfigSet/DcmGeneral[0:DcmDevErrorDetect] */

#define FBLCW_MODULE_NM                  STD_OFF  /**< DefinitionRef: /[ANY]/Nm */
#define FBLCW_MODULE_CANNM               STD_OFF  /**< DefinitionRef: /[ANY]/CanNm */
#define FBLCW_MODULE_FRNM                STD_OFF  /**< DefinitionRef: /[ANY]/FrNm */

#define FBLCW_MODULE_XCP                 STD_OFF  /**< DefinitionRef: /[ANY]/Xcp */
#define FBLCW_MODULE_CANXCP              STD_OFF  /**< DefinitionRef: /MICROSAR/CanXcp */
#define FBLCW_MODULE_TCPIPXCP            STD_OFF  /**< DefinitionRef: /MICROSAR/TcpIpXcp */

#define FBLCW_MODULE_COMM                STD_OFF  /**< DefinitionRef: /[ANY]/ComM */
#define FBLCW_MODULE_CANSM               STD_OFF  /**< DefinitionRef: /[ANY]/CanSM */
#define FBLCW_MODULE_FRSM                STD_OFF  /**< DefinitionRef: /[ANY]/FrSM */
#define FBLCW_MODULE_ETHSM               STD_OFF  /**< DefinitionRef: /MICROSAR/EthSM */

#define FBLCW_MODULE_ETHSWT              STD_OFF  /**< DefinitionRef: /[ANY]/EthSwt */
#define FBLCW_MODULE_ETHTRCV             STD_OFF  /**< DefinitionRef: /[ANY]/EthTrcv */


#define FBLCW_QUEUED_REQUEST             STD_OFF  /**< /ActiveEcuC/Dcm/DcmConfigSet/DcmGeneral[0:DcmQueuedRequest] */
#define FBLCW_KEY_SLOT_MODE              STD_OFF  /**< /ActiveEcuC/Dcm/DcmConfigSet/DcmGeneral[0:DcmKeySlotMode] */
#define FBLCW_BAUDRATE_SWITCH            STD_OFF  /**< /ActiveEcuC/Dcm/DcmConfigSet/DcmGeneral[0:DcmBaudrateSwitch] */
#define FBLCW_NW_STATUS_RX_BUFFER_SIZE   0UL  /**< /ActiveEcuC/Dcm/DcmConfigSet/DcmGeneral[0:DcmNwStatusRxBufferSize] */
#define FBLCW_TASK_CYCLE                 5U  /**< /ActiveEcuC/Dcm/DcmConfigSet/DcmGeneral[0:DcmTaskCycle] */
#define FBLCW_CAN_HARDWARE_LOOP_TIMEOUT  100U  /**< /ActiveEcuC/Dcm/DcmConfigSet/DcmGeneral[0:DcmCanHardwareLoopTimeout] */
#define FBLCW_DECLINED_REQUESTS          STD_OFF  /**< /ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslDiagResp[0:DcmDslDiagRespOnSecondDeclinedRequest] */
#define kFblCwMaxNumDeclinedRequests     3U /**< /ActiveEcuC/Dcm/DcmConfigSet/DcmDsl/DcmDslDiagResp[0:DcmDslDiagRespMaxNumOfDeclinedRequests] */

#if(FBLCW_MODULE_ETHSWT == STD_ON)
# define FBLCW_ETHSWT_MAINFUNCTION()      _MainFunction()
#endif
#if(FBLCW_MODULE_ETHTRCV == STD_ON)
# define FBLCW_ETHTRCV_MAINFUNCTION()     _MainFunction()
#endif

#define FBLCW_CHANGE_PARAMETER           STD_OFF  /**< /ActiveEcuC/PduR/Dcm[0:PduRChangeParameterRequestApi] */

/** PDU handle to the key slot mode PDU (first slot) */
/* Customer TODO: At this point the handle ID of the FrIfLPdu of the first slot shall be configured */
# define FBLCW_NW_STATUS_PDU           (FrIfConf_FrIfLPdu_LPdu_FrTrKeySlot1Frame_S_1_B_0_R_1_ChA_IN)

/* User Config File Start */

/* User Config File End */


/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

#endif  /* FBLCW_CFG_H */
/**********************************************************************************************************************
  END OF FILE: FblCw_Cfg.h
**********************************************************************************************************************/

