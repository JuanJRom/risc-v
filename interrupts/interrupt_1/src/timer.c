#include "riscv.h"
#include "uart.h"
#include "main.h"
#define CLINT_BASE 0x2000000
#define MTIME (volatile unsigned long long int *)(CLINT_BASE + 0xbff8)
#define MTIMECMP (volatile unsigned long long int *)(CLINT_BASE + 0x4000)

extern void trap_entry();

void system_init() {

    // requires gcc -mcmodel=medany
    w_mepc((uint64_t)main);   //update mepc with current instruction address
    // setup trap_entry
    w_mtvec((uint64_t)trap_entry);  //this contains the address the processor jumps to

    *MTIMECMP = *MTIME + 0xfffff * 5;
    uint64_t mie = r_mie();
    mie |= (1 << 7);
    
    w_mie(mie);
    
    uart_init();
    kinit();

    // switch to machine mode and jump to main().
    asm volatile("mret");
}
