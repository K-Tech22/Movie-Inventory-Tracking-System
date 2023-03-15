#include <iostream>
#include "transaction.h"

Transaction::Transaction()
{
  // instance variables not set
}

Transaction::Transaction(char mediaType, char transactionType, Movie mv)
{
  this->mediaType = mediaType;
  this->transactionType = transactionType;
  this->mv = mv;
}

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

char Transaction::getMediaType() const
{
  return this->mediaType;
}

void Transaction::setMediaType(char mType)
{
  this->mediaType = mType;
}

char Transaction::getTransactionType() const
{
  return this->transactionType;
}

void Transaction::setTransactionType(char tType)
{
  this->transactionType = tType;
}

Movie Transaction::getMovie() const
{
  return this->mv;
}

void Transaction::setMovie(Movie mv)
{
  this->mv = mv;
}

ostream &operator<<(ostream &out, const Transaction &t)
{
  t.display();
  return out;
}
