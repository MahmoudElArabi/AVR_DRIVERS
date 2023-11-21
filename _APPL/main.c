#include "APP_Config.h"

u8 d1;
u8 d2;

u8 Received = 0;

u16 distanceArray[4] = { 0 };

int main() {
	Port_Init(pins);
	GI_voidEnable();
	lcd4_Init();
	ICU_voidInit();
	SPI_voidInit();

	while (1) {
		for (u8 channel = 0; channel < 4; channel++) {
			switch (channel) {
			case 0:
				Ultra_Sonic_void_trigger(PC_0);
				distanceArray[0] = Ultra_Sonic_Distance_in_cm();
				break;
			case 1:
				Ultra_Sonic_void_trigger(PC_1);
				distanceArray[1] = Ultra_Sonic_Distance_in_cm();
				break;
			case 2:
				Ultra_Sonic_void_trigger(PC_2);
				distanceArray[2] = Ultra_Sonic_Distance_in_cm();
				break;
			case 3:
				Ultra_Sonic_void_trigger(PC_3);
				distanceArray[3] = Ultra_Sonic_Distance_in_cm();
				break;
			}
		}
		lcd4_CLR();
		lcd4_set_cursor(1, 1);
		lcd4_disply_num(distanceArray[0]);
		lcd4_set_cursor(2, 1);
		lcd4_disply_num(distanceArray[1]);
		lcd4_set_cursor(3, 1);
		lcd4_disply_num(distanceArray[2]);
		lcd4_set_cursor(4, 1);
		lcd4_disply_num(distanceArray[3]);
	}
}
