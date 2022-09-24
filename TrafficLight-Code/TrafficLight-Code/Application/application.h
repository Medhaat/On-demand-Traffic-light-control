/*
 * application.h
 *
 * Created: 8/6/2022 7:21:20 AM
 *  Author: Ahmed Medhat
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Button Driver/button.h"
#include "../MCAL/Timer Driver/timer.h"

/************************************ HELPER MACROS ************************************/

/* TIMER CALCULATIONS DEFINES FOR 1 SEC delay */
#define TIMER_INITIAL 0x0C
#define	NUMBER_OF_OVERFLOWS_1S 4
#define SECONDS_5 5
#define SECONDS_1 1
#define SECONDS_2 2

/* MODES DEFINES */
#define NORMAL_TRAFFIC_MODE 0
#define PEDESTRIAN_TRAFFIC_MODE 1

/* PHASE DEFINES */
#define  RED 1
#define YELLOW 2
#define  GREEN 3

/* BITS DEFINES */
#define BIT_0 0
#define BIT_1 1
#define INT_0 6

/* BUTTON DEFINES */
#define BUTTON_PORT PORT_D 
#define BUTTON_PIN PIN2

/* CARS LED DEFINES */
#define CAR_LEDS_PORT PORT_A // CAR LEDs Port A
#define CAR_LEDR_PIN PIN0 // CAR RED LED  
#define CAR_LEDY_PIN PIN1 // CAR YELLOW LED
#define CAR_LEDG_PIN PIN2 // CAR GREEN LED

/* PED LED DEFINES */
#define PED_LEDS_PORT PORT_B // PEDESTRAIN LEDs Port B
#define PED_LEDR_PIN PIN0 // PEDESTRAIN RED LED
#define PED_LEDY_PIN PIN1 // PEDESTRAIN YELLOW LED
#define PED_LEDG_PIN PIN2 // PEDESTRAIN GREEN LED

/********************************** FUNCTIONS PROTOTYPES **********************************/

void APP_init(void); // Application initialization function
void APP_start(void); // Application Start function

#endif /* APPLICATION_H_ */