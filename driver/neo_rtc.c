#include "neo_rtc.h"

static void Vbat_WaitTransferComplete(void)
{
  while(0u != FM4_RTC->WTCR10_f.TRANS);
}

static void Clk_InitSubClock(void)
{
    // Sub Clock initialisation method.
    // Refer to system_mb9bf56xr.c for details
    
    FM4_RTC->VDET = 0x00u;
    FM4_RTC->VBPFR = 0x1Cu;
    FM4_RTC->CCB = 0x10u;
    FM4_RTC->CCS = 0x08u;

    FM4_RTC->VB_CLKDIV = 0x4Eu;
    FM4_RTC->BOOST = 0x03u;

    FM4_RTC->WTOSCCNT_f.SOSCEX  = 0u;
    FM4_RTC->WTOSCCNT_f.SOSCNTL = 1u;

    FM4_RTC->WTCR20_f.PWRITE = 1u;

    Vbat_WaitTransferComplete();

    FM4_CRG->SCM_CTL |= (1ul << 3u);                
    while (!(FM4_CRG->SCM_STR & (1ul << 3u)));     
}

static void Rtc_EnableDisableRtc(boolean_t bEnable)
{
  if(TRUE == bEnable)
  {
    if(1u == FM4_RTC->WTCR10_f.RUN)             // Check if RTC is already enabled                                 
    {
      return;
    }
    else
    {
      FM4_RTC->WTCR10_f.ST = 1u;                // Start the RTC count block
      FM4_RTC->WTCR20_f.CWRITE = 1u;            // Start to save buffer from the Always ON Domain to the VBAT Domain 
      Vbat_WaitTransferComplete();              // Wait for TRANS bit to become 0
    }
  }
  else
  {
    if(0u == FM4_RTC->WTCR10_f.RUN)             // Check if the RTC is already disabled
    {
      return;
    }
    else
    {
      FM4_RTC->WTCR10_f.ST = 0u;                // Stop the RTC count block           
      FM4_RTC->WTCR20_f.CWRITE = 1u;            // Start to save buffer from the Always ON Domain to the VBAT Domain 
      Vbat_WaitTransferComplete();              // Wait for TRANS bit to become 0
    }
  }
}

static void Rtc_EnableSubSecondInterrupt(void)
{
  FM4_RTC->WTCR12 = 0x00;                                   // Clear all previous interrupt flags
  FM4_RTC->WTCR13_f.INTSSIE = 1u;                           // Enable sub second interrupt  

  // Interrupt enable and priority setup
  NVIC_SetPriority(RTC_IRQn, 1u);           			
  NVIC_ClearPendingIRQ(RTC_IRQn);           								
  NVIC_EnableIRQ(RTC_IRQn);
  
}

/**
 ******************************************************************************
 ** \brief  Dec2Hex function
 ** \param [in] uint8_t     Decimal value to be converted
 ** \return uint8_t         BCD Value. Upper 4 bits contain the second digit
 **                         Lower 4 bits contain the first digit
 ******************************************************************************/
static uint8_t Dec2Hex(uint8_t u8Dec)
{
  uint8_t u8Hex;
  uint8_t u8FirstDigit;
  uint8_t u8SecondDigit;
  
  u8FirstDigit = u8Dec % 10u;
  u8SecondDigit = (u8Dec - u8FirstDigit) / 10u;
  
  u8Hex = (u8SecondDigit << 4u) | u8FirstDigit;
  return u8Hex;
}

/**
 ******************************************************************************
 ** \brief  Hex2Dec function
 ** \param [in] uint8_t     BCD Hex value to be converted. Upper 4 bits contain the second digit
 **                         Lower 4 bits contain the first digit
 ** \return uint8_t         Decimal value
 ******************************************************************************/
static uint8_t Hex2Dec(uint8_t u8Hex)
{
  uint8_t u8Dec;
  uint8_t u8FirstDigit;
  uint8_t u8SecondDigit;
  
  u8FirstDigit = u8Hex & 0x0Fu;
  u8SecondDigit = (u8Hex >> 4u) & 0x0Fu;
  
  u8Dec = (u8SecondDigit * 10u) + u8FirstDigit;
  
  return u8Dec;
}


static void Rtc_UpdateTime(void)
{
  
  //  There are different methods to update time in the RTC depending on whether the RTC is already running or stopped.
  //  Refer to the RTC programming manual for the method description
  
  Vbat_WaitTransferComplete();                                                    // Wait for TRANS bit to become 0
  
  if(0u == FM4_RTC->WTCR10_f.RUN)                                                 // Check if RTC is already running
  {
    FM4_RTC->WTCR10_f.ST = 1u;                                                    // Start the RTC count block
      
    FM4_RTC->WTCR20_f.CWRITE = 1u;                                                // Start to save buffer from the Always ON Domain to the VBAT Domain 
    Vbat_WaitTransferComplete();                                                  // Wait for TRANS bit to become 0
  }
  else
  {
    while((1u == FM4_RTC->WTCR10_f.BUSY) && (0u == FM4_RTC->WTCR10_f.SCST));      // Wait until BUSY flag is 0, while SCST flag is 0
    FM4_RTC->WTCR12_f.INTSI = 0u;                                                 // Clear 1 second interrupt flag
    FM4_RTC->WTCR13_f.INTSIE = 1u;                                                // Enable 1 second interrupt
    while(0u == FM4_RTC->WTCR12_f.INTSI);                                         // Wait for 1 second interrupt 
    FM4_RTC->WTCR12_f.INTSI = 0u;                                                 // Clear 1 second interrupt flag
    FM4_RTC->WTCR10_f.SCST = 1u;                                                  // Clear SCST flag
    while(0u == FM4_RTC->WTCR10_f.BUSY);                                          // Wait until BUSY flag becomes 1

    FM4_RTC->WTCR20_f.CWRITE = 1u;                                                // Start to save buffer from the Always ON Domain to the VBAT Domain
    Vbat_WaitTransferComplete();                                                  // Wait for TRANS bit to become 0
    FM4_RTC->WTCR10_f.SCST = 0u;                                                  // Clear SCST flag
    while(1u == FM4_RTC->WTCR10_f.BUSY);                                          // Wait until BUSY flag becomes 0
  }
}

void Rtc_SetManualTime(RTC r)
{
  
  //   All the internal RTC time registers store values in BCD format. So before the value is written,
  //   is has to be converted to the right format. Dec2Hex function converts values from Dec to Hex(BCD)  
  
  FM4_RTC->WTSR =  Dec2Hex(r.u8Seconds);                    // Update the seconds register
  FM4_RTC->WTMIR =  Dec2Hex(r.u8Minutes);                   // Update the minutes register
  FM4_RTC->WTHR =  Dec2Hex(r.u8Hours);                    // Update the hours register
  FM4_RTC->WTDW =  r.enDayOfWeek;                              // Update the day of week register
  FM4_RTC->WTDR =  Dec2Hex(r.u8Days);                    // Update the day of month register
  FM4_RTC->WTMOR =  Dec2Hex(r.u8Months - 1u);            // Update the month register
  FM4_RTC->WTYR =  Dec2Hex(r.u16Years - 2000u);     // Update the year register  
    
  Rtc_UpdateTime();                                                                // Update the time in RTC

}


void Rtc_ReadRtcTime(void)
{
  Vbat_WaitTransferComplete();
  
  FM4_RTC->WTCR20_f.CREAD = 1u;                 // Start to recall register value from the Always ON Domain to the VBAT Domain
  Vbat_WaitTransferComplete();                  // Wait for TRANS bit to become 0
  FM4_RTC->WTCR12_f.INTCRI = 0u;                // Clear the read interrupt flag
  
  // All the internal RTC time registers store values in BCD format. So after the value is read, it
  // is has to be converted to the right format. Hex2Dec function converts values from Hex(BCD) to Dec
  
  rtc.u8Seconds = Hex2Dec(FM4_RTC->WTSR);
  rtc.u8Minutes = Hex2Dec(FM4_RTC->WTMIR);
  rtc.u8Hours = Hex2Dec(FM4_RTC->WTHR);
  rtc.enDayOfWeek = (en_day_of_week_t)FM4_RTC->WTDW;
  rtc.u8Days = Hex2Dec(FM4_RTC->WTDR);
  rtc.u8Months = Hex2Dec(FM4_RTC->WTMOR);
  rtc.u16Years = Hex2Dec(FM4_RTC->WTYR) + 2000u;  
}

void register_rtc_callback(void (*func)(RTC r))
{ 
  if (func) rtc_callback_func = func;
}
void rtc_init(void)
{
  rtc_callback_func = NULL;
  Clk_InitSubClock();
  Rtc_EnableSubSecondInterrupt(); //Enable interrupt, will call  RTC_IRQHandler()
  Rtc_EnableDisableRtc(TRUE);   
}

void RTC_IRQHandler(void)
{ 
  if(1u == FM4_RTC->WTCR12_f.INTSSI)
  {
    FM4_RTC->WTCR12_f.INTSSI = 0u;                            // Clear interrupt flag
      if(1u == FM4_RTC->WTCR12_f.INTSI)                       // Check if Second interrupt flag is set
      {
        Rtc_ReadRtcTime();
        if (rtc_callback_func) rtc_callback_func(rtc);
        //neo_printf("\f%d:%d:%d, %s, %d-%d-%d\r\n", u8Hours, u8Minutes, u8Seconds, acDaysOfWeek[enDayOfWeek], u8Days, u8Months + 1, u16Years);
      }             
    FM4_RTC->WTCR12_f.INTSI = 0u;                             // Clear second interrupt flag
  }  
}