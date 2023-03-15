#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "transaction.h"
#include <vector>

using namespace std;

class Customer
{
    friend ostream &operator<<(ostream &, const Customer &);

public:
    Customer();
    // customer constructor
    Customer(int id, string fname, string lname);

    // adds a transaction to the vector
    bool addTransaction(Transaction &);

    bool setCustomerId(Customer, int);
    // prints the vector
    void transactionHistory() const;

    string getFirstName() const;
    void setFirstName(string);

    string getLastName() const;
    void setLastName(string);

    int getID() const;

    bool operator==(const Customer &) const;

private:
    vector<Transaction> transactions;
    int id;
    string fname;
    string lname;
};

#endif