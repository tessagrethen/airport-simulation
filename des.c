#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Queue.h"
#include "Kiosk.h"
#include "Customer.h"

int arrivals();	// Returns the number of customers that arrived (any value between 0 - 3).
void simulate(int m, int k);

int main(int argc, char *argv[]) {
	srand(time(NULL));

	if (argc != 3) {
		printf("Cannot proceed: Missing arguments.");
		exit(EXIT_FAILURE);
	}

	int m = atoi(argv[1]), nk = atoi(argv[2]);

	simulate(m, nk);

	return 0;
}

int arrivals() {
	return 0 + rand() % 4;
}

void simulate(int m, int nk) {
	Kiosk *kiosks[nk];

	// Creates nk kiosks.
	for (int i = 0; i < nk; i++) {
		kiosks[i] = newKiosk();
	}

	printf("There are %d kiosks.\n", nk);
	printf("[ ");

	for (int i = 0; i < nk; i++) {
		printf("%s ", kioskToString(kiosks[i]));
	}

	printf("]\n");

	// Creates a queue of customers.
	Queue *checkInQueue;
	checkInQueue = newQueue();

	int nc = 0;	// Total customers arrived.

	// For each minute...
	for (int t = 1; t <= m; t++) {
		// n customers arrive.
		int n = arrivals();

		// Creates and adds each customer to the queue.
		for (int i = 1; i < n; i++) {
			Customer *c = newCustomer(t);
			insertQ(checkInQueue, c);
			nc++;
		}

		printf("At time %d, there are %d customers on queue.\n", t, sizeQ(checkInQueue));

		// Checks for idle kiosks.
		for (int k = 0; k < nk; k++) {
			if (!busy(kiosks[k]) && !emptyQ(checkInQueue)) {
				Customer *c = removeQ(checkInQueue);
				assignCustomer(kiosks[k], c);
			}
		}
		
		// Prints out status of all kiosks.
		printf("[ ");

		for (int i = 0; i < nk; i++) {
			printf("%s ", kioskToString(kiosks[i]));
		}

		printf("]\n");
	}

}

//--------------------------------------------------------------------------------
