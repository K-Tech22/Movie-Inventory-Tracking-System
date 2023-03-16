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
    /**
     * Constructor
     *
     * @pre none
     * @post Customer and Movie hashmaps will be initialized
     */
    Store();

    /**
     * Deconstructor
     *
     * @pre none
     * @post all memory allocated by store will be cleared
     */
    ~Store();

    /**
     * buildCustomerDatabase
     *
     * @pre Customer data in file passed is formatted properly
     * @post Customer data is stored in store customer hashmap
     */
    void buildCustomerDatabase(const string &);

    /**
     * buildMovieDatabase
     *
     * @pre Movie data in file passed is formatted properly
     * @post Movie data will be stored in store movie hashmap
     */
    void buildMovieDatabase(const string &);

    /**
     * processCommands
     *
     * @pre Commands in file passed are formatted properly
     * @post Commands will be issued and store data will be updated accordingly
     */
    void processCommands(const string &);

private:
    HashTable<Customer *> *customerDatabase;
    HashTable<Movie *> *movieDatabase;

    /**
     * displayInventoryHelper
     *
     * @pre none
     * @post Inventory of store will be displayed to console
     */
    void displayInventoryHelper();

    /**
     * displayHistoryHelper
     *
     * @pre fileStream must be at a point to receive data for processing a history command
     * @post History command will be issued and displayed to console
     */
    void displayHistoryHelper(fstream &);

    /**
     * processBorrowHelper
     *
     * @pre fileStream must be at a point to receive data for a borrow command
     * @post Borrow command will be issued and update store inventory
     */
    void processBorrowHelper(fstream &);

    /**
     * processReturnHelper
     *
     * @pre fileStream must be at a point to receive data for a return command
     * @post Return command will be issued and update store inventory
     */
    void processReturnHelper(fstream &);
};
#endif