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
#include "kernel.h"
#include "queue.h"

typedef struct semaphore_t{
   int32_t value;
   struct pcb *queue;
}semaphore_t;

void semaphore_init(semaphore_t *semaphore, int32_t value);
void semaphore_wait(semaphore_t *semaphore);
void semaphore_signal(semaphore_t *semaphore);


#endif /* SEMAPHORE_H */
