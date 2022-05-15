/*
 * semaphore.c
 *
 *  Created on: 25 mar. 2022
 *      Author: jjrh
 */

#include "semaphore.h"

extern void switch_to(void);

void semaphore_init(semaphore_t *semaphore, int32_t value){
	semaphore->value = value;
}

void semaphore_wait(semaphore_t *semaphore){
	asm volatile("ecall");
	intr_off();
	if(semaphore->value > 1000)
		semaphore->value = 1;
	semaphore->value--;
	//printf("test_wait: %d\n", semaphore->value);
	if(semaphore->value < 0){
		task_wait(semaphore->queue);
		switch_to();
	}
	intr_on();
}

void semaphore_signal(semaphore_t *semaphore){
	intr_off();
	semaphore->value ++;
	//printf("test_signal: %d\n", semaphore->value);
	if(semaphore->value <= 0){
		task_unlock();
		switch_to();
	}
	intr_on();
}


