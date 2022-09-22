/*
 * TIMER.h
 *
 * Created: 9/13/2022 2:28:36 AM
 *  Author: HP
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/STD_TYPES.h"

//Timer 0 Modes
#define NORMAL 		0
#define CTC			1
#define PWM			2
#define FPWM		3

//TIMER 0 CLK Source
#define TIMER_OFF						0
#define NO_PRESCALING					1
#define _8								2
#define _64								3
#define _256							4
#define _1024							5


//TIMER 0 PROTOTYPES


void TIMER_0_INIT			(void);
void TIMER_0_INT_TOV		(void);

void TIMER_0_START			(void);
void TIMER_0_1s_DELAY		(void);
void TIMER_0_5s_DELAY		(void);
void TIMER_0_STOP			(void);

//TIMER 2
void TIMER_2_INIT			(void);
void TIMER_2_START			(void);
void TIMER_2_STOP			(void);

void TIMER_2_1s_DELAY		(void);
void TIMER_2_5s_DELAY		(void);

#endif /* TIMER_H_ */