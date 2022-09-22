/*
 * EXT_INTERRUPT.c
 *
 * Created: 9/13/2022 2:23:49 AM
 *  Author: HP
 */ 

#include "EXT_INTERRUPT.h"
#include "../../Utilities/BIT_MATH.h"
#include "../REGISTERS.h"

void EXT_INT_0_INIT_RISING_EDGE (void)
{
	SET_BIT(MCUCR,0);        //Interrupt on Rising edge
	SET_BIT(MCUCR,1);
	
}