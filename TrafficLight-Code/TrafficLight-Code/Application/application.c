/*
 * application.c
 *
 * Created: 8/6/2022 7:21:02 AM
 *  Author: Ahmed Medhat
 */ 
#include "application.h"

uint8_t mode = NORMAL_MODE; uint8_t Phase_When_Pressed; uint8_t Blinking_Count = 0;

void APP_init(void) // Application initialization function
{
	/* Pedestrian Button */
	BUTTON_init(BUTTON_PORT, BUTTON_PIN); // Button initialization
	
	/* CAR LEDs */
	LED_init(CAR_LEDS_PORT, CAR_LEDR_PIN); // Red Led initialization
	LED_init(CAR_LEDS_PORT, CAR_LEDY_PIN); // Yellow Led initialization
	LED_init(CAR_LEDS_PORT, CAR_LEDG_PIN); // Green Led initialization
	
	/* Pedestrian LEDs */
	LED_init(PED_LEDS_PORT, PED_LEDR_PIN); // Red Led initialization
	LED_init(PED_LEDS_PORT, PED_LEDY_PIN); // Yellow Led initialization
	LED_init(PED_LEDS_PORT, PED_LEDG_PIN); // Green Led initialization
	
	/* Enable External Interrupts */
	sei(); // Set Bit-I in Status Register to 1
	
	/* Choose External interrupt Sense - On Falling edge to avoid long press */
	SET_BIT(MCUCR, BIT_1);
	
	SET_BIT(GICR, INT_0); // Enable External Interrupt 0 (Start Listening)
	
	/* Initialize timer/counter 0 - Normal Mode */
	TIMER_init(T0,NORMAL_MODE);
	
	/* Set timer/counter 0 with calculated initial value */
	TIMER_set_initial_value(T0, TIMER_INITIAL);
	
}

void APP_start(void) // Application Start function
{
	while(1)
	{
		switch(mode)
		{
			case NORMAL_TRAFFIC_MODE: // Normal Mode (Interrupt is enabled)
				
				/* Normal Mode Code */
				
				/* Cars' LEDs Starting from Green */
				Phase_When_Pressed = GREEN; // Set Current Phase to Green
				LED_on(CAR_LEDS_PORT, CAR_LEDG_PIN); // Car Green Led turns on
				LED_on(PED_LEDS_PORT, PED_LEDR_PIN); // Pedestrian Red Led turns on
				
				/* Wait 5 Seconds then Close Green LED and turn on the yellow and make it blink for 5 seconds*/
				TIMER_delay(T0,SECONDS_5,NUMBER_OF_OVERFLOWS_1S,PRESCALER_1024); // Delay 5 seconds
				TIMER_set_initial_value(T0, TIMER_INITIAL); // Re-initializing the timer initial value
				
				Phase_When_Pressed = YELLOW; // Set Current Phase to Yellow
				LED_off(CAR_LEDS_PORT, CAR_LEDG_PIN); // Car Green Led turns off
				
				while(Blinking_Count != 5) // Car Yellow blinking for 5 seconds
				{
					LED_blink(CAR_LEDS_PORT, CAR_LEDY_PIN); // Car Yellow Led blinks
					TIMER_delay(T0,SECONDS_1,NUMBER_OF_OVERFLOWS_1S,PRESCALER_1024); // Delay 1 Seconds
					TIMER_set_initial_value(T0, TIMER_INITIAL); // Re-initializing the timer initial value
					Blinking_Count++;
				}
				Blinking_Count = 0;
				
				LED_off(PED_LEDS_PORT, PED_LEDR_PIN); // Pedestrian Red Led turns off
				Phase_When_Pressed = RED; // Set Current Phase to Red
				LED_off(CAR_LEDS_PORT, CAR_LEDY_PIN); // Car Yellow Led turns off
				LED_on(CAR_LEDS_PORT, CAR_LEDR_PIN); // Car Red Led turns on
				LED_on(PED_LEDS_PORT, PED_LEDG_PIN); // Pedestrian Green Led turns on
				
				/* Wait 5 Seconds */
				TIMER_delay(T0,SECONDS_5,NUMBER_OF_OVERFLOWS_1S,PRESCALER_1024); // Delay 5 Seconds
				TIMER_set_initial_value(T0, TIMER_INITIAL); // Re-initializing the timer initial value
				Phase_When_Pressed = YELLOW; // Set Current Phase to Yellow
				LED_off(CAR_LEDS_PORT, CAR_LEDR_PIN); // Car Red Led turns off
				LED_off(PED_LEDS_PORT, PED_LEDG_PIN); // Pedestrian Green Led turns off
				
				while(Blinking_Count != 5) // Car and Pedestrian Yellow blinking for 5 seconds
				{
					LED_blink(CAR_LEDS_PORT, CAR_LEDY_PIN); // Car Yellow Led blinks
					LED_blink(PED_LEDS_PORT, PED_LEDY_PIN); // Pedestrian Yellow led blinks
					TIMER_delay(T0,SECONDS_1,NUMBER_OF_OVERFLOWS_1S,PRESCALER_1024); // Delay 1 Seconds
					TIMER_set_initial_value(T0, TIMER_INITIAL); // Re-initializing the timer initial value
					Blinking_Count++;
				}
				Blinking_Count = 0;
				
				LED_off(CAR_LEDS_PORT, CAR_LEDY_PIN); // Car Yellow Led turns off
				LED_off(PED_LEDS_PORT, PED_LEDY_PIN); // Pedestrian Yellow Led turns off
				
				break;
			
			case PEDESTRIAN_TRAFFIC_MODE: // Pedestrian Mode (Interrupt is disabled to avoid double press)
			
				/* Pedestrian Mode Code */
				
				cli(); // Disable Global Interrupt to avoid double press on the button
				
				switch(Phase_When_Pressed)
				{
					case  RED:
						
						LED_on(PED_LEDS_PORT, PED_LEDG_PIN); // Pedestrian Green Led turns on
						TIMER_delay(T0,SECONDS_5,NUMBER_OF_OVERFLOWS_1S,PRESCALER_1024); // Delay 5 Seconds
						TIMER_set_initial_value(T0, TIMER_INITIAL); // Re-initializing the timer initial value
						LED_off(CAR_LEDS_PORT, CAR_LEDR_PIN); // Car Red Led turns off
						
						while(Blinking_Count != 5) // Car Yellow blinking for 5 seconds
						{
							LED_blink(CAR_LEDS_PORT, CAR_LEDY_PIN); // Car Yellow Led blinks
							TIMER_delay(T0,SECONDS_1,NUMBER_OF_OVERFLOWS_1S,PRESCALER_1024); // Delay 1 Seconds
							TIMER_set_initial_value(T0, TIMER_INITIAL); // Re-initializing the timer initial value
							Blinking_Count++;
						}
						Blinking_Count = 0;
						
						LED_off(CAR_LEDS_PORT, CAR_LEDY_PIN); // Car Yellow Led turns off
						LED_off(PED_LEDS_PORT, PED_LEDG_PIN); // Pedestrian Green Led turns off
						
						break;
					
					case YELLOW: 
						
						LED_off(CAR_LEDS_PORT, CAR_LEDY_PIN); // Car Yellow Led turns off
						LED_off(PED_LEDS_PORT, PED_LEDR_PIN); // Pedestrian Red Led turns off
						
						while(Blinking_Count != 5) // Car and Pedestrian Yellow blinking for 5 seconds
						{
							LED_blink(CAR_LEDS_PORT, CAR_LEDY_PIN); // Car Yellow Led blinks
							LED_blink(PED_LEDS_PORT, PED_LEDY_PIN); // Pedestrian Yellow led blinks
							TIMER_delay(T0,SECONDS_1,NUMBER_OF_OVERFLOWS_1S,PRESCALER_1024); // Delay 1 Seconds
							TIMER_set_initial_value(T0, TIMER_INITIAL); // Re-initializing the timer initial value
							Blinking_Count++;
						}
						Blinking_Count = 0;
						
						LED_off(CAR_LEDS_PORT, CAR_LEDY_PIN); // Car Yellow Led turns off
						LED_on(CAR_LEDS_PORT, PED_LEDR_PIN); // Car Red Led turns on
						LED_off(PED_LEDS_PORT, PED_LEDY_PIN); // Pedestrian Yellow Led turns off
						LED_on(PED_LEDS_PORT, PED_LEDG_PIN); // Pedestrian Green Led turns on
						
						TIMER_delay(T0,SECONDS_5,NUMBER_OF_OVERFLOWS_1S,PRESCALER_1024); // Delay 5 Seconds
						TIMER_set_initial_value(T0, TIMER_INITIAL); // Re-initializing the timer initial value
						
						LED_off(CAR_LEDS_PORT, CAR_LEDR_PIN); // Car Red Led turns off
						
						while(Blinking_Count != 5) // Car Yellow blinking for 5 seconds
						{
							LED_blink(CAR_LEDS_PORT, CAR_LEDY_PIN); // Car Yellow Led blinks
							TIMER_delay(T0,SECONDS_1,NUMBER_OF_OVERFLOWS_1S,PRESCALER_1024); // Delay 1 Seconds
							TIMER_set_initial_value(T0, TIMER_INITIAL); // Re-initializing the timer initial value
							Blinking_Count++;
						}
						Blinking_Count = 0;
						
						LED_off(PED_LEDS_PORT, PED_LEDG_PIN); // Pedestrian Green Led turns off
						LED_off(CAR_LEDS_PORT, CAR_LEDY_PIN); // Car Yellow Led turns off
						
						break;
						
					case GREEN:
						
						LED_off(CAR_LEDS_PORT, CAR_LEDG_PIN); // Car Green Led turns off
						LED_off(PED_LEDS_PORT, PED_LEDR_PIN); // Pedestrian Red Led turns off
						
						while(Blinking_Count != 5) // Car and Pedestrian Yellow blinking for 5 seconds
						{
							LED_blink(CAR_LEDS_PORT, CAR_LEDY_PIN); // Car Yellow Led blinks
							LED_blink(PED_LEDS_PORT, PED_LEDY_PIN); // Pedestrian Yellow led blinks
							TIMER_delay(T0,SECONDS_1,NUMBER_OF_OVERFLOWS_1S,PRESCALER_1024); // Delay 1 Seconds
							TIMER_set_initial_value(T0, TIMER_INITIAL); // Re-initializing the timer initial value
							Blinking_Count++;
						}
						Blinking_Count = 0;
						
						LED_off(CAR_LEDS_PORT, CAR_LEDY_PIN); // Car Yellow Led turns off
						LED_on(CAR_LEDS_PORT, PED_LEDR_PIN); // Car Red Led turns on
						LED_off(PED_LEDS_PORT, PED_LEDY_PIN); // Pedestrian Yellow Led turns off
						LED_on(PED_LEDS_PORT, PED_LEDG_PIN); // Pedestrian Green Led turns on
						
						TIMER_delay(T0,SECONDS_5,NUMBER_OF_OVERFLOWS_1S,PRESCALER_1024); // Delay 5 Seconds
						TIMER_set_initial_value(T0, TIMER_INITIAL); // Re-initializing the timer initial value
						
						LED_off(CAR_LEDS_PORT, CAR_LEDR_PIN); // Car Red Led turns off
						
						while(Blinking_Count != 5) // Car Yellow blinking for 5 seconds
						{
							LED_blink(CAR_LEDS_PORT, CAR_LEDY_PIN); // Car Yellow Led blinks
							TIMER_delay(T0,SECONDS_1,NUMBER_OF_OVERFLOWS_1S,PRESCALER_1024); // Delay 1 Seconds
							TIMER_set_initial_value(T0, TIMER_INITIAL); // Re-initializing the timer initial value
							Blinking_Count++;
						}
						Blinking_Count = 0;
						
						LED_off(PED_LEDS_PORT, PED_LEDG_PIN); // Pedestrian Green Led turns off
						LED_off(CAR_LEDS_PORT, CAR_LEDY_PIN); // Car Yellow Led turns off
						
						break;
					
				}
				
				mode = NORMAL_TRAFFIC_MODE; // To return back to Normal Mode and wait to another press
				
				sei(); // Re-Enable the Global Interrupt and wait for the next button press
				
				break;
		}
	}
}

ISR(EXT_INT_0) // Interrupt Service Routine for external interrupt 0
{
	mode = PEDESTRIAN_TRAFFIC_MODE;
	APP_start();
}