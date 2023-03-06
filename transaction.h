#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include "movie.h"
#include "customer.h"

using namespace std;

class Transaction
{
public:
    Transaction();
    Transaction(char mediaType, char transactionType, Movie mv, bool isError, int errorCode, Customer account);

    void display();

    char getMediaType();
    void setMediaType(char mType);

    char getTransactionType();
    void setTransactionType(char tType);

    Movie getMovie();
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