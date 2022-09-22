/*
 * INTERRUPT.h
 *
 * Created: 9/13/2022 3:35:03 AM
 *  Author: HP
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../Utilities/BIT_MATH.h"
#include "../REGISTERS.h"

#define GLOBAL_INTERRUPT_ENABLE		SET_BIT(SREG,7)
#define GLOBAL_INTERRUPT_DISABLE	CLR_BIT(SREG,7)

//External Interrupt Requests
#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2
#define EXT_INT_2 __vector_3

/*
//set global interrupt
#define sei() __asm__ __volatile__ ("sei" ::: "memory")
//clear global interrupt
#define cli() __asm__ __volatile__ ("cli" ::: "memory")*/

//ISR Definition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

#endif /* INTERRUPT_H_ */