#include "riscv.h"
#include "uart.h"
#define CLINT_BASE 0x2000000
#define MTIME (volatile unsigned long long int *)(CLINT_BASE + 0xbff8)
#define MTIMECMP (volatile unsigned long long int *)(CLINT_BASE + 0x4000)

int count = 0;
int *ptr = &count;
extern void process_2();

void handle_interrupt(uint64_t mcause) {
    if ((mcause << 1 >> 1) == 0x7) {
       // print_s("Interrupcion del temporizador: ");
       // print_i(++count);
       process_2(ptr);

        *MTIMECMP = *MTIME + 0xfffff * 2;
        if (count == 9) {
            unsigned long long int mie;
            asm volatile("csrr %0, mie" : "=r"(mie));
            mie &= ~(1 << 7);
            asm volatile("csrw mie, %0" : "=r"(mie));
        }
    } else {
        print_s("Unknown interrupt: ");
        print_i(mcause << 1 >> 1);
        print_s("\n");
        while (1)
            ;
    }
}

void handle_exception(uint64_t mcause) {
    unsigned long long int mie;

    if (mcause == 0x8) {
        *MTIMECMP = *MTIME + 0xfffff * 5;

        asm volatile("csrr %0, mie" : "=r"(mie));
        mie |= (1 << 7);
        asm volatile("csrw mie, %0" : "=r"(mie));
    } else {
        print_s("Unknown exception: ");
        print_i(mcause << 1 >> 1);
        print_s("\n");
        while (1)
            ;
    }
}

void handle_trap() {
    uint64_t mcause, mepc;
    asm volatile("csrr %0, mcause" : "=r"(mcause));
    asm volatile("csrr %0, mepc" : "=r"(mepc));

    if (mcause >> 63) {
        handle_interrupt(mcause);
    } else {
        handle_exception(mcause);
        asm volatile("csrr t0, mepc");
        asm volatile("addi t0, t0, 0x4");
        asm volatile("csrw mepc, t0");
    }
}