#include "neo_pwm_rgbled.h"

#define DELAY_US            19.607f
#define PCSR_VAL            ((DELAY_US * (160000000ul / 1000000ul)) - 1u)

uint8_t u8Counter = 0u; 
uint8_t au8DutyCycle[3] = {0u, 0u, 0u};  //R,G,B

static void rgbled_gpio_init(void)
{
  bFM4_GPIO_ADE_AN08 = 0;     // AN08 to GPIO (bit 08 set to zero) 
  bFM4_GPIO_ADE_AN10 = 0;     // AN10 to GPIO (bit 10 set to zero) 
  bFM4_GPIO_ADE_AN18 = 0;     // AN18 to GPIO (bit 10 set to zero) 
  FM4_GPIO->PDOR1_f.P8 = 1u;   // P18 preset output: high (BLUE LED off)
  FM4_GPIO->PDOR1_f.PA = 1u;   // P1A preset output: high (RED LED off)
  FM4_GPIO->PDORB_f.P2 = 1u;   // PB2 preset output: high (RED LED off)
  FM4_GPIO->DDR1_f.P8 = 1u;    // P18 direction to output
  FM4_GPIO->DDR1_f.PA = 1u;    // P1A direction to output
  FM4_GPIO->DDRB_f.P2 = 1u;    // PB2 direction to output
}

/**
 ******************************************************************************
 ** \brief  Initializes Base Timer ch. 0 in Reload Timer mode 
 **
 ******************************************************************************/
static void InitBT0(void)
{  
  FM_BTIOSEL03->BTSEL0123 = 0x00u;                          // I/O mode 0  
  FM_BT0_RT->TMCR = 0x0032u;                                // Timer Control Register 
  FM_BT0_RT->TMCR2 = 0x00u;                                  
  FM_BT0_RT->PCSR =  PCSR_VAL;                              // Cycle Set Register (PCSR)   
  // This value of PCSR generates a delay of 19.607 us. Each LED has 255 steps in the duty cycle so 19.6 us * 255, 
  // generates a delay of 5 ms. Which in turn produces a PWM signal with frequency 200 Hz   
  FM_BT0_RT->STC = 0x00u;
  FM_BT0_RT->STC_f.UDIE = 1u;                               // Enable under flow interrupt
  // Setting up interrupt and its priority
  NVIC_SetPriority(BT0_IRQn, 1u);           			
  NVIC_ClearPendingIRQ(BT0_IRQn);           								
  NVIC_EnableIRQ(BT0_IRQn);  
  FM_BT0_RT->TMCR_f.STRG = 1u;                              // Start the timer
}

void rgb_led_init(void)
{
  rgbled_gpio_init();
  InitBT0();
}

void rgb_led_set(uint8_t r,uint8_t g, uint8_t b)
{
    au8DutyCycle[0] = r;
    au8DutyCycle[1] = g;
    au8DutyCycle[2] = b;
}

void BT0_IRQHandler(void)
{ 
  FM_BT0_RT->STC_f.UDIR = 0u;                             // Clear the interrupt flag
  // An inverted PWM signal is produced due to the LED configuration.
  // Writing a 0 on the port turns the LED off and vice versa.  
  if(u8Counter < au8DutyCycle[0u])                        // Check if the interrupt counter has reached the duty cycle value
  {
    FM4_GPIO->PDOR1_f.PA = 0u;
  }
  else
  {
    FM4_GPIO->PDOR1_f.PA = 1u;
  }
  
  if(u8Counter < au8DutyCycle[1u])                        // Check if the interrupt counter has reached the duty cycle value
  {
      FM4_GPIO->PDORB_f.P2 = 0u;
  }
  else
  {
      FM4_GPIO->PDORB_f.P2 = 1u;
  }
  
  if(u8Counter < au8DutyCycle[2u])                        // Check if the interrupt counter has reached the duty cycle value
  {
    FM4_GPIO->PDOR1_f.P8 = 0u;
  }
  else
  {
    FM4_GPIO->PDOR1_f.P8 = 1u;
  }
  u8Counter++;                                            // Increment the interrupt counter variable
  // The size of this variable is 8 bits. Therefore, it automatically wraps to 0 after 255
}
