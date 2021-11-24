#include "list.h"

struct node *head = NULL;
struct node *current = NULL;


//display the list
void printList() {
   struct node *ptr = head;
   print_s("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      //printf("(%d,%d) ",ptr->key,ptr->data);
      print_s("( ");
      print_i(ptr->key);
      print_s(" , ");
      print_i(ptr->data);
      print_s(") ");
      ptr = ptr->next;
   }
	
   print_s(" ]");
}

//insert link at the first location
void insertFirst(int key, task_callback_t data) {
   //create a link
   struct node *link = (struct node*) kalloc(sizeof(struct node));
   link->key = key;
   link->data = data;
	
   //point it to old first node
   link->next = head;
	
   //point first to new first node
   head = link;
}

//insert link at the last location
void insertLast(int key, task_callback_t data) {
   //create a link
   struct node *tempLink;
   struct node *link = (struct node*) kalloc(sizeof(struct node));
   link->key = key;
   link->data = data;
	
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
struct node* deleteFirst() {

   //save reference to first link
   struct node *tempLink = head;
	
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
   struct node *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

//find a link with given key
struct node* find(int key) {

   //start from the first link
   struct node* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {
	
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	
   //if data found, return the current Link
   return current;
}

//delete a link with given key
struct node* delete(int key) {

   //start from the first link
   struct node* current = head;
   struct node* previous = NULL;
	
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {

      //if it is last node
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

   int i, j, k, tempKey;
   task_callback_t tempData;
   struct node *current;
   struct node *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( current->data > next->data ) {
            tempData = current->data;
            current->data = next->data;
            next->data = tempData;

            tempKey = current->key;
            current->key = next->key;
            next->key = tempKey;
         }
			
         current = current->next;
         next = next->next;
      }
   }   
}

void reverse(struct node** head_ref) {
   struct node* prev   = NULL;
   struct node* current = *head_ref;
   struct node* next;
	
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
      struct node *temp = deleteFirst();
      print_s("\nDeleted value:");
      //printf("(%d,%d) ",temp->key,temp->data);
      print_s("( ");
      print_i(temp->key);
      print_s(" , ");
      print_i(temp->data);
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
   struct node *foundLink = find(4);
	
   if(foundLink != NULL) {
      print_s("Element found: ");
      //printf("(%d,%d) ",foundLink->key,foundLink->data);
      print_s("( ");
      print_i(foundLink->key);
      print_s(" , ");
      print_i(foundLink->data);
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
      //printf("(%d,%d) ",foundLink->key,foundLink->data);
      print_s("( ");
      print_i(foundLink->key);
      print_s(" , ");
      print_i(foundLink->data);
      print_s(") ");
      print_s("\n"); 
      print_s("\n");
   } else {
      print_s("Element not found.");
   }
	
   print_s("\n");
   sort();
	
   print_s("List after sorting the data: ");
   printList();
	
   reverse(&head);
   print_s("\nList after reversing the data: ");
   printList();
}*/