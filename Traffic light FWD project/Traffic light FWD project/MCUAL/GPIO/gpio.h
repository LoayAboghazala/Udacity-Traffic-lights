#ifndef GPIO_H
#define GPIO_H



// include avr library
#include <avr/io.h>
// including utilities
#include "../../UTILITIES/typedef.h"
#include "../../UTILITIES/macros.h"

// GPIO functions prototype
// set pin direction
uint8_t GPIO_INIT(uint8_t portNum, uint8_t pinNum, uint8_t dir);
// set pin value
uint8_t GPIO_WRITE(uint8_t portNum, uint8_t pinNum, uint8_t value);
//get pin value
uint8_t GPIO_READ (uint8_t port_num, uint8_t pin_num, uint8_t * value);
// toggle the pin value
uint8_t GPIO_TOGGLE(uint8_t port_num, uint8_t pin_num);



#endif
