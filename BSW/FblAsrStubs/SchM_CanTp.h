/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief SchM_CanTp ASR4 stub for flash bootloader
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

#ifndef SCHM_CANTP_H
#define SCHM_CANTP_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"

/***********************************************************************************************************************
 *  EXTERNAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define CANTP_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, CANTP_CODE) CanTp_MainFunction( void );
#define CANTP_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_COM_RX_INTERRUPT )
# define SchM_Enter_CanTp_CANTP_EXCLUSIVE_AREA_0()   FblInterruptDisable()
# define SchM_Exit_CanTp_CANTP_EXCLUSIVE_AREA_0()    FblInterruptEnable()
# define SchM_Enter_CanTp_CANTP_EXCLUSIVE_AREA_1()   FblInterruptDisable()
# define SchM_Exit_CanTp_CANTP_EXCLUSIVE_AREA_1()    FblInterruptEnable()
#else
# define SchM_Enter_CanTp_CANTP_EXCLUSIVE_AREA_0()
# define SchM_Exit_CanTp_CANTP_EXCLUSIVE_AREA_0()
# define SchM_Enter_CanTp_CANTP_EXCLUSIVE_AREA_1()
# define SchM_Exit_CanTp_CANTP_EXCLUSIVE_AREA_1()
#endif /* FBL_ENABLE_COM_RX_INTERRUPT */

#endif /* SCHM_CANTP_H */

/***********************************************************************************************************************
 *  END OF FILE: SCHM_CANTP.H
 **********************************************************************************************************************/
