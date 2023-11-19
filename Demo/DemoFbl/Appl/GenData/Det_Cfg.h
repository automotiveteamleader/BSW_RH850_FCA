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
 *            Module: Det
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701374A
 *    License Scope : The usage is restricted to CBD1800284_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Det_Cfg.h
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

 
#if !defined(DET_CFG_H)
#define DET_CFG_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


#define DET_GENERATOR_CFG5
#define DET_AUTOSARVERSION                       4U
#define DET_ENABLED                              STD_ON
#define DET_VERSION_INFO_API                     STD_OFF
#define DET_DEBUG_ENABLED                        STD_OFF
#define DET_DLTFILTERSIZE                        0U
#define DET_GLOBALFILTERSIZE                     0U
#define DET_BREAKFILTERSIZE                      0U
#define DET_LOGBUFFERSIZE                        0U
#define DET_FORWARD_TO_DLT                       STD_OFF
#define DET_REPORT_ERROR_RECURSIONLIMIT          0U
#define DET_REPORT_RUNTIMEERROR_RECURSIONLIMIT   0U
#define DET_REPORT_TRANSIENTFAULT_RECURSIONLIMIT 0U

/*! DetModuleId symbolic name defines */


/*! Service port defines */


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DetPCDataSwitches  Det Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define DET_ERRORHOOKTABLE                                            STD_ON
#define DET_FINALMAGICNUMBER                                          STD_OFF  /**< Deactivateable: 'Det_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define DET_INITDATAHASHCODE                                          STD_OFF  /**< Deactivateable: 'Det_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define DET_RUNTIMEERRORCALLOUTTABLE                                  STD_ON
#define DET_SIZEOFERRORHOOKTABLE                                      STD_ON
#define DET_SIZEOFRUNTIMEERRORCALLOUTTABLE                            STD_ON
#define DET_SIZEOFTRANSIENTFAULTCALLOUTTABLE                          STD_ON
#define DET_TRANSIENTFAULTCALLOUTTABLE                                STD_ON
#define DET_PCCONFIG                                                  STD_ON
#define DET_ERRORHOOKTABLEOFPCCONFIG                                  STD_ON
#define DET_FINALMAGICNUMBEROFPCCONFIG                                STD_OFF  /**< Deactivateable: 'Det_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define DET_INITDATAHASHCODEOFPCCONFIG                                STD_OFF  /**< Deactivateable: 'Det_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define DET_RUNTIMEERRORCALLOUTTABLEOFPCCONFIG                        STD_ON
#define DET_SIZEOFERRORHOOKTABLEOFPCCONFIG                            STD_ON
#define DET_SIZEOFRUNTIMEERRORCALLOUTTABLEOFPCCONFIG                  STD_ON
#define DET_SIZEOFTRANSIENTFAULTCALLOUTTABLEOFPCCONFIG                STD_ON
#define DET_TRANSIENTFAULTCALLOUTTABLEOFPCCONFIG                      STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  DetPCIsReducedToDefineDefines  Det Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define DET_ISDEF_ERRORHOOKTABLE                                      STD_OFF
#define DET_ISDEF_RUNTIMEERRORCALLOUTTABLE                            STD_OFF
#define DET_ISDEF_TRANSIENTFAULTCALLOUTTABLE                          STD_OFF
#define DET_ISDEF_ERRORHOOKTABLEOFPCCONFIG                            STD_ON
#define DET_ISDEF_RUNTIMEERRORCALLOUTTABLEOFPCCONFIG                  STD_ON
#define DET_ISDEF_TRANSIENTFAULTCALLOUTTABLEOFPCCONFIG                STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  DetPCEqualsAlwaysToDefines  Det Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define DET_EQ2_ERRORHOOKTABLE                                        
#define DET_EQ2_RUNTIMEERRORCALLOUTTABLE                              
#define DET_EQ2_TRANSIENTFAULTCALLOUTTABLE                            
#define DET_EQ2_ERRORHOOKTABLEOFPCCONFIG                              Det_ErrorHookTable
#define DET_EQ2_RUNTIMEERRORCALLOUTTABLEOFPCCONFIG                    Det_RuntimeErrorCalloutTable
#define DET_EQ2_TRANSIENTFAULTCALLOUTTABLEOFPCCONFIG                  Det_TransientFaultCalloutTable
/** 
  \}
*/ 

/** 
  \defgroup  DetPCSymbolicInitializationPointers  Det Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define Det_Config_Ptr                                                NULL_PTR  /**< symbolic identifier which shall be used to initialize 'Det' */
/** 
  \}
*/ 

/** 
  \defgroup  DetPCInitializationSymbols  Det Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define Det_Config                                                    NULL_PTR  /**< symbolic identifier which could be used to initialize 'Det */
/** 
  \}
*/ 

/** 
  \defgroup  DetPCGeneral  Det General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define DET_CHECK_INIT_POINTER                                        STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define DET_FINAL_MAGIC_NUMBER                                        0x0F1EU  /**< the precompile constant to validate the size of the initialization structure at initialization time of Det */
#define DET_INDIVIDUAL_POSTBUILD                                      STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'Det' is not configured to be postbuild capable. */
#define DET_INIT_DATA                                                 DET_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define DET_INIT_DATA_HASH_CODE                                       651877085L  /**< the precompile constant to validate the initialization structure at initialization time of Det with a hashcode. The seed value is '0x0F1EU' */
#define DET_USE_ECUM_BSW_ERROR_HOOK                                   STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define DET_USE_INIT_POINTER                                          STD_OFF  /**< STD_ON if the init pointer Det shall be used. */
/** 
  \}
*/ 



#ifndef DET_USE_DUMMY_FUNCTIONS
#define DET_USE_DUMMY_FUNCTIONS STD_OFF /* /MICROSAR/EcuC/EcucGeneral/DummyFunction */
#endif
#ifndef DET_USE_DUMMY_STATEMENT
#define DET_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef DET_DUMMY_STATEMENT
#define DET_DUMMY_STATEMENT(v) (v)=(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef DET_DUMMY_STATEMENT_CONST
#define DET_DUMMY_STATEMENT_CONST(v) (void)(v) /* PRQA S 3453 */ /* MD_MSR_19.7 */  /* /MICROSAR/EcuC/EcucGeneral/DummyStatementKind */
#endif
#ifndef DET_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define DET_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef DET_ATOMIC_VARIABLE_ACCESS
#define DET_ATOMIC_VARIABLE_ACCESS 32U /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef DET_PROCESSOR_RH850_1374
#define DET_PROCESSOR_RH850_1374
#endif
#ifndef DET_COMP_GREENHILLS
#define DET_COMP_GREENHILLS
#endif
#ifndef DET_GEN_GENERATOR_MSR
#define DET_GEN_GENERATOR_MSR
#endif
#ifndef DET_CPUTYPE_BITORDER_LSB2MSB
#define DET_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/EcuC/EcucGeneral/BitOrder */
#endif
#ifndef DET_CONFIGURATION_VARIANT_PRECOMPILE
#define DET_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef DET_CONFIGURATION_VARIANT_LINKTIME
#define DET_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef DET_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define DET_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef DET_CONFIGURATION_VARIANT
#define DET_CONFIGURATION_VARIANT DET_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef DET_POSTBUILD_VARIANT_SUPPORT
#define DET_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


/*! Compatibility defines */
#define DET_RUNTIME_ERROR_CALLOUT_ENABLED        DET_RUNTIMEERRORCALLOUTTABLE
#define DET_TRANSIENT_FAULT_CALLOUT_ENABLED      DET_TRANSIENTFAULTCALLOUTTABLE
#define DET_ERROR_HOOK_ENABLED                   DET_ERRORHOOKTABLE

/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
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
  \defgroup  DetPCGetConstantDuplicatedRootDataMacros  Det Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define Det_GetErrorHookTableOfPCConfig()                             Det_ErrorHookTable  /**< the pointer to Det_ErrorHookTable */
#define Det_GetRuntimeErrorCalloutTableOfPCConfig()                   Det_RuntimeErrorCalloutTable  /**< the pointer to Det_RuntimeErrorCalloutTable */
#define Det_GetSizeOfErrorHookTableOfPCConfig()                       1U  /**< the number of accomplishable value elements in Det_ErrorHookTable */
#define Det_GetSizeOfRuntimeErrorCalloutTableOfPCConfig()             1U  /**< the number of accomplishable value elements in Det_RuntimeErrorCalloutTable */
#define Det_GetSizeOfTransientFaultCalloutTableOfPCConfig()           1U  /**< the number of accomplishable value elements in Det_TransientFaultCalloutTable */
#define Det_GetTransientFaultCalloutTableOfPCConfig()                 Det_TransientFaultCalloutTable  /**< the pointer to Det_TransientFaultCalloutTable */
/** 
  \}
*/ 

/** 
  \defgroup  DetPCGetDataMacros  Det Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define Det_GetErrorHookTable(Index)                                  (Det_GetErrorHookTableOfPCConfig()[(Index)])
#define Det_GetRuntimeErrorCalloutTable(Index)                        (Det_GetRuntimeErrorCalloutTableOfPCConfig()[(Index)])
#define Det_GetTransientFaultCalloutTable(Index)                      (Det_GetTransientFaultCalloutTableOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  DetPCGetDeduplicatedDataMacros  Det Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define Det_GetSizeOfErrorHookTable()                                 Det_GetSizeOfErrorHookTableOfPCConfig()
#define Det_GetSizeOfRuntimeErrorCalloutTable()                       Det_GetSizeOfRuntimeErrorCalloutTableOfPCConfig()
#define Det_GetSizeOfTransientFaultCalloutTable()                     Det_GetSizeOfTransientFaultCalloutTableOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  DetPCHasMacros  Det Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define Det_HasErrorHookTable()                                       (TRUE != FALSE)
#define Det_HasRuntimeErrorCalloutTable()                             (TRUE != FALSE)
#define Det_HasSizeOfErrorHookTable()                                 (TRUE != FALSE)
#define Det_HasSizeOfRuntimeErrorCalloutTable()                       (TRUE != FALSE)
#define Det_HasSizeOfTransientFaultCalloutTable()                     (TRUE != FALSE)
#define Det_HasTransientFaultCalloutTable()                           (TRUE != FALSE)
#define Det_HasPCConfig()                                             (TRUE != FALSE)
#define Det_HasErrorHookTableOfPCConfig()                             (TRUE != FALSE)
#define Det_HasRuntimeErrorCalloutTableOfPCConfig()                   (TRUE != FALSE)
#define Det_HasSizeOfErrorHookTableOfPCConfig()                       (TRUE != FALSE)
#define Det_HasSizeOfRuntimeErrorCalloutTableOfPCConfig()             (TRUE != FALSE)
#define Det_HasSizeOfTransientFaultCalloutTableOfPCConfig()           (TRUE != FALSE)
#define Det_HasTransientFaultCalloutTableOfPCConfig()                 (TRUE != FALSE)
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



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*! Function pointer type for callouts */
typedef P2FUNC(Std_ReturnType, DET_CODE, Det_CalloutTableType )( uint16, uint8, uint8, uint8 );


/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  DetPCIterableTypes  Det Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate Det_ErrorHookTable */
typedef uint8_least Det_ErrorHookTableIterType;

/**   \brief  type used to iterate Det_RuntimeErrorCalloutTable */
typedef uint8_least Det_RuntimeErrorCalloutTableIterType;

/**   \brief  type used to iterate Det_TransientFaultCalloutTable */
typedef uint8_least Det_TransientFaultCalloutTableIterType;

/** 
  \}
*/ 

/** 
  \defgroup  DetPCValueTypes  Det Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for Det_SizeOfErrorHookTable */
typedef uint8 Det_SizeOfErrorHookTableType;

/**   \brief  value based type definition for Det_SizeOfRuntimeErrorCalloutTable */
typedef uint8 Det_SizeOfRuntimeErrorCalloutTableType;

/**   \brief  value based type definition for Det_SizeOfTransientFaultCalloutTable */
typedef uint8 Det_SizeOfTransientFaultCalloutTableType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  DetPCRootValueTypes  Det Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in Det_PCConfig */
typedef struct sDet_PCConfigType
{
  uint8 Det_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} Det_PCConfigType;

typedef Det_PCConfigType Det_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 

 


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  Det_ErrorHookTable
**********************************************************************************************************************/
/** 
  \var    Det_ErrorHookTable
  \brief  List of functions to be called by the Default Error Tracer in context of each call of Det_ReportError
*/ 
#define DET_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Det_CalloutTableType, DET_CONST) Det_ErrorHookTable[1];
#define DET_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Det_RuntimeErrorCalloutTable
**********************************************************************************************************************/
/** 
  \var    Det_RuntimeErrorCalloutTable
  \brief  List of callout functions for the corresponding runtime error handler.
*/ 
#define DET_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Det_CalloutTableType, DET_CONST) Det_RuntimeErrorCalloutTable[1];
#define DET_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  Det_TransientFaultCalloutTable
**********************************************************************************************************************/
/** 
  \var    Det_TransientFaultCalloutTable
  \brief  List of callout functions for the corresponding transient fault handler.
*/ 
#define DET_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(Det_CalloutTableType, DET_CONST) Det_TransientFaultCalloutTable[1];
#define DET_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

 

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

 
#define DET_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


FUNC(Std_ReturnType, DET_CODE) ApplFbl_DetEntryHandler( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId );


#define DET_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#endif /* DET_CFG_H */
