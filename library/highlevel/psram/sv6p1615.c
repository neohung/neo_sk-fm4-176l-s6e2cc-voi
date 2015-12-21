/*************************************************************************************
* Copyright (C) 2013-2015, Cypress Semiconductor Corporation. All rights reserved.    
*                                                                                     
* This software, including source code, documentation and related                     
* materials ( "Software" ), is owned by Cypress Semiconductor                         
* Corporation ( "Cypress" ) and is protected by and subject to worldwide              
* patent protection (United States and foreign), United States copyright              
* laws and international treaty provisions. Therefore, you may use this               
* Software only as provided in the license agreement accompanying the                 
* software package from which you obtained this Software ( "EULA" ).                  
* If no EULA applies, Cypress hereby grants you a personal, nonexclusive,             
* non-transferable license to copy, modify, and compile the                           
* Software source code solely for use in connection with Cypress's                    
* integrated circuit products. Any reproduction, modification, translation,           
* compilation, or representation of this Software except as specified                 
* above is prohibited without the express written permission of Cypress.              
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO                                
* WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING,                                
* BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED                                        
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A                                     
* PARTICULAR PURPOSE. Cypress reserves the right to make                              
* changes to the Software without notice. Cypress does not assume any                 
* liability arising out of the application or use of the Software or any              
* product or circuit described in the Software. Cypress does not                      
* authorize its products for use in any products where a malfunction or               
* failure of the Cypress product may reasonably be expected to result in              
* significant property damage, injury or death ( "High Risk Product" ). By            
* including Cypress's product in a High Risk Product, the manufacturer                
* of such system or application assumes all risk of such use and in doing             
* so agrees to indemnify Cypress against all liability.                               
*/

/*****************************************************************************/
/** \file s26kl512s.c
 **
 ** S26KL512S driver API functions
 **
 ** History:
 ** - 2015-01-28  1.0   EZh  First version for FM universal PDL
 **
 *****************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "sv6p1615.h"

#if (PDL_UTILITY_ENABLE_EXTIF_SV6P1615 == PDL_ON)   
   
/**
 ******************************************************************************
 ** \addtogroup S26kl512sGroup
 ******************************************************************************/
//@{   

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/

/******************************************************************************/
/* Local function prototypes                                                  */
/******************************************************************************/

/**
 ******************************************************************************
 ** \brief Initialize SV6P1615
 **
 ** This function maps SV6P1615 to a certain external area
 **
 ** \param [in]  u8CsArea        Chip selection area selected
 ** \param [in]  u32BaseAddress  Base address of SV6P1615
 ** \param [in]  enSize          PSRAM size   
 **
 ** \retval Ok                    SV6P1615 initialized normally
 ** \retval Error                 Invalid configuration
 ******************************************************************************/
en_result_t Sv6p1615_Init(uint8_t u8CsArea, 
                          uint32_t u32BaseAddress,
                          en_psram_size_t enSize)
{
    stc_extif_area_config_t stcMemConfig;
    
    // Clear structure
    PDL_ZERO_STRUCT(stcMemConfig);
    
    stcMemConfig.enWidth = Extif16Bit;    // 16-bit width
    stcMemConfig.bReadByteMask = TRUE;    // Use read byte mask
    stcMemConfig.bWriteEnableOff = FALSE; // Don't enable write enable off
    stcMemConfig.bNandFlash  = FALSE;     // Disable Nand Flash mode
    stcMemConfig.bPageAccess = FALSE;     // Disable page access 
    stcMemConfig.bRdyOn = FALSE;          // Don't use ready signal
    stcMemConfig.bStopDataOutAtFirstIdle = TRUE;  // Stop data output at first idle cycle
    stcMemConfig.bMultiplexMode = FALSE;          // Single mode
    stcMemConfig.bAleInvert = FALSE;              // Don't invert ALE
    stcMemConfig.bAddrOnDataLinesOff = TRUE;      // Don't output address on data lines
    stcMemConfig.bMpxcsOff = FALSE;               // Assert MCSX in ALC cycle period
    stcMemConfig.bMoexWidthAsFradc = FALSE;       // MOEX width is set with RACC-RADC 
    
    stcMemConfig.enReadAccessCycle          = Extif4Cycle;  // Read Access Cycle timing
    stcMemConfig.enReadAddressSetupCycle    = Extif0Cycle;  // Read Address Set-up Cycle timing
    stcMemConfig.enFirstReadAddressCycle    = Extif1Cycle;  // First Read Address Cycle timing
    stcMemConfig.enReadIdleCycle            = Extif1Cycle;  // Read Idle Cycle timing
    stcMemConfig.enWriteAccessCycle         = Extif5Cycle;  // Write Access Cycle timing
    stcMemConfig.enWriteAddressSetupCycle   = Extif1Cycle;  // Write Address Set-up Cycle timing
    stcMemConfig.enWriteEnableCycle         = Extif4Cycle;  // Write Enable Cycle timing
    stcMemConfig.enWriteIdleCycle           = Extif1Cycle;  // Write Idle Cycle timing
    
    stcMemConfig.u8AreaAddress = ((u32BaseAddress >> 20u) & 0x00FFu);
    stcMemConfig.enAreaMask = (en_extif_mask_t) enSize;
    stcMemConfig.enAddressLatchCycle = Extif16Cycle;
    stcMemConfig.enAddressLatchSetupCycle = Extif5Cycle;
    stcMemConfig.enAddressLatchWidthCycle = Extif5Cycle;
    stcMemConfig.bMclkoutEnable = FALSE;
    stcMemConfig.u8MclkDivision = 3u;
    
    if (Ok != Extif_InitArea(u8CsArea, &stcMemConfig))
    {
        return Error;
    }
    
    return Ok;
}


//@} // Sv6p1615Group  

#endif

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
