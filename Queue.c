// File: Queue.c
// Description: Implements a basic Queue type.
// Author: Tessa Pham
// Date: 04/22/2018

#include <stdlib.h>

#include "List.h"
#include "Queue.h"

Queue *newQueue() {
	Queue *q = malloc(sizeof(Queue));
	q->L = newList();
	return q;
}

int sizeQ(const Queue *q) {
	return size(q->L);
} 

int emptyQ(const Queue *q) {
	return empty(q->L);
}

void insertQ(Queue *q, void *item) {
	add(q->L, item);
}

void *removeQ(Queue *q) {
	return removeItem(q->L, 0);
}

//--------------------------------------------------------------------------------
