#include "neo_i2s.h"

static int8_t I2sClockInit(void)
{
	 neo_printf("I2sClockInit\r\n");
	uint32_t u32TimeOut = 1000000ul;
  
  bFM4_CLK_GATING_CKEN2_I2SCK0 = 1u; // enable I2S0 clock peripheral
  
  FM4_GPIO->EPFR24 |= (1ul << 2ul);  // I2S0-MCLK pin to output
  bFM4_GPIO_PFR5_PD = 1u;
        
  FM4_GPIO->EPFR24 |= (1ul << 10ul); // I2S0-DO pin to output
  bFM4_GPIO_PFR5_PE = 1u;
          
  FM4_GPIO->EPFR24 |= (1ul << 4ul);  // I2S0-CK pin to input/output (input used)
  bFM4_GPIO_PFR3_P1 = 1u;
        
  FM4_GPIO->EPFR24 |= (1ul << 6ul);  // I2S0-WS pin to input/output (input used)
  bFM4_GPIO_PFR5_PF = 1u;
 
  // I2S Clock off
  FM4_I2SPRE->ICCR_f.I2SEN = 0u; 
  
  // Clock off within time out?
  while((0u != u32TimeOut) && (1u == FM4_I2SPRE->ICCR_f.I2SEN))  
  {
    u32TimeOut--;
  }
  
  // Too long waited?
  if (0u == u32TimeOut)
  {
    neo_printf("u32TimeOut\r\n");
    return -1;
  }
  
  // Switch off PLL
  FM4_I2SPRE->IPCR1_f.IPLLEN = 0u;
  
  // Set I2SMCLOCK to input
  FM4_I2SPRE->ICCR_f.ICSEL = 0u;
  
  // Set PLL stabilization wait time to 426 us
  FM4_I2SPRE->IPCR2_f.IPOWT = 4u;
  
  // Overclock PLL for SGTL5000 minimum input frequency of 8 MHz
  FM4_I2SPRE->IPCR3_f.IPLLK = 1u;
  FM4_I2SPRE->IPCR4_f.IPLLN = 31u;
  FM4_I2SPRE->IPCR5_f.IPLLM = 7u;
  
  FM4_I2SPRE->IPINT_ENR_f.IPCSE = 0u; // No interrupt used

  // Enable PLL
  FM4_I2SPRE->IPCR1_f.IPLLEN = 1u;
    
  u32TimeOut = 10000000ul;
  
  // Wait for PLL stabilization
  while((0u != u32TimeOut) && (0u == FM4_I2SPRE->IP_STR_f.IPRDY))
  {
    u32TimeOut--;
  }
  
  // Too long waited?
  if (0u == u32TimeOut)
  {
    // Disable PLL
    FM4_I2SPRE->IPCR1_f.IPLLEN = 0u;
    return -1;
  }
  
  // Clock on
  FM4_I2SPRE->ICCR_f.I2SEN = 1u;
   
  return 0;
}

static void I2sStart(void)
{
    FM4_I2S0->OPRREG_f.START  = 1u;  // Start of I2S
}


static int8_t I2sInit(void)
{
  neo_printf("I2sInit\r\n");
  // Disable I2C channel for configuration
  FM4_I2S0->OPRREG_f.START = 0u;     
  // Clock divider configuration: Bypass: Use SGTL5000 clock as is
  FM4_I2S0->CNTREG_f.CKRT  =  0u;  
  // No overhead bits in corresponding sub frame channel
  FM4_I2S0->CNTREG_f.OVHD  =  0u;
  // No mask bit
  FM4_I2S0->CNTREG_f.MSKB  =  0u;  
  // Slave mode 
  FM4_I2S0->CNTREG_f.MSMD  =  0u;  
  // Subframe 0 only
  FM4_I2S0->CNTREG_f.SBFN  =  0u;    
  // FIFO two 16bit half words
  FM4_I2S0->CNTREG_f.RHLL  =  1u; 
  // I2SMCLK to output (for SGTL5000)
  FM4_I2S0->CNTREG_f.ECKM  =  1u;  
  // No bit extension
  FM4_I2S0->CNTREG_f.BEXT  =  0u;   
  // Free run mode
  FM4_I2S0->CNTREG_f.FRUN  =  1u;   
  // Shifting order: MSB first
  FM4_I2S0->CNTREG_f.MLSB  =  0u;   
  // Sampling point of data reception (not used for TX only)
  FM4_I2S0->CNTREG_f.SMPL  =  0u;   
  // Clock polarity (not used for TX only)
  FM4_I2S0->CNTREG_f.CPOL  =  0u; 
  // Data with I2SWS edge
  FM4_I2S0->CNTREG_f.FSPH  =  1u; 
  // I2SWS: one clock pulse
  FM4_I2S0->CNTREG_f.FSLN  =  0u;   
  // I2SWS at '1'
  FM4_I2S0->CNTREG_f.FSPL  =  0u;  
  // Configuration for Sub Frame 0
  FM4_I2S0->MCR0REG_f.S0CHN  =  1u;      // 1 channel sub frame 
  FM4_I2S0->MCR0REG_f.S0CHL  =  15u;     // 16 bit length 
  FM4_I2S0->MCR0REG_f.S0WDL  =  15u;     // 16 bit word length 
  // Configuration for Sub Frame 1
  FM4_I2S0->MCR0REG_f.S1CHN  =  1u;      // 1 channel sub frame 
  FM4_I2S0->MCR0REG_f.S1CHL  =  15u;     // 16 bit length 
  FM4_I2S0->MCR0REG_f.S1WDL  =  15u;     // 16 bit word length   
  // Set active channels for Sub Frame 0   
  FM4_I2S0->MCR1REG  =  3ul;             // Enable channel 0 and 1  
  // Set active channels for Sub Frame 1   
  FM4_I2S0->MCR2REG  =  3ul;             // Enable channel 0 and 1  
  // Interrupts (0 = do not mask interrupt (enable), 1 = mask interrupt (disable)
  FM4_I2S0->INTCNT_f.TXUD0M = 1u;        // Tx FIFO 0 underflow enable interrupt
  FM4_I2S0->INTCNT_f.TXUD1M = 1u;        // Tx FIFO 1 underflow enable interrupt
  FM4_I2S0->INTCNT_f.TBERM  = 1u;        // No Tx block size error interrupt
  FM4_I2S0->INTCNT_f.FERRM  = 1u;        // No Tx Frame error interrupt
  FM4_I2S0->INTCNT_f.TXOVM  = 1u;        // No Tx FIFO overflow interrupt
  FM4_I2S0->INTCNT_f.TXFDM  = 0u;        // Tx DMA                        <----
  FM4_I2S0->INTCNT_f.TXFIM  = 1u;        // No Tx FIFO interrupt          <- Switch this two to use CPU instead of DSTC
  FM4_I2S0->INTCNT_f.RBERM  = 1u;        // No Rx block size error interrupt
  FM4_I2S0->INTCNT_f.RXUDM  = 1u;        // No Rx FIFO overflow interrupt
  FM4_I2S0->INTCNT_f.RXOVM  = 1u;        // No Rx FIFO overflow interrupt
  FM4_I2S0->INTCNT_f.RXFDM  = 1u;        // No Rx DMA
  FM4_I2S0->INTCNT_f.EOPM   = 1u;        // No EOPI interrupt
  FM4_I2S0->INTCNT_f.RXFIM  = 1u;        // No Rx FIFO interrupt
  
  // Tx FIFO thresholds
  FM4_I2S0->INTCNT_f.TFTH = 0x0Fu;  // Set the interrupt trigger to the maximum free space in fifo (16 entries).
  FM4_I2S0->INTCNT_f.RFTH = 0x0Fu;  
  
  // No packet receive completion timer
  FM4_I2S0->INTCNT_f.RPTMR = 0u;
  
  // Enable I2S Transmitter
  FM4_I2S0->OPRREG_f.TXENB = 1u;
  FM4_I2S0->CNTREG_f.TXDIS = 0u;
      
  // Disable I2S Receiver
  FM4_I2S0->OPRREG_f.RXENB = 0u;
  FM4_I2S0->CNTREG_f.RXDIS = 1u;
  
  // Globally enable I2S interrupt  117
  NVIC_ClearPendingIRQ(PCRC_I2S0_1_IRQn);
  NVIC_EnableIRQ(PCRC_I2S0_1_IRQn);
  NVIC_SetPriority(PCRC_I2S0_1_IRQn, 1u);  
   
  return 0;
}

 /**
 ******************************************************************************
 ** \brief  Writes a value to a register of the I2S codec (MSB first)
 **
 ** \param  u16Register   Register address
 ** \param  u16SetValue   New value
 **
 ** \return Ok
 **
 ******************************************************************************/
static void I2scodec_Write(uint16_t u16Register, uint16_t u16SetValue)
{ 

  //I2CCODEC_I2CSTART(I2S_CODEC_ADDRESS << 1);
  //I2CCODEC_I2CSENDBYTE((uint8_t)(u16Register >> 8u));
  //I2CCODEC_I2CSENDBYTE((uint8_t)(u16Register & 0x00FFu));
  //I2CCODEC_I2CSENDBYTE((uint8_t)(u16SetValue >> 8u));
  //I2CCODEC_I2CSENDBYTE((uint8_t)(u16SetValue & 0x00FFu));
  //I2CCODEC_I2CWRITESTOP();

}
/*
//Reads a value of a register of the I2S codec (MSB first)
//u16Register   Register address
static uint16_t I2scodec_Read(uint16_t u16Register)
{
     
  uint16_t u16Data;
  int16_t  i16I2cReception;
  

  I2CCODEC_I2CSTART(I2S_CODEC_ADDRESS << 1);
  I2CCODEC_I2CSENDBYTE((uint8_t)(u16Register >> 8u));
  I2CCODEC_I2CSENDBYTE((uint8_t)(u16Register & 0x00FF));
  I2CCODEC_I2CCONTINUESENDBYTE((I2S_CODEC_ADDRESS << 1) | 1u);   // read
  
  i16I2cReception = I2CCODEC_I2CRECEIVEBYTE();
  if (i16I2cReception < 0)
  {
    return 0u;
  }
  u16Data = ((uint16_t)(0x00FFu & i16I2cReception) << 8u);
  
  i16I2cReception = I2CCODEC_I2CRECEIVEBYTE();
  if (i16I2cReception < 0)
  {
    return 0u;
  }
  u16Data |= ((uint16_t)(0x00FFu & i16I2cReception));
  
  I2CCODEC_I2CREADSTOP();        // set read stop
  I2CCODEC_I2CWRITESTOP();       // force stop
  
  return u16Data;
}

//Modifies a register of the I2S codec by RMW (MSB first)
//u16Register   Register address
//u16ClearMask  Bits to clear
//u16SetValue   New value of the bits
static void I2scodec_Modify(uint16_t u16Register, uint16_t u16ClearMask, uint16_t u16SetValue)
{
  uint16_t u16Data;
  // 1) Read current value
  u16Data = I2scodec_Read(u16Register);
  // 2) Clear out old bits
  u16Data &= ~u16ClearMask;
  // 3) set new bit values u16Data = u16Data | u16SetValue;
  u16Data |= u16SetValue;
  // 4) Write out new value created
  I2scodec_Write(u16Register, u16Data);
}

*/

/**
 ******************************************************************************
 ** \brief Initialize the external I²S codeg SGTL5000 via I2C
 **
 ** \return   Ok   Coded initialized
 ******************************************************************************/
static uint8_t I2scodec_Init(void)
{
  /*
    volatile uint32_t u32Wait = 1000000ul;

    // "Reset" SGTL5000 (Needed for using INITX, because reconfiguration otherwise not possible)  
    I2scodec_Modify(CHIP_ADCDAC_CTRL, 0x0004u, 0x0004u); // Mute DAC left
    I2scodec_Modify(CHIP_ADCDAC_CTRL, 0x0008u, 0x0008u); // Mute DAC right
    I2scodec_Modify(CHIP_ANA_CTRL,    0x0010u, 0x0010u); // Mute HP out
    I2scodec_Modify(CHIP_ANA_CTRL,    0x0100u, 0x0100u); // Mute line out
    
    I2scodec_Modify(DAP_CONTROL,      0x00001, 0x0000u); // Disable DAP

    I2scodec_Modify(CHIP_CLK_CTRL,    0x0003u, 0x0000u); // Unuse PLL    
    
    I2scodec_Modify(CHIP_ANA_POWER,   0x0100u, 0x0000u); // Power down VCO-Amplifier
    I2scodec_Modify(CHIP_ANA_POWER,   0x0400u, 0x0000u); // Power down PLL

    I2scodec_Write(CHIP_DIG_POWER,    0x0000u);          // Power down digital: I2S_IN, I2S_OUT, DAP, DAC, ADC
    I2scodec_Write(CHIP_ANA_POWER,    0x0000u);          // Power down analog: LINEOUT, HP, ADC, DAC    
    
    while(u32Wait--)    // SGTL50000 needs some time to power down
    {}
  
    // (Re-) Configure SGTL5000
    // Chip powerup and supply configurations
    I2scodec_Write(CHIP_ANA_POWER,     0x4060u);        // VDDD external driven
    I2scodec_Write(CHIP_LINREG_CTRL,   0x006Cu);        // Both VDDA and VDDIO > 3.1 V
    I2scodec_Write(CHIP_REF_CTRL,      0x004Eu); 
    I2scodec_Write(CHIP_LINE_OUT_CTRL, 0x031Eu);        // LINEOUT reference voltage to VDDIO / 2 
    I2scodec_Write(CHIP_REF_CTRL,      0x01EFu);
    I2scodec_Write(CHIP_SHORT_CTRL,    0x1106u);        // Short headphone detect
    I2scodec_Write(CHIP_ANA_CTRL,      0x0133u);        // Enable zero-cross detect
    I2scodec_Write(CHIP_ANA_POWER,     0x60FFu);        // Power up analog: LINEOUT, HP, ADC, DAC
    I2scodec_Write(CHIP_DIG_POWER,     0x0073u);        // Power up digital: I2S_IN, I2S_OUT, DAP, DAC, ADC
    I2scodec_Write(CHIP_LINE_OUT_VOL,  0x0F0Fu);        // Set LINEOUT volume level
    
    // System MCLK and sample clock
    I2scodec_Modify(CHIP_CLK_CTRL,  0x000Cu, 0x0004u);   // 44.1 kHz
    I2scodec_Modify(CHIP_CLK_CTRL,  0x0030u, 0x0000u);   // SYS_FS = MCLK
    I2scodec_Modify(CHIP_I2S_CTRL,  0x0080u, 0x0080u);   // Bit 7: 0 = slave, 1 = master
    
    // PLL configuration
    I2scodec_Modify(CHIP_ANA_POWER,  0x0400u, 0x0400u);  // Power up PLL
    I2scodec_Modify(CHIP_ANA_POWER,  0x0100u, 0x0100u);  // Power up VCO-Amplifier
    
    I2scodec_Modify(CHIP_CLK_TOP_CTRL, 0x0008u, 0x0000u);  // MCLK < 17 MHz: Input freq div = 1 (1:1)
    I2scodec_Write(CHIP_PLL_CTRL, (((uint16_t)I2C_CODEC_PLL_INT_DIV_441 << 11u) | (0x07FFu & (uint16_t)I2C_CODEC_PLL_FRAC_DIV_441)));
    I2scodec_Modify(CHIP_CLK_CTRL,     0x0003u, 0x0003u);  // Use PLL

    
    // Input/output routing
    I2scodec_Modify(CHIP_SSS_CTRL,  0x0030u, 0x0010u);  // Route I2S_IN to DAC
    I2scodec_Modify(CHIP_ANA_CTRL,  0x0040u, 0x0000u);  // Route DAC to HP_OUT
    
    // Digital audio processor configuration
    I2scodec_Modify(DAP_CONTROL,    0x00001, 0x0001u);  // Enable DAP
    
    // I2S Audio format
    I2scodec_Modify(CHIP_I2S_CTRL,  0x0100u, 0x0100u);  // SCLKFREQ, 0 = 64Fs, 1 = 32Fs (not supported, if I2S_MODE == 1)
    I2scodec_Modify(CHIP_I2S_CTRL,  0x0040u, 0x0040u);  // SCLK_INV = 1
    I2scodec_Modify(CHIP_I2S_CTRL,  0x0030u, 0x0030u);  // DLEN = 1: 24 bits (not valid for right justified mode)
    I2scodec_Modify(CHIP_I2S_CTRL,  0x000Cu, 0x0008u);  // I2S_MODE = 2: PCM Format B
    I2scodec_Modify(CHIP_I2S_CTRL,  0x0002u, 0x0002u);  // LRALIGN = 1: Data with I2S_WS pulse
    I2scodec_Modify(CHIP_I2S_CTRL,  0x0001u, 0x0000u);  // LRPOL = 0: I2S_LRCLK = 0 (left), 1 (right)

    // Volume control
    I2scodec_Write(CHIP_ANA_HP_CTRL,  0x7F7Fu);          // Left, right full HP volume
    I2scodec_Modify(CHIP_ANA_CTRL,    0x0010u, 0x0000u); // Unmute HP out
    I2scodec_Modify(CHIP_ANA_CTRL,    0x0100u, 0x0000u); // Unmute line out
    I2scodec_Write(CHIP_DAC_VOL,      0x3C3Cu);          // DAC left/right 0 dB
    I2scodec_Modify(CHIP_ADCDAC_CTRL, 0x0004u, 0x0000u); // Unmute DAC left
    I2scodec_Modify(CHIP_ADCDAC_CTRL, 0x0008u, 0x0000u); // Unmute DAC right
    I2scodec_Write(CHIP_LINE_OUT_VOL, 0x0F0Fu);          // Line out left/right maximum
    */
    return 0u;
}

void i2s_init()
{
  int ret;
  ret = I2sClockInit();
  if (ret) neo_printf("I2sClockInit() error\r\n");
  ret = I2sInit();
  if (ret) neo_printf("I2sInit() error\r\n");
  ret = I2scodec_Init();
  if (ret) neo_printf("I2scodec_Init() error\r\n");
  I2sStart();
  /*
   if(0u == I2sClockInit()) {
    if(0u == I2sInit()) {
      if(0u == I2scodec_Init()) {
        I2sStart();
      }
    }
  } 
  */
}