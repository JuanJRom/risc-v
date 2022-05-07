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

void osKernelLaunch(void);

uint32_t osKernelAddThreads(void(*task0)(void),
						    void(*task1)(void)/*,
							void(*task2)(void),
							void(*task3)(void)*/);

void timer_init(void);
void system_init(void);
void osSchedulerRoundRobin(void);


#endif /* KERNEL_H */
