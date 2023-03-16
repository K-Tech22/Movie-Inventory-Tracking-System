#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "transaction.h"
#include <vector>

using namespace std;

class Customer
{
    /**
     * operator<<
     *
     * @pre customer is not null
     * @post customer information will be outputted to the console
     */
    friend ostream &operator<<(ostream &, const Customer &);

public:
    /**
     * Constructor
     *
     * @pre none
     * @post Customer will be constructed, no instance variables will be set
     */
    Customer();

    /**
     * Constructor
     *
     * @pre none
     * @post Customer will be constructed, instance variables will be set
     */
    Customer(int id, string fname, string lname);

    /**
     * addTransaction
     *
     * @pre none
     * @post Transaction passed will be added to transaction history
     */
    bool addTransaction(Transaction &);

    /**
     * transactionHistory
     *
     * @pre none
     * @post Customer transaction history will be displayed to console
     */
    void transactionHistory() const;

    /**
     * getFirstName
     *
     * Returns customer first name
     */
    string getFirstName() const;

    /**
     * getLastName
     *
     * Returns customer last name
     */
    string getLastName() const;

    /**
     * getID
     *
     * Returns customer ID
     */
    int getID() const;

    /**
     * operator==
     *
     * @pre none customer is not null
     * @post returns true if customer name and id are the same, false otherwise
     */
    bool operator==(const Customer &) const;

private:
    vector<Transaction> transactions;
    int id;
    string fname;
    string lname;
};

#endif