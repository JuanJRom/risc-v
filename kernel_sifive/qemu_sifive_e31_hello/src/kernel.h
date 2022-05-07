#ifndef KERNEL_H
#define KERNEL_H

#include <stdint.h>
#include "process.h"
#include <stdio.h>

void osKernelLaunch(void);

uint32_t osKernelAddThreads(void(*task0)(void),
						    void(*task1)(void));

void timer_init(void);
void system_init(void);


#endif
