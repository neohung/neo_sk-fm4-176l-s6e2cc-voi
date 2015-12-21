#ifndef NEO_PWM_RGBLED_H
#define NEO_PWM_RGBLED_H

#include "mcu.h" 
#include "pdl_header.h" 

void rgb_led_init(void);
void rgb_led_set(uint8_t r,uint8_t g, uint8_t b);

#endif