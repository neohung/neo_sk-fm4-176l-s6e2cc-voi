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
/******************************************************************************/
/** \file uart_printf.h
 **
 ** Headerfile for UART printf functions
 **  
 ** History:
 **   - 2014-11-03  1.0  EZh   First version for FM uinversal PDL.
 **
 ******************************************************************************/

#ifndef __UART_IO__
#define __UART_IO__

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "mcu.h"
#include "pdl_user.h"
#include <stdio.h>

#if (PDL_UTILITY_ENABLE_UART_PRINTF == PDL_ON)

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup UartPrintfGroup Uart Input/Output Function
 **
 ** Provided functions of UartIoGroup module:
 **
 ** - Uart_Io_Init()
 ** - fputc()
 ** - fgetc()
 **
 ** To enable the pirntf/scanf via UART0 funciton, Uart_Io_Init() must be called
 ** to initialize UART0.
 **
 ** fputc() will be called in printf() to output one byte via UART0. 
 ** fgetc() will be called in scanf() to receive one byte from UART0. 
 **
 ******************************************************************************/
//@{

/******************************************************************************/
/* Global pre-processor symbols/macros ('#define')                            */
/******************************************************************************/
 
/******************************************************************************
 * Global type definitions
 ******************************************************************************/

/******************************************************************************/
/* Global variable definitions ('extern')                                     */
/******************************************************************************/

/******************************************************************************/
/* Global function prototypes (definition in C source)                        */
/******************************************************************************/
void Uart_Io_Init(void);
int fputc(int ch, FILE *f);
int fgetc(FILE *f);

//@} // UartPrintfGroup

#ifdef __cplusplus
}
#endif

#endif /* #if (PDL_UTILITY_ENABLE_UART_PRINTF == PDL_ON) */

#endif /* __UART_PRINTF__ */
/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
