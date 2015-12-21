/*******************************************************************************
* Copyright (C) 2013 Spansion LLC. All Rights Reserved.
*
* This software is owned and published by:
* Spansion LLC, 915 DeGuigne Dr. Sunnyvale, CA  94088-3453 ("Spansion").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with Spansion
* components. This software is licensed by Spansion to be adapted only
* for use in systems utilizing Spansion components. Spansion shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein.  Spansion is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* SPANSION MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS),
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
* WARRANTY OF NONINFRINGEMENT.
* SPANSION SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
* SAVINGS OR PROFITS,
* EVEN IF SPANSION HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
* FROM, THE SOFTWARE.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with each copy of this software, whether used in part or whole,
* at all times.
*/
/******************************************************************************/
/** \file pdl.h
 **
 ** Common headerfile for FM Peripheral Driver Library
 **
 ** History:
 **   - 2014-09-16  0.1  EZh  First version for FM universal PDL.
 **
 ******************************************************************************/

#ifndef __PDL_H__
#define __PDL_H__

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "mcu.h"

/* C binding of definitions if building with C++ compiler                     */
#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************/
/* Global pre-processor symbols/macros ('#define')                            */
/* Macro for initializing local structures to zero                            */
/******************************************************************************/
#define PDL_ZERO_STRUCT(x) pdl_memclr((uint8_t*)&(x), (uint32_t)(sizeof(x)))

/**
 ******************************************************************************
 ** All definitions needed for pdl_user.h are stated here
 ******************************************************************************/
#define PDL_ON            1u    ///< Switches a feature on
#define PDL_OFF           0u    ///< Switches a feature off

/**
 ******************************************************************************
 ** Global Device type definitions
 ** Note that an existing definition does not implicitly means full device
 ** type support of this library!
 ******************************************************************************/
// FM0+ device type  
#define PDL_FM0P_TYPE0   0100u  ///< FM0+ device type0
#define PDL_FM0P_TYPE1   0101u  ///< FM0+ device type1
#define PDL_FM0P_TYPE2   0102u  ///< FM0+ device type2
#define PDL_FM0P_TYPE3   0103u  ///< FM0+ device type3
#define PDL_FM0P_TYPE4   0104u  ///< FM0+ device type4
#define PDL_FM0P_TYPE5   0105u  ///< FM0+ device type5
#define PDL_FM0P_TYPE6   0106u  ///< FM0+ device type6
#define PDL_FM0P_TYPE7   0107u  ///< FM0+ device type7
#define PDL_FM0P_TYPE8   0108u  ///< FM0+ device type8
#define PDL_FM0P_TYPE9   0109u  ///< FM0+ device type9
// FM3 device type  
#define PDL_FM3_TYPE0    3000u  ///< FM3 device type0
#define PDL_FM3_TYPE1    3001u  ///< FM3 device type1
#define PDL_FM3_TYPE2    3002u  ///< FM3 device type2
#define PDL_FM3_TYPE3    3003u  ///< FM3 device type3
#define PDL_FM3_TYPE4    3004u  ///< FM3 device type4
#define PDL_FM3_TYPE5    3005u  ///< FM3 device type5
#define PDL_FM3_TYPE6    3006u  ///< FM3 device type6
#define PDL_FM3_TYPE7    3007u  ///< FM3 device type7
#define PDL_FM3_TYPE8    3008u  ///< FM3 device type8
#define PDL_FM3_TYPE9    3009u  ///< FM3 device type9
#define PDL_FM3_TYPE10   3010u  ///< FM3 device type10
#define PDL_FM3_TYPE11   3011u  ///< FM3 device type11
#define PDL_FM3_TYPE12   3012u  ///< FM3 device type12
// FM4 device type  
#define PDL_FM4_TYPE0    4000u  ///< FM4 device type0
#define PDL_FM4_TYPE1    4001u  ///< FM4 device type1
#define PDL_FM4_TYPE2    4002u  ///< FM4 device type2
#define PDL_FM4_TYPE3    4003u  ///< FM4 device type3
#define PDL_FM4_TYPE4    4004u  ///< FM4 device type4
#define PDL_FM4_TYPE5    4005u  ///< FM4 device type5
#define PDL_FM4_TYPE6    4006u  ///< FM4 device type6
#define PDL_FM4_TYPE7    4007u  ///< FM4 device type7
#define PDL_FM4_TYPE8    4008u  ///< FM4 device type8
#define PDL_FM4_TYPE9    4009u  ///< FM4 device type9
  
#define PDL_MCU_TYPE     FM_DEVICE_TYPE    // Definition from peripheral header

/**
 ******************************************************************************
 ** Global Device Core list
 ******************************************************************************/
#define PDL_FM0P_CORE            10u
#define PDL_FM3_CORE             20u
#define PDL_FM4_CORE             30u  
  
#ifdef FM_CORE_TYPE_FM0P                // Definition from peripheral header
#define PDL_MCU_CORE     PDL_FM0P_CORE 
#endif
  
#ifdef FM_CORE_TYPE_FM3                 // Definition from peripheral header
#define PDL_MCU_CORE     PDL_FM3_CORE 
#endif
  
#ifdef FM_CORE_TYPE_FM4                 // Definition from peripheral header
#define PDL_MCU_CORE     PDL_FM4_CORE 
#endif
  
/**
 ******************************************************************************
 ** Global Device interrupt list
 ******************************************************************************/  
// FM0+ interrupt type
#define PDL_FM0P_INT_TYPE_1_A                0100u
#define PDL_FM0P_INT_TYPE_1_B                0101u
#define PDL_FM0P_INT_TYPE_2_A                0102u
#define PDL_FM0P_INT_TYPE_2_B                0103u   
#define PDL_FM0P_INT_TYPE_3                  0104u   
  
// FM3 interrupt type
#define PDL_FM3_INT_TYPE_A                   3000u
#define PDL_FM3_INT_TYPE_B                   3001u
#define PDL_FM3_INT_TYPE_C                   3002u
   
// FM4 interrupt type
#define PDL_FM4_INT_TYPE_A                   4000u
#define PDL_FM4_INT_TYPE_B                   4001u
#define PDL_FM4_INT_TYPE_C                   4002u   
   
#define PDL_MCU_INT_TYPE    FM_INTERRUPT_TYPE // Definition from peripheral header
  
/******************************************************************************/
/* User Device Setting Include file                                           */
/******************************************************************************/
//#include "pdl_device.h"  // MUST be included here!

/**
 ******************************************************************************
 ** Default Interrupt Level (lowest priority, used for De-Init functions)
 ******************************************************************************/
#if (PDL_MCU_CORE == PDL_FM3_CORE) || (PDL_MCU_CORE == PDL_FM4_CORE)       
#define PDL_DEFAULT_INTERRUPT_LEVEL 0x0Fu
#else
#define PDL_DEFAULT_INTERRUPT_LEVEL 0x03u        
#endif  

/******************************************************************************/
/* Global type definitions ('typedef')                                        */
/******************************************************************************/
/**
 ******************************************************************************
 ** \brief Level
 **
 ** Specifies levels.
 **
 ******************************************************************************/
typedef enum en_level
{
    PdlLow      = 0u,  ///< Low level '0'
    PdlHigh     = 1u   ///< High level '1'
} en_level_t;

/**
 ******************************************************************************
 ** \brief Generic Flag Code
 **
 ** Specifies flags.
 **
 ******************************************************************************/
typedef enum en_flag
{
    PdlClr = 0u,       ///< Flag clr '0'
    PdlSet = 1u        ///< Flag set '1'
} en_stat_flag_t, en_irq_flag_t;

/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source)           */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/

/******************************************************************************
 * Global function prototypes
 ******************************************************************************/
extern void pdl_memclr(uint8_t* pu32Address, uint32_t u32Count);

/**
 ******************************************************************************
 ** This hook is part of wait loops.
 ******************************************************************************/
extern void PDL_WAIT_LOOP_HOOK(void);

#ifdef __cplusplus
}
#endif

#endif /* __PDL_H__ */

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
