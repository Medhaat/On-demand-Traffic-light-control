/*
 * bit_manipulation.h
 *
 * Created: 8/6/2022 7:25:58 AM
 *  Author: Ahmed Medhat
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

#define SET_BIT(X,BIT_NO) (X|=(1<<BIT_NO)) // Set Bit Function Like Macro
#define SET_2BITS(X,BIT_NO1,BIT_NO2) (X|=((1<<BIT_NO1)|(1<<BIT_NO2))) // Set 2 Bits Function Like Macro
#define CLR_BIT(X,BIT_NO) (X&=~(1<<BIT_NO)) // CLear Bit Function Like Macro
#define READ_BIT(X,BIT_NO) ((X&(1<<BIT_NO))>>BIT_NO) // Read Bit Function Like Macro
#define TOGGLE_BIT(X,BIT_NO) (X^=(1<<BIT_NO)) // Toggle Bit Function Like Macro


#endif /* BIT_MANIPULATION_H_ */