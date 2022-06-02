/*
 * task.c
 *
 *  Created on: 31 may. 2022
 *      Author: jjrh
 */

#include "task.h"
//extern void switch_to(void);

uint32_t count = 0, count1= 0, count2= 0, count3= 0;

void task(void){
	while(1){
		if(count == 0){
			count++;
			task_create(&task1);
			task_create(&task2);
			task_create(&task3);
			//printList();
			//semaphore_init(&semaphore, 1);
			task_end();
			asm volatile("wfi");
		}
		count++;
	}
}

// Concurrency test
void task1(void){
	while(1){
		count1++;
		for(int i=0; i<900000;i++){}
		count1++;
		//delay(4000000000);
		//count1++;
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
}

//Semaphore test
/*void task1(void){
	while(1){
		if(count2==0){
			semaphore_wait(&semaphore);
			count2++;
			printf("task 1 Entering..\n");
		}

		//critical section
		delay(4000000000);

		printf("Exiting...\n");
		count2--;
		semaphore_signal(&semaphore);
		//asm volatile("wfi");

		//delay(400000000);
	}
}

void task2(void){
	while(1){
		if(count3==0){
			semaphore_wait(&semaphore);
			printf("task 2 Entering..\n");
			count3++;
		}


		//critical section
		delay(4000);

		printf("Exiting...\n");
		count3--;
		semaphore_signal(&semaphore);
		//asm volatile("wfi");

		//delay(400000000);
	}
}*/



