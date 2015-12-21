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
/** \file sv6p1615.h
 **
 ** SV6P1615 (PSRAM) driver header file
 **
 ** History:
 ** - 2015-01-31  1.0   EZh  First version for FM universal PDL
 **
 *****************************************************************************/

#ifndef __SV6P1615_H__
#define __SV6P1615_H__

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "mcu.h"
#include "pdl_user.h"
#include "gpio.h"
#include "extif\extif.h"   


#if (PDL_UTILITY_ENABLE_EXTIF_SV6P1615 == PDL_ON)   
   
/**
 ******************************************************************************
 ** \defgroup Sv6p1615Group 
 **
 ** Provided SV6P1615 module functions:
 **
 ** - Sv6p1615_Init()
 **
 ** Sv6p1615_Init() initializes Hyper bus and allcates SV6P1615 to 
 ** a certain area.
 **
 ******************************************************************************/
/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif
  
//@{  

/*****************************************************************************/
/* Global pre-processor symbols/macros ('define')                            */
/*****************************************************************************/  
 
/******************************************************************************
 * Global definitions
 ******************************************************************************/

/*****************************************************************************/
/* Global type definitions ('typedef')                                       */
/*****************************************************************************/

/**
 ******************************************************************************
 ** \brief PSRAM size setting 
 ******************************************************************************/
typedef enum en_psram_size
{
    Psram1MB   = 0u,  ///< Size 1 MByte 
    Psram2MB   = 1u,  ///< Size 2 MByte 
    Psram4MB   = 2u,  ///< Size 4 MByte 
    Psram8MB   = 3u,  ///< Size 8 MByte 
    Psram16MB  = 4u,  ///< Size 16 MByte 
    Psram32MB  = 5u,  ///< Size 32 MByte 
    Psram64MB  = 6u,  ///< Size 64 MByte 
    Psram128MB = 7u,  ///< Size 128 MByte 
} en_psram_size_t;
  
/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source)           */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/
en_result_t Sv6p1615_Init(uint8_t u8CsArea, 
                          uint32_t u32BaseAddress,
                          en_psram_size_t enSize) ;

//@}
#ifdef __cplusplus
}
#endif

#endif

#endif /* __SV6P1615_H__ */
/*****************************************************************************/
/* EOF (not truncated)                                                       */
/*****************************************************************************/
