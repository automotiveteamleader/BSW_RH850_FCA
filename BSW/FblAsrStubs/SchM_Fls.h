/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief SchM_Fls ASR4 stub for flash bootloader
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 **********************************************************************************************************************/

#ifndef SCHM_FLS_H
#define SCHM_FLS_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"

/***********************************************************************************************************************
 *  EXTERNAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FLS_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
extern FUNC(void, FLS_CODE) Fls_MainFunction (void);
#define FLS_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if !defined( SchM_Enter_Fls )
# define SchM_Enter_Fls(section)       SchM_Enter_Fls_ ## section()
#endif
#if !defined( SchM_Exit_Fls )
# define SchM_Exit_Fls(section)        SchM_Exit_Fls_ ## section()
#endif

#if defined( FBL_ENABLE_COM_RX_INTERRUPT )
# define SchM_Enter_Fls_FLS_REGISTER_PROTECTION()           FblInterruptDisable()
# define SchM_Exit_Fls_FLS_REGISTER_PROTECTION()            FblInterruptEnable()
# define SchM_Enter_Fls_DRIVERSTATE_DATA_PROTECTION()       FblInterruptDisable()
# define SchM_Exit_Fls_DRIVERSTATE_DATA_PROTECTION()        FblInterruptEnable()
# define SchM_Enter_Fls_FLS_DRIVERSTATE_DATA_PROTECTION()   FblInterruptDisable()
# define SchM_Exit_Fls_FLS_DRIVERSTATE_DATA_PROTECTION()    FblInterruptEnable()
# define SchM_Enter_Fls_FLS_CODE_FLASH_DISABLED()           FblInterruptDisable()
# define SchM_Exit_Fls_FLS_CODE_FLASH_DISABLED()            FblInterruptEnable()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_0()              FblInterruptDisable()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_0()               FblInterruptEnable()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00()             FblInterruptDisable()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00()              FblInterruptEnable()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_02()             FblInterruptDisable()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_02()              FblInterruptEnable()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_04()             FblInterruptDisable()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_04()              FblInterruptEnable()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_05()             FblInterruptDisable()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_05()              FblInterruptEnable()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_06()             FblInterruptDisable()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_06()              FblInterruptEnable()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_10()             FblInterruptDisable()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_10()              FblInterruptEnable()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_11()             FblInterruptDisable()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_11()              FblInterruptEnable()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_12()             FblInterruptDisable()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_12()              FblInterruptEnable()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_13()             FblInterruptDisable()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_13()              FblInterruptEnable()
#else
# define SchM_Enter_Fls_FLS_REGISTER_PROTECTION()
# define SchM_Exit_Fls_FLS_REGISTER_PROTECTION()
# define SchM_Enter_Fls_DRIVERSTATE_DATA_PROTECTION()
# define SchM_Exit_Fls_DRIVERSTATE_DATA_PROTECTION()
# define SchM_Enter_Fls_FLS_DRIVERSTATE_DATA_PROTECTION()
# define SchM_Exit_Fls_FLS_DRIVERSTATE_DATA_PROTECTION()
# define SchM_Enter_Fls_FLS_CODE_FLASH_DISABLED()
# define SchM_Exit_Fls_FLS_CODE_FLASH_DISABLED()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_0()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_0()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_00()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_00()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_02()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_02()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_04()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_04()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_05()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_05()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_06()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_06()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_10()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_10()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_11()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_11()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_12()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_12()
# define SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_13()
# define SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_13()
#endif /* FBL_ENABLE_COM_RX_INTERRUPT */

#endif /* SCHM_FLS_H */

/***********************************************************************************************************************
 *  END OF FILE: SCHM_FLS.H
 **********************************************************************************************************************/
