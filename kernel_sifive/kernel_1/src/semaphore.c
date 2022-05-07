/*
 * semaphore.c
 *
 *  Created on: 25 mar. 2022
 *      Author: jjrh
 */

#include "semaphore.h"

extern void switch_to(void);

void SemaphoreInit(semaphore_t *semaphore, int32_t value){
	semaphore->value = value;
}

void SemaphoreWait(semaphore_t *semaphore){
	intr_off();
	semaphore->value -=1;
	while(semaphore < 0){
		semaphore->list = deleteFirst();  //Is necessary check it
		semaphore->list->Current_state = waiting;
		//here in missing add to waiting list
		switch_to();
	}
	intr_on();
}

void SemaphoreSignal(semaphore_t *semaphore){
	intr_off();
	semaphore->value +=1;
	intr_on();
}


