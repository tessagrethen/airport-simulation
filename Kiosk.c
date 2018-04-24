// File: Kiosk.c
// Description: Implements a Kiosk type.
// Author: Tessa Pham
// Date: 04/22/2018

#include <stdlib.h>
#include <stdio.h>
#include "Kiosk.h"
#include "Customer.h"

static int nServed = 0;
static int count = 0;

char *genKioskId() {
	count++;
	char *id = malloc(5 * sizeof(char));
	sprintf(id, "K%d", count);
	return id;
}

Kiosk *newKiosk() {
	Kiosk *k = malloc(sizeof(Kiosk));
	k->id = genKioskId();
	k->nowServing = NULL;
	k->timeRemaining = 0;
	return k;
}

char *getKioskId(const Kiosk *k) {
	return k->id;
}

Customer *getCustomer(const Kiosk *k) {
	return k->nowServing;
}

void assignCustomer(Kiosk *k, Customer *c) {
	k->nowServing = c;
	k->timeRemaining = getServiceTime(c);
}

void tick(Kiosk *k) {
	if (k->nowServing) {
		k->timeRemaining--;

		if (k->timeRemaining == 0) {
			k->nowServing = NULL;
			nServed++;
		}
	}
}

int busy(const Kiosk *k) {
	return k->nowServing != NULL;
}

int getNServed() {	// returns total# Customers served so far in simulation
	return nServed;
} 

char *kioskToString(const Kiosk *k) {
	char *result = malloc(30 * sizeof(char));

	sprintf(result, "%s: %s", k->id, (k->nowServing ? custToString(k->nowServing): "<>"));

	return result;
}

//--------------------------------------------------------------------------------
