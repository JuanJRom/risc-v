/*
 * trap.h
 *
 *  Created on: 8 feb. 2022
 *      Author: jjrh
 */
#ifndef TRAP_H
#define TRAP_H

#include <stdint.h>
#include <stdio.h>

void handle_interrupt(uint32_t mcause);
void handle_exception(uint32_t mcause);
void handle_trap();

#endif /* TRAP_H */
