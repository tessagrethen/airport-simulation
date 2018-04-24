#ifndef LIST_H
#define LIST_H

#include "node.h"

typedef struct {
   int size;
   struct node *head;
   struct node *tail;
} List;

List *newList();			// Creates a new empty list
int size(const List *l);		// Returns the size of list-l
int empty(const List *l);		// is the list-l empty?
void clear(List *l);		// removes all items from list-l
void add(List *l, void *item);	// Add item at end of list-l
void addAt(List *l, int index, void *item);	// Add item at index in list-l
void *get(const List *L, int index);	// Returns item at index in list-l
void* set(List *l, int index, void *item);// Change value at index to item, return
					// replaced item
void* removeItem(List *l, int index);	// Remove item at index and return it
void *contains(const List *l, void *item, int (*comp)(const void *, const void *));
// Does list-l have item? Use compare() to check

void print(const List *l);	// prints contents of list (test only)


struct ListIterator *newIterator(List *l);
int hasNext(struct ListIterator *it);
void* next(struct ListIterator *it);
void clearIterator(struct ListIterator *it);

#endif
