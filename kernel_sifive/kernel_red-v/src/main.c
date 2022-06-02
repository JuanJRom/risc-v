/* Juan Jose Romero Hernandez
   Diseño de kernel sobre arquitectura risc-v
     */

#include "kernel.h"
#include <stdio.h>
#include "task.h"
//#include "list.h"

int main() {
	printf("RISC-V Kernel\n");
    task_create(&task);
	kernel_launch();
}


/*  Only for remember
 *  asm volatile("wfi");
 *  asm volatile("ecall");
 *  task_create(&task1);
 *  semaphore_init(&semaphore, 1);
 */
