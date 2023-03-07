#include "classicMovie.h"

using namespace std;

ClassicMovie::ClassicMovie(const string &majorActor, int month, char type, int stock,
                           const string &director, const string &title, int year)
    : Movie(type, stock, director, title, year),
      majorActor(majorActor),
      month(month)
{
}