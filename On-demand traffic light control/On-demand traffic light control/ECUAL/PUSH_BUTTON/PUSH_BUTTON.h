/*
 * PUSH_BUTTON.h
 *
 * Created: 9/13/2022 2:29:55 AM
 *  Author: HP
 */ 


#ifndef PUSH_BUTTON_H_
#define PUSH_BUTTON_H_

#include "../../Utilities/STD_TYPES.h"

//BUTTONS
#define PB_INT0   0
#define PB_INT1   1

//Function prototypes
void	PUSH_BUTTON_INIT (uint8_t);
uint8_t		PUSH_BUTTON_READ (uint8_t);

#endif /* PUSH_BUTTON_H_ */