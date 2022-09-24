/*
 * interrupts.h
 *
 * Created: 8/6/2022 7:28:37 AM
 *  Author: ICONICS_USER
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

/************************************ EXTERNAL INTERRUPT REQUEST 0 ************************************/
#define EXT_INT_0 __vector_1

/************************************** ENABLE GLOABLE INTERRUPT **************************************/
#define sei() __asm__ __volatile__ ("sei" ::: "memory") // Sets the I-Bit in status register to 1

/************************************* DISABLE GLOABLE INTERRUPT **************************************/
#define cli() __asm__ __volatile__ ("cli" ::: "memory") // Sets the I-Bit in status register to 0

/*************************************** MACRO DEFINES THE ISR ***************************************/
#define ISR(INT_VECT) void INT_VECT(void) __attribute__((signal,used)); \
void INT_VECT(void)

#endif /* INTERRUPTS_H_ */