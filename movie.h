#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>

using namespace std;

class Movie
{
public:
  Movie();
  Movie(char type, int stock, string director, string title, int year);

  virtual void display();

  void setStock(int);
  int getStock();

  char getType();

  void setTitle();
  string getTitle();

  void setYear();
  int getYear();

  string getDirectorFirstName();
  string getDirectorLastName();

  bool operator==(const Movie &) const;
  bool operator<=(const Movie &) const;
  bool operator>=(const Movie &) const;
  bool operator<(const Movie &) const;
  bool operator>(const Movie &) const;

protected:
  struct Director
  {
    string fname;
    string lname;
  };

  int stock;
  char type;
  string title;
  int year;
  Director director;
};

#endif