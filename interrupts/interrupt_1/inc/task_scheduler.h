#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H
#include "list.h"
#include "proccess.h"

//void task_initialize(void);
void task_create(int  id, task_callback_t task );
void task_run();
//void task_delete(PCB_t *task);


#endif