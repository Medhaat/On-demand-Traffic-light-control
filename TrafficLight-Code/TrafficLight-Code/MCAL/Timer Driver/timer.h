/*
 * timer.h
 *
 * Created: 8/6/2022 12:53:24 PM
 *  Author: ICONICS_USER
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../DIO Driver/dio.h"

/************************************ HELPER MACROS ************************************/

/* BITS DEFINES */
#define BIT0 0
#define BIT1 1
#define BIT2 2

/* MODE DEFINES */
#define NORMAL_MODE 0x00
#define PHASE_CORRECT_PWM_MODE 0x40
#define CTC_MODE 0x08
#define FAST_PWM_MODE 0x48

/* 8-bit TIMER DEFINES */
#define T0 0

/* Pre-scaler DEFINES */
#define NO_PRESCALER 1
#define PRESCALER_8 8
#define PRESCALER_64 64
#define PRESCALER_256 256
#define PRESCALER_1024 1024

/********************************** FUNCTIONS PROTOTYPES **********************************/

EN_ErrorHandling_t TIMER_init (uint8_t TimerNumber, uint8_t Mode); // Timer Initialization
EN_ErrorHandling_t TIMER_set_initial_value (uint8_t TimerNumber, uint16_t InitialValue); // Sets Timer Initial value
EN_ErrorHandling_t TIMER_start (uint8_t TimerNumber, uint16_t PreScaler); // Starts timer by setting its pre-scaler 
EN_ErrorHandling_t TIMER_stop (uint8_t TimerNumber); // Stops the timer
EN_ErrorHandling_t TIMER_delay (uint8_t TimerNumber, uint16_t NumberOfSeconds, uint16_t NumberOfOverflowsPerSec, uint16_t PreScaler); // Adjust the timer delay


#endif /* TIMER_H_ */