/*
 * GI_program.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Mahmoud El Arabi
 */

/* ----------------- Section : includes -----------------*/

#include "GI_Interface.h"
#include "GI_Registers.h"


/* ----------------- Section : Software Interfaces Implementation -----------------*/

/**
 * GI_voidEnable : This function to Enable the General/Global Interrupt
 * @param	void
 * @return	void
 */
void GI_voidEnable(void)
{
	SET_BIT(_SREG, GLE);
}

/**
 * GI_voidEnable : This function to Disable the General/Global Interrupt
 * @param	void
 * @return	void
 */
void GI_voidDisable(void)
{
	CLR_BIT(_SREG, GLE);
}
