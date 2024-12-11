/*
 * scheduler.h
 *
 *  Created on: Dec 1, 2024
 *      Author: HOME
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "global.h"
#include <stdlib.h>

typedef struct sTask{
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	struct sTask * next;
	struct sTask * prev;
}sTask;
typedef struct List{
	sTask * head;
	sTask * tail;
	uint8_t numTask;
}List;
extern List list;
void SCH_Init(void);
void SCH_Add_Task (void (*function) (), uint32_t, uint32_t);
void SCH_Update(void);
void SCH_Dispatch_Task(void);
uint8_t SCH_Is_Task_Exist(void (*function)());
uint8_t SCH_Delete_Task(void (*function)() );
#endif /* INC_SCHEDULER_H_ */
