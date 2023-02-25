#ifndef STORE_H
#define STORE_H

#include <iostream>
#include "movie.h"
#include "customer.h"
#include "hashtable.cpp"

class Store
{
public:
    Store();

    void buildCustomerDatabase(ifstream &);

    void buildMovieDatabase(ifstream &);

    void processCommands(ifstream &);

private:
    HashTable<int, Customer> customerDatabase;
    HashTable<string, Movie> movieDatabase;
};

#endif