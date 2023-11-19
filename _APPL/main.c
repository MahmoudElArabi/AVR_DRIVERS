#include "APP_Config.h"
#include "../_MCAL/TIMER0/TMR0_Registers.h"

void toggle_led1();
void toggle_led2();
void toggle_led3();
void toggle_led4();
void toggle_led5();

int main() {
	Port_Init(pins);
	GI_voidEnable();

	Task_Creat(0, 50, toggle_led1, 50);
	Task_Creat(0, 70, toggle_led2, 100);
	Task_Creat(2, 110, toggle_led3, 150);
	Task_Creat(2, 150, toggle_led4, 100);
	Task_Creat(4, 200, toggle_led5, 150);

	Task_Creat(5,0, NULL ,0);
	Scheduler_Start();

    while (1)
    {

    }
}


void toggle_led1() {
    Dio_FlipChannel(PB_0);
}

void toggle_led2() {
    Dio_FlipChannel(PB_1);
}

void toggle_led3() {
    Dio_FlipChannel(PB_2);
}

void toggle_led4() {
    Dio_FlipChannel(PB_3);
}

void toggle_led5() {
    Dio_FlipChannel(PB_4);
}
