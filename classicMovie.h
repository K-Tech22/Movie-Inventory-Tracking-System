#ifndef CLASSIC_MOVIE_H
#define CLASSIC_MOVIE_H
#include <iostream>
#include "movie.h"
#include <vector>

using namespace std;

class ClassicMovie : public Movie
{
public:
    ClassicMovie(const string &majorActor, int month, char type, int stock,
                 const string &director, const string &title, int year);

    void display();

private:
    struct MajorActor
    {
        string name;
        int stock;
    };
    string majorActor;
    int month;
    vector<MajorActor> majorActors;
    void displayMajorActor(MajorActor actor);
};

#endif