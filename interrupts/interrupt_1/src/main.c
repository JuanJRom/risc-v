#include <timer.h>
#include <stdio.h>
#include "trap.h"
#include "uart.h"
#include "main.h"
#include "proccess.h"

int count_1 = 0;
int *ptr_1 = &count_1;

int main(){
    uart_init();
    print_s("Manejador de interrupciones Risc-v!\n");
    while (1){
        asm volatile ("wfi");
        process_1(ptr_1);
    };
    return 0;
}

