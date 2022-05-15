/*
 * task.h
 *
 *  Created on: 7 may. 2022
 *      Author: jjrh
 */

#ifndef TASK_H_
#define TASK_H_

#include <stdio.h>
#include "kernel.h"

semaphore_t semaphore;

void task(void);
void task1(void);
void task2(void);
void task3(void);

#endif /* TASK_H_ */
