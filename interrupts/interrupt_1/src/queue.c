#include "queue.h"

struct PCB *head_Queue = NULL;
struct PCB *current_Queue = NULL;


//display the list
void printQueue() {
   struct PCB *ptr = head_Queue;
   print_s("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      //printf("(%d,%d) ",ptr->id,ptr->task);
      print_s("( ");
      print_i(ptr->id);
      print_s(" , ");
      print_i(ptr->task);
      print_s(") ");
      ptr = ptr->next;
   }
	
   print_s(" ]");
}

//insert link at the first location
void insertFirstQueue(int id, task_callback_t task, int registers) {
   //create a link
   struct PCB *link = (struct PCB*) kalloc(sizeof(struct PCB));
   link->id = id;
   link->task = task;
   link->registers = registers;
   
   //point it to old first node
   link->next = head_Queue;
	
   //point first to new first node
   head_Queue = link;
}

//insert link at the last location
void insertLastQueue(int id, task_callback_t task) {
   //create a link
   struct PCB *tempLink;
   struct PCB *link = (struct PCB*) kalloc(sizeof(struct PCB));
   link->id = id;
   link->task = task;
	
   if(head_Queue == NULL){
      link->next = head_Queue;
      head_Queue = link;
   }else{
      tempLink = head_Queue;
      while(tempLink->next !=NULL){
         tempLink = tempLink->next;
      }
      tempLink->next = link;
   }
}

//delete first item
struct PCB* deleteFirstQueue() {

   //save reference to first link
   struct PCB *tempLink = head_Queue;
	
   //mark next to first link as first 
   head_Queue = head_Queue->next;
	
   //return the deleted link
   return tempLink;
}

//is list empty
bool isEmptyQueue() {
   return head_Queue == NULL;
}

int lengthQueue() {
   int length = 0;
   struct PCB *current_Queue;
	
   for(current_Queue = head_Queue; current_Queue != NULL; current_Queue = current_Queue->next) {
      length++;
   }
	
   return length;
}

//find a link with given id
struct PCB* findQueue(int id) {

   //start from the first link
   struct PCB* current_Queue = head_Queue;

   //if list is empty
   if(head_Queue == NULL) {
      return NULL;
   }

   //navigate through list
   while(current_Queue->id != id) {
	
      //if it is last node
      if(current_Queue->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current_Queue = current_Queue->next;
      }
   }      
	
   //if task found, return the current_Queue Link
   return current_Queue;
}

//delete a link with given id
struct PCB* deleteQueue(int id) {

   //start from the first link
   struct PCB* current_Queue = head_Queue;
   struct PCB* previous = NULL;
	
   //if list is empty
   if(head_Queue == NULL) {
      return NULL;
   }

   //navigate through list
   while(current_Queue->id != id) {

      //if it is last node
      if(current_Queue->next == NULL) {
         return NULL;
      } else {
         //store reference to current_Queue link
         previous = current_Queue;
         //move to next link
         current_Queue = current_Queue->next;
      }
   }

   //found a match, update the link
   if(current_Queue == head_Queue) {
      //change first to point to next link
      head_Queue = head_Queue->next;
   } else {
      //bypass the current_Queue link
      previous->next = current_Queue->next;
   }    
	
   return current_Queue;
}

void sortQueue() {

   int i, j, k, temp_id;
   task_callback_t tempTask;
   struct PCB *current_Queue;
   struct PCB *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current_Queue = head_Queue;
      next = head_Queue->next;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( current_Queue->task > next->task ) {
            tempTask = current_Queue->task;
            current_Queue->task = next->task;
            next->task = tempTask;

            temp_id = current_Queue->id;
            current_Queue->id = next->id;
            next->id = temp_id;
         }
			
         current_Queue = current_Queue->next;
         next = next->next;
      }
   }   
}

void reverseQueue(struct PCB** head_ref) {
   struct PCB* prev   = NULL;
   struct PCB* current_Queue = *head_ref;
   struct PCB* next;
	
   while (current_Queue != NULL) {
      next  = current_Queue->next;
      current_Queue->next = prev;   
      prev = current_Queue;
      current_Queue = next;
   }
	
   *head_ref = prev;
}