


#include "app.h"
extern uint8_t INTERRUPTION_FLAG ;
extern uint8_t flag ;

uint8_t APP_INITILIZATION(void)
{
	// Initializing Cars LEDS        
	// Calling led init functions to set the port and pin numbers of the leds and set the direction output
	// green car led
	LED_INIT (PORT_A, PIN_0);
	// yellow car led
	LED_INIT (PORT_A, PIN_1);
	// red car led
	LED_INIT (PORT_A, PIN_2);

	//  Initializing Pedestrian LEDS  
	// Calling led init functions to set the port and pin numbers of the leds and set the direction output
	// green pedestrian led
	LED_INIT (PORT_B, PIN_0);
	// yellow pedestrian led
	LED_INIT (PORT_B, PIN_1);
	// red pedestrian led
	LED_INIT (PORT_B, PIN_2);

	// Initializing the Push Button for Pedestrian 
	// Calling button init functions to set the port and pin numbers of the button and set the direction input
	BUTTON_Init(PORT_D,PIN_2);

	// Initializing the timer 
	//to initialize timer 2 configuration or mode "NORMAL MODE"
	TIMER_2_CONFIG_NORMAL_MODE ();
	//to start the timer 2 counting
	TIMER_2_START_VALUE_5SECS();
	TIMER_2_START();


	// Initializing the interrupt 
	INTERRUPT_0_INIT ();
	//every thing is ok
	return OK;

}
uint8_t RUN_APP(void){
	// leds sequence
	// red and yellow car leds are off & green and yellow pedestrian leds are off
	// 	LED_OFF (PORT_A, PIN_1); // yellow car led
	// 	LED_OFF (PORT_A, PIN_2); // red car led
	// 	LED_OFF (PORT_B, PIN_0); // green pedestrian led
	// 	LED_OFF (PORT_B, PIN_1); // yellow pedestrian led
	// green car led is on & red pedestrian led is on
	LED_ON (PORT_A, PIN_0); // green car led
	LED_ON (PORT_B, PIN_2); // red pedestrian led
	// delay for 5 secs to make the leds on for 5 secs
	TIMER_2_DELAY_5SECS ();
	// green car led is off & red pedestrian led is off
	LED_OFF (PORT_A, PIN_0); // green car led
	LED_OFF (PORT_B, PIN_2); // red pedestrian led
	//  both Yellow leds blinking for 5 secs
	YELLOW_BLINKING (5000);
	// 	LED_ON (PORT_A, PIN_1); // yellow car led
	// 	LED_ON (PORT_B, PIN_1); // yellow pedestrian led
	// 	TIMER_2_DELAY_5SECS ();
	//  both Yellow leds are off
	LED_OFF (PORT_A, PIN_1); // yellow car led
	LED_OFF (PORT_B, PIN_1); // yellow pedestrian led
	// red car led is on & green pedestrian led is on
	LED_ON (PORT_A, PIN_2); // red car led
	LED_ON (PORT_B, PIN_0); // green pedestrian led
	// delay for 5 secs to make the leds on for 5 secs
	TIMER_2_DELAY_5SECS ();
	// red car led is off & green pedestrian led is off
	LED_OFF (PORT_A, PIN_2); // red car led
	LED_OFF (PORT_B, PIN_0); // green pedestrian led
	//  both Yellow leds blinking for 5 secs
	YELLOW_BLINKING (5000);
	// 	LED_ON (PORT_A, PIN_1); // yellow car led
	// 	LED_ON (PORT_B, PIN_1); // yellow pedestrian led
	// 	TIMER_2_DELAY_5SECS ();
	//  both Yellow leds are off
	LED_OFF (PORT_A, PIN_1); // yellow car led
	LED_OFF (PORT_B, PIN_1); // yellow pedestrian led

}

ISR(INT0_vect){

	INTERRUPTION();
	//every thing is ok
	return OK;
}

