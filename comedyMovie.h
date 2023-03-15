#ifndef COMEDY_MOVIE_H
#define COMEDY_MOVIE_H
#include <iostream>
#include "movie.h"

using namespace std;

class ComedyMovie : public Movie
{
public:
  ComedyMovie();
  ComedyMovie(int stock, string director, string title, int year);

  void display(int spaces) const;

private:
};

#endif