/*
 * PUSH_BUTTON.c
 *
 * Created: 9/13/2022 2:29:37 AM
 *  Author: HP
 */ 

#include "PUSH_BUTTON.h"
#include "PUSH_BUTTON_CFG.h"
#include "../../Utilities/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"

void  PUSH_BUTTON_INIT (uint8_t button)
{
	switch(button)
	{
		case 0:
		PIN_MODE(BUTTON_PIN_INT0,INPUT);
		break;
		case 1:
		PIN_MODE(BUTTON_PIN_INT1,INPUT);
		break;
	}
}

uint8_t	PUSH_BUTTON_READ (uint8_t button)
{
	uint8_t value = 0;
	switch(button)
	{
		case 0:
		value = PIN_READ(BUTTON_PIN_INT0);
		break;
		case 1:
		value = PIN_READ(BUTTON_PIN_INT1);
		break;
		
	}
	return value;
}


