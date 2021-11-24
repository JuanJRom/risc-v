#include "main.h"
#include "list.h"

int main(){
    

    print_s("Kernel RISC-V");
    print_s("\n");
    task_create(1, process_1); 
    task_create(2, process_2);    
    task_create(3, process_3);
    task_create(4, process_4); 
    
    //task_create(5, process_5);
    //task_create(6, process_6);
    //task_end(proccess_1);  //trap_entry
    //task_wait();
   while (1){
        asm volatile ("wfi");
        //schedule task 

        //task_create(1, process_1); 
        //task_create(2, process_2);    
        //task_create(3, process_3);
        //task_create(4, process_4); 
        
    };
}

