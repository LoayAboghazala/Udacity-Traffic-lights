
#include <avr/io.h>
 
 #include "APP/app.h"
 #include "HCUAL/LED/led.h"
#include "MCUAL/TIMER/timer.h"
#include "Test.h"

int main(void)
{  
	//TEST_GPIO ();
	TEST_TIMERS ();
	//TEST_LED();
	
	
	
	//APP_INITILIZATION();
// 	LED_INIT(PORT_A,PIN_1);
// 	LED_INIT(PORT_B,PIN_1);
// 	TIMER_2_CONFIG_NORMAL_MODE();
// 	TIMER_2_START();
//DDRA|=(1<<0);
	

    /* Replace with your application code */
   /* while (1) 
    {
	//	YELLOW_BLINKING();
// 		LED_ON(PORT_A,PIN_1);
// 		LED_ON(PORT_B,PIN_1);
// 		TIMER_2_DELAY_5SECS ();
// 		LED_OFF(PORT_A,PIN_1);
// 		LED_OFF(PORT_B,PIN_1		//PORTA|=(1<<0);
		//LED_OFF(PORT_A,PIN_0);
		//TIMER_2_DELAY_5SECS ();
		//LED_ON(PORT_A,PIN_0);
		//TIMER_2_DELAY_5SECS ();
		//LED_OFF(PORT_A,PIN_0);
		//TIMER_2_DELAY_5SECS ();
		
		 RUN_APP();
    }*/
}

