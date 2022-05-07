/*
 * list.c
 *
 *  Created on: 8 mar. 2022
 *      Author: jjrh
 */

#include "list.h"

struct pcb *head = NULL;
struct pcb *current = NULL;

//display the list
void printList() {
   struct pcb *ptr = head;
   printf("\n[ ");

   //start from the beginning
   while(ptr != NULL) {
      printf("(ID: %d, State: %d) ", ptr->id ,ptr->Current_state);
      ptr = ptr->nextPt;
   }

   printf(" ]");
}

//insert link at the first location
struct pcb* insertFirst(int id, int Current_state) {
   //create a link
   struct pcb *link = (struct pcb*) malloc(sizeof(struct pcb));

   link->id = id;
   link->Current_state = Current_state;

   //point it to old first pcb
   link->nextPt = head;

   //point first to new first pcb
   head = link;

   return head;
}

//give the first pcb
//struct pcb* giveFirst(void){
//	struct pcb *tempLink = head;
//	return tempLink;
//}

//delete first item
struct pcb* deleteFirst() {

   //save reference to first link
   struct pcb *tempLink = head;

   //mark next to first link as first
   head = head->nextPt;

   //return the deleted link
   return tempLink;
}

//is list empty
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct pcb *current;

   for(current = head; current != NULL; current = current->nextPt) {
      length++;
   }

   return length;
}

//find a link with given id
struct pcb* find(int id) {

   //start from the first link
   struct pcb* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->id != id) {

      //if it is last pcb
      if(current->nextPt == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->nextPt;
      }
   }

   //if Current_state found, return the current Link
   return current;
}

//delete a link with given id
struct pcb* delete(int id) {

   //start from the first link
   struct pcb* current = head;
   struct pcb* previous = NULL;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->id != id) {

      //if it is last pcb
      if(current->nextPt == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->nextPt;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->nextPt;
   } else {
      //bypass the current link
      previous->nextPt = current->nextPt;
   }

   return current;
}
/*
void sort() {

   int i, j, k, tempid, tempCurrent_state;
   struct pcb *current;
   struct pcb *nextPt;

   int size = length();
   k = size ;

   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      nextPt = head->nextPt;

      for ( j = 1 ; j < k ; j++ ) {

         if ( current->Current_state > nextPt->Current_state ) {
            tempCurrent_state = current->Current_state;
            current->Current_state = nextPt->Current_state;
            nextPt->Current_state = tempCurrent_state;

            tempid = current->id;
            current->id = nextPt->id;
            nextPt->id = tempid;
         }

         current = current->nextPt;
         nextPt = nextPt->nextPt;
      }
   }
}

void reverse(struct pcb** head_ref) {
   struct pcb* prev   = NULL;
   struct pcb* current = *head_ref;
   struct pcb* nextPt;

   while (current != NULL) {
      nextPt  = current->nextPt;
      current->nextPt = prev;
      prev = current;
      current = nextPt;
   }

   *head_ref = prev;
}*/
