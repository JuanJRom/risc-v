/*
 * list.h
 *
 *  Created on: 31 may. 2022
 *      Author: jjrh
 */

#ifndef list_h
#define list_h

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

enum state_t{ready, running, waiting};

typedef struct node{
    int32_t *stackPt;
    struct node* next;
    int32_t id;
    enum state_t state;
}node_t;

typedef struct list{
    node_t* head;
    int length;
}list_t;

list_t* createList(list_t* list);
void destroyList(list_t* list);
node_t* createNode();
void destroyNode(node_t* node);
void addFirst(list_t* list, node_t* node_1);
void addLast(list_t* list, node_t* node_1);
void addAfter(int n, list_t* list, node_t* node_1);
node_t* get(int n, list_t* list);
int length(list_t* list);
int isEmpty(list_t* list);
void deleteFirst(list_t* list);
void deleteLast(list_t* list);
void deleteElement(list_t* list, int id);
node_t* find(list_t* list, int id);
void printList(list_t* list);

#endif
