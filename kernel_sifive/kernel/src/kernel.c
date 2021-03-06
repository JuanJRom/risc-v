/*
 * kernel.c
 *
 *  Created on: 8 feb. 2022
 *      Author: jjrh
 */

#include "kernel.h"
#include "riscv.h"

#define CLINT_BASE 0x2000000
#define MTIME (volatile unsigned long long int *)(CLINT_BASE + 0xbff8)
#define MTIMECMP (volatile unsigned long long int *)(CLINT_BASE + 0x4000)

#define NUM_OF_THREADS 2
#define STACKSIZE      200

extern void switch_to(void);
extern void osSchedulerLaunch(void);
extern void switch_to(void);

struct tcb{
	int32_t *stackPt;
	struct tcb *nextPt;
};

typedef struct tcb tcb_t;
tcb_t tcbs[NUM_OF_THREADS];
tcb_t *currentPt;
int32_t TCB_STACK[NUM_OF_THREADS][STACKSIZE];

void osKernelStackInit(int i){
	tcbs[i].stackPt	= &TCB_STACK[i][STACKSIZE];
	//TCB_STACK[i][STACKSIZE-1] = 0x0100DEAD;
}

void osKernelAddTask(void(*task0)(void), void(*task1)(void), void(*task2)(void), void(*task3)(void)){
	intr_off();
	tcbs[0].nextPt = &tcbs[1];
	tcbs[1].nextPt = &tcbs[2];
	tcbs[2].nextPt = &tcbs[3];
	tcbs[3].nextPt = &tcbs[0];
	osKernelStackInit(0);
	TCB_STACK[0][STACKSIZE] = (int32_t)(task0);
	osKernelStackInit(1);
	TCB_STACK[1][STACKSIZE] = (int32_t)(task1);
	TCB_STACK[1][STACKSIZE-1] = (int32_t)(task1);
	osKernelStackInit(2);
	TCB_STACK[2][STACKSIZE] = (int32_t)(task2);
	TCB_STACK[2][STACKSIZE-1] = (int32_t)(task2);
	osKernelStackInit(3);
	TCB_STACK[3][STACKSIZE] = (int32_t)(task3);
	TCB_STACK[3][STACKSIZE-1] = (int32_t)(task3);
	currentPt =  &tcbs[0];
	intr_on();
}

void osKernelKillTask(void){
	intr_off();
	tcbs[0].nextPt = &tcbs[2];
	//tcbs[1].nextPt = &tcbs[2];
	tcbs[2].nextPt = &tcbs[3];
	tcbs[3].nextPt = &tcbs[0];
	intr_on();
}

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
	currentPt = currentPt->nextPt;
}
