
#include <stdlib.h>
#include "node.h"

struct node *newNode(void *item) {  // Creates a new node with item
   struct node *n = malloc(sizeof(struct node));
   n->data = item;
   n->next = NULL;
   return n;
} // newNode()

