#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include "kalloc.h"
#include "stdint.h"

typedef void (*task_callback_t)(void/*int *count*/);

struct PCB {
   task_callback_t task;
   int id;
   int state;
   long long int registers;
   int procces_stack[40];         // Reserva de espacio para el proceso 
   int *sp_procces;               // stack pointer que apunta al stack 
   struct PCB *next;
};

void insertFirst(int id, task_callback_t task, int registers);
void insertLast(int id, task_callback_t task);
struct PCB* deleteFirst();
bool isEmpty();
int length();
struct PCB* find(int id);
struct PCB* delete(int id);
void sort();
void reverse();


#endif