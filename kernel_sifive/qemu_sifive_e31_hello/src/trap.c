/*#include "riscv.h"

#define CLINT_BASE 0x2000000
#define MTIME (volatile unsigned long long int *)(CLINT_BASE + 0xbff8)
#define MTIMECMP (volatile unsigned long long int *)(CLINT_BASE + 0x4000)

int count4 = 0;

void handle_interrupt(uint64_t mcause) {
    if ((mcause << 1 >> 1) == 0x7) {
        printf("Interrupcion del temporizador: %d\n",++count4);

        *MTIMECMP = *MTIME + 0xfffff * 25;
        if (count4 == 10) {
            unsigned long long int mie;
            asm volatile("csrr %0, mie" : "=r"(mie));
            mie &= ~(1 << 7);
            asm volatile("csrw mie, %0" : "=r"(mie));
        }
    } else {
        printf("Unknown interrupt: %x\n ",mcause << 1 >> 1);
        while (1)
            ;
    }
}

void handle_exception(uint64_t mcause) {
    unsigned long long int mie;

    if (mcause == 0x8) {
        *MTIMECMP = *MTIME + 0xfffff * 25;

        asm volatile("csrr %0, mie" : "=r"(mie));
        mie |= (1 << 7);
        asm volatile("csrw mie, %0" : "=r"(mie));
    } else {
    	printf("Unknown interrupt: %x\n ",mcause << 1 >> 1);
        while (1)
            ;
    }
}

void handle_trap() {
    uint32_t mcause, mepc;
    asm volatile("csrr %0, mcause" : "=r"(mcause));
    asm volatile("csrr %0, mepc" : "=r"(mepc));

    if (mcause >> 31) {
        handle_interrupt(mcause);
    } else {
        handle_exception(mcause);
        asm volatile("csrr t0, mepc");
        asm volatile("addi t0, t0, 0x4");
        asm volatile("csrw mepc, t0");
    }
}
*/
