/* Juan Jose Romero Hernandez */
/* Diseño de kernel sobre arquitectura risc-v*/

#include "kernel.h"
#include "semaphore.h"
#include "riscv.h"
#include <stdio.h>
#include "list.h"

int count = 0, count1= 0, count2= 0, count3= 0;
//uint32_t semaphore1, semaphore2;

void task(void){
	while(1){
		count++;
		//printf("task 0 counter: %d\n", count);
	}
}


void task1(void){
	while(1){
		count1++;
		if(count1 >= 1000){
			osKernelKillTask();
		}
		//printf("task 1 counter: %d\n", count1);
	}
}

void task2(void){
	while(1){
		//SemaphoreWait(&semaphore2);
		count2++;
		//printf("task 2 counter: %d\n", count2);
		//SemaphoreSignal(&semaphore1);
	}
}

void task3(void){
	while(1){
		//SemaphoreWait(&semaphore1);
		count3++;
		//printf("task 3 counter: %d\n", count3);
		//SemaphoreSignal(&semaphore2);
	}
}

int main() {
	printf("RISC-V Kernel\n");
	//SemaphoreInit(&semaphore1, 1);
	//SemaphoreInit(&semaphore2, 0);

	osKernelAddTask(&task, &task1 , &task2, &task3 );
	osKernelLaunch();
	//asm volatile("wfi");
}

