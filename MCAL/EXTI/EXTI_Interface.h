/*
 * EXTI_Interface.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#include "../PORT/PORT.h"
#include "../GI/GI_Interface.h"


/* Modes */
#define RISING_EDGE		0
#define FALLING_EDGE	1
#define LOW_LEVEL		2
#define LOGICAL_CHANGE	3

#define EXTI_INT0		0
#define EXTI_INT1		1
#define EXTI_INT2		2

/* Interrupt Control (GICR) */
#define INT0	6
#define INT1	7
#define INT2	5

//#define INTF1 	7
//#define INTF0 	6
//#define INTF2 	5

/* MCUCR Register */
#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3

/* MCUCSR Register */
#define ISC2	6

void EXTI_voidInit(u8 copy_u8InterruptSource , u8 copy_u8SenseControl);
void EXTI_voidEnable(u8 copy_u8InterruptSource);
void EXTI_voidDisable(u8 copy_u8InterruptSource);

void EXTRI_voidSetCallBackINT1(void (*ptrToFunction)(void));

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
