#pragma once
#include "movie.h";

using namespace std;

Movie::Movie()
{
}

Movie::Movie(char type, int stock, string director, string title, int year)
{
}

void Movie::display()
{
}

void Movie::setStock(int stock)
{
}

int Movie::getStock()
{
}

char Movie::getType()
{
}

void Movie::setTitle(string title)
{
}

string Movie::getTitle()
{
}

void Movie::setYear(int year)
{
}

int Movie::getYear()
{
}

string Movie::getDirectorFirstName()
{
}

string Movie::getDirectorLastName()
{
}

bool Movie::operator==(const Movie &movie) const
{
}

bool Movie::operator<=(const Movie &movie) const
{
}

bool Movie::operator>=(const Movie &movie) const
{
}

bool Movie::operator<(const Movie &movie) const
{
}

bool Movie::operator>(const Movie &movie) const
{
}
