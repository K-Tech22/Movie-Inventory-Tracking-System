#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>

using namespace std;

class Movie
{
public:
  Movie();
  Movie(char type, int stock, string director, string title, int year, char mediaType);
  virtual void display(int spaces) const;
  bool borrow(int num);

  void setStock(int);
  int getStock() const;
  void incStockBy(int);

  char getType() const;

  void setTitle(string title);
  string getTitle() const;

  void setYear(int year);
  int getYear() const;

  string getDirectorName() const;

  bool operator==(const Movie &) const;
  bool operator<=(const Movie &) const;
  bool operator>=(const Movie &) const;
  bool operator<(const Movie &) const;
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

  // string director;
};

// class Movie
// {
// public:
//   Movie();
//   Movie(char type, int stock, string directorFirstName, string getDirectorLastName, string title, int year);

//   virtual void display();

//   void setStock(int);
//   int getStock();

//   char getType();

//   void setTitle(string title);
//   string getTitle();

//   void setYear(int year);
//   int getYear();

//   string getDirectorFirstName();
//   string getDirectorLastName();

//   bool operator==(const Movie &) const;
//   bool operator<=(const Movie &) const;
//   bool operator>=(const Movie &) const;
//   bool operator<(const Movie &) const;
//   bool operator>(const Movie &) const;

// protected:
//   struct Director
//   {
//     string fname;
//     string lname;
//   };

//   int stock;
//   char type;
//   string title;
//   int year;
//   Director director;
// };

#endif