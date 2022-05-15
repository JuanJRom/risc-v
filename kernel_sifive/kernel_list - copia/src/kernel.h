/*
 * kernel.h
 *
 *  Created on: 8 feb. 2022
 *      Author: jjrh
 */

#ifndef KERNEL_H
#define KERNEL_H


#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include "riscv.h"
#include "list.h"
#include "semaphore.h"


struct pcb *temp_ptr;
struct pcb *current_ptr;

void kernel_launch(void);

int  task_create(void(*task)(void));
void task_end();
void task_wait(struct pcb *queue);
void task_unlock();

void timer_init(void);
void scheduler_RoundRobin(void);


#endif /* KERNEL_H */
