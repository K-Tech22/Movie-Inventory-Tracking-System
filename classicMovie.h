#ifndef CLASSIC_MOVIE_H
#define CLASSIC_MOVIE_H
#include <iostream>
#include "movie.h"
#include <vector>

using namespace std;

class ClassicMovie : public Movie
{
    friend ostream &operator<<(ostream &, const ClassicMovie &);

public:
    /**
     * Constructor
     *
     * @pre none
     * @post ComedyMovie will be constructed, variables will be set
     */
    ClassicMovie();

    /**
     * Constructor
     *
     * @pre none
     * @post ComedyMovie will be constructed, variables will be set
     */
    ClassicMovie(int stock, string director, string title, string majorActor, int month, int year);

    /**
     * display
     *
     * @pre none
     * @post Contents of movie will be displayed to console, with 'spaces' number of spaces in front
     */
    void display(int spaces) const;

    /**
     * addMajorActor
     *
     * @pre none
     * @post Adds stock to major actor of movie. If there is no major actor, a new major actor will be added to movie
     */
    void addMajorActor(string actor, int stock);

    /**
     * removeStock
     *
     * @pre none
     * @post If actorName is major actor for movie, then 'stock' amount stock will be removed only if stock will be >= 0
     */
    bool removeStock(string actor, int stock);

private:
    struct MajorActor
    {
        string name;
        int stock;
    };
    int month;
    vector<MajorActor> majorActors;

    /**
     * displayMajorActor
     *
     * @pre none
     * @post displays the actor and the stock to the console
     */
    void displayMajorActor(MajorActor actor) const;
};

#endif