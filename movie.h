#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>

using namespace std;

class Movie
{
    struct Director
    {
        string fname;
        string lname;
    };

    int stock;
    char type;
    string title;
    int year;

public:
    virtual void display();
};

#endif