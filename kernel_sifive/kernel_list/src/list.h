/*
 * list.h
 *
 *  Created on: 8 mar. 2022
 *      Author: jjrh
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

enum state{ready, running, waiting};

struct pcb {
	int32_t *stackPt;
	struct pcb *nextPt;
    int id;
    enum state Current_state;
};

void printList(void);
//struct pcb* giveFirst(void);
struct pcb* insertFirst(int id, int Current_state);
struct pcb* deleteFirst(void);
bool isEmpty(void);
int length(void);
struct pcb* find(int id);
struct pcb* delete(int id);
//void sort(void);
//void reverse(struct pcb** head_ref);

#endif /* LIST_H_ */
