#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "hashtable.cpp"
#include "transaction.h"
#include <vector>

using namespace std;

class Customer
{
    int id;
    string fname;
    string lname;

public:
    Customer();
    // customer constructor
    Customer(int, string, string);
    // adds a transaction to the vector
    bool addTransaction(Transaction &);

    bool setCustomerId(Customer, int);
    // prints the vector
    void transactionHistory();

private:
    vector<Transaction> transactions;
};

#endif