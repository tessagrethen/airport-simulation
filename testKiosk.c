// File: testKiosk.c
// Purpose: Tests the Kiosk unit/module functionality
//	Not everything is tested here...this is a starter program
//	Also, this should only be done after Customer is fully tested.
#include <stdio.h>
#include "Kiosk.h"
#include "Customer.h"

int main(void) {

   Kiosk *ks[5];
   for (int i=0; i < 5; i++) {	// Create five kiosks
      ks[i] = newKiosk(); 
   }

   for (int i=0; i < 5; i++) { // print out status of each kiosk
      printf("<%s: %d>\n", ks[i]->id, ks[i]->timeRemaining);
      printf("%s\n", kioskToString(ks[i]));
   }
  

   return 0;
} // main()
