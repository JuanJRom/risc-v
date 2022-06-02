/*
 * list_1.c
 *
 *  Created on: 21 may. 2022
 *      Author: jjrh
 */
#include "list.h"

list_t* createList(list_t* list){
    list = (list_t*) malloc(sizeof(list_t));
    list->head = NULL;
    return list;
}

void destroyList(list_t* list){
    free(list);
}

node_t* createNode(){
    node_t* node = (node_t*) malloc(sizeof(node_t));
    node->stackPt =0;
    node->next = NULL;
    node->id = 0;
    node->state = 0;
    return node;
}

void destroyNode(node_t* node){
    free(node);
}

void addFirst(list_t* list, node_t* node_1){
    node_t* node = createNode();
    node->id = node_1->id;
	node->stackPt = node_1->stackPt;
	node->state = node_1->state;
    node->next = list->head;
    list->head = node;
}

void addLast(list_t* list, node_t* node_1){
    node_t* node = createNode();
    node->id = node_1->id;
    node->stackPt = node_1->stackPt;
    node->state = node_1->state;
    if(list->head == NULL){
        node->next = list->head;
        list->head = node;
    }else{
        node_t* temp_node = list->head;
        while (temp_node->next != NULL){
            temp_node = temp_node->next;
        }
        temp_node->next = node;
    }
}

void addAfter(int n, list_t* list, node_t* node_1){
    node_t* node = createNode();
    node->id = node_1->id;
    node->stackPt = node_1->stackPt;
    node->state = node_1->state;
    if(list->head == NULL){
        node->next = list->head;
        list->head = node;
    }else{
        node_t* temp_node = list->head;
        int position = 0;
        while (position < n && temp_node->next != NULL){
            temp_node = temp_node->next;
            position++;
        }
        node->next = temp_node->next;
        temp_node->next = node;
    }
}

node_t* get(int n, list_t* list){
    if(list->head==NULL){
        return NULL;
    }else{
        node_t* temp_node = list->head;
        int position = 0;
        while (position < n && temp_node->next != NULL){
            temp_node = temp_node->next;
            position++;
        }
        if(position !=n){
            return NULL;
        }else{
            return temp_node;
        }
    }
}

int length(list_t* list){
    int length = 0;
    node_t* temp_node;
    for(temp_node = list->head; temp_node != NULL; temp_node = temp_node->next){
        length++;
    }
    return length;
}

int isEmpty(list_t* list){
   return list->head == NULL;
}

void deleteFirst(list_t* list){
    if(list->head != NULL){
        node_t* temp_node = list->head;
        list->head = list->head->next;
        destroyNode(temp_node);
    }
}

void deleteLast(list_t* list){
    if(list->head != NULL){
        if(list->head->next != NULL){
            node_t* temp_node = list->head;
            while(temp_node->next->next){
                temp_node = temp_node->next;
            }
            node_t* node_delete = temp_node->next;
            temp_node->next = NULL;
            destroyNode(node_delete);
        }else{
            node_t* node_delete = list->head;
            list->head = NULL;
            destroyNode(node_delete);
        }
    }
}

void deleteElement(list_t* list,int id) {

   node_t* current = list->head;
   node_t* previous = NULL;

   if(list->head == NULL) {
      return;
   }

   while(current->id != id) {
      if(current->next == NULL) {
         return;
      } else {
         previous = current;
         current = current->next;
      }
   }

   if(current == list->head) {
      list->head = list->head->next;
   } else {
      previous->next = current->next;
   }
}

node_t* find(list_t* list, int id){
    node_t* temp_node = list->head;
    if(list->head == NULL){
        return NULL;
    }
    while (temp_node->id != id){
        if(temp_node->next == NULL){
            return NULL;
        }else{
            temp_node = temp_node->next;
        }
    }
    return temp_node;
}


void printList(list_t* list) {
    node_t* node = list->head;
    while (node != NULL){
        printf("ID: %d, State: %d, Stack address: %x \n", node->id, node->state, node->stackPt);
        node = node->next;
    }
}
