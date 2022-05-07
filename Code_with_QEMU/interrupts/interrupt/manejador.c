#include <stdio.h>
#include <stdint.h>
#include "uart.h"
#define CLINT_BASE 0x2000000
#define MTIME (volatile unsigned long long int *)(CLINT_BASE + 0xbff8)
#define MTIMECMP (volatile unsigned long long int *)(CLINT_BASE + 0x4000)
//#define  MTIME       *((volatile uint64_t *) 0x02000000 + 0xbff8)
//#define  MTIMECMP    *((volatile uint64_t *) 0x02000000 + 0x4000)
//#define  MTIME_INTERRUPT_PERIOD  12000000    // 24 MHz, so 12000000 generates an interrupt period of exactly half a second

void interruptHandler() __attribute__ ((interrupt, section(".interrupt_handler")));

void interruptHandler() {
    *MTIMECMP = *MTIME + 0xfffff * 25;
   
    //printf("Machine Interrupt");
    print_s("Machine Interrupt\n");
}

void printf_status(uint64_t mstatus, uint64_t mie, uint64_t mip, uint64_t mcause) {
    asm volatile ("csrr %[reg], mie" : [reg] "=r" (mie));
    asm volatile ("csrr %[reg], mip" : [reg] "=r" (mip));
    asm volatile ("csrr %[reg], mstatus" : [reg] "=r" (mstatus));
    asm volatile ("csrr %[reg], mcause" : [reg] "=r" (mcause));
    print_s("Manejador de interrupciones Risc-v!\n");
    print_s(mie);
    //printf("mie=%x, mip=%x, mstatus=%x, mcause=%x\r\n", mie, mip, mstatus, mcause);
}

int main() {
    
    uart_init();
    uint64_t mstatus, mie, mip, mcause, mtvec;
    printf_status(mstatus, mie, mip, mcause);
    
    // basic (non vectored) interrupt handler (to force non vectored, set 0 to lower two bits of mtvec, so force 4 byte aligned on linker script for interrupt handler)
    asm volatile ("csrw mtvec, %[reg]" : : [reg] "r" ((uint64_t) interruptHandler));
    asm volatile ("csrr %[reg], mtvec" : [reg] "=r" (mtvec));
    print_s(mtvec);
    
    // machine interrupt enable
    asm volatile ("csrw mie, %[reg]" : : [reg] "r" ((uint32_t) 0x80));

    asm volatile ("csrsi mstatus, 8");

    // configure interrupt period
    //MTIME = 0;
    //MTIMECMP = 10;

    // sleep
    while (1){
        asm volatile ("wfi");
        print_s("test");
    }  
    
    return 0;
}
