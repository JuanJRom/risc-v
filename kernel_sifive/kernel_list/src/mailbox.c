/*
 * mailbox.c
 *
 *  Created on: 2 jun. 2022
 *      Author: jjrh
 */

#include "mailbox.h"

void mailbox_init(void){
	MB_hasdata = 0;
	MB_data = 0;
	semaphore_init(&MB_Sem, 1);
}

void mailbox_send(unsigned int data){
	intr_off();
	if(MB_hasdata){
		intr_on();
		return;
	}

	MB_data = data;
	MB_hasdata =1;
	intr_on();
	semaphore_signal(&MB_Sem);
}

unsigned int mailbox_recv(void){
	semaphore_wait(&MB_Sem);
	unsigned int data;
	intr_off();
	data = MB_data;
	MB_hasdata = 0;
	intr_on();
	return data;
}

