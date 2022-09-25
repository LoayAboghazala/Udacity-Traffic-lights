#ifndef LED_H_
#define LED_H_
#include "../../MCUAL/GPIO/gpio.h"

//led initialization func. to set the led configurations
uint8_t LED_INIT (uint8_t port_num, uint8_t pin_num);
//led on function to on the led
uint8_t LED_ON (uint8_t port_num, uint8_t pin_num);
// led off function to off the led
uint8_t LED_OFF (uint8_t port_num, uint8_t pin_num);
//led toggle func. to make the led blink
uint8_t LED_TOGGLE (uint8_t port_num, uint8_t pin_num);

//uint8_t YELLOW_BLINKING (uint64_t DELAY);
uint8_t YELLOW_BLINKING ();


#endif
