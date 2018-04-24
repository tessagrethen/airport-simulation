// File: Customer.c
// Description: Implements a Customer type.
// Author: Tessa Pham
// Date: 04/22/2018

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Customer.h"

static int count = 0;

char *genCustId() {
	count++;
	char *id = malloc(5 * sizeof(char));
	sprintf(id, "C%d", count);
	return id;
} // genCustId()

Customer *newCustomer (int at) {
	Customer *c = malloc(sizeof(Customer));
	c->id = genCustId();
	c->arrivalTime = at;
	c->serviceTime = 5 + rand() % 4;
	return c;
}

char *getCustId(const Customer *c) {
	return c->id;
}

int getArrivalTime(const Customer *c) {
	return c->arrivalTime;
}

int getServiceTime (const Customer *c) {
	return c->serviceTime;
}

char *custToString(const Customer *c) {
	char *result = malloc(20 * sizeof(char));
	
	if (c) {
		sprintf(result, "<%s: %d, %d>", c->id, c->arrivalTime, c->serviceTime);
	} else {
		sprintf(result, "<Customer: NULL>");
	}

	return result;
}

//--------------------------------------------------------------------------------
