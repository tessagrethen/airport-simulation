// File: Customer.h
// Description: Defines a Customer type.
// Author: Tessa Pham
// Date: 04/22/2018

#ifndef CUSTOMER_H
#define CUSTOMER_H

typedef struct {
	char *id;
	int arrivalTime;
	int serviceTime;
} Customer;

Customer * newCustomer(int time);

// Accessors
char *getCustId(const Customer *c);
int getArrivalTime(const Customer *c);
int getServiceTime(const Customer *c);

// Print Form
char *custToString(const Customer *c);

#endif

//--------------------------------------------------------------------------------
