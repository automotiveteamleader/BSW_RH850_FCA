
/**********************************************************************************************************************
  COPYRIGHT
-----------------------------------------------------------------------------------------------------------------------
  \par      copyright
  \verbatim
  Copyright (c) 2014 by Vector Informatik GmbH.                                                  All rights reserved.

                This software is copyright protected and proprietary to Vector Informatik GmbH.
                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
                All other rights remain with Vector Informatik GmbH.
  \endverbatim
-----------------------------------------------------------------------------------------------------------------------
  FILE DESCRIPTION
-----------------------------------------------------------------------------------------------------------------------
  \file  File:  startup.c
      Project:  Vector Basic Runtime System
       Module:  BrsHw for Platform RH850
    Generator:  -

  \brief Description:  This file consists of the Startup Code.
**********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
-----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
-----------------------------------------------------------------------------------------------------------------------
  Jan Lutterbeck                visljn        Vector Informatik GmbH
  Torsten Kercher               vistkr        Vector Informatik GmbH
  Alexander Becker              visabc        Vector Informatik GmbH
  Benjamin Walter               visbwa        Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
 ----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Change Id     Description
 ----------------------------------------------------------------------------------------------------------------------
  01.00.00  2012-07-12  visljn  -             Initial version for RH850
  01.03.00  2013-08-14  visljn  -             Support for GHS and DiabData compiler
  01.04.00  2013-08-20  vistkr  -             Use V_ switches
  01.05.00  2013-09-20  visabc  -             P1X added
  01.06.00  2013-11-11  visljn  -             R1M added
  01.07.00  2014-01-21  visljn  -             Cleanup
  01.08.00  2014-05-20  vistkr  -             Added support for IAR compiler
  02.00.00  2014-07-30  visbwa  -             Complete rework of zBrs_Rh850, according to styleguide Vector_BrsHw_2.0
**********************************************************************************************************************/

/**********************************************************************************************************************
  DEFINES
**********************************************************************************************************************/
#define ___asm(c)               __asm_(c)
#define __asm_(c)               asm(" " #c);
#define __as1(c, d)             __as1_(c, d)
#define __as1_(c, d)            asm(" " #c " , " #d);
#define __as2(c, d, e)          __as2_(c, d, e)
#define __as2_(c, d, e)         asm(" " #c " , " #d " , " #e);
#define IRAM_START              0xFEBE0000
#define IRAM_END                0xFEBFFFFF


___asm(;/* =========================================================================== */)
___asm(;/* Definition of external functions                                            */)
___asm(;/* =========================================================================== */)

___asm(;/* reset */)
___asm(.globl __usr_init)


___asm(.section ".text")


___asm(;/* =========================================================================== */)
___asm(;/* _RESET                                                                      */)
___asm(;/*                                                                             */)
___asm(;/* Description: Initialize stack pointer, SDA data pointer and text pointer.   */)
___asm(;/*              Configure INTBP and EBASE address.                             */)
___asm(;/*                                                                             */)
___asm(;/* =========================================================================== */)

___asm(;/* _RESET: */)
___asm(__usr_init:)

___asm(;/* =========================================================================== */)
___asm(;/* == COMPILER SPECIFIC INIT                                            ====== */)
___asm(;/* =========================================================================== */)

  ___asm(;/* Initialisation of the global pointer */)
  __as2(movhi hi(___ghsbegin_sdabase), zero, gp)
  __as2(movea lo(___ghsbegin_sdabase), gp, gp)

  ___asm(;/* Initialisation of the text pointer */)
  __as2(movhi hi(___ghsbegin_robase), zero, tp)
  __as2(movea lo(___ghsbegin_robase), tp, tp)

  ___asm(;/* Initialisation of the stack pointer */)
  __as2(movhi hi(___ghsend_stack-4), zero, sp)
  __as2(movea lo(___ghsend_stack-4), sp, sp)
  __as1(mov   -4, r1)
  __as1(and   r1, sp)

  ___asm(;/* Set INTBP base address for interrupt handler table */)
  __as1(mov   0x200, r6;/* exception handler base address*/)
  __as2(ldsr  r6, 4, 1;/* INTBP*/)
  __as2(stsr  4, r6, 1;/* INTBP*/)

  ___asm(;/* Set EBASE register value */)
  __as1(mov   zero, r6)
  __as2(ldsr  r6,3,1)
  __as2(stsr  3, r6, 1)
  __as1(mov   zero, r6)

  ___asm(;/* set PSW.EBV bit to 1 to use EBASE as exception vector base address */)
  __as2(stsr  5, r1, 0)
  __as1(mov   0x8000, r2)
  __as1(or    r2, r1)
  __as2(ldsr  r1, 5, 0)

  ___asm(;/* Check for 0x080 (application reset) in RESF */)
  ___asm(;/* If flag is not set, clear iRAM and clear flag */)
  __as1(ld.w      -520192[r0], r18)
  __as2(andi      0x080, r18, r18)
  ___asm(bnz       clear_iRAM_done)

  ___asm(;/* Clear RAM with value of 0 */)
  __as1(mov     IRAM_START, r6;/* r6 = Start address*/)
  __as1(mov     (IRAM_END +1 - IRAM_START) >> 2, r7;/* r7 = Word(32-Bit) count */)
___asm(clear_iRAM:)
  __as1(st.w    r0, 0[r6];/* store 0 to address which is in r6 */)
  __as1(add     4, r6;/* increment address */)
  __as1(loop    r7, clear_iRAM;/* loop until 512KB written */)

___asm(clear_iRAM_done:)

  ___asm(;/* Clear flag 0x080 (application reset) in RESFC */)
  __as1(ld.w      -520184[r0], r18)
  __as2(addi      0x080, r0, r17)
  __as1(or        r17, r18)
  __as1(st.w      r18, -520184[r0])

  ___asm(;/* Jump to the Initialization functions of the GHS "crt.o" library ! */)
  ___asm(jr __start)


___asm(;/*-------------------------------------------------------------------------------*/)































	














































































