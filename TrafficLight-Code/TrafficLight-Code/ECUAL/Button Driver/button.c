/*
 * button.c
 *
 * Created: 8/6/2022 7:22:28 AM
 *  Author: Ahmed Medhat
 */ 
#include "button.h"

EN_ErrorHandling_t BUTTON_init(uint8_t ButtonPort, uint8_t ButtonPin) // Button initialization as input device
{
	if(DIO_init(ButtonPort, ButtonPin, IN) == 0)
	{
		return GOOD;
	}
	else
	{
		return BAD;
	}
}

EN_ErrorHandling_t BUTTON_read(uint8_t ButtonPort, uint8_t ButtonPin, uint8_t* Value) // Button get status
{
	if(DIO_read(ButtonPort, ButtonPin, Value) == 0)
	{
		return GOOD;
	}
	else
	{
		return BAD;
	}
}
