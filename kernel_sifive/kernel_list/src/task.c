/*
 * task.c
 *
 *  Created on: 7 may. 2022
 *      Author: jjrh
 */

#include "task.h"

int32_t count = 0, count1= 0, count2= 0, count3= 0;

void task(void){
	while(1){
		count++;
		task_create(&task1);
		task_create(&task2);
		task_create(&task3);
		printList();
		task_end();
		asm volatile("wfi");
		//printf("task 0 counter: %d\n", count);
	}
}


void task1(void){
	while(1){
		count1++;
//		if(count1 >= 1000){
//			osKernelKillTask();
//		}
		//printf("task 1 counter: %d\n", count1);
	}
}

void task2(void){
	while(1){
		//semaphore_wait(&semaphore);
		count2++;
		//printf("This is a server\n");
		//printf("task 2 counter: %d\n", count2);
	//	semaphore_signal(&semaphore);
	}
}

void task3(void){
	while(1){
		//semaphore_wait(&semaphore);
		count3++;
		//printf("This is a client\n");
		//printf("task 3 counter: %d\n", count3);
		//semaphore_signal(&semaphore);
	}
}
