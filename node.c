#include <stdlib.h>
#include "node.h"

struct node *newNode(void *item) {
   struct node *n = malloc(sizeof(struct node));
   n->data = item;
   n->next = NULL;
   return n;
}

