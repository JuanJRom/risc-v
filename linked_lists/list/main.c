#include <stdio.h>
#include "list.h"

int main(){

    list_t* readyList = createList(readyList);
    node_t* temp_node = createNode();
    int temp= 8000, temp1=8001,  temp2=8002,  temp3=8003;
    temp_node->id = 1;
    temp_node->stackPt= &temp;
    temp_node->state = 0;
    addLast(readyList, temp_node);
    temp_node->id = 2;
     temp_node->stackPt= &temp1;
    temp_node->state = 0;
    addLast(readyList, temp_node);
    temp_node->id = 3;
     temp_node->stackPt= &temp2;
    temp_node->state = 0;
    addLast(readyList, temp_node);
    temp_node->id = 4;
     temp_node->stackPt= &temp3;
    temp_node->state = 0;
    addLast(readyList, temp_node);
    
    

    printf("This is the list\n");
    printList(readyList);
    printf("Find 4 : %d \n", find(readyList,4)->id);
    printf("The length of list is: %d\n", length(readyList));

    list_t* waitQueue= createList(waitQueue);
    temp_node = get(3,readyList);
    addLast(waitQueue, temp_node);
    deleteElement(readyList, 4);
    printf("\nThis is the Queue\n");
    printList(waitQueue);
    printf("\nThis is the list before change\n");
    printList(readyList);

    temp_node = get(0,waitQueue);
    addLast(readyList, temp_node);
    printf("\nThis is the list after change\n");
    printList(readyList);

    return 0;
   
}


