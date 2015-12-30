#ifndef NEO_I2S_H
#define NEO_I2S_H

#include "mcu.h" 
#include "pdl_header.h" 

void i2s_init();

#define I2CCODEC_I2CSTART(data)             MULTICON_INTERNAL_I2CSTART(data)
#define I2CCODEC_I2CSENDBYTE(data)          MULTICON_INTERNAL_I2CSENDBYTE(data)         
#define I2CCODEC_I2CCONTINUESENDBYTE(data)  MULTICON_INTERNAL_I2CCONTINUESENDBYTE(data)
#define I2CCODEC_I2CWRITESTOP()             MULTICON_INTERNAL_I2CWRITESTOP()
#define I2CCODEC_I2CREADSTOP()              MULTICON_INTERNAL_I2CREADSTOP()      
#define I2CCODEC_I2CRECEIVEBYTE()           MULTICON_INTERNAL_I2CRCEIVEBYTE() 

/*
    #define MULTICON_INTERNAL_MFS_CHANNEL               14
    #define MULTICON_INTERNAL_INIT(mode)                Multicon_Init(14, mode)
    #define MULTICON_INTERNAL_I2CSTART(data)            Multicon_I2cStart(14,data)
    #define MULTICON_INTERNAL_I2CSENDBYTE(data)         Multicon_I2cSendByte(14,data)
    #define MULTICON_INTERNAL_I2CCONTINUESENDBYTE(data) Multicon_I2cContinueSendByte(14,data)
    #define MULTICON_INTERNAL_I2CWRITESTOP()            Multicon_I2cWriteStop(14)
    #define MULTICON_INTERNAL_I2CREADSTOP()             Multicon_I2cReadStop(14)
    #define MULTICON_INTERNAL_I2CRCEIVEBYTE()           Multicon_I2cReceiveByte(14) 
*/

#endif