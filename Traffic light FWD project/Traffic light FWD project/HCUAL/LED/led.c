#include "led.h"
// global variable
uint8_t flag = 0;

// implementation of led initialization func. to set the led configurations
uint8_t LED_INIT (uint8_t port_num, uint8_t pin_num){

	// error handling for wrong arguments
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		printf("please enter correct port or pin numbers\n");
		// there is an error
		return ERROR ;
	}
	else
	{
		// calling the gpio init func. to set the led port and pin numbers, and the led to be output
		GPIO_INIT(port_num,pin_num,OUT);
		//every thing is ok
		return OK;
	}

}
// implentation of led on function to on the led
uint8_t LED_ON (uint8_t port_num, uint8_t pin_num){
	//error handling for wrong arguments
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		printf("please enter correct port or pin numbers\n");
		// there is an error
		return ERROR ;
	}
	else
	{

		// calling the gpio write func. to set the led port and pin numbers, and the led to be High "on"
		GPIO_WRITE(port_num,pin_num,HIGH);
		//every thing is ok
		return OK;
	}
}


// implentation of led off function to off the led
uint8_t LED_OFF (uint8_t port_num, uint8_t pin_num){
	// error handling for wrong arguments
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		printf("please enter correct port or pin numbers\n");
		// there is an error
		return ERROR ;
	}
	else
	{

		// calling the gpio write func. to set the led port and pin numbers, and the led to be low "off"
		GPIO_WRITE(port_num,pin_num,LOW);
		//every thing is ok
		return OK;
	}
}
// implentation of led toggle func. to make the led blink
uint8_t LED_TOGGLE (uint8_t port_num, uint8_t pin_num){
	// error handling for wrong arguments
	if((pin_num >= NUM_OF_PINS_PER_PORT) || (port_num >= NUM_OF_PORTS))
	{
		printf("please enter correct port or pin numbers\n");
		// there is an error
		return ERROR ;
	}
	else
	{
		// calling the gpio toggle func. to set the led port and pin numbers,and the led to be output
		GPIO_TOGGLE(port_num,pin_num);
		//every thing is ok
		return OK;
	}
}

uint8_t YELLOW_BLINKING (uint64_t delay){
	flag = 1;
	// error handling for negative values
	if((delay < 0)){

		printf("please enter positive number");
		//there is an error
		return ERROR;
	}
	else{

		for(int l = 0; l< 10; l++){

			LED_ON (PORT_A, PIN_1); // yellow car led
			LED_ON (PORT_B, PIN_1); // yellow pedestrian led
			Timer2_delay_ms(delay/5);
			//  both Yellow leds are off
			LED_OFF (PORT_A, PIN_1); // yellow car led
			LED_OFF (PORT_B, PIN_1); // yellow pedestrian led
			Timer2_delay_ms(delay/5);	

		}
		//every thing is ok
		return OK;
	}
	flag = 0 ;
}
