#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>

using namespace std;

class Movie
{
public:
  /**
   * Constructor
   *
   * @pre none
   * @post Movie is constructed, no variables set
   */
  Movie();

  /**
   * Constructor
   *
   * @pre none
   * @post sets/initializes movie instance variables
   */
  Movie(char type, int stock, string director, string title, int year, char mediaType);

  /**
   * display (virtual)
   *
   * @pre none
   * @post Determined by child class implementation
   */
  virtual void display(int spaces) const;
  bool borrow(int num);

  /**
   * setStock
   *
   * setter method for stock
   */
  void setStock(int);

  /**
   * getStock
   *
   * getter method for stock (int)
   */
  int getStock() const;

  /**
   * incStockBy
   *
   * @pre none
   * @post increases the stock by int passed
   */
  void incStockBy(int);

  /**
   * getType
   *
   * getter for movie type (char)
   */
  char getType() const;

  /**
   * setTitle
   *
   * Setter for movie title
   */
  void setTitle(string title);

  /**
   * getTitle
   *
   * getter for movie title (string)
   */
  string getTitle() const;

  /**
   * setYear
   *
   * setter for movie year
   */
  void setYear(int year);

  /**
   * getYear
   *
   * getter for movie year
   */
  int getYear() const;

  /**
   * getDirectorName
   *
   * getter for director name (string)
   */
  string getDirectorName() const;

  /**
   * operator==
   *
   * @pre movie is not null
   * @post returns true if contents of this are same as movie passed, false otherwise
   */
  bool operator==(const Movie &) const;

  /**
   * operator<=
   *
   * @pre movie is not null
   * @post Returns true if this title < movie title, or if both movies are equal
   */
  bool operator<=(const Movie &) const;

  /**
   * operator<=
   *
   * @pre movie is not null
   * @post Returns true if this title > movie title, or if both movies are equal
   */
  bool operator>=(const Movie &) const;

  /**
   * operator<
   *
   * @pre movie is not null
   * @post Returns true if this title < movie title
   */
  bool operator<(const Movie &) const;

  /**
   * operator>
   *
   * @pre movie is not null
   * @post Returns true if this title > movie title
   */
  bool operator>(const Movie &) const;

protected:
  char type;
  int stock;
  struct Director
  {
    string fname;
    string lname;
  };
  string director;
  string title;
  int year;
  char mediaType;
};

#endif