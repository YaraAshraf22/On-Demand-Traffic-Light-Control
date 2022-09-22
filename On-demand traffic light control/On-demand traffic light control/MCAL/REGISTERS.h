/*
 * Registers.h
 *
 * Created: 9/11/2022 1:26:46 AM
 *  Author: HP
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "../Utilities/STD_TYPES.h"

//DIO REGISTERS

#define PORTA	(*((volatile uint8_t*)0x3B))
#define DDRA	(*((volatile uint8_t*)0x3A))
#define PINA	(*((volatile uint8_t*)0x39))

#define PORTB	(*((volatile uint8_t*)0x38))
#define DDRB	(*((volatile uint8_t*)0x37))
#define PINB	(*((volatile uint8_t*)0x36))

#define PORTC	(*((volatile uint8_t*)0x35))
#define DDRC	(*((volatile uint8_t*)0x34))
#define PINC	(*((volatile uint8_t*)0x33))

#define PORTD	(*((volatile uint8_t*)0x32))
#define DDRD	(*((volatile uint8_t*)0x31))
#define PIND	(*((volatile uint8_t*)0x30))

//TIMER 0 REGISTERS

#define TCNT0	(*(volatile uint8_t*)(0x52))
#define TCCR0	(*(volatile uint8_t*)(0x53))
#define TIMSK	(*(volatile uint8_t*)(0x59))
#define OCR0	(*(volatile uint8_t*)(0x5C))

#define TIFR	(*((volatile uint8_t*)0x58))

//TIMER 2 REGISTERS

#define TCCR2	(*(volatile uint8_t*)(0x45))
#define TCNT2	(*(volatile uint8_t*)(0x44))

//EXT INTERRUPT REGISTERS

#define SREG	(*(volatile uint8_t*)(0x5F))
#define GICR	(*(volatile uint8_t*)(0x5B))
#define GIFR	(*(volatile uint8_t*)(0x5A))
#define MCUCR	(*(volatile uint8_t*)(0x55))
#define MCUCSR	(*(volatile uint8_t*)(0x54))





#endif /* REGISTERS_H_ */