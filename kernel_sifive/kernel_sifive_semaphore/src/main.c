/* Juan Jose Romero Hernandez */
/* Dise�o de kernel sobre arquitectura risc-v*/

#include "kernel.h"
#include "semaphore.h"
#include "riscv.h"
#include <stdio.h>
#include "list.h"

int count = 0, count1= 0;//*, count2= 0, count3= 0;
uint32_t semaphore1, semaphore2;

void task(void){
	while(1){
		osSignalWait(&semaphore2);
		count++;
		//printf("task 0 counter: %d\n", count);
		osSignalSet(&semaphore1);
		//asm volatile("wfi");
	}
}


void task1(void){
	while(1){
		osSignalWait(&semaphore1);
		count1++;
		//printf("task 1 counter: %d\n", count);
		osSignalSet(&semaphore2);
		//asm volatile("wfi");
	}
}
/*
void task2(void){
	while(1){
		count1++;
		printf("task_2_counter: %d\n", count2);
		asm volatile("wfi");
	}
}

void task3(void){
	while(1){
		count3++;
		printf("task_3_counter: %d\n", count3);
		asm volatile("wfi");
	}
}
*/

int main() {
	printf("RISC-V Kernel\n");
	osSemaphoreInit(&semaphore1, 1);
	osSemaphoreInit(&semaphore2, 2);

	osKernelAddThreads(&task, &task1 /*, &task2, &task3 */);
	osKernelLaunch();
}

