#ifndef TIMER_H
# define TIMER_H
//including lower layers
#include "../GPIO/gpio.h"

#define NO_OF_OVERFLOWS 20
/*void ALL_TIMERS_CONFIG (uint8_t REG ,uint8_t BIT_1,uint8_t BIT_2);(to make a driver for all AVR timers in the near future)*/

// function to initialize timer 2 configuration or mode
uint8_t TIMER_2_CONFIG_NORMAL_MODE (void);
// function to set the initial value of timer 2
uint8_t TIMER_2_START_VALUE_5SECS(void);
// function to start the timer 2 counting
uint8_t TIMER_2_START(void);
//  function to delay 5 secs using timer 2,using polling
uint8_t TIMER_2_DELAY_5SECS (void);
// function to get the timer value at this time
uint8_t GET_TIMER_2_VALUE(uint64_t TOTAL_OVERFLOWS);
//  function to delay any time using timer 2,using polling
uint8_t Timer2_delay_ms(float64_t Time);





#endif
