/*
 * EXTI_Interface.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

/* ----------------- Section : includes -----------------*/

#include "../PORT/PORT_Interface.h"

/* ----------------- Section : Macro Declarations -----------------*/

//External interrupt Modes
#define RISING_EDGE		0
#define FALLING_EDGE	1
#define LOW_LEVEL		2
#define LOGICAL_CHANGE	3

// Interrupt INTx source
#define EXTI_INT0		0
#define EXTI_INT1		1
#define EXTI_INT2		2

// Interrupt Control (GICR)  pins :  External Interrupt Request 0, 1, 2
#define INT0			6
#define INT1			7
#define INT2			5

// MCUCR Register pins : Interrupt 0, 1 Sense Control
#define ISC00			0
#define ISC01			1
#define ISC10			2
#define ISC11			3

// MCUCSR Register pins : Interrupt 2 Sense Control
#define ISC2			6


/* ----------------- Section : Software Interfaces Declarations -----------------*/

/**
 * EXTI_voidInit : This function initialize the External interrupt "EXTI0, EXTI1 or EXTI2" Mode to be:
 * 1- Rising Edge	2- Falling Edge		3- Logical Change	4- Low Level
 * @param	1- copy_u8InterruptSource 	-> External interrupt source (EXTI_INTx where x = (0, 1 or 2))
 * 			2- copy_u8SenseControl		-> External interrupt Modes (RISING_EDGE, FALLING_EDGE, LOW_LEVEL or LOGICAL_CHANGE)
 * @return	void
 */
void EXTI_voidInit(u8 copy_u8InterruptSource , u8 copy_u8SenseControl);

/**
 * EXTI_voidEnable : This function enable the External interrupt "EXTI0, EXTI1 or EXTI2"
 * @param	1- copy_u8InterruptSource 	-> External interrupt source (EXTI_INTx where x = (0, 1 or 2))
 * @return	void
 */
void EXTI_voidEnable(u8 copy_u8InterruptSource);

/**
 * EXTI_voidDisable : This function disable the External interrupt "EXTI0, EXTI1 or EXTI2"
 * @param	1- copy_u8InterruptSource 	-> External interrupt source (EXTI_INTx where x = (0, 1 or 2))
 * @return	void
 */
void EXTI_voidDisable(u8 copy_u8InterruptSource);

//CallBack Functions Declarations for EXTI0, 1, 2
void EXTI0_voidSendCallBack(void (*PtrF0)(void));
void EXTI1_voidSendCallBack(void (*PtrF1)(void));
void EXTI2_voidSendCallBack(void (*PtrF2)(void));

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
