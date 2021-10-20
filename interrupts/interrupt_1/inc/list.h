#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include "kalloc.h"
#include "stdint.h"

void insertFirst(int key, int data);
struct node* deleteFirst();
bool isEmpty();
int length();
struct node* find(int key);
struct node* delete(int key);
void sort();
void reverse();


#endif