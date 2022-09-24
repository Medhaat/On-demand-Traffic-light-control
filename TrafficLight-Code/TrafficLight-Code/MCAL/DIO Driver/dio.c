/*
 * dio.c
 *
 * Created: 8/6/2022 7:23:47 AM
 *  Author: Ahmed Medhat
 */ 

#include "dio.h"

EN_ErrorHandling_t DIO_init(uint8_t PortNumber, uint8_t PinNumber, uint8_t Direction) // Initialize dio direction
{
	switch(PortNumber)
	{
		case PORT_A: // In Case Port A
			if(Direction == IN) // Input PIN
			{
				CLR_BIT(DDRA, PinNumber);
			}
			else if(Direction == OUT) // Output PIN
			{
				SET_BIT(DDRA, PinNumber);
			}
			else // Error handling
			{
				return BAD;
			}
			return GOOD;
			
		case PORT_B: // In Case Port B
			if(Direction == IN) // Input PIN
			{
				CLR_BIT(DDRB, PinNumber);
			}
			else if(Direction == OUT) // Output PIN
			{
				SET_BIT(DDRB, PinNumber);
			}
			else // Error handling
			{
				return BAD;
			}
			return GOOD;
			
		case PORT_C: // In Case Port C
			if(Direction == IN) // Input PIN
			{
				CLR_BIT(DDRC, PinNumber);
			}
			else if(Direction == OUT) // Output PIN
			{
				SET_BIT(DDRC, PinNumber);
			}
			else // Error handling
			{
				return BAD;
			}
			return GOOD;
			
		case PORT_D: // In Case Port D
			if(Direction == IN) // Input PIN
			{
				CLR_BIT(DDRD, PinNumber);
			}
			else if(Direction == OUT) // Output PIN
			{
				SET_BIT(DDRD, PinNumber);
			}
			else // Error handling
			{
				return BAD;
			}
			return GOOD;
			 
		default: // Error handling
			return BAD;
	}
}

EN_ErrorHandling_t DIO_write(uint8_t PortNumber, uint8_t PinNumber, uint8_t Value) // Write data to dio
{
	switch(PortNumber)
	{
		case PORT_A: // In Case Port A
			if(Value == LOW) // LOW Voltage
			{
				CLR_BIT(PORTA, PinNumber);
			}
			else if(Value == HIGH) // HIGH Voltage
			{
				SET_BIT(PORTA, PinNumber);
			}
			else // Error handling
			{
				return BAD;
			}
			return GOOD;
		
		case PORT_B: // In Case Port B
			if(Value == LOW) // LOW Voltage
			{
				CLR_BIT(PORTB, PinNumber);
			}
			else if(Value == HIGH) // HIGH Voltage
			{
				SET_BIT(PORTB, PinNumber);
			}
			else // Error handling
			{
				return BAD;
			}
			return GOOD;
		
		case PORT_C: // In Case Port C
			if(Value == LOW) // LOW Voltage
			{
				CLR_BIT(PORTC, PinNumber);
			}
			else if(Value == HIGH) // HIGH Voltage
			{
				SET_BIT(PORTC, PinNumber);
			}
			else // Error handling
			{
				return BAD;
			}
			return GOOD;
		
		case PORT_D: // In Case Port D
			if(Value == LOW) // LOW Voltage
			{
				CLR_BIT(PORTD, PinNumber);
			}
			else if(Value == HIGH) // HIGH Voltage
			{
				SET_BIT(PORTD, PinNumber);
			}
			else // Error handling
			{
				return BAD;
			}
			return GOOD;
		
		default: // Error handling
			return BAD;
	}
}

EN_ErrorHandling_t DIO_toggle(uint8_t PortNumber, uint8_t PinNumber) // Toggle dio
{
	switch(PortNumber)
	{
		case PORT_A: // In Case Port A
		
			TOGGLE_BIT(PORTA, PinNumber);
			return GOOD;
		
		case PORT_B: // In Case Port B
			
			TOGGLE_BIT(PORTB, PinNumber);
			return GOOD;
		
		case PORT_C: // In Case Port C
		
			TOGGLE_BIT(PORTC, PinNumber);
			return GOOD;
		
		case PORT_D: // In Case Port D
			
			TOGGLE_BIT(PORTD, PinNumber);
			return GOOD;
		
		default: // Error handling
			return BAD;
	}
}

EN_ErrorHandling_t DIO_read(uint8_t PortNumber, uint8_t PinNumber, uint8_t* Value) // Read dio
{
	switch(PortNumber)
	{
		case PORT_A: // In Case Port A
		
			*Value = READ_BIT(PINA, PinNumber);
			return GOOD;
		
		case PORT_B: // In Case Port B
		
			*Value = READ_BIT(PINB, PinNumber);
			return GOOD;
		
		case PORT_C: // In Case Port C
		
			*Value = READ_BIT(PINC, PinNumber);
			return GOOD;
		
		case PORT_D: // In Case Port D
		
			*Value = READ_BIT(PIND, PinNumber);
			return GOOD;
		
		default: // Error handling
			return BAD;
	}
}

