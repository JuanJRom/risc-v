#include "kernel.h"
#include "riscv.h"

extern void switch_to(void);

#define CLINT_BASE 0x2000000
#define MTIME (volatile unsigned long long int *)(CLINT_BASE + 0xbff8)
#define MTIMECMP (volatile unsigned long long int *)(CLINT_BASE + 0x4000)

#define NUM_OF_THREADS 2
#define STACKSIZE      100

extern void osSchedulerLaunch(void);
extern int main(void);
extern void switch_to(void);

void handle_trap() {
    uint32_t mcause, mepc;
    asm volatile("csrr %0, mcause" : "=r"(mcause));
    asm volatile("csrr %0, mepc" : "=r"(mepc));
    //*MTIMECMP = *MTIME + 0xfffff * 5;
    printf("Unknown interrupt: %x\n ",mcause << 1 >> 1);
}

struct tcb{
	int32_t *stackPt;
	struct tcb *nextPt;
};

typedef struct tcb tcb_t;
tcb_t tcbs[NUM_OF_THREADS];
tcb_t *currentPt;
int32_t TCB_STACK[NUM_OF_THREADS][STACKSIZE];

void osKernelStackInit(int i){
	tcbs[i].stackPt	= &TCB_STACK[i][STACKSIZE];
	//TCB_STACK[i][STACKSIZE-1] = 0x01000000;
}

uint32_t osKernelAddThreads(void(*task0)(void), void(*task1)(void)){
	//__disable_irq();
	tcbs[0].nextPt = &tcbs[1];
	tcbs[1].nextPt = &tcbs[0];
	osKernelStackInit(0);
	TCB_STACK[0][STACKSIZE] = (int32_t)(task0);
	osKernelStackInit(1);
	TCB_STACK[1][STACKSIZE] = (int32_t)(task1);
	currentPt = &tcbs[0];
	//__enable_irq();
	return 1;
}

void osKernelLaunch(void){
	system_init();
//	asm volatile("ecall");
	osSchedulerLaunch();
}

void system_init(){
	w_mepc((uint32_t)main);
	w_mtvec((uint32_t)switch_to);
	timer_init();
}


void timer_init(void) {
	*MTIMECMP = *MTIME + 0xfffff * 5;
	uint32_t mie = r_mie();
	mie |= (1 << 7);
	asm volatile ("csrsi mstatus, 8");
	w_mie(mie);
}
