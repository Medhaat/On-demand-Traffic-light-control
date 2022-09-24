/*
 * button.h
 *
 * Created: 8/6/2022 7:22:39 AM
 *  Author: Ahmed Medhat
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO Driver/dio.h"

/************************************* HELPER MACROS **************************************/

/* BUTTON STATUS */
#define PRESSED 1
#define NOT_PRESSED 0

/********************************** FUNCTIONS PROTOTYPES **********************************/

EN_ErrorHandling_t BUTTON_init(uint8_t ButtonPort, uint8_t ButtonPin); // Button initialization as input device
EN_ErrorHandling_t BUTTON_read(uint8_t ButtonPort, uint8_t ButtonPin, uint8_t* Value); // Button get status


#endif /* BUTTON_H_ */