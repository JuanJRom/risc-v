#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>
#include "kalloc.h"
#include "stdint.h"
#include "list.h"

typedef void (*task_callback_t)(void);

void printQueue();
void insertFirstQueue(int id, task_callback_t task, int registers);
//void insertLast(int id, task_callback_t task);
struct PCB* deleteFirstQueue();
bool isEmptyQueue();
int lengthQueue();
struct PCB* findQueue(int id);
struct PCB* deleteQueue(int id);
void sortQueue();
void reverseQueue();


#endif