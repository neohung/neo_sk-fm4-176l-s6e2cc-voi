#ifndef NEO_RTC_H
#define NEO_RTC_H

#include "mcu.h" 
#include "pdl_header.h" 

typedef enum en_day_of_week
{
  SUN,
  MON,
  TUE,
  WED,
  THU,
  FRI,
  SAT
} en_day_of_week_t;


typedef struct __RTC
{
 uint8_t u8Seconds;
 uint8_t u8Minutes;
 uint8_t u8Hours;
 en_day_of_week_t enDayOfWeek;
 uint8_t u8Days;
 uint8_t u8Months;
 uint16_t u16Years; 
}RTC;

RTC rtc;

void (*rtc_callback_func)(RTC getRtc);


void rtc_init(void);
void Rtc_ReadRtcTime(void);
void Rtc_SetManualTime(RTC r);
void register_rtc_callback(void (*func)(RTC r));
#endif