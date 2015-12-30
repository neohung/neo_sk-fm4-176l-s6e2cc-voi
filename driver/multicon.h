/* multicon.h - Source Code for Spansion's Evaluation Board Support Package */
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
/** \file multicon.h
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
#ifndef __MULTICON_H__
#define __MULTICON_H__

//#include "board.h"

#include "mcu.h"
#include "base_types.h"

/*
#define I2C_TIME_OUT          5000      // error counter time-out
#define I2C_STOP_TIMEOUT      0xFFFF    // time-out for stop condition
#define I2C_RW_READ           1
#define I2C_RW_WRITE          0

#if defined(_SK_FM3_48PMC_MB9BF524K_)
    #define MULTICON1_MFS_CHANNEL               3
    #define MULTICON1_INIT(mode)                Multicon_Init(3, mode)
    #define MULTICON1_I2CSTART(data)            Multicon_I2cStart(3,data)
    #define MULTICON1_I2CSENDBYTE(data)         Multicon_I2cSendByte(3,data)
    #define MULTICON1_I2CCONTINUESENDBYTE(data) Multicon_I2cContinueSendByte(3,data)
    #define MULTICON1_I2CWRITESTOP()            Multicon_I2cWriteStop(3)
    #define MULTICON1_I2CREADSTOP()             Multicon_I2cReadStop(3)
    #define MULTICON1_I2CRCEIVEBYTE()           Multicon_I2cReceiveByte(3)

    #define MULTICON1_UARTINIT(baudrate)        Multicon_UartInit(3,MULTICON_UART_BAUDRATE(baudrate))
    #define MULTICON1_UARTHASDATA()             Multicon_UartHasData(3)
    #define MULTICON1_SENDBYTE(x)               Multicon_UartSendByte(3,x)
    #define MULTICON1_GETBYTE(x)                Multicon_UartGetByte(3)
#elif defined(_SK_FM3_64PMC1_)
    #define MULTICON1_MFS_CHANNEL               2
    #define MULTICON1_INIT(mode)                Multicon_Init(2, mode)
    #define MULTICON1_I2CSTART(data)            Multicon_I2cStart(2,data)
    #define MULTICON1_I2CSENDBYTE(data)         Multicon_I2cSendByte(2,data)
    #define MULTICON1_I2CCONTINUESENDBYTE(data) Multicon_I2cContinueSendByte(2,data)
    #define MULTICON1_I2CWRITESTOP()            Multicon_I2cWriteStop(2)
    #define MULTICON1_I2CREADSTOP()             Multicon_I2cReadStop(2)
    #define MULTICON1_I2CRCEIVEBYTE()           Multicon_I2cReceiveByte(2)

    #define MULTICON1_UARTINIT(baudrate)        Multicon_UartInit(2,MULTICON_UART_BAUDRATE(baudrate))
    #define MULTICON1_UARTHASDATA()             Multicon_UartHasData(2)
    #define MULTICON1_SENDBYTE(x)               Multicon_UartSendByte(2,x)
    #define MULTICON1_GETBYTE(x)                Multicon_UartGetByte(2)
#elif defined(_SK_FM3_100PMC_) || defined(_SK_FM3_100PMC_MB9BF516N_)
    #define MULTICON1_MFS_CHANNEL               3
    #define MULTICON1_INIT(mode)                Multicon_Init(3, mode)
    #define MULTICON1_I2CSTART(data)            Multicon_I2cStart(3,data)
    #define MULTICON1_I2CSENDBYTE(data)         Multicon_I2cSendByte(3,data)
    #define MULTICON1_I2CCONTINUESENDBYTE(data) Multicon_I2cContinueSendByte(3,data)
    #define MULTICON1_I2CWRITESTOP()            Multicon_I2cWriteStop(3)
    #define MULTICON1_I2CREADSTOP()             Multicon_I2cReadStop(3)
    #define MULTICON1_I2CRCEIVEBYTE()           Multicon_I2cReceiveByte(3)

    #define MULTICON1_UARTINIT(baudrate)        Multicon_UartInit(3,MULTICON_UART_BAUDRATE(baudrate))
    #define MULTICON1_UARTHASDATA()             Multicon_UartHasData(3)
    #define MULTICON1_SENDBYTE(x)               Multicon_UartSendByte(3,x)
    #define MULTICON1_GETBYTE(x)                Multicon_UartGetByte(3)
#elif defined(_SK_FM3_100PMC_MB9AFB44N_)
    #define MULTICON1_MFS_CHANNEL               7
    #define MULTICON1_INIT(mode)                Multicon_Init(7, mode)
    #define MULTICON1_I2CSTART(data)            Multicon_I2cStart(7,data)
    #define MULTICON1_I2CSENDBYTE(data)         Multicon_I2cSendByte(7,data)
    #define MULTICON1_I2CCONTINUESENDBYTE(data) Multicon_I2cContinueSendByte(7,data)
    #define MULTICON1_I2CWRITESTOP()            Multicon_I2cWriteStop(7)
    #define MULTICON1_I2CREADSTOP()             Multicon_I2cReadStop(7)
    #define MULTICON1_I2CRCEIVEBYTE()           Multicon_I2cReceiveByte(7)

    #define MULTICON1_UARTINIT(baudrate)        Multicon_UartInit(7,MULTICON_UART_BAUDRATE(baudrate))
    #define MULTICON1_UARTHASDATA()             Multicon_UartHasData(7)
    #define MULTICON1_SENDBYTE(x)               Multicon_UartSendByte(7,x)
    #define MULTICON1_GETBYTE(x)                Multicon_UartGetByte(7)
#elif defined(_SK_FM3_176PMC_ETHERNET_)
    #define MULTICON1_MFS_CHANNEL               1
    #define MULTICON1_INIT(mode)                Multicon_Init(1, mode)
    #define MULTICON1_I2CSTART(data)            Multicon_I2cStart(1,data)
    #define MULTICON1_I2CSENDBYTE(data)         Multicon_I2cSendByte(1,data)
    #define MULTICON1_I2CCONTINUESENDBYTE(data) Multicon_I2cContinueSendByte(1,data)
    #define MULTICON1_I2CWRITESTOP()            Multicon_I2cWriteStop(1)
    #define MULTICON1_I2CREADSTOP()             Multicon_I2cReadStop(1)
    #define MULTICON1_I2CRCEIVEBYTE()           Multicon_I2cReceiveByte(1)

    #define MULTICON1_UARTINIT(baudrate)        Multicon_UartInit(1,MULTICON_UART_BAUDRATE(baudrate))
    #define MULTICON1_UARTHASDATA()             Multicon_UartHasData(1)
    #define MULTICON1_SENDBYTE(x)               Multicon_UartSendByte(1,x)
    #define MULTICON1_GETBYTE(x)                Multicon_UartGetByte(1)
#elif defined(_SK_FM3_176PMC_FA_)
    #define MULTICON1_MFS_CHANNEL               6
    #define MULTICON1_INIT(mode)                Multicon_Init(6, mode)
    #define MULTICON1_I2CSTART(data)            Multicon_I2cStart(6,data)
    #define MULTICON1_I2CSENDBYTE(data)         Multicon_I2cSendByte(6,data)
    #define MULTICON1_I2CCONTINUESENDBYTE(data) Multicon_I2cContinueSendByte(1,data)
    #define MULTICON1_I2CWRITESTOP()            Multicon_I2cWriteStop(6)
    #define MULTICON1_I2CREADSTOP()             Multicon_I2cReadStop(6)
    #define MULTICON1_I2CRCEIVEBYTE()           Multicon_I2cReceiveByte(6)

    #define MULTICON1_UARTINIT(baudrate)        Multicon_UartInit(1,MULTICON_UART_BAUDRATE(baudrate))
    #define MULTICON1_UARTHASDATA()             Multicon_UartHasData(1)
    #define MULTICON1_SENDBYTE(x)               Multicon_UartSendByte(1,x)
    #define MULTICON1_GETBYTE(x)                Multicon_UartGetByte(1)
#elif defined(_SK_FM3_176PMC_TFT_)
    #define MULTICON1_MFS_CHANNEL               6
    #define MULTICON1_INIT(mode)                Multicon_Init(6, mode)
    #define MULTICON1_I2CSTART(data)            Multicon_I2cStart(6,data)
    #define MULTICON1_I2CSENDBYTE(data)         Multicon_I2cSendByte(6,data)
    #define MULTICON1_I2CCONTINUESENDBYTE(data) Multicon_I2cContinueSendByte(6,data)
    #define MULTICON1_I2CWRITESTOP()            Multicon_I2cWriteStop(6)
    #define MULTICON1_I2CREADSTOP()             Multicon_I2cReadStop(6)
    #define MULTICON1_I2CRCEIVEBYTE()           Multicon_I2cReceiveByte(6)

    #define MULTICON1_UARTINIT(baudrate)        Multicon_UartInit(6,MULTICON_UART_BAUDRATE(baudrate))
    #define MULTICON1_UARTHASDATA()             Multicon_UartHasData(6)
    #define MULTICON1_SENDBYTE(x)               Multicon_UartSendByte(6,x)
    #define MULTICON1_GETBYTE(x)                Multicon_UartGetByte(6)

    #define MULTICON2_MFS_CHANNEL               1
    #define MULTICON2_INIT(mode)                Multicon_Init(1, mode)
    #define MULTICON2_I2CSTART(data)            Multicon_I2cStart(1,data)
    #define MULTICON2_I2CSENDBYTE(data)         Multicon_I2cSendByte(1,data)
    #define MULTICON2_I2CCONTINUESENDBYTE(data) Multicon_I2cContinueSendByte(1,data)
    #define MULTICON2_I2CWRITESTOP()            Multicon_I2cWriteStop(1)
    #define MULTICON2_I2CREADSTOP()             Multicon_I2cReadStop(1)
    #define MULTICON2_I2CRCEIVEBYTE()           Multicon_I2cReceiveByte(1)

    #define MULTICON2_UARTINIT(baudrate)        Multicon_UartInit(1,MULTICON_UART_BAUDRATE(baudrate))
    #define MULTICON2_UARTHASDATA()             Multicon_UartHasData(1)
    #define MULTICON2_SENDBYTE(x)               Multicon_UartSendByte(1,x)
    #define MULTICON2_GETBYTE(x)                Multicon_UartGetByte(1)

#elif defined(_SK_FM4_120PMC_TFT_)
    #define MULTICON1_MFS_CHANNEL               5
    #define MULTICON1_INIT(mode)                Multicon_Init(5, mode)
    #define MULTICON1_I2CSTART(data)            Multicon_I2cStart(5,data)
    #define MULTICON1_I2CSENDBYTE(data)         Multicon_I2cSendByte(5,data)
    #define MULTICON1_I2CCONTINUESENDBYTE(data) Multicon_I2cContinueSendByte(5,data)
    #define MULTICON1_I2CWRITESTOP()            Multicon_I2cWriteStop(5)
    #define MULTICON1_I2CREADSTOP()             Multicon_I2cReadStop(5)
    #define MULTICON1_I2CRCEIVEBYTE()           Multicon_I2cReceiveByte(5)

    #define MULTICON1_UARTINIT(baudrate)        Multicon_UartInit(5,MULTICON_UART_BAUDRATE(baudrate))
    #define MULTICON1_UARTHASDATA()             Multicon_UartHasData(5)
    #define MULTICON1_SENDBYTE(x)               Multicon_UartSendByte(5,x)
    #define MULTICON1_GETBYTE(x)                Multicon_UartGetByte(5)

    #define MULTICON2_MFS_CHANNEL               2
    #define MULTICON2_INIT(mode)                Multicon_Init(2, mode)
    #define MULTICON2_I2CSTART(data)            Multicon_I2cStart(2,data)
    #define MULTICON2_I2CSENDBYTE(data)         Multicon_I2cSendByte(2,data)
    #define MULTICON2_I2CCONTINUESENDBYTE(data) Multicon_I2cContinueSendByte(2,data)
    #define MULTICON2_I2CWRITESTOP()            Multicon_I2cWriteStop(2)
    #define MULTICON2_I2CREADSTOP()             Multicon_I2cReadStop(2)
    #define MULTICON2_I2CRCEIVEBYTE()           Multicon_I2cReceiveByte(2)

    #define MULTICON2_UARTINIT(baudrate)        Multicon_UartInit(2,MULTICON_UART_BAUDRATE(baudrate))
    #define MULTICON2_UARTHASDATA()             Multicon_UartHasData(2)
    #define MULTICON2_SENDBYTE(x)               Multicon_UartSendByte(2,x)
    #define MULTICON2_GETBYTE(x)                Multicon_UartGetByte(2)
#elif defined(_SK_FM4_216_ETHERNET_)
    #define MULTICON0_MFS_CHANNEL               8
    #define MULTICON0_INIT(mode)                Multicon_Init(8, mode)
    #define MULTICON0_I2CSTART(data)            Multicon_I2cStart(8,data)
    #define MULTICON0_I2CSENDBYTE(data)         Multicon_I2cSendByte(8,data)
    #define MULTICON0_I2CCONTINUESENDBYTE(data) Multicon_I2cContinueSendByte(8,data)
    #define MULTICON0_I2CWRITESTOP()            Multicon_I2cWriteStop(8)
    #define MULTICON0_I2CREADSTOP()             Multicon_I2cReadStop(8)
    #define MULTICON0_I2CRCEIVEBYTE()           Multicon_I2cReceiveByte(8)

    #define MULTICON0_UARTINIT(baudrate)        Multicon_UartInit(8,MULTICON_UART_BAUDRATE(baudrate))
    #define MULTICON0_UARTHASDATA()             Multicon_UartHasData(8)
    #define MULTICON0_SENDBYTE(x)               Multicon_UartSendByte(8,x)
    #define MULTICON0_GETBYTE(x)                Multicon_UartGetByte(8)

    #define MULTICON1_MFS_CHANNEL               13
    #define MULTICON1_INIT(mode)                Multicon_Init(13, mode)
    #define MULTICON1_I2CSTART(data)            Multicon_I2cStart(13,data)
    #define MULTICON1_I2CSENDBYTE(data)         Multicon_I2cSendByte(13,data)
    #define MULTICON1_I2CCONTINUESENDBYTE(data) Multicon_I2cContinueSendByte(13,data)
    #define MULTICON1_I2CWRITESTOP()            Multicon_I2cWriteStop(13)
    #define MULTICON1_I2CREADSTOP()             Multicon_I2cReadStop(13)
    #define MULTICON1_I2CRCEIVEBYTE()           Multicon_I2cReceiveByte(13)

    #define MULTICON1_UARTINIT(baudrate)        Multicon_UartInit(13,MULTICON_UART_BAUDRATE(baudrate))
    #define MULTICON1_UARTHASDATA()             Multicon_UartHasData(13)
    #define MULTICON1_SENDBYTE(x)               Multicon_UartSendByte(13,x)
    #define MULTICON1_GETBYTE(x)                Multicon_UartGetByte(13)
     
    #define MULTICON_INTERNAL_MFS_CHANNEL               14
    #define MULTICON_INTERNAL_INIT(mode)                Multicon_Init(14, mode)
    #define MULTICON_INTERNAL_I2CSTART(data)            Multicon_I2cStart(14,data)
    #define MULTICON_INTERNAL_I2CSENDBYTE(data)         Multicon_I2cSendByte(14,data)
    #define MULTICON_INTERNAL_I2CCONTINUESENDBYTE(data) Multicon_I2cContinueSendByte(14,data)
    #define MULTICON_INTERNAL_I2CWRITESTOP()            Multicon_I2cWriteStop(14)
    #define MULTICON_INTERNAL_I2CREADSTOP()             Multicon_I2cReadStop(14)
    #define MULTICON_INTERNAL_I2CRCEIVEBYTE()           Multicon_I2cReceiveByte(14) 
#endif

#ifndef CLOCK_FREQ
    #ifdef __PLLCLK
        #define CLOCK_FREQ __PLLCLK
    #else
        #error __PLLCLK is undefined!
    #endif
#endif


#define MULTICON_UART_BAUDRATE(x)  (uint16_t)((CLOCK_FREQ/((uint32_t)x - 1))/2)

typedef struct stc_multicon_mfs_uart_smr_field
{
  __IO  uint8_t SOE        : 1;
        uint8_t RESERVED1  : 1;
  __IO  uint8_t BDS        : 1;
  __IO  uint8_t SBL        : 1;
  __IO  uint8_t WUCR       : 1;
  __IO  uint8_t MD         : 3;
} stc_multicon_mfs_uart_smr_field_t;

typedef struct stc_multicon_mfs_uart_scr_field
{
  __IO  uint8_t TXE        : 1;
  __IO  uint8_t RXE        : 1;
  __IO  uint8_t TBIE       : 1;
  __IO  uint8_t TIE        : 1;
  __IO  uint8_t RIE        : 1;
        uint8_t RESERVED1  : 2;
  __IO  uint8_t UPCL       : 1;
} stc_multicon_mfs_uart_scr_field_t;

typedef struct stc_multicon_mfs_uart_escr_field
{
  __IO  uint8_t L0         : 1;
  __IO  uint8_t L1         : 1;
  __IO  uint8_t L2         : 1;
  __IO  uint8_t P          : 1;
  __IO  uint8_t PEN        : 1;
  __IO  uint8_t INV        : 1;
  __IO  uint8_t ESBL       : 1;
  __IO  uint8_t FLWEN      : 1;
} stc_multicon_mfs_uart_escr_field_t;

typedef struct stc_multicon_mfs_uart_ssr_field
{
  __IO  uint8_t TBI        : 1;
  __IO  uint8_t TDRE       : 1;
  __IO  uint8_t RDRF       : 1;
  __IO  uint8_t ORE        : 1;
  __IO  uint8_t FRE        : 1;
  __IO  uint8_t PE         : 1;
        uint8_t RESERVED1  : 1;
  __IO  uint8_t REC        : 1;
} stc_multicon_mfs_uart_ssr_field_t;

typedef struct stc_multicon_mfs_uart_rdr_field
{
       uint16_t RESERVED1  : 8;
  __IO uint16_t AD         : 1;
} stc_multicon_mfs_uart_rdr_field_t;

typedef struct stc_multicon_mfs_uart_tdr_field
{
       uint16_t RESERVED1  : 8;
  __IO uint16_t AD         : 1;
} stc_multicon_mfs_uart_tdr_field_t;

typedef struct stc_multicon_mfs_uart_bgr_field
{
       uint16_t RESERVED1  : 15;
  __IO uint16_t EXT        : 1;
} stc_multicon_mfs_uart_bgr_field_t;

typedef struct stc_multicon_mfs_uart_bgr1_field
{
        uint8_t RESERVED1  : 7;
  __IO  uint8_t EXT        : 1;
} stc_multicon_mfs_uart_bgr1_field_t;

typedef struct stc_multicon_mfs_uart
{
  union {
    __IO  uint8_t SMR;
    stc_multicon_mfs_uart_smr_field_t SMR_f;
  };
  union {
    __IO  uint8_t SCR;
    stc_multicon_mfs_uart_scr_field_t SCR_f;
  };
       uint8_t RESERVED1[2];
  union {
    __IO  uint8_t ESCR;
    stc_multicon_mfs_uart_escr_field_t ESCR_f;
  };
  union {
    __IO  uint8_t SSR;
    stc_multicon_mfs_uart_ssr_field_t SSR_f;
  };
       uint8_t RESERVED3[2];
  union {
    union {
      __IO uint16_t RDR;
      stc_multicon_mfs_uart_rdr_field_t RDR_f;
    };
    union {
      __IO uint16_t TDR;
      stc_multicon_mfs_uart_tdr_field_t TDR_f;
    };
  };
       uint8_t RESERVED5[2];
  union {
    union {
      __IO uint16_t BGR;
      stc_multicon_mfs_uart_bgr_field_t BGR_f;
    };
    struct {
      __IO  uint8_t BGR0;
      union {
        __IO  uint8_t BGR1;
        stc_multicon_mfs_uart_bgr1_field_t BGR1_f;
      };
    };
  };
} stc_multicon_mfs_uart_t;






typedef struct stc_multicon_mfs_i2c_smr_field
{
        uint8_t RESERVED1  : 2;
  __IO  uint8_t TIE        : 1;
  __IO  uint8_t RIE        : 1;
  __IO  uint8_t WUCR       : 1;
  __IO  uint8_t MD         : 3;
} stc_multicon_mfs_i2c_smr_field_t;

typedef struct stc_multicon_mfs_i2c_ibcr_field
{
  __IO  uint8_t INT        : 1;
  __IO  uint8_t BER        : 1;
  __IO  uint8_t INTE       : 1;
  __IO  uint8_t CNDE       : 1;
  __IO  uint8_t WSEL       : 1;
  __IO  uint8_t ACKE       : 1;
  __IO  uint8_t SCC        : 1;
  __IO  uint8_t MSS        : 1;
} stc_multicon_mfs_i2c_ibcr_field_t;

typedef struct stc_multicon_mfs_i2c_ibsr_field
{
  __IO  uint8_t BB         : 1;
  __IO  uint8_t SPC        : 1;
  __IO  uint8_t RSC        : 1;
  __IO  uint8_t AL         : 1;
  __IO  uint8_t TRX        : 1;
  __IO  uint8_t RSA        : 1;
  __IO  uint8_t RACK       : 1;
  __IO  uint8_t FBT        : 1;
} stc_multicon_mfs_i2c_ibsr_field_t;

typedef struct stc_multicon_mfs_i2c_ssr_field
{
  __IO  uint8_t TBI        : 1;
  __IO  uint8_t TDRE       : 1;
  __IO  uint8_t RDRF       : 1;
  __IO  uint8_t ORE        : 1;
  __IO  uint8_t TBIE       : 1;
  __IO  uint8_t DMA        : 1;
  __IO  uint8_t TSET       : 1;
  __IO  uint8_t REC        : 1;
} stc_multicon_mfs_i2c_ssr_field_t;

typedef struct stc_multicon_mfs_i2c_isba_field
{
  __IO  uint8_t SA0        : 1;
  __IO  uint8_t SA1        : 1;
  __IO  uint8_t SA2        : 1;
  __IO  uint8_t SA3        : 1;
  __IO  uint8_t SA4        : 1;
  __IO  uint8_t SA5        : 1;
  __IO  uint8_t SA6        : 1;
  __IO  uint8_t SAEN       : 1;
} stc_multicon_mfs_i2c_isba_field_t;

typedef struct stc_multicon_mfs_i2c_ismk_field
{
  __IO  uint8_t SM0        : 1;
  __IO  uint8_t SM1        : 1;
  __IO  uint8_t SM2        : 1;
  __IO  uint8_t SM3        : 1;
  __IO  uint8_t SM4        : 1;
  __IO  uint8_t SM5        : 1;
  __IO  uint8_t SM6        : 1;
  __IO  uint8_t EN         : 1;
} stc_multicon_mfs_i2c_ismk_field_t;

typedef struct stc_multicon_mfs_i2c
{
  union {
    __IO  uint8_t       SMR;
    stc_multicon_mfs_i2c_smr_field_t SMR_f;
  };
  union {
    __IO  uint8_t            SCR;
    stc_multicon_mfs_uart_scr_field_t      SCR_f;
    __IO  uint8_t            IBCR;
    stc_multicon_mfs_i2c_ibcr_field_t IBCR_f;
  };
        uint8_t RESERVED0[2];
  union {
    __IO  uint8_t            ESCR;
    stc_multicon_mfs_uart_escr_field_t     ESCR_f;
    __IO  uint8_t            IBSR;
    stc_multicon_mfs_i2c_ibsr_field_t IBSR_f;
  };
  union {
    __IO  uint8_t       SSR;
    stc_multicon_mfs_i2c_ssr_field_t SSR_f;
  };
        uint8_t RESERVED1[2];
  union {
    __IO uint32_t RDR32;
    __IO uint32_t TDR32;
    struct {
      union {
        __IO uint16_t            RDR;
      };
             uint8_t RESERVED2[2];
    };
    struct {
      union {
        __IO uint16_t            TDR;
      };
             uint8_t RESERVED3[2];
    };
  };
  union {
    union {
      __IO uint16_t       BGR;
      stc_multicon_mfs_uart_bgr_field_t BGR_f;
    };
    struct {
      __IO  uint8_t BGR0;
      union {
        __IO  uint8_t        BGR1;
        stc_multicon_mfs_uart_bgr1_field_t BGR1_f;
      };
    };
  };
        uint8_t RESERVED4[2];
  union {
    __IO  uint8_t            ISBA;
    stc_multicon_mfs_i2c_isba_field_t ISBA_f;
  };
  union {
    __IO  uint8_t            ISMK;
    stc_multicon_mfs_i2c_ismk_field_t ISMK_f;
  };
        uint8_t RESERVED5[2];
  union {
    union {
      __IO uint16_t       FCR;
    };
    struct {
      union {
        __IO  uint8_t        FCR0;
      };
      union {
        __IO  uint8_t        FCR1;
      };
    };
  };
        uint8_t RESERVED6[2];
  union {
    union {
      __IO uint16_t         FBYTE;
    };
    struct {
      union {
        __IO  uint8_t          FBYTE1;
      };
      union {
        __IO  uint8_t          FBYTE2;
      };
    };
  };
        uint8_t RESERVED7[2];
  union {
    __IO uint16_t                SCSTR10;
    struct {
      union {
        __IO  uint8_t               SCSTR0;
        __IO  uint8_t NFCR;
      };
      union {
        __IO  uint8_t               SCSTR1;
        __IO  uint8_t               EIBCR;
      };
    };
  };
        uint8_t RESERVED8[2];
  union {
    __IO uint16_t                SCSTR32;
    struct {
      union {
        __IO  uint8_t               SCSTR2;
      };
      union {
        __IO  uint8_t               SCSTR3;
      };
    };
  };
        uint8_t RESERVED9[2];
  union {
    __IO uint16_t              SACSR;
    struct {
      union {
        __IO  uint8_t               SACSR0;
      };
      union {
        __IO  uint8_t               SACSR1;
      };
    };
  };
        uint8_t RESERVED10[2];
  union {
    __IO uint16_t             STMR;
    struct {
      union {
        __IO  uint8_t              STMR0;
      };
      union {
        __IO  uint8_t              STMR1;
      };
    };
  };
        uint8_t RESERVED11[2];
  union {
    __IO uint16_t              STMCR;
    struct {
      union {
        __IO  uint8_t               STMCR0;
      };
      union {
        __IO  uint8_t               STMCR1;
      };
    };
  };
        uint8_t RESERVED12[2];
  union {
    __IO uint16_t              SCSCR;
  };
        uint8_t RESERVED13[2];
  union {
    __IO uint16_t SCSFR;
    struct {
      __IO  uint8_t SCSFR0;
      __IO  uint8_t SCSFR1;
    };
  };
        uint8_t RESERVED14[2];
  __IO  uint8_t SCSFR2;
        uint8_t RESERVED15[3];
  union {
    __IO uint16_t TBYTE10;
    struct {
      __IO  uint8_t TBYTE0;
      __IO  uint8_t TBYTE1;
    };
  };
        uint8_t RESERVED16[2];
  union {
    __IO uint16_t TBYTE32;
    struct {
      __IO  uint8_t TBYTE2;
      __IO  uint8_t TBYTE3;
    };
  };
}stc_multicon_mfs_i2c_t;


typedef enum en_multicon_mode
{
    MulticonUnknown = 0,
    MulticonI2C,
    MulticonSpi,
    MulticonUart,
} en_multicon_mode_t;

typedef struct stc_pinsettings_i2c
{
  boolean_t bUsable;
  volatile uint32_t* pu32DDR;
  volatile uint32_t* pu32PFR;
  volatile uint32_t* pu32PDOR;
  volatile uint32_t* pu32PDIR;
  uint32_t u32SclMask;
  uint32_t u32SdaMask;
} stc_pinsettings_i2c_t;

boolean_t Multicon_Init(uint8_t u8MfsChannel, en_multicon_mode_t enMode);
en_result_t Multicon_I2CBusClear(uint8_t u8MfsChannel);
int32_t Multicon_I2cStart(uint8_t u8MfsChannel, uint8_t u8Data);
int32_t Multicon_I2cSendByte(uint8_t u8MfsChannel, uint8_t u8Data);
void Multicon_I2cSendBytes(uint8_t u8MfsChannel, uint8_t* pu8Data, uint32_t u32Size);
int32_t Multicon_I2cContinueSendByte(uint8_t u8MfsChannel, uint8_t u8Data);
int32_t Multicon_I2cWriteStop(uint8_t u8MfsChannel);
int32_t Multicon_I2cReadStop(uint8_t u8MfsChannel);
int16_t Multicon_I2cReceiveByte(uint8_t u8MfsChannel);

boolean_t Multicon_UartInit(uint8_t u8Uart, uint32_t Baudrate);
boolean_t Multicon_UartHasData(uint8_t u8Uart);
void Multicon_UartSendByte(uint8_t u8Uart, uint8_t u8Data);
uint8_t Multicon_UartGetByte(uint8_t u8Uart);
*/

#endif // __MULTICON_H__ 
