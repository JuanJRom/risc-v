#include "list.h"

PCB_t* createPCB(PCB_t* pcb){
    pcb = (PCB_t*) malloc(sizeof(PCB_t));
    pcb->id = 0;
    pcb->stackPt = 0;
    pcb->state = 0;
    return pcb;
}

void destroyPCB(PCB_t* pcb){
    free(pcb);
}

list_t* createList(list_t* list){
   list = (list_t*) malloc(sizeof(list_t));
    list->head = NULL;
    return list;
}

void destroyList(list_t* list){
    free(list);
}

node_t* createNode(PCB_t* pcb){
    node_t* node = (node_t*) malloc(sizeof(node_t));
    node->pcb.id = pcb->id;
    node->pcb.state = pcb->state;
    node->pcb.stackPt = pcb->stackPt;
    node->next = NULL;
    return node;
}

void destroyNode(node_t* node){
    free(node);
}

void addFirst(list_t* list, PCB_t* pcb){
    node_t* node = createNode(pcb);
    node->next = list->head;
    list->head = node;
}

void addLast(list_t* list, PCB_t* pcb){
    node_t* node = createNode(pcb);
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

void addAfter(int n, list_t* list, PCB_t* pcb){
    node_t* node = createNode(pcb);
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

node_t* find(list_t* list, int id){
    node_t* temp_node = list->head;
    if(list->head == NULL){
        return NULL;
    }
    while (temp_node->pcb.id != id){
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
        printf("%d \n", node->pcb.id);
        node = node->next;
    }
}