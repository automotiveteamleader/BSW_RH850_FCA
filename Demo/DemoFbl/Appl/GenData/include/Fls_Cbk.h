/*============================================================================*/
/* Project      = AUTOSAR Renesas P1x-C MCAL Components                       */
/* Module       = Fls_Cbk.h                                                   */
/* $Revision: 368213 $                                                        */
/* $Date: 2017-02-24 19:52:35 +0530 (Fri, 24 Feb 2017) $                      */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015 Renesas Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains Prototype Declarations for FLS callback Notification    */
/* Functions.                                                                 */
/* AUTOMATICALLY GENERATED FILE - DO NOT EDIT                                 */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        P1x-C                                         */
/*============================================================================*/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
* V1.0.0:  06-Aug-2015    : Initial Version
*
* V1.0.1:  22-Mar-2016    : As part of P1x-C V4.01.00 release the following
*                           modifications are done:
*                           1. CopyRight information is updated.
*                           2. Included Dem.h file.
*                           3. Added FlsEccSedNotification and
*                              FlsEccDedNotification Notifications.
*
* V1.0.2:  08-Aug-2016    :1.As part of ARDAAAF-559 Extern declaration for User
*                            error interface function is added.
*                          2.As part of ARDAAAF-1482 validation for generation
*                            of FlsEccSedNotification,FlsEccDedNotification,
*                            FlsJobEndNotification,FlsJobErrorNotification,
*                            FlsUseWVErrorInterface updated.
*/
/******************************************************************************/
#ifndef FLS_CBK_H
#define FLS_CBK_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem.h"
/*******************************************************************************
**                      Macro definitions                                     **
*******************************************************************************/
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* FLS_CBK SW Major Version */
#define FLS_CBK_SW_MAJOR_VERSION_VALUE              1U
/* FLS_CBK SW Minor Version */
#define FLS_CBK_SW_MINOR_VERSION_VALUE              0U
/* FLS_CBK SW Revision Version */
#define FLS_CBK_SW_PATCH_VERSION_VALUE              2U
/* FLS_CBK AR Major Version */
#define FLS_CBK_AR_RELEASE_MAJOR_VERSION_VALUE      4U
/* FLS_CBK AR Minor Version */
#define FLS_CBK_AR_RELEASE_MINOR_VERSION_VALUE      0U
/* FLS_CBK AR Revision Version */
#define FLS_CBK_AR_RELEASE_REVISION_VERSION_VALUE   3U
/* FLS_CBK Module ID */
#define FLS_CBK_MODULE_ID_VALUE                     92U
/* FLS_CBK Vendor ID */
#define FLS_CBK_VENDOR_ID_VALUE                     59U
/*******************************************************************************
*                         Global Symbols                                       *
*******************************************************************************/
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define FLS_START_SEC_APPL_CODE
#include "MemMap.h"
extern FUNC(void, FLS_APPL_CODE) Fee_30_SmallSector_JobEndNotification(void);
extern FUNC(void, FLS_APPL_CODE) Fee_30_SmallSector_JobErrorNotification(void);
extern FUNC(void, FLS_APPL_CODE) $UsrWVErrNotif_Print \
(Dem_EventIdType WVErrId, uint8 uiApiId);
#define FLS_STOP_SEC_APPL_CODE
#include "MemMap.h"
#endif /* FLS_CBK_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

