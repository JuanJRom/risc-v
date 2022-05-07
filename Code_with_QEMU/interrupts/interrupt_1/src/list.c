#include "list.h"

struct PCB *head = NULL;
struct PCB *current = NULL;


//display the list
void printList() {
   struct PCB *ptr = head;
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
void insertFirst(int id, task_callback_t task, int registers) {
   //create a link
   struct PCB *link = (struct PCB*) kalloc(sizeof(struct PCB));
   link->id = id;
   link->task = task;
   link->registers = registers;
	
   //point it to old first PCB
   link->next = head;
	
   //point first to new first PCB
   head = link;
}

//insert link at the last location
void insertLast(int id, task_callback_t task) {
   //create a link
   struct PCB *tempLink;
   struct PCB *link = (struct PCB*) kalloc(sizeof(struct PCB));
   link->id = id;
   link->task = task;
	
   if(head == NULL){
      link->next = head;
      head = link;
   }else{
      tempLink = head;
      while(tempLink->next !=NULL){
         tempLink = tempLink->next;
      }
      tempLink->next = link;
   }
}

//delete first item
struct PCB* deleteFirst() {

   //save reference to first link
   struct PCB *tempLink = head;
	
   //mark next to first link as first 
   head = head->next;
	
   //return the deleted link
   return tempLink;
}

//is list empty
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct PCB *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

//find a link with given id
struct PCB* find(int id) {

   //start from the first link
   struct PCB* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->id != id) {
	
      //if it is last PCB
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	
   //if task found, return the current Link
   return current;
}

//delete a link with given id
struct PCB* delete(int id) {

   //start from the first link
   struct PCB* current = head;
   struct PCB* previous = NULL;
	
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->id != id) {

      //if it is last PCB
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }    
	
   return current;
}

void sort() {

   int i, j, k, temp_id;
   task_callback_t tempTask;
   struct PCB *current;
   struct PCB *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( current->task > next->task ) {
            tempTask = current->task;
            current->task = next->task;
            next->task = tempTask;

            temp_id = current->id;
            current->id = next->id;
            next->id = temp_id;
         }
			
         current = current->next;
         next = next->next;
      }
   }   
}

void reverse(struct PCB** head_ref) {
   struct PCB* prev   = NULL;
   struct PCB* current = *head_ref;
   struct PCB* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *head_ref = prev;
}

/*
void test_list() {
   print_s("Firts test\n");
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56); 
   print_s("Original List: "); 
	
   //print list
   printList();
   while(!isEmpty()) {            
      struct PCB *temp = deleteFirst();
      print_s("\nDeleted value:");
      //printf("(%d,%d) ",temp->id,temp->task);
      print_s("( ");
      print_i(temp->id);
      print_s(" , ");
      print_i(temp->task);
      print_s(") ");
   }  
	
   print_s("\nList after deleting all items: ");
   printList();
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56);
   
   print_s("\nRestored List: ");
   printList();
   print_s("\n");  
   struct PCB *foundLink = find(4);
	
   if(foundLink != NULL) {
      print_s("Element found: ");
      //printf("(%d,%d) ",foundLink->id,foundLink->task);
      print_s("( ");
      print_i(foundLink->id);
      print_s(" , ");
      print_i(foundLink->task);
      print_s(") ");
      print_s("\n");  
   } else {
      print_s("Element not found.");
   }
   delete(4);
   print_s("List after deleting an item: ");
   printList();
   print_s("\n");
   foundLink = find(4);
	
   if(foundLink != NULL) {
      print_s("Element found: ");
      //printf("(%d,%d) ",foundLink->id,foundLink->task);
      print_s("( ");
      print_i(foundLink->id);
      print_s(" , ");
      print_i(foundLink->task);
      print_s(") ");
      print_s("\n"); 
      print_s("\n");
   } else {
      print_s("Element not found.");
   }
	
   print_s("\n");
   sort();
	
   print_s("List after sorting the task: ");
   printList();
	
   reverse(&head);
   print_s("\nList after reversing the task: ");
   printList();
}*/