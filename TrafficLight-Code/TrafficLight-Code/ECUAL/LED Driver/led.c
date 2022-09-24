/*
 * led.c
 *
 * Created: 8/6/2022 7:23:04 AM
 *  Author: Ahmed Medhat
 */ 

#include "led.h"

EN_ErrorHandling_t LED_init(uint8_t LedPort, uint8_t LedPin) // LED initialization as output device
{
	if(DIO_init(LedPort, LedPin, OUT) == 0)
	{
		return GOOD;
	}
	else
	{
		return BAD;	
	}
}

EN_ErrorHandling_t LED_on(uint8_t LedPort, uint8_t LedPin) // LED on
{
	if(DIO_write(LedPort, LedPin, HIGH) == 0)
	{
		return GOOD;
	}
	else
	{
		return BAD;
	}
}

EN_ErrorHandling_t LED_off(uint8_t LedPort, uint8_t LedPin) // LED off
{
	if(DIO_write(LedPort, LedPin, LOW) == 0)
	{
		return GOOD;
	}
	else
	{
		return BAD;
	}
}

EN_ErrorHandling_t LED_blink(uint8_t LedPort, uint8_t LedPin) // LED blinking
{
	if(DIO_toggle(LedPort, LedPin) == 0)
	{
		return GOOD;
	}
	else
	{
		return BAD;
	}
}