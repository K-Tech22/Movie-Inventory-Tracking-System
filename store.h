#ifndef STORE_H
#define STORE_H

#include <iostream>
#include "movie.h"
#include "comedyMovie.h"
#include "classicMovie.h"
#include "dramaMovie.h"
#include "customer.h"
#include "hashtable.cpp"

class Store
{
public:
    Store();

    void buildCustomerDatabase(const string &);

    void buildMovieDatabase(const string &);

    void processCommands(const string &);

private:
    HashTable<int, Customer *> customerDatabase;
    HashTable<string, Movie *> movieDatabase;
};

#endif