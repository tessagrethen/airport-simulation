// File: Queue.h
// Description: Defines a basic Queue type.
// Author: Tessa Pham
// Date: 04/22/2018

#ifndef QUEUE_H
#define QUEUE_H

#include "List.h"

typedef struct {
	List *L;
} Queue;

Queue *newQueue();

int sizeQ(const Queue *q);
int emptyQ(const Queue *q);
void insertQ(Queue *q, void *item);
void *removeQ(Queue *q);

#endif

//--------------------------------------------------------------------------------
