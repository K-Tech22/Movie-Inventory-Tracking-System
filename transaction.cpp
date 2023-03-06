#include <iostream>
#include "transaction.h"
#include "customer.h"

Transaction::Transaction()
{
  // instance variables not set
}

Transaction::Transaction(char mediaType, char transactionType, Movie mv, bool isError, int errorCode, Customer account)
{
  this->mediaType = mediaType;
  this->transactionType = transactionType;
  this->mv = mv;
  this->isError = isError;
  this->errorCode = errorCode;
  this->account = account;
}

void Transaction::display()
{
  if (this->isError)
  {
    cout << "ERROR: "; // initial error message

    switch (this->errorCode)
    {
    case 100: // invalid transaction type
      cout << this->transactionType << " Invalid Transaction Type. Try Again.";
      break;
    case 200: // invalid media type
      cout << this->mediaType << " Invalid Media Type. Try Again.";
      break;
    case 300: // borrow transaction failed: Customer does not exist
      cout << "Borrow Transaction Failed -- Customer " << this->account.getID() << " does not exist";
      break;
    case 301: // borrow transaction failed: Movie does not exist in inventory
      cout << "Borrow Transaction Failed -- Movie does not Exist in the Inventory";
      break;
    case 302: // borrow transaction failed: Not enough in stock
      cout << "Borrow Transaction Failed -- Not enough in the Stock";
      break;
    case 400: // return transaction failed: Customer does not exist
      cout << "Return Transaction Failed -- Customer " << this->account.getID() << " does not exist";
      break;
    default:
      break;
    }
    cout << endl;
    return;
  }

  switch (this->transactionType)
  {
  case 'B':
    cout << "Borrowed " << this->mv.getTitle() << " by " << this->mv.getDirectorFirstName() << " " << this->mv.getDirectorLastName();
    break;
  case 'R':
    cout << "Returned " << this->mv.getTitle() << " by " << this->mv.getDirectorFirstName() << " " << this->mv.getDirectorLastName();
    break;
  default:
    break;
  }
}

char Transaction::getMediaType()
{
  return this->mediaType;
}

void Transaction::setMediaType(char mType)
{
  this->mediaType = mType;
}

char Transaction::getTransactionType()
{
  return this->transactionType;
}

void Transaction::setTransactionType(char tType)
{
  this->transactionType = tType;
}

Movie Transaction::getMovie()
{
  return this->mv;
}

void Transaction::setMovie(Movie mv)
{
  this->mv = mv;
}
