/*
* app.c
*
* Created: 9/11/2022 1:43:51 AM
*  Author: HP
*/

#include "APP.h"

#include "../Utilities/BIT_MATH.h"
#include "../Utilities/STD_TYPES.h"

#include "../MCAL/REGISTERS.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/TIMER/TIMER.h"
#include "../MCAL/EXT_INTERRUPT/EXT_INTERRUPT.h"
#include "../MCAL/EXT_INTERRUPT/INTERRUPT_LIB.h"

#include "../ECUAL/LED/LED.h"
#include "../ECUAL/PUSH_BUTTON/PUSH_BUTTON.h"

#define F_CPU 1000000UL

void APP_INIT	(void)
{
	LED_INIT_ALL();
	TIMER_0_INIT();
	TIMER_2_INIT();
	
	PUSH_BUTTON_INIT (PB_INT0);
	EXT_INT_0_INIT_RISING_EDGE();
	
	LED_OFF_ALL();
	
	EXT_INT_0_ENABLE;
	GLOBAL_INTERRUPT_ENABLE;
	
	LED_ON(PED_RED_LED);
}
void APP_START	(void)
{	
	while (1)
	{	
		NORMAL_MODE ();
	}
	
}

ISR (EXT_INT_0)
{
	
	GLOBAL_INTERRUPT_DISABLE;
	EXT_INT_0_DISABLE;
	
	PEDESTRIAN_MODE ();
	
	EXT_INT_0_ENABLE;
	GLOBAL_INTERRUPT_ENABLE;
}


void NORMAL_MODE (void)
{
	Traffic_Flag = 0;
	
	Normal_State=YELLOW_OR_GREEN;
	//Green on for 5s
	LED_ON(CAR_GREEN_LED);
	TIMER_0_5s_DELAY();
	LED_OFF(CAR_GREEN_LED);
	
	//Yellow blink for 5s
	LED_ON(CAR_YELLOW_LED);
	uint8_t i=0;
	while(i<5)
	{
		if(Traffic_Flag==1)
		{
			LED_OFF(CAR_YELLOW_LED);
			goto END;
		}
		TIMER_0_1s_DELAY();
		LED_TOGGLE(CAR_YELLOW_LED);
		i++;
	}
	
	//Red on for 5s
	Normal_State=RED;
	LED_ON(CAR_RED_LED);
	TIMER_0_5s_DELAY();
	LED_OFF(CAR_RED_LED);
	
	Normal_State=YELLOW_OR_GREEN;
	//Yellow blink for 5s
	LED_ON(CAR_YELLOW_LED);
	
	i=0;
	while(i<5)
	{
		if(Traffic_Flag==1)
		{
			LED_OFF(CAR_YELLOW_LED);
			goto END;
		}
		TIMER_0_1s_DELAY();
		LED_TOGGLE(CAR_YELLOW_LED);
		i++;
		
	}
	
	END:
	Traffic_Flag = 0;
}
void PEDESTRIAN_MODE (void)
{
		Traffic_Flag = 1;

		
		switch(Normal_State)
		{
			case (RED):
			{	//Pedestrian can cross
				LED_ON(CAR_RED_LED);
				
				LED_OFF(PED_RED_LED);
				LED_ON(PED_GREEN_LED);
				TIMER_2_5s_DELAY();

				break;
			}
			case (YELLOW_OR_GREEN):
			{
				//Ped Red 5s
				LED_ON(PED_RED_LED);
				TIMER_2_5s_DELAY();
				LED_OFF(PED_RED_LED);
				
				LED_OFF(CAR_GREEN_LED);
				
				//Both yellow leds blink for 5s
				LED_ON(CAR_YELLOW_LED);
				LED_ON(PED_YELLOW_LED);
				uint8_t i=0;
				while(i<5)
				{
					TIMER_2_1s_DELAY();
					LED_TOGGLE(CAR_YELLOW_LED);
					LED_TOGGLE(PED_YELLOW_LED);
					i++;
				}
				
				LED_ON(CAR_RED_LED);
				LED_ON(PED_GREEN_LED);
				TIMER_2_5s_DELAY();
				//wait until green is on
				break;
			}
		}

		//After normal to pedestrian state transition

		LED_OFF(CAR_RED_LED);
		LED_ON(CAR_YELLOW_LED);
		LED_ON(PED_YELLOW_LED);
		uint8_t i=0;
		while(i<5)
		{
			TIMER_2_1s_DELAY();
			LED_TOGGLE(CAR_YELLOW_LED);
			LED_TOGGLE(PED_YELLOW_LED);
			i++;
		}
		
		LED_OFF(PED_GREEN_LED);
		LED_ON(PED_RED_LED);
		LED_ON(CAR_GREEN_LED);

}