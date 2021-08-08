#include <timer.h>
#include <stdio.h>
#include "trap.h"
#include "uart.h"


int main() {
    uart_init();
    print_s("Manejador de interrupciones Risc-v!\n");
    print_s("Generar excepción para habilitar el temporizador ...\n");
    print_s("Volver al modo de usuario\n");
    while (1){
        
    };
    return 0;
}
