/*
 * registers.h
 *
 * Created: 8/6/2022 7:25:12 AM
 *  Author: Ahmed Medhat
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "types.h"

/******************************** DIO REGISTERS ********************************/

/****************************** PORT A REGISTERS ******************************/
#define DDRA (*((volatile uint8_t*)(0x3A))) // Data Direction Register of Port A
#define PORTA (*((volatile uint8_t*)(0x3B))) // Data Register of Port A
#define PINA (*((volatile uint8_t*)(0x39))) // Status Register of Port A

/****************************** PORT B REGISTERS ******************************/
#define DDRB (*((volatile uint8_t*)(0x37))) // Data Direction Register of Port B
#define PORTB (*((volatile uint8_t*)(0x38))) // Data Register of Port B
#define PINB (*((volatile uint8_t*)(0x36))) // Status Register of Port B

/****************************** PORT C REGISTERS ******************************/
#define DDRC (*((volatile uint8_t*)(0x34))) // Data Direction Register of Port C
#define PORTC (*((volatile uint8_t*)(0x35))) // Data Register of Port C
#define PINC (*((volatile uint8_t*)(0x33))) // Status Register of Port C

/****************************** PORT D REGISTERS ******************************/
#define DDRD (*((volatile uint8_t*)(0x31))) // Data Direction Register of Port D
#define PORTD (*((volatile uint8_t*)(0x32))) // Data Register of Port D
#define PIND (*((volatile uint8_t*)(0x30))) // Status Register of Port D

/*********************** EXTERNAL INTERRUPTS REGISTERS ************************/
#define MCUCR (*((volatile uint8_t*)(0x55)))
#define MCUCSR (*((volatile uint8_t*)(0x54)))
#define GICR (*((volatile uint8_t*)(0x5B)))
#define GIFR (*((volatile uint8_t*)(0x5A)))

/****************************** TIMER REGISTERS *******************************/
#define TCCR0 (*((volatile uint8_t*)(0x53)))
#define TCNT0 (*((volatile uint8_t*)(0x52)))
#define TIFR (*((volatile uint8_t*)(0x58)))
#define OCR0 (*((volatile uint8_t*)(0x5C)))

#endif /* REGISTERS_H_ */