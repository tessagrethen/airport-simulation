#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "List.h"

List *newList() {			// Creates a new empty list
  List *L = malloc(sizeof(List));
  L->head = NULL;
  L->tail = NULL;
  L->size = 0;
  return L; 
} // newList()

int size(const List *l) {		// Returns the size of list-l
   return l->size;
} // size()

int empty(const List *l) {		// is the list-l empty?
   return l->size == 0;
} // empty()

void clear(List *l) {		// removes all items from list-l
   struct node *n = l->head;
   struct node *nxt;
   while (n != NULL) {
      nxt = n->next;
      //free(n->data);
      free(n);
      n = nxt; 
   }
   l->head = l->tail = NULL;
   l->size = 0;
} // clear()

void add(List *l, void *item) {	// Add item at end of list-l
   struct node *n= newNode(item);
   if (l->size == 0)
     l->head = l->tail = n;
   else {
      l->tail->next = n;
      l->tail = n;
   }
   l->size++;
} // add()

void addAt(List *l, int index, void *item) {	// Add item at index in list-l
   if (index < 0 || index > l->size) {
      printf("Error: List index out of bounds %d. Exiting!\n", index);
      exit(EXIT_FAILURE);
   }

   struct node *n = newNode(item);
   if (index == 0) { // adding at front
      if (l->size == 0)	// of an empty list
        l->head = l-> tail = n; 
     else {	// list with >1 element
        n->next = l->head;
        l->head = n;
     }
   }
   else if (index == l->size) {  // adding at end
      l->tail->next = n;
      l->tail = n;
   }
   else { // adding in the middle
      struct node *p = l->head;
      for (int i=0; i < index-1; i++)
         p = p->next;
      n->next = p->next;
      p->next = n;
   }
   l->size++;
} // addAt()

void* get(const List *l, int index) {	// Returns item at index in list-l

   if (index < 0 || index >= l->size) {
      printf("Error: List index out of bounds %d. Exiting!\n", index);
      exit(EXIT_FAILURE);
   }

   struct node *n=l->head;
   for (int i=0; i < index; i++)
      n = n->next;
   return n->data;
} // get()

void *set(List *l, int index, void *item) {	// Change value at index to item, return
					// replaced item
   if (index < 0 || index >= l->size) {
      printf("Error: List index out of bounds %d. Exiting!\n", index);
      exit(EXIT_FAILURE);
   }

   struct node *n=l->head;
   for (int i=0; i < index; i++)
      n = n->next;
   void* old = n->data;
   n->data = item;

   return old;

}// set()

void* removeItem(List *l, int index) {	// Remove item at index and return it

   if (index < 0 || index >= l->size) {
      printf("Error: List index out of bounds %d. Exiting!\n", index);
      exit(EXIT_FAILURE);
   }

   void* item;	// item removed
   if (index == 0) {	// removing the first item
       item = l->head->data;
       if (l->size == 1) { // from a list with 1 item
         free(l->head);
         l->head = l->tail = NULL;
       }
       else {		// from a list with >1 items
          struct node *n = l->head;
          l->head = n->next;
          n->next = NULL;
          free(n);
       }
   }
   else {	// List has >1 item, go to the node before it
      struct node *n = l->head;
      for (int i=0; i < index-1; i++)
         n = n->next;
      item = n->next->data;
      if (index == l->size-1) {  // Removing the last item
         l->tail = n;
         free(n->next);
         l->tail->next = NULL;
      }
      else {	// Not the last item, but something in between...
	 struct node *r = n->next;	// node to be removed
         n->next = r->next;
         free(r);
      }
   }
   l->size--;
   return item;
} // removeItem()
	

void *contains(const List *l, void *item, int (*comp)(const void *, const void *)) {
   // Does list-l have item? Use compare() to check.
   struct node *n = l->head;
   while (n != NULL) {
      if (comp(n->data, item))
         return n->data;
      n = n->next;
   }
   return NULL;

} // contains()


void print(const List *l) {
   struct node *n = l->head;
   printf("L(%d) = ", l->size);
   while (n != NULL) {
      int *d = n->data;
      printf("%d ", *d);
      n = n->next;
   }
   printf("\n");
} // print()

//----------------Iterator Stuff

struct ListIterator {
   List *list;
   struct node *current;
};

struct ListIterator *newIterator(List *l) {
   struct ListIterator *it = malloc(sizeof(struct ListIterator));
   it->list = l;
   it->current = l->head;
   return it;
} // newIterator()

int hasNext(struct ListIterator *it) {
   return (it->current != NULL);
} // hasNext()

void* next(struct ListIterator *it) {	// This should really return a ptr
   void* data = NULL;		// Then this would be NULL
   if (it->current) {
      data = it->current->data;
      it->current = it->current->next;
   }
   return data;
} // next()

void clearIterator(struct ListIterator *it) {
   free(it);
} // clearIterator()
