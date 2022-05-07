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

struct pcb *temp_ptr;
struct pcb *current_ptr;

int32_t PCB_STACK[NUM_OF_THREADS][STACKSIZE];

void osKernelStackInit(int i){
	temp_ptr->stackPt = &PCB_STACK[i][STACKSIZE];
	//PCB_STACK[i][STACKSIZE-1] = 0x0100DEAD;
}

void osKernelAddTask(void(*task0)(void), void(*task1)(void), void(*task2)(void), void(*task3)(void)){
	intr_off();
	temp_ptr = insertFirst(0, 0);
	current_ptr = temp_ptr;
	osKernelStackInit(temp_ptr->id);
	PCB_STACK[0][STACKSIZE] = (int32_t)(task0);
	temp_ptr = insertFirst(1, 0);
	osKernelStackInit(temp_ptr->id);
	PCB_STACK[1][STACKSIZE] = (int32_t)(task1);
	PCB_STACK[1][STACKSIZE-1] = (int32_t)(task1);
	temp_ptr = insertFirst(2, 0);
	osKernelStackInit(temp_ptr->id);
	PCB_STACK[2][STACKSIZE] = (int32_t)(task2);
	PCB_STACK[2][STACKSIZE-1] = (int32_t)(task2);
	temp_ptr = insertFirst(3, 0);
	osKernelStackInit(temp_ptr->id);
	PCB_STACK[3][STACKSIZE] = (int32_t)(task3);
	PCB_STACK[3][STACKSIZE-1] = (int32_t)(task3);

	intr_on();
}

/*void osKernelKillTask(void){
	intr_off();
	pcbs[0].nextPt = &pcbs[2];
	//pcbs[1].nextPt = &pcbs[2];
	pcbs[2].nextPt = &pcbs[3];
	pcbs[3].nextPt = &pcbs[0];
	intr_on();
}*/

void osKernelLaunch(void){
	system_init();
	osSchedulerLaunch();
}

void system_init(){
	//w_mepc((uint32_t)main);
	w_mtvec((uint32_t)switch_to);
	timer_init();
}


void timer_init(void) {
	*MTIMECMP = *MTIME + 0xfffff * 5;
	intr_on();
}

void osSchedulerRoundRobin(void){
	current_ptr->Current_state = ready;
	if(current_ptr->nextPt == NULL)
		current_ptr = find(3);
	else
		current_ptr = current_ptr->nextPt;
		current_ptr->Current_state = running;
}
