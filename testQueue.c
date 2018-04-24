// File: testQ.c
// Purpose: To test the functionality of the Q
// Written by: Deepak Kumar
// Date: April 2018

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main(void) {

   Queue *Q;
   Q = newQueue();	// Create a queue

   // test size() and empty()
   printf("Q Size = %d\n", sizeQ(Q));
   if (emptyQ(Q))
      printf("The queue is empty.\n");
   else
      printf("The queue is not empty.\n");

   // Add some random ints to queue (using insert())
   int *n;
   printf("Adding: ");
   for (int i=0; i < 10; i++) {
      n = malloc(sizeof(int));
      *n = rand()%100; 
      printf("%d ", *n);
      insertQ(Q, n);
   }
   printf("\n");
   
   // test size() and empty()
   printf("Q Size = %d\n", sizeQ(Q));
   if (emptyQ(Q))
      printf("The queue is empty.\n");
   else
      printf("The queue is not empty.\n");

   // Remove some entries from queue (using remove())
   for (int i = 0; i < 8; i++) {
      n = removeQ(Q);
      printf("Removed: %d\n", *n);
   }

   // test size() and empty()
   printf("Q Size = %d\n", sizeQ(Q));
   if (emptyQ(Q))
      printf("The queue is empty.\n");
   else
      printf("the queue is not empty.\n");
  
   return 0;
} // main()
