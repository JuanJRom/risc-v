/* Juan Jose Romero Hernandez */
/* Diseño de kernel sobre arquitectura risc-v*/

#include "kernel.h"
#include "semaphore.h"
#include "riscv.h"
#include <stdio.h>
#include "list.h"

int count = 0, count1= 0;//*, count2= 0, count3= 0;
uint32_t semaphore;

void task(void){
	while(1){
		semaphore_wait(&semaphore);
		printf("\nEntrada..\n");
		//count1++;

		//critical section
		delay(4000000);

		printf("\nSaliendo...\n");
		//count1++;
		semaphore_signal(&semaphore);
	}
}


void task1(void){
	while(1){
		semaphore_wait(&semaphore);
		printf("\nEntrada..\n");
		//count1++;

		//critical section
		delay(4000);

		printf("\nSaliendo...\n");
		//count1++;
		semaphore_signal(&semaphore);
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
	osSemaphoreInit(&semaphore, 1);
	//osSemaphoreInit(&semaphore2, 2);

	osKernelAddThreads(&task, &task1 /*, &task2, &task3 */);
	osKernelLaunch();
}

