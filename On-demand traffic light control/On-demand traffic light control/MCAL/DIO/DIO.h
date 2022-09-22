/*
 * DIO.h
 *
 * Created: 9/13/2022 1:11:10 AM
 *  Author: HP
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/STD_TYPES.h"

//PORT PINS MACROS
//PORTB
#define PB0      10
#define PB1      11
#define PB2      12
#define PB3      13
#define PB4      14
#define PB5      15
#define PB6      16
#define PB7      17

//PORTD
#define PD0      20
#define PD1      21
#define PD2      22
#define PD3      23
#define PD4      24
#define PD5      25
#define PD6      26
#define PD7      27

//PORTC
#define PC0      30
#define PC1      31
#define PC2      32
#define PC3      33
#define PC4      34
#define PC5      35
#define PC6      36
#define PC7      37

//PORTA
#define PA0      40
#define PA1      41
#define PA2      42
#define PA3      43
#define PA4      44
#define PA5      45
#define PA6      46
#define PA7      47

// PORT MACROS
#define B         1
#define D         2
#define C         3
#define A         4

//STATE MACROS
#define INPUT     0
#define OUTPUT    1

#define LOW       0
#define HIGH      1

// PROTOTYPES
void  PIN_MODE		(uint8_t,uint8_t);
void  PIN_WRITE		(uint8_t,uint8_t);
void  PIN_TOGGLE	(uint8_t);
uint8_t PIN_READ	(uint8_t );

#endif /* DIO_H_ */