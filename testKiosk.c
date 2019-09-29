// File: testKiosk.c
// Description: Main program to test the Kiosk module. This should only be run after Customer is fully tested.
// Authors: Deepak Kumar, Tessa Pham
// Date: 04/22/2018

#include <stdio.h>
#include "Kiosk.h"
#include "Customer.h"

int main(void) {
   Kiosk *ks[5];
   for (int i = 0; i < 5; i++) {
      ks[i] = newKiosk(); 
   }

   for (int i = 0; i < 5; i++) {
      printf("<%s: %d>\n", ks[i]->id, ks[i]->timeRemaining);
      printf("%s\n", kioskToString(ks[i]));
   }
   return 0;
}
