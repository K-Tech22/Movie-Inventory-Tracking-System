#ifndef CLASSIC_MOVIE_H
#define CLASSIC_MOVIE_H
#include <iostream>
#include "movie.h"

using namespace std;

class ClassicMovie : public Movie
{
public:
    ClassicMovie(const string &majorActor, int month, char type, int stock,
                 const string &director, const string &title, int year);

    // void display();
    // string getMajorActor();

private:
    string majorActor;
    int month;
};

#endif