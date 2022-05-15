/*
 * queue.h
 *
 *  Created on: 7 may. 2022
 *      Author: jjrh
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "list.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void queue_printList(void);
//struct pcb* queue_giveFirst(void);
struct pcb* queue_insertFirst(int id, int Current_state);
struct pcb* queue_deleteFirst(void);
bool queue_isEmpty(void);
int queue_length(void);
struct pcb* queue_find(int id);
struct pcb* queue_delete(int id);
//void queue_sort(void);
//void queue_reverse(struct pcb** head_ref);

#endif /* QUEUE_H_ */
