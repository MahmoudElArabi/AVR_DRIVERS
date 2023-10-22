/*
 * GI_program.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Mahmoud El Arabi
 */


#include "GI_Interface.h"
#include "GI_Register.h"

void GI_voidEnable(void)
{
	SET_BIT(_SREG, GLE);
}

void GI_voidDisable(void)
{
	CLR_BIT(_SREG, GLE);
}
