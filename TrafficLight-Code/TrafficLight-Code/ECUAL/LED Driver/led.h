/*
 * led.h
 *
 * Created: 8/6/2022 7:22:53 AM
 *  Author: Ahmed Medhat
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"

/************************************* HELPER MACROS **************************************/

/* LED STATUS */
#define ON 1
#define OFF 0

/********************************** FUNCTIONS PROTOTYPES **********************************/

EN_ErrorHandling_t LED_init(uint8_t LedPort, uint8_t LedPin); // LED initialization
EN_ErrorHandling_t LED_on(uint8_t LedPort, uint8_t LedPin); // LED on
EN_ErrorHandling_t LED_off(uint8_t LedPort, uint8_t LedPin); // LED off
EN_ErrorHandling_t LED_blink(uint8_t LedPort, uint8_t LedPin); // LED blinking


#endif /* LED_H_ */