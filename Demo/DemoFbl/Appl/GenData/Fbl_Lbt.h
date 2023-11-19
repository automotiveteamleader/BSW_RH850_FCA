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
 *            Module: Fbl
 *           Program: FBL Fca SLP5 (FBL_Fca_SLP5)
 *          Customer: Nexteer Automotive Corporation
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: R7F701374A
 *    License Scope : The usage is restricted to CBD1800284_D00
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Fbl_Lbt.h
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


#if !defined(__FBL_MTAB_H__)
#define __FBL_MTAB_H__

/* Defines ***********************************************************************************************************/
#define FBL_MTAB_DEMOAPPL_BLOCK_NUMBER 0 
#define FBL_MTAB_DEMOAPPL_BLOCK_INDEX  0x00000000UL 
#define kBlockTypeCode                 0x00000001UL 
#define kBlockTypeData                 0x00000002UL 
#define kBlockTypeBoot                 0x00000000UL 
#define kBlockTypeCodeNoOfBlocks       0x00000001UL 
#define kBlockTypeDataNoOfBlocks       0x00000000UL 
#define kBlockTypeBootNoOfBlocks       0x00000000UL 
#define FBL_MTAB_NO_OF_BLOCKS          1 
#define kNrOfValidationBytes           1 

/* Macro to determine if the block table is valid */
#define FBL_MTAB_MAGIC_FLAG               0xB5A4C3D2UL
#define IsLogicalBlockTableValid()        (FblLogicalBlockTable.magicFlag == FBL_MTAB_MAGIC_FLAG)

/* Typedefs **********************************************************************************************************/

/* Entry type of logical block table */
typedef struct tBlockDescriptorTag {
  vuint8 blockNr; /*  Number of logical block  */ 
  vuint32 blockIndex;
  vuint32 blockType;
  tFblAddress blockStartAddress; /*  Start address of current block  */ 
  tFblLength blockLength; /*  Block length in bytes  */ 
  vuint16 maxProgAttempts; /*  Maximum number of reprogramming attempts  */ 
  tExportFct verifyInput; /*  Input Verification  */ 
  tExportFct verifyProcessed; /*  Processed Verification  */ 
  tExportFct verifyPipelined; /*  Pipelined Verification  */ 
  tExportFct verifyOutput; /*  Output Verification  */ 
} tBlockDescriptor;

/* The logical block table describes the memory layout of logical blocks */
typedef struct tLogicalBlockTableTag {
  vuint32 magicFlag; /*  Value of FBL_MTAB_MAGIC_FLAG - Indicates the existence of the table  */ 
  vuint8 assignFlags[kNrOfValidationBytes]; /*  Disposability bit field (mandatory/optional)  */ 
  vuint8 noOfBlocks; /*  Number of configured logical blocks  */ 
  tBlockDescriptor logicalBlock[FBL_MTAB_NO_OF_BLOCKS];
} tLogicalBlockTable;

/* Global data *******************************************************************************************************/
V_MEMROM0 extern  V_MEMROM1 tLogicalBlockTable V_MEMROM2 FblLogicalBlockTable;

#endif /* __FBL_MTAB_H__ */

