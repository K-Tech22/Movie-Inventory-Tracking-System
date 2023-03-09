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
}