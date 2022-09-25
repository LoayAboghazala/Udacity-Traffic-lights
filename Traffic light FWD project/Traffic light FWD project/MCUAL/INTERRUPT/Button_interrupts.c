#include "Button_interrupts.h"

extern uint8_t flag ;

// implementation for initialization interrupt 0 function
uint8_t INTERRUPT_0_INIT (void)
{

	// enable global interrupt by built in function
	sei();
	// choose the external interrupt sense "rising edge",long press will not matter 
	// setting the two bits to be = 1
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);

	// enable external interrupt 0
	// setting the bit to be = 1
	SET_BIT(GICR,INT0);
	//every thing is ok
	return OK;
}

uint8_t INTERRUPTION (void){
	//"1st case" if the button is pressed when the cars' Red LED is on
	// check if the button is pressed when the cars' red led is on
	if ( BIT_IS_SET(PINA,PIN_2) ) { 
		// the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds
		LED_ON(PORT_A,PIN_2);  // red car led
		LED_ON(PORT_B,PIN_0);  // green pedestrian led
		// delay for 5 secs to make the leds on for 5 secs
		TIMER_2_DELAY_5SECS ();
	}
	// "2nd case" if the button is pressed when the cars' Green LED is on or the cars' Yellow LED is blinking,
	// check if the button is pressed when the cars' green led is on. or  yellow leds is blinking
	else if ( BIT_IS_SET(PINA,PIN_0) ||   flag ==1)
	{
		// the pedestrian red led will be off and the car green led will be off
		LED_OFF(PORT_A,PIN_0);  // green car led
		LED_OFF (PORT_B, PIN_2); // red pedestrian led
		// then both yellow leds start to blink for five seconds,
		YELLOW_BLINKING(5000);
		//  both Yellow leds are off
		LED_OFF (PORT_A, PIN_1); // yellow car led
		LED_OFF (PORT_B, PIN_1); // yellow pedestrian led

		// then the car red led and pedestrian green led are on for five seconds,
		LED_ON(PORT_A,PIN_2);  // RED LED FOR CARS
		LED_ON(PORT_B,PIN_0);  // GREEN LED FOR PEDESTRIANS
		TIMER_2_DELAY_5SECS ();
	}
	//after any case happen from above
	// 	 the car red led will be off and both yellow leds start blinking for 5 seconds
	// 	 and the pedestrian's green led is still on
	LED_OFF(PORT_A,PIN_2);  // red car led
	// then both yellow leds start to blink for five seconds,
	YELLOW_BLINKING(5000);
	//   After 5 seconds the pedestrian green led will be off
	LED_OFF(PORT_B,PIN_0);  // green pedestrian led
	//  both Yellow leds are off
	LED_OFF(PORT_A,PIN_1);  // yellow car led
	LED_OFF(PORT_B,PIN_1);  // yellow pedestrian led
	//   and both the pedestrian Red LED and the cars' Green LED will be on.
	LED_ON(PORT_A,PIN_0);  // green car led
	LED_ON(PORT_B,PIN_2);  // red pedestrian led
	TIMER_2_DELAY_5SECS ();
	//   "to return to the state that were on the normal mode " after 5 secs both the pedestrian Red LED and the cars' Green LED will be off .
	LED_OFF(PORT_A,PIN_0);  // green car led
	LED_OFF(PORT_B,PIN_2);  // red pedestrian led
	//every thing is ok
	return OK;
}
