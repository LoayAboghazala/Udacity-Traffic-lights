
//include driver files
#include "gpio.h"
// include avr library
#include <avr/io.h>

//implementation for gpio_init func. to set the direction of pin to Output or input
uint8_t GPIO_INIT(uint8_t port_num, uint8_t pin_num, uint8_t dir){
	// error handling for wrong arguments
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS)||(dir > OUT))
	{
		printf("please enter correct port or pin numbers and OUT or IN directions only\n");
		// there is an error
		return ERROR ;
	}
	else
	{
		// cases for all ports and different directions
		switch(port_num){
		// for port A
		case PORT_A:
			// checking if the pin is set to input
			if(dir == IN){
				// clearing the bit to be = 0
				CLEAR_BIT(DDRA,pin_num);
			}
			// checking if the pin is set to output
			else if (dir == OUT){
				// setting the bit to be = 1
				SET_BIT(DDRA,pin_num);
			}
			break;
			// for port B
		case PORT_B:
			// checking if the pin is set to input
			if(dir == IN){
				// clearing the bit to be = 0
				CLEAR_BIT(DDRB,pin_num);
			}
			// checking if the pin is set to output
			else if (dir == OUT){
				// setting the bit to be = 1
				SET_BIT(DDRB,pin_num);
			}

			break;
			// for port D
		case PORT_D:
			// checking if the pin is set to input
			if(dir == IN){
				// clearing the bit to be = 0
				CLEAR_BIT(DDRD,pin_num);
			}
			// checking if the pin is set to output
			else if (dir == OUT){
				// setting the bit to be = 1
				SET_BIT(DDRD,pin_num);
			}
			break;
		}
		//every thing is ok
		return OK;
	}
}
//implementation for gpio_toggle func. to set the value of the pin to High or Low
uint8_t GPIO_TOGGLE(uint8_t port_num, uint8_t pin_num){
	// error handling for wrong arguments
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		printf("please enter correct port or pin numbers\n");
		// there is an error
		return ERROR;
	}
	else
	{
		// cases for all ports and different values for the pin
		switch (port_num){
		// for port A
		case PORT_A:
			// toggling the bit to high and low "blinking"
			TOGGLE_BIT(PORTA,pin_num);
			break;
			// for port B
		case PORT_B:
			// toggling the bit to high and low "blinking"
			TOGGLE_BIT(PORTB,pin_num);
			break;

			// for port D
		case PORT_D:
			// toggling the bit to high and low "blinking"
			TOGGLE_BIT(PORTD,pin_num);
			break;
		}
		// every thing is ok
		return OK ;
	}
}
// implentation for gpio_write func. to set the value of the pin to High or Low
uint8_t GPIO_WRITE(uint8_t port_num, uint8_t pin_num, uint8_t value){
	// error handling for wrong arguments
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS)||(value > HIGH))
	{
		printf("please enter correct port or pin numbers and HIGH or LOW values only \n");
		// there is an error
		return ERROR;
	}
	else
	{
		// cases for all ports and different values of the pin
		switch(port_num){
		// for port A
		case PORT_A:
			// checking the pin state if set to low
			if(value == LOW){
				// clearing the bit to be = 0
				CLEAR_BIT(PORTA,pin_num);
			}
			// checking the pin state if set to high
			else if (value == HIGH){
				// setting the bit to be = 1
				SET_BIT(PORTA,pin_num);
			}
			break;
			// for port B
		case PORT_B:
			// checking the pin state if set to low
			if(value == LOW){
				// clearing the bit to be = 0
				CLEAR_BIT(PORTB,pin_num);
			}
			// checking the pin state if set to high
			else if (value == HIGH){
				// setting the bit to be = 1
				SET_BIT(PORTB,pin_num);
			}

			break;
			// for port D
		case PORT_D:
			// checking the pin state if set to low
			if(value == LOW){
				// clearing the bit to be = 0
				CLEAR_BIT(PORTD,pin_num);
			}
			// checking the pin state if set to high
			else if (value == HIGH){
				// setting the bit to be = 1
				SET_BIT(PORTD,pin_num);
			}
			break;
		}
		// every thing is ok
		return OK ;
	}
}
// implementation for gpio_read func. to know the state of the pin
uint8_t GPIO_READ (uint8_t port_num, uint8_t pin_num, uint8_t * value){
	// error handling for wrong arguments
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		printf("please enter correct port or pin numbers and address only\n");
		// there is an error
		return ERROR;
	}
	else
	{
		// cases for reading all ports
		switch(port_num){
		// for port A
		case PORT_A:
			*value = READ_BIT(PINA,pin_num);
			break;
			// for port B
		case PORT_B:
			*value = READ_BIT(PINB,pin_num);
			break;
			// for port D
		case PORT_D:
			*value = READ_BIT(PIND,pin_num);
			break;
		}
		// Every thing is ok
		return OK;
	}
}
