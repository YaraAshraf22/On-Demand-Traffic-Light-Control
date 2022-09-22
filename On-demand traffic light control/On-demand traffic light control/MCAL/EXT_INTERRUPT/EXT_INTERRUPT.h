/*
 * EXT_INTERRUPT.h
 *
 * Created: 9/13/2022 2:24:22 AM
 *  Author: HP
 */ 


#ifndef EXT_INTERRUPT_H_
#define EXT_INTERRUPT_H_

#include "../../Utilities/BIT_MATH.h"
#include "../REGISTERS.h"

void EXT_INT_0_INIT_RISING_EDGE (void);	//PD2 

#define EXT_INT_0_ENABLE		SET_BIT(GICR,6)         
#define EXT_INT_0_DISABLE		CLR_BIT(GICR,6)


#endif /* EXT_INTERRUPT_H_ */