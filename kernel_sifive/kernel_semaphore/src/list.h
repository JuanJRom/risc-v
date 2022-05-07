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

void printList(void);
void insertFirst(int key, int data);
struct node* deleteFirst(void);
bool isEmpty(void);
int length(void);
struct node* find(int key);
struct node* delete(int key);
void sort(void);
void reverse(struct node** head_ref);

#endif /* LIST_H_ */
