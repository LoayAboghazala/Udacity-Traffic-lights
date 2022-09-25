#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCUAL/GPIO/gpio.h"

//button initialization func. to set the button configurations
uint8_t BUTTON_INIT (uint8_t port_num, uint8_t pin_num);
//button read func. to know the state of the button
uint8_t BUTTON_READ (uint8_t port_num, uint8_t pin_num, uint8_t * value);


#endif
