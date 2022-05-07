/*
 * kernel.c
 *
 *  Created on: 8 feb. 2022
 *      Author: jjrh
 */

#include "kernel.h"

#define CLINT_BASE 0x2000000
#define MTIME (volatile unsigned long long int *)(CLINT_BASE + 0xbff8)
#define MTIMECMP (volatile unsigned long long int *)(CLINT_BASE + 0x4000)

#define NUM_OF_THREADS 4
#define STACKSIZE      200

extern void switch_to(void);
extern void osSchedulerLaunch(void);

int32_t PCB_STACK[NUM_OF_THREADS][STACKSIZE];

void stack_init(int i){
	temp_ptr->stackPt = &PCB_STACK[i][STACKSIZE];
	//PCB_STACK[i][STACKSIZE-1] = 0x0100DEAD;
}

int task_create(void(*task)(void)/*, void(*task1)(void), void(*task2)(void), void(*task3)(void)*/){
	intr_off();
	static uint32_t i=0;
	temp_ptr = insertFirst(i, 0);
	if(temp_ptr->id==0) current_ptr = temp_ptr;
	stack_init(temp_ptr->id);
	PCB_STACK[i][STACKSIZE] = (int32_t)(task);
	PCB_STACK[i][STACKSIZE-1] = (int32_t)(task);
	i++;
	intr_on();
	return i;
}

void task_end(void){
	intr_off();
	delete(current_ptr->id);
	intr_on();
}

void kernel_launch(void){
	w_mtvec((uint32_t)switch_to);
	timer_init();
	osSchedulerLaunch();
}

void timer_init(void) {
	*MTIMECMP = *MTIME + 0xfffff * 5;
	intr_on();
}

void scheduler_RoundRobin(void){
	current_ptr->Current_state = ready;
	if(current_ptr->nextPt == NULL)
		current_ptr = find(3);
	else
		current_ptr = current_ptr->nextPt;
		current_ptr->Current_state = running;
}
