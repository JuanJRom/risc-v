#include <timer.h>
#include <stdio.h>
#include "trap.h"
#include "uart.h"

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

void process_1(int *count){
    print_s("                 |    Proceso uno: ");
    print_i(++*count);
    print_s("\n");
    
};

int process_2(int *count_1 ){
     print_s("Proceso dos: ");
    print_i(++*count_1);
    //print_s("\n");
};
