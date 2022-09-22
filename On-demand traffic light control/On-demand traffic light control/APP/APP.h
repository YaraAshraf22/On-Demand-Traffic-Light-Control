/*
 * app.h
 *
 * Created: 9/11/2022 1:43:38 AM
 *  Author: HP
 */ 


#ifndef APP_H_
#define APP_H_

uint8_t Traffic_Flag = 0;
enum
{
	RED, YELLOW_OR_GREEN
}Normal_State;


void APP_INIT	(void);
void APP_START	(void);

void PEDESTRIAN_MODE (void);
void NORMAL_MODE (void);

#endif /* APP_H_ */