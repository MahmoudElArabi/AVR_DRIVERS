/*
 * DIO.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_DIO_DIO_INTERFANCE_H_
#define MCAL_DIO_DIO_INTERFANCE_H_

/* ----------------- Section : includes -----------------*/

#include "../../MY_LIBS/BIT_MATH.h"
#include "../../MY_LIBS/STD_TYPES.h"
#include "DIO_Registers.h"

/* ----------------- Section : Macro Declarations -----------------*/

#define PORT_MAX_PIN_ID 32


/* ----------------- Section : Data types Declarations -----------------*/

// All channels --> example : PA_0 refer to PORTA PIN0
typedef enum {
	PA_0,
	PA_1,
	PA_2,
	PA_3,
	PA_4,
	PA_5,
	PA_6,
	PA_7,
	PB_0,
	PB_1,
	PB_2,
	PB_3,
	PB_4,
	PB_5,
	PB_6,
	PB_7,
	PC_0,
	PC_1,
	PC_2,
	PC_3,
	PC_4,
	PC_5,
	PC_6,
	PC_7,
	PD_0,
	PD_1,
	PD_2,
	PD_3,
	PD_4,
	PD_5,
	PD_6,
	PD_7,
}Dio_ChannelType;

// Pin Level if STD_LOW the pin is 0V  and STD_HIGH is 5V
typedef enum {
	STD_LOW,
	STD_HIGH
}Dio_LevelType;

typedef enum {
	Dio_PORTA,
	Dio_PORTB,
	Dio_PORTC,
	Dio_PORTD,
}Dio_PortType;

typedef enum {
	pin_0,
	pin_1,
	pin_2,
	pin_3,
	pin_4,
	pin_5,
	pin_6,
	pin_7
}Dio_PinType;

// Pin Direction if STD_IN the pin is input and STD_OUT the pin is output
typedef enum {
	STD_IN,
	STD_OUT
}Dio_DirectionType;

typedef u8 Dio_PortLevelType;


/* ----------------- Section : Software Interfaces Declaration -----------------*/

/**
 * Dio_WriteChannel : This function writes the level on a PIN
 * @param	1- ChannelId 	-> to choose the PIN to write on 	-->  EX: (PA_0) refers to PIN0 in PORTA
 * 			2- Level		-> to choose the level to write on that PIN	(0 for 0V and 1 for 5V)
 * @return	void
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/**
 * Dio_ReadChannel : This function READ the level on a PIN
 * @param	1- ChannelId 	-> to choose the PIN to read from  EX: (PA_0) refers to PIN0 in PORTA
 * @return	Dio_LevelType 	-> return the level of the pin --> 1 for level HIGH,  0 for level LOW
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/**
 * Dio_FlipChannel : This function toggle the level on a PIN
 * @param	1- ChannelId 	-> to choose the PIN to toggle its level  EX: (PA_0) refers to PIN0 in PORTA
 * @return	Dio_LevelType 	-> return the level of the pin after toggling --> 1 for level HIGH,  0 for level LOW
 */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

/**
 * Dio_ReadPort : This function read the level on a PORT
 * @param	1- PortId 	-> to choose the PORT to read its level  EX: (Dio_PORTA) refers to PORTA
 * @return	Dio_PortLevelType 	-> return the level of the PORT
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/**
 * Dio_WritePort : This function Write a level on a whole PORT (8 pins)
 * @param	1- PortId 	-> to choose the PORT to Write level on it  EX: (Dio_PORTA) refers to PORTA
 * 			2- Level 	-> the level to write 	Ex : (255) to write 1111 1111
 * @return	Dio_LevelType 	-> return the level of the PORT
 */
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);


#endif /* MCAL_DIO_DIO_INTERFANCE_H_ */
