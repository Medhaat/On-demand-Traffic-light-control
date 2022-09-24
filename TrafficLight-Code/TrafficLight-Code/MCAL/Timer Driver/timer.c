/*
 * timer.c
 *
 * Created: 8/6/2022 12:53:14 PM
 *  Author: ICONICS_USER
 */ 
#include "timer.h"

uint16_t OverFlowCounter = 0;

EN_ErrorHandling_t TIMER_init (uint8_t TimerNumber, uint8_t Mode) // Timer Initialization
{
	switch(TimerNumber)
	{
		case T0: // In Case Timer 0 (In case we want to add other timers in future work ^ ^)
			if(Mode == NORMAL_MODE) 
			{
				TCCR0 = NORMAL_MODE; 
			}
			else if(Mode == PHASE_CORRECT_PWM_MODE)
			{
				TCCR0 = PHASE_CORRECT_PWM_MODE;
			}
			else if(Mode == CTC_MODE)
			{
				TCCR0 = CTC_MODE;
			}
			else if(Mode == FAST_PWM_MODE)
			{
				TCCR0 = FAST_PWM_MODE;
			}
			else
			{
				return BAD;
			}
			return GOOD;
			
		default: // Error Handling
			return BAD;
	}
}

EN_ErrorHandling_t TIMER_set_initial_value (uint8_t TimerNumber, uint16_t InitialValue) // Sets Timer Initial value
{
	switch(TimerNumber)
	{
		case T0: // In Case Timer 0 (In case we want to add other timers in future work ^ ^)
			TCNT0 = InitialValue;
			return GOOD;
			
		default:
			return BAD;
	}
}

EN_ErrorHandling_t TIMER_start (uint8_t TimerNumber, uint16_t PreScaler) // Starts timer by setting its pre-scaler
{
	switch(TimerNumber)
	{
		case T0: // In Case Timer 0 (In case we want to add other timers in future work ^ ^)
			if(PreScaler == NO_PRESCALER) // No pre-scaler
			{
				SET_BIT(TCCR0,BIT0);
			}
			else if(PreScaler == PRESCALER_8) // Divide Frequency/8
			{
				SET_BIT(TCCR0,BIT1);
			}
			else if(PreScaler == PRESCALER_64) // Divide Frequency/64
			{
				SET_2BITS(TCCR0,BIT0,BIT1);
			}
			else if(PreScaler == PRESCALER_256) // Divide Frequency/256
			{
				SET_BIT(TCCR0,BIT2);
			}
			else if(PreScaler == PRESCALER_1024) // Divide Frequency/1024
			{
				SET_2BITS(TCCR0,BIT0,BIT2);
			}
			else // Error Handling
			{
				return BAD;
			}
			return GOOD;
			
		default:
			return BAD;
	}
}

EN_ErrorHandling_t TIMER_stop (uint8_t TimerNumber) // Stops the timer
{
	switch(TimerNumber)
	{
		case T0: // In Case Timer 0 (In case we want to add other timers in future work ^ ^)
			TCCR0 &= 0xF8;
			return GOOD;
			
		default:
			return BAD;	
	}
}

EN_ErrorHandling_t TIMER_delay (uint8_t TimerNumber, uint16_t NumberOfSeconds, uint16_t NumberOfOverflowsPerSec, uint16_t PreScaler) // Adjust the timer delay
{
	switch(TimerNumber) 
	{
		case T0: // In Case Timer 0 (In case we want to add other timers in future work ^ ^)
			if (TIMER_start(TimerNumber, PreScaler) == GOOD)
			{
				while(OverFlowCounter < (NumberOfSeconds*NumberOfOverflowsPerSec))
				{
					while((READ_BIT(TIFR,BIT0)) == 0); // waits until overflow occurs
					SET_BIT(TIFR,BIT0); // Reset Overflow Flag bit
					OverFlowCounter++;
				}
				OverFlowCounter = 0;
				if(TIMER_stop(TimerNumber) == GOOD)
				{
					return GOOD;
				}
				else
				{
					return BAD;
				}
			}
			else
			{
				return BAD;
			}
			
			
		default: //Error Handling
			return BAD;
	}
	
}
