#ifndef KALLOC_H
#define KALLOC_H

#include "stdint.h"
struct run_t {
    struct run_t* next;
};

extern struct run_t* freelist;

void *c_memset(void *dst, int c, uint32_t n);

void kinit();
void kfree(uint8_t* pa);
void* kalloc();



#endif