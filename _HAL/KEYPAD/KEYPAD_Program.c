/*
 * KEYPAD_Program.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Mahmoud El Arabi
 */

/* ----------------- Section : includes -----------------*/
#include "KEYPAD_Interface.h"
#include "../../_MCAL/DIO/DIO_Interface.h"


/*Keypad buttons values */
static const u8 btn_values[keypad_rows][keypad_coul]={  {'7','8','9','/'},
														{'4','5','6','*'},
														{'1','2','3','-'},
														{'#','0','=','+'}};

void Keypad_Init(void)
{
	Dio_WriteChannel(PC_2, 1);
	Dio_WriteChannel(PC_3, 1);
	Dio_WriteChannel(PC_4, 1);
	Dio_WriteChannel(PC_5, 1);
}

void Keypad_Get_value(u8 *value) {
    u8 rows[keypad_rows] = {PC_5, PC_4, PC_3, PC_2};
    u8 columns[keypad_coul] = {PD_7, PD_6, PD_5, PD_3};

    // Loop through rows and columns to scan for a pressed key
    u8 row, col;
    for (row = 0; row < keypad_rows; row++) {
        Dio_WriteChannel(rows[row], STD_LOW);
        for (col = 0; col < keypad_coul; col++) {
            if (Dio_ReadChannel(columns[col]) == STD_LOW) {
                *value = btn_values[row][col];
                while (Dio_ReadChannel(columns[col]) == STD_LOW);
                return;
            }
        }
        Dio_WriteChannel(rows[row], STD_HIGH);
    }
    *value = 'T';
}
