#include "classicMovie.h"

using namespace std;

ClassicMovie::ClassicMovie(const string &majorActor, int month, char type, int stock,
                           const string &director, const string &title, int year)
{
}

void ClassicMovie::display()
{
  cout << this->type << "      " << this->mediaType;

  int numSpaces = 35 - this->title.length();
  for (int i = 0; i < numSpaces; i++)
  {
    cout << " ";
  }
  cout << this->title;

  numSpaces = 20 - this->director.length();
  for (int i = 0; i < numSpaces; i++)
  {
    cout << " ";
  }
  cout << this->director;

  numSpaces = 7 - to_string(this->month).length();
  for (int i = 0; i < numSpaces; i++)
  {
    cout << " ";
  }
  cout << this->month;

  cout << "   " << this->year;

  numSpaces = 7 - to_string(this->stock).length();
  for (int i = 0; i < numSpaces; i++)
  {
    cout << " ";
  }
  cout << this->stock << endl;

  for (int i = 0; i < this->majorActors.size(); i++)
  {
    int numSpaces = 90 - (this->majorActors.at(i).name.length() + 15 + to_string(this->majorActors.at(i).stock).length());
    this->displayMajorActor(this->majorActors.at(i));
  }
  cout << endl;
}

void ClassicMovie::displayMajorActor(MajorActor actor)
{
  cout << actor.name
       << " ------------- ";

  int numSpaces = 2 - to_string(actor.stock).length();
  for (int i = 0; i < numSpaces; i++)
  {
    cout << " ";
  }
  cout << actor.stock << endl;
}