/*
 * semaphore.h
 *
 *  Created on: 31 may. 2022
 *      Author: jjrh
 */

#ifndef SEMAPHORE_H_
#define SEMAPHORE_H_

#include "list.h"
#include "kernel.h"
#include "riscv.h"
#include "kernel.h"

typedef struct semaphore_t{
   int32_t value;
   list_t *queue;
}semaphore_t;

void semaphore_init(semaphore_t *semaphore, int32_t value);
void semaphore_wait(semaphore_t *semaphore);
void semaphore_signal(semaphore_t *semaphore);

#endif /* SEMAPHORE_H_ */
