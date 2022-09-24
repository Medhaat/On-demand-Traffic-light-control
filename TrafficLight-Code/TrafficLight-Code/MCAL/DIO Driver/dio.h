/*
 * dio.h
 *
 * Created: 8/6/2022 7:23:58 AM
 *  Author: Ahmed Medhat
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/error_handling.h"
#include "../../Utilities/interrupts.h"

/************************************ HELPER MACROS ************************************/

/* PORTS DEFINES */
#define PORT_A 'A' // Port A
#define PORT_B 'B' // Port B
#define PORT_C 'C' // Port C
#define PORT_D 'D' // Port D

/* PINS DEFINES */
#define PIN0 0 // Pin 0
#define PIN1 1 // Pin 1
#define PIN2 2 // Pin 2
#define PIN3 3 // Pin 3
#define PIN4 4 // Pin 4
#define PIN5 5 // Pin 5
#define PIN6 6 // Pin 6
#define PIN7 7 // Pin 7

/* DIRECTIONS DEFINES */
#define IN 0 // Input Direction
#define OUT 1 // Output Direction

/* VALUES DEFINES */
#define HIGH 1 // High Voltage
#define LOW 0 // Low Voltage

/********************************** FUNCTIONS PROTOTYPES **********************************/

EN_ErrorHandling_t DIO_init(uint8_t PortNumber, uint8_t PinNumber, uint8_t Direction); // Initialize dio direction
EN_ErrorHandling_t DIO_write(uint8_t PortNumber, uint8_t PinNumber, uint8_t Value); // Write data to dio
EN_ErrorHandling_t DIO_toggle(uint8_t PortNumber, uint8_t PinNumber); // Toggle dio
EN_ErrorHandling_t DIO_read(uint8_t PortNumber, uint8_t PinNumber, uint8_t* Value); // Read dio

#endif /* DIO_H_ */