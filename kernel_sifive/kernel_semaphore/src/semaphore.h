/*
 * semaphore.h
 *
 *  Created on: 15 mar. 2022
 *      Author: jjrh
 */

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

void osSemaphoreInit(int32_t *semaphore, int32_t value);
void osSignalSet(int32_t *semaphore);
void osSignalWait(int32_t *semaphore);

#endif /* SEMAPHORE_H */
