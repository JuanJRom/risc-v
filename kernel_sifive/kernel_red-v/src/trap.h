/*
 * trap.h
 *
 *  Created on: 31 may. 2022
 *      Author: jjrh
 */

#ifndef TRAP_H_
#define TRAP_H_

#include <stdint.h>
#include <stdio.h>
//#include "kernel.h"
//#include "list.h"

void handle_interrupt(uint32_t mcause);
void handle_exception(uint32_t mcause);
void handle_trap();

#endif /* TRAP_H_ */
