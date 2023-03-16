#include <iostream>
#include "customer.h"

using namespace std;

/**
 * operator<<
 *
 * @pre customer is not null
 * @post customer information will be outputted to the console
 */
ostream &operator<<(ostream &out, Customer customer)
{
    out << customer.getID() << " " << customer.getFirstName() << " " << customer.getLastName() << endl;
    return out;
}

/**
 * Constructor
 *
 * @pre none
 * @post Customer will be constructed, no instance variables will be set
 */
Customer::Customer()
{
    this->id = 0;
    this->fname = "";
    this->lname = "";
}

/**
 * Constructor
 *
 * @pre none
 * @post Customer will be constructed, instance variables will be set
 */
Customer::Customer(int id, string fname, string lname)
{
    this->id = id;
    this->fname = fname;
    this->lname = lname;
}

/**
 * addTransaction
 *
 * @pre none
 * @post Transaction passed will be added to transaction history
 */
bool Customer::addTransaction(Transaction &t)
{
    this->transactions.push_back(t);
    return true;
}

/**
 * transactionHistory
 *
 * @pre none
 * @post Customer transaction history will be displayed to console
 */
void Customer::transactionHistory() const
{
    for (int i = 0; i < this->transactions.size(); i++)
    {
        cout << transactions[this->transactions.size() - i - 1] << endl;
    }
    cout << endl;
}

/**
 * getFirstName
 *
 * Returns customer first name
 */
string Customer::getFirstName() const
{
    return this->fname;
}

/**
 * getLastName
 *
 * Returns customer last name
 */
string Customer::getLastName() const
{
    return this->lname;
}

/**
 * operator==
 *
 * @pre none customer is not null
 * @post returns true if customer name and id are the same, false otherwise
 */
bool Customer::operator==(const Customer &customer) const
{
    if (this->id == customer.id && this->fname == customer.fname && this->lname == customer.lname)
    {
        return true;
    }
    return false;
}

/**
 * getID
 *
 * Returns customer ID
 */
int Customer::getID() const
{
    return this->id;
}
