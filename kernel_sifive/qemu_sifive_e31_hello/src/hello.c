/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#include "kernel.h"
#include "process.h"
#include <stdio.h>


int count = 0, count1= 0;

void task(void){
	while(1){
		count++;
		printf("Value: %d\n", count);
	}
}

void task1(void){
	while(1){
		count1++;
		printf("Value: %d\n", count1);
	}
}

int main() {
//	printf("Value: %d\n", count);
	osKernelAddThreads(&task, &task1);
	osKernelLaunch();
}


/*
 uint32_t task_stack[40];              // Reserva de espacio para la tarea
 uint32_t *sp_task = &task_stack[40];  // stack pointer que apunta al stack task
 	*(--sp_task) = (uint32_t)&task; 		//PC
	*(--sp_task) =  0x0000000DU;          //LR
	*(--sp_task) =  0x0000000EU;          //R12
	*(--sp_task) =  0x0000000AU;          //R3
	*(--sp_task) =  0x0000000DU;          //R2
	*(--sp_task) =  0x0000000EU;          //R1
	*(--sp_task) =  0x0000000AU;          //R0 */
