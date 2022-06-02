/*
 * kernel.c
 *
 *  Created on: 31 may. 2022
 *      Author: jjrh
 */

#include "kernel.h"

#define CLINT_BASE 0x2000000
#define MTIME (volatile unsigned long long int *)(CLINT_BASE + 0xbff8)
#define MTIMECMP (volatile unsigned long long int *)(CLINT_BASE + 0x4000)

#define NUM_OF_THREADS 4
#define STACKSIZE      184

extern void switch_to(void);
extern void osSchedulerLaunch(void);

int32_t PCB_STACK[NUM_OF_THREADS][STACKSIZE];

/*void stack_init(int i){
	temp_ptr->stackPt = &PCB_STACK[i][STACKSIZE];
	//PCB_STACK[i][STACKSIZE-1] = 0x0100DEAD;
}*/

int task_create(void(*task)(void)/*, void(*task1)(void), void(*task2)(void), void(*task3)(void)*/){
	intr_off();
	static uint32_t i=0;
	if(i==0){
		temp_pcb = createNode();
		readyList = createList(readyList);
	}
	temp_pcb->id = i;
	temp_pcb->state = ready;
	temp_pcb->stackPt = &PCB_STACK[i][STACKSIZE];
	//PCB_STACK[i][STACKSIZE-1] = 0x0100DEAD;   //This is only for test
	addLast(readyList, temp_pcb);
	if(i==0) current = find(readyList, i);
	//stack_init(temp_ptr->id);
	PCB_STACK[i][STACKSIZE] = (int32_t)(task);
	PCB_STACK[i][STACKSIZE-1] = (int32_t)(task);
	i++;
	intr_on();
	return i;
}

void task_end(void){
	deleteElement(readyList, current->id);
	//current = current->next;
	//switch_to();
}

void task_wait(list_t* queue){
	temp_pcb = find(readyList, current->id);
	temp_pcb->state = waiting;
	addFirst(queue, temp_pcb);
	deleteElement(readyList, current->id);
}

void task_unlock(list_t* queue){
	temp_pcb = get(0,queue);
	temp_pcb->state = ready;
	addLast(readyList, temp_pcb);
	deleteFirst(queue);
}

void kernel_launch(void){
	w_mtvec((uint32_t)switch_to);
	timer_init();
	osSchedulerLaunch();
}

void timer_init(void) {
	//*MTIMECMP = *MTIME + 0xfffff * 5;
	*MTIMECMP = *MTIME + 0x11111;
	intr_on();
}

void scheduler_RoundRobin(void){
	current->state = ready;
	if(current->next == NULL)
		current = get(0, readyList);
		//current_ptr = find(1);
	else
		current = current->next;
	current->state = running;
}

void process_details(node_t* pcb){
	printf("Process ID: %d , ", temp_pcb->id);
	printf("State: %d , ", temp_pcb->state);
	printf("Stack address: %d \n", temp_pcb->stackPt);
}

//custom write delay
void delay(int number_of_microseconds){ //not actually number of seconds
	// Converting time into multiples of a hundred nS
	int hundred_ns = 10 * number_of_microseconds;
	// Storing start time
	clock_t start_time = clock();
	// looping till required time is not achieved
	while (clock() < start_time + hundred_ns);
}
