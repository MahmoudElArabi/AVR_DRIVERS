/*
 * DIO.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include "../../MY_LIBS/BIT_MATH.h"
#include "../../MY_LIBS/STD_TYPES.h"

#define PORT_MAX_PIN_ID 32

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

typedef enum {
	STD_IN,
	STD_OUT
}Dio_DirectionType;

typedef u8 Dio_PortLevelType;

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);

//Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);
//void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level);
#endif /* MCAL_DIO_DIO_H_ */
