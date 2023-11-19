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
 *              File: PduR_Lcfg.h
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


#if !defined (PDUR_LCFG_H)
# define PDUR_LCFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
# include "PduR_Types.h"
# include "PduR_PBcfg.h"


/* include headers with symbolic name values */
/* \trace SPEC-2020167 */

#include "CanTp.h"
#include "Dcm_Cbk.h"




/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  PduRPCDataSwitches  PduR Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define PDUR_BMTXBUFFERARRAYRAM                                       STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferArrayRam' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERINDROM                                         STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferIndRom' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERROMIDXOFBMTXBUFFERINDROM                       STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferIndRom.BmTxBufferRomIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERINSTANCERAM                                    STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRam' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERARRAYRAMREADIDXOFBMTXBUFFERINSTANCERAM         STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamReadIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERARRAYRAMWRITEIDXOFBMTXBUFFERINSTANCERAM        STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.BmTxBufferArrayRamWriteIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_PDURBUFFERSTATEOFBMTXBUFFERINSTANCERAM                   STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.PduRBufferState' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TXBUFFERUSEDOFBMTXBUFFERINSTANCERAM                      STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRam.TxBufferUsed' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERINSTANCEROM                                    STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRom' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERROMIDXOFBMTXBUFFERINSTANCEROM                  STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferInstanceRom.BmTxBufferRomIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERRAM                                            STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERARRAYRAMINSTANCESTOPIDXOFBMTXBUFFERRAM         STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamInstanceStopIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERARRAYRAMREADIDXOFBMTXBUFFERRAM                 STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamReadIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERARRAYRAMWRITEIDXOFBMTXBUFFERRAM                STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.BmTxBufferArrayRamWriteIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_PDURBUFFERSTATEOFBMTXBUFFERRAM                           STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.PduRBufferState' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_RXLENGTHOFBMTXBUFFERRAM                                  STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.RxLength' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TPBUFMGRSTATEOFBMTXBUFFERRAM                             STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRam.TpBufMgrState' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERROM                                            STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERARRAYRAMENDIDXOFBMTXBUFFERROM                  STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamEndIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERARRAYRAMLENGTHOFBMTXBUFFERROM                  STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamLength' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERARRAYRAMSTARTIDXOFBMTXBUFFERROM                STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferArrayRamStartIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERINSTANCEROMENDIDXOFBMTXBUFFERROM               STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomEndIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERINSTANCEROMSTARTIDXOFBMTXBUFFERROM             STD_OFF  /**< Deactivateable: 'PduR_BmTxBufferRom.BmTxBufferInstanceRomStartIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_CONFIGID                                                 STD_ON
#define PDUR_COPYRXDATARXSMTRANSITION                                 STD_OFF  /**< Deactivateable: 'PduR_CopyRxDataRxSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFCOPYRXDATARXSMTRANSITION                         STD_OFF  /**< Deactivateable: 'PduR_CopyRxDataRxSmTransition.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_COPYTXDATATXINSTSMTRANSITION                             STD_OFF  /**< Deactivateable: 'PduR_CopyTxDataTxInstSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFCOPYTXDATATXINSTSMTRANSITION                     STD_OFF  /**< Deactivateable: 'PduR_CopyTxDataTxInstSmTransition.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FIFOINITVALUES                                           STD_OFF  /**< Deactivateable: 'PduR_FiFoInitValues' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FINALMAGICNUMBER                                         STD_OFF  /**< Deactivateable: 'PduR_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define PDUR_FINISHREADFMSMTRANSITION                                 STD_OFF  /**< Deactivateable: 'PduR_FinishReadFmSmTransition' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FCTPTROFFINISHREADFMSMTRANSITION                         STD_OFF  /**< Deactivateable: 'PduR_FinishReadFmSmTransition.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FINISHRECEPTIONRMSMTRANSITION                            STD_OFF  /**< Deactivateable: 'PduR_FinishReceptionRmSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFFINISHRECEPTIONRMSMTRANSITION                    STD_OFF  /**< Deactivateable: 'PduR_FinishReceptionRmSmTransition.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FINISHTRANSMISSIONRMSMTRANSITION                         STD_OFF  /**< Deactivateable: 'PduR_FinishTransmissionRmSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFFINISHTRANSMISSIONRMSMTRANSITION                 STD_OFF  /**< Deactivateable: 'PduR_FinishTransmissionRmSmTransition.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FINISHWRITEFMSMTRANSITION                                STD_OFF  /**< Deactivateable: 'PduR_FinishWriteFmSmTransition' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FCTPTROFFINISHWRITEFMSMTRANSITION                        STD_OFF  /**< Deactivateable: 'PduR_FinishWriteFmSmTransition.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FMFIFOELEMENTRAM                                         STD_OFF  /**< Deactivateable: 'PduR_FmFifoElementRam' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERROMIDXOFFMFIFOELEMENTRAM                       STD_OFF  /**< Deactivateable: 'PduR_FmFifoElementRam.BmTxBufferRomIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_DEDICATEDTXBUFFEROFFMFIFOELEMENTRAM                      STD_OFF  /**< Deactivateable: 'PduR_FmFifoElementRam.DedicatedTxBuffer' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_RMDESTROMIDXOFFMFIFOELEMENTRAM                           STD_OFF  /**< Deactivateable: 'PduR_FmFifoElementRam.RmDestRomIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_STATEOFFMFIFOELEMENTRAM                                  STD_OFF  /**< Deactivateable: 'PduR_FmFifoElementRam.State' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FMFIFOINSTANCERAM                                        STD_OFF  /**< Deactivateable: 'PduR_FmFifoInstanceRam' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERINSTANCEROMIDXOFFMFIFOINSTANCERAM              STD_OFF  /**< Deactivateable: 'PduR_FmFifoInstanceRam.BmTxBufferInstanceRomIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FMFIFOINSTANCEROM                                        STD_OFF  /**< Deactivateable: 'PduR_FmFifoInstanceRom' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FMFIFOROMIDXOFFMFIFOINSTANCEROM                          STD_OFF  /**< Deactivateable: 'PduR_FmFifoInstanceRom.FmFifoRomIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FMFIFORAM                                                STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FILLLEVELOFFMFIFORAM                                     STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam.FillLevel' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FMFIFOELEMENTRAMREADIDXOFFMFIFORAM                       STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamReadIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FMFIFOELEMENTRAMWRITEIDXOFFMFIFORAM                      STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam.FmFifoElementRamWriteIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_PENDINGCONFIRMATIONSOFFMFIFORAM                          STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam.PendingConfirmations' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TPTXSMSTATEOFFMFIFORAM                                   STD_OFF  /**< Deactivateable: 'PduR_FmFifoRam.TpTxSmState' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FMFIFOROM                                                STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FMFIFOELEMENTRAMENDIDXOFFMFIFOROM                        STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamEndIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FMFIFOELEMENTRAMLENGTHOFFMFIFOROM                        STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamLength' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FMFIFOELEMENTRAMSTARTIDXOFFMFIFOROM                      STD_OFF  /**< Deactivateable: 'PduR_FmFifoRom.FmFifoElementRamStartIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FMFLUSHFIFOELEMENT                                       STD_OFF  /**< Deactivateable: 'PduR_FmFlushFifoElement' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FCTPTROFFMFLUSHFIFOELEMENT                               STD_OFF  /**< Deactivateable: 'PduR_FmFlushFifoElement.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_IFROUTINGSTATETABLE                                      STD_ON
#define PDUR_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE STD_ON
#define PDUR_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE STD_ON
#define PDUR_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE STD_ON
#define PDUR_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE STD_ON
#define PDUR_INITDATAHASHCODE                                         STD_OFF  /**< Deactivateable: 'PduR_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define PDUR_INITIALIZED                                              STD_ON
#define PDUR_MMROM                                                    STD_ON
#define PDUR_CANCELRECEIVESUPPORTEDOFMMROM                            STD_OFF  /**< Deactivateable: 'PduR_MmRom.CancelReceiveSupported' Reason: 'the value of PduR_CancelReceiveSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_CHANGEPARAMETERSUPPORTEDOFMMROM                          STD_OFF  /**< Deactivateable: 'PduR_MmRom.ChangeParameterSupported' Reason: 'the value of PduR_ChangeParameterSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_IFCANCELTRANSMITSUPPORTEDOFMMROM                         STD_OFF  /**< Deactivateable: 'PduR_MmRom.IfCancelTransmitSupported' Reason: 'the value of PduR_IfCancelTransmitSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_LOIFCANCELTRANSMITFCTPTROFMMROM                          STD_OFF  /**< Deactivateable: 'PduR_MmRom.LoIfCancelTransmitFctPtr' Reason: 'the value of PduR_LoIfCancelTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_LOIFOFMMROM                                              STD_OFF  /**< Deactivateable: 'PduR_MmRom.LoIf' Reason: 'the value of PduR_LoIfOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_LOIFTRANSMITFCTPTROFMMROM                                STD_OFF  /**< Deactivateable: 'PduR_MmRom.LoIfTransmitFctPtr' Reason: 'the value of PduR_LoIfTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_LOTPCANCELRECEIVEFCTPTROFMMROM                           STD_OFF  /**< Deactivateable: 'PduR_MmRom.LoTpCancelReceiveFctPtr' Reason: 'the value of PduR_LoTpCancelReceiveFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_LOTPCANCELTRANSMITFCTPTROFMMROM                          STD_OFF  /**< Deactivateable: 'PduR_MmRom.LoTpCancelTransmitFctPtr' Reason: 'the value of PduR_LoTpCancelTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_LOTPCHANGEPARAMETERFCTPTROFMMROM                         STD_OFF  /**< Deactivateable: 'PduR_MmRom.LoTpChangeParameterFctPtr' Reason: 'the value of PduR_LoTpChangeParameterFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_LOTPOFMMROM                                              STD_ON
#define PDUR_LOTPTRANSMITFCTPTROFMMROM                                STD_ON
#define PDUR_MASKEDBITSOFMMROM                                        STD_ON
#define PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM                         STD_OFF  /**< Deactivateable: 'PduR_MmRom.TpCancelTransmitSupported' Reason: 'the value of PduR_TpCancelTransmitSupportedOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_UPIFOFMMROM                                              STD_OFF  /**< Deactivateable: 'PduR_MmRom.UpIf' Reason: 'the value of PduR_UpIfOfMmRom is always 'false' due to this, the array is deactivated.' */
#define PDUR_UPIFRXINDICATIONFCTPTROFMMROM                            STD_OFF  /**< Deactivateable: 'PduR_MmRom.UpIfRxIndicationFctPtr' Reason: 'the value of PduR_UpIfRxIndicationFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_UPIFTRIGGERTRANSMITFCTPTROFMMROM                         STD_OFF  /**< Deactivateable: 'PduR_MmRom.UpIfTriggerTransmitFctPtr' Reason: 'the value of PduR_UpIfTriggerTransmitFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_UPIFTXCONFIRMATIONFCTPTROFMMROM                          STD_OFF  /**< Deactivateable: 'PduR_MmRom.UpIfTxConfirmationFctPtr' Reason: 'the value of PduR_UpIfTxConfirmationFctPtrOfMmRom is always 'NULL_PTR' due to this, the array is deactivated.' */
#define PDUR_UPTPCOPYRXDATAFCTPTROFMMROM                              STD_ON
#define PDUR_UPTPCOPYTXDATAFCTPTROFMMROM                              STD_ON
#define PDUR_UPTPOFMMROM                                              STD_ON
#define PDUR_UPTPSTARTOFRECEPTIONFCTPTROFMMROM                        STD_ON
#define PDUR_UPTPTPRXINDICATIONFCTPTROFMMROM                          STD_ON
#define PDUR_UPTPTPTXCONFIRMATIONFCTPTROFMMROM                        STD_ON
#define PDUR_RECEPTIONINDICATIONQUEUE                                 STD_OFF  /**< Deactivateable: 'PduR_ReceptionIndicationQueue' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduREnableDeferredReception] is configured to 'false'' */
#define PDUR_RMGDESTROMIDXOFRECEPTIONINDICATIONQUEUE                  STD_OFF  /**< Deactivateable: 'PduR_ReceptionIndicationQueue.RmGDestRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduREnableDeferredReception] is configured to 'false'' */
#define PDUR_RECEPTIONINDICATIONQUEUEREADIDX                          STD_OFF  /**< Deactivateable: 'PduR_ReceptionIndicationQueueReadIdx' Reason: 'All indirection targets are deactivated in all variants.' */
#define PDUR_RECEPTIONINDICATIONQUEUEWRITEIDX                         STD_OFF  /**< Deactivateable: 'PduR_ReceptionIndicationQueueWriteIdx' Reason: 'All indirection targets are deactivated in all variants.' */
#define PDUR_RMBUFFEREDIFPROPERTIESRAM                                STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRam' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_IFSMSTATEOFRMBUFFEREDIFPROPERTIESRAM                     STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRam.IfSmState' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_RMBUFFEREDIFPROPERTIESROM                                STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_BMTXBUFFERINDROMENDIDXOFRMBUFFEREDIFPROPERTIESROM        STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.BmTxBufferIndRomEndIdx' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_BMTXBUFFERINDROMLENGTHOFRMBUFFEREDIFPROPERTIESROM        STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.BmTxBufferIndRomLength' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_BMTXBUFFERINDROMSTARTIDXOFRMBUFFEREDIFPROPERTIESROM      STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.BmTxBufferIndRomStartIdx' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_DEDICATEDTXBUFFEROFRMBUFFEREDIFPROPERTIESROM             STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.DedicatedTxBuffer' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_FIFOINITVALUESENDIDXOFRMBUFFEREDIFPROPERTIESROM          STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.FiFoInitValuesEndIdx' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_FIFOINITVALUESLENGTHOFRMBUFFEREDIFPROPERTIESROM          STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.FiFoInitValuesLength' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_FIFOINITVALUESSTARTIDXOFRMBUFFEREDIFPROPERTIESROM        STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.FiFoInitValuesStartIdx' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_FIFOINITVALUESUSEDOFRMBUFFEREDIFPROPERTIESROM            STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.FiFoInitValuesUsed' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM                      STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.FifoType' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_MAXPDULENGTHOFRMBUFFEREDIFPROPERTIESROM                  STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.MaxPduLength' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_RMBUFFEREDTPPROPERTIESRAM                                STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRam' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FMFIFOELEMENTRAMIDXOFRMBUFFEREDTPPROPERTIESRAM           STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRam.FmFifoElementRamIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TPRXSMSTATEOFRMBUFFEREDTPPROPERTIESRAM                   STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRam.TpRxSmState' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_RMBUFFEREDTPPROPERTIESROM                                STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERINDROMENDIDXOFRMBUFFEREDTPPROPERTIESROM        STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.BmTxBufferIndRomEndIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERINDROMLENGTHOFRMBUFFEREDTPPROPERTIESROM        STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.BmTxBufferIndRomLength' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_BMTXBUFFERINDROMSTARTIDXOFRMBUFFEREDTPPROPERTIESROM      STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.BmTxBufferIndRomStartIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_DEDICATEDTXBUFFEROFRMBUFFEREDTPPROPERTIESROM             STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.DedicatedTxBuffer' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FMFIFOROMIDXOFRMBUFFEREDTPPROPERTIESROM                  STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.FmFifoRomIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_METADATALENGTHOFRMBUFFEREDTPPROPERTIESROM                STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.MetaDataLength' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_METADATALENGTHUSEDOFRMBUFFEREDTPPROPERTIESROM            STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.MetaDataLengthUsed' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TPTHRESHOLDOFRMBUFFEREDTPPROPERTIESROM                   STD_OFF  /**< Deactivateable: 'PduR_RmBufferedTpPropertiesRom.TpThreshold' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_RMDESTROM                                                STD_ON
#define PDUR_DIRECTIONOFRMDESTROM                                     STD_ON
#define PDUR_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM                     STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.PduLengthHandlingStrategy' Reason: 'the value of PduR_PduLengthHandlingStrategyOfRmDestRom is always '0' due to this, the array is deactivated.' */
#define PDUR_RMDESTRPGROMIDXOFRMDESTROM                               STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.RmDestRpgRomIdx' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMDESTRPGROMUSEDOFRMDESTROM                              STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.RmDestRpgRomUsed' Reason: 'the optional indirection is deactivated because RmDestRpgRomUsedOfRmDestRom is always 'FALSE' and the target of the indirection is of the Configuration Class 'PRE_COMPILE'.' */
#define PDUR_RMGDESTROMIDXOFRMDESTROM                                 STD_ON
#define PDUR_RMSRCROMIDXOFRMDESTROM                                   STD_ON
#define PDUR_ROUTINGTYPEOFRMDESTROM                                   STD_ON
#define PDUR_RMDESTRPGRAM                                             STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_ENABLEDCNTOFRMDESTRPGRAM                                 STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRam.EnabledCnt' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_RMDESTRPGROM                                             STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_INITIALENABLEDCNTOFRMDESTRPGROM                          STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.InitialEnabledCnt' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTROMIDXOFRMDESTRPGROM                               STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.RmDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTROMIFIDXOFRMDESTRPGROM                             STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.RmDestRomIfIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTROMIFUSEDOFRMDESTRPGROM                            STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.RmDestRomIfUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTROMUSEDOFRMDESTRPGROM                              STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRom.RmDestRomUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMIND                                          STD_OFF  /**< Deactivateable: 'PduR_RmDestRpgRomInd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMGDESTNTO1INFORAM                                       STD_OFF  /**< Deactivateable: 'PduR_RmGDestNto1InfoRam' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_RMDESTROMIDXOFRMGDESTNTO1INFORAM                         STD_OFF  /**< Deactivateable: 'PduR_RmGDestNto1InfoRam.RmDestRomIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TRANSMISSIONACTIVEOFRMGDESTNTO1INFORAM                   STD_OFF  /**< Deactivateable: 'PduR_RmGDestNto1InfoRam.TransmissionActive' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_RMGDESTROM                                               STD_ON
#define PDUR_DESTHNDOFRMGDESTROM                                      STD_ON
#define PDUR_FMFIFOINSTANCEROMIDXOFRMGDESTROM                         STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.FmFifoInstanceRomIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FMFIFOINSTANCEROMUSEDOFRMGDESTROM                        STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.FmFifoInstanceRomUsed' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_MMROMIDXOFRMGDESTROM                                     STD_ON
#define PDUR_PDURDESTPDUPROCESSINGOFRMGDESTROM                        STD_ON
#define PDUR_RMBUFFEREDIFPROPERTIESROMIDXOFRMGDESTROM                 STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.RmBufferedIfPropertiesRomIdx' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_RMBUFFEREDIFPROPERTIESROMUSEDOFRMGDESTROM                STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.RmBufferedIfPropertiesRomUsed' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_RMDESTROMIDXOFRMGDESTROM                                 STD_ON
#define PDUR_RMDESTROMUSEDOFRMGDESTROM                                STD_ON
#define PDUR_RMGDESTNTO1INFORAMIDXOFRMGDESTROM                        STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.RmGDestNto1InfoRamIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_RMGDESTNTO1INFORAMUSEDOFRMGDESTROM                       STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.RmGDestNto1InfoRamUsed' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_RMGDESTTPTXSTATERAMIDXOFRMGDESTROM                       STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.RmGDestTpTxStateRamIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_RMGDESTTPTXSTATERAMUSEDOFRMGDESTROM                      STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.RmGDestTpTxStateRamUsed' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_SMGDESTROMIDXOFRMGDESTROM                                STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.SmGDestRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTROMUSEDOFRMGDESTROM                               STD_OFF  /**< Deactivateable: 'PduR_RmGDestRom.SmGDestRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_RMGDESTTPTXSTATERAM                                      STD_OFF  /**< Deactivateable: 'PduR_RmGDestTpTxStateRam' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TPTXINSTSMSTATEOFRMGDESTTPTXSTATERAM                     STD_OFF  /**< Deactivateable: 'PduR_RmGDestTpTxStateRam.TpTxInstSmState' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_RMSRCROM                                                 STD_ON
#define PDUR_MMROMIDXOFRMSRCROM                                       STD_ON
#define PDUR_RMBUFFEREDTPPROPERTIESROMIDXOFRMSRCROM                   STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.RmBufferedTpPropertiesRomIdx' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_RMBUFFEREDTPPROPERTIESROMUSEDOFRMSRCROM                  STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.RmBufferedTpPropertiesRomUsed' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_RMDESTROMENDIDXOFRMSRCROM                                STD_ON
#define PDUR_RMDESTROMLENGTHOFRMSRCROM                                STD_ON
#define PDUR_RMDESTROMSTARTIDXOFRMSRCROM                              STD_ON
#define PDUR_SMSRCROMIDXOFRMSRCROM                                    STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.SmSrcRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCROMUSEDOFRMSRCROM                                   STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.SmSrcRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SRCHNDOFRMSRCROM                                         STD_ON
#define PDUR_TRIGGERTRANSMITSUPPORTEDOFRMSRCROM                       STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.TriggerTransmitSupported' Reason: 'No BswModule with TriggerTransmit active.' */
#define PDUR_TXCONFIRMATIONSUPPORTEDOFRMSRCROM                        STD_OFF  /**< Deactivateable: 'PduR_RmSrcRom.TxConfirmationSupported' Reason: 'No BswModule with TxConfirmation active.' */
#define PDUR_RMTRANSMITFCTPTR                                         STD_ON
#define PDUR_RPGRAM                                                   STD_OFF  /**< Deactivateable: 'PduR_RpgRam' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_ENABLEDOFRPGRAM                                          STD_OFF  /**< Deactivateable: 'PduR_RpgRam.Enabled' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
#define PDUR_RPGROM                                                   STD_OFF  /**< Deactivateable: 'PduR_RpgRom' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_ENABLEDATINITOFRPGROM                                    STD_OFF  /**< Deactivateable: 'PduR_RpgRom.EnabledAtInit' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_INVALIDHNDOFRPGROM                                       STD_OFF  /**< Deactivateable: 'PduR_RpgRom.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMINDENDIDXOFRPGROM                            STD_OFF  /**< Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndEndIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMINDSTARTIDXOFRPGROM                          STD_OFF  /**< Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndStartIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMDESTRPGROMINDUSEDOFRPGROM                              STD_OFF  /**< Deactivateable: 'PduR_RpgRom.RmDestRpgRomIndUsed' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RXIF2DEST                                                STD_OFF  /**< Deactivateable: 'PduR_RxIf2Dest' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' */
#define PDUR_BSWMPDURRXINDICATIONCALLBACKOFRXIF2DEST                  STD_OFF  /**< Deactivateable: 'PduR_RxIf2Dest.BswMPduRRxIndicationCallback' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' */
#define PDUR_INVALIDHNDOFRXIF2DEST                                    STD_OFF  /**< Deactivateable: 'PduR_RxIf2Dest.InvalidHnd' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' */
#define PDUR_RMSRCROMIDXOFRXIF2DEST                                   STD_OFF  /**< Deactivateable: 'PduR_RxIf2Dest.RmSrcRomIdx' Reason: 'No communication interface PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCommunicationInterface' */
#define PDUR_RXTP2DEST                                                STD_ON
#define PDUR_BSWMPDURTPRXINDICATIONCALLBACKOFRXTP2DEST                STD_OFF  /**< Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpRxIndicationCallback' Reason: 'Callback Support is not active' */
#define PDUR_BSWMPDURTPSTARTOFRECEPTIONCALLBACKOFRXTP2DEST            STD_OFF  /**< Deactivateable: 'PduR_RxTp2Dest.BswMPduRTpStartOfReceptionCallback' Reason: 'Callback Support is not active' */
#define PDUR_INVALIDHNDOFRXTP2DEST                                    STD_OFF  /**< Deactivateable: 'PduR_RxTp2Dest.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfRxTp2Dest is always 'false' due to this, the array is deactivated.' */
#define PDUR_RMSRCROMIDXOFRXTP2DEST                                   STD_ON
#define PDUR_RMSRCROMUSEDOFRXTP2DEST                                  STD_ON
#define PDUR_RXTP2SRC                                                 STD_OFF  /**< Deactivateable: 'PduR_RxTp2Src' Reason: '(No PduRBswModule configured which uses the CancelReceive API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelReceive) && (No PduRBswModule configured which uses the ChangeParameter API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRChangeParameterRequestApi)' */
#define PDUR_INVALIDHNDOFRXTP2SRC                                     STD_OFF  /**< Deactivateable: 'PduR_RxTp2Src.InvalidHnd' Reason: '(No PduRBswModule configured which uses the CancelReceive API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelReceive) && (No PduRBswModule configured which uses the ChangeParameter API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRChangeParameterRequestApi)' */
#define PDUR_RMDESTROMIDXOFRXTP2SRC                                   STD_OFF  /**< Deactivateable: 'PduR_RxTp2Src.RmDestRomIdx' Reason: '(No PduRBswModule configured which uses the CancelReceive API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRCancelReceive) && (No PduRBswModule configured which uses the ChangeParameter API.. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRChangeParameterRequestApi)' */
#define PDUR_SIZEOFIFROUTINGSTATETABLE                                STD_ON
#define PDUR_SIZEOFMMROM                                              STD_ON
#define PDUR_SIZEOFRMDESTROM                                          STD_ON
#define PDUR_SIZEOFRMGDESTROM                                         STD_ON
#define PDUR_SIZEOFRMSRCROM                                           STD_ON
#define PDUR_SIZEOFRMTRANSMITFCTPTR                                   STD_ON
#define PDUR_SIZEOFRXTP2DEST                                          STD_ON
#define PDUR_SIZEOFTX2LO                                              STD_ON
#define PDUR_SIZEOFTXTP2SRC                                           STD_ON
#define PDUR_SMDATAPLANEROM                                           STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMFIBRAMENDIDXOFSMDATAPLANEROM                           STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamEndIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMFIBRAMSTARTIDXOFSMDATAPLANEROM                         STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamStartIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMFIBRAMUSEDOFSMDATAPLANEROM                             STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmFibRamUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROMIDXOFSMDATAPLANEROM  STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROMUSEDOFSMDATAPLANEROM STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmLinearTaToSaCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROMIDXOFSMDATAPLANEROM STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROMUSEDOFSMDATAPLANEROM STD_OFF  /**< Deactivateable: 'PduR_SmDataPlaneRom.SmSaTaFromMetaDataCalculationStrategyRomUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMFIBRAM                                                 STD_OFF  /**< Deactivateable: 'PduR_SmFibRam' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_LEARNEDCONNECTIONIDOFSMFIBRAM                            STD_OFF  /**< Deactivateable: 'PduR_SmFibRam.LearnedConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTFILTERFCTPTR                                      STD_OFF  /**< Deactivateable: 'PduR_SmGDestFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTROM                                               STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_CONNECTIONIDOFSMGDESTROM                                 STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_METADATALENGTHOFSMGDESTROM                               STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMDATAPLANEROMIDXOFSMGDESTROM                            STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMGDESTFILTERFCTPTRIDXOFSMGDESTROM                       STD_OFF  /**< Deactivateable: 'PduR_SmGDestRom.SmGDestFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTR             STD_OFF  /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyGetSaFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYROM                     STD_OFF  /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_MASKOFSMLINEARTATOSACALCULATIONSTRATEGYROM               STD_OFF  /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Mask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_OFFSETOFSMLINEARTATOSACALCULATIONSTRATEGYROM             STD_OFF  /**< Deactivateable: 'PduR_SmLinearTaToSaCalculationStrategyRom.Offset' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSATAFROMMETADATACALCULATIONSTRATEGYROM                 STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SAMASKOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM         STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SASTARTBITOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM     STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.SaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_TAMASKOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM         STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaMask' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_TASTARTBITOFSMSATAFROMMETADATACALCULATIONSTRATEGYROM     STD_OFF  /**< Deactivateable: 'PduR_SmSaTaFromMetaDataCalculationStrategyRom.TaStartBit' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCFILTERFCTPTR                                        STD_OFF  /**< Deactivateable: 'PduR_SmSrcFilterFctPtr' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCROM                                                 STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_CONNECTIONIDOFSMSRCROM                                   STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.ConnectionId' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_METADATALENGTHOFSMSRCROM                                 STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.MetaDataLength' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMDATAPLANEROMIDXOFSMSRCROM                              STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.SmDataPlaneRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTRIDXOFSMSRCROM STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMLINEARTATOSACALCULATIONSTRATEGYGETSAFCTPTRUSEDOFSMSRCROM STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.SmLinearTaToSaCalculationStrategyGetSaFctPtrUsed' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_SMSRCFILTERFCTPTRIDXOFSMSRCROM                           STD_OFF  /**< Deactivateable: 'PduR_SmSrcRom.SmSrcFilterFctPtrIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduRSwitching] is configured to 'false'' */
#define PDUR_STARTOFRECEPTIONRXSMTRANSITION                           STD_OFF  /**< Deactivateable: 'PduR_StartOfReceptionRxSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFSTARTOFRECEPTIONRXSMTRANSITION                   STD_OFF  /**< Deactivateable: 'PduR_StartOfReceptionRxSmTransition.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TPACTIVATENEXTFIFOSMTRANSITION                           STD_OFF  /**< Deactivateable: 'PduR_TpActivateNextFifoSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFTPACTIVATENEXTFIFOSMTRANSITION                   STD_OFF  /**< Deactivateable: 'PduR_TpActivateNextFifoSmTransition.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TPACTIVATEREADFIFOSMTRANSITION                           STD_OFF  /**< Deactivateable: 'PduR_TpActivateReadFifoSmTransition' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FCTPTROFTPACTIVATEREADFIFOSMTRANSITION                   STD_OFF  /**< Deactivateable: 'PduR_TpActivateReadFifoSmTransition.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TPACTIVATEWRITEFIFOSMTRANSITION                          STD_OFF  /**< Deactivateable: 'PduR_TpActivateWriteFifoSmTransition' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FCTPTROFTPACTIVATEWRITEFIFOSMTRANSITION                  STD_OFF  /**< Deactivateable: 'PduR_TpActivateWriteFifoSmTransition.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TPCANCELRECEIVEFIFOSMTRANSITION                          STD_OFF  /**< Deactivateable: 'PduR_TpCancelReceiveFifoSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFTPCANCELRECEIVEFIFOSMTRANSITION                  STD_OFF  /**< Deactivateable: 'PduR_TpCancelReceiveFifoSmTransition.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TPCANCELTRANSMITTXINSTSMTRANSITION                       STD_OFF  /**< Deactivateable: 'PduR_TpCancelTransmitTxInstSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFTPCANCELTRANSMITTXINSTSMTRANSITION               STD_OFF  /**< Deactivateable: 'PduR_TpCancelTransmitTxInstSmTransition.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TPCHECKREADY2TRANSMITRMSMTRANSITION                      STD_OFF  /**< Deactivateable: 'PduR_TpCheckReady2TransmitRmSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFTPCHECKREADY2TRANSMITRMSMTRANSITION              STD_OFF  /**< Deactivateable: 'PduR_TpCheckReady2TransmitRmSmTransition.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TPDISABLEROUTINGTXSMTRANSITION                           STD_OFF  /**< Deactivateable: 'PduR_TpDisableRoutingTxSmTransition' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_FCTPTROFTPDISABLEROUTINGTXSMTRANSITION                   STD_OFF  /**< Deactivateable: 'PduR_TpDisableRoutingTxSmTransition.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TPRXINDICATIONRXSMTRANSITION                             STD_OFF  /**< Deactivateable: 'PduR_TpRxIndicationRxSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFTPRXINDICATIONRXSMTRANSITION                     STD_OFF  /**< Deactivateable: 'PduR_TpRxIndicationRxSmTransition.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TPTRIGGERTRANSMITTXINSTSMTRANSITION                      STD_OFF  /**< Deactivateable: 'PduR_TpTriggerTransmitTxInstSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFTPTRIGGERTRANSMITTXINSTSMTRANSITION              STD_OFF  /**< Deactivateable: 'PduR_TpTriggerTransmitTxInstSmTransition.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TPTXCONFIRMATIONTXSMTRANSITION                           STD_OFF  /**< Deactivateable: 'PduR_TpTxConfirmationTxSmTransition' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_FCTPTROFTPTXCONFIRMATIONTXSMTRANSITION                   STD_OFF  /**< Deactivateable: 'PduR_TpTxConfirmationTxSmTransition.FctPtr' Reason: 'The PDUR gateway is not Licensed.' */
#define PDUR_TRANSMITREQUESTQUEUE                                     STD_OFF  /**< Deactivateable: 'PduR_TransmitRequestQueue' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduREnableDeferredTransmission] is configured to 'false'' */
#define PDUR_RMGDESTROMIDXOFTRANSMITREQUESTQUEUE                      STD_OFF  /**< Deactivateable: 'PduR_TransmitRequestQueue.RmGDestRomIdx' Reason: '/ActiveEcuC/PduR/PduRGeneral[0:PduREnableDeferredTransmission] is configured to 'false'' */
#define PDUR_TRANSMITREQUESTQUEUEREADIDX                              STD_OFF  /**< Deactivateable: 'PduR_TransmitRequestQueueReadIdx' Reason: 'All indirection targets are deactivated in all variants.' */
#define PDUR_TRANSMITREQUESTQUEUEWRITEIDX                             STD_OFF  /**< Deactivateable: 'PduR_TransmitRequestQueueWriteIdx' Reason: 'All indirection targets are deactivated in all variants.' */
#define PDUR_TX2LO                                                    STD_ON
#define PDUR_BSWMPDURTRANSMITCALLBACKOFTX2LO                          STD_OFF  /**< Deactivateable: 'PduR_Tx2Lo.BswMPduRTransmitCallback' Reason: 'Callback Support is not active' */
#define PDUR_CANCELTRANSMITUSEDOFTX2LO                                STD_OFF  /**< Deactivateable: 'PduR_Tx2Lo.CancelTransmitUsed' Reason: 'the value of PduR_CancelTransmitUsedOfTx2Lo is always 'false' due to this, the array is deactivated.' */
#define PDUR_INVALIDHNDOFTX2LO                                        STD_OFF  /**< Deactivateable: 'PduR_Tx2Lo.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTx2Lo is always 'false' due to this, the array is deactivated.' */
#define PDUR_RMSRCROMIDXOFTX2LO                                       STD_ON
#define PDUR_RMSRCROMUSEDOFTX2LO                                      STD_ON
#define PDUR_RMTRANSMITFCTPTRIDXOFTX2LO                               STD_ON
#define PDUR_TXIF2UP                                                  STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up' Reason: 'the struct is deactivated because all elements are deactivated.' */
#define PDUR_BSWMPDURTXCONFIRMATIONCALLBACKOFTXIF2UP                  STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up.BswMPduRTxConfirmationCallback' Reason: 'Callback Support is not active' */
#define PDUR_INVALIDHNDOFTXIF2UP                                      STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up.InvalidHnd' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_RMGDESTROMIDXOFTXIF2UP                                   STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up.RmGDestRomIdx' Reason: 'the array is deactivated because the size is 0 and the piece of data is in the configuration class: PRE_COMPILE' */
#define PDUR_TXCONFIRMATIONUSEDOFTXIF2UP                              STD_OFF  /**< Deactivateable: 'PduR_TxIf2Up.TxConfirmationUsed' Reason: 'No tx confirmation PduRBswModule configured. Evaluated DefinitionRef: /MICROSAR/PduR/PduRBswModules/PduRTxConfirmation' */
#define PDUR_TXTP2SRC                                                 STD_ON
#define PDUR_BSWMPDURTPTXCONFIRMATIONCALLBACKOFTXTP2SRC               STD_OFF  /**< Deactivateable: 'PduR_TxTp2Src.BswMPduRTpTxConfirmationCallback' Reason: 'Callback Support is not active' */
#define PDUR_INVALIDHNDOFTXTP2SRC                                     STD_OFF  /**< Deactivateable: 'PduR_TxTp2Src.InvalidHnd' Reason: 'the value of PduR_InvalidHndOfTxTp2Src is always 'false' due to this, the array is deactivated.' */
#define PDUR_RMGDESTROMIDXOFTXTP2SRC                                  STD_ON
#define PDUR_PCCONFIG                                                 STD_ON
#define PDUR_CONFIGIDOFPCCONFIG                                       STD_ON
#define PDUR_FINALMAGICNUMBEROFPCCONFIG                               STD_OFF  /**< Deactivateable: 'PduR_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define PDUR_IFROUTINGSTATETABLEOFPCCONFIG                            STD_ON
#define PDUR_INITDATAHASHCODEOFPCCONFIG                               STD_OFF  /**< Deactivateable: 'PduR_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define PDUR_INITIALIZEDOFPCCONFIG                                    STD_ON
#define PDUR_MMROMOFPCCONFIG                                          STD_ON
#define PDUR_RMDESTROMOFPCCONFIG                                      STD_ON
#define PDUR_RMGDESTROMOFPCCONFIG                                     STD_ON
#define PDUR_RMSRCROMOFPCCONFIG                                       STD_ON
#define PDUR_RMTRANSMITFCTPTROFPCCONFIG                               STD_ON
#define PDUR_RXTP2DESTOFPCCONFIG                                      STD_ON
#define PDUR_SIZEOFIFROUTINGSTATETABLEOFPCCONFIG                      STD_ON
#define PDUR_SIZEOFMMROMOFPCCONFIG                                    STD_ON
#define PDUR_SIZEOFRMDESTROMOFPCCONFIG                                STD_ON
#define PDUR_SIZEOFRMGDESTROMOFPCCONFIG                               STD_ON
#define PDUR_SIZEOFRMSRCROMOFPCCONFIG                                 STD_ON
#define PDUR_SIZEOFRMTRANSMITFCTPTROFPCCONFIG                         STD_ON
#define PDUR_SIZEOFRXTP2DESTOFPCCONFIG                                STD_ON
#define PDUR_SIZEOFTX2LOOFPCCONFIG                                    STD_ON
#define PDUR_SIZEOFTXTP2SRCOFPCCONFIG                                 STD_ON
#define PDUR_TX2LOOFPCCONFIG                                          STD_ON
#define PDUR_TXTP2SRCOFPCCONFIG                                       STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCNoReferenceDefines  PduR No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define PDUR_NO_DESTHNDOFRMGDESTROM                                   255U
#define PDUR_NO_RMDESTROMIDXOFRMGDESTROM                              255U
#define PDUR_NO_SRCHNDOFRMSRCROM                                      255U
#define PDUR_NO_RMSRCROMIDXOFRXTP2DEST                                255U
#define PDUR_NO_RMSRCROMIDXOFTX2LO                                    255U
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCEnumExistsDefines  PduR Enum Exists Defines (PRE_COMPILE)
  \brief  These defines can be used to deactivate enumeration based code sequences if the enumeration value does not exist in the configuration data.
  \{
*/ 
#define PDUR_EXISTS_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE STD_OFF
#define PDUR_EXISTS_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE STD_OFF
#define PDUR_EXISTS_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE STD_OFF
#define PDUR_EXISTS_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE STD_ON
#define PDUR_EXISTS_NO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM     STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.FifoType' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_EXISTS_T_T_SINGLE_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.FifoType' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_EXISTS_T_T_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.FifoType' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_EXISTS_DIRECT_FIFO_BUFFER_FIFOTYPEOFRMBUFFEREDIFPROPERTIESROM STD_OFF  /**< Deactivateable: 'PduR_RmBufferedIfPropertiesRom.FifoType' Reason: 'No CommunicationInterface BswModule active.' */
#define PDUR_EXISTS_RX_DIRECTIONOFRMDESTROM                           STD_ON
#define PDUR_EXISTS_TX_DIRECTIONOFRMDESTROM                           STD_ON
#define PDUR_EXISTS_SHORTEN_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM      STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.PduLengthHandlingStrategy' Reason: 'the value of PduR_PduLengthHandlingStrategyOfRmDestRom is always '0' due to this, the array is deactivated.' */
#define PDUR_EXISTS_DISCARD_PDULENGTHHANDLINGSTRATEGYOFRMDESTROM      STD_OFF  /**< Deactivateable: 'PduR_RmDestRom.PduLengthHandlingStrategy' Reason: 'the value of PduR_PduLengthHandlingStrategyOfRmDestRom is always '0' due to this, the array is deactivated.' */
#define PDUR_EXISTS_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM   STD_OFF
#define PDUR_EXISTS_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM   STD_OFF
#define PDUR_EXISTS_IF_NOBUFFER_GATEWAY_ROUTINGTYPEOFRMDESTROM        STD_OFF
#define PDUR_EXISTS_IF_BUFFERED_ROUTINGTYPEOFRMDESTROM                STD_OFF  /**< The PDUR gateway is not Licensed. */
#define PDUR_EXISTS_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM   STD_ON
#define PDUR_EXISTS_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM   STD_ON
#define PDUR_EXISTS_TP_BUFFERED_ROUTINGTYPEOFRMDESTROM                STD_OFF  /**< The PDUR gateway is not Licensed. */
#define PDUR_EXISTS_DEFERRED_PDURDESTPDUPROCESSINGOFRMGDESTROM        STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduREnableDeferredReception] and /ActiveEcuC/PduR/PduRGeneral[0:PduREnableDeferredTransmission] are both disabled. */
#define PDUR_EXISTS_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM       STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCEnumDefines  PduR Enum Defines (PRE_COMPILE)
  \brief  These defines are the enumeration values of enumeration based CONST and VAR data.
  \{
*/ 
#define PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE 0x00U
#define PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE 0x01U
#define PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE 0x00U
#define PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE 0x01U
#define PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE 0x02U
#define PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE 0x01U
#define PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE 0x02U
#define PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE 0x01U
#define PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE 0x02U
#define PDUR_RX_DIRECTIONOFRMDESTROM                                  0x00U
#define PDUR_TX_DIRECTIONOFRMDESTROM                                  0x01U
#define PDUR_TP_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM          0x04U
#define PDUR_TP_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM          0x05U
#define PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM              0x01U
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCMaskedBitDefines  PduR Masked Bit Defines (PRE_COMPILE)
  \brief  These defines are masks to extract packed boolean data.
  \{
*/ 
#define PDUR_LOTPOFMMROM_MASK                                         0x02U
#define PDUR_UPTPOFMMROM_MASK                                         0x01U
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCIsReducedToDefineDefines  PduR Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define PDUR_ISDEF_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE STD_OFF
#define PDUR_ISDEF_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE STD_OFF
#define PDUR_ISDEF_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE STD_OFF
#define PDUR_ISDEF_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE STD_OFF
#define PDUR_ISDEF_LOTPOFMMROM                                        STD_OFF
#define PDUR_ISDEF_LOTPTRANSMITFCTPTROFMMROM                          STD_OFF
#define PDUR_ISDEF_MASKEDBITSOFMMROM                                  STD_OFF
#define PDUR_ISDEF_UPTPCOPYRXDATAFCTPTROFMMROM                        STD_OFF
#define PDUR_ISDEF_UPTPCOPYTXDATAFCTPTROFMMROM                        STD_OFF
#define PDUR_ISDEF_UPTPOFMMROM                                        STD_OFF
#define PDUR_ISDEF_UPTPSTARTOFRECEPTIONFCTPTROFMMROM                  STD_OFF
#define PDUR_ISDEF_UPTPTPRXINDICATIONFCTPTROFMMROM                    STD_OFF
#define PDUR_ISDEF_UPTPTPTXCONFIRMATIONFCTPTROFMMROM                  STD_OFF
#define PDUR_ISDEF_DIRECTIONOFRMDESTROM                               STD_OFF
#define PDUR_ISDEF_RMGDESTROMIDXOFRMDESTROM                           STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFRMDESTROM                             STD_OFF
#define PDUR_ISDEF_ROUTINGTYPEOFRMDESTROM                             STD_OFF
#define PDUR_ISDEF_DESTHNDOFRMGDESTROM                                STD_OFF
#define PDUR_ISDEF_MMROMIDXOFRMGDESTROM                               STD_OFF
#define PDUR_ISDEF_PDURDESTPDUPROCESSINGOFRMGDESTROM                  STD_OFF
#define PDUR_ISDEF_RMDESTROMIDXOFRMGDESTROM                           STD_OFF
#define PDUR_ISDEF_RMDESTROMUSEDOFRMGDESTROM                          STD_OFF
#define PDUR_ISDEF_MMROMIDXOFRMSRCROM                                 STD_OFF
#define PDUR_ISDEF_RMDESTROMENDIDXOFRMSRCROM                          STD_OFF
#define PDUR_ISDEF_RMDESTROMLENGTHOFRMSRCROM                          STD_OFF
#define PDUR_ISDEF_RMDESTROMSTARTIDXOFRMSRCROM                        STD_OFF
#define PDUR_ISDEF_SRCHNDOFRMSRCROM                                   STD_OFF
#define PDUR_ISDEF_RMTRANSMITFCTPTR                                   STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFRXTP2DEST                             STD_OFF
#define PDUR_ISDEF_RMSRCROMUSEDOFRXTP2DEST                            STD_OFF
#define PDUR_ISDEF_RMSRCROMIDXOFTX2LO                                 STD_OFF
#define PDUR_ISDEF_RMSRCROMUSEDOFTX2LO                                STD_OFF
#define PDUR_ISDEF_RMTRANSMITFCTPTRIDXOFTX2LO                         STD_OFF
#define PDUR_ISDEF_RMGDESTROMIDXOFTXTP2SRC                            STD_OFF
#define PDUR_ISDEF_IFROUTINGSTATETABLEOFPCCONFIG                      STD_ON
#define PDUR_ISDEF_INITIALIZEDOFPCCONFIG                              STD_ON
#define PDUR_ISDEF_MMROMOFPCCONFIG                                    STD_ON
#define PDUR_ISDEF_RMDESTROMOFPCCONFIG                                STD_ON
#define PDUR_ISDEF_RMGDESTROMOFPCCONFIG                               STD_ON
#define PDUR_ISDEF_RMSRCROMOFPCCONFIG                                 STD_ON
#define PDUR_ISDEF_RMTRANSMITFCTPTROFPCCONFIG                         STD_ON
#define PDUR_ISDEF_RXTP2DESTOFPCCONFIG                                STD_ON
#define PDUR_ISDEF_TX2LOOFPCCONFIG                                    STD_ON
#define PDUR_ISDEF_TXTP2SRCOFPCCONFIG                                 STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCEqualsAlwaysToDefines  PduR Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define PDUR_EQ2_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE 
#define PDUR_EQ2_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE 
#define PDUR_EQ2_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE 
#define PDUR_EQ2_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE 
#define PDUR_EQ2_LOTPOFMMROM                                          
#define PDUR_EQ2_LOTPTRANSMITFCTPTROFMMROM                            
#define PDUR_EQ2_MASKEDBITSOFMMROM                                    
#define PDUR_EQ2_UPTPCOPYRXDATAFCTPTROFMMROM                          
#define PDUR_EQ2_UPTPCOPYTXDATAFCTPTROFMMROM                          
#define PDUR_EQ2_UPTPOFMMROM                                          
#define PDUR_EQ2_UPTPSTARTOFRECEPTIONFCTPTROFMMROM                    
#define PDUR_EQ2_UPTPTPRXINDICATIONFCTPTROFMMROM                      
#define PDUR_EQ2_UPTPTPTXCONFIRMATIONFCTPTROFMMROM                    
#define PDUR_EQ2_DIRECTIONOFRMDESTROM                                 
#define PDUR_EQ2_RMGDESTROMIDXOFRMDESTROM                             
#define PDUR_EQ2_RMSRCROMIDXOFRMDESTROM                               
#define PDUR_EQ2_ROUTINGTYPEOFRMDESTROM                               
#define PDUR_EQ2_DESTHNDOFRMGDESTROM                                  
#define PDUR_EQ2_MMROMIDXOFRMGDESTROM                                 
#define PDUR_EQ2_PDURDESTPDUPROCESSINGOFRMGDESTROM                    
#define PDUR_EQ2_RMDESTROMIDXOFRMGDESTROM                             
#define PDUR_EQ2_RMDESTROMUSEDOFRMGDESTROM                            
#define PDUR_EQ2_MMROMIDXOFRMSRCROM                                   
#define PDUR_EQ2_RMDESTROMENDIDXOFRMSRCROM                            
#define PDUR_EQ2_RMDESTROMLENGTHOFRMSRCROM                            
#define PDUR_EQ2_RMDESTROMSTARTIDXOFRMSRCROM                          
#define PDUR_EQ2_SRCHNDOFRMSRCROM                                     
#define PDUR_EQ2_RMTRANSMITFCTPTR                                     
#define PDUR_EQ2_RMSRCROMIDXOFRXTP2DEST                               
#define PDUR_EQ2_RMSRCROMUSEDOFRXTP2DEST                              
#define PDUR_EQ2_RMSRCROMIDXOFTX2LO                                   
#define PDUR_EQ2_RMSRCROMUSEDOFTX2LO                                  
#define PDUR_EQ2_RMTRANSMITFCTPTRIDXOFTX2LO                           
#define PDUR_EQ2_RMGDESTROMIDXOFTXTP2SRC                              
#define PDUR_EQ2_IFROUTINGSTATETABLEOFPCCONFIG                        PduR_IfRoutingStateTable
#define PDUR_EQ2_INITIALIZEDOFPCCONFIG                                (&(PduR_Initialized))
#define PDUR_EQ2_MMROMOFPCCONFIG                                      PduR_MmRom
#define PDUR_EQ2_RMDESTROMOFPCCONFIG                                  PduR_RmDestRom
#define PDUR_EQ2_RMGDESTROMOFPCCONFIG                                 PduR_RmGDestRom
#define PDUR_EQ2_RMSRCROMOFPCCONFIG                                   PduR_RmSrcRom
#define PDUR_EQ2_RMTRANSMITFCTPTROFPCCONFIG                           PduR_RmTransmitFctPtr
#define PDUR_EQ2_RXTP2DESTOFPCCONFIG                                  PduR_RxTp2Dest
#define PDUR_EQ2_TX2LOOFPCCONFIG                                      PduR_Tx2Lo
#define PDUR_EQ2_TXTP2SRCOFPCCONFIG                                   PduR_TxTp2Src
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCSymbolicInitializationPointers  PduR Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define PduR_Config_Ptr                                               NULL_PTR  /**< symbolic identifier which shall be used to initialize 'PduR' */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCInitializationSymbols  PduR Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define PduR_Config                                                   NULL_PTR  /**< symbolic identifier which could be used to initialize 'PduR */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGeneral  PduR General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define PDUR_CHECK_INIT_POINTER                                       STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define PDUR_FINAL_MAGIC_NUMBER                                       0x331EU  /**< the precompile constant to validate the size of the initialization structure at initialization time of PduR */
#define PDUR_INDIVIDUAL_POSTBUILD                                     STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'PduR' is not configured to be postbuild capable. */
#define PDUR_INIT_DATA                                                PDUR_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define PDUR_INIT_DATA_HASH_CODE                                      -713907762L  /**< the precompile constant to validate the initialization structure at initialization time of PduR with a hashcode. The seed value is '0x331EU' */
#define PDUR_USE_ECUM_BSW_ERROR_HOOK                                  STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define PDUR_USE_INIT_POINTER                                         STD_OFF  /**< STD_ON if the init pointer PduR shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  PduRLTDataSwitches  PduR Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define PDUR_LTCONFIG                                                 STD_OFF  /**< Deactivateable: 'PduR_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 



/** BroadcastDummy */

#define PDUR_MAX_TRIGGER_TRANSMIT_PDU_SIZE 0


#if (PDUR_FMFIFOELEMENTRAM == STD_OFF)
  #define PduR_FmFifoElementRamIterType uint16
#endif

/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  PduRPCGetConstantDuplicatedRootDataMacros  PduR Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define PduR_GetConfigIdOfPCConfig()                                  0U  /**< DefinitionRef: /MICROSAR/PduR/PduRRoutingTables/PduRConfigurationId */
#define PduR_GetIfRoutingStateTableOfPCConfig()                       PduR_IfRoutingStateTable  /**< the pointer to PduR_IfRoutingStateTable */
#define PduR_GetInitializedOfPCConfig()                               (&(PduR_Initialized))  /**< the pointer to PduR_Initialized */
#define PduR_GetMmRomOfPCConfig()                                     PduR_MmRom  /**< the pointer to PduR_MmRom */
#define PduR_GetRmDestRomOfPCConfig()                                 PduR_RmDestRom  /**< the pointer to PduR_RmDestRom */
#define PduR_GetRmGDestRomOfPCConfig()                                PduR_RmGDestRom  /**< the pointer to PduR_RmGDestRom */
#define PduR_GetRmSrcRomOfPCConfig()                                  PduR_RmSrcRom  /**< the pointer to PduR_RmSrcRom */
#define PduR_GetRmTransmitFctPtrOfPCConfig()                          PduR_RmTransmitFctPtr  /**< the pointer to PduR_RmTransmitFctPtr */
#define PduR_GetRxTp2DestOfPCConfig()                                 PduR_RxTp2Dest  /**< the pointer to PduR_RxTp2Dest */
#define PduR_GetSizeOfIfRoutingStateTableOfPCConfig()                 4U  /**< the number of accomplishable value elements in PduR_IfRoutingStateTable */
#define PduR_GetSizeOfMmRomOfPCConfig()                               2U  /**< the number of accomplishable value elements in PduR_MmRom */
#define PduR_GetSizeOfRmDestRomOfPCConfig()                           6U  /**< the number of accomplishable value elements in PduR_RmDestRom */
#define PduR_GetSizeOfRmGDestRomOfPCConfig()                          6U  /**< the number of accomplishable value elements in PduR_RmGDestRom */
#define PduR_GetSizeOfRmSrcRomOfPCConfig()                            6U  /**< the number of accomplishable value elements in PduR_RmSrcRom */
#define PduR_GetSizeOfRmTransmitFctPtrOfPCConfig()                    1U  /**< the number of accomplishable value elements in PduR_RmTransmitFctPtr */
#define PduR_GetSizeOfRxTp2DestOfPCConfig()                           4U  /**< the number of accomplishable value elements in PduR_RxTp2Dest */
#define PduR_GetSizeOfTx2LoOfPCConfig()                               2U  /**< the number of accomplishable value elements in PduR_Tx2Lo */
#define PduR_GetSizeOfTxTp2SrcOfPCConfig()                            2U  /**< the number of accomplishable value elements in PduR_TxTp2Src */
#define PduR_GetTx2LoOfPCConfig()                                     PduR_Tx2Lo  /**< the pointer to PduR_Tx2Lo */
#define PduR_GetTxTp2SrcOfPCConfig()                                  PduR_TxTp2Src  /**< the pointer to PduR_TxTp2Src */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetDataMacros  PduR Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define PduR_GetNextState_For_Init_If_Routing_StateOfIfRoutingStateTable(Index) (PduR_GetIfRoutingStateTableOfPCConfig()[(Index)].NextState_For_Init_If_Routing_StateOfIfRoutingStateTable)
#define PduR_GetNextState_For_Wait_For_RxIndicationOfIfRoutingStateTable(Index) (PduR_GetIfRoutingStateTableOfPCConfig()[(Index)].NextState_For_Wait_For_RxIndicationOfIfRoutingStateTable)
#define PduR_GetNextState_For_Wait_For_TriggerTransmitOfIfRoutingStateTable(Index) (PduR_GetIfRoutingStateTableOfPCConfig()[(Index)].NextState_For_Wait_For_TriggerTransmitOfIfRoutingStateTable)
#define PduR_GetNextState_For_Wait_For_TxConfirmationOfIfRoutingStateTable(Index) (PduR_GetIfRoutingStateTableOfPCConfig()[(Index)].NextState_For_Wait_For_TxConfirmationOfIfRoutingStateTable)
#define PduR_IsInitialized()                                          (((*(PduR_GetInitializedOfPCConfig()))) != FALSE)
#define PduR_GetLoTpTransmitFctPtrOfMmRom(Index)                      (PduR_GetMmRomOfPCConfig()[(Index)].LoTpTransmitFctPtrOfMmRom)
#define PduR_GetMaskedBitsOfMmRom(Index)                              (PduR_GetMmRomOfPCConfig()[(Index)].MaskedBitsOfMmRom)
#define PduR_GetUpTpCopyRxDataFctPtrOfMmRom(Index)                    (PduR_GetMmRomOfPCConfig()[(Index)].UpTpCopyRxDataFctPtrOfMmRom)
#define PduR_GetUpTpCopyTxDataFctPtrOfMmRom(Index)                    (PduR_GetMmRomOfPCConfig()[(Index)].UpTpCopyTxDataFctPtrOfMmRom)
#define PduR_GetUpTpStartOfReceptionFctPtrOfMmRom(Index)              (PduR_GetMmRomOfPCConfig()[(Index)].UpTpStartOfReceptionFctPtrOfMmRom)
#define PduR_GetUpTpTpRxIndicationFctPtrOfMmRom(Index)                (PduR_GetMmRomOfPCConfig()[(Index)].UpTpTpRxIndicationFctPtrOfMmRom)
#define PduR_GetUpTpTpTxConfirmationFctPtrOfMmRom(Index)              (PduR_GetMmRomOfPCConfig()[(Index)].UpTpTpTxConfirmationFctPtrOfMmRom)
#define PduR_GetRoutingTypeOfRmDestRom(Index)                         (PduR_GetRmDestRomOfPCConfig()[(Index)].RoutingTypeOfRmDestRom)
#define PduR_GetDestHndOfRmGDestRom(Index)                            (PduR_GetRmGDestRomOfPCConfig()[(Index)].DestHndOfRmGDestRom)
#define PduR_GetMmRomIdxOfRmGDestRom(Index)                           (PduR_GetRmGDestRomOfPCConfig()[(Index)].MmRomIdxOfRmGDestRom)
#define PduR_GetPduRDestPduProcessingOfRmGDestRom(Index)              (PduR_GetRmGDestRomOfPCConfig()[(Index)].PduRDestPduProcessingOfRmGDestRom)
#define PduR_GetMmRomIdxOfRmSrcRom(Index)                             (PduR_GetRmSrcRomOfPCConfig()[(Index)].MmRomIdxOfRmSrcRom)
#define PduR_GetRmDestRomLengthOfRmSrcRom(Index)                      (PduR_GetRmSrcRomOfPCConfig()[(Index)].RmDestRomLengthOfRmSrcRom)
#define PduR_GetSrcHndOfRmSrcRom(Index)                               (PduR_GetRmSrcRomOfPCConfig()[(Index)].SrcHndOfRmSrcRom)
#define PduR_GetRmTransmitFctPtr(Index)                               (PduR_GetRmTransmitFctPtrOfPCConfig()[(Index)])
#define PduR_GetRmSrcRomIdxOfRxTp2Dest(Index)                         (PduR_GetRxTp2DestOfPCConfig()[(Index)].RmSrcRomIdxOfRxTp2Dest)
#define PduR_GetRmSrcRomIdxOfTx2Lo(Index)                             (PduR_GetTx2LoOfPCConfig()[(Index)].RmSrcRomIdxOfTx2Lo)
#define PduR_GetRmTransmitFctPtrIdxOfTx2Lo(Index)                     (PduR_GetTx2LoOfPCConfig()[(Index)].RmTransmitFctPtrIdxOfTx2Lo)
#define PduR_GetRmGDestRomIdxOfTxTp2Src(Index)                        (PduR_GetTxTp2SrcOfPCConfig()[(Index)].RmGDestRomIdxOfTxTp2Src)
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetBitDataMacros  PduR Get Bit Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read bitcoded data elements.
  \{
*/ 
#define PduR_IsUpTpOfMmRom(Index)                                     (PDUR_UPTPOFMMROM_MASK == (PduR_GetMaskedBitsOfMmRom(Index) & PDUR_UPTPOFMMROM_MASK))  /**< Is the module a upper transport protocol module. */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCGetDeduplicatedDataMacros  PduR Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define PduR_GetConfigId()                                            PduR_GetConfigIdOfPCConfig()
#define PduR_IsLoTpOfMmRom(Index)                                     (((!(PduR_IsUpTpOfMmRom(Index)))) != FALSE)  /**< Is the module a lower transport protocol module. */
#define PduR_GetDirectionOfRmDestRom(Index)                           ((PduR_DirectionOfRmDestRomType)((PduR_GetRoutingTypeOfRmDestRom(Index) - 0x04U)))  /**< Direction of this Pdu: Rx or Tx */
#define PduR_GetRmGDestRomIdxOfRmDestRom(Index)                       ((PduR_RmGDestRomIdxOfRmDestRomType)((Index)))  /**< the index of the 1:1 relation pointing to PduR_RmGDestRom */
#define PduR_GetRmSrcRomIdxOfRmDestRom(Index)                         ((PduR_RmSrcRomIdxOfRmDestRomType)((Index)))  /**< the index of the 1:1 relation pointing to PduR_RmSrcRom */
#define PduR_GetRmDestRomIdxOfRmGDestRom(Index)                       ((PduR_RmDestRomIdxOfRmGDestRomType)((Index)))  /**< the index of the 0:1 relation pointing to PduR_RmDestRom */
#define PduR_IsRmDestRomUsedOfRmGDestRom(Index)                       (((boolean)(PduR_GetRmDestRomIdxOfRmGDestRom(Index) != PDUR_NO_RMDESTROMIDXOFRMGDESTROM)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to PduR_RmDestRom */
#define PduR_GetRmDestRomEndIdxOfRmSrcRom(Index)                      ((PduR_RmDestRomEndIdxOfRmSrcRomType)(((Index) + 1U)))  /**< the end index of the 1:n relation pointing to PduR_RmDestRom */
#define PduR_GetRmDestRomStartIdxOfRmSrcRom(Index)                    ((PduR_RmDestRomStartIdxOfRmSrcRomType)((Index)))  /**< the start index of the 1:n relation pointing to PduR_RmDestRom */
#define PduR_IsRmSrcRomUsedOfRxTp2Dest(Index)                         (((boolean)(PduR_GetRmSrcRomIdxOfRxTp2Dest(Index) != PDUR_NO_RMSRCROMIDXOFRXTP2DEST)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to PduR_RmSrcRom */
#define PduR_GetSizeOfIfRoutingStateTable()                           PduR_GetSizeOfIfRoutingStateTableOfPCConfig()
#define PduR_GetSizeOfMmRom()                                         PduR_GetSizeOfMmRomOfPCConfig()
#define PduR_GetSizeOfRmDestRom()                                     PduR_GetSizeOfRmDestRomOfPCConfig()
#define PduR_GetSizeOfRmGDestRom()                                    PduR_GetSizeOfRmGDestRomOfPCConfig()
#define PduR_GetSizeOfRmSrcRom()                                      PduR_GetSizeOfRmSrcRomOfPCConfig()
#define PduR_GetSizeOfRmTransmitFctPtr()                              PduR_GetSizeOfRmTransmitFctPtrOfPCConfig()
#define PduR_GetSizeOfRxTp2Dest()                                     PduR_GetSizeOfRxTp2DestOfPCConfig()
#define PduR_GetSizeOfTx2Lo()                                         PduR_GetSizeOfTx2LoOfPCConfig()
#define PduR_GetSizeOfTxTp2Src()                                      PduR_GetSizeOfTxTp2SrcOfPCConfig()
#define PduR_IsRmSrcRomUsedOfTx2Lo(Index)                             (((boolean)(PduR_GetRmSrcRomIdxOfTx2Lo(Index) != PDUR_NO_RMSRCROMIDXOFTX2LO)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to PduR_RmSrcRom */
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCSetDataMacros  PduR Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define PduR_SetInitialized(Value)                                    (*(PduR_GetInitializedOfPCConfig())) = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  PduRPCHasMacros  PduR Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define PduR_HasConfigId()                                            (TRUE != FALSE)
#define PduR_HasIfRoutingStateTable()                                 (TRUE != FALSE)
#define PduR_HasNextState_For_Init_If_Routing_StateOfIfRoutingStateTable() (TRUE != FALSE)
#define PduR_HasNextState_For_Wait_For_RxIndicationOfIfRoutingStateTable() (TRUE != FALSE)
#define PduR_HasNextState_For_Wait_For_TriggerTransmitOfIfRoutingStateTable() (TRUE != FALSE)
#define PduR_HasNextState_For_Wait_For_TxConfirmationOfIfRoutingStateTable() (TRUE != FALSE)
#define PduR_HasInitialized()                                         (TRUE != FALSE)
#define PduR_HasMmRom()                                               (TRUE != FALSE)
#define PduR_HasLoTpOfMmRom()                                         (TRUE != FALSE)
#define PduR_HasLoTpTransmitFctPtrOfMmRom()                           (TRUE != FALSE)
#define PduR_HasMaskedBitsOfMmRom()                                   (TRUE != FALSE)
#define PduR_HasUpTpCopyRxDataFctPtrOfMmRom()                         (TRUE != FALSE)
#define PduR_HasUpTpCopyTxDataFctPtrOfMmRom()                         (TRUE != FALSE)
#define PduR_HasUpTpOfMmRom()                                         (TRUE != FALSE)
#define PduR_HasUpTpStartOfReceptionFctPtrOfMmRom()                   (TRUE != FALSE)
#define PduR_HasUpTpTpRxIndicationFctPtrOfMmRom()                     (TRUE != FALSE)
#define PduR_HasUpTpTpTxConfirmationFctPtrOfMmRom()                   (TRUE != FALSE)
#define PduR_HasRmDestRom()                                           (TRUE != FALSE)
#define PduR_HasDirectionOfRmDestRom()                                (TRUE != FALSE)
#define PduR_HasRmGDestRomIdxOfRmDestRom()                            (TRUE != FALSE)
#define PduR_HasRmSrcRomIdxOfRmDestRom()                              (TRUE != FALSE)
#define PduR_HasRoutingTypeOfRmDestRom()                              (TRUE != FALSE)
#define PduR_HasRmGDestRom()                                          (TRUE != FALSE)
#define PduR_HasDestHndOfRmGDestRom()                                 (TRUE != FALSE)
#define PduR_HasMmRomIdxOfRmGDestRom()                                (TRUE != FALSE)
#define PduR_HasPduRDestPduProcessingOfRmGDestRom()                   (TRUE != FALSE)
#define PduR_HasRmDestRomIdxOfRmGDestRom()                            (TRUE != FALSE)
#define PduR_HasRmDestRomUsedOfRmGDestRom()                           (TRUE != FALSE)
#define PduR_HasRmSrcRom()                                            (TRUE != FALSE)
#define PduR_HasMmRomIdxOfRmSrcRom()                                  (TRUE != FALSE)
#define PduR_HasRmDestRomEndIdxOfRmSrcRom()                           (TRUE != FALSE)
#define PduR_HasRmDestRomLengthOfRmSrcRom()                           (TRUE != FALSE)
#define PduR_HasRmDestRomStartIdxOfRmSrcRom()                         (TRUE != FALSE)
#define PduR_HasSrcHndOfRmSrcRom()                                    (TRUE != FALSE)
#define PduR_HasRmTransmitFctPtr()                                    (TRUE != FALSE)
#define PduR_HasRxTp2Dest()                                           (TRUE != FALSE)
#define PduR_HasRmSrcRomIdxOfRxTp2Dest()                              (TRUE != FALSE)
#define PduR_HasRmSrcRomUsedOfRxTp2Dest()                             (TRUE != FALSE)
#define PduR_HasSizeOfIfRoutingStateTable()                           (TRUE != FALSE)
#define PduR_HasSizeOfMmRom()                                         (TRUE != FALSE)
#define PduR_HasSizeOfRmDestRom()                                     (TRUE != FALSE)
#define PduR_HasSizeOfRmGDestRom()                                    (TRUE != FALSE)
#define PduR_HasSizeOfRmSrcRom()                                      (TRUE != FALSE)
#define PduR_HasSizeOfRmTransmitFctPtr()                              (TRUE != FALSE)
#define PduR_HasSizeOfRxTp2Dest()                                     (TRUE != FALSE)
#define PduR_HasSizeOfTx2Lo()                                         (TRUE != FALSE)
#define PduR_HasSizeOfTxTp2Src()                                      (TRUE != FALSE)
#define PduR_HasTx2Lo()                                               (TRUE != FALSE)
#define PduR_HasRmSrcRomIdxOfTx2Lo()                                  (TRUE != FALSE)
#define PduR_HasRmSrcRomUsedOfTx2Lo()                                 (TRUE != FALSE)
#define PduR_HasRmTransmitFctPtrIdxOfTx2Lo()                          (TRUE != FALSE)
#define PduR_HasTxTp2Src()                                            (TRUE != FALSE)
#define PduR_HasRmGDestRomIdxOfTxTp2Src()                             (TRUE != FALSE)
#define PduR_HasPCConfig()                                            (TRUE != FALSE)
#define PduR_HasConfigIdOfPCConfig()                                  (TRUE != FALSE)
#define PduR_HasIfRoutingStateTableOfPCConfig()                       (TRUE != FALSE)
#define PduR_HasInitializedOfPCConfig()                               (TRUE != FALSE)
#define PduR_HasMmRomOfPCConfig()                                     (TRUE != FALSE)
#define PduR_HasRmDestRomOfPCConfig()                                 (TRUE != FALSE)
#define PduR_HasRmGDestRomOfPCConfig()                                (TRUE != FALSE)
#define PduR_HasRmSrcRomOfPCConfig()                                  (TRUE != FALSE)
#define PduR_HasRmTransmitFctPtrOfPCConfig()                          (TRUE != FALSE)
#define PduR_HasRxTp2DestOfPCConfig()                                 (TRUE != FALSE)
#define PduR_HasSizeOfIfRoutingStateTableOfPCConfig()                 (TRUE != FALSE)
#define PduR_HasSizeOfMmRomOfPCConfig()                               (TRUE != FALSE)
#define PduR_HasSizeOfRmDestRomOfPCConfig()                           (TRUE != FALSE)
#define PduR_HasSizeOfRmGDestRomOfPCConfig()                          (TRUE != FALSE)
#define PduR_HasSizeOfRmSrcRomOfPCConfig()                            (TRUE != FALSE)
#define PduR_HasSizeOfRmTransmitFctPtrOfPCConfig()                    (TRUE != FALSE)
#define PduR_HasSizeOfRxTp2DestOfPCConfig()                           (TRUE != FALSE)
#define PduR_HasSizeOfTx2LoOfPCConfig()                               (TRUE != FALSE)
#define PduR_HasSizeOfTxTp2SrcOfPCConfig()                            (TRUE != FALSE)
#define PduR_HasTx2LoOfPCConfig()                                     (TRUE != FALSE)
#define PduR_HasTxTp2SrcOfPCConfig()                                  (TRUE != FALSE)
/** 
  \}
*/ 

  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* Communication Interface APIs */
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TransmitFctPtrType) (PduIdType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TriggerTransmitFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_IfRxIndicationType) (PduIdType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_IfTxConfirmationFctPtrType) (PduIdType);

/* Transport Protocol APIs */
typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_StartOfReceptionFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), PduLengthType, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyRxDataFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyTxDataFctPtrType) (PduIdType, P2VAR(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpRxIndicationFctPtrType) (PduIdType, Std_ReturnType);

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpTxConfirmationFctPtrType) (PduIdType, Std_ReturnType);


#if ((PDUR_IFCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON) || (PDUR_TPCANCELTRANSMITSUPPORTEDOFMMROM == STD_ON))
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_CancelTransmitFctPtrType)(PduIdType);
#endif
#if (PDUR_CANCELRECEIVESUPPORTEDOFMMROM == STD_ON)
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_CancelReceiveFctPtrType) (PduIdType);
#endif
#if (PDUR_CHANGEPARAMETERSUPPORTEDOFMMROM == STD_ON)
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_ChangeParameterFctPtrType) (PduIdType, TPParameterType, uint16);
#endif

typedef P2FUNC(void, PDUR_CODE, PduR_DisableRoutingFctPtrType) (PduR_RoutingPathGroupIdType);


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  PduRPCIterableTypes  PduR Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate PduR_IfRoutingStateTable */
typedef uint8_least PduR_IfRoutingStateTableIterType;

/**   \brief  type used to iterate PduR_MmRom */
typedef uint8_least PduR_MmRomIterType;

/**   \brief  type used to iterate PduR_RmDestRom */
typedef uint8_least PduR_RmDestRomIterType;

/**   \brief  type used to iterate PduR_RmGDestRom */
typedef uint8_least PduR_RmGDestRomIterType;

/**   \brief  type used to iterate PduR_RmSrcRom */
typedef uint8_least PduR_RmSrcRomIterType;

/**   \brief  type used to iterate PduR_RmTransmitFctPtr */
typedef uint8_least PduR_RmTransmitFctPtrIterType;

/**   \brief  type used to iterate PduR_RxTp2Dest */
typedef uint8_least PduR_RxTp2DestIterType;

/**   \brief  type used to iterate PduR_Tx2Lo */
typedef uint8_least PduR_Tx2LoIterType;

/**   \brief  type used to iterate PduR_TxTp2Src */
typedef uint8_least PduR_TxTp2SrcIterType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCValueTypes  PduR Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for PduR_ConfigId */
typedef uint8 PduR_ConfigIdType;

/**   \brief  value based type definition for PduR_NextState_For_Init_If_Routing_StateOfIfRoutingStateTable */
typedef uint8 PduR_NextState_For_Init_If_Routing_StateOfIfRoutingStateTableType;

/**   \brief  value based type definition for PduR_NextState_For_Wait_For_RxIndicationOfIfRoutingStateTable */
typedef uint8 PduR_NextState_For_Wait_For_RxIndicationOfIfRoutingStateTableType;

/**   \brief  value based type definition for PduR_NextState_For_Wait_For_TriggerTransmitOfIfRoutingStateTable */
typedef uint8 PduR_NextState_For_Wait_For_TriggerTransmitOfIfRoutingStateTableType;

/**   \brief  value based type definition for PduR_NextState_For_Wait_For_TxConfirmationOfIfRoutingStateTable */
typedef uint8 PduR_NextState_For_Wait_For_TxConfirmationOfIfRoutingStateTableType;

/**   \brief  value based type definition for PduR_Initialized */
typedef boolean PduR_InitializedType;

/**   \brief  value based type definition for PduR_LoTpOfMmRom */
typedef boolean PduR_LoTpOfMmRomType;

/**   \brief  value based type definition for PduR_MaskedBitsOfMmRom */
typedef uint8 PduR_MaskedBitsOfMmRomType;

/**   \brief  value based type definition for PduR_UpTpOfMmRom */
typedef boolean PduR_UpTpOfMmRomType;

/**   \brief  value based type definition for PduR_DirectionOfRmDestRom */
typedef uint8 PduR_DirectionOfRmDestRomType;

/**   \brief  value based type definition for PduR_RmGDestRomIdxOfRmDestRom */
typedef uint8 PduR_RmGDestRomIdxOfRmDestRomType;

/**   \brief  value based type definition for PduR_RmSrcRomIdxOfRmDestRom */
typedef uint8 PduR_RmSrcRomIdxOfRmDestRomType;

/**   \brief  value based type definition for PduR_RoutingTypeOfRmDestRom */
typedef uint8 PduR_RoutingTypeOfRmDestRomType;

/**   \brief  value based type definition for PduR_DestHndOfRmGDestRom */
typedef uint8 PduR_DestHndOfRmGDestRomType;

/**   \brief  value based type definition for PduR_MmRomIdxOfRmGDestRom */
typedef uint8 PduR_MmRomIdxOfRmGDestRomType;

/**   \brief  value based type definition for PduR_PduRDestPduProcessingOfRmGDestRom */
typedef uint8 PduR_PduRDestPduProcessingOfRmGDestRomType;

/**   \brief  value based type definition for PduR_RmDestRomIdxOfRmGDestRom */
typedef uint8 PduR_RmDestRomIdxOfRmGDestRomType;

/**   \brief  value based type definition for PduR_RmDestRomUsedOfRmGDestRom */
typedef boolean PduR_RmDestRomUsedOfRmGDestRomType;

/**   \brief  value based type definition for PduR_MmRomIdxOfRmSrcRom */
typedef uint8 PduR_MmRomIdxOfRmSrcRomType;

/**   \brief  value based type definition for PduR_RmDestRomEndIdxOfRmSrcRom */
typedef uint8 PduR_RmDestRomEndIdxOfRmSrcRomType;

/**   \brief  value based type definition for PduR_RmDestRomLengthOfRmSrcRom */
typedef uint8 PduR_RmDestRomLengthOfRmSrcRomType;

/**   \brief  value based type definition for PduR_RmDestRomStartIdxOfRmSrcRom */
typedef uint8 PduR_RmDestRomStartIdxOfRmSrcRomType;

/**   \brief  value based type definition for PduR_SrcHndOfRmSrcRom */
typedef uint8 PduR_SrcHndOfRmSrcRomType;

/**   \brief  value based type definition for PduR_RmSrcRomIdxOfRxTp2Dest */
typedef uint8 PduR_RmSrcRomIdxOfRxTp2DestType;

/**   \brief  value based type definition for PduR_RmSrcRomUsedOfRxTp2Dest */
typedef boolean PduR_RmSrcRomUsedOfRxTp2DestType;

/**   \brief  value based type definition for PduR_SizeOfIfRoutingStateTable */
typedef uint8 PduR_SizeOfIfRoutingStateTableType;

/**   \brief  value based type definition for PduR_SizeOfMmRom */
typedef uint8 PduR_SizeOfMmRomType;

/**   \brief  value based type definition for PduR_SizeOfRmDestRom */
typedef uint8 PduR_SizeOfRmDestRomType;

/**   \brief  value based type definition for PduR_SizeOfRmGDestRom */
typedef uint8 PduR_SizeOfRmGDestRomType;

/**   \brief  value based type definition for PduR_SizeOfRmSrcRom */
typedef uint8 PduR_SizeOfRmSrcRomType;

/**   \brief  value based type definition for PduR_SizeOfRmTransmitFctPtr */
typedef uint8 PduR_SizeOfRmTransmitFctPtrType;

/**   \brief  value based type definition for PduR_SizeOfRxTp2Dest */
typedef uint8 PduR_SizeOfRxTp2DestType;

/**   \brief  value based type definition for PduR_SizeOfTx2Lo */
typedef uint8 PduR_SizeOfTx2LoType;

/**   \brief  value based type definition for PduR_SizeOfTxTp2Src */
typedef uint8 PduR_SizeOfTxTp2SrcType;

/**   \brief  value based type definition for PduR_RmSrcRomIdxOfTx2Lo */
typedef uint8 PduR_RmSrcRomIdxOfTx2LoType;

/**   \brief  value based type definition for PduR_RmSrcRomUsedOfTx2Lo */
typedef boolean PduR_RmSrcRomUsedOfTx2LoType;

/**   \brief  value based type definition for PduR_RmTransmitFctPtrIdxOfTx2Lo */
typedef uint8 PduR_RmTransmitFctPtrIdxOfTx2LoType;

/**   \brief  value based type definition for PduR_RmGDestRomIdxOfTxTp2Src */
typedef uint8 PduR_RmGDestRomIdxOfTxTp2SrcType;

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

#if(PDUR_RMSRCROM == STD_ON)
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_RmTransmitFctPtrType) (PduR_RmSrcRomIterType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));
#endif
#if(PDUR_RMDESTROM == STD_ON)
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_RmIfRxIndicationType) (PduR_RmDestRomIterType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));
#endif

#if(PDUR_FMFIFORAM == STD_ON)
typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_StartOfReceptionFifoSmFctPtrType) (PduR_RmSrcRomIterType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA), PduLengthType, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyRxDataFifoSmFctPtrType) (PduR_RmSrcRomIterType, PduLengthType, SduDataPtrType, P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpRxIndicationFifoSmFctPtrType) (PduR_RmSrcRomIterType, Std_ReturnType);
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpCancelReceiveFctPtrType) (PduR_RmSrcRomIterType);

typedef P2FUNC(BufReq_ReturnType, PDUR_APPL_CODE, PduR_CopyTxDataFifoSmFctPtrType) (PduR_RmGDestRomIterType, PduLengthType, SduDataPtrType, P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA), P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TpTriggerTransmitFctPtrType) (PduR_RmDestRomIterType);
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_TpTxConfirmationFifoSmFctPtrType) (PduR_RmGDestRomIterType, Std_ReturnType);
typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_TpCancelTransmitFctPtrType)(PduR_RmDestRomIterType);
typedef P2FUNC(void, PDUR_CODE, PduR_TpDisableRoutingFctPtrType) (PduR_RmGDestRomIterType);

typedef P2FUNC(Std_ReturnType, PDUR_APPL_CODE, PduR_CheckReady2TransmitFctPtrType) (PduR_RmSrcRomIterType);

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_FinishReceptionFctPtrType) (PduR_RmSrcRomIterType, Std_ReturnType);

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_FinishTransmissionFctPtrType) (PduR_RmSrcRomIterType, Std_ReturnType);

typedef P2FUNC(void, PDUR_APPL_CODE, PduR_ActivateNextFctPtrType) (PduR_FmFifoElementRamIterType, Std_ReturnType);
#endif

#if(PDUR_FINISHREADFMSMTRANSITION  == STD_ON)
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_FinishReadFctPtrType) (PduR_FmFifoElementRamIterType, Std_ReturnType);
#endif
#if (PDUR_FINISHWRITEFMSMTRANSITION  == STD_ON)
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_FinishWriteFctPtrType) (PduR_FmFifoElementRamIterType, Std_ReturnType);
#endif
#if (PDUR_TPACTIVATEREADFIFOSMTRANSITION == STD_ON)
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_ActivateReadFctPtrType) (PduR_FmFifoElementRamIterType);
#endif
#if (PDUR_TPACTIVATEWRITEFIFOSMTRANSITION == STD_ON)
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_ActivateWriteFctPtrType) (PduR_FmFifoElementRamIterType);
#endif

#if (PDUR_FMFLUSHFIFOELEMENT == STD_ON)
typedef P2FUNC(void, PDUR_APPL_CODE, PduR_Fm_FlushFiFoElementPtrType) (PduR_FmFifoElementRamIterType);
#endif

#if(PDUR_SMDATAPLANEROM == STD_ON)
typedef uint8 PduR_FilterReturnType;
# define PDUR_FILTER_PASS  0u
# define PDUR_FILTER_BLOCK 1u

typedef uint32 PduR_SmSaType;
typedef uint32 PduR_SmTaType;

#define PDUR_SM_UNLEARNED_CONNECTION 0u
typedef P2FUNC(PduR_SmSaType, PDUR_CODE, PduR_Sm_LinearTaToSaCalculationStrategy_GetSaFctPtrType) (PduR_SmLinearTaToSaCalculationStrategyRomIterType, uint32);
typedef P2FUNC(void, PDUR_CODE, PduR_Sm_SrcFilterFctPtrType) (PduR_SmSrcRomIdxOfRmSrcRomType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));
typedef P2FUNC(PduR_FilterReturnType, PDUR_CODE, PduR_Sm_DestFilterFctPtrType) (PduR_SmGDestRomIdxOfRmGDestRomType, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA));
#endif

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  PduRPCStructTypes  PduR Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in PduR_IfRoutingStateTable */
typedef struct sPduR_IfRoutingStateTableType
{
  PduR_NextState_For_Init_If_Routing_StateOfIfRoutingStateTableType NextState_For_Init_If_Routing_StateOfIfRoutingStateTable;
  PduR_NextState_For_Wait_For_RxIndicationOfIfRoutingStateTableType NextState_For_Wait_For_RxIndicationOfIfRoutingStateTable;
  PduR_NextState_For_Wait_For_TriggerTransmitOfIfRoutingStateTableType NextState_For_Wait_For_TriggerTransmitOfIfRoutingStateTable;
  PduR_NextState_For_Wait_For_TxConfirmationOfIfRoutingStateTableType NextState_For_Wait_For_TxConfirmationOfIfRoutingStateTable;
} PduR_IfRoutingStateTableType;

/**   \brief  type used in PduR_MmRom */
typedef struct sPduR_MmRomType
{
  PduR_MaskedBitsOfMmRomType MaskedBitsOfMmRom;  /**< contains bitcoded the boolean data of PduR_LoTpOfMmRom, PduR_UpTpOfMmRom */
  PduR_CopyRxDataFctPtrType UpTpCopyRxDataFctPtrOfMmRom;  /**< Transport protocol CopyRxData function pointers */
  PduR_CopyTxDataFctPtrType UpTpCopyTxDataFctPtrOfMmRom;  /**< Transport protocol CopyTxData function pointers */
  PduR_StartOfReceptionFctPtrType UpTpStartOfReceptionFctPtrOfMmRom;  /**< Transport protocol StartOfReception function pointers */
  PduR_TpRxIndicationFctPtrType UpTpTpRxIndicationFctPtrOfMmRom;  /**< Transport protocol TpRxIndication function pointers */
  PduR_TpTxConfirmationFctPtrType UpTpTpTxConfirmationFctPtrOfMmRom;  /**< Transport protocol TpTxConfimation function pointers */
  PduR_TransmitFctPtrType LoTpTransmitFctPtrOfMmRom;  /**< Lower layer Tp transmit function pointers */
} PduR_MmRomType;

/**   \brief  type used in PduR_RmDestRom */
typedef struct sPduR_RmDestRomType
{
  PduR_RoutingTypeOfRmDestRomType RoutingTypeOfRmDestRom;  /**< Type of the Routing (API Forwarding, Gateway). */
} PduR_RmDestRomType;

/**   \brief  type used in PduR_RmGDestRom */
typedef struct sPduR_RmGDestRomType
{
  PduR_DestHndOfRmGDestRomType DestHndOfRmGDestRom;  /**< handle to be used as parameter for the StartOfReception, CopyRxData, Transmit or RxIndication function call. */
  PduR_MmRomIdxOfRmGDestRomType MmRomIdxOfRmGDestRom;  /**< the index of the 1:1 relation pointing to PduR_MmRom */
  PduR_PduRDestPduProcessingOfRmGDestRomType PduRDestPduProcessingOfRmGDestRom;  /**< Is Processing Type of destination PDU. */
} PduR_RmGDestRomType;

/**   \brief  type used in PduR_RmSrcRom */
typedef struct sPduR_RmSrcRomType
{
  PduR_MmRomIdxOfRmSrcRomType MmRomIdxOfRmSrcRom;  /**< the index of the 1:1 relation pointing to PduR_MmRom */
  PduR_RmDestRomLengthOfRmSrcRomType RmDestRomLengthOfRmSrcRom;  /**< the number of relations pointing to PduR_RmDestRom */
  PduR_SrcHndOfRmSrcRomType SrcHndOfRmSrcRom;  /**< handle to be used as parameter for the TxConfirmation or TriggerTransmit function call. */
} PduR_RmSrcRomType;

/**   \brief  type used in PduR_RxTp2Dest */
typedef struct sPduR_RxTp2DestType
{
  PduR_RmSrcRomIdxOfRxTp2DestType RmSrcRomIdxOfRxTp2Dest;  /**< the index of the 0:1 relation pointing to PduR_RmSrcRom */
} PduR_RxTp2DestType;

/**   \brief  type used in PduR_Tx2Lo */
typedef struct sPduR_Tx2LoType
{
  PduR_RmSrcRomIdxOfTx2LoType RmSrcRomIdxOfTx2Lo;  /**< the index of the 0:1 relation pointing to PduR_RmSrcRom */
  PduR_RmTransmitFctPtrIdxOfTx2LoType RmTransmitFctPtrIdxOfTx2Lo;  /**< the index of the 1:1 relation pointing to PduR_RmTransmitFctPtr */
} PduR_Tx2LoType;

/**   \brief  type used in PduR_TxTp2Src */
typedef struct sPduR_TxTp2SrcType
{
  PduR_RmGDestRomIdxOfTxTp2SrcType RmGDestRomIdxOfTxTp2Src;  /**< the index of the 1:1 relation pointing to PduR_RmGDestRom */
} PduR_TxTp2SrcType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCRootPointerTypes  PduR Root Pointer Types (PRE_COMPILE)
  \brief  These type definitions are used to point from the config root to symbol instances.
  \{
*/ 
/**   \brief  type used to point to PduR_IfRoutingStateTable */
typedef P2CONST(PduR_IfRoutingStateTableType, TYPEDEF, PDUR_CONST) PduR_IfRoutingStateTablePtrType;

/**   \brief  type used to point to PduR_Initialized */
typedef P2VAR(PduR_InitializedType, TYPEDEF, PDUR_VAR_ZERO_INIT) PduR_InitializedPtrType;

/**   \brief  type used to point to PduR_MmRom */
typedef P2CONST(PduR_MmRomType, TYPEDEF, PDUR_CONST) PduR_MmRomPtrType;

/**   \brief  type used to point to PduR_RmDestRom */
typedef P2CONST(PduR_RmDestRomType, TYPEDEF, PDUR_CONST) PduR_RmDestRomPtrType;

/**   \brief  type used to point to PduR_RmGDestRom */
typedef P2CONST(PduR_RmGDestRomType, TYPEDEF, PDUR_CONST) PduR_RmGDestRomPtrType;

/**   \brief  type used to point to PduR_RmSrcRom */
typedef P2CONST(PduR_RmSrcRomType, TYPEDEF, PDUR_CONST) PduR_RmSrcRomPtrType;

/**   \brief  type used to point to PduR_RmTransmitFctPtr */
typedef P2CONST(PduR_RmTransmitFctPtrType, TYPEDEF, PDUR_CONST) PduR_RmTransmitFctPtrPtrType;

/**   \brief  type used to point to PduR_RxTp2Dest */
typedef P2CONST(PduR_RxTp2DestType, TYPEDEF, PDUR_CONST) PduR_RxTp2DestPtrType;

/**   \brief  type used to point to PduR_Tx2Lo */
typedef P2CONST(PduR_Tx2LoType, TYPEDEF, PDUR_CONST) PduR_Tx2LoPtrType;

/**   \brief  type used to point to PduR_TxTp2Src */
typedef P2CONST(PduR_TxTp2SrcType, TYPEDEF, PDUR_CONST) PduR_TxTp2SrcPtrType;

/** 
  \}
*/ 

/** 
  \defgroup  PduRPCRootValueTypes  PduR Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in PduR_PCConfig */
typedef struct sPduR_PCConfigType
{
  uint8 PduR_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} PduR_PCConfigType;

typedef PduR_PCConfigType PduR_PBConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
 * GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
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
extern CONST(PduR_IfRoutingStateTableType, PDUR_CONST) PduR_IfRoutingStateTable[4];
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
extern CONST(PduR_MmRomType, PDUR_CONST) PduR_MmRom[2];
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
extern CONST(PduR_RmDestRomType, PDUR_CONST) PduR_RmDestRom[6];
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
extern CONST(PduR_RmGDestRomType, PDUR_CONST) PduR_RmGDestRom[6];
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
extern CONST(PduR_RmSrcRomType, PDUR_CONST) PduR_RmSrcRom[6];
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
extern CONST(PduR_RmTransmitFctPtrType, PDUR_CONST) PduR_RmTransmitFctPtr[1];
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
extern CONST(PduR_RxTp2DestType, PDUR_CONST) PduR_RxTp2Dest[4];
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
extern CONST(PduR_Tx2LoType, PDUR_CONST) PduR_Tx2Lo[2];
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
extern CONST(PduR_TxTp2SrcType, PDUR_CONST) PduR_TxTp2Src[2];
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
extern VAR(PduR_InitializedType, PDUR_VAR_ZERO_INIT) PduR_Initialized;
#define PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


#define PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_19.1 */

#if(PDUR_USE_INIT_POINTER == STD_ON)
extern P2CONST(PduR_PBConfigType, PDUR_VAR_ZERO_INIT, PDUR_PBCFG) PduR_ConfigDataPtr;
#endif

#define PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 * LOCAL GEN FUNCTION PROTOTYPES
 *********************************************************************************************************************/
# ifdef PDUR_SOURCE
#if(PDUR_RECEPTIONINDICATIONQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_ReceptionIndicationQueueInit
 *********************************************************************************************************************/
/*! \brief   Initializes the queue parameters
 *  \details -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_ReceptionIndicationQueueInit(void);
#endif

#if(PDUR_RECEPTIONINDICATIONQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_IsReceptionIndicationQueueFull
 *********************************************************************************************************************/
/*! \brief   Checks if the queue is full
 *  \details -
 *  \return  TRUE  - If the queue is full
 *            FALSE - If the queue is not full
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, PDUR_CODE) PduR_IsReceptionIndicationQueueFull(void);
#endif

#if(PDUR_RECEPTIONINDICATIONQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_IsReceptionIndicationQueueEmpty
 *********************************************************************************************************************/
/*! \brief   Checks if the queue is empty
 *  \details -
 *  \return  TRUE  - If the queue is empty
 *            FALSE - If the queue is not empty
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, PDUR_CODE) PduR_IsReceptionIndicationQueueEmpty(void);
#endif

#if(PDUR_RECEPTIONINDICATIONQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_ReceptionIndicationQueueWriteIdxIncrement
 *********************************************************************************************************************/
/*! \brief   Increments the queue write index
 *  \details -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_ReceptionIndicationQueueWriteIdxIncrement(void);
#endif

#if(PDUR_RECEPTIONINDICATIONQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_ReceptionIndicationQueueReadIdxIncrement
 *********************************************************************************************************************/
/*! \brief   Increments the queue read index
 *  \details -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_ReceptionIndicationQueueReadIdxIncrement(void);
#endif

#if(PDUR_TRANSMITREQUESTQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_TransmitRequestQueueInit
 *********************************************************************************************************************/
/*! \brief   Initializes the queue parameters
 *  \details -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_TransmitRequestQueueInit(void);
#endif

#if(PDUR_TRANSMITREQUESTQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_IsTransmitRequestQueueFull
 *********************************************************************************************************************/
/*! \brief   Checks if the queue is full
 *  \details -
 *  \return  TRUE  - If the queue is full
 *            FALSE - If the queue is not full
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, PDUR_CODE) PduR_IsTransmitRequestQueueFull(void);
#endif

#if(PDUR_TRANSMITREQUESTQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_IsTransmitRequestQueueEmpty
 *********************************************************************************************************************/
/*! \brief   Checks if the queue is empty
 *  \details -
 *  \return  TRUE  - If the queue is empty
 *            FALSE - If the queue is not empty
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, PDUR_CODE) PduR_IsTransmitRequestQueueEmpty(void);
#endif

#if(PDUR_TRANSMITREQUESTQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_TransmitRequestQueueWriteIdxIncrement
 *********************************************************************************************************************/
/*! \brief   Increments the queue write index
 *  \details -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_TransmitRequestQueueWriteIdxIncrement(void);
#endif

#if(PDUR_TRANSMITREQUESTQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_TransmitRequestQueueReadIdxIncrement
 *********************************************************************************************************************/
/*! \brief   Increments the queue read index
 *  \details -
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_TransmitRequestQueueReadIdxIncrement(void);
#endif


# endif

/**********************************************************************************************************************
 * LOCAL GEN FUNCTIONS
 *********************************************************************************************************************/
# ifdef PDUR_SOURCE
#if(PDUR_RECEPTIONINDICATIONQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_ReceptionIndicationQueueInit
 *********************************************************************************************************************/
/*!
 * \internal
 * - Initialize read and write index
 * \endinternal
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_ReceptionIndicationQueueInit(void)
{
  PduR_SetReceptionIndicationQueueReadIdx(0); /* SBSW_PDUR_CSL_VAR_ACCESS */
  PduR_SetReceptionIndicationQueueWriteIdx(0); /* SBSW_PDUR_CSL_VAR_ACCESS */
}
#endif

#if(PDUR_RECEPTIONINDICATIONQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_IsReceptionIndicationQueueFull
 *********************************************************************************************************************/
/*!
 * \internal
 * - return true if the queue is full
 * \endinternal
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, PDUR_CODE) PduR_IsReceptionIndicationQueueFull(void)
{
  boolean ret = FALSE;
  if(PduR_GetReceptionIndicationQueueReadIdx() == ((PduR_GetReceptionIndicationQueueWriteIdx() + 1) % PduR_GetSizeOfReceptionIndicationQueue()))
  {
    ret = TRUE;
  }
  return ret;
}
#endif

#if(PDUR_RECEPTIONINDICATIONQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_IsReceptionIndicationQueueEmpty
 *********************************************************************************************************************/
/*!
 * \internal
 * - return true if the queue is empty
 * \endinternal
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, PDUR_CODE) PduR_IsReceptionIndicationQueueEmpty(void)
{
  boolean ret = FALSE;
  if(PduR_GetReceptionIndicationQueueReadIdx() == PduR_GetReceptionIndicationQueueWriteIdx())
  {
    ret = TRUE;
  }
  return ret;
}
#endif

#if(PDUR_RECEPTIONINDICATIONQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_ReceptionIndicationQueueWriteIdxIncrement
 *********************************************************************************************************************/
/*!
 * \internal
 * - increment the write index
 * \endinternal
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_ReceptionIndicationQueueWriteIdxIncrement(void)
{
  PduR_SetReceptionIndicationQueueWriteIdx((PduR_GetReceptionIndicationQueueWriteIdx() + 1) % PduR_GetSizeOfReceptionIndicationQueue()); /* SBSW_PDUR_CSL_VAR_ACCESS */
}
#endif

#if(PDUR_RECEPTIONINDICATIONQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_ReceptionIndicationQueueReadIdxIncrement
 *********************************************************************************************************************/
/*!
 * \internal
 * - increment the read index
 * \endinternal
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_ReceptionIndicationQueueReadIdxIncrement(void)
{
  PduR_SetReceptionIndicationQueueReadIdx((PduR_GetReceptionIndicationQueueReadIdx() + 1) % PduR_GetSizeOfReceptionIndicationQueue()); /* SBSW_PDUR_CSL_VAR_ACCESS */
}
#endif

#if(PDUR_TRANSMITREQUESTQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_TransmitRequestQueueInit
 *********************************************************************************************************************/
/*!
 * \internal
 * - Initialize read and write index
 * \endinternal
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_TransmitRequestQueueInit(void)
{
  PduR_SetTransmitRequestQueueReadIdx(0); /* SBSW_PDUR_CSL_VAR_ACCESS */
  PduR_SetTransmitRequestQueueWriteIdx(0); /* SBSW_PDUR_CSL_VAR_ACCESS */
}
#endif

#if(PDUR_TRANSMITREQUESTQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_IsTransmitRequestQueueFull
 *********************************************************************************************************************/
/*!
 * \internal
 * - return true if the queue is full
 * \endinternal
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, PDUR_CODE) PduR_IsTransmitRequestQueueFull(void)
{
  boolean ret = FALSE;
  if(PduR_GetTransmitRequestQueueReadIdx() == ((PduR_GetTransmitRequestQueueWriteIdx() + 1) % PduR_GetSizeOfTransmitRequestQueue()))
  {
    ret = TRUE;
  }
  return ret;
}
#endif

#if(PDUR_TRANSMITREQUESTQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_IsTransmitRequestQueueEmpty
 *********************************************************************************************************************/
/*!
 * \internal
 * - return true if the queue is empty
 * \endinternal
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(boolean, PDUR_CODE) PduR_IsTransmitRequestQueueEmpty(void)
{
  boolean ret = FALSE;
  if(PduR_GetTransmitRequestQueueReadIdx() == PduR_GetTransmitRequestQueueWriteIdx())
  {
    ret = TRUE;
  }
  return ret;
}
#endif

#if(PDUR_TRANSMITREQUESTQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_TransmitRequestQueueWriteIdxIncrement
 *********************************************************************************************************************/
/*!
 * \internal
 * - increment the write index
 * \endinternal
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_TransmitRequestQueueWriteIdxIncrement(void)
{
  PduR_SetTransmitRequestQueueWriteIdx((PduR_GetTransmitRequestQueueWriteIdx() + 1) % PduR_GetSizeOfTransmitRequestQueue()); /* SBSW_PDUR_CSL_VAR_ACCESS */
}
#endif

#if(PDUR_TRANSMITREQUESTQUEUE == STD_ON)
/**********************************************************************************************************************
 * PduR_TransmitRequestQueueReadIdxIncrement
 *********************************************************************************************************************/
/*!
 * \internal
 * - increment the read index
 * \endinternal
 *********************************************************************************************************************/
LOCAL_INLINE FUNC(void, PDUR_CODE) PduR_TransmitRequestQueueReadIdxIncrement(void)
{
  PduR_SetTransmitRequestQueueReadIdx((PduR_GetTransmitRequestQueueReadIdx() + 1) % PduR_GetSizeOfTransmitRequestQueue()); /* SBSW_PDUR_CSL_VAR_ACCESS */
}
#endif


# endif

#endif  /* PDUR_LCFG_H */
/**********************************************************************************************************************
 * END OF FILE: PduR_Lcfg.h
 *********************************************************************************************************************/

