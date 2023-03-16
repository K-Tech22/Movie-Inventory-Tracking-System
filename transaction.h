#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include "movie.h"

using namespace std;

class Transaction
{
    /**
     * operator<<
     *
     * @pre none
     * @post outputs transaction to console
     */
    friend ostream &operator<<(ostream &, const Transaction &);

public:
    /**
     * Constructor
     *
     * @pre none
     * @post Transaction object made
     */
    Transaction();

    /**
     * Constructor
     *
     * @pre none
     * @post instance variables will be set
     */
    Transaction(char mediaType, char transactionType, Movie mv);

    /**
     * display
     *
     * @pre none
     * @post Details of transaction will be displayed to console
     */
    void display() const;

    /**
     * getMediaType
     *
     * mediaType getter (char)
     */
    char getMediaType() const;

    /**
     * setMediaType
     *
     * mediaType setter
     */
    void setMediaType(char mType);

    /**
     * getTransactionType
     *
     * transactionType getter (char)
     */
    char getTransactionType() const;

    /**
     * setTransactionType
     *
     * transactionType setter
     */
    void setTransactionType(char tType);

    /**
     * getMovie
     *
     * Returns movie tied to transaction
     */
    Movie getMovie() const;

    /**
     * setMovie
     *
     * Sets movie tied to transaction
     */
    void setMovie(Movie mv);

private:
    char mediaType;
    char transactionType;
    Movie mv;
};

#endif