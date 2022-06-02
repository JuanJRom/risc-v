/*
 * semaphore.h
 *
 *  Created on: 15 mar. 2022
 *      Author: jjrh
 */

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

void osSemaphoreInit(int32_t *semaphore, int32_t value);
void semaphore_signal(int32_t *semaphore);
void semaphore_wait(int32_t *semaphore);

#endif /* SEMAPHORE_H */
