#ifndef CLASSIC_MOVIE_H
#define CLASSIC_MOVIE_H
#include <iostream>
#include "movie.h"

using namespace std;

class ClassicMovie : public Movie
{
public:
    ClassicMovie();
    ClassicMovie(int stock, string director, string title, string actor, int month, int year);

    void display();
    string getMajorActor();

private:
    string majorActor;
    int month;
};

#endif