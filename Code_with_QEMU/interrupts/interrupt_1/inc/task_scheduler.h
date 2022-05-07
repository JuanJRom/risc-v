#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H
#include "list.h"
#include "queue.h"
#include "proccess.h"

//void task_initialize(void);
void task_create(int  id, task_callback_t task );
void task_exec();
void task_end();
void task_wait();
//void task_delete(PCB_t *task);


#endif