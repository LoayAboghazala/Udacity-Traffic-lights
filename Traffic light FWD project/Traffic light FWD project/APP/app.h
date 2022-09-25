#ifndef APP_H
#define APP_H
#include "../HCUAL/BUTTON/button.h"
#include "../HCUAL/LED/led.h"
#include "../MCUAL/INTERRUPT/Button_interrupts.h"
#include "../MCUAL/TIMER/timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>


uint8_t APP_INITILIZATION(void);

uint8_t RUN_APP(void);




#endif
