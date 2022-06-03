#include <stdio.h>
#include "list.h"

int main(){

    PCB_t* pcb_1 =createPCB(pcb_1);
    pcb_1->id = 1;
   
    list_t* readyList = createList(readyList);

    addLast(readyList,pcb_1);
    pcb_1->id = 2;
    addLast(readyList,pcb_1);
    pcb_1->id = 3;
    addLast(readyList,pcb_1);

    printf("This is the list\n");
    printList(readyList);
    printf("Find 3 : %d \n", find(readyList,3)->pcb.id);
    printf("The length of list is: %d\n", length(readyList));

    list_t* waitQueue= createList(waitQueue);

    PCB_t* pcb_2= createPCB(pcb_2);
    
    pcb_2->id = 4;
    
    addLast(waitQueue,pcb_2);
    pcb_2->id = 5;
    addLast(waitQueue,pcb_2);
    pcb_2->id = 6;
    addLast(waitQueue,pcb_2);
    pcb_2->id = 9;
    addAfter(1,waitQueue,pcb_2);

    
    printf("This is the queue\n");
    deleteLast(waitQueue);
    printList(waitQueue);
    printf("The length of list is: %d\n", length(waitQueue));
    printf("test get: %d ", get(1,waitQueue)->pcb.id);

    destroyList(waitQueue);

    return 0;
   
}


