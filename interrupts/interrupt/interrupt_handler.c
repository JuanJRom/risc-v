#include <stdio.h>

void mtrap() __attribute__ ((interrupt, section(".mtrap")));

void mtrap(){
    //uint8_t txt[0x100];
    //struct uart_t uart = { .reg = (uint32_t*) 0x10013000 };

    //stringFormat(txt, 0x100, "machine trap\r\n");
    //uart_write(&uart, txt, 0x100);
    printf("machine trap\n");
}

void main(){
    //uint8_t txt[0x100];
    uint64_t mvendorid, marchid, mimpid, mhartid, mstatus, misa, mtvec, mie, mip, mcause;
    //struct clint_t clint = { .addr = 0x2000000 };
    //struct plic_t plic = { .reg = (uint32_t*) 0x0c000000 };
    //struct uart_t uart = { .reg = (uint32_t*) 0x10013000 };

    asm volatile ("csrr %[reg], mvendorid" : [reg] "=r" (mvendorid));
    asm volatile ("csrr %[reg], marchid" : [reg] "=r" (marchid));
    asm volatile ("csrr %[reg], mimpid" : [reg] "=r" (mimpid));
    asm volatile ("csrr %[reg], mhartid" : [reg] "=r" (mhartid));
    asm volatile ("csrr %[reg], misa" : [reg] "=r" (misa));

    // block all harts except hart 0
    if(mhartid)
        for(;;){ asm volatile ("wfi"); }

    //mm_init(0x84000000, 0x1bffe000); // addr: 2GB + 64MB & size: 512MB - 64MB - 8KB
    //uart_init(&uart);

    //stringFormat(txt, 0x100, "mvendorid=%x, marchid=%x, mimpid=%x, mhartid=%x, misa=%x\r\n", mvendorid, marchid, mimpid, mhartid, misa);
    //uart_write(&uart, txt, 0x100);

    printf("mvendorid=%x, marchid=%x, mimpid=%x, mhartid=%x, misa=%x\r\n", mvendorid, marchid, mimpid, mhartid, misa);

    // check if pending interrupt
    asm volatile ("csrr %[reg], mie" : [reg] "=r" (mie));
    asm volatile ("csrr %[reg], mip" : [reg] "=r" (mip));
    asm volatile ("csrr %[reg], mstatus" : [reg] "=r" (mstatus));
    asm volatile ("csrr %[reg], mcause" : [reg] "=r" (mcause));
    //stringFormat(txt, 0x100, "mie=%x, mip=%x, mstatus=%x, mcause=%x\r\n", mie, mip, mstatus, mcause);
    printf("mie=%x, mip=%x, mstatus=%x, mcause=%x\r\n", mie, mip, mstatus, mcause);
    //uart_write(&uart, txt, 0x100);

    // set interrupt function or vector
    asm volatile ("csrw mtvec, %[reg]" : : [reg] "r" (uint32_t) mtrap));
    asm volatile ("csrr %[reg], mtvec" : [reg] "=r" (mtvec));
    //stringFormat(txt, 0x100, "mtvec=%x\r\n", mtvec);
    //uart_write(&uart, txt, 0x100);

    printf("mtvec=%x\r\n", mtvec);

    // enable machine mode interrupts
    asm volatile ("csrs mstatus, 0x8");

    // enable interrupts
    asm volatile ("csrs mie, 0x8");

    // check if pending interrupt
    asm volatile ("csrr %[reg], mie" : [reg] "=r" (mie));
    asm volatile ("csrr %[reg], mip" : [reg] "=r" (mip));
    asm volatile ("csrr %[reg], mstatus" : [reg] "=r" (mstatus));
    asm volatile ("csrr %[reg], mcause" : [reg] "=r" (mcause));
    //stringFormat(txt, 0x100, "mie=%x, mip=%x, mstatus=%x, mcause=%x\r\n", mie, mip, mstatus, mcause);
    //uart_write(&uart, txt, 0x100);

     printf("mie=%x, mip=%x, mstatus=%x, mcause=%x\r\n", mie, mip, mstatus, mcause);

    // enable timer and wait for x cycles
    clint_set_hart_timer(0x2000000, mhartid, 10);
    for(mip = 0; mip < 0x100; mip++){}

    // check if pending interrupt
    asm volatile ("csrr %[reg], mie" : [reg] "=r" (mie));
    asm volatile ("csrr %[reg], mip" : [reg] "=r" (mip));
    asm volatile ("csrr %[reg], mstatus" : [reg] "=r" (mstatus));
    asm volatile ("csrr %[reg], mcause" : [reg] "=r" (mcause));
    //stringFormat(txt, 0x100, "mie=%x, mip=%x, mstatus=%x, mcause=%x\r\n", mie, mip, mstatus, mcause);
    //uart_write(&uart, txt, 0x100);

     printf("mie=%x, mip=%x, mstatus=%x, mcause=%x\r\n", mie, mip, mstatus, mcause);
    for(;;){ asm volatile ("wfi"); }
}