#include "timer.h"
#include <math.h>


//implementation for function to initialize timer 2 configuration or mode "NORMAL MODE"
uint8_t TIMER_2_CONFIG_NORMAL_MODE (void)
{
	// clearing WGM20 AND WGM21 bits to set the normal mode
	CLEAR_BIT(TCCR2,WGM20);
	CLEAR_BIT(TCCR2,WGM21);
	//every thing is ok
	return OK ;
}
// implementation for function to set the initial value of timer 2
uint8_t TIMER_2_START_VALUE_5SECS(void){
	// setting the initial value to 12 ms
	TCNT2 = 0x0c;
	//every thing is ok
	return OK ;
}
// implementation for function to start the timer 2 counting
uint8_t TIMER_2_START(void){
	// setting CS20,CS21 and CS22 bits to set the prescalar to 1024 and start the timer counting
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	//every thing is ok
	return Ok ;
}
//  implementation for function to delay 5 secs with timer2,using polling
uint8_t TIMER_2_DELAY_5SECS (void){
	// declaring variable to count no of overflows
	uint8_t i =0;
	// loop to make the timer overflow 20 times
	while(i < NO_OF_OVERFLOWS){
		//"polling" checking the flag state,if it is 0 then stay at the infinite loop untill it becomes 1 this mean that an overflow occurred so it get out of the loop
		while ( (TIFR & (1<<TOV2)) == 0);
		// clearing the overflow flag by setting the overflow bit "TOV2" to 1
		SET_BIT(TIFR,TOV2);
		//incrementing the counter
		i ++;
	}
	// reseting the counter
	i =0;
	//every thing is ok
	return OK;
}
// implementation for function to get the timer value at this time
uint8_t GET_TIMER_2_VALUE(uint64_t TOTAL_OVERFLOWS){
	// error handling for non integer or negative values
	if((TOTAL_OVERFLOWS < 0)||(!(uint32_t)TOTAL_OVERFLOWS)){

		printf("please enter positive int number");
		//there is an error
		return ERROR;
	}
	else{
		//declaring a variable to put the time value in it
		uint64_t TIME_VALUE;

		uint32_t j =0;
		while(j < TOTAL_OVERFLOWS){
			//"polling" checking the flag state,if it is 0 then stay at the infinite loop untill, it becomes 1 this mean that an overflow occurred so it get out of the loop
			while ( (TIFR & (1<<TOV2)) == 0);
			// clearing the overflow flag by setting the overlow bit "TOV2" to 1
			SET_BIT(TIFR,TOV2);
			//incrementing the counter
			j++;
		}
		if(j > 0){
			TIME_VALUE = j*TCNT2 ;
		}
		else {
			TIME_VALUE = TCNT2 ;
		}
		// reseting the counter
		j=0;
		//every thing is ok
		return OK;
	}
}
//  implementation for function to delay any time using timer 2,using polling
uint8_t Timer2_delay_ms(float64_t Time )
{
	// error handling for negative values
	if((Time < 0)){

		printf("please enter positive number");
		//there is an error
		return ERROR;
	}
	else{
		// initializing some used variables
		uint32_t Counter=0;
		uint32_t GENERAL_NUMBER_OF_OVERFLOWS,INITIAL_VALUE_OF_TIMER;
		float64_t MAX_D_TIME ,TICK;
		uint16_t PRESCALAR = 1024 ;

		// at Frequency 1MHZ
		TICK = PRESCALAR / 1000.0; // milLi second
		//  8-bit timer
		MAX_D_TIME= TICK * 256; // milli seconds
		// (Time<MAX_D_TIME) state
		if(Time<MAX_D_TIME)
		{ //calculating INITIAL_VALUE_OF_TIMER
			INITIAL_VALUE_OF_TIMER = (MAX_D_TIME-Time)/TICK;
			// sating the GENERAL_NUMBER_OF_OVERFLOWS
			GENERAL_NUMBER_OF_OVERFLOWS = 1;

		}
		// (Time=MAX_D_TIME) state
		else if(Time == MAX_D_TIME)
		{
			// stating INITIAL_VALUE_OF_TIMER
			INITIAL_VALUE_OF_TIMER=0;
			// sating the GENERAL_NUMBER_OF_OVERFLOWS
			GENERAL_NUMBER_OF_OVERFLOWS=1;
		}
		// (Time>MAX_D_TIME) state
		else
		{
			//calculating GENERAL_NUMBER_OF_OVERFLOWS
			GENERAL_NUMBER_OF_OVERFLOWS = ceil(Time/MAX_D_TIME);
			//calculating INITIAL_VALUE_OF_TIMER
			INITIAL_VALUE_OF_TIMER = 256 - (Time/TICK)/GENERAL_NUMBER_OF_OVERFLOWS;

		}
		// loop to make the timer overflow calculated GENERAL_NUMBER_OF_OVERFLOWS times
		while (Counter < GENERAL_NUMBER_OF_OVERFLOWS){
			//"polling" checking the flag state,if it is 0 then stay at the infinite loop untill, it becomes 1 this mean that an overflow occurred so it get out of the loop
			while ( (TIFR & (1<<TOV2)) == 0);
			// clearing the overflow flag by setting the overflow bit "TOV2" to 1
			SET_BIT(TIFR,TOV2);
			//incrementing the counter
			Counter++;
		}
		// reseting the counter
		Counter =0;
		//every thing is ok
		return OK;
	}
}
