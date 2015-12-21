/*******************************************************************************
* Copyright (C) 2015 Spansion LLC. All Rights Reserved. 
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
/** \file interrupts.c
 **
 ** PDL Interrupt Handler Inclusion for PDL
 **
 ** A detailed description is available at 
 ** @link PdlInterrupts PDL Interrupt handling description @endlink
 **
 ** History:
 **   - 2015-07-02  1.0  MWi   First version for universal PDL        
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "pdl.h"

#if (PDL_MCU_CORE == PDL_FM0P_CORE)

  #if (PDL_MCU_INT_TYPE == PDL_FM0P_INT_TYPE_1_A)
    #define __INTERRUPTS_FM0P_TYPE_1_A_C__
    #include "interrupts_fm0p_type_1-a.c"

  #elif (PDL_MCU_INT_TYPE == PDL_FM0P_INT_TYPE_1_B)
    #define __INTERRUPTS_FM0P_TYPE_1_B_C__
    #include "interrupts_fm0p_type_1-b.c"
    
  #elif (PDL_MCU_INT_TYPE == PDL_FM0P_INT_TYPE_2_A)
    #define __INTERRUPTS_FM0P_TYPE_2_A_C__
    #include "interrupts_fm0p_type_2-a.c"
    
  #elif (PDL_MCU_INT_TYPE == PDL_FM0P_INT_TYPE_2_B)
    #define __INTERRUPTS_FM0P_TYPE_2_B_C__
    #include "interrupts_fm0p_type_2-b.c"
    
  #elif (PDL_MCU_INT_TYPE == PDL_FM0P_INT_TYPE_3)
    #define __INTERRUPTS_FM0P_TYPE_3_C__
    #include "interrupts_fm0p_type_3.c"
    
  #else
    #error Interrupt Type for FM0+ not defined!
  #endif

#elif (PDL_MCU_CORE == PDL_FM3_CORE)

  #if (PDL_MCU_INT_TYPE == PDL_FM3_INT_TYPE_A)
    #define __INTERRUPTS_FM3_TYPE_A_C__
    #include "interrupts_fm3_type_a.c"

  #elif (PDL_MCU_INT_TYPE == PDL_FM3_INT_TYPE_B)
    #define __INTERRUPTS_FM3_TYPE_B_C__
    #include "interrupts_fm3_type_b.c"
    
  #elif (PDL_MCU_INT_TYPE == PDL_FM3_INT_TYPE_C)
    #define __INTERRUPTS_FM3_TYPE_C_C__
    #include "interrupts_fm3_type_c.c"
  
  #else
    #error Interrupt Type for FM3 not defined!
  #endif

#elif (PDL_MCU_CORE == PDL_FM4_CORE)
  #if (PDL_MCU_INT_TYPE == PDL_FM4_INT_TYPE_A)
    #define __INTERRUPTS_FM4_TYPE_A_C__
    #include "interrupts_fm4_type_a.c"

  #elif (PDL_MCU_INT_TYPE == PDL_FM4_INT_TYPE_B)
    #define __INTERRUPTS_FM4_TYPE_B_C__
    #include "interrupts_fm4_type_b.c"
    
  #elif (PDL_MCU_INT_TYPE == PDL_FM4_INT_TYPE_C)
    #define __INTERRUPTS_FM4_TYPE_C_C__
    #include "interrupts_fm4_type_c.c"
    
  #else
    #error Interrupt Type for FM4 not defined!
  #endif

#else
    #error FM core not defined!
#endif
  
/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
