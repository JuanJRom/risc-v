#include "task_scheduler.h"

extern int store_context(void/*int registers*/);

//PCB_t *listHead = NULL;
//PCB_t * volatile executeQueueHead = NULL;
//PCB_t dummy;

//volatile bool  isRunning = false;

struct PCB *temp;
struct PCB *dummy[4];

void task_create(int  id, task_callback_t task)
{
    insertFirst(id, task, 0);
}

void task_exec()
{
   if(length()){
        temp = deleteFirst();
        temp->task();
        //print_s(" registers: ");
        //print_i(temp->registers);
        //temp->registers = store_context(/*temp->registers*/);
        //print_s(" registers: ");
        //print_i(temp->registers);
        insertFirstQueue(temp->id, temp->task, temp->registers );
       
    }else{
        if(lengthQueue()){
            int8_t length_temp = lengthQueue();
            for (int i = 0; i <length_temp; ++i) {
                dummy[i] = deleteFirstQueue();
                insertFirst(dummy[i]->id, dummy[i]->task, dummy[i]->registers );
            }             
        }
        
        /*
        print_s("No hay procesos para ejecutar ");
        unsigned long long int mie;
        asm volatile("csrr %0, mie" : "=r"(mie));
        mie &= ~(1 << 7);
        asm volatile("csrw mie, %0" : "=r"(mie));
        */
    }
}

void task_end(){
    temp = deleteFirst();
};








