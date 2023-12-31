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
 *            Module: EcuC
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701374A
 *    License Scope : The usage is restricted to CBD1800284_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: v_cfg.h
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

#if !defined(__V_CFG_H__)
#define __V_CFG_H__


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef V_USE_DUMMY_FUNCTIONS
#define V_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef V_USE_DUMMY_STATEMENT
#define V_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef V_DUMMY_STATEMENT
#define V_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef V_DUMMY_STATEMENT_CONST
#define V_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef V_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define V_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef V_ATOMIC_VARIABLE_ACCESS
#define V_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef V_PROCESSOR_RH850_1374
#define V_PROCESSOR_RH850_1374
#endif
#ifndef V_COMP_GREENHILLS
#define V_COMP_GREENHILLS
#endif
#ifndef V_GEN_GENERATOR_MSR
#define V_GEN_GENERATOR_MSR
#endif
#ifndef V_CPUTYPE_BITORDER_LSB2MSB
#define V_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef V_CONFIGURATION_VARIANT_PRECOMPILE
#define V_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef V_CONFIGURATION_VARIANT_LINKTIME
#define V_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef V_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define V_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef V_CONFIGURATION_VARIANT
#define V_CONFIGURATION_VARIANT V_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef V_POSTBUILD_VARIANT_SUPPORT
#define V_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif

#ifndef C_USE_DUMMY_FUNCTIONS
#define C_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef C_USE_DUMMY_STATEMENT
#define C_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef C_DUMMY_STATEMENT
#define C_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef C_DUMMY_STATEMENT_CONST
#define C_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef C_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define C_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef C_ATOMIC_VARIABLE_ACCESS
#define C_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef C_PROCESSOR_RH850_1374
#define C_PROCESSOR_RH850_1374
#endif
#ifndef C_COMP_GREENHILLS
#define C_COMP_GREENHILLS
#endif
#ifndef C_GEN_GENERATOR_MSR
#define C_GEN_GENERATOR_MSR
#endif
#ifndef C_CPUTYPE_BITORDER_LSB2MSB
#define C_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef C_CONFIGURATION_VARIANT_PRECOMPILE
#define C_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef C_CONFIGURATION_VARIANT_LINKTIME
#define C_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef C_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define C_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef C_CONFIGURATION_VARIANT
#define C_CONFIGURATION_VARIANT C_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef C_POSTBUILD_VARIANT_SUPPORT
#define C_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define V_DISABLE_USE_DUMMY_FUNCTIONS
#define V_ENABLE_USE_DUMMY_STATEMENT
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif /* __V_CFG_H__ */
/**********************************************************************************************************************
 *  END OF FILE: v_cfg.h
 *********************************************************************************************************************/    

