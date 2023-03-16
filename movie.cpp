#include "movie.h"

using namespace std;

/**
 * Constructor
 *
 * @pre none
 * @post Movie is constructed, no variables set
 */
Movie::Movie()
{
}

/**
 * Constructor
 *
 * @pre none
 * @post sets/initializes movie instance variables
 */
Movie::Movie(char type, int stock, string director, string title, int year, char mediaType)
{
    this->type = type;
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->year = year;
    this->mediaType = mediaType;
}

/**
 * display (virtual)
 *
 * @pre none
 * @post Determined by child class implementation
 */
void Movie::display(int spaces) const
{
}

/**
 * setStock
 *
 * setter method for stock
 */
void Movie::setStock(int stock)
{
    this->stock = stock;
}

/**
 * getStock
 *
 * getter method for stock (int)
 */
int Movie::getStock() const
{
    return this->stock;
}

/**
 * incStockBy
 *
 * @pre none
 * @post increases the stock by int passed
 */
void Movie::incStockBy(int s)
{
    this->stock += s;
}

/**
 * getType
 *
 * getter for movie type (char)
 */
char Movie::getType() const
{
    return this->type;
}

/**
 * setTitle
 *
 * Setter for movie title
 */
void Movie::setTitle(string title)
{
    this->title = title;
}

/**
 * getTitle
 *
 * getter for movie title (string)
 */
string Movie::getTitle() const
{
    return this->title;
}

/**
 * setYear
 *
 * setter for movie year
 */
void Movie::setYear(int year)
{
    this->year = year;
}

/**
 * getYear
 *
 * getter for movie year
 */
int Movie::getYear() const
{
    return this->year;
}

/**
 * getDirectorName
 *
 * getter for director name (string)
 */
string Movie::getDirectorName() const
{
    return this->director;
}

/**
 * operator==
 *
 * @pre movie is not null
 * @post returns true if contents of this are same as movie passed, false otherwise
 */
bool Movie::operator==(const Movie &movie) const
{
    return (this->title == movie.title &&
            this->director == movie.director &&
            this->mediaType == movie.mediaType &&
            this->year == movie.year);
}

/**
 * operator<=
 *
 * @pre movie is not null
 * @post Returns true if this title < movie title, or if both movies are equal
 */
bool Movie::operator<=(const Movie &movie) const
{
    return (this->title < movie.title || (this->operator==(movie)));
}

/**
 * operator<=
 *
 * @pre movie is not null
 * @post Returns true if this title > movie title, or if both movies are equal
 */
bool Movie::operator>=(const Movie &movie) const
{
    return (this->title > movie.title || (this->operator==(movie)));
}

/**
 * operator<
 *
 * @pre movie is not null
 * @post Returns true if this title < movie title
 */
bool Movie::operator<(const Movie &movie) const
{
    return this->title < movie.title;
}

/**
 * operator>
 *
 * @pre movie is not null
 * @post Returns true if this title > movie title
 */
bool Movie::operator>(const Movie &movie) const
{
    return this->title > movie.title;
}

/**
 * borrow
 *
 * @pre none
 * @post Returns true if stock - num is >= 0. Stock is subtracted by num if true
 */
bool Movie::borrow(int num)
{
    if (this->stock - num < 0)
    {
        return false;
    }
    this->stock -= num;
    return true;
}