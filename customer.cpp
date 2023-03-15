#include <iostream>
#include "customer.h"

using namespace std;

ostream &operator<<(ostream &out, Customer customer)
{
    out << customer.getID() << " " << customer.getFirstName() << " " << customer.getLastName() << endl;
    return out;
}

Customer::Customer()
{
    this->id = 0;
    this->fname = "";
    this->lname = "";
}

Customer::Customer(int id, string fname, string lname)
{
    this->id = id;
    this->fname = fname;
    this->lname = lname;
}

bool Customer::addTransaction(Transaction &t)
{
    this->transactions.push_back(t);
    return true;
}

bool Customer::setCustomerId(Customer c, int id)
{
    // if (c == true)
    // {
    //     c.id = id;
    //     return true;
    // }
    return false;
}

void Customer::transactionHistory() const
{
    for (int i = 0; i < this->transactions.size(); i++)
    {
        cout << transactions[this->transactions.size() - i - 1] << endl;
    }
    cout << endl;
}

string Customer::getFirstName() const
{
    return this->fname;
}

void Customer::setFirstName(string fname)
{
    this->fname = fname;
}

string Customer::getLastName() const
{
    return this->lname;
}

void Customer::setLastName(string lname)
{
    this->lname = lname;
}

bool Customer::operator==(const Customer &customer) const
{
    if (this->id == customer.id && this->fname == customer.fname && this->lname == customer.lname)
    {
        return true;
    }
    return false;
}

int Customer::getID() const
{
    return this->id;
}

ostream &operator<<(ostream &out, const Customer &customer)
{
    out << customer.getID() << " " << customer.getFirstName() << " " << customer.getLastName();
    return out;
}