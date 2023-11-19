/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief SchM_Can ASR4 stub for flash bootloader
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

#ifndef SCHM_CAN_H
#define SCHM_CAN_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"

/***********************************************************************************************************************
 *  EXTERNAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define CAN_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Write( void );
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_BusOff( void );
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Read( void );
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Wakeup( void );
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Mode( void );
#define CAN_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_COM_RX_INTERRUPT )
# define SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0()   FblInterruptDisable()
# define SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0()    FblInterruptEnable()
# define SchM_Enter_Can_CAN_EXCLUSIVE_AREA_1()   FblInterruptDisable()
# define SchM_Exit_Can_CAN_EXCLUSIVE_AREA_1()    FblInterruptEnable()
# define SchM_Enter_Can_CAN_EXCLUSIVE_AREA_2()   FblInterruptDisable()
# define SchM_Exit_Can_CAN_EXCLUSIVE_AREA_2()    FblInterruptEnable()
# define SchM_Enter_Can_CAN_EXCLUSIVE_AREA_3()   FblInterruptDisable()
# define SchM_Exit_Can_CAN_EXCLUSIVE_AREA_3()    FblInterruptEnable()
# define SchM_Enter_Can_CAN_EXCLUSIVE_AREA_4()   FblInterruptDisable()
# define SchM_Exit_Can_CAN_EXCLUSIVE_AREA_4()    FblInterruptEnable()
# define SchM_Enter_Can_CAN_EXCLUSIVE_AREA_5()   FblInterruptDisable()
# define SchM_Exit_Can_CAN_EXCLUSIVE_AREA_5()    FblInterruptEnable()
# define SchM_Enter_Can_CAN_EXCLUSIVE_AREA_6()   FblInterruptDisable()
# define SchM_Exit_Can_CAN_EXCLUSIVE_AREA_6()    FblInterruptEnable()
#else
# define SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0()
# define SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0()
# define SchM_Enter_Can_CAN_EXCLUSIVE_AREA_1()
# define SchM_Exit_Can_CAN_EXCLUSIVE_AREA_1()
# define SchM_Enter_Can_CAN_EXCLUSIVE_AREA_2()
# define SchM_Exit_Can_CAN_EXCLUSIVE_AREA_2()
# define SchM_Enter_Can_CAN_EXCLUSIVE_AREA_3()
# define SchM_Exit_Can_CAN_EXCLUSIVE_AREA_3()
# define SchM_Enter_Can_CAN_EXCLUSIVE_AREA_4()
# define SchM_Exit_Can_CAN_EXCLUSIVE_AREA_4()
# define SchM_Enter_Can_CAN_EXCLUSIVE_AREA_5()
# define SchM_Exit_Can_CAN_EXCLUSIVE_AREA_5()
# define SchM_Enter_Can_CAN_EXCLUSIVE_AREA_6()
# define SchM_Exit_Can_CAN_EXCLUSIVE_AREA_6()
#endif /* FBL_ENABLE_COM_RX_INTERRUPT */

#endif /* SCHM_CAN_H */

/***********************************************************************************************************************
 *  END OF FILE: SCHM_CAN.H
 **********************************************************************************************************************/
