#ifndef __MULTICON_I2C_H__
#define __MULTICON_I2C_H__

#include "mcu.h"
#include "base_types.h"

#define I2C_TIME_OUT          5000//5000      // error counter time-out
#define I2C_STOP_TIMEOUT      0xFFFF    // time-out for stop condition
#define I2C_RW_READ           1
#define I2C_RW_WRITE          0


typedef enum en_multicon_mode
{
    MulticonUnknown = 0,
    MulticonI2C,
    MulticonSpi,
    MulticonUart,
} en_multicon_mode_t;

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
    //stc_multicon_mfs_uart_scr_field_t      SCR_f;
    __IO  uint8_t            IBCR;
    stc_multicon_mfs_i2c_ibcr_field_t IBCR_f;
  };
        uint8_t RESERVED0[2];
  union {
    __IO  uint8_t            ESCR;
   // stc_multicon_mfs_uart_escr_field_t     ESCR_f;
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
    //  stc_multicon_mfs_uart_bgr_field_t BGR_f;
    };
    struct {
      __IO  uint8_t BGR0;
      union {
        __IO  uint8_t        BGR1;
      //  stc_multicon_mfs_uart_bgr1_field_t BGR1_f;
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

boolean_t I2C_Init(uint8_t u8MfsChannel);
int32_t Multicon_I2cStart(uint8_t u8MfsChannel, uint8_t u8Data);

/*
boolean_t Multicon_Init(uint8_t u8MfsChannel, en_multicon_mode_t enMode);
en_result_t Multicon_I2CBusClear(uint8_t u8MfsChannel);
int32_t Multicon_I2cStart(uint8_t u8MfsChannel, uint8_t u8Data);
int32_t Multicon_I2cSendByte(uint8_t u8MfsChannel, uint8_t u8Data);
void Multicon_I2cSendBytes(uint8_t u8MfsChannel, uint8_t* pu8Data, uint32_t u32Size);
int32_t Multicon_I2cContinueSendByte(uint8_t u8MfsChannel, uint8_t u8Data);
int32_t Multicon_I2cWriteStop(uint8_t u8MfsChannel);
int32_t Multicon_I2cReadStop(uint8_t u8MfsChannel);
int16_t Multicon_I2cReceiveByte(uint8_t u8MfsChannel);
*/
#endif