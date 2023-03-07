#pragma once
#include "movie.h"

using namespace std;

Movie::Movie(char type, int stock, string director, string title, int year)
{
    this->type = type;
    this->stock = stock;
    this->director = director;
    this->title = title;
    this->year = year;
}

// Movie::Movie()
// {
// }

// Movie::Movie(char type, int stock, string directorFirstName, string directorLastName, string title, int year)
// {
//     this->type = type;
//     this->stock = stock;
//     this->director.fname = directorFirstName;
//     this->director.lname = directorLastName;
//     this->title = title;
//     this->year = year;
// }

// // void Movie::display()
// // {
// // }

// void Movie::setStock(int stock)
// {
//     this->stock = stock;
// }

// int Movie::getStock()
// {
//     return this->stock;
// }

// char Movie::getType()
// {
//     return this->type;
// }

// void Movie::setTitle(string title)
// {
//     this->title = title;
// }

// string Movie::getTitle()
// {
//     return this->title;
// }

// void Movie::setYear(int year)
// {
// }

// int Movie::getYear()
// {
// }

// string Movie::getDirectorFirstName()
// {
// }

// string Movie::getDirectorLastName()
// {
// }

// bool Movie::operator==(const Movie &movie) const
// {
// }

// bool Movie::operator<=(const Movie &movie) const
// {
// }

// bool Movie::operator>=(const Movie &movie) const
// {
// }

// bool Movie::operator<(const Movie &movie) const
// {
// }

// bool Movie::operator>(const Movie &movie) const
// {
// }