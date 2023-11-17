/*
 * sheduler.c
 *
 *  Created on: Nov 17, 2023
 *      Author: Mahmoud El Arabi
 */


#include "scheduler.h"
#include "../../_MCAL/TIMER1/TMR1_Register.h"
#include "../../_MCAL/GI/GI_Interface.h"
#include "../../_MCAL/TIMER0/TMR0_Interface.h"

Task_t OS_Tasks[OS_NUMBER_OF_TASKS];

u32 TickCount = 0;

void Scheduler(void)
{
    for (u8 i = 0; i < OS_NUMBER_OF_TASKS; i++) {
        if ((OS_Tasks[i].State == OS_TASK_READY)) {
            if (OS_Tasks[i].InitialDelay == 0)
            {
                OS_Tasks[i].InitialDelay = OS_Tasks[i].Periodicity - 1;
                OS_Tasks[i].Fptr();
            }
            else
            {
                OS_Tasks[i].InitialDelay--;
            }
        }
    }
    TickCount++;
}


void OS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u8Periodicity, u16 Copy_u8InitialDelay, void (*ptr)(void))
{
    OS_Tasks[Copy_u8ID].Fptr = ptr;
    OS_Tasks[Copy_u8ID].InitialDelay = Copy_u8InitialDelay;
    OS_Tasks[Copy_u8ID].Periodicity = Copy_u8Periodicity;
    OS_Tasks[Copy_u8ID].State = OS_TASK_READY;
    OS_Tasks[Copy_u8ID].TaskID = Copy_u8ID;
}


void OS_voidDeleteTask(u8 Copy_u8ID) {
    OS_Tasks[Copy_u8ID].State = OS_TASK_DELETED;
}

void OS_voidSuspendTask(u8 Copy_u8ID, u8 Copy_u8SuspendTime) {
    OS_Tasks[Copy_u8ID].State = OS_TASK_SUSPENDED;
    OS_Tasks[Copy_u8ID].SuspendTime = Copy_u8SuspendTime + TickCount;
}


void OS_voidStartScheduler(void) {
    TMR0_voidInit();

    TMR0_voidStart();

    TMR0_voidSendCallBack_OVF(Scheduler);
}


void OS_voidResumeTask(u8 Copy_u8ID) {
    OS_Tasks[Copy_u8ID].State = OS_TASK_READY;
}


u8 OS_u8GetTaskState(u8 Copy_u8ID) {
    return OS_Tasks[Copy_u8ID].State;
}

