#include "classicMovie.h"

using namespace std;

ClassicMovie::ClassicMovie()
{
}

ClassicMovie::ClassicMovie(int stock, string director, string title, string majorActor, int month, int year)
{
  this->type = 'C';
  this->mediaType = 'D';
  this->director = director;
  this->title = title;
  MajorActor actor;
  actor.name = majorActor;
  actor.stock = stock;
  this->majorActors.push_back(actor);
  this->month = month;
  this->year = year;
  this->stock = stock;
}

void ClassicMovie::display(int spaces) const
{
  for (int i = 0; i < spaces; i++)
  {
    cout << " ";
  }
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
    int numSpaces = 84 + spaces - (this->majorActors.at(i).name.length() + 15 + to_string(this->majorActors.at(i).stock).length());
    for (int j = 0; j < numSpaces; j++)
    {
      cout << " ";
    }
    this->displayMajorActor(this->majorActors.at(i));
  }
  cout << endl;
}

void ClassicMovie::displayMajorActor(MajorActor actor) const
{
  cout << actor.name
       << " ------------- " << actor.stock << endl;
}

void ClassicMovie::addMajorActor(string actorName, int stock)
{
  bool contains = false;
  for (int i = 0; i < this->majorActors.size(); i++)
  {
    if (this->majorActors.at(i).name == actorName)
    {
      this->majorActors.at(i).stock += stock;
      this->stock += stock;
      contains = true;
      break;
    }
  }
  if (!contains)
  {
    MajorActor actor;
    actor.name = actorName;
    actor.stock = stock;
    this->majorActors.push_back(actor);
    this->stock += stock;
  }
}

bool ClassicMovie::removeStock(string actorName, int stock)
{
  for (int i = 0; i < this->majorActors.size(); i++)
  {
    if (this->majorActors.at(i).name == actorName)
    {
      if (this->majorActors.at(i).stock - stock >= 0)
      {
        this->majorActors.at(i).stock -= stock;
        this->stock -= stock;
        return true;
      }
      else
      {
        return false;
      }
    }
  }
  return false;
}
