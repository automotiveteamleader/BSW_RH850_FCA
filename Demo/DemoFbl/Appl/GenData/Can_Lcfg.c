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
 *            Module: Can
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701374A
 *    License Scope : The usage is restricted to CBD1800284_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Can_Lcfg.c
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


#define CAN_LCFG_SOURCE

/* PRQA S 0857 EOF */ /* MD_Can_0857 */
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */

/* -----------------------------------------------------------------------------
    Includes
 ----------------------------------------------------------------------------- */

#include "Can_Cfg.h"

/* -----------------------------------------------------------------------------
    Hw specific
 ----------------------------------------------------------------------------- */

/* HW specific CT global C file */

/* !HW specific CT global C file */


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
  Can_BTP
**********************************************************************************************************************/
/** 
  \var    Can_BTP
  \brief  Bit Timing and Prescaler
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_BTPType, CAN_CONST) Can_BTP[1] = {
  /* Index    BTP               Comment */
  /*     0 */ 0x00090100UL   /* [CT_DemoFBL_Fca_SLP5_01db1962 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_BufferConfig
**********************************************************************************************************************/
/** 
  \var    Can_BufferConfig
  \brief  CAN Buffer Configuration
  \details
  Element    Description
  RXBC   
  RXF0C  
  RXF1C  
  TXBC   
  TXEFC  
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_BufferConfigType, CAN_CONST) Can_BufferConfig[1] = {
    /* Index    RXBC          RXF0C         RXF1C         TXBC          TXEFC               Comment */
  { /*     0 */ 0x00000000UL, 0x00060008UL, 0x00000000UL, 0x000101B8UL, 0x00000000UL }   /* [CT_DemoFBL_Fca_SLP5_01db1962] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_CanIfChannelId
**********************************************************************************************************************/
/** 
  \var    Can_CanIfChannelId
  \brief  indirection table Can to CanIf controller ID
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_CanIfChannelIdType, CAN_CONST) Can_CanIfChannelId[1] = {
  /* Index    CanIfChannelId      Comment */
  /*     0 */             0U   /* [CT_DemoFBL_Fca_SLP5_01db1962] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_ControllerConfig
**********************************************************************************************************************/
/** 
  \var    Can_ControllerConfig
  \brief  Global configuration for all controllers
  \details
  Element                         Description
  BasisAdr                        CAN channel base address
  CanControllerDefaultBaudrate
  MailboxRxBasicEndIdx            the end index of the 0:n relation pointing to Can_Mailbox
  MailboxRxBasicLength            the number of relations pointing to Can_Mailbox
  MailboxRxBasicStartIdx          the start index of the 0:n relation pointing to Can_Mailbox
  MailboxTxBasicEndIdx            the end index of the 0:n relation pointing to Can_Mailbox
  MailboxTxBasicLength            the number of relations pointing to Can_Mailbox
  MailboxTxBasicStartIdx          the start index of the 0:n relation pointing to Can_Mailbox
  MailboxUnusedEndIdx             the end index of the 0:n relation pointing to Can_Mailbox
  MailboxUnusedLength             the number of relations pointing to Can_Mailbox
  MailboxUnusedStartIdx           the start index of the 0:n relation pointing to Can_Mailbox
  IsTTCan                         TTCAN channel support
  RxBasicHwStart              
  RxBasicHwStop               
  RxFullHwStart               
  RxFullHwStop                
  TxBasicHwStart              
  TxBasicHwStop               
  TxFullHwStart               
  TxFullHwStop                
  UnusedHwStart               
  UnusedHwStop                
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_ControllerConfigType, CAN_CONST) Can_ControllerConfig[1] = {
    /* Index    BasisAdr      CanControllerDefaultBaudrate  MailboxRxBasicEndIdx                                                                                                                                                      MailboxRxBasicLength                                                                                                                                                      MailboxRxBasicStartIdx                                                                                                                                                      MailboxTxBasicEndIdx                                                                                                                                                      MailboxTxBasicLength                                                                                                                                                      MailboxTxBasicStartIdx                                                                                                                                                      MailboxUnusedEndIdx                                                                                                                                                     MailboxUnusedLength                                                                                                                                                     MailboxUnusedStartIdx                                                                                                                                                     IsTTCan  RxBasicHwStart  RxBasicHwStop  RxFullHwStart  RxFullHwStop  TxBasicHwStart  TxBasicHwStop  TxFullHwStart  TxFullHwStop  UnusedHwStart  UnusedHwStop        Comment                                    Referable Keys */
  { /*     0 */ 0xFFEF0000UL,                         500U,                   2U  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   1U  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                     1U  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   1U  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   1U  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                     0U  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  4U  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  2U  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                    2U  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,   FALSE,            96U,           97U,           32U,          32U,             0U,            1U,            0U,           0U,            0U,           0U }   /* [CT_DemoFBL_Fca_SLP5_01db1962] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_FBTP
**********************************************************************************************************************/
/** 
  \var    Can_FBTP
  \brief  Fast Bit Timing and Prescaler
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_FBTPType, CAN_CONST) Can_FBTP[1] = {
  /* Index    FBTP              Comment */
  /*     0 */ 0x00040100UL   /* [CT_DemoFBL_Fca_SLP5_01db1962 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_GFC
**********************************************************************************************************************/
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_GFCType, CAN_CONST) Can_GFC[1] = {
  /* Index    GFC               Comment */
  /*     0 */ 0x0000003FUL   /* [CT_DemoFBL_Fca_SLP5_01db1962] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectBaudrate
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectBaudrate
  \brief  baudrates ('InitStruct' as index)
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_InitObjectBaudrateType, CAN_CONST) Can_InitObjectBaudrate[1] = {
  /* Index    InitObjectBaudrate      Comment */
  /*     0 */               500U   /* [CT_DemoFBL_Fca_SLP5_01db1962 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectFdBrsConfig
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectFdBrsConfig
  \brief  FD config ('BaudrateObject' as index)
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_InitObjectFdBrsConfigType, CAN_CONST) Can_InitObjectFdBrsConfig[1] = {
  /* Index    InitObjectFdBrsConfig              */
  /*     0 */ CAN_FD_RXTX_INITOBJECTFDBRSCONFIG
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectStartIndex
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectStartIndex
  \brief  Start index of 'InitStruct' / baudratesets (controllers as index)
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_InitObjectStartIndexType, CAN_CONST) Can_InitObjectStartIndex[2] = {
  /* Index    InitObjectStartIndex      Comment */
  /*     0 */                   0U,  /* [CT_DemoFBL_Fca_SLP5_01db1962] */
  /*     1 */                   1U   /* [stop index] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_Mailbox
**********************************************************************************************************************/
/** 
  \var    Can_Mailbox
  \brief  mailbox configuration (over all controllers)
  \details
  Element                Description
  IDValue            
  ControllerConfigIdx    the index of the 1:1 relation pointing to Can_ControllerConfig
  DLC_FIFO           
  FdPadding          
  HwHandle           
  MailboxType        
  MaxDataLen         
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_MailboxType, CAN_CONST) Can_Mailbox[4] = {
    /* Index    IDValue       ControllerConfigIdx                                                                   DLC_FIFO  FdPadding  HwHandle  MailboxType                                MaxDataLen        Comment                                           Referable Keys */
  { /*     0 */ 0x00000000UL,                  0U  /* /ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 */,       1U,        0U,       0U, CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64U },  /* [CN_DemoFBL_Fca_SLP5_01db1962_Tx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CN_DemoFBL_Fca_SLP5_01db1962_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962, TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*     1 */ 0x00000000UL,                  0U  /* /ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 */,       1U,        0U,      96U, CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64U },  /* [CN_DemoFBL_Fca_SLP5_01db1962_Rx_Ext] */  /* [/ActiveEcuC/Can/CanConfigSet/CN_DemoFBL_Fca_SLP5_01db1962_Rx_Ext (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962, RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*     2 */ 0x00000000UL,                  0U  /* /ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 */,      95U,        0U,       1U,  CAN_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX,         0U },  /* []                                    */  /* [undefined, /ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962, UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*     3 */ 0x00000000UL,                  0U  /* /ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 */,       1U,        0U,      97U,  CAN_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX,         0U }   /* []                                    */  /* [undefined, /ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962, UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_SIDFC
**********************************************************************************************************************/
/** 
  \var    Can_SIDFC
  \brief  Standard ID filter configuration
  \details
  Element    Description
  FLSSA      Filter List Standard Start Address
  LSS        List size standard
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_SIDFCType, CAN_CONST) Can_SIDFC[1] = {
    /* Index    FLSSA    LSS          Comment */
  { /*     0 */ 0x0000U, 0x00U }   /* [CT_DemoFBL_Fca_SLP5_01db1962] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_SIDFE
**********************************************************************************************************************/
/** 
  \var    Can_SIDFE
  \brief  Standard ID filters
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_SIDFEType, CAN_CONST) Can_SIDFE[1] = {
  /* Index    SIDFE         */
  /*     0 */ 0x00000000UL
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_ShmAdr
**********************************************************************************************************************/
/** 
  \var    Can_ShmAdr
  \brief  CAN Shared Message RAM configuration
  \details
  Element     Description
  RXBA        RX Buffer Address
  RXF0A       RX FIFO0 Address
  RXF1A       RX FIFO1 Address
  SIDFA       Standard Filters Address
  StartAdr    Start address of the shared memory area
  StopAdr     Stop address of the shared memory area
  TXBA        TX Buffer address
  TXEFA       TX Event FIFO address
  XIDFA       Extended Filters Address
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_ShmAdrType, CAN_CONST) Can_ShmAdr[1] = {
    /* Index    RXBA                            RXF0A                             RXF1A                           SIDFA                           StartAdr      StopAdr       TXBA                             TXEFA                           XIDFA                                 Comment */
  { /*     0 */ 0xFFEF8000UL  /* Size[B]: 0 */, 0xFFEF8008UL  /* Size[B]: 432 */, 0xFFEF8000UL  /* Size[B]: 0 */, 0xFFEF8000UL  /* Size[B]: 0 */, 0xFFEF8000UL, 0xFFEF8201UL, 0xFFEF81B8UL  /* Size[B]: 72 */, 0xFFEF8000UL  /* Size[B]: 0 */, 0xFFEF8000UL  /* Size[B]: 8 */ }   /* [CT_DemoFBL_Fca_SLP5_01db1962] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_ShmElementSize
**********************************************************************************************************************/
/** 
  \var    Can_ShmElementSize
  \brief  data buffer size in case of CAN_FD Full
  \details
  Element    Description
  F0DS   
  F1DS   
  RBDS   
  TBDS   
  TEFBDS 
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_ShmElementSizeType, CAN_CONST) Can_ShmElementSize[1] = {
    /* Index    F0DS                  F1DS                 RBDS                  TBDS                  TEFBDS                        Comment */
  { /*     0 */ 0x07U  /* F0DS 64 */, 0x00U  /* F1DS 8 */, 0x07U  /* RBDS 64 */, 0x07U  /* TBDS 64 */,  0x00U  /* EFTBDS 8 */ }   /* [CT_DemoFBL_Fca_SLP5_01db1962] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_TDCR
**********************************************************************************************************************/
/** 
  \var    Can_TDCR
  \brief  Transmitter Delay Compensation
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_TDCRType, CAN_CONST) Can_TDCR[1] = {
  /* Index    TDCR              Comment */
  /*     0 */ 0x00000000UL   /* [CT_DemoFBL_Fca_SLP5_01db1962 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_TxOffsetHwToLog
**********************************************************************************************************************/
/** 
  \var    Can_TxOffsetHwToLog
  \brief  tx hardware to logical handle indirection table
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_TxOffsetHwToLogType, CAN_CONST) Can_TxOffsetHwToLog[1] = {
  /* Index    TxOffsetHwToLog      Comment */
  /*     0 */               0   /* [CT_DemoFBL_Fca_SLP5_01db1962] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_XIDAM
**********************************************************************************************************************/
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_XIDAMType, CAN_CONST) Can_XIDAM[1] = {
  /* Index    XIDAM             Comment */
  /*     0 */ 0x1FFFFFFFUL   /* [CT_DemoFBL_Fca_SLP5_01db1962] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_XIDFC
**********************************************************************************************************************/
/** 
  \var    Can_XIDFC
  \brief  Extended ID filter configuration
  \details
  Element          Description
  FLESA            Filter List Extended Start Address
  XIDFEEndIdx      the end index of the 0:n relation pointing to Can_XIDFE
  XIDFEStartIdx    the start index of the 0:n relation pointing to Can_XIDFE
  LSE              List size extended
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_XIDFCType, CAN_CONST) Can_XIDFC[1] = {
    /* Index    FLESA    XIDFEEndIdx                                                                   XIDFEStartIdx                                                                   LSE          Comment */
  { /*     0 */ 0x0000U,          1U  /* /ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 */,            0U  /* /ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962 */, 0x01U }   /* [CT_DemoFBL_Fca_SLP5_01db1962] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_XIDFE
**********************************************************************************************************************/
/** 
  \var    Can_XIDFE
  \brief  Extended ID filters
  \details
  Element    Description
  EIDFE_0
  EIDFE_1
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(Can_XIDFEType, CAN_CONST) Can_XIDFE[1] = {
    /* Index    EIDFE_0                             EIDFE_1                                   Comment                                    Referable Keys */
  { /*     0 */ 0x20000000UL  /*  I:0 F0 FIFO_0 */, 0x80000000UL  /*  I:0 F1 FIFO_0 */ }   /* [CT_DemoFBL_Fca_SLP5_01db1962] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_DemoFBL_Fca_SLP5_01db1962] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_ActiveSendObject
**********************************************************************************************************************/
/** 
  \var    Can_ActiveSendObject
  \brief  temporary data for TX object
  \details
  Element    Description
  Pdu        buffered PduId for confirmation or cancellation
  State      send state like cancelled or send activ
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Can_ActiveSendObjectType, CAN_VAR_NOINIT) Can_ActiveSendObject[2];
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Can_ControllerData
**********************************************************************************************************************/
/** 
  \var    Can_ControllerData
  \brief  struct for all controller related variable data
  \details
  Element                    Description
  IntEnable                  CAN Interrupt Enable state for each controller
  NonFdObjectsPendingFlag    CAN Tx Objects pending with CAN-FD format
  TXBCR                      CAN Tx Buffer Cancellation Request for each controller
  TXBCRWait                  CAN Tx Buffer Cancellation Request Confirmation for each controller
  TXBRP                      CAN Tx Buffer request Pending for each controller
  BusOffNotification         CAN state for each controller: busoff occur
  CanInterruptCounter        CAN interrupt disable counter for each controller
  IsBusOff                   CAN state for each controller: busoff occur
  IsHardwareCanceled         hw loop timeout occur for controller
  LastInitObject             last set baudrate for reinit
  LogStatus                  CAN state for each controller: UNINIT=0x00, START=0x01, STOP=0x02, INIT=0x04, INCONSISTENT=0x08, WARNING =0x10, PASSIVE=0x20, BUSOFF=0x40, SLEEP=0x80
  StatusReq                  CAN state request for each controller: START=0x01, STOP=0x02, WAKEUP=0x08, SLEEP=0x80
  CanInterruptOldStatus      last CAN interrupt status for restore interrupt for each controller
  LoopTimeout                hw loop timeout for each controller
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(Can_ControllerDataType, CAN_VAR_NOINIT) Can_ControllerData[1];
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/




