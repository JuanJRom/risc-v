//#include "riscv.h"
#include <stdint.h>
#define CLINT_BASE 0x2000000
#define MTIME (volatile unsigned long long int *)(CLINT_BASE + 0xbff8)
#define MTIMECMP (volatile unsigned long long int *)(CLINT_BASE + 0x4000)

void timer_init() {
    *MTIMECMP = *MTIME + 0xfffff * 25;
    uint64_t mie;// = r_mie();
    asm volatile("csrr %0, mie" : "=r"(mie));
    mie |= (1 << 7);
    //w_mie(mie); Esta funcion y r_mie estan en el archivo riscv.h de bare metal 
    asm volatile("csrw mie, %0" : : "r"(mie));
    // switch to machine mode and jump to main().
    asm volatile("mret");
}
