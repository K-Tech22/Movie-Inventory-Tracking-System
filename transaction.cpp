#include <iostream>
#include "transaction.h"

/**
 * Constructor
 *
 * @pre none
 * @post Transaction object made
 */
Transaction::Transaction()
{
}

/**
 * Constructor
 *
 * @pre none
 * @post instance variables will be set
 */
Transaction::Transaction(char mediaType, char transactionType, Movie mv)
{
  this->mediaType = mediaType;
  this->transactionType = transactionType;
  this->mv = mv;
}

/**
 * display
 *
 * @pre none
 * @post Details of transaction will be displayed to console
 */
void Transaction::display() const
{

  switch (this->transactionType)
  {
  case 'B':
    cout << "Borrowed " << this->mv.getTitle() << " by " << this->mv.getDirectorName();
    break;
  case 'R':
    cout << "Returned " << this->mv.getTitle() << " by " << this->mv.getDirectorName();
    break;
  default:
    break;
  }
}

/**
 * getMediaType
 *
 * mediaType getter (char)
 */
char Transaction::getMediaType() const
{
  return this->mediaType;
}

/**
 * setMediaType
 *
 * mediaType setter
 */
void Transaction::setMediaType(char mType)
{
  this->mediaType = mType;
}

/**
 * getTransactionType
 *
 * transactionType getter (char)
 */
char Transaction::getTransactionType() const
{
  return this->transactionType;
}

/**
 * setTransactionType
 *
 * transactionType setter
 */
void Transaction::setTransactionType(char tType)
{
  this->transactionType = tType;
}

/**
 * getMovie
 *
 * Returns movie tied to transaction
 */
Movie Transaction::getMovie() const
{
  return this->mv;
}

/**
 * setMovie
 *
 * Sets movie tied to transaction
 */
void Transaction::setMovie(Movie mv)
{
  this->mv = mv;
}

/**
 * operator<<
 *
 * @pre none
 * @post outputs transaction to console
 */
ostream &operator<<(ostream &out, const Transaction &t)
{
  t.display();
  return out;
}
