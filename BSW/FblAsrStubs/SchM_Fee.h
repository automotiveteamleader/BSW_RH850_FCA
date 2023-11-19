/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief SchM_Fee ASR4 stub for flash bootloader
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

#ifndef SCHM_FEE_H
#define SCHM_FEE_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#if !defined( SchM_Enter_Fee )
# define SchM_Enter_Fee(section)    SchM_Enter_Fee_ ## section()
#endif
#if !defined( SchM_Exit_Fee )
# define SchM_Exit_Fee(section)     SchM_Exit_Fee_ ## section()
#endif

#if defined( FBL_ENABLE_COM_RX_INTERRUPT )
# define SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_0()   FblInterruptDisable()
# define SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_0()    FblInterruptEnable()
# define SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_1()   FblInterruptDisable()
# define SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_1()    FblInterruptEnable()
#else
# define SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_0()
# define SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_0()
# define SchM_Enter_Fee_FEE_EXCLUSIVE_AREA_1()
# define SchM_Exit_Fee_FEE_EXCLUSIVE_AREA_1()
#endif /* FBL_ENABLE_COM_RX_INTERRUPT */

#endif /* SCHM_FEE_H */

/***********************************************************************************************************************
 *  END OF FILE: SCHM_FEE.H
 **********************************************************************************************************************/
