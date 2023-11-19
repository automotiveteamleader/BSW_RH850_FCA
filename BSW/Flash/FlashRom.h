/****************************************************************
*
*  Filename:      D:\usr\usage\Delivery\CBD18x\CBD1800284\D00\external\BSW\Flash\Build\..\FlashRom.h
*  Project:       Exported definition of C-Array Flash-Driver
*  File created:  Wed Jul 11 16:42:46 2018

*
****************************************************************/

#ifndef __FLASHDRV__
#define __FLASHDRV__
#define FLASHDRV_GEN_RAND 26181

#define FLASHDRV_NUMBLOCKS 1

#define FLASHDRV_DECRYPTVALUE	0xCC
#define FLASHDRV_DECRYPTDATA(a)   (vuint8)((vuint8)(a) ^ (vuint8)FLASHDRV_DECRYPTVALUE)
#define FLASHDRV_BLOCK0_ADDRESS	0xFEBE0000
#define FLASHDRV_BLOCK0_LENGTH	0x19E0
#define FLASHDRV_BLOCK0_CHECKSUM	0xA851u

V_MEMROM0 extern V_MEMROM1 vuint8 V_MEMROM2 flashDrvBlk0[FLASHDRV_BLOCK0_LENGTH];


#endif    /* #ifdef __FLASHDRV__ */

