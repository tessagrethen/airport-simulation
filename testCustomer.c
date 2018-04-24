// File: testCust.c
// Purpose: To test the unit/module Customer
// Written By: Deepak Kumar
// Date: April, 2018

#include <stdio.h>
#include "Customer.h"

int main(void) {

   Customer *cs[5];
   int t = 23;
   for (int i=0; i < 5; i++) { // Create five customers
      cs[i] = newCustomer(t); 
      t++;
   }

   for (int i=0; i < 5; i++) {	// print out details
      printf("<%s: %d, %d>\n", cs[i]->id, cs[i]->arrivalTime, cs[i]->serviceTime);
      printf("Customer id: %s, Arr: %d, Ser: %d\n", getCustId(cs[i]), getArrivalTime(cs[i]), getServiceTime(cs[i]));
      printf("%s\n", custToString(cs[i]));
      printf("-------------------\n");
   }
  

   return 0;
} // main()
