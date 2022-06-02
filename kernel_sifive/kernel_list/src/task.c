/*
 * task.c
 *
 *  Created on: 7 may. 2022
 *      Author: jjrh
 */

#include "task.h"
//extern void switch_to(void);

uint32_t count = 0/*, count1= 0, count2= 0, count3= 0*/;
int i=0;

void task(void){
	while(1){
		if(count == 0){
			count++;
			task_create(&task1);
			task_create(&task2);
			//task_create(&task3);
			//printList(readyList);
			semaphore_init(&semaphore, 1);
			task_end();
			asm volatile("wfi");
		}
		count++;
	}
}

//Semaphore test
void task1(void){
	while(1){
		semaphore_wait(&semaphore);
		printf("Task 1 Entering..\n");

		//critical section
		for(i=0;i<90000000;i++){}

		printf("Task 1 Exiting...\n");
		semaphore_signal(&semaphore);
		//asm volatile("wfi");

		//delay(400000000);
	}
}

void task2(void){
	while(1){
		semaphore_wait(&semaphore);
		printf("Task 2 Entering..\n");


		//critical section
		for(i=0;i<90000000;i++){}
		//delay(4000);

		printf("Task 2 Exiting...\n");
		semaphore_signal(&semaphore);
		//asm volatile("wfi");

		//delay(400000000);
	}
}

// Concurrency test
/*void task1(void){
	while(1){
		count1++;
		//printf("task 1 counter: %d\n", count1);
	}
}

void task2(void){
	while(1){
		count2++;
		//printf("task 2 counter: %d\n", count2);
	}
}

void task3(void){
	while(1){
		count3++;
		//printf("task 3 counter: %d\n", count3);
	}
}*/

