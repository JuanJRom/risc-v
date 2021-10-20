#ifndef PROCCESS_H
#define PROCCESS_H

#include "uart.h"

typedef struct{
    int state;
    int number;
    int pc;
    int memory_begin; //Contains the memory begin address where the registers are
    int memory_end; //Contains the memory end address where the registers are
}PCB_t;

void process_1(int *count);

void process_2(int *count_1);


#endif