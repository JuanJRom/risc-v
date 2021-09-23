#include "riscv.h"
#include "uart.h"
#include "main.h"
#define CLINT_BASE 0x2000000
#define MTIME (volatile unsigned long long int *)(CLINT_BASE + 0xbff8)
#define MTIMECMP (volatile unsigned long long int *)(CLINT_BASE + 0x4000)

extern void trap_entry();

void timer_init() {

    // requires gcc -mcmodel=medany
    w_mepc((uint64_t)main);

    // setup trap_entry
    w_mtvec((uint64_t)trap_entry);

    *MTIMECMP = *MTIME + 0xfffff * 2;
    uint64_t mie = r_mie();
    mie |= (1 << 7);
    w_mie(mie);

    // switch to machine mode and jump to main().
    asm volatile("mret");
}
