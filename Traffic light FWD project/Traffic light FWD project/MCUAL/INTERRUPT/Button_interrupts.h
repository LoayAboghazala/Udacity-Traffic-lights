
#ifndef BUTTON_INTERRUPTS_H_
#define BUTTON_INTERRUPTS_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../UTILITIES/macros.h"
#include "../../HCUAL/LED/led.h"

//initialization interrupt 0 function
uint8_t INTERRUPT_O_INIT (void);
// func when button is pressed
uint8_t INTERRUPTION (void);


#endif
