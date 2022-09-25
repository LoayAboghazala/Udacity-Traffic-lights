#include "button.h"

// implementation of button initialization func. to set the button configurations
uint8_t BUTTON_INIT(uint8_t port_num, uint8_t pin_num){
	// error handling for wrong arguments
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		printf("please enter correct port or pin numbers\n");
		// there is an error
		return ERROR ;
	}
	else
	{
		// calling the gpio init func. to set the button port and pin numbers, and the button to be input
		GPIO_INIT(port_num,pin_num,IN);
		//every thing is ok
		return OK;
	}
}
// implementation of button read func. to know the state of the button
uint8_t BUTTON_READ (uint8_t port_num, uint8_t pin_num, uint8_t * value){
	// error handling for wrong arguments
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		printf("please enter correct port or pin numbers and address only\n");
		// there is an error
		return ERROR;
	}
	else
	{
		// calling the gpio read function to know the state of the pin that the button is connected to
		GPIO_READ(port_num,pin_num,value);
		//every thing is ok
		return OK;
	}
}
