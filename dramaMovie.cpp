#include "dramaMovie.h"

using namespace std;

DramaMovie::DramaMovie()
{
}

DramaMovie::DramaMovie(int stock, string director, string title, int year)
{
}

void DramaMovie::display()
{
  cout << this->type;
  cout << "      ";
  cout << this->mediaType;

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

  cout << "   ";
  cout << this->year;
  numSpaces = 7 - to_string(this->stock).length();
  for (int i = 0; i < numSpaces; i++)
  {
    cout << " ";
  }
  cout << this->stock << endl
       << endl;
}
