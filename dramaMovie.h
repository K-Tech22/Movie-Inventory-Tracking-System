#ifndef DRAMA_MOVIE_H
#define DRAMA_MOVIE_H
#include <iostream>
#include "movie.h"

using namespace std;

class DramaMovie : public Movie
{
public:
  DramaMovie();
  DramaMovie(int stock, string director, string title, int year);

  void display(int spaces);

private:
};

#endif