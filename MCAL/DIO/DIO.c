/*
 * DIO.c
 *
 *  Created on: Oct 20, 2023
 *      Author: Mahmoud El Arabi
 */


#include "DIO.h"

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	switch(ChannelId/8)
	{
	case Dio_PORTA:
		if(Level == 1)
			SET_BIT(PORTA, ChannelId);
		else
			CLR_BIT(PORTA, ChannelId);
		break;
	case Dio_PORTB:
		if(Level == 1)
			SET_BIT(PORTB, ChannelId % 8);
		else
			CLR_BIT(PORTB, ChannelId % 8);
		break;
	case Dio_PORTC:
		if(Level == 1)
			SET_BIT(PORTC, ChannelId % 8);
		else
			CLR_BIT(PORTC, ChannelId % 8);
		break;
	case Dio_PORTD:
		if(Level == 1)
			SET_BIT(PORTD, ChannelId % 8);
		else
			CLR_BIT(PORTD, ChannelId % 8);
		break;
	default:	break;
	}
}

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	Dio_LevelType ret = STD_LOW;
	switch(ChannelId /8)
	{
	case Dio_PORTA:
		ret = GET_BIT(PINA, ChannelId);
		break;
	case Dio_PORTB:
		ret = GET_BIT(PINB, ChannelId %8);
		break;
	case Dio_PORTC:
		ret = GET_BIT(PINC, ChannelId % 8);
		break;
	case Dio_PORTD:
		ret = GET_BIT(PIND, ChannelId % 8);
		break;
	default:	break;
	}
	return ret;
}

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	Dio_LevelType ret = STD_LOW;
	switch(ChannelId / 8)
	{
	case Dio_PORTA:
		TOG_BIT(PORTA, ChannelId);
		ret = GET_BIT(PINA, ChannelId);
		break;
	case Dio_PORTB:
		TOG_BIT(PORTB, ChannelId % 8);
		ret = GET_BIT(PINB, ChannelId %8);
		break;
	case Dio_PORTC:
		TOG_BIT(PORTC, ChannelId % 8);
		ret = GET_BIT(PINC, ChannelId % 8);
		break;
	case Dio_PORTD:
		TOG_BIT(PORTD, ChannelId % 8);
		ret = GET_BIT(PIND, ChannelId % 8);
		break;
	default:	break;
	}
	return ret;
}

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	Dio_PortLevelType ret;
	switch(PortId)
	{
	case Dio_PORTA:
		ret = PINA;
		break;
	case Dio_PORTB:
		ret = PINB;
		break;
	case Dio_PORTC:
		ret = PINC;
		break;
	case Dio_PORTD:
		ret =PIND;
			break;
	}
	return ret;
}

void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level)
{
	switch(PortId)
		{
		case Dio_PORTA:
			PORTA = Level;
			break;
		case Dio_PORTB:
			PORTB = Level;
			break;
		case Dio_PORTC:
			PORTC = Level;
			break;
		case Dio_PORTD:
			PORTD = Level;
			break;
		}
}
