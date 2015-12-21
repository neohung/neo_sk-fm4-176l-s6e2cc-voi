#include "mcu.h" 
#include "pdl_header.h" 
#include <string.h> 

#include "FreeRTOS.h"
#include "task.h"
#include "mfs\mfs.h"
#include "uart_io.h"

#include "neo_rtc.h"
#include "neo_pwm_rgbled.h"

static void mainTask( void *pvParameters );
static void RtcTask( void *pvParameters );
static void rgbledTask(void *pvParameters);
static char szUartTxBuf[] = "\r\nWelcome sk-fm4-176l-s6e2cc-voi\n\r"; 

static char end[] = "Finish\n\r"; 

extern int neo_printf(const char* format, ...);

int main(void) 
{ 
  //uart_init();
  Uart_Io_Init();
  neo_printf("%s",szUartTxBuf);
  NVIC_SetPriorityGrouping( 0 );
 
  
  xTaskCreate(mainTask,                       // The function that implements the task.
                "main_task",                             // The text name assigned to the task - for debug only as it is not used by the kernel.
                128,               // The size of the stack to allocate to the task.
                NULL,                                   // The parameter passed to the task
                tskIDLE_PRIORITY + 1,                   // The priority assigned to the task.
                NULL );        
     
  neo_printf("%s",end);
  vTaskStartScheduler();
  return 0;

} 

#define I2C_RW_WRITE          (0u)

#define I2C_TIME_OUT          (5000u)    // error counter time-out

#define I2C_STOP_TIMEOUT      (0xFFFFu)  // time-out for stop condition

/*****************************************************************************
 ** \brief    The following function checks if a slave device holds the SDA
 **           line low before initializing I2C. This can happen if a read
 **           operation from a slave was interrupted, eg. due to MCU reset.
 **           In case some slave device is holding the bus low, up to nine
 **           clock pulses are generated until the line is released.
 **
 ** \param    [in] pu32DDR pointer to DDR register of I/O port to which SCL & SDA are configured
 ** \param    [in] pu32PFR pointer to PFR register of I/O port to which SCL & SDA are configured
 ** \param    [in] pu32PDOR pointer to PDOR register of I/O port to which SCL & SDA are configured
 ** \param    [in] pu32PDIR pointer to PDIR register of I/O port to which SCL & SDA are configured
 ** \param    [in] u32SclMask Mask bit corresponding to the SCL line
 ** \param    [in] u32SdaMask Mask bit corresponding to the SDA line
 *****************************************************************************/
void I2cBusClear(volatile uint32_t* pu32DDR, volatile uint32_t* pu32PFR, volatile uint32_t* pu32PDOR, volatile uint32_t* pu32PDIR, uint32_t u32SclMask, uint32_t u32SdaMask)
{
  volatile uint32_t u32Dly;
  uint8_t u8I;

  *pu32DDR  &= ~(u32SclMask | u32SdaMask);                   // input (to read bus state)
  *pu32PDOR &= ~(u32SclMask | u32SdaMask);                  // PF low
  *pu32PFR  &= ~(u32SclMask | u32SdaMask);                   // Disable MFS peripheral output

  if (0u == (*pu32PDIR & u32SdaMask))                       // If someone holds SDA low, generate some dummy clock pulses until line is released
  {
    *pu32DDR |= u32SclMask;                                 // set SCL to output
    for (u8I = 0u; u8I < 9u; u8I++)
    {
      u32Dly = 0xFFFFul;
      while (--u32Dly)
      {}
      *pu32PDOR |= u32SclMask;                              // PF2 --> high (SCL)
      
      u32Dly = 0xFFFFul;
      while (--u32Dly)
      {}
          
      *pu32PDOR &= ~u32SclMask;                             // PF2 --> low (SCL)
      if (*pu32PDIR & u32SdaMask)
      {
          break;                                            // stop if SDA was released meanwhile
      }
    }
  }
  u32Dly = 0xFFFFul;
  while (--u32Dly)
  {}
      
  *pu32PDOR |= (u32SclMask | u32SdaMask);                   // SDA + SCL high
  *pu32DDR  |= (u32SclMask | u32SdaMask);
  
  u32Dly = 0xFFFFul;
  while (--u32Dly)
  {}

  // MFS I2C has to be re-initialized after this!
}

#define i2cmfs FM4_MFS8

boolean_t I2c_Init(void)
{
   I2cBusClear(&FM4_GPIO->DDRB,
               &FM4_GPIO->PFRB,
               &FM4_GPIO->PDORB,
               &FM4_GPIO->PDIRB,
               (1ul << 0x6ul),
               (1ul << 0x5ul));
                                                                        
   bFM4_GPIO_PFRB_P5 = 1u;                                  // Pin 113 (SOT8_1)
   bFM4_GPIO_PFRB_P6 = 1u;                                  // Pin 114 (SCK8_1)

   FM4_GPIO->EPFR16 &= ~(0x3ul << 4ul);                    // SIN14S
   FM4_GPIO->EPFR16 &= ~(0x3ul << 6ul);                    // SOT14B
   FM4_GPIO->EPFR16 &= ~(0x3ul << 8ul);                    // SCK14B

   FM4_GPIO->EPFR16 |= (0x2ul << 6ul);                     // SOT14B
   FM4_GPIO->EPFR16 |= (0x2ul << 8ul);                     // SCK14B
  

   //BAUDRATE = 400,000 ; 400KHz
   i2cmfs->BGR  = (__HCLK / 2ul) / 400000ul - 1ul;       // BGR = PCLK / BAUDRATE - 1
    
   i2cmfs->SCR |= 0x80u;                                 // Reset (UPCL = 1)
   i2cmfs->SMR  = 0x80u;                                 // operation mode 4, no interrupts, no test
                                                            // mode, no wake up

   i2cmfs->ISBA = 0x00u;

   i2cmfs->NFCR |= 0x0008u;                              // Enable noise filter for I2C ch. 1 for 60-80MHz PCLK operation

   i2cmfs->ISMK = 0x80u;                                 // Enable I2C interface
   
   return TRUE;
}

/*****************************************************************************
 ** \brief    Send I2C Byte
 **
 ** \param    [in] u8Data Data
 **
 ** \return   int32_t 0 = 0k / -1 = Error
 *****************************************************************************/
int32_t I2cSendByte(uint8_t u8Data)
{
  volatile uint32_t u32Timeout;

  i2cmfs->TDR = u8Data;                                  // Send data to TSC
  i2cmfs->IBCR = 0xB0u;                                  // WSEL = 1, ACKE = 1, Clear INT flag

  u32Timeout = I2C_TIME_OUT;
  while(!(i2cmfs->IBCR & 0x01u))                         // Wait for transmission complete
  {                                                         // via INT flag
      u32Timeout--;
      if (0u == u32Timeout)
      {
         neo_printf("Error Timeout \r\n");
   
          return -1;
      }
  }

  if (i2cmfs->IBCR & 0x02u)                              // BER == 1? ->  error
  {
     neo_printf("Error BER == 1 \r\n");
   
    return -1;
  }

  if (!(i2cmfs->IBCR & 0x40u))                           // ACT == 0? ->  error
  {
     neo_printf("Error ACT == 0 \r\n");
   
    return -1;
  }

  // MSS is set, no reserved address

  if (i2cmfs->IBSR & 0x40u)                              // RACK == 1? ->  error
  {
    neo_printf("Error RACK == 1 \r\n");
    return -1;
  }

  if (!(i2cmfs->IBSR & 0x10u))                           // TRX == 0? ->  error
  {
     neo_printf("Error TRX == 0 \r\n");
   
    return -1;
  }

  return 0u;
}

static void i2cTask( void *pvParameters )
{
   neo_printf("i2cTask task started test\r\n");
   I2c_Init();
   int ret = 0;
   ret = I2cSendByte(0x0e);
   neo_printf("ret=%d\r\n",ret);
   while(1){
      vTaskDelay(1000/portTICK_RATE_MS);
   };
   vTaskDelete(NULL); 
}

static void mainTask( void *pvParameters )
{
  
  
    neo_printf("Main task started test\r\n");
    /*
     xTaskCreate(RtcTask,                       // The function that implements the task.
                "rtc_task",                             // The text name assigned to the task - for debug only as it is not used by the kernel.
                128,               // The size of the stack to allocate to the task.
                NULL,                                   // The parameter passed to the task
                tskIDLE_PRIORITY + 1,                   // The priority assigned to the task.
                NULL );      
         
     */
       xTaskCreate(rgbledTask,                       // The function that implements the task.
                "rgbled_task",                             // The text name assigned to the task - for debug only as it is not used by the kernel.
                128,               // The size of the stack to allocate to the task.
                NULL,                                   // The parameter passed to the task
                tskIDLE_PRIORITY + 1,                   // The priority assigned to the task.
                NULL );      

  
         xTaskCreate(i2cTask,                       // The function that implements the task.
                "i2c_task",                             // The text name assigned to the task - for debug only as it is not used by the kernel.
                128,               // The size of the stack to allocate to the task.
                NULL,                                   // The parameter passed to the task
                tskIDLE_PRIORITY + 1,                   // The priority assigned to the task.
                NULL );      

  
   vTaskDelete(NULL);

}
  

void rtc_update(RTC rtc)
{
  char_t acDaysOfWeek[7u][4u] = {
            "SUN\0",
            "MON\0",
            "TUE\0",
            "WED\0",
            "THU\0",
            "FRI\0",
            "SAT\0"
  };
  neo_printf("\f%d:%d:%d, %s, %d-%d-%d\r\n", rtc.u8Hours, rtc.u8Minutes, rtc.u8Seconds, acDaysOfWeek[rtc.enDayOfWeek], rtc.u8Days, rtc.u8Months + 1, rtc.u16Years);
}
static void RtcTask( void *pvParameters )
{  
    rtc_init(); //Enable interrupt, will call  RTC_IRQHandler()
    neo_printf("Current RTC Status : %s\r\n", FM4_RTC->WTCR10_f.RUN ? "Enabled" : "Disabled");
    register_rtc_callback(rtc_update);
    const char* t = __TIME__;
    neo_printf("%s\r\n",t);
    const char s[2] = {t[6],t[7]};
    const char m[2] = {t[3],t[4]};
    const char h[2] = {t[0],t[1]};
    const char* d = __DATE__;
    const char y[4] = {d[7],d[8],d[9],d[10]};
    const char day[2] = {d[4],d[5]};
    neo_printf("%s\r\n",d);
    RTC r = {
      atoi(s), atoi(m), 1,0,atoi(day),0,2015
    };
    neo_printf("s[%d]\r\n",r.u8Seconds);
    neo_printf("m[%d]\r\n",r.u8Minutes);
    neo_printf("h[%d]\r\n",r.u8Hours);
    neo_printf("d[%d]\r\n",r.u8Days);
    neo_printf("y[%d]\r\n",r.u16Years);
    Rtc_SetManualTime(r);
    while(1){
      //Rtc_ReadRtcTime();
      //neo_printf("[%d:%d:%d]\r\n",u8Hours,u8Minutes,u8Seconds);
      vTaskDelay (1000/portTICK_RATE_MS);
   };   
}

static void rgbledTask(void *pvParameters)
{
  neo_printf("rgbledTask started test\r\n");
  rgb_led_init();
  rgb_led_set(5,5,5);
  while(1){
    vTaskDelay (100/portTICK_RATE_MS);
  };  
 
}
