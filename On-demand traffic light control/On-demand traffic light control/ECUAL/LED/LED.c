/*
 * LED.c
 *
 * Created: 9/13/2022 2:29:17 AM
 *  Author: HP
 */ 

#include "../../Utilities/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"


#include "LED.h"
#include "LED_CFG.h"


void LED_INIT   (uint8_t led)
{
	switch(led)
	{
		case 0:
		PIN_MODE(CAR_RED_LED_PIN,OUTPUT);
		break;
		case 1:
		PIN_MODE(CAR_YELLOW_LED_PIN,OUTPUT);
		break;
		case 2:
		PIN_MODE(CAR_GREEN_LED_PIN,OUTPUT);
		break;
		case 3:
		PIN_MODE(PED_RED_LED_PIN,OUTPUT);
		break;
		case 4:
		PIN_MODE(PED_YELLOW_LED_PIN,OUTPUT);
		break;
		case 5:
		PIN_MODE(PED_GREEN_LED_PIN,OUTPUT);
		break;
	}
}
void LED_ON     (uint8_t led)
{
	switch(led)
	{
		case 0:
		PIN_WRITE(CAR_RED_LED_PIN,HIGH);
		break;
		case 1:
		PIN_WRITE(CAR_YELLOW_LED_PIN,HIGH);
		break;
		case 2:
		PIN_WRITE(CAR_GREEN_LED_PIN,HIGH);
		break;
		case 3:
		PIN_WRITE(PED_RED_LED_PIN,HIGH);
		break;
		case 4:
		PIN_WRITE(PED_YELLOW_LED_PIN,HIGH);
		break;
		case 5:
		PIN_WRITE(PED_GREEN_LED_PIN,HIGH);
		break;
	}
}
void LED_OFF    (uint8_t led)
{
	switch(led)
	{
		case 0:
		PIN_WRITE(CAR_RED_LED_PIN,LOW);
		break;
		case 1:
		PIN_WRITE(CAR_YELLOW_LED_PIN,LOW);
		break;
		case 2:
		PIN_WRITE(CAR_GREEN_LED_PIN,LOW);
		break;
		case 3:
		PIN_WRITE(PED_RED_LED_PIN,LOW);
		break;
		case 4:
		PIN_WRITE(PED_YELLOW_LED_PIN,LOW);
		break;
		case 5:
		PIN_WRITE(PED_GREEN_LED_PIN,LOW);
		break;
	}
}
void LED_TOGGLE (uint8_t led)
{
	switch(led)
	{
		case 0:
		PIN_TOGGLE(CAR_RED_LED_PIN);
		break;
		case 1:
		PIN_TOGGLE(CAR_YELLOW_LED_PIN);
		break;
		case 2:
		PIN_TOGGLE(CAR_GREEN_LED_PIN);
		break;
		case 3:
		PIN_TOGGLE(PED_RED_LED_PIN);
		break;
		case 4:
		PIN_TOGGLE(PED_YELLOW_LED_PIN);
		break;
		case 5:
		PIN_TOGGLE(PED_GREEN_LED_PIN);
		break;
	}
}


void LED_INIT_ALL (void)
{
		LED_INIT(CAR_RED_LED);
		LED_INIT(CAR_YELLOW_LED);
		LED_INIT(CAR_GREEN_LED);
		
		LED_INIT(PED_RED_LED);
		LED_INIT(PED_YELLOW_LED);
		LED_INIT(PED_GREEN_LED);
}

void LED_OFF_ALL(void)
{
	LED_OFF(CAR_RED_LED);
	LED_OFF(CAR_YELLOW_LED);
	LED_OFF(CAR_GREEN_LED);

	LED_OFF(PED_RED_LED);
	LED_OFF(PED_YELLOW_LED);
	LED_OFF(PED_GREEN_LED);
}
