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
 *  02.00.00   2015-09-23  JHg     ESCAN00085431    No changes
 *                         JHg     ESCAN00085436    Replaced program dependent switches (FBL_CLIENT_<program>)
 *                                                   with feature switch FBL_MIO_ENABLE_MEM_DRIVER_READY.
 *                         JHg     ESCAN00085438    Removed _COMMENT from FBL_ENABLE_FUNC_VERIFYSYNC
 *                         JHg     ESCAN00085439    Refactoring
 *  02.01.00   2018-02-09  TnS     ESCAN00088473    MISRA related code changes
 *                         Ach     ESCAN00098291    No changes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

#include "fbl_inc.h"

/***********************************************************************************************************************
 *  VERSION
 **********************************************************************************************************************/

#if ( FBLMIO_VERSION != 0x0201u ) || \
    ( FBLMIO_RELEASE_VERSION != 0x00u )
# error "Error in FBL_MIO.C: Source and header file are inconsistent!"
#endif

#if ( FBLMIO_VERSION != _FBLMIO_VERSION ) || \
    ( FBLMIO_RELEASE_VERSION != _FBLMIO_RELEASE_VERSION )
# error "Error in FBL_MIO.C: Source and V_VER.H are inconsistent!"
#endif

/***********************************************************************************************************************
 *  GLOBALS
 **********************************************************************************************************************/

/* Device active status, if currently an    */
/*  erase or programming is active.         */
/*  It contains either the state "Idle" or  */
/*  the device driver number that is active  */
vuint8 memDrvDeviceActive;
vuint8 memDrvFunctionActive;

#define FBLMIO_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

#if defined( FBL_ENABLE_MULTIPLE_MEM_DEVICES )
/***********************************************************************************************************************
 *  MemDriver_InitSync
 **********************************************************************************************************************/
/*! \brief      Initialize all memory drivers.
 *  \pre        Memory drivers have to be present (e.g. copied to RAM).
 *  \param[in]  address Parameter to be passed to HIS interface flash driver.
 *  \return     Reports if all memory drivers have been initialized successfully.
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR MemDriver_InitSync( void * address )
{
   vuintx i;
   IO_ErrorType result = IO_E_OK;
   IO_ErrorType rc;

   {
      for (i = 0u; i < kNrOfMemDrv; i++)
      {
         MemDriver_InitBegin(i); /* PRQA S 3109 */ /* MD_CBD_14.3 */
         rc = (*memDrvLst[i].init)(address);
         MemDriver_InitEnd(i); /* PRQA S 3109 */ /* MD_CBD_14.3 */

         if (rc != IO_E_OK)
         {
            result = rc;
            break;
         }
      }
   }

   return result;
}

/***********************************************************************************************************************
 *  MemDriver_DeinitSync
 **********************************************************************************************************************/
/*! \brief      Deinitialize all memory drivers.
 *  \pre        Memory drivers have to be present (e.g. copied to RAM).
 *  \param[in]  address Parameter to be passed to HIS interface flash driver.
 *  \return     The return code shows the success of the deinitialization.
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR MemDriver_DeinitSync( void * address )
{
   vuintx i;
   IO_ErrorType result = IO_E_OK;

   for (i = 0u; i < kNrOfMemDrv; i++)
   {
      result = (*memDrvLst[i].deinit)(address);
      if (result != IO_E_OK)
      {
         break;
      }
   }
   return result;
}
#else
#endif

# if defined( FBL_ENABLE_MULTIPLE_MEM_DEVICES )
/***********************************************************************************************************************
 *  MemDriver_RWriteSync
 **********************************************************************************************************************/
/*! \brief      Write data into memory
 *  \details    This function selects the memory driver used to program a memory device and
 *              calls the write function of this driver.
 *  \pre        All drivers are initialized, memory to be written is erased (flash memory).
 *  \param[in]  buf Pointer to input data buffer.
 *  \param[in]  len Data length. Has to be aligned to a multiple of the smallest writable data segment.
 *  \param[in]  addr Write target address. Has to be aligned to a write segment start address.
 *  \return     Reports write success or error code.
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR MemDriver_RWriteSync(IO_MemPtrType buf, IO_SizeType len, IO_PositionType addr)
{
   IO_ErrorType ret_status;
   MemDriver_RWriteBegin(FlashBlock[memSegment].device); /* PRQA S 3109 */ /* MD_CBD_14.3 */
   ret_status = (*memDrvLst[FlashBlock[memSegment].device].write)((buf), (len), (addr));
   MemDriver_RWriteEnd(FlashBlock[memSegment].device); /* PRQA S 3109 */ /* MD_CBD_14.3 */
   return ret_status;
}

/***********************************************************************************************************************
 *  MemDriver_REraseSync
 **********************************************************************************************************************/
/*! \brief      Erase area in memory
 *  \details    This function erases an area in memory.
 *  \pre        All drivers are initialized.
 *  \param[in]  len Length of memory to be erased. The length has to be aligned to the length of one or
 *              more erasable sectors of the used memories.
 *  \param[in]  addr Start address of erase area. The start address has to be aligned to the start address
 *              of an erasable area.
 *  \return     Reports erase success or error code.
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR MemDriver_REraseSync(IO_SizeType len, IO_PositionType addr)
{
   IO_ErrorType ret_status;
   MemDriver_REraseBegin(FlashBlock[memSegment].device); /* PRQA S 3109 */ /* MD_CBD_14.3 */
   ret_status = (*memDrvLst[FlashBlock[memSegment].device].erase) ((len), (addr));
   MemDriver_REraseEnd(FlashBlock[memSegment].device); /* PRQA S 3109 */ /* MD_CBD_14.3 */
   return ret_status;
}

# else /* FBL_ENABLE_MULTIPLE_MEM_DEVICES */
/***********************************************************************************************************************
 *  MemDriver_RWriteSync
 **********************************************************************************************************************/
/*! \brief      Write data into memory
 *  \details    This function calls the write function of the internal flash memory.
 *  \pre        Internal flash driver is initialized, memory to be written is erased.
 *  \param[in]  buf Pointer to input data buffer.
 *  \param[in]  len Data length. Has to be aligned to a multiple of the smallest writable data segment.
 *  \param[in]  addr Write target address. Has to be aligned to a write segment start address.
 *  \return     Reports write success or error code.
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR MemDriver_RWriteSync( IO_MemPtrType buf, IO_SizeType len, IO_PositionType addr )
{
   IO_ErrorType ret_status;
   MemDriver_RWriteBegin(kMioDeviceInternalFlash); /* PRQA S 3109 */ /* MD_CBD_14.3 */
   ret_status = FlashDriver_RWriteSync(buf, len, addr);
   MemDriver_RWriteEnd(kMioDeviceInternalFlash); /* PRQA S 3109 */ /* MD_CBD_14.3 */
   return ret_status;
}

/***********************************************************************************************************************
 *  MemDriver_REraseSync
 **********************************************************************************************************************/
/*! \brief      Erase area in memory
 *  \details    This function erases an area in memory.
 *  \pre        Internal flash driver is initialized.
 *  \param[in]  len Length of memory to be erased. The length has to be aligned to the length of one or
 *              more erasable sectors of the internal flash.
 *  \param[in]  addr Start address of erase area. The start address has to be aligned to the start address
 *              of an erasable area.
 *  \return     Reports erase success or error code.
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR MemDriver_REraseSync( IO_SizeType len, IO_PositionType addr )
{
   IO_ErrorType ret_status;
   MemDriver_REraseBegin((kMioDeviceInternalFlash)); /* PRQA S 3109 */ /* MD_CBD_14.3 */
   ret_status = FlashDriver_REraseSync(len, addr);
   MemDriver_REraseEnd((kMioDeviceInternalFlash)); /* PRQA S 3109 */ /* MD_CBD_14.3 */
   return ret_status;
}

/***********************************************************************************************************************
 *  MemDriver_InitSync
 **********************************************************************************************************************/
/*! \brief      Initialize all memory drivers
 *  \pre        All memory drivers need to be copied to RAM (if necessary)
 *  \param      address Not used; conformance to HIS interface
 *  \return     The return code shows the success of the initialization
 **********************************************************************************************************************/
IO_ErrorType V_API_NEAR MemDriver_InitSync( void * address ) /* PRQA S 3673 */ /* MD_FblMio_3673 */
{
   IO_ErrorType ret_status;
# if defined( V_ENABLE_USE_DUMMY_STATEMENT )
   (void)address; /* PRQA S 3112 */ /* MD_FblMio_3112 */
# endif
   MemDriver_InitBegin(kMioDeviceInternalFlash); /* PRQA S 3109 */ /* MD_CBD_14.3 */
   ret_status = FlashDriver_InitSync(V_NULL);
   MemDriver_InitEnd(kMioDeviceInternalFlash); /* PRQA S 3109 */ /* MD_CBD_14.3 */
   return ret_status;
}

# endif /* FBL_ENABLE_MULTIPLE_MEM_DEVICES */

#define FBLMIO_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/*****************************************************************************/

/* module specific MISRA deviations:

   MD_FblMio_3112:
      Reason:     Dummy statements have been added to avoid compiler warnings because of unused variables.
      Risk:       Unused statements add to program complexity just by being there - adding lines to the program and
                  causing readers to puzzle over its presence.
      Prevention: Dummy statements can be turned off externally (V_DISABLE_USE_DUMMY_STATEMENT).

   MD_FblMio_3673:
      Reason:     This is a standard API that should not be changed for compatibility reasons.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

   MD_FblMio_Dummy:
      Reason:     This Dummy function only exists, because some compilers require that every source module
                  implements functions/variables and not only macros. However, depending on the configuration,
                  only macros will be present in the file.
      Risk:       No identifiable risk.
      Prevention: No prevention required.

*/

/***********************************************************************************************************************
 *  END OF FILE: FBL_MIO.C
 **********************************************************************************************************************/

