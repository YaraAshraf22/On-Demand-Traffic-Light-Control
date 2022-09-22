/*
 * LED.h
 *
 * Created: 9/13/2022 2:29:05 AM
 *  Author: HP
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../Utilities/STD_TYPES.h"

//Macros
//Traffic light LEDS
#define CAR_RED_LED		0
#define CAR_YELLOW_LED	1
#define CAR_GREEN_LED   2

//Pedestrian LEDS
#define PED_RED_LED		3
#define PED_YELLOW_LED	4
#define PED_GREEN_LED   5

// Prototypes
void LED_INIT   (uint8_t);
void LED_ON     (uint8_t);
void LED_OFF    (uint8_t);
void LED_TOGGLE (uint8_t);


void LED_INIT_ALL (void);
void LED_OFF_ALL(void);

#endif /* LED_H_ */