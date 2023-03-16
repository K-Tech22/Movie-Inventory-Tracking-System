#ifndef DRAMA_MOVIE_H
#define DRAMA_MOVIE_H
#include <iostream>
#include "movie.h"

using namespace std;

class DramaMovie : public Movie
{
public:
  /**
   * Constructor
   *
   * @pre none
   * @post Movie is constructed, no variables initialized
   */
  DramaMovie();

  /**
   * Constructor
   *
   * @pre none
   * @post Movie is constructed, variables are initialized
   */
  DramaMovie(int stock, string director, string title, int year);

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