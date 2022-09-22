/*
 * BIT_MATH.h
 *
 * Created: 9/11/2022 1:36:32 AM
 *  Author: HP
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)   (reg |= (1<<bit))
#define CLR_BIT(reg,bit)   (reg &= ~(1<<bit))
#define TOG_BIT(reg,bit)   (reg ^= (1<<bit))
#define GET_BIT(reg,bit)   ((reg >> bit)&1)

#endif /* BIT_MATH_H_ */