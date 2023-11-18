/*
 * scheduler.h
 *
 *  Created on: Nov 17, 2023
 *      Author: Mahmoud El Arabi
 */

#ifndef SIMPLE_SCHEDULER_H
#define SIMPLE_SCHEDULER_H

/* ----------------- Section : includes -----------------*/
#include "../../_MY_LIBS/STD_TYPES.h"

/* ----------------- Section : Defined Data Types -----------------*/
#define MAX_NUMBER_OF_TASKS      5

typedef struct {
    u8 Task_Periodicity;
    u8 Task_Priority;
    void (*Task_FuncPtr)(void);
} task_t;

/* ----------------- Section : Software Interfaces Declarations -----------------*/
void Task_Creat(u8 Copy_u8Priority, u16 Copy_u8Periodicity, void (*Fptr)(void));
void Scheduler_Start(void);

#endif // SIMPLE_SCHEDULER_H
