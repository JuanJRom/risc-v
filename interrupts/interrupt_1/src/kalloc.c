#include "kalloc.h"
//#include "memorylayout.h"
//#include "memutils.h"
#include "riscv.h"
#include "stdint.h"
#include "uart.h"

// the kernel expects there to be RAM
// for use by the kernel and user pages
// from physical address 0x80000000 to PHYSTOP.
#define KERNBASE 0x80000000L
#define PHYSTOP (KERNBASE + 128 * 1024 * 1024)


#define PGUP(addr) (((addr) + PGSIZE - 1) & ~(PGSIZE - 1))
extern uint8_t end[];
struct run_t *freelist;

void *c_memset(void *dst, int c, uint32_t n) {
    char *cdst = (char *)dst;
    int i;
    for (i = 0; i < n; i++) {
        cdst[i] = c;
    }
    return dst;
}

// construct the freelist from end of the text to PHYSTOP
void kinit() {
    uint8_t *p;
    for (p = (uint8_t *)(PHYSTOP - PGSIZE); p >= (uint8_t *)PGUP((uint64_t)end);
         p -= PGSIZE) {
        kfree(p);
    }
}

void kfree(uint8_t *pa) {
    c_memset(pa, 1, PGSIZE);
    struct run_t *r = (struct run_t *)pa;
    r->next = freelist;
    freelist = r;
}

void *kalloc() {
    void *pa = freelist;
    freelist = freelist->next;
    return pa;
}