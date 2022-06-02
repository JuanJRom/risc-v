/*
 * semaphore.c
 *
 *  Created on: 31 may. 2022
 *      Author: jjrh
 */

#include "semaphore.h"

extern void switch_to(void);

void semaphore_init(semaphore_t *semaphore, int32_t value){
	semaphore->value = value;
	semaphore->queue = createList(semaphore->queue);
}

void semaphore_wait(semaphore_t *semaphore){
	intr_off();
	semaphore->value--;
	if(semaphore->value < 0){
		task_wait(semaphore->queue);
		w_mstatus(MSTATUS_MPP_M);
		switch_to();
	}
	intr_on();
}

void semaphore_signal(semaphore_t *semaphore){
	intr_off();
	semaphore->value ++;
	if(semaphore->value <= 0){
		task_unlock(semaphore->queue);
		intr_on();
		w_mstatus(MSTATUS_MPP_M);
		switch_to();
	}
	intr_on();
}

/*void semaphore_wait(semaphore_t *semaphore){
	intr_off();
	if(semaphore->value < 0){
		semaphore->value--;
		intr_on();
		return;
	}
	task_wait(semaphore->queue);
	intr_on();
	w_mstatus(MSTATUS_MPP_M);
	switch_to();
}

void semaphore_signal(semaphore_t *semaphore){
	intr_off();
	if(queue_isEmpty()){
		semaphore->value ++;
	}else{
		task_unlock();
		w_mstatus(MSTATUS_MPP_M);
		switch_to();
	}
	intr_on();
}*/




