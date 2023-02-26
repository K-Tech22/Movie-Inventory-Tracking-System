#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "hashtable.cpp"
#include "transaction.h"
#include <vector>

using namespace std;

class Customer
{

public:
    Customer();
    // customer constructor
    Customer(int id, string fname, string lname);
    // adds a transaction to the vector
    bool addTransaction(Transaction &);

    bool setCustomerId(Customer, int);
    // prints the vector
    void transactionHistory();

    string getFirstName();
    void setFirstName(string);

    string getLastName();
    void setLastName(string);

    int getID();

private:
    vector<Transaction> transactions;
    int id;
    string fname;
    string lname;
};

#endif