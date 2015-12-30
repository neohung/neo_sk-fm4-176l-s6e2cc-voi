/* multicon.c - Source Code for Spansion's Evaluation Board Support Package */
/**************************************************************************
* Copyright (C)2011 Spansion LLC. All Rights Reserved . 
*
* This software is owned and published by: 
* Spansion LLC, 915 DeGuigne Dr. Sunnyvale, CA  94088-3453 ("Spansion").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND 
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software constitutes driver source code for use in programming Spansion's 
* Flash memory components. This software is licensed by Spansion to be adapted only 
* for use in systems utilizing Spansion's Flash memories. Spansion is not be 
* responsible for misuse or illegal use of this software for devices not 
* supported herein.  Spansion is providing this source code "AS IS" and will 
* not be responsible for issues arising from incorrect user implementation 
* of the source code herein.  
*
* SPANSION MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE, 
* REGARDING THE SOFTWARE, ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED 
* USE, INCLUDING, WITHOUT LIMITATION, NO IMPLIED WARRANTY OF MERCHANTABILITY, 
* FITNESS FOR A  PARTICULAR PURPOSE OR USE, OR NONINFRINGEMENT.  SPANSION WILL 
* HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT, NEGLIGENCE OR 
* OTHERWISE) FOR ANY DAMAGES ARISING FROM USE OR INABILITY TO USE THE SOFTWARE, 
* INCLUDING, WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, 
* SPECIAL, OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA, SAVINGS OR PROFITS, 
* EVEN IF SPANSION HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.  
*
* This software may be replicated in part or whole for the licensed use, 
* with the restriction that this Copyright notice must be included with 
* this software, whether used in part or whole, at all times.  
******************************************************************************/
/** \file multicon.c
 **
 **
 ** Supported boards:
 ** - FSSDC-9B506-EVB
 ** - SK-FM3-48PMC-MB9BF524K
 ** - SK-FM3-64PMC1
 ** - SK-FM3-80PMC-MB9BF524M
 ** - SK-FM3-100PMC
 ** - SK-FM3-100PMC-MB9AFB44N
 ** - SK-FM3-100PMC-MB9BF516N
 ** - SK-FM3-176PMC-ETHERNET
 ** - SK-FM3-176PMC-TFT
 ** - SK-FM4-120PMC-TFT
 ** - SK-FM3-176PMC-FA
 ** - SK-FM4-216-ETHERNET
 **
 ** History:
 **   - 2013-07-10  1.0  MSc  First Version
 **   - 2014-01-09  1.1  MSc  SK-FM3-100PMC and SK-FM3-100PMC-MB9BF516N added
 **   - 2014-03-03  1.2  MSc  I2C Bus Reset Routines Added
 **                           Added SK-FM3-176PMC-FA
 **   - 2014-03-12  1.3  MSc  SK-FM3-100PMC-MB9AFB44N, SK-FM3-48PMC-MB9BF524K 
 **                           SK-FM3-64PMC1, SK-FM3-80PMC-MB9BF524M added
 **   - 2014-09-08  1.4  MSc  SK-FM4-216-ETHERNET added
 **                           
 *****************************************************************************/
#include "multicon_neo.h"

/*
#if defined(FM3_PERIPH_BASE) 
static stc_multicon_mfs_uart_t* UART_BASE[] = {
        #if defined(FM3_MFS0_UART_BASE)
          ((stc_multicon_mfs_uart_t *)FM3_MFS0_UART_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM3_MFS1_UART_BASE)
          ((stc_multicon_mfs_uart_t *)FM3_MFS1_UART_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM3_MFS2_UART_BASE)
          ((stc_multicon_mfs_uart_t *)FM3_MFS2_UART_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM3_MFS3_UART_BASE)
          ((stc_multicon_mfs_uart_t *)FM3_MFS3_UART_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM3_MFS4_UART_BASE)
          ((stc_multicon_mfs_uart_t *)FM3_MFS4_UART_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM3_MFS5_UART_BASE)
          ((stc_multicon_mfs_uart_t *)FM3_MFS5_UART_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM3_MFS6_UART_BASE)
          ((stc_multicon_mfs_uart_t *)FM3_MFS6_UART_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM3_MFS7_UART_BASE)
          ((stc_multicon_mfs_uart_t *)FM3_MFS7_UART_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
};
#elif defined(FM4_PERIPH_BASE)
*/
static stc_multicon_mfs_uart_t* UART_BASE[] = {
        #if defined(FM4_MFS0_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS0_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS1_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS1_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS2_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS2_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS3_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS3_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS4_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS4_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS5_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS5_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS6_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS6_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS7_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS7_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS8_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS8_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS9_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS9_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS10_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS10_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS11_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS11_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS12_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS12_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS13_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS13_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS14_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS14_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
        #if defined(FM4_MFS15_BASE)
          ((stc_multicon_mfs_uart_t *)FM4_MFS15_BASE),
        #else
          ((stc_multicon_mfs_uart_t *)NULL),
        #endif
};
//#endif
/*
#if defined(FM3_PERIPH_BASE) 
static stc_multicon_mfs_i2c_t* I2C_BASE[] = {
        #if defined(FM3_MFS0_I2C_BASE)
          ((stc_multicon_mfs_i2c_t *)FM3_MFS0_I2C_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM3_MFS1_I2C_BASE)
          ((stc_multicon_mfs_i2c_t *)FM3_MFS1_I2C_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM3_MFS2_I2C_BASE)
          ((stc_multicon_mfs_i2c_t *)FM3_MFS2_I2C_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM3_MFS3_I2C_BASE)
          ((stc_multicon_mfs_i2c_t *)FM3_MFS3_I2C_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM3_MFS4_I2C_BASE)
          ((stc_multicon_mfs_i2c_t *)FM3_MFS4_I2C_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM3_MFS5_I2C_BASE)
          ((stc_multicon_mfs_i2c_t *)FM3_MFS5_I2C_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM3_MFS6_I2C_BASE)
          ((stc_multicon_mfs_i2c_t *)FM3_MFS6_I2C_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM3_MFS7_I2C_BASE)
          ((stc_multicon_mfs_i2c_t *)FM3_MFS7_I2C_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
};
#elif defined(FM4_PERIPH_BASE)
*/
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/*
static stc_multicon_mfs_i2c_t* I2C_BASE[] = {
        #if defined(FM4_MFS0_BASE)
          ((stc_multicon_mfs_i2c_t *)FM4_MFS0_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM4_MFS1_BASE)
          ((stc_multicon_mfs_i2c_t *)FM4_MFS1_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM4_MFS2_BASE)
          ((stc_multicon_mfs_i2c_t *)FM4_MFS2_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM4_MFS3_BASE)
          ((stc_multicon_mfs_i2c_t *)FM4_MFS3_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM4_MFS4_BASE)
          ((stc_multicon_mfs_i2c_t *)FM4_MFS4_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM4_MFS5_BASE)
          ((stc_multicon_mfs_i2c_t *)FM4_MFS5_BASE),
        #else
          ((FM4_MFS_TypeDef *)NULL),
        #endif
        #if defined(FM4_MFS6_BASE)
          ((stc_multicon_mfs_i2c_t *)FM4_MFS6_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM4_MFS7_BASE)
          ((stc_multicon_mfs_i2c_t *)FM4_MFS7_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM4_MFS8_BASE)
          ((stc_multicon_mfs_i2c_t *)FM4_MFS8_BASE),
        #else
          ((FM4_MFS_TypeDef *)NULL),
        #endif
        #if defined(FM4_MFS9_BASE)
          ((stc_multicon_mfs_i2c_t *)FM4_MFS9_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM4_MFS10_BASE)
          ((stc_multicon_mfs_i2c_t *)FM4_MFS10_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM4_MFS11_BASE)
          ((stc_multicon_mfs_i2c_t *)FM4_MFS11_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM4_MFS12_BASE)
          ((stc_multicon_mfs_i2c_t *)FM4_MFS12_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM4_MFS13_BASE)
          ((stc_multicon_mfs_i2c_t *)FM4_MFS13_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM4_MFS14_BASE)
          ((stc_multicon_mfs_i2c_t *)FM4_MFS14_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
        #if defined(FM4_MFS15_BASE)
          ((stc_multicon_mfs_i2c_t *)FM4_MFS15_BASE),
        #else
          ((stc_multicon_mfs_i2c_t *)NULL),
        #endif
};
*/
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//#endif
/*
#if defined(_SK_FM3_48PMC_MB9BF524K_) || defined(_SK_FM3_80PMC_MB9BF524M_)
static const stc_pinsettings_i2c_t astcPinSettings[] = 
{
  {FALSE},
  {FALSE},
  {FALSE},
  {TRUE,&FM3_GPIO->DDR5,&FM3_GPIO->PFR5,&FM3_GPIO->PDOR5,&FM3_GPIO->PDIR5,(1<<2),(1<<1)},
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
};
#elif defined(_SK_FM3_64PMC1_)
static const stc_pinsettings_i2c_t astcPinSettings[] = 
{
  {FALSE},
  {FALSE},
  {TRUE,&FM3_GPIO->DDR1,&FM3_GPIO->PFR1,&FM3_GPIO->PDOR1,&FM3_GPIO->PDIR1,(1<<9),(1<<8)},
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
};
#elif defined(_SK_FM3_100PMC_) || defined(_SK_FM3_100PMC_MB9BF516N_)
static const stc_pinsettings_i2c_t astcPinSettings[] = 
{
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
  {TRUE,&FM3_GPIO->DDR4,&FM3_GPIO->PFR4,&FM3_GPIO->PDOR4,&FM3_GPIO->PDIR4,(1<<10),(1<<9)},
  {FALSE},
  {FALSE},
  {FALSE},
};
#elif (_SK_FM3_100PMC_MB9AFB44N_)
static const stc_pinsettings_i2c_t astcPinSettings[] = 
{
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
  {TRUE,&FM3_GPIO->DDR4,&FM3_GPIO->PFR4,&FM3_GPIO->PDOR4,&FM3_GPIO->PDIR4,(1<<12),(1<<13)},
};
#elif defined(_SK_FM4_120PMC_TFT_)
static const stc_pinsettings_i2c_t astcPinSettings[] = 
{
  {FALSE},
  {FALSE},
  {TRUE,&FM4_GPIO->DDR7,&FM4_GPIO->PFR7,&FM4_GPIO->PDOR7,&FM4_GPIO->PDIR7,(1<<4),(1<<3)},
  {FALSE},
  {FALSE},
  {TRUE,&FM4_GPIO->DDR3,&FM4_GPIO->PFR3,&FM4_GPIO->PDOR3,&FM4_GPIO->PDIR3,(1<<8),(1<<7)},
  {FALSE},
  {FALSE},
};
#elif defined(_SK_FM3_176PMC_TFT_)
static const stc_pinsettings_i2c_t astcPinSettings[] = 
{
  {FALSE},
  {TRUE,&FM3_GPIO->DDRF,&FM3_GPIO->PFRF,&FM3_GPIO->PDORF,&FM3_GPIO->PDIRF,(1<<2),(1<<1)},
  {FALSE},
  {FALSE},
  {FALSE},
  {TRUE,&FM3_GPIO->DDRF,&FM3_GPIO->PFRF,&FM3_GPIO->PDORF,&FM3_GPIO->PDIRF,(1<<5),(1<<4)},
  {FALSE},
  {FALSE},
};
#elif defined(_SK_FM3_176PMC_ETHERNET_)
static const stc_pinsettings_i2c_t astcPinSettings[] = 
{
  {FALSE},
  {TRUE,&FM3_GPIO->DDRF,&FM3_GPIO->PFRF,&FM3_GPIO->PDORF,&FM3_GPIO->PDIRF,(1<<2),(1<<1)},
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
};
#elif defined(_SK_FM3_176PMC_FA_)
static const stc_pinsettings_i2c_t astcPinSettings[] = 
{
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
  {TRUE,&FM3_GPIO->DDR0,&FM3_GPIO->PFR0,&FM3_GPIO->PDOR0,&FM3_GPIO->PDIR0,(1<<7),(1<<6)},
  {FALSE},
  {TRUE,&FM3_GPIO->DDR3,&FM3_GPIO->PFR3,&FM3_GPIO->PDOR3,&FM3_GPIO->PDIR3,(1<<1),(1<<2)},
  {FALSE},
};
#elif defined(_SK_FM4_216_ETHERNET_)
*/
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/*
static const stc_pinsettings_i2c_t astcPinSettings[] = 
{
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
  {TRUE,&FM4_GPIO->DDR7,&FM4_GPIO->PFR7,&FM4_GPIO->PDOR7,&FM4_GPIO->PDIR7,(1<<7),(1<<6)},
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
  {TRUE,&FM4_GPIO->DDR6,&FM4_GPIO->PFR6,&FM4_GPIO->PDOR6,&FM4_GPIO->PDIR6,(1<<8),(1<<7)},
  {TRUE,&FM4_GPIO->DDR6,&FM4_GPIO->PFR6,&FM4_GPIO->PDOR6,&FM4_GPIO->PDIR6,(1<<0xD),(1<<0xC)},
  {FALSE}
};
*/
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//#endif

/*                        
boolean_t Multicon_Init(uint8_t u8MfsChannel, en_multicon_mode_t enMode)
{
    switch(enMode)
    {
        case MulticonI2C:
            if (I2C_BASE[u8MfsChannel] == NULL)
            {
                return FALSE;
            }
            Multicon_I2CBusClear(u8MfsChannel);
            #if defined(_SK_FM3_48PMC_MB9BF524K_) || defined(_SK_FM3_80PMC_MB9BF524M_)
                switch(u8MfsChannel)
                {
                    case 3:
                        FM3_GPIO->EPFR07 &= ~(0x3 << 22); // SIN3S 
                        FM3_GPIO->EPFR07 &= ~(0x3 << 24); // SOT3B
                        FM3_GPIO->EPFR07 &= ~(0x3 << 26); // SCK3B
                        
                        FM3_GPIO->EPFR07 |= (0x2 << 24); // SOT3B --> 3_1 SDA
                        FM3_GPIO->EPFR07 |= (0x2 << 26); // SCK3B --> 3_1 SCL
                        
                        bFM3_GPIO_PFR5_P1 = 1; // Pin 3 (SOT3_1)
                        bFM3_GPIO_PFR5_P2 = 1; // Pin 5 (SCK3_1)
                        FM3_GPIO->ADE &= ~(0x7 << 22);
                        break;
                    default:
                        return FALSE;
                }
                I2C_BASE[u8MfsChannel]->BGR  = (__PLLCLK/2) / 400000 - 1; // BGR = PCLK / BAUDRATE - 1
                UART_BASE[u8MfsChannel]->SCR |= 0x80;      // Reset (UPCL = 1)
                I2C_BASE[u8MfsChannel]->SMR  = 0x80;      // operation mode 4, no interrupts, no test
                                                          // mode, no wake up
                                                
                I2C_BASE[u8MfsChannel]->ISBA = 0x00;
                
                
                
                I2C_BASE[u8MfsChannel]->ISMK = 0x80;       // Enable I2C interface
                return TRUE;
            #elif defined(_SK_FM3_64PMC1_)
                switch(u8MfsChannel)
                {
                    case 2:
                        FM3_GPIO->EPFR07 &= ~(0x3 << 16); // SIN2S 
                        FM3_GPIO->EPFR07 &= ~(0x3 << 18); // SOT2B
                        FM3_GPIO->EPFR07 &= ~(0x3 << 20); // SCK2B
                        
                        FM3_GPIO->EPFR07 |= (0x3 << 18); // SOT3B --> 2_2 SDA
                        FM3_GPIO->EPFR07 |= (0x3 << 20); // SCK3B --> 2_2 SCL
                        
                        bFM3_GPIO_PFR1_P8 = 1; // Pin 44 (SOT2_2)
                        bFM3_GPIO_PFR1_P9 = 1; // Pin 45 (SCK2_2)
                        FM3_GPIO->ADE &= ~(0x3 << 8);
                        break;
                    default:
                        return FALSE;
                }
                I2C_BASE[u8MfsChannel]->BGR  = (__PLLCLK/2) / 400000 - 1; // BGR = PCLK / BAUDRATE - 1
                UART_BASE[u8MfsChannel]->SCR |= 0x80;      // Reset (UPCL = 1)
                I2C_BASE[u8MfsChannel]->SMR  = 0x80;      // operation mode 4, no interrupts, no test
                                                          // mode, no wake up
                                                
                I2C_BASE[u8MfsChannel]->ISBA = 0x00;
                
                FM3_MFS_NFC->I2CDNF |= 0x0008;  // enable noise filter for I2C ch. 1 for 60-80MHz PCLK operation
                
                I2C_BASE[u8MfsChannel]->ISMK = 0x80;       // Enable I2C interface
                return TRUE;
            #elif defined(_SK_FM3_100PMC_) || defined(_SK_FM3_100PMC_MB9BF516N_)
                switch(u8MfsChannel)
                {
                    case 3:
                        FM3_GPIO->EPFR07 &= ~(0x3 << 22); // SIN3S 
                        FM3_GPIO->EPFR07 &= ~(0x3 << 24); // SOT3B
                        FM3_GPIO->EPFR07 &= ~(0x3 << 26); // SCK3B
                        
                        FM3_GPIO->EPFR07 |= (0x3 << 24); // SOT3B --> 3_2 SDA
                        FM3_GPIO->EPFR07 |= (0x3 << 26); // SCK3B --> 3_2 SCL
                        
                        bFM3_GPIO_PFR4_P9 = 1; // Pin 40 (SOT3_2)
                        bFM3_GPIO_PFR4_PA = 1; // Pin 41 (SCK3_2)
                        break;
                    default:
                        return FALSE;
                }
                I2C_BASE[u8MfsChannel]->BGR  = (__PLLCLK/2) / 400000 - 1; // BGR = PCLK / BAUDRATE - 1
                UART_BASE[u8MfsChannel]->SCR |= 0x80;      // Reset (UPCL = 1)
                I2C_BASE[u8MfsChannel]->SMR  = 0x80;      // operation mode 4, no interrupts, no test
                                                          // mode, no wake up
                                                
                I2C_BASE[u8MfsChannel]->ISBA = 0x00;
                
                //FM3_MFS_NFC->I2CDNF |= 0x0008;  // enable noise filter for I2C ch. 1 for 60-80MHz PCLK operation
                
                I2C_BASE[u8MfsChannel]->ISMK = 0x80;       // Enable I2C interface
                return TRUE;
            #elif defined(_SK_FM3_100PMC_MB9AFB44N_)
                switch(u8MfsChannel)
                {
                    case 7:
                        FM3_GPIO->EPFR08 &= ~(0x3 << 22); // SIN7S 
                        FM3_GPIO->EPFR08 &= ~(0x3 << 24); // SOT7B
                        FM3_GPIO->EPFR08 &= ~(0x3 << 26); // SCK7B
                        
                        FM3_GPIO->EPFR08 |= (0x2 << 24); // SOT7B --> 7_1 SDA
                        FM3_GPIO->EPFR08 |= (0x2 << 26); // SCK7B --> 7_1 SCL
                        
                        bFM3_GPIO_PFR4_PC = 1; // Pin 43 (SOT7_1)
                        bFM3_GPIO_PFR4_PD = 1; // Pin 77 (SCK7_1)
                        break;
                    default:
                        return FALSE;
                }
                I2C_BASE[u8MfsChannel]->BGR  = (__PLLCLK/2) / 400000 - 1; // BGR = PCLK / BAUDRATE - 1
                UART_BASE[u8MfsChannel]->SCR |= 0x80;      // Reset (UPCL = 1)
                I2C_BASE[u8MfsChannel]->SMR  = 0x80;      // operation mode 4, no interrupts, no test
                                                          // mode, no wake up
                                                
                I2C_BASE[u8MfsChannel]->ISBA = 0x00;
                
                FM3_MFS_NFC->I2CDNF |= 0x0008;  // enable noise filter for I2C ch. 1 for 60-80MHz PCLK operation
                
                I2C_BASE[u8MfsChannel]->ISMK = 0x80;       // Enable I2C interface
                return TRUE;
            #elif defined(_SK_FM3_176PMC_ETHERNET_)
                switch(u8MfsChannel)
                {
                    case 1:
                        FM3_GPIO->EPFR07 &= ~(0x3 << 10); // SIN1S 
                        FM3_GPIO->EPFR07 &= ~(0x3 << 12); // SOT1B
                        FM3_GPIO->EPFR07 &= ~(0x3 << 14); // SCK1B
                        
                        FM3_GPIO->EPFR07 |= (0x3 << 12); // SOT1B --> 1_2 SDA
                        FM3_GPIO->EPFR07 |= (0x3 << 14); // SCK1B --> 1_2 SCL
                        
                        bFM3_GPIO_PFRF_P1 = 1; // Pin 82 (SOT1_2)
                        bFM3_GPIO_PFRF_P2 = 1; // Pin 83 (SCK1_2)
                        break;
                    default:
                        return FALSE;
                }
                I2C_BASE[u8MfsChannel]->BGR  = (__PLLCLK/2) / 400000 - 1; // BGR = PCLK / BAUDRATE - 1
                UART_BASE[u8MfsChannel]->SCR |= 0x80;      // Reset (UPCL = 1)
                I2C_BASE[u8MfsChannel]->SMR  = 0x80;      // operation mode 4, no interrupts, no test
                                                          // mode, no wake up
                                                
                I2C_BASE[u8MfsChannel]->ISBA = 0x00;
                
                FM3_MFS_NFC->I2CDNF |= 0x0008;  // enable noise filter for I2C ch. 1 for 60-80MHz PCLK operation
                
                I2C_BASE[u8MfsChannel]->ISMK = 0x80;       // Enable I2C interface
                return TRUE;
            #elif defined(_SK_FM3_176PMC_FA_)
                switch(u8MfsChannel)
                {
                    case 4:
                        FM3_GPIO->EPFR08 &= ~(0x2 << 4); // SIN4S 
                        FM3_GPIO->EPFR08 &= ~(0x2 << 6); // SOT4B
                        FM3_GPIO->EPFR08 &= ~(0x2 << 8); // SCK4B
                        
                        FM3_GPIO->EPFR08 |= (0x3 << 4); // SOT4B --> 4_2 SDA
                        FM3_GPIO->EPFR08 |= (0x3 << 8); // SCK4B --> 4_2 SCL
                        
                        bFM3_GPIO_PFR3_P6 = 1; // Pin 9  (SOT4_2)
                        bFM3_GPIO_PFR3_P7 = 1; // Pin 10 (SCK4_2)
                        break;
                    case 6:
                        FM3_GPIO->EPFR08 &= ~(0x2 << 16); // SIN6S 
                        FM3_GPIO->EPFR08 &= ~(0x2 << 18); // SOT6B
                        FM3_GPIO->EPFR08 &= ~(0x2 << 20); // SCK6B
                        
                        FM3_GPIO->EPFR08 |= (0x2 << 18); // SOT6B --> 6_1 SDA
                        FM3_GPIO->EPFR08 |= (0x2 << 20); // SCK6B --> 6_1 SCL
                        
                        bFM3_GPIO_PFR3_P1 = 1; // Pin 3ß (SOT6_1)
                        bFM3_GPIO_PFR3_P2 = 1; // Pin 29 (SCK6_1)
                        break;
                    default:
                        return FALSE;
                }
                I2C_BASE[u8MfsChannel]->BGR  = (__PLLCLK/2) / 400000 - 1; // BGR = PCLK / BAUDRATE - 1
                UART_BASE[u8MfsChannel]->SCR |= 0x80;      // Reset (UPCL = 1)
                I2C_BASE[u8MfsChannel]->SMR  = 0x80;      // operation mode 4, no interrupts, no test
                                                          // mode, no wake up
                                                
                I2C_BASE[u8MfsChannel]->ISBA = 0x00;
                
                FM3_MFS_NFC->I2CDNF |= 0x0008;  // enable noise filter for I2C ch. 1 for 60-80MHz PCLK operation
                
                I2C_BASE[u8MfsChannel]->ISMK = 0x80;       // Enable I2C interface
                return TRUE;
            #elif defined(_SK_FM3_176PMC_TFT_)
                switch(u8MfsChannel)
                {
                    case 1:
                        FM3_GPIO->EPFR07 &= ~(0x3 << 10); // SIN1S 
                        FM3_GPIO->EPFR07 &= ~(0x3 << 12); // SOT1B
                        FM3_GPIO->EPFR07 &= ~(0x3 << 14); // SCK1B
                        
                        FM3_GPIO->EPFR07 |= (0x3 << 12); // SOT1B --> 1_2 SDA
                        FM3_GPIO->EPFR07 |= (0x3 << 14); // SCK1B --> 1_2 SCL
                        
                        bFM3_GPIO_PFRF_P1 = 1; // Pin 82 (SOT1_2)
                        bFM3_GPIO_PFRF_P2 = 1; // Pin 83 (SCK1_2)
                        break;
                    case 6:
                        bFM3_GPIO_PFRF_P4 = 1; // Pin 171 (SOT6_2)
                        bFM3_GPIO_PFRF_P5 = 1; // Pin 172 (SCK6_2)
                        
                        FM3_GPIO->EPFR08 &= ~(0x3 << 16); // SIN6S 
                        FM3_GPIO->EPFR08 &= ~(0x3 << 18); // SOT6B
                        FM3_GPIO->EPFR08 &= ~(0x3 << 20); // SCK6B
                        
                        FM3_GPIO->EPFR08 |= (0x3 << 18); // SOT6B --> 6_2 SDA
                        FM3_GPIO->EPFR08 |= (0x3 << 20); // SCK6B --> 6_2 SCL
                        break;
                    default:
                        return FALSE;
                }
                I2C_BASE[u8MfsChannel]->BGR  = (__PLLCLK/2) / 400000 - 1; // BGR = PCLK / BAUDRATE - 1
                UART_BASE[u8MfsChannel]->SCR |= 0x80;      // Reset (UPCL = 1)
                I2C_BASE[u8MfsChannel]->SMR  = 0x80;      // operation mode 4, no interrupts, no test
                                                          // mode, no wake up
                                                
                I2C_BASE[u8MfsChannel]->ISBA = 0x00;
                
                FM3_MFS_NFC->I2CDNF |= 0x0008;  // enable noise filter for I2C ch. 1 for 60-80MHz PCLK operation
                
                I2C_BASE[u8MfsChannel]->ISMK = 0x80;       // Enable I2C interface
                return TRUE;
            #elif defined(_SK_FM4_120PMC_TFT_)
                switch(u8MfsChannel)
                {
                    case 2:
                        bFM4_GPIO_PFR7_P73 = 1; // Pin 54 (SOT2_0)
                        bFM4_GPIO_PFR7_P74 = 1; // Pin 55 (SCK2_0)
                        
                        FM4_GPIO->EPFR07 &= ~(0x3 << 16); // SIN2S 
                        FM4_GPIO->EPFR07 &= ~(0x3 << 18); // SOT2B
                        FM4_GPIO->EPFR07 &= ~(0x3 << 20); // SCK2B
                        
                        FM4_GPIO->EPFR07 |= (0x1 << 18); // SOT2B --> 2_0 SDA
                        FM4_GPIO->EPFR07 |= (0x1 << 20); // SCK2B --> 2_0 SCL
                        break;
                    case 5:
                        bFM4_GPIO_PFR3_P37 = 1; // Pin 21 (SOT5_2)
                        bFM4_GPIO_PFR3_P38 = 1; // Pin 22 (SCK5_2)
                        
                        FM4_GPIO->EPFR08 &= ~(0x3 << 10); // SIN5S 
                        FM4_GPIO->EPFR08 &= ~(0x3 << 12); // SOT5B
                        FM4_GPIO->EPFR08 &= ~(0x3 << 14); // SCK5B
                        
                        FM4_GPIO->EPFR08 |= (0x3 << 12); // SOT5B --> 5_2 SDA
                        FM4_GPIO->EPFR08 |= (0x3 << 14); // SCK5B --> 5_2 SCL
                        break;
                    default:
                        return FALSE;
                }
                I2C_BASE[u8MfsChannel]->BGR  = (__PLLCLK/2) / 400000 - 1; // BGR = PCLK / BAUDRATE - 1
                UART_BASE[u8MfsChannel]->SCR |= 0x80;      // Reset (UPCL = 1)
                I2C_BASE[u8MfsChannel]->SMR  = 0x80;      // operation mode 4, no interrupts, no test
                                                          // mode, no wake up
                                                
                I2C_BASE[u8MfsChannel]->ISBA = 0x00;
                
                //FM4_MFS_NFC->I2CDNF |= 0x0008;  // enable noise filter for I2C ch. 1 for 60-80MHz PCLK operation
                
                I2C_BASE[u8MfsChannel]->ISMK = 0x80;       // Enable I2C interface
                return TRUE;
            #elif defined(_SK_FM4_216_ETHERNET_)
                switch(u8MfsChannel)
                {
                    case 8:
                        bFM4_GPIO_PFR7_P6 = 1; // Pin 92 (SOT8_0)
                        bFM4_GPIO_PFR7_P7 = 1; // Pin 93 (SCK8_0)
                        
                        FM4_GPIO->EPFR16 &= ~(0x3 << 4); // SIN8S 
                        FM4_GPIO->EPFR16 &= ~(0x3 << 6); // SOT8B
                        FM4_GPIO->EPFR16 &= ~(0x3 << 8); // SCK8B
                        
                        FM4_GPIO->EPFR16 |= (0x1 << 6); // SOT8B
                        FM4_GPIO->EPFR16 |= (0x1 << 8); // SCK8B
                        break;
                    case 13:
                        bFM4_GPIO_PFR6_P7 = 1; // Pin 205 (SOT13_1)
                        bFM4_GPIO_PFR6_P8 = 1; // Pin 204 (SCK13_1)
                        
                        FM4_GPIO->EPFR17 &= ~(0x3 << 10); // SIN13S 
                        FM4_GPIO->EPFR17 &= ~(0x3 << 12); // SOT13B
                        FM4_GPIO->EPFR17 &= ~(0x3 << 14); // SCK13B
                        
                        FM4_GPIO->EPFR17 |= (0x2 << 12); // SOT13B
                        FM4_GPIO->EPFR17 |= (0x2 << 14); // SCK13B
                        break;
                    case 14:
                        bFM4_GPIO_PFR6_PC = 1; // Pin 200 (SOT14_1)
                        bFM4_GPIO_PFR6_PD = 1; // Pin 199 (SCK14_1)
                        
                        FM4_GPIO->EPFR17 &= ~(0x3 << 16); // SIN14S 
                        FM4_GPIO->EPFR17 &= ~(0x3 << 18); // SOT14B
                        FM4_GPIO->EPFR17 &= ~(0x3 << 20); // SCK14B
                        
                        FM4_GPIO->EPFR17 |= (0x2 << 18); // SOT14B
                        FM4_GPIO->EPFR17 |= (0x2 << 20); // SCK14B
                        break;
                    default:
                        return FALSE;
                }
                I2C_BASE[u8MfsChannel]->BGR  = (__PLLCLK/2) / 400000 - 1; // BGR = PCLK / BAUDRATE - 1
                UART_BASE[u8MfsChannel]->SCR |= 0x80;      // Reset (UPCL = 1)
                I2C_BASE[u8MfsChannel]->SMR  = 0x80;      // operation mode 4, no interrupts, no test
                                                          // mode, no wake up
                                                
                I2C_BASE[u8MfsChannel]->ISBA = 0x00;
                
                I2C_BASE[u8MfsChannel]->NFCR |= 0x0008;  // enable noise filter for I2C ch. 1 for 60-80MHz PCLK operation
                
                I2C_BASE[u8MfsChannel]->ISMK = 0x80;       // Enable I2C interface
                return TRUE;
            #else
            break;
						#endif
        case MulticonSpi:
            #if defined(_SK_FM3_48PMC_MB9BF524K_) || defined(_SK_FM3_80PMC_MB9BF524M_)
                switch(u8MfsChannel)
                {
                    case 3:
                        FM3_GPIO->EPFR07 &= ~(0x3 << 22); // SIN3S 
                        FM3_GPIO->EPFR07 &= ~(0x3 << 24); // SOT3B
                        FM3_GPIO->EPFR07 &= ~(0x3 << 26); // SCK3B
                        
                        FM3_GPIO->EPFR07 |= (0x2 << 24); // SOT3B
                        FM3_GPIO->EPFR07 |= (0x2 << 26); // SCK3B
                        FM3_GPIO->EPFR07 |= (0x2 << 22); // SIN3S

                        bFM3_GPIO_PFR5_P0 = 1; // Pin 2 (SIN3_1)
                        bFM3_GPIO_PFR5_P1 = 1; // Pin 3 (SOT3_1)
                        bFM3_GPIO_PFR5_P2 = 1; // Pin 4 (SCK3_1)
                        FM3_GPIO->ADE &= ~(0x7 << 22);
                        break;
                    default:
                        return FALSE;
                }
                return TRUE;
            #elif defined(_SK_FM3_100PMC_) || defined(_SK_FM3_100PMC_MB9BF516N_)
                switch(u8MfsChannel)
                {
                    default:
                        return FALSE;
                }
                return TRUE;
            #elif defined(_SK_FM3_100PMC_MB9AFB44N_)
                switch(u8MfsChannel)
                {
                    case 7:
                        FM3_GPIO->EPFR08 &= ~(0x3 << 22); // SIN7S 
                        FM3_GPIO->EPFR08 &= ~(0x3 << 24); // SOT7B
                        FM3_GPIO->EPFR08 &= ~(0x3 << 26); // SCK7B
                        
                        FM3_GPIO->EPFR08 |= (0x2 << 24); // SOT7B
                        FM3_GPIO->EPFR08 |= (0x2 << 22); // SIN7B
                        FM3_GPIO->EPFR08 |= (0x2 << 26); // SCK7B

                        bFM3_GPIO_PFR4_PC = 1; // Pin 43 (SOT7_1)
                        bFM3_GPIO_PFR4_PD = 1; // Pin 44 (SIN7_1)
                        bFM3_GPIO_PFR4_PE = 1; // Pin 45 (SIN7_1)
                        break;
                    default:
                        return FALSE;
                }
                return TRUE;
            #elif defined(_SK_FM3_176PMC_ETHERNET_)
                switch(u8MfsChannel)
                {
                    case 1:
                        FM3_GPIO->EPFR07 &= ~(0x3 << 10); // SIN1S 
                        FM3_GPIO->EPFR07 &= ~(0x3 << 12); // SOT1B
                        FM3_GPIO->EPFR07 &= ~(0x3 << 14); // SCK1B
                        
                        FM3_GPIO->EPFR07 |= (0x3 << 12); // SOT1B
                        FM3_GPIO->EPFR07 |= (0x3 << 10); // SIN1B
                        FM3_GPIO->EPFR07 |= (0x3 << 14); // SCK1B
                        
                        bFM3_GPIO_PFRF_P1 = 1; // Pin 82 (SOT1_2)
                        bFM3_GPIO_PFRF_P0 = 1; // Pin 81 (SIN1_2)
                        bFM3_GPIO_PFRF_P2 = 1; // Pin 83 (SCK1_2)
                        break;
                    default:
                        return FALSE;
                }
                return TRUE;
            #elif defined(_SK_FM3_176PMC_FA_)
                switch(u8MfsChannel)
                {
                    case 6:
                        FM3_GPIO->EPFR08 &= ~(0x2 << 16); // SIN6S 
                        FM3_GPIO->EPFR08 &= ~(0x2 << 18); // SOT6B
                        FM3_GPIO->EPFR08 &= ~(0x2 << 20); // SCK6B
                        
                        FM3_GPIO->EPFR08 |= (0x2 << 16); // SIN6B 
                        FM3_GPIO->EPFR08 |= (0x2 << 18); // SOT6B
                        FM3_GPIO->EPFR08 |= (0x2 << 20); // SCK6B
                        
                        bFM3_GPIO_PFR3_P3 = 1; // Pin 3ß (SIN6_1)
                        bFM3_GPIO_PFR3_P2 = 1; // Pin 3ß (SOT6_1)
                        bFM3_GPIO_PFR3_P1 = 1; // Pin 29 (SCK6_1)
                        break;
                    default:
                        return FALSE;
                }
                return TRUE;
            #elif defined(_SK_FM3_176PMC_TFT_)
                switch(u8MfsChannel)
                {
                    case 1:
                        FM3_GPIO->EPFR07 &= ~(0x3 << 10); // SIN1S 
                        FM3_GPIO->EPFR07 &= ~(0x3 << 12); // SOT1B
                        FM3_GPIO->EPFR07 &= ~(0x3 << 14); // SCK1B
                        
                        FM3_GPIO->EPFR07 |= (0x3 << 12); // SOT1B
                        FM3_GPIO->EPFR07 |= (0x3 << 10); // SIN1B
                        FM3_GPIO->EPFR07 |= (0x3 << 14); // SCK1B
                        
                        bFM3_GPIO_PFRF_P1 = 1; // Pin 82 (SOT1_2)
                        bFM3_GPIO_PFRF_P0 = 1; // Pin 81 (SIN1_2)
                        bFM3_GPIO_PFRF_P2 = 1; // Pin 83 (SCK1_2)
                        break;
                    case 6:
                        bFM3_GPIO_PFRF_P4 = 1; // Pin 171 (SOT6_2)
                        bFM3_GPIO_PFRF_P3 = 1; // Pin 170 (SIN6_2)
                        bFM3_GPIO_PFRF_P5 = 1; // Pin 172 (SCK6_2)
                        
                        FM3_GPIO->EPFR08 &= ~(0x3 << 16); // SIN6S 
                        FM3_GPIO->EPFR08 &= ~(0x3 << 18); // SOT6B
                        FM3_GPIO->EPFR08 &= ~(0x3 << 20); // SCK6B
                        
                        FM3_GPIO->EPFR08 |= (0x3 << 18); // SOT6B
                        FM3_GPIO->EPFR08 |= (0x3 << 16); // SIN6B 
                        FM3_GPIO->EPFR08 |= (0x3 << 20); // SCK6B
                        break;
                    default:
                        return FALSE;
                }
                return TRUE;
            #elif defined(_SK_FM4_120PMC_TFT_)
                switch(u8MfsChannel)
                {
                    case 2:
                        bFM4_GPIO_PFR7_P73 = 1; // Pin 54 (SOT2_0)
                        bFM4_GPIO_PFR7_P74 = 1; // Pin 53 (SIN2_0)
                        bFM4_GPIO_PFR7_P75 = 1; // Pin 54 (SCK2_0)
                        
                        FM4_GPIO->EPFR07 &= ~(0x3 << 16); // SIN2S 
                        FM4_GPIO->EPFR07 &= ~(0x3 << 18); // SOT2B
                        FM4_GPIO->EPFR07 &= ~(0x3 << 20); // SCK2B
                        
                        FM4_GPIO->EPFR07 |= (0x1 << 18); // SOT2B
                        FM4_GPIO->EPFR07 |= (0x1 << 16); // SIN2B
                        FM4_GPIO->EPFR07 |= (0x3 << 20); // SCK2B
                        break;
                    case 5:
                        bFM4_GPIO_PFR3_P37 = 1; // Pin 21 (SOT5_2)
                        bFM4_GPIO_PFR3_P36 = 1; // Pin 20 (SIN5_2)
                        bFM4_GPIO_PFR3_P38 = 1; // Pin 22 (SIN5_2)
                        
                        FM4_GPIO->EPFR08 &= ~(0x3 << 10); // SIN5S 
                        FM4_GPIO->EPFR08 &= ~(0x3 << 12); // SOT5B
                        FM4_GPIO->EPFR08 &= ~(0x3 << 14); // SCK5B
                        
                        FM4_GPIO->EPFR08 |= (0x3 << 12); // SOT5B
                        FM4_GPIO->EPFR08 |= (0x3 << 10); // SIN5B
                        FM4_GPIO->EPFR08 |= (0x3 << 14); // SCK5B
                        break;
                    default:
                        return FALSE;
                }
                return TRUE;
            #elif defined(_SK_FM4_216_ETHERNET_)
                switch(u8MfsChannel)
                {
                    case 8:
                        bFM4_GPIO_PFR7_P6 = 1; // Pin 92 (SOT8_0)
                        bFM4_GPIO_PFR7_P5 = 1; // Pin 91 (SIN8_0)
                        bFM4_GPIO_PFR7_P7 = 1; // Pin 93 (SCK8_0)
                        
                        FM4_GPIO->EPFR16 &= ~(0x3 << 4); // SIN8S 
                        FM4_GPIO->EPFR16 &= ~(0x3 << 6); // SOT8B
                        FM4_GPIO->EPFR16 &= ~(0x3 << 8); // SCK8B
                        
                        FM4_GPIO->EPFR16 |= (0x1 << 4); // SOT8B
                        FM4_GPIO->EPFR16 |= (0x1 << 6); // SIN8B
                        FM4_GPIO->EPFR16 |= (0x1 << 8); // SCK8B
                        break;
                    case 13:
                        bFM4_GPIO_PFR6_P7 = 1; // Pin 205 (SOT13_1)
                        bFM4_GPIO_PFR6_P6 = 1; // Pin 206 (SIN13_1)
                        bFM4_GPIO_PFR6_P8 = 1; // Pin 204 (SCK13_1)
                        
                        FM4_GPIO->EPFR17 &= ~(0x3 << 10); // SIN13S 
                        FM4_GPIO->EPFR17 &= ~(0x3 << 12); // SOT13B
                        FM4_GPIO->EPFR17 &= ~(0x3 << 14); // SCK13B
                        
                        FM4_GPIO->EPFR17 |= (0x2 << 12); // SOT13B
                        FM4_GPIO->EPFR17 |= (0x2 << 10); // SIN13B
                        FM4_GPIO->EPFR17 |= (0x2 << 14); // SCK13B
                        break;
                    default:
                        return FALSE;
                }
                return TRUE;            
						#else
            break;
						#endif
        case MulticonUart:
            if (UART_BASE[u8MfsChannel] == NULL)
            {
                return FALSE;
            }
            #if defined(_SK_FM3_48PMC_MB9BF524K_) || defined(_SK_FM3_80PMC_MB9BF524M_)
                switch(u8MfsChannel)
                {
                    case 3:
                        FM3_GPIO->EPFR07 &= ~(0x3 << 22); // SIN3S 
                        FM3_GPIO->EPFR07 &= ~(0x3 << 24); // SOT3B
                        FM3_GPIO->EPFR07 &= ~(0x3 << 26); // SCK3B
                        
                        FM3_GPIO->EPFR07 |= (0x2 << 24); // SOT3B
                        FM3_GPIO->EPFR07 |= (0x2 << 22); // SIN3S

                        bFM3_GPIO_PFR5_P0 = 1; // Pin 2 (SIN3_1)
                        bFM3_GPIO_PFR5_P1 = 1; // Pin 3 (SOT3_1)
                        FM3_GPIO->ADE &= ~(0x3 << 22);
                        break;
                    default:
                        return FALSE;
                }
                return TRUE;
            #elif defined(_SK_FM3_100PMC_) || defined(_SK_FM3_100PMC_MB9BF516N_)
                switch(u8MfsChannel)
                {
                    default:
                        return FALSE;
                }
                return TRUE;
            #elif defined(_SK_FM3_100PMC_MB9AFB44N_)
                switch(u8MfsChannel)
                {
                    case 7:
                        FM3_GPIO->EPFR08 &= ~(0x3 << 22); // SIN7S 
                        FM3_GPIO->EPFR08 &= ~(0x3 << 24); // SOT7B
                        FM3_GPIO->EPFR08 &= ~(0x3 << 26); // SCK7B
                        
                        FM3_GPIO->EPFR08 |= (0x2 << 24); // SOT7B
                        FM3_GPIO->EPFR08 |= (0x2 << 22); // SIN7B

                        bFM3_GPIO_PFR4_PC = 1; // Pin 43 (SOT7_1)
                        bFM3_GPIO_PFR4_PD = 1; // Pin 44 (SIN7_1)
                        break;
                    default:
                        return FALSE;
                }
                return TRUE;
            #elif defined(_SK_FM3_176PMC_ETHERNET_)
                switch(u8MfsChannel)
                {
                    case 1:
                        FM3_GPIO->EPFR07 &= ~(0x3 << 10); // SIN1S 
                        FM3_GPIO->EPFR07 &= ~(0x3 << 12); // SOT1B
                        FM3_GPIO->EPFR07 &= ~(0x3 << 14); // SCK1B
                        
                        FM3_GPIO->EPFR07 |= (0x3 << 12); // SOT1B
                        FM3_GPIO->EPFR07 |= (0x3 << 10); // SIN1B
                        
                        bFM3_GPIO_PFRF_P1 = 1; // Pin 82 (SOT1_2)
                        bFM3_GPIO_PFRF_P0 = 1; // Pin 81 (SIN1_2)
                        break;
                    default:
                        return FALSE;
                }
                return TRUE;
             #elif defined(_SK_FM3_176PMC_FA_)
                switch(u8MfsChannel)
                {
                   case 6:
                        FM3_GPIO->EPFR08 &= ~(0x2 << 16); // SIN6S 
                        FM3_GPIO->EPFR08 &= ~(0x2 << 18); // SOT6B
                        FM3_GPIO->EPFR08 &= ~(0x2 << 20); // SCK6B
                        
                        FM3_GPIO->EPFR08 |= (0x2 << 16); // SIN6B 
                        FM3_GPIO->EPFR08 |= (0x2 << 18); // SOT6B
                        
                        bFM3_GPIO_PFR3_P3 = 1; // Pin 3ß (SIN6_1)
                        bFM3_GPIO_PFR3_P2 = 1; // Pin 3ß (SOT6_1)
                        break;
                    default:
                        return FALSE;
                }
                return TRUE;
            #elif defined(_SK_FM3_176PMC_TFT_)
                switch(u8MfsChannel)
                {
                    case 1:
                        FM3_GPIO->EPFR07 &= ~(0x3 << 10); // SIN1S 
                        FM3_GPIO->EPFR07 &= ~(0x3 << 12); // SOT1B
                        FM3_GPIO->EPFR07 &= ~(0x3 << 14); // SCK1B
                        
                        FM3_GPIO->EPFR07 |= (0x3 << 12); // SOT1B
                        FM3_GPIO->EPFR07 |= (0x3 << 10); // SIN1B
                        
                        bFM3_GPIO_PFRF_P1 = 1; // Pin 82 (SOT1_2)
                        bFM3_GPIO_PFRF_P0 = 1; // Pin 81 (SIN1_2)
                        break;
                    case 6:
                        bFM3_GPIO_PFRF_P4 = 1; // Pin 171 (SOT6_2)
                        bFM3_GPIO_PFRF_P3 = 1; // Pin 170 (SIN6_2)
                        
                        FM3_GPIO->EPFR08 &= ~(0x3 << 16); // SIN6S 
                        FM3_GPIO->EPFR08 &= ~(0x3 << 18); // SOT6B
                        FM3_GPIO->EPFR08 &= ~(0x3 << 20); // SCK6B
                        
                        FM3_GPIO->EPFR08 |= (0x3 << 18); // SOT6B
                        FM3_GPIO->EPFR08 |= (0x3 << 16); // SIN6B 
                        break;
                    default:
                        return FALSE;
                }
                return TRUE;
            #elif defined(_SK_FM4_120PMC_TFT_)
                switch(u8MfsChannel)
                {
                    case 2:
                        bFM4_GPIO_PFR7_P73 = 1; // Pin 54 (SOT2_0)
                        bFM4_GPIO_PFR7_P74 = 1; // Pin 53 (SIN2_0)
                        
                        FM4_GPIO->EPFR07 &= ~(0x3 << 16); // SIN2S 
                        FM4_GPIO->EPFR07 &= ~(0x3 << 18); // SOT2B
                        FM4_GPIO->EPFR07 &= ~(0x3 << 20); // SCK2B
                        
                        FM4_GPIO->EPFR07 |= (0x1 << 18); // SOT2B
                        FM4_GPIO->EPFR07 |= (0x1 << 16); // SIN2B
                        break;
                    case 5:
                        bFM4_GPIO_PFR3_P37 = 1; // Pin 21 (SOT5_2)
                        bFM4_GPIO_PFR3_P36 = 1; // Pin 20 (SIN5_2)
                        
                        FM4_GPIO->EPFR08 &= ~(0x3 << 10); // SIN5S 
                        FM4_GPIO->EPFR08 &= ~(0x3 << 12); // SOT5B
                        FM4_GPIO->EPFR08 &= ~(0x3 << 14); // SCK5B
                        
                        FM4_GPIO->EPFR08 |= (0x3 << 12); // SOT5B
                        FM4_GPIO->EPFR08 |= (0x3 << 10); // SIN5B
                        break;
                    default:
                        return FALSE;
                }
                return TRUE;
            #elif defined(_SK_FM4_216_ETHERNET_)
                switch(u8MfsChannel)
                {
                    case 8:
                        bFM4_GPIO_PFR7_P6 = 1; // Pin 92 (SOT8_0)
                        bFM4_GPIO_PFR7_P5 = 1; // Pin 91 (SIN8_0)
                        
                        FM4_GPIO->EPFR16 &= ~(0x3 << 4); // SIN8S 
                        FM4_GPIO->EPFR16 &= ~(0x3 << 6); // SOT8B
                        FM4_GPIO->EPFR16 &= ~(0x3 << 8); // SCK8B
                        
                        FM4_GPIO->EPFR16 |= (0x1 << 4); // SOT8B
                        FM4_GPIO->EPFR16 |= (0x1 << 6); // SIN8B
                        break;
                    case 13:
                        bFM4_GPIO_PFR6_P7 = 1; // Pin 205 (SOT13_1)
                        bFM4_GPIO_PFR6_P6 = 1; // Pin 206 (SIN13_1)
                        
                        FM4_GPIO->EPFR17 &= ~(0x3 << 10); // SIN13S 
                        FM4_GPIO->EPFR17 &= ~(0x3 << 12); // SOT13B
                        FM4_GPIO->EPFR17 &= ~(0x3 << 14); // SCK13B
                        
                        FM4_GPIO->EPFR17 |= (0x2 << 12); // SOT13B
                        FM4_GPIO->EPFR17 |= (0x2 << 10); // SIN13B
                        break;
                    default:
                        return FALSE;
                }
                return TRUE;
						#else
            break;
						#endif
    }
    return FALSE;
}

// The following function checks if a slave device holds the SDA line low before initializing I2C.
// This can happen if a read operation from a slave was interrupted, eg. due to MCU reset.
// In case some slave device is holding the bus low, up to nine clock pulses are generated until the line is released.

static void _Multicon_I2CBusClear(volatile uint32_t* pu32DDR,volatile uint32_t* pu32PFR,volatile uint32_t* pu32PDOR,volatile uint32_t* pu32PDIR, uint32_t u32SclMask, uint32_t u32SdaMask)
{
  volatile unsigned long int dly;
  unsigned char i;
  
  *pu32DDR &= ~(u32SclMask | u32SdaMask);   // input (to read bus state)
  *pu32PDOR &= ~(u32SclMask | u32SdaMask);  // PF low
  *pu32PFR &= ~(u32SclMask | u32SdaMask);   // Disable MFS peripheral output
            
  if (0 == (*pu32PDIR & u32SdaMask)) // If someone holds SDA low, generate some dummy clock pulses until line is released
  {
    *pu32DDR |= u32SclMask;          // set SCL to output
    for (i=0; i<9; i++)
    {
      dly = 0xffff;
      while (--dly);
      *pu32PDOR |= u32SclMask;             // PF2 --> high (SCL)
      dly = 0xffff;
      while (--dly);
      *pu32PDOR &= ~u32SclMask;            // PF2 --> low (SCL)
      if (*pu32PDIR & u32SdaMask) break;   // stop if SDA was released meanwhile
    }
  }
  dly = 0xffff;
  while (--dly);
  *pu32PDOR |= (u32SclMask | u32SdaMask);  // SDA + SCL high
  *pu32DDR |= (u32SclMask | u32SdaMask);
  dly = 0xffff;
  while (--dly);
  
  // MFS I2C has to be re-initialized after this!

}

en_result_t Multicon_I2CBusClear(uint8_t u8MfsChannel)
{
    if (astcPinSettings[u8MfsChannel].bUsable == FALSE)
    {
        return Error;
    }
    else
    {
        _Multicon_I2CBusClear(astcPinSettings[u8MfsChannel].pu32DDR,
                              astcPinSettings[u8MfsChannel].pu32PFR,
                              astcPinSettings[u8MfsChannel].pu32PDOR,
                              astcPinSettings[u8MfsChannel].pu32PDIR,
                              astcPinSettings[u8MfsChannel].u32SclMask,
                              astcPinSettings[u8MfsChannel].u32SdaMask);
    }
    return Ok;
}

//Start of I2C Communication with 1st Data Byte
//u8Data: Data Byte
//RETURNS:        0 = 0k / -1 = Error
int32_t Multicon_I2cStart(uint8_t u8MfsChannel, uint8_t u8Data)
{ 
  uint32_t u16ErrorCount = 0;
  volatile uint32_t u32Timeout;
  if (I2C_BASE[u8MfsChannel] == NULL)
  {
      return -1;
  }
  
  I2C_BASE[u8MfsChannel]->TDR  = (u8Data);     // Send data to TSC
  I2C_BASE[u8MfsChannel]->IBCR = 0x80;         // MSS = 1: Master Mode
  
  do
  {
    u32Timeout = I2C_TIME_OUT;
    while(!(I2C_BASE[u8MfsChannel]->IBCR & 0x01)) // Wait for transmission complete
    {                                     //   via INT flag
        u32Timeout--;
        if (u32Timeout == 0)
        {
            return -1;
        }
    }
    if (I2C_BASE[u8MfsChannel]->IBCR & 0x02)       // BER == 1? ->  error
    {
      return -1;
    }
    
    if (!(I2C_BASE[u8MfsChannel]->IBCR & 0x40))    // ACT == 0? ->  error
    {
      return -1;
    }
    
    // MSS is set ...
  
    if (I2C_BASE[u8MfsChannel]->IBSR & 0x40)  // RACK == 1? ->  busy or error
    {
      I2C_BASE[u8MfsChannel]->IBCR = 0xE0;    // MMS = CSS = ACKE = 1: Try restart (if busy)
      u16ErrorCount++;
      
      if (u16ErrorCount > I2C_TIME_OUT)
      {
        return -1;        // too much retrials
      }
    }
    else
    {
      u16ErrorCount = 0; 
    }
    
  }while (u16ErrorCount);

  if (!(I2C_BASE[u8MfsChannel]->IBSR & 0x10))   // TRX == 0? ->  error
  {
     return -1;
  }
  
  return 0;
}

void Multicon_I2cSendBytes(uint8_t u8MfsChannel, uint8_t* pu8Data, uint32_t u32Size)
{
    uint32_t i;
    for(i = 0;i < u32Size;i++)
    {
        Multicon_I2cSendByte(u8MfsChannel,pu8Data[i]);
    }
}

//Send I2C Byte
//u8Data:  Byte Data
//RETURNS: 0 = 0k / -1 = Error
int32_t Multicon_I2cSendByte(uint8_t u8MfsChannel, uint8_t u8Data)
{
  volatile uint32_t u32Timeout;
  if (I2C_BASE[u8MfsChannel] == NULL)
  {
      return -1;
  }
  I2C_BASE[u8MfsChannel]->TDR = u8Data;  // Send data to TSC
  I2C_BASE[u8MfsChannel]->IBCR = 0xB0;   // WSEL = 1, ACKE = 1, Clear INT flag
  
  u32Timeout = I2C_TIME_OUT;
  while(!(I2C_BASE[u8MfsChannel]->IBCR & 0x01)) // Wait for transmission complete
  {                                     //   via INT flag
      u32Timeout--;
      if (u32Timeout == 0)
      {
          return -1;
      }
  }
   
  if (I2C_BASE[u8MfsChannel]->IBCR & 0x02)       // BER == 1? ->  error
  {
    return -1;
  }
  
  if (!(I2C_BASE[u8MfsChannel]->IBCR & 0x40))    // ACT == 0? ->  error
  {
    return -1;
  }
  
  // MSS is set, no reserved address
  
  if (I2C_BASE[u8MfsChannel]->IBSR & 0x40)       // RACK == 1? ->  error
  {
    return -1;
  }
  
  if (!(I2C_BASE[u8MfsChannel]->IBSR & 0x10))    // TRX == 0? ->  error
  {
    return -1;
  }
  
  return 0;
}

//Continue I2C Byte (Iteration)
//u8Data: Byte Data
//RETURNS:        0 = 0k / -1 = Error
int32_t Multicon_I2cContinueSendByte(uint8_t u8MfsChannel, uint8_t u8Data)
{
  volatile uint32_t u32Timeout;
  if (I2C_BASE[u8MfsChannel] == NULL)
  {
      return -1;
  }
  I2C_BASE[u8MfsChannel]->TDR = u8Data;  // Send data to TSC
  I2C_BASE[u8MfsChannel]->IBCR = 0xE0;   // Set continuous mode MSS = SCC = ACKE = 1

  u32Timeout = I2C_TIME_OUT;
  while(!(I2C_BASE[u8MfsChannel]->IBCR & 0x01)) // Wait for transmission complete
  {                                     //   via INT flag
      u32Timeout--;
      if (u32Timeout == 0)
      {
          return -1;
      }
  }
  
  if (I2C_BASE[u8MfsChannel]->IBCR & 0x02)       // BER == 1? ->  error
  {
    return -1;
  }
  
  if (!(I2C_BASE[u8MfsChannel]->IBCR & 0x40))    // ACT == 0? ->  error
  {
    return -1;
  }
  
  // MSS is set, no reserved address
  
  if (I2C_BASE[u8MfsChannel]->IBSR & 0x40)       // RACK == 1? ->  error
  {
    return -1;
  }

  if (u8Data & 0x01)                   // Read = 0, Write = 1
  {
    if (I2C_BASE[u8MfsChannel]->IBSR & 0x10)     // TRX != (data & 0x01) ? ->  error
    {    
      return -1;
    }
  }
  else
  {
    if (!(I2C_BASE[u8MfsChannel]->IBSR & 0x10)) // TRX == (data & 0x01) ? ->  error
    {
      return -1; 
    }
  }
  
  return 0;
}


//Stop I2C Write Communication
int32_t Multicon_I2cWriteStop(uint8_t u8MfsChannel)
{ 
  volatile uint32_t u32Timeout;
  if (I2C_BASE[u8MfsChannel] == NULL)
  {
      return -1;
  }
  u32Timeout = I2C_STOP_TIMEOUT;
  
  I2C_BASE[u8MfsChannel]->IBCR = 0x20;       // MMS = CSS = INT = 0, ACKE = 1
  
  while(1 == (I2C_BASE[u8MfsChannel]->IBSR & 0x01))
  {
    u32Timeout--;
    if (u32Timeout == 0)
    {
      return -1;
    }
  }
  return 0;
}

int32_t Multicon_I2cReadStop(uint8_t u8MfsChannel)
{
  if (I2C_BASE[u8MfsChannel] == NULL)
  {
      return -1;
  }
  I2C_BASE[u8MfsChannel]->IBCR = 0x01;     // INT = 1, MMS = ACKE = 0
  return 0;
}


//Receive I2C Byte
//RETURNS: 0 = 0k / -1 = Error
int16_t Multicon_I2cReceiveByte(uint8_t u8MfsChannel)
{ 
  volatile uint32_t u32Timeout;
  int16_t i16Data = -1;
  uint16_t u16ErrorCount = 1;
  
  if (I2C_BASE[u8MfsChannel] == NULL)
  {
      return -1;
  }
  do
  {
    if ((!(I2C_BASE[u8MfsChannel]->IBSR & 0x80))&& (u16ErrorCount != 1))   // FBT == 0 -> finished read
    {
      i16Data = I2C_BASE[u8MfsChannel]->RDR;
      u16ErrorCount = 0;
    }
    else
    {
      u16ErrorCount++;
      if (u16ErrorCount > I2C_TIME_OUT)     // too much retrails
      {
        return -1; 
      }
      
      I2C_BASE[u8MfsChannel]->IBCR = 0xB0;   // WSEL = 1, ACKE = 1, Clear INT flag
      
      u32Timeout = I2C_TIME_OUT;
      while(!(I2C_BASE[u8MfsChannel]->IBCR & 0x01)) // Wait for transmission complete
      {                                     //   via INT flag
          u32Timeout--;
          if (u32Timeout == 0)
          {
              return -1;
          }
      }     
      if (I2C_BASE[u8MfsChannel]->IBCR & 0x02)       // BER == 1? ->  error
      {
        return -1;
      }
      
      if (!(I2C_BASE[u8MfsChannel]->IBCR & 0x40))    // ACT == 0? ->  error
      {
        return -2;
      }
      
      // MSS is set, no reserved address
      
      if (I2C_BASE[u8MfsChannel]->IBSR & 0x40)       // RACK == 1? ->  error
      {
        return -3;
      }
      
      if (I2C_BASE[u8MfsChannel]->IBSR & 0x10)       // TRX == 1? ->  error
      {
        return -4;
      }
    }
  }while(u16ErrorCount);
  
  return i16Data;
}


boolean_t Multicon_UartInit(uint8_t u8Uart, uint32_t Baudrate)
{
    if (UART_BASE[u8Uart] == NULL)
    {
        return FALSE;
    }
    UART_BASE[u8Uart]->SCR =  0x80;
    UART_BASE[u8Uart]->SMR =  0x01;
    UART_BASE[u8Uart]->SSR =  0x00;
    UART_BASE[u8Uart]->ESCR = 0x00;
    UART_BASE[u8Uart]->BGR = (uint16_t)Baudrate;
    UART_BASE[u8Uart]->SCR = 0x03;
    return TRUE;
}

boolean_t Multicon_UartHasData(uint8_t u8Uart)
{
    //uint8_t u8Dummy;
    if (UART_BASE[u8Uart] == NULL)
    {
        return FALSE;
    }
    if ((UART_BASE[u8Uart]->SSR & (1 << 2)))
    {
        if (UART_BASE[u8Uart]->SSR & 0x38) 
        {	// overrun or parity error
            UART_BASE[u8Uart]->SSR |= (1 << 7);
            return FALSE;//(-1);
        } 
        else
        {
            return TRUE;
        }
    }
    return FALSE;
}

void Multicon_UartSendByte(uint8_t u8Uart, uint8_t u8Data)
{
    if (UART_BASE[u8Uart] == NULL)
    {
        return;
    }
    while (!(UART_BASE[u8Uart]->SSR & (1 << 1)));
    UART_BASE[u8Uart]->RDR = u8Data;            
}

uint8_t Multicon_UartGetByte(uint8_t u8Uart)
{
    //char_t cDummy;
    if (UART_BASE[u8Uart] == NULL)
    {
        return 0;
    }
    while(!(UART_BASE[u8Uart]->SSR & (1 << 2)));
    if (UART_BASE[u8Uart]->SSR & 0x38) 
    {	// overrun or parity error 
        UART_BASE[u8Uart]->SSR |= (1 << 7);
        return 0;
    } 
    else
    {
	return (UART_BASE[u8Uart]->RDR);
    }
}

*/
