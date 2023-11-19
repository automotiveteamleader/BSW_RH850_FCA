/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief Rte_ComM_type ASR4 stub for flash bootloader
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

#ifndef RTE_COMM_TYPE_H
#define RTE_COMM_TYPE_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "Rte_Type.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

#ifndef COMM_NO_COMMUNICATION
# define COMM_NO_COMMUNICATION 0U
#endif

#ifndef COMM_SILENT_COMMUNICATION
# define COMM_SILENT_COMMUNICATION 1U
#endif

#ifndef COMM_FULL_COMMUNICATION
# define COMM_FULL_COMMUNICATION 2U
#endif

#endif /* RTE_COMM_TYPE_H */

/***********************************************************************************************************************
 *  END OF FILE: RTE_COMM_TYPE.H
 **********************************************************************************************************************/
