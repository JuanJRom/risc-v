/*
 * semaphore.c
 *
 *  Created on: 25 mar. 2022
 *      Author: jjrh
 */


#include "kernel.h"
#include "riscv.h"

void SemaphoreInit(int32_t *semaphore, int32_t value){
	*semaphore = value;
}

void SemaphoreSignal(int32_t *semaphore){
	intr_off();
	*semaphore +=1;
	intr_on();
}

void SemaphoreWait(int32_t *semaphore){
	intr_off();
	while(*semaphore <=0){
		//Push on list
		intr_off();
		//*MTIMECMP = *MTIME;
		intr_on();
	}
	*semaphore -=1;
	intr_on();
}
