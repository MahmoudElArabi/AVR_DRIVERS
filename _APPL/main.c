
#include "APP_Config.h"
#include "../_MCAL/SPI/SPI_Registers.h"

//SPI Bytes
#define CHECK_HAND				0x56
#define COND_STOP 				0x66
#define COND_AvoidToL 			0x77
#define COND_AvoidToR			0x88
#define STATE_AUTO_PARK 		0x99
#define STATE_AVOID_lane_isR	0x34
#define STATE_AVOID_lane_isL	0x35

//AutoPark
#define STOP					0x15
#define STEAR_RIGHT				0x16
#define STEAR_LEFT				0x17
#define BACKWARD				0x18
#define FORWARD					0x19

//States
#define AutoParkState			1
#define OpsAvoid_rightlane		2
#define OpsAvoid_leftlane		3

//PINS
#define F_US_TRIGGER			PC_0
#define F_US_ECH_SWI			PC_4
#define F_US_VCC_SWI			PA_4
#define L_US_TRIGGER			PC_1
#define L_US_ECH_SWI			PC_5
#define L_US_VCC_SWI			PA_5
#define B_US_TRIGGER			PC_2
#define B_US_ECH_SWI			PC_6
#define B_US_VCC_SWI			PA_6
#define R_US_TRIGGER			PC_3
#define R_US_ECH_SWI			PC_7
#define R_US_VCC_SWI			PA_7
#define EXT_INT_PIN				PA_1

u8 RUN_STATE = 0;
u8 received  = 0;
u8 RightFlag, LeftFlag, Auto_R_Flag, Auto_B_Flag;
u16 DistanceForward , DistanceLeft, DistanceBack, DistanceRight;

void ACT_SPI(u8 Copy_u8Recrived);
void lane_action(u8 X_lane);
void AutoPark_action(void);
static void stop_after_back_cm (u8 distance);


int main()
{
	Port_Init(pins);
	GI_voidEnable();
	lcd4_Init();
	ICU_voidInit();
	SPI_voidInit();
	lcd4_Init();

	Dio_WriteChannel(EXT_INT_PIN, 1);

	_delay_us(200);
	SPI_voidTransmit_Async(0, ACT_SPI);

	while(1)
	{
		switch(RUN_STATE)
		{
			case OpsAvoid_rightlane:
				lane_action(OpsAvoid_rightlane);
				break;
			case OpsAvoid_leftlane:
				lane_action(OpsAvoid_leftlane);
				break;
			case AutoParkState:
				AutoPark_action();
				break;
			default:
				break;
		}

	}
}

void ACT_SPI(u8 Copy_u8Recrived)
{
	lcd4_CLR();
	lcd4_disply_num(Copy_u8Recrived);

	switch(Copy_u8Recrived)
	{
		case STATE_AUTO_PARK:
			RUN_STATE = AutoParkState;
			CLR_BIT(_SPCR, 7);		// SPI INT DISABE
			break;
		case STATE_AVOID_lane_isR:
			RUN_STATE = OpsAvoid_rightlane;
			break;
		case STATE_AVOID_lane_isL:
			RUN_STATE = OpsAvoid_leftlane;
			break;
		default: break;
	}
}

void lane_action(u8 X_lane)
{
	switch (X_lane)
	{
		case OpsAvoid_rightlane:
			if(RightFlag == 0)
			{
				Dio_WriteChannel(F_US_ECH_SWI, 1);	// switch ON
				Dio_WriteChannel(F_US_VCC_SWI, 1);
				Dio_WriteChannel(L_US_ECH_SWI, 1);
				Dio_WriteChannel(L_US_VCC_SWI, 1);
				_delay_ms(500);
				RightFlag = 1;
			}
			Ultra_Sonic_void_trigger(F_US_TRIGGER);
			DistanceForward = Ultra_Sonic_Distance_in_cm();
			Ultra_Sonic_void_trigger(L_US_TRIGGER);
			DistanceLeft = Ultra_Sonic_Distance_in_cm();

			lcd4_set_cursor(4, 1);
			lcd4_disply_num(DistanceForward);
			lcd4_disply_char('_');
			lcd4_disply_num(DistanceLeft);

			// CONDITION 1 --> Emergency Stop
			if(DistanceForward < 20 && DistanceLeft < 20)
			{
				RUN_STATE = 0;
				Dio_WriteChannel(F_US_ECH_SWI, 0);	// switch OFF
				Dio_WriteChannel(F_US_VCC_SWI, 0);
				Dio_WriteChannel(L_US_ECH_SWI, 0);
				Dio_WriteChannel(L_US_VCC_SWI, 0);
				RightFlag = 0;
				CLR_BIT(_SPCR, 7);		// SPI INT DISABE
				Dio_WriteChannel(EXT_INT_PIN, 0);	//Make an EXTINT to master
				do{
					SPI_voidTranseive(COND_STOP, &received);
				}
				while(received != CHECK_HAND);
				SET_BIT(_SPCR, 7);		// SPI INT ENABE
				Dio_WriteChannel(EXT_INT_PIN, 1);
			}

			// CONDITION 2 --> Avoid the Car to left
			if(DistanceForward < 20 && DistanceLeft > 50)
			{
				RUN_STATE = 0;
				RightFlag = 0;
				Dio_WriteChannel(F_US_ECH_SWI, 0);	// switch OFF
				Dio_WriteChannel(F_US_VCC_SWI, 0);
				Dio_WriteChannel(L_US_ECH_SWI, 0);
				Dio_WriteChannel(L_US_VCC_SWI, 0);
				CLR_BIT(_SPCR, 7);			// SPI INT DISABE
				Dio_WriteChannel(EXT_INT_PIN, 0);	//Make an EXTINT to master
				do{
					SPI_voidTranseive(COND_AvoidToL, &received);
				}
				while(received != CHECK_HAND);
				SET_BIT(_SPCR, 7);		// SPI INT ENABE
				Dio_WriteChannel(EXT_INT_PIN, 1);
			}
			break;
		case OpsAvoid_leftlane:
			if(LeftFlag == 0)
			{
				Dio_WriteChannel(F_US_ECH_SWI, 1);	// switch ON
				Dio_WriteChannel(F_US_VCC_SWI, 1);
				Dio_WriteChannel(R_US_ECH_SWI, 1);
				Dio_WriteChannel(R_US_VCC_SWI, 1);
				_delay_ms(500);
				LeftFlag = 1;
			}
			Ultra_Sonic_void_trigger(F_US_TRIGGER);
			DistanceForward = Ultra_Sonic_Distance_in_cm();
			Ultra_Sonic_void_trigger(R_US_TRIGGER);
			DistanceRight = Ultra_Sonic_Distance_in_cm();

			lcd4_set_cursor(4, 1);
			lcd4_disply_num(DistanceForward);
			lcd4_disply_char('_');
			lcd4_disply_num(DistanceRight);

			// CONDITION 1 --> Emergency Stop
			if(DistanceForward < 20 && DistanceRight < 20)
			{
				RUN_STATE = 0;
				Dio_WriteChannel(F_US_ECH_SWI, 0);	// switch OFF
				Dio_WriteChannel(F_US_VCC_SWI, 0);
				Dio_WriteChannel(R_US_ECH_SWI, 0);
				Dio_WriteChannel(R_US_VCC_SWI, 0);
				LeftFlag = 0;
				CLR_BIT(_SPCR, 7);		// SPI INT DISABE
				Dio_WriteChannel(EXT_INT_PIN, 0);	//Make an EXTINT to master
				do{
					SPI_voidTranseive(COND_STOP, &received);
				}
				while(received != CHECK_HAND);
				SET_BIT(_SPCR, 7);		// SPI INT ENABE
				Dio_WriteChannel(EXT_INT_PIN, 1);
			}

			// CONDITION 2 --> Avoid the Car to Right
			if(DistanceForward < 20 && DistanceRight > 20)
			{
				RUN_STATE = 0;
				LeftFlag = 0;
				Dio_WriteChannel(F_US_ECH_SWI, 0);	// switch OFF
				Dio_WriteChannel(F_US_VCC_SWI, 0);
				Dio_WriteChannel(R_US_ECH_SWI, 0);
				Dio_WriteChannel(R_US_VCC_SWI, 0);
				lcd4_CLR();
				CLR_BIT(_SPCR, 7);			// SPI INT DISABE
				Dio_WriteChannel(EXT_INT_PIN, 0);	//Make an EXTINT to master
				do{
					SPI_voidTranseive(COND_AvoidToR, &received);
				}
				while(received != CHECK_HAND);
				SET_BIT(_SPCR, 7);		// SPI INT ENABE
				Dio_WriteChannel(EXT_INT_PIN, 1);
			}
			break;
		default: break;
	}
}

void AutoPark_action(void)
{
	u8 Continue_flag = 0;
	u32 count =0;
	u32 timeout = 0;
	RUN_STATE = 0;
	while(1)
	{
		//Step -1:	Turn your signal and find parking space.
		if(Auto_R_Flag == 0)
		{
			Dio_WriteChannel(R_US_ECH_SWI, 1);
			Dio_WriteChannel(R_US_VCC_SWI, 1);
			_delay_ms(500);
			Auto_R_Flag = 1;
		}
		Ultra_Sonic_void_trigger(R_US_TRIGGER);
		DistanceRight = Ultra_Sonic_Distance_in_cm();
		if (DistanceRight > 20)
		{
			count++;
			timeout = 0;
		}
		else if (DistanceRight < 20)
		{
			count = 0;
//			timeout++;
		}

		//Step -2:	STOP the vehicle in front of the empty space.
		if(count == 40)
		{
			do{
				SPI_voidTranseive(COND_STOP, &received);
			}
			while(received != CHECK_HAND);
			Continue_flag = 1;
			Auto_R_Flag = 0;
			Dio_WriteChannel(R_US_ECH_SWI, 0);
			Dio_WriteChannel(R_US_VCC_SWI, 0);
			break;
		}
//				if (timeout == 500000)
//				{
//					break;
//				}

		//Step -3: 	STEAR the wheel all the way to the right.
	}

	if (Continue_flag == 1)
	{
		Dio_WriteChannel(B_US_ECH_SWI, 1);
		Dio_WriteChannel(B_US_VCC_SWI, 1);
		_delay_ms(500);

		//Step -4: 	BACKWARD until a specific distance
		stop_after_back_cm(40);

		//Step -5: 	STEAR the wheels back to normal

		//Step -6:	BACKWARD until a specific distance
		stop_after_back_cm(20);

		//Step -7: 	STEAR the wheel all the way to the left (opposite of Step -3)

		//Step -8: 	BACKWARD until a specific distance
		stop_after_back_cm(20);
	}

	/******* OPTIONAL ******/
	//Step -9: 	STEAR the wheel all the way to the right / left. (opposite of Step -7)
	//Step-10:	BACKWARD until a specific distance

	RUN_STATE = 0;
	Dio_WriteChannel(B_US_ECH_SWI, 0);
	Dio_WriteChannel(B_US_VCC_SWI, 0);
	SET_BIT(_SPCR, 7);		// SPI INT ENABLE
}

static void stop_after_back_cm (u8 distance)
{
	while(1)
	{
		Ultra_Sonic_void_trigger(B_US_TRIGGER);
		DistanceBack = Ultra_Sonic_Distance_in_cm();
		if (DistanceBack < distance)
		{
			do{
				SPI_voidTranseive(STOP, &received);
			}
			while(received != CHECK_HAND);
			break;
		}
	}
}
