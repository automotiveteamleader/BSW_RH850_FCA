/****************************************************************************
 ** Main author: Alf                     Creation date: 03/05/2005
 ** $LastChangedBy: mneuhaus $
 ** $Date: 2018-02-12 16:11:47 +0100 (Mo, 12 Feb 2018) $
 ** $URL: https://subversion/svn/library-ES/branches/library-es/1.2.0-VectorInformatik/development/common/lib_es/source/ESLib_version.c $
 ** $Rev: 2709 $
 ** $NoKeywords$
 **
 **
 ** \copyright(cv cryptovision GmbH, 1999 - 2005)                            *
 **
 ** \version(cvActLibES 1.0)                                                 *
 ***************************************************************************/

/****************************************************************************
 **
 **     This file is part of the embedded systems library cvActLib/ES.
 **
 **     Layer: core level
 **
 ***************************************************************************/

/****************************************************************************
 **
 ** This file contains: A String, that can be read out fom any delivery,
 **                     in order to get information about the Revision and
 **                     date of build.
 **
 ** variables:  ESLib_Version String that holds information on latest build
 **             of a library
 **
 **
 ***************************************************************************/


#include "ESLib.h"
#include "actConfig.h"

/* Version string */
CRYPTOCV_CONST( CRYPTOCV_NONE, char ) ESLib_Version[] = "cv_Act_Library_ES_Version_1.2.11, " __DATE__;


#ifdef __HARVARD
CRYPTOCV_CONST( CRYPTOCV_NONE, char ) ESLib_Params_[] = "CPU address size (bits)  ";
CRYPTOCV_CONST( CRYPTOCV_NONE, char ) ESLib_Params0[] = "actBN_BITS_PER_DIGIT     ";
CRYPTOCV_CONST( CRYPTOCV_NONE, char ) ESLib_Params1[] = "actBN_MONT_MUL_VERSION   ";
CRYPTOCV_CONST( CRYPTOCV_NONE, char ) ESLib_Params2[] = "actBN_MOD_EXP_WINDOW_SIZE";
CRYPTOCV_CONST( CRYPTOCV_NONE, char ) ESLib_Params3[] = "actSHA_SPEED_UP          ";
CRYPTOCV_CONST( CRYPTOCV_NONE, char ) ESLib_Params4[] = "actRMD160_SPEED_UP       ";
CRYPTOCV_CONST( CRYPTOCV_NONE, char ) ESLib_Params5[] = "actSHA256_SPEED_UP       ";
CRYPTOCV_CONST( CRYPTOCV_NONE, char ) ESLib_Params6[] = "actSHA512_SPEED_UP       ";
CRYPTOCV_CONST( CRYPTOCV_NONE, char ) ESLib_Params7[] = "actMD5_SPEED_UP          ";
CRYPTOCV_CONST( CRYPTOCV_NONE, char ) ESLib_Params8[] = "actAES_SPEED_UP          ";
CRYPTOCV_CONST( CRYPTOCV_NONE, char ) ESLib_Params9[] = "actGHASH_SPEED_UP        ";
CRYPTOCV_CONST( CRYPTOCV_NONE, char ) ESLib_ParamsZ[] = "actWD_LEVEL              ";
/* insert new settings here! */
CRYPTOCV_CONST( CRYPTOCV_NONE, eslt_Version ) ESLib_Params[] =
{
   ESLib_Params_, ACT_CPU_ADDRESS_SIZE,
   ESLib_Params0, actBN_BITS_PER_DIGIT,
   ESLib_Params1, actBN_MONT_MUL_VERSION,
   ESLib_Params2, actBN_MOD_EXP_WINDOW_SIZE,
   ESLib_Params3, actSHA_SPEED_UP,
   ESLib_Params4, actRMD160_SPEED_UP,
   ESLib_Params5, actSHA256_SPEED_UP,
   ESLib_Params6, actSHA512_SPEED_UP,
   ESLib_Params7, actMD5_SPEED_UP,
   ESLib_Params8, actAES_SPEED_UP,
   ESLib_Params9, actGHASH_SPEED_UP,
/* insert new settings here! */
   ESLib_ParamsZ, actWD_LEVEL,
   NULL
};
#else
#define param(p,s)    {#p s, p}

CRYPTOCV_CONST( CRYPTOCV_NONE, eslt_Version ) ESLib_Params[] =
{
/* param(LITTLE_ENDIAN, "            "),*/   /* NO value */
   param(ACT_CPU_ADDRESS_SIZE, "  "),
   param(actBN_BITS_PER_DIGIT, "     "),
   param(actBN_MONT_MUL_VERSION, "   "),
/* param(actNO_INDIRECT_CALLS, "     "),*/   /* NO value */
   param(actBN_MOD_EXP_WINDOW_SIZE, ""),
/* param(actBN_EUCLID, "             "),*/   /* NO value */
   param(actSHA_SPEED_UP, "          "),
   param(actRMD160_SPEED_UP, "       "),
   param(actSHA256_SPEED_UP, "       "),
   param(actSHA512_SPEED_UP, "       "),
   param(actMD5_SPEED_UP, "          "),
   param(actAES_SPEED_UP, "          "),
   param(actGHASH_SPEED_UP, "        "),
/* param(actPRNG_CALLBACK, "         "),*/   /* NO value */
/* insert new settings here! */
   param(actWD_LEVEL, "              "),
/* keep this as LAST element!! */ { NULL, 0 }
 };
#endif

