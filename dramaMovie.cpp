#include "dramaMovie.h"

using namespace std;

/**
 * Constructor
 *
 * @pre none
 * @post Movie is constructed, no variables initialized
 */
DramaMovie::DramaMovie()
{
}

/**
 * Constructor
 *
 * @pre none
 * @post Movie is constructed, variables are initialized
 */
DramaMovie::DramaMovie(int stock, string director, string title, int year)
{
  this->type = 'D';
  this->mediaType = 'D';
  this->stock = stock;
  this->director = director;
  this->title = title;
  this->year = year;
}

/**
 * display
 *
 * @pre none
 * @post Contents of movie will be displayed to console, with 'spaces' number of spaces in front
 */
void DramaMovie::display(int spaces) const
{
  for (int i = 0; i < spaces; i++)
  {
    cout << " ";
  }
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
