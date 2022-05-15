/* Juan Jose Romero Hernandez */
/* Diseño de kernel sobre arquitectura risc-v*/

#include "kernel.h"
#include "semaphore.h"
#include "riscv.h"
#include <stdio.h>
#include "list.h"
#include "task.h"



int main() {
	semaphore_init(&semaphore, 1);
	printf("RISC-V Kernel\n");
	task_create(&task);
	kernel_launch();
	//asm volatile("wfi");
}

