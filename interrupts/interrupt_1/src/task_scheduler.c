#include "task_scheduler.h"

//PCB_t *listHead = NULL;
//PCB_t * volatile executeQueueHead = NULL;
//PCB_t dummy;

//volatile bool  isRunning = false;

struct node *temp[4];

int count_3 = 0;
int *ptr_0 = &count_3;

int count_1 = 0;
int *ptr_1 = &count_1;

int count_2 = 0;
int *ptr_2 = &count_2;

void task_create(int  id, task_callback_t task)
{
    insertFirst(id, task);
}

void task_run()
{
   if(isEmpty){
        
       /* int length_temp = length();
        for (int i = 0; i <length_temp; ++i)
        {
            temp[i] = deleteFirst();
            temp[i]->data();
        } */
        temp[0] = deleteFirst();
        temp[0]->data();
       
    }else{
        print_s("no hay procesos ");
    }
}







