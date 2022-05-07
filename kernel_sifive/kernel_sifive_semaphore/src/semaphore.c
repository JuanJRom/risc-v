/*
 * semaphore.c
 *
 *  Created on: 25 mar. 2022
 *      Author: jjrh
 */

#include "kernel.h"
#include "riscv.h"

void osSemaphoreInit(int32_t *semaphore, int32_t value){
	*semaphore = value;
}

void osSignalSet(int32_t *semaphore){
	intr_off();
	*semaphore +=1;
	intr_on();
}

void osSignalWait(int32_t *semaphore){
	intr_off();
	while(*semaphore <=0){
		intr_off();
		intr_on();
	}
	*semaphore -=1;
	intr_on();
}
