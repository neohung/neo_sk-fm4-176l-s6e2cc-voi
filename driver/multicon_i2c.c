#include "multicon_uart.h"
#include "multicon_i2c.h"

static stc_multicon_mfs_uart_t* UART_BASE[] = {
        #if defined(FM4_MFS0_BASE)          
          ((stc_multicon_mfs_uart_t *)FM4_MFS0_BASE),
        #else
           //#error "For SK-FM4-176L-S6E2CC UART Should be FM4_MFS0_BASE"
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
          //#error "For SK-FM4-176L-S6E2CC I2C Should be FM4_MFS8_BASE"
          ((stc_multicon_mfs_i2c_t *)FM4_MFS8_BASE),
        #else
          #error "For SK-FM4-176L-S6E2CC I2C Should be FM4_MFS8_BASE"
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


//_SK_FM4_216_ETHERNET_
//astcPinSettings[u8MfsChannel].pu32DDR,
//astcPinSettings[u8MfsChannel].pu32PFR,
//astcPinSettings[u8MfsChannel].pu32PDOR,
//astcPinSettings[u8MfsChannel].pu32PDIR,
//astcPinSettings[u8MfsChannel].u32SclMask,
//astcPinSettings[u8MfsChannel].u32SdaMask
//typedef struct stc_pinsettings_i2c
//{
//  boolean_t bUsable;
//  volatile uint32_t* pu32DDR;
//  volatile uint32_t* pu32PFR;
//  volatile uint32_t* pu32PDOR;
//  volatile uint32_t* pu32PDIR;
//  uint32_t u32SclMask;
//  uint32_t u32SdaMask;
//} stc_pinsettings_i2c_t;
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
  //8
  //{TRUE,&FM4_GPIO->DDR7,&FM4_GPIO->PFR7,&FM4_GPIO->PDOR7,&FM4_GPIO->PDIR7,(1<<7),(1<<6)},
  {TRUE,&FM4_GPIO->DDRB,&FM4_GPIO->PFRB,&FM4_GPIO->PDORB,&FM4_GPIO->PDIRB,(1<<(6+1)),(1<<(5+1))},
    
  {FALSE},
  {FALSE},
  {FALSE},
  {FALSE},
  {TRUE,&FM4_GPIO->DDR6,&FM4_GPIO->PFR6,&FM4_GPIO->PDOR6,&FM4_GPIO->PDIR6,(1<<8),(1<<7)},
  {TRUE,&FM4_GPIO->DDR6,&FM4_GPIO->PFR6,&FM4_GPIO->PDOR6,&FM4_GPIO->PDIR6,(1<<0xD),(1<<0xC)},
  {FALSE}
};

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
        printf("Multicon_I2CBusClear \n\r");
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
            switch(u8MfsChannel)
                {
                    case 8:
                        printf("do acc init\n\r");
                        bFM4_GPIO_PFRB_P5 = 1; // Pin 113 (SOT8_1)
                        bFM4_GPIO_PFRB_P6 = 1; // Pin 114 (SCK8_1)
                        /*                       
                        FM4_GPIO->EPFR16 &= ~(0x3 << 4); // SIN8S 
                        FM4_GPIO->EPFR16 &= ~(0x3 << 6); // SOT8B
                        FM4_GPIO->EPFR16 &= ~(0x3 << 8); // SCK8B
                        
                        FM4_GPIO->EPFR16 |= (0x1 << 6); // SOT8B
                        FM4_GPIO->EPFR16 |= (0x1 << 8); // SCK8B
                        */
                        FM4_GPIO->EPFR16 &= ~(0x3 << 4); // SIN8S 
                        FM4_GPIO->EPFR16 &= ~(0x3 << 6); // SOT8B
                        FM4_GPIO->EPFR16 &= ~(0x3 << 8); // SCK8B
                        
                        FM4_GPIO->EPFR16 |= (0x2 << 6); // SOT8B
                        FM4_GPIO->EPFR16 |= (0x2 << 8); // SCK8B
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
                
                //<<<<<<<<<<<<<<<<  Here to reset UPCL <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
                UART_BASE[u8MfsChannel]->SCR |= 0x80;      // Reset (UPCL = 1)
                //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
              
                I2C_BASE[u8MfsChannel]->SMR  = 0x80;      // operation mode 4, no interrupts, no test
                                                          // mode, no wake up
                                                
                I2C_BASE[u8MfsChannel]->ISBA = 0x00;
                
                I2C_BASE[u8MfsChannel]->NFCR |= 0x0008;  // enable noise filter for I2C ch. 1 for 60-80MHz PCLK operation
                
                I2C_BASE[u8MfsChannel]->ISMK = 0x80;       // Enable I2C interface
                return TRUE;
    }
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
          printf("start1: check IBCR TIME_OUT err\n\r");
            return -1;
        }
    }
   
    if (I2C_BASE[u8MfsChannel]->IBCR & 0x02)       // BER == 1? ->  error
    {
       printf("start2: check IBCR 0x02 err\n\r");
      return -1;
    }

    if (!(I2C_BASE[u8MfsChannel]->IBCR & 0x40))    // ACT == 0? ->  error
    {
      printf("start3: check IBCR 0x40 err\n\r");
      return -1;
    }
    
    // MSS is set ...
  
    if (I2C_BASE[u8MfsChannel]->IBSR & 0x40)  // RACK == 1? ->  busy or error
    {
      I2C_BASE[u8MfsChannel]->IBCR = 0xE0;    // MMS = CSS = ACKE = 1: Try restart (if busy)
      u16ErrorCount++;
      
      if (u16ErrorCount > I2C_TIME_OUT)
      {
        printf("start4: check I2C_TIME_OUT err\n\r");
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
    printf("start5: check IBSR 0x10 err\n\r");
     return -1;
  }
  
  return 0;
}


boolean_t I2C_Init(uint8_t u8MfsChannel)
{
  //u8MfsChannel=8 or 13 or 14
 if (Multicon_Init(u8MfsChannel, MulticonI2C)){
    printf("i2c init pass \n\r");
 } else{
   printf("i2c init fail \n\r");
 }
}

