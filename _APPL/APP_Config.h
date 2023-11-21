/*
 * main_h.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef MAIN_H_H_
#define MAIN_H_H_

/* ----------------- Section : includes -----------------*/
#include <util/delay.h>

#include "../_MY_LIBS/BIT_MATH.h"
#include "../_MY_LIBS/STD_TYPES.h"

#include "../_HAL/7SEGMENTS/7SEG_Interface.h"
#include "../_HAL/DCMotor/DCM_Interface.h"
#include "../_HAL/KEYPAD/KEYPAD_Interface.h"
#include "../_HAL/LCD/LCD_Interface.h"
#include "../_HAL/SERVO/SRVM_Interface.h"
#include "../_HAL/EXT_EEPROM/EXT_EEPROM_Interface.h"
#include "../_HAL/Shceduler/scheduler.h"
#include "../_HAL/ULTRA_SONIC/ULTRA_SONIC.h"

#include "../_MCAL/DIO/DIO_Registers.h"
#include "../_MCAL/DIO/DIO_Interface.h"
#include "../_MCAL/PORT/PORT_Interface.h"
#include "../_MCAL/EXTI/EXTI_Interface.h"
#include "../_MCAL/GI/GI_Interface.h"
#include "../_MCAL/ADC/ADC_Interface.h"
#include "../_MCAL/TIMER0/TMR0_Interface.h"
#include "../_MCAL/TIMER1/TMR1_Interface.h"
#include "../_MCAL/TIMER2/TMR2_Interface.h"
#include "../_MCAL/SPI/SPI_interface.h"
//#include "../_MCAL/SPI2/SPI_int.h"
#include "../_MCAL/UART/UART_Interface.h"
#include "../_MCAL/TWI/TWI_Interface.h"
#include "../_MCAL/WDT/WDT_Interface.h"
#include "../_MCAL/HICU/ICU_Interface.h"

/* ----------------- Section : PORT Configuration -----------------*/
Pin_ConfigType pins[] =	{
/** PORT A **/
//			{Dio_PORTA, pin_0, STD_OUT},	// ADC0
			{Dio_PORTA, pin_1, STD_OUT},	// ADC1
//			{Dio_PORTA, pin_2, STD_OUT},	// ADC2
//			{Dio_PORTA, pin_3, STD_OUT},	// ADC3
			{Dio_PORTA, pin_4, STD_OUT},	// ADC4
//			{Dio_PORTA, pin_5, STD_OUT},	// ADC5
//			{Dio_PORTA, pin_6, STD_OUT},	// ADC6
//			{Dio_PORTA, pin_7, STD_OUT},	// ADC7
/** PORT B **/
//			{Dio_PORTB, pin_0, STD_OUT},	// XCK/T0
//			{Dio_PORTB, pin_1, STD_OUT},	// T1
//			{Dio_PORTB, pin_2, STD_OUT},	// INT2/AIN0
//			{Dio_PORTB, pin_3, STD_OUT},	// OC0/AIN1
//			{Dio_PORTB, pin_4, STD_OUT},	// SS
//			{Dio_PORTB, pin_5, STD_OUT},	// MOSI
			{Dio_PORTB, pin_6, STD_OUT},	// MISO
//			{Dio_PORTB, pin_7, STD_OUT},	// SCK
/** PORT C **/
			{Dio_PORTC, pin_0, STD_OUT},	// SCL
			{Dio_PORTC, pin_1, STD_OUT},	// SDA
			{Dio_PORTC, pin_2, STD_OUT},	// SDA
			{Dio_PORTC, pin_3, STD_OUT},	// TMS
//			{Dio_PORTC, pin_4, STD_OUT},	// TDO
//			{Dio_PORTC, pin_5, STD_OUT},	// TDI
//			{Dio_PORTC, pin_6, STD_OUT},	// TOSC1
//			{Dio_PORTC, pin_7, STD_OUT},	// TOSC2
/** PORT D **/
//			{Dio_PORTD, pin_0, STD_OUT},	// RXD
//			{Dio_PORTD, pin_1, STD_OUT},	// TXD
//			{Dio_PORTD, pin_2, STD_OUT},	// INT0
//			{Dio_PORTD, pin_3, STD_OUT},	// INT1
//			{Dio_PORTD, pin_4, STD_OUT},	// OC1B
//			{Dio_PORTD, pin_5, STD_OUT},	// OC1A
//			{Dio_PORTD, pin_6, STD_OUT},	// ICP
//			{Dio_PORTD, pin_7, STD_OUT},	// OC2

/*************** 7_Segment ***************/
//			{Dio_PORTB, pin_0, STD_OUT },
//			{Dio_PORTB, pin_1, STD_OUT },
//			{Dio_PORTB, pin_2, STD_OUT },
//			{Dio_PORTB, pin_4, STD_OUT },
//			{Dio_PORTA, pin_2, STD_OUT },
//			{Dio_PORTA, pin_3, STD_OUT },
//			{Dio_PORTB, pin_5, STD_OUT },
//			{Dio_PORTB, pin_6, STD_OUT },

/*************** LCD 4 BITS ***************/
			{Dio_PORTB, pin_0, STD_OUT },	//D4
			{Dio_PORTB, pin_1, STD_OUT },	//D5
			{Dio_PORTB, pin_2, STD_OUT },	//D6
			{Dio_PORTB, pin_3, STD_OUT },	//D7
			{Dio_PORTA, pin_2, STD_OUT },	//EN
			{Dio_PORTA, pin_3, STD_OUT },	//RS

/*************** KEYPAD ***************/
//			{Dio_PORTC, pin_0, STD_OUT},	// Row 1
//			{Dio_PORTC, pin_1, STD_OUT},	// Row 2
//			{Dio_PORTC, pin_2, STD_OUT},	// Row 3
//			{Dio_PORTC, pin_3, STD_OUT},	// Row 4
//			{Dio_PORTC, pin_4, STD_IN},		// Column 1
//			{Dio_PORTC, pin_5, STD_IN},		// Column 2
//			{Dio_PORTC, pin_6, STD_IN},		// Column 3
//			{Dio_PORTC, pin_7, STD_IN},		// Column 4

/*************** Terminate ***************/
			{-1}
};

#endif /* MAIN_H_H_ */
