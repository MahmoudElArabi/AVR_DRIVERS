/*
 * DIO.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Mahmoud El Arabi
 */

/* ----------------- Section : includes -----------------*/

#include "DIO_Interfance.h"

/* ----------------- Section : Software Interfaces Implementation -----------------*/

/**
 * Dio_WriteChannel : This function writes the level --> if 0 then 0V and if 1 then 5V
 * @param	1- ChannelId 	-> to choose the right PIN  EX: (PA_0) refers to PIN0 in PORTA
 * 			2- Level		-> to choose the level on that PIN	(0 or 1)
 * @return	void
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	switch(ChannelId/8)
	{
	case Dio_PORTA:
		if(Level == 1)
			SET_BIT(_PORTA, ChannelId);
		else
			CLR_BIT(_PORTA, ChannelId);
		break;
	case Dio_PORTB:
		if(Level == 1)
			SET_BIT(_PORTB, ChannelId % 8);
		else
			CLR_BIT(_PORTB, ChannelId % 8);
		break;
	case Dio_PORTC:
		if(Level == 1)
			SET_BIT(_PORTC, ChannelId % 8);
		else
			CLR_BIT(_PORTC, ChannelId % 8);
		break;
	case Dio_PORTD:
		if(Level == 1)
			SET_BIT(_PORTD, ChannelId % 8);
		else
			CLR_BIT(_PORTD, ChannelId % 8);
		break;
	default:	break;
	}
}

/**
 * Dio_ReadChannel : This function READ the level on a PIN
 * @param	1- ChannelId 	-> to choose the PIN to read from  EX: (PA_0) refers to PIN0 in PORTA
 * @return	Dio_LevelType 	-> if 1 then the level id HIGH, if 0 then the level id LOW
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	Dio_LevelType ret = STD_LOW;
	switch(ChannelId /8)
	{
	case Dio_PORTA:
		ret = GET_BIT(_PINA, ChannelId);
		break;
	case Dio_PORTB:
		ret = GET_BIT(_PINB, ChannelId %8);
		break;
	case Dio_PORTC:
		ret = GET_BIT(_PINC, ChannelId % 8);
		break;
	case Dio_PORTD:
		ret = GET_BIT(_PIND, ChannelId % 8);
		break;
	default:	break;
	}
	return ret;
}

/**
 * Dio_FlipChannel : This function toggle the level on a PIN
 * @param	1- ChannelId 	-> to choose the PIN to toggle its level  EX: (PA_0) refers to PIN0 in PORTA
 * @return	Dio_LevelType 	-> return the level of the pin after toggling --> 1 for level HIGH,  0 for level LOW
 */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	Dio_LevelType ret = STD_LOW;
	switch(ChannelId / 8)
	{
	case Dio_PORTA:
		TOG_BIT(_PORTA, ChannelId);
		ret = GET_BIT(_PORTA, ChannelId);
		break;
	case Dio_PORTB:
		TOG_BIT(_PORTB, ChannelId % 8);
		ret = GET_BIT(_PORTB, ChannelId %8);
		break;
	case Dio_PORTC:
		TOG_BIT(_PORTC, ChannelId % 8);
		ret = GET_BIT(_PORTC, ChannelId % 8);
		break;
	case Dio_PORTD:
		TOG_BIT(_PORTD, ChannelId % 8);
		ret = GET_BIT(_PORTD, ChannelId % 8);
		break;
	default:	break;
	}
	return ret;
}

/**
 * Dio_ReadPort : This function read the level on a PORT
 * @param	1- PortId 	-> to choose the PORT to read its level  EX: (Dio_PORTA) refers to PORTA
 * @return	Dio_PortLevelType 	-> return the level of the PORT
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	Dio_PortLevelType ret = 0;
	switch(PortId)
	{
	case Dio_PORTA:
		ret = _PINA;
		break;
	case Dio_PORTB:
		ret = _PINB;
		break;
	case Dio_PORTC:
		ret = _PINC;
		break;
	case Dio_PORTD:
		ret =_PIND;
			break;
	}
	return ret;
}

/**
 * Dio_WritePort : This function Write a level on a whole PORT (8 pins)
 * @param	1- PortId 	-> to choose the PORT to Write level on it  EX: (Dio_PORTA) refers to PORTA
 * 			2- Level 	-> the level to write 	Ex : (255) to write 1111 1111
 * @return	Dio_LevelType 	-> return the level of the PORT
 */
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level)
{
	switch(PortId)
		{
		case Dio_PORTA:
			_PORTA = Level;
			break;
		case Dio_PORTB:
			_PORTB = Level;
			break;
		case Dio_PORTC:
			_PORTC = Level;
			break;
		case Dio_PORTD:
			_PORTD = Level;
			break;
		}
}
