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


node_t* temp_pcb;
node_t* current;
list_t* readyList;

void kernel_launch(void);

int  task_create(void(*task)(void));
void task_end();
void task_wait(list_t* queue);
void task_unlock(list_t* queue);

void timer_init(void);
void scheduler_RoundRobin(void);
void process_details(node_t* pcb);

void delay(int number_of_microseconds);


#endif /* KERNEL_H */
