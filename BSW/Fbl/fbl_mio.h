/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Memory Driver wrapper functions
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

/***********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  --------------------------------------------------------------------------------------------------------------------
 *  Joern Herwig                  JHg           Vector Informatik GmbH
 *  Torben Stoessel               TnS           Vector Informatik GmbH
 *  Achim Strobelt                Ach           Vector Informatik GmbH
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id        Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  02.00.00   2015-09-23  JHg     ESCAN00085431    Moved type definitions of flash driver function pointers and
 *                                                   memory driver structure to flash block table configuration
 *                         JHg     ESCAN00085436    Replaced program dependent switches (FBL_CLIENT_<program>)
 *                                                   with feature switch FBL_MIO_ENABLE_MEM_DRIVER_READY.
 *                         JHg     ESCAN00085438    Removed _COMMENT from FBL_ENABLE_FUNC_VERIFYSYNC
 *                         JHg     ESCAN00085439    Refactoring
 *  02.01.00   2018-02-09  TnS     ESCAN00088473    MISRA related code changes
 *                         Ach     ESCAN00098291    No changes
 **********************************************************************************************************************/

#ifndef __FBL_MIO_H__
#define __FBL_MIO_H__

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

/* ##V_CFG_MANAGEMENT ##CQProject : FblMio CQComponent : Implementation */
#define FBLMIO_VERSION              0x0201u
#define FBLMIO_RELEASE_VERSION      0x00u

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/
/* PRQA S 3453 EOF */ /* MD_MSR_19.7 */

/** Device active state */
#define kMioDeviceIdle              0xFFu

/* Functional macros */
# define MemDriver_InitPowerOn()            { \
                                              memDrvDeviceActive   = kMioDeviceIdle;     \
                                              memDrvFunctionActive = kMioFunctionNone;   \
                                            } /* PRQA S 3458 */ /* MD_CBD_19.4 */
# define MemDriver_InitBegin(a)             { \
                                              memDrvDeviceActive   = (a);                \
                                              memDrvFunctionActive = kMioFunctionInit;   \
                                            } /* PRQA S 3458 */ /* MD_CBD_19.4 */
# define MemDriver_InitEnd(a)               { \
                                              memDrvDeviceActive   = kMioDeviceIdle;     \
                                              memDrvFunctionActive = kMioFunctionNone;   \
                                            } /* PRQA S 3458 */ /* MD_CBD_19.4 */
# define MemDriver_REraseBegin(a)           { \
                                              memDrvDeviceActive   = (a);                \
                                              memDrvFunctionActive = kMioFunctionErase;  \
                                            } /* PRQA S 3458 */ /* MD_CBD_19.4 */
# define MemDriver_REraseEnd(a)             { \
                                              memDrvDeviceActive   = kMioDeviceIdle;     \
                                              memDrvFunctionActive = kMioFunctionNone;   \
                                            } /* PRQA S 3458 */ /* MD_CBD_19.4 */
# define MemDriver_RWriteBegin(a)           { \
                                              memDrvDeviceActive   = (a);                \
                                              memDrvFunctionActive = kMioFunctionWrite;  \
                                            } /* PRQA S 3458 */ /* MD_CBD_19.4 */
# define MemDriver_RWriteEnd(a)             { \
                                              memDrvDeviceActive   = kMioDeviceIdle;     \
                                              memDrvFunctionActive = kMioFunctionNone;   \
                                            } /* PRQA S 3458 */ /* MD_CBD_19.4 */
# define MemDriver_VerifyBegin(a)           { \
                                              memDrvDeviceActive   = (a);                \
                                              memDrvFunctionActive = kMioFunctionVerify; \
                                            } /* PRQA S 3458 */ /* MD_CBD_19.4 */
# define MemDriver_VerifyEnd(a)             { \
                                              memDrvDeviceActive   = kMioDeviceIdle;     \
                                              memDrvFunctionActive = kMioFunctionNone;   \
                                            } /* PRQA S 3458 */ /* MD_CBD_19.4 */
# define MemDriver_DeinitBegin(a)           { \
                                             memDrvDeviceActive   = (a);                 \
                                             memDrvFunctionActive = kMioFunctionDeinit;  \
                                            } /* PRQA S 3458 */ /* MD_CBD_19.4 */
# define MemDriver_DeinitEnd(a)             { \
                                             memDrvDeviceActive   = kMioDeviceIdle;      \
                                             memDrvFunctionActive = kMioFunctionNone;    \
                                            } /* PRQA S 3458 */ /* MD_CBD_19.4 */

#if defined( FBL_ENABLE_MULTIPLE_MEM_DEVICES )

# define MemDriver_RReadSync                       (*memDrvLst[FlashBlock[memSegment].device].read)
# define MemDriver_SegmentSize                     (memDrvLst[FlashBlock[memSegment].device].segmentSize)
# if defined( FBL_MEMDRV_SEGMENT_SIZE )
#  if ( FLASH_SEGMENT_SIZE > FBL_MEMDRV_SEGMENT_SIZE )
#   define FBL_MAX_SEGMENT_SIZE_MIO FLASH_SEGMENT_SIZE
#  else
#   define FBL_MAX_SEGMENT_SIZE_MIO FBL_MEMDRV_SEGMENT_SIZE
#  endif
# else
#  define FBL_MAX_SEGMENT_SIZE_MIO FLASH_SEGMENT_SIZE
# endif /* FBL_MEMDRV_SEGMENT_SIZE */

#else /* FBL_ENABLE_MULTIPLE_MEM_DEVICES */

/* In case of single memory this index will be used */
/* In case of multiple memory the FlashBlock[memSegment].device, or device index will be used */
# define kMioDeviceInternalFlash     0u

/* PRQA S 3453 TAG_FblMio_3453 */ /* MD_MSR_19.7 */

# define MemDriver_RReadSync(a, b, c)              FlashDriver_RReadSync((a), (b), (c))
# define MemDriver_DeinitSync(a)                   FlashDriver_DeinitSync((a))
# define MemDriver_SegmentSize                     FLASH_SEGMENT_SIZE
# define FBL_MAX_SEGMENT_SIZE_MIO                  FLASH_SEGMENT_SIZE
/* PRQA L:TAG_FblMio_3453 */

#endif /* FBL_ENABLE_MULTIPLE_MEM_DEVICES */

#if defined( FBL_MAX_SEGMENT_SIZE )
# if ( FBL_MAX_SEGMENT_SIZE_MIO > FBL_MAX_SEGMENT_SIZE )
#  error "Define FBL_MAX_SEGMENT_SIZE from external only with values larger than determined through FblMio."
# endif
#else
# define FBL_MAX_SEGMENT_SIZE FBL_MAX_SEGMENT_SIZE_MIO
#endif /* FBL_MAX_SEGMENT_SIZE */

/* Defines to indicate, which function is active */
# define kMioFunctionNone            0u
# define kMioFunctionInit            1u
# define kMioFunctionDeinit          2u
# define kMioFunctionWrite           3u
# define kMioFunctionErase           4u
# define kMioFunctionVerify          5u

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define FBLMIO_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#if defined( FBL_ENABLE_MULTIPLE_MEM_DEVICES )
IO_ErrorType V_API_NEAR MemDriver_DeinitSync( void * address );
#else
#endif /* FBL_ENABLE_MULTIPLE_MEM_DEVICES */

/* MemDriver general interface */
IO_ErrorType V_API_NEAR MemDriver_RWriteSync( IO_MemPtrType buf, IO_SizeType len, IO_PositionType addr );
IO_ErrorType V_API_NEAR MemDriver_REraseSync( IO_SizeType len, IO_PositionType addr );
IO_ErrorType V_API_NEAR MemDriver_InitSync( void * address );

#define FBLMIO_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

extern vuint8 memDrvDeviceActive;
extern vuint8 memDrvFunctionActive;

/***********************************************************************************************************************
 *  CONFIGURATION CHECKS
 **********************************************************************************************************************/

#endif /* __FBL_MIO_H__ */

/***********************************************************************************************************************
 *  END OF FILE: FBL_MIO.H
 **********************************************************************************************************************/
