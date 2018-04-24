// File: Kiosk.h
// Description: Defines a Kiosk type.
// Author: Tessa Pham
// Date: 04/22/2018

#ifndef KIOSK_H
#define KIOSK_H

#include "Customer.h"

typedef struct {
	char *id;
	Customer *nowServing;
	int timeRemaining;
} Kiosk;

Kiosk *newKiosk();

// Accessors
char *getKioskId(const Kiosk *k);
Customer *getCustomer(const Kiosk *k);

void assignCustomer(Kiosk *k, Customer *c);
void tick(Kiosk *k);
int busy(const Kiosk *k);
int getNServed();
char *kioskToString(const Kiosk *k);

#endif

//--------------------------------------------------------------------------------
