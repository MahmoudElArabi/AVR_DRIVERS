/*
 *  main.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Mahmoud El Arabi
 */

#include "APP_Config.h"
#include "../_MCAL/TIMER0/TMR0_Registers.h"

void toggle_led1();
void toggle_led2();
void toggle_led3();
void toggle_led4();


int main() {
	Port_Init(pins);
	GI_voidEnable();


	TMR0_voidInit();

	OS_voidCreateTask(0,200,0,toggle_led1);
	OS_voidCreateTask(1,200,100,toggle_led2);
	OS_voidCreateTask(2,200,150,toggle_led3);

	OS_voidStartScheduler();

    while (1) {

    }
}


// Task to toggle LED connected to PORTB, Pin 0
void toggle_led1() {
    Dio_FlipChannel(PB_0);
}

// Task to toggle LED connected to PORTB, Pin 1
void toggle_led2() {
    Dio_FlipChannel(PB_1);
}

// Task to toggle LED connected to PORTB, Pin 2
void toggle_led3() {
    Dio_FlipChannel(PB_2);
}

// Task to toggle LED connected to PORTB, Pin 3
void toggle_led4() {
    Dio_FlipChannel(PB_3);
}
