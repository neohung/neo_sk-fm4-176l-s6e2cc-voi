#ifndef __MULTICON_UART_H__
#define __MULTICON_UART_H__

#include "mcu.h"
#include "base_types.h"

#ifndef CLOCK_FREQ
    #ifdef __PLLCLK
        #define CLOCK_FREQ __PLLCLK
    #else
        #error __PLLCLK is undefined!
    #endif
#endif

#define UART_BAUDRATE(x)  (uint16_t)((CLOCK_FREQ/((uint32_t)x - 1))/2)

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


boolean_t Uart_Init(uint8_t u8Uart, uint32_t Baudrate);
int puts(const char_t* String);
void putdec(uint32_t x);
void puthex(uint32_t n, uint8_t digits);
char* receive_line_echo(int *cnt);
int printf(const char* format, ...);

#endif