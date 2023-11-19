/*
 * scheduler.c
 *
 *  Created on: Nov 17, 2023
 *      Author: Mahmoud El Arabi
 */

/* ----------------- Section : includes -----------------*/
#include "scheduler.h"
#include "../../_MCAL/TIMER0/TMR0_Interface.h"

/*------------------Section : Helpers -------------------*/
task_t My_Tasks[MAX_NUMBER_OF_TASKS+1];
u16 temp_priodicity[MAX_NUMBER_OF_TASKS+1];
static u8 created_tasks_number = 0;
static void Simple_Scheduler(void);
static void shift_array_index(u8 index);

/* ----------------- Section : Software Interfaces Implementation -----------------*/
void Task_Creat(u8 Copy_u8Priority, u16 Copy_u8Periodicity, void (*Fptr)(void), u16 Copy_u16InitialDelay)
{
	u8 flag = 0;
	//check if the priority (index) is repeated
	for (int i = 0; i<created_tasks_number ; i++)
	{
		if (Copy_u8Priority == My_Tasks[i].Task_Priority)
		{
			flag = 1;
			break;
		}
	}

	if (flag == 1)
	{
		shift_array_index(Copy_u8Priority);
		Copy_u8Priority++;
	}
	My_Tasks[Copy_u8Priority].Task_FuncPtr = Fptr;
	My_Tasks[Copy_u8Priority].Task_Periodicity = Copy_u8Periodicity;
	My_Tasks[Copy_u8Priority].Task_Priority = Copy_u8Priority;
	My_Tasks[Copy_u8Priority].Task_InitialDelay = Copy_u16InitialDelay;

    temp_priodicity[Copy_u8Priority] = Copy_u16InitialDelay;
    created_tasks_number++;
}

void Scheduler_Start(void) {
    TMR0_voidInit();
    TMR0_voidStart();
    TMR0_voidSendCallBack_OVF(Simple_Scheduler);
}

/*-----------------------------------------------------*/
static void Simple_Scheduler(void)
{
    for (u8 i = 0; i <= created_tasks_number ; i++)
    {
    	if (My_Tasks[i].Task_FuncPtr == NULL)
    	{
    		continue;
    	}
        if (temp_priodicity[i] == 0)
        {
            My_Tasks[i].Task_FuncPtr();
            temp_priodicity[i] = My_Tasks[i].Task_Periodicity;
        }
        else
        {
        	temp_priodicity[i]--;
        }
    }
}

static void shift_array_index(u8 index)
{
	for(int i = index; i< created_tasks_number-1 ; i ++)
	{
		My_Tasks[i].Task_Priority++;
	}

}
