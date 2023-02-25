#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include "movie.h"

using namespace std;

class Transaction
{
    char mediaType;
    char transactionType;
    Movie mv;

public:
    void display();
};

#endif