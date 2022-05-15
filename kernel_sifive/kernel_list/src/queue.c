/*
 * queue.c
 *
 *  Created on: 7 may. 2022
 *      Author: jjrh
 */
#include "queue.h"

struct pcb *queue_head = NULL;
struct pcb *queue_current = NULL;

//display the list
void queue_printList() {
   struct pcb *ptr = queue_head;
   printf("\n[ ");

   //start from the beginning
   while(ptr != NULL) {
      printf("(ID: %d, State: %d) ", ptr->id ,ptr->Current_state);
      ptr = ptr->nextPt;
   }

   printf(" ]");
}

//insert link at the first location
struct pcb* queue_insertFirst(int id, int Current_state) {
   //create a link
   struct pcb *link = (struct pcb*) malloc(sizeof(struct pcb));

   link->id = id;
   link->Current_state = Current_state;

   //point it to old first pcb
   link->nextPt = queue_head;

   //point first to new first pcb
   queue_head = link;

   return queue_head;
}

//give the first pcb
//struct pcb* queue_giveFirst(void){
//	struct pcb *tempLink = queue_head;
//	return tempLink;
//}

//delete first item
struct pcb* queue_deleteFirst() {

   //save reference to first link
   struct pcb *tempLink = queue_head;

   //mark next to first link as first
   queue_head = queue_head->nextPt;

   //return the deleted link
   return tempLink;
}

//is list empty
bool queue_isEmpty() {
   return queue_head == NULL;
}

int queue_length() {
   int length = 0;
   struct pcb *queue_current;

   for(queue_current = queue_head; queue_current != NULL; queue_current = queue_current->nextPt) {
      length++;
   }

   return length;
}

//find a link with given id
struct pcb* queue_find(int id) {

   //start from the first link
   struct pcb* queue_current = queue_head;

   //if list is empty
   if(queue_head == NULL) {
      return NULL;
   }

   //navigate through list
   while(queue_current->id != id) {

      //if it is last pcb
      if(queue_current->nextPt == NULL) {
         return NULL;
      } else {
         //go to next link
         queue_current = queue_current->nextPt;
      }
   }

   //if Current found, return the current Link
   return queue_current;
}

//delete a link with given id
struct pcb* queue_delete(int id) {

   //start from the first link
   struct pcb* queue_current = queue_head;
   struct pcb* previous = NULL;

   //if list is empty
   if(queue_head == NULL) {
      return NULL;
   }

   //navigate through list
   while(queue_current->id != id) {

      //if it is last pcb
      if(queue_current->nextPt == NULL) {
         return NULL;
      } else {
         //store reference to queue_current link
         previous = queue_current;
         //move to next link
         queue_current = queue_current->nextPt;
      }
   }

   //found a match, update the link
   if(queue_current == queue_head) {
      //change first to point to next link
      queue_head = queue_head->nextPt;
   } else {
      //bypass the queue_current link
      previous->nextPt = queue_current->nextPt;
   }

   return queue_current;
}
/*
void sort() {

   int i, j, k, tempid, tempCurrent_state;
   struct pcb *current;
   struct pcb *nextPt;

   int size = length();
   k = size ;

   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = queue_head;
      nextPt = queue_head->nextPt;

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

