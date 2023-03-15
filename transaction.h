#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include "movie.h"
#include "customer.h"

using namespace std;

class Transaction
{
    friend ostream &operator<<(ostream &, const Transaction &);

public:
    Transaction();
    Transaction(char mediaType, char transactionType, Movie mv, Customer account);

    void display() const;

    char getMediaType() const;
    void setMediaType(char mType);

    char getTransactionType() const;
    void setTransactionType(char tType);

    Movie getMovie() const;
    void setMovie(Movie mv);

private:
    char mediaType;
    char transactionType;
    Movie mv;
    bool isError;
    int errorCode;
    Customer account;
};

#endif