/*
 * PORT.h
 *
 *  Created on: Oct 20, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_PORT_PORT_H_
#define MCAL_PORT_PORT_H_

#include "../DIO/DIO.h"



typedef struct {
		Dio_PortType Port;
		Dio_PinType Pin;
		Dio_DirectionType Direction;
}Pin_ConfigType;

void Port_Init (Pin_ConfigType *pins_cfg);
void Port_SetPinDirection (Dio_ChannelType Pin,Dio_DirectionType Direction);

#endif /* MCAL_PORT_PORT_H_ */