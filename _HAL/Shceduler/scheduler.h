/*
 * scheduler.h
 *
 *  Created on: Nov 17, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef HAL_SHCEDULER_SCHEDULER_H_
#define HAL_SHCEDULER_SCHEDULER_H_

#include "../../_MY_LIBS/STD_TYPES.h"

#define OS_NUMBER_OF_TASKS		4
#define OS_TASK_DELETED			2
#define OS_TASK_READY			1
#define OS_TASK_SUSPENDED		0


typedef struct{
	u8 Periodicity;
	u8 InitialDelay;
	u8 TaskID;
	u8 State;
	u8 SuspendTime;
	void (*Fptr)(void);
}Task;

void Scheduler(void);
/*
 * OS_voidCreateTask
 */
void OS_voidCreateTask(u8 Copy_u8ID, u16 Copy_u8Periodicity, u16 Copy_u8InitialDelay, void (*ptr)(void));

/*
 * OS_voidDeleteTask
 */
void OS_voidDeleteTask(u8 Copy_u8ID);

/*
 * OS_voidSuspendTask
 */
void OS_voidSuspendTask(u8 Copy_u8ID, u8 Copy_u8SuspendTime);

/*
 * OS_voidStartScheduler
 */
void OS_voidStartScheduler(void);

/*
 * OS_voidResumeTask
 */
void OS_voidResumeTask(u8 Copy_u8ID);

/*
 * OS_u8GetTaskState
 */
u8 OS_u8GetTaskState(u8 Copy_u8ID);



#endif /* HAL_SHCEDULER_SCHEDULER_H_ */
