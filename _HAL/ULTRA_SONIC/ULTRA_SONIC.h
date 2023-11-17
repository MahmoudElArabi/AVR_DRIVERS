/*
 * ULTRA_SONIC.h
 *
 *  Created on: Nov 17, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef HAL_ULTRA_SONIC_ULTRA_SONIC_H_
#define HAL_ULTRA_SONIC_ULTRA_SONIC_H_

#include "../../_MY_LIBS/STD_TYPES.h"

void Ultra_Sonic_void_trigger(u8 channel);
u16 Ultra_Sonic_Distance_in_cm(void);

#endif /* HAL_ULTRA_SONIC_ULTRA_SONIC_H_ */
