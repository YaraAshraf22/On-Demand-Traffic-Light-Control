/*
 * TIMER.c
 *
 * Created: 9/13/2022 2:28:21 AM
 *  Author: HP
 */ 

#include "TIMER.h"
#include "TIMER_CFG.h"

#include "../../Utilities/BIT_MATH.h"
#include "../../Utilities/STD_TYPES.h"
#include "../REGISTERS.h"
#include "../DIO/DIO.h"
#include <math.h>


//ENABLE TIMER0 OVERFLOW INTERRUPT
void TIMER_0_INT_TOV			(void)
{
	SET_BIT(SREG,7);			// ENABLE GLOBAL INT
	SET_BIT(TIMSK,0);			// ENABLE TIMER0 TOV INT
}

void TIMER_0_INIT			(void)		//	timer 0 mode
{
	#if  TIMER0_MODE == NORMAL
	CLR_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);
	#elif TIMER0_MODE == CTC
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	#elif TIMER0_MODE == PWM
	SET_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	#elif TIMER0_MODE == FPWM
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	#endif
}

void TIMER_0_START		(void) //CLK source
{
	#if  TIMER0_SOURCE == NO_PRESCALING
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
	#elif TIMER0_SOURCE == _8
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
	#elif TIMER0_SOURCE == _64
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
	#elif TIMER0_SOURCE == _256
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	#elif TIMER0_SOURCE == _1024
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	#endif	
}

void TIMER_0_STOP		(void)
{
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
}




	//every time overflow occurs f_clk=1MHz
	//clk_cycles/sec = 1M/f_prescaler= 1M/1024= 977 (cycles/sec)
	//overflows/sec = (clk_cycles/sec)/255 = 977/256=4
	//5 seconds>> 4*5=20 OVF
	
	
void TIMER_0_5s_DELAY		(void)
{
	uint8_t number_of_overflows=0;
	TCNT0=TIMER0_INITAL_VALUE;
	TIMER_0_START();
	SET_BIT(TIFR,0);	//CLEAR TIMER OVF FLAG	
	
	while(number_of_overflows<=TIMER0_NUM_OVFS_5s)
	{
		while(!GET_BIT(TIFR,0));//check for OVF Flag
	
		SET_BIT(TIFR,0);			//Clear flag
		number_of_overflows++;
	}
	TIMER_0_STOP();
}


void TIMER_0_1s_DELAY		(void)
{
	uint8_t number_of_overflows=0;
	TCNT0=TIMER0_INITAL_VALUE;
	TIMER_0_START();
	SET_BIT(TIFR,0);
	
	while(number_of_overflows<=TIMER0_NUM_OVFS_1s)
	{
	
		while(!GET_BIT(TIFR,0));//check for OVF Flag
		
		SET_BIT(TIFR,0);			//Clear flag
		number_of_overflows++;
	}
	
	TIMER_0_STOP();
	
}


//TIMER 2

void TIMER_2_INIT			(void)
{
	//Normal Mode
	CLR_BIT(TCCR2,6);
	CLR_BIT(TCCR2,3);
}
void TIMER_2_START			(void)
{
	//PRESCALER 1024
	SET_BIT(TCCR2,0);
	SET_BIT(TCCR2,1);
	SET_BIT(TCCR2,2);
}
void TIMER_2_STOP			(void)
{
	CLR_BIT(TCCR2,0);
	CLR_BIT(TCCR2,1);
	CLR_BIT(TCCR2,2);
}


void TIMER_2_5s_DELAY		(void)
{
	uint8_t number_of_overflows=0;
	TCNT2=TIMER0_INITAL_VALUE;
	TIMER_2_START();
	SET_BIT(TIFR,6);	//CLEAR TIMER OVF FLAG
	
	while(number_of_overflows<=TIMER0_NUM_OVFS_5s)
	{
		while(!GET_BIT(TIFR,6));//check for OVF Flag
		SET_BIT(TIFR,6);			//Clear flag
		number_of_overflows++;
	}
	TIMER_2_STOP();
}


void TIMER_2_1s_DELAY		(void)
{
	uint8_t number_of_overflows=0;
	TCNT2=TIMER0_INITAL_VALUE;
	TIMER_2_START();
	SET_BIT(TIFR,6);
	
	while(number_of_overflows<=TIMER0_NUM_OVFS_1s)
	{
		while(!GET_BIT(TIFR,6));//check for OVF Flag
		SET_BIT(TIFR,6);			//Clear flag
		number_of_overflows++;
	}
	
	TIMER_2_STOP();
}