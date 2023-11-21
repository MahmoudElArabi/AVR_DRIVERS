#include "APP_Config.h"

u8 d1;
u8 d2;

u8 Received = 0;

int main() {
	Port_Init(pins);
	GI_voidEnable();
	lcd4_Init();
	ICU_voidInit();
	SPI_voidInit();

	Dio_WriteChannel(PA_1, 1);
	Dio_WriteChannel(PA_4, 0);

	while (1)
    {
    	Ultra_Sonic_void_trigger(PC_0);
    	d1 = Ultra_Sonic_Distance_in_cm();

    	if( (d1 < 20) && (d2 > 20) )
    	{
    		Dio_WriteChannel(PA_4, 1);
    		Dio_WriteChannel(PA_1, 0);
    		do
    		{
    			SPI_voidTranseive(0x66, &Received);
    		}while (GET_BIT(_PINB, 4) == 0);
    		Dio_WriteChannel(PA_1, 1);
    		Dio_WriteChannel(PA_4, 0);
    	}
    	if( (d1 < 20) && (d2 < 20) )
			{
				Dio_WriteChannel(PA_4, 1);
				Dio_WriteChannel(PA_1, 0);
				do
				{
					SPI_voidTranseive(0x77, &Received);
				}while (GET_BIT(_PINB, 4) == 0);
				Dio_WriteChannel(PA_1, 1);
				Dio_WriteChannel(PA_4, 0);
			}
    }
}
