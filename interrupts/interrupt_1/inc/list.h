#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include "kalloc.h"
#include "stdint.h"

typedef  void (*task_callback_t)(void/*int *count*/);

struct node {
   task_callback_t data;
   int key;
   int state;
   int *address_memory;
   struct node *next;
};

void insertFirst(int key, task_callback_t data);
void insertLast(int key, task_callback_t data);
struct node* deleteFirst();
bool isEmpty();
int length();
struct node* find(int key);
struct node* delete(int key);
void sort();
void reverse();


#endif