/*
 * TIMER_CFG.h
 *
 * Created: 9/13/2022 4:14:30 AM
 *  Author: HP
 */ 


#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

//TIMER 0 CFG

#define TIMER0_MODE					NORMAL
#define TIMER0_SOURCE				_1024

//FOR PRESCALER 1024 AND 5 SECOND DELAY
/*
tick time=1024/1M
max delay=1.024*2^8=0.262144
NOVF=ceil[5s/1.024ms]=20
timer init value= 2^8 -[(5/1.024ms)/20]=12*/

#define TIMER0_NUM_OVFS_5s		20
#define TIMER0_INITAL_VALUE		12	

#define TIMER0_NUM_OVFS_1s		4


#endif /* TIMER_CFG_H_ */