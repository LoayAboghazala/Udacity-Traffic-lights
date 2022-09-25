#include "Test.h"

void TEST_GPIO (void){
	GPIO_INIT(PORT_A,PIN_1,OUT);
	GPIO_INIT(PORT_A,PIN_5,OUT);
	GPIO_WRITE(PORT_A,PIN_1,LOW);
	GPIO_WRITE(PORT_A,PIN_5,HIGH);
	
}


void TEST_TIMERS (void){
	TIMER_2_CONFIG_NORMAL_MODE();
	TIMER_2_START_VALUE_5SECS();
	TIMER_2_START();
	LED_INIT(PORT_A,PIN_3);
	while (1)
	{
		LED_ON(PORT_A,PIN_3);
		TIMER_2_DELAY_5SECS();
		//Timer2_delay_ms(5000);
		LED_OFF(PORT_A,PIN_3);
		TIMER_2_DELAY_5SECS();
		//Timer2_delay_ms(5000);
	}
	
}

void TEST_LED (void){
	LED_INIT(PORT_A,PIN_3);  
	while (1)
	{
		LED_TOGGLE(PORT_A,PIN_3);
		_delay_ms(1000);
	
	
}
}