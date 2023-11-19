#define FEE_30_SMALLSECTOR_IMPLEMENTATION_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Fee_30_SmallSector.h"


/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
 
#if (   (FEE_30_SMALLSECTOR_CFG_MAJOR_VERSION != (2u)) \
     || (FEE_30_SMALLSECTOR_CFG_MINOR_VERSION != (0u)))
# error "Version numbers of Fee_30_SmallSector_Cfg.c and Fee_30_SmallSector_Cfg.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

#define FEE_30_SMALLSECTOR_START_SEC_CONST_8BIT
#include "MemMap.h"    /* PRQA S 5087 */ /* MD_MSR_19.1 */

CONST(uint8, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_DatasetSelectionBits = (4U);

#define FEE_30_SMALLSECTOR_STOP_SEC_CONST_8BIT
#include "MemMap.h"   /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define FEE_30_SMALLSECTOR_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_19.1 */

/* PRQA S 686 PARTITIONLIST */ /* MD_FEE_30_SMALLSECTOR_9.2 */
CONST(Fee_30_SmallSector_PartitionConfigType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_PartitionConfigList[FEE_30_SMALLSECTOR_NUMBER_OF_PARTITIONS] = 
{
   /*  FEEPARTITIONCONFIGURATION  */ {
     /*  Partition Start Address  */ 0x00000000UL, 
     /*  Partition Address Alignment  */ 0x0040U, 
     /*  Partition Write Alignment  */ 0x0004U, 
     /*  Partition Read Alignment  */ 0x0001U, 
     /*  FLS Device Index  */ 0x0000U, 
     /*  FLS API Reference  */ &Fee_30_SmallSector_FlsApi0, 
     /*  FLS Erase Value  */ 0xFFU, 
     /*  FLS Blank Check API Enabled  */ FALSE, 
    {
       /*  FeeConfigBlock  */ 0x0010U, 
       /*  FblGeneral  */ 0x0020U, 
       /*  FblDid  */ 0x0030U, 
       /*  FblMetaData  */ 0x0040U
    }
  }
};
/* PRQA L: PARTITIONLIST */

/* BlockConfigList is sorted by BlockNumbers in ascending order */
CONST(Fee_30_SmallSector_BlockConfigType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_BlockConfigList[FEE_30_SMALLSECTOR_NUMBER_OF_BLOCKS] =
{
  {
     /*  Block Start Address  */ 0x00000000UL, 
     /*  Data Length  */ 0x0004U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x02U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000080UL, 
     /*  Data Length  */ 0x000DU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x000000C0UL, 
     /*  Data Length  */ 0x0026U, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }, 
  {
     /*  Block Start Address  */ 0x00000100UL, 
     /*  Data Length  */ 0x002DU, 
     /*  Number Of Instances  */ 0x01U, 
     /*  Number Of Datasets  */ 0x01U, 
     /*  Immediate Data Block  */ FALSE, 
     /*  Data Verification Enabled  */ FALSE
  }
};
/* FLS API pointer table */
CONST(Fee_30_SmallSector_FlsApiType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_FlsApi0 = 
{
   /*  Read Service  */ Fls_Read, 
   /*  Write Service  */ Fls_Write, 
   /*  Compare Service  */ Fls_Compare, 
   /*  Erase Service  */ Fls_Erase, 
   /*  Blank Check Service  */ NULL_PTR, 
   /*  Get Status Service  */ Fls_GetStatus, 
   /*  Get Job Result Service  */ Fls_GetJobResult
};
 

/**** NvM Callback Assignments ****/
CONST(Fee_30_SmallSector_CbkJobEndNotificationType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_CbkJobEndNotification =
    NULL_PTR;
CONST(Fee_30_SmallSector_CbkJobErrorNotificationType, FEE_30_SMALLSECTOR_PRIVATE_CONST) Fee_30_SmallSector_CbkJobErrorNotification =
    NULL_PTR;

#define FEE_30_SMALLSECTOR_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"	/* PRQA S 5087 */ /* MD_MSR_19.1 */

/* Justification for module-specific MISRA deviations:
 MD_FEE_30_SMALLSECTOR_9.2: rule 9.2
      Reason:     Array size of Fee_30_SmallSector_PartitionConfigType.BlockNumberList depends on maximum number of blocks in one partition.             
      Risk:       No risk. Partitions with fewer blocks and thus BlockNumberLists with fewer initializers are implicitly 
                  initialized to zero.
      Prevention: Program flow has been verified by component tests and review.
*/

/**********************************************************************************************************************
 *  END OF FILE: Fee_30_SmallSector_Cfg.c
 *********************************************************************************************************************/

