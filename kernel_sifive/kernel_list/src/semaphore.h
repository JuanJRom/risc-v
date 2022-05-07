/*
 * semaphore.h
 *
 *  Created on: 15 mar. 2022
 *      Author: jjrh
 */

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include "list.h"
#include "kernel.h"
#include "riscv.h"

typedef struct{
	int32_t value;
   struct pcb *list;
}semaphore_t;

void SemaphoreInit(semaphore_t *semaphore, int32_t value);
void SemaphoreWait(semaphore_t *semaphore);
void SemaphoreSignal(semaphore_t *semaphore);


#endif /* SEMAPHORE_H */
