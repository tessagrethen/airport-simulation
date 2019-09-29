#ifndef LIST_H
#define LIST_H

#include "node.h"

typedef struct {
   int size;
   struct node *head;
   struct node *tail;
} List;

List *newList();
int size(const List *l);
int empty(const List *l);
void clear(List *l);
void add(List *l, void *item);
void addAt(List *l, int index, void *item);
void *get(const List *L, int index);
void* set(List *l, int index, void *item);
void* removeItem(List *l, int index);
void *contains(const List *l, void *item, int (*comp)(const void *, const void *));

void print(const List *l);

struct ListIterator *newIterator(List *l);
int hasNext(struct ListIterator *it);
void* next(struct ListIterator *it);
void clearIterator(struct ListIterator *it);

#endif