/*
 * TrafficLight-Code.c
 *
 * Created: 8/6/2022 7:19:49 AM
 * Author : Ahmed Medhat
 */ 


#include "Application/application.h"


int main(void)
{
	APP_init(); // APPLICATION INITIALIZATION
	APP_start(); // APPLICATION START
	
	
	/* LED Driver Test Module */
	/*LED_init(PORT_C,0);
	while(1)
	{
		LED_on(PORT_C,0);
	}*/
	
	
	
	/* Button Test Module */
	/*uint8_t Button_State = NOT_PRESSED;
	BUTTON_init(PORT_D,2);
	LED_init(PORT_C,0);
	while(1)
	{
		BUTTON_read(PORT_D, 2, &Button_State);
		
		if(Button_State == PRESSED)
		{
			LED_on(PORT_C,0);
		}
		else
		{
			LED_off(PORT_C,0);
		}
	}*/
}

