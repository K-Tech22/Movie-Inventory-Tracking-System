#ifndef CLASSIC_MOVIE_H
#define CLASSIC_MOVIE_H
#include <iostream>
#include "movie.h"
#include <vector>

using namespace std;

class ClassicMovie : public Movie
{
public:
    ClassicMovie();
    ClassicMovie(int stock, string director, string title, string majorActor, int month, int year);

    void display(int spaces);
    void addMajorActor(string actor, int stock);

private:
    struct MajorActor
    {
        string name;
        int stock;
    };
    int month;
    vector<MajorActor> majorActors;
    void displayMajorActor(MajorActor actor);
};

#endif