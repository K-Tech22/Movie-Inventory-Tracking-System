#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>

using namespace std;

class Movie
{
public:
  Movie();
  Movie(char type, int stock, string name, int year);

  virtual void display();

  void setStock(int);
  int getStock();

  char getType();

  void setTitle();
  string getTitle();

  void setYear();
  int getYear();

private:
  struct Director
  {
    string fname;
    string lname;
  };

  int stock;
  char type;
  string title;
  int year;
};

#endif