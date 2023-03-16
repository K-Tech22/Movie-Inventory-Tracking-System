#ifndef COMEDY_MOVIE_H
#define COMEDY_MOVIE_H
#include <iostream>
#include "movie.h"

using namespace std;

class ComedyMovie : public Movie
{
public:
  /**
   * Constructor
   *
   * @pre none
   * @post ComedyMovie will be constructed, no variables will be set
   */
  ComedyMovie();

  /**
   * Constructor
   *
   * @pre none
   * @post ComedyMovie will be constructed, variables will be set
   */
  ComedyMovie(int stock, string director, string title, int year);

  /**
   * display
   *
   * @pre none
   * @post Contents of movie will be displayed to console, with 'spaces' number of spaces in front
   */
  void display(int spaces) const;

private:
};

#endif