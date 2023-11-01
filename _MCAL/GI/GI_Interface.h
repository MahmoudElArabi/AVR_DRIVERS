/*
 * GI_Interface.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MCAL_GI_GI_INTERFACE_H_
#define MCAL_GI_GI_INTERFACE_H_

/* ----------------- Section : Software Interfaces Declaration -----------------*/

/**
 * GI_voidEnable : This function to Enable the General/Global Interrupt
 * @param	void
 * @return	void
 */
void GI_voidEnable(void);

/**
 * GI_voidEnable : This function to Disable the General/Global Interrupt
 * @param	void
 * @return	void
 */
void GI_voidDisable(void);

#endif /* MCAL_GI_GI_INTERFACE_H_ */
