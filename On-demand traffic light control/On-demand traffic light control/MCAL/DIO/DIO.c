/*
 * DIO.c
 *
 * Created: 9/13/2022 1:10:58 AM
 *  Author: HP
 */ 

#include "DIO.h"
#include "../../Utilities/BIT_MATH.h"
#include "../../Utilities/STD_TYPES.h"
#include "../REGISTERS.h"


void PIN_MODE (uint8_t pin,uint8_t mode)
{
	uint8_t port = pin / 10;
	switch(mode)
	{
		case OUTPUT:
		switch(port)
		{
			case 1:
			pin = pin % 10;
			SET_BIT(DDRB,pin);
			break;
			case 2:
			pin = pin % 20;
			SET_BIT(DDRD,pin);
			break;
			case 3:
			pin = pin % 30;
			SET_BIT(DDRC,pin);
			break;
			case 4:
			pin = pin % 40;
			SET_BIT(DDRA,pin);
			break;
		}
		break;
		
		case INPUT:
		switch(port)
		{
			case 1:
			pin = pin % 10;
			CLR_BIT(DDRB,pin);
			break;
			case 2:
			pin = pin % 20;
			CLR_BIT(DDRD,pin);
			break;
			case 3:
			pin = pin % 30;
			CLR_BIT(DDRC,pin);
			break;
			case 4:
			pin = pin % 40;
			CLR_BIT(DDRA,pin);
			break;
		}
		break;
	}
}
void PIN_WRITE (uint8_t pin,uint8_t status)
{
	uint8_t port = pin / 10;
	switch(status)
	{
		case HIGH:
		switch(port)
		{
			case 1:
			pin = pin % 10;
			SET_BIT(PORTB,pin);
			break;
			case 2:
			pin = pin % 20;
			SET_BIT(PORTD,pin);
			break;
			case 3:
			pin = pin % 30;
			SET_BIT(PORTC,pin);
			break;
			case 4:
			pin = pin % 40;
			SET_BIT(PORTA,pin);
			break;
		}
		break;
		
		case LOW:
		switch(port)
		{
			case 1:
			pin = pin % 10;
			CLR_BIT(PORTB,pin);
			break;
			case 2:
			pin = pin % 20;
			CLR_BIT(PORTD,pin);
			break;
			case 3:
			pin = pin % 30;
			CLR_BIT(PORTC,pin);
			break;
			case 4:
			pin = pin % 40;
			CLR_BIT(PORTA,pin);
			break;
		}
		break;
	}
}

void PIN_TOGGLE(uint8_t pin)
{
	uint8_t port = pin / 10;
	switch(port)
	{
		case 1:
		pin = pin % 10;
		TOG_BIT(PORTB,pin);
		break;
		case 2:
		pin = pin % 20;
		TOG_BIT(PORTD,pin);
		break;
		case 3:
		pin = pin % 30;
		TOG_BIT(PORTC,pin);
		break;
		case 4:
		pin = pin % 40;
		TOG_BIT(PORTA,pin);
		break;
	}
}

uint8_t PIN_READ (uint8_t pin)
{
	uint8_t port = pin / 10;
	uint8_t value = 0;
	switch(port)
	{
		case 1:
		pin = pin % 10;
		value = GET_BIT(PINB,pin);
		break;
		case 2:
		pin = pin % 20;
		value = GET_BIT(PIND,pin);
		break;
		case 3:
		pin = pin % 30;
		value = GET_BIT(PINC,pin);
		break;
		case 4:
		pin = pin % 40;
		value = GET_BIT(PINA,pin);
		break;
	}
	return value;
}
