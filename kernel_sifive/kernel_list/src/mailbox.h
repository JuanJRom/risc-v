/*
 * mailbox.h
 *
 *  Created on: 2 jun. 2022
 *      Author: jjrh
 */

#ifndef MAILBOX_H_
#define MAILBOX_H_

#include "semaphore.h"

static short unsigned int MB_hasdata;
static unsigned int MB_data;
static semaphore_t MB_Sem;

void mailbox_init(void);
void mailbox_send(unsigned int MB_data);
unsigned int mailbox_recv(void);


#endif /* MAILBOX_H_ */
