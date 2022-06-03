#ifndef list_h
#define list_h

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

enum state_t{ready, running, waiting};

typedef struct PCB{
    int32_t id;
    enum state_t state;
    int32_t *stackPt;
}PCB_t;

typedef struct node{
    PCB_t pcb;
    struct node* next;
}node_t;

typedef struct list{
    node_t* head;
    int length;
}list_t;

PCB_t* createPCB(PCB_t* pcb);
void destroyPCB(PCB_t* pcb);
list_t* createList(list_t* list);
void destroyList(list_t* list);
node_t* createNode(PCB_t* pcb);
void destroyNode(node_t* node);
void addFirst(list_t* list, PCB_t* pcb);
void addLast(list_t* list, PCB_t* pcb);
void addAfter(int n, list_t* list, PCB_t* pcb);
node_t* get(int n, list_t* list);
int length(list_t* list);
int isEmpty(list_t* list);
void deleteFirst(list_t* list);
void deleteLast(list_t* list);
node_t* find(list_t* list, int id);

void printList(list_t* list);

#endif 
