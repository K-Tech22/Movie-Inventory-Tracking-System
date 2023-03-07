#include "store.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Store::Store()
{
}

// void Store::buildCustomerDatabase(const string &filename)
// {
//     ifstream infile(filename);
//     string line;
//     while (getline(infile, line))
//     {
//         int id;
//         string firstname;
//         string lastname;
//         stringstream ss(line);
//         ss >> id >> firstname >> lastname;
//         Customer customer(id, firstname, lastname);
//         customerDatabase.insertItem(customer.getID(), customer);
//         // Just to check if its inserting & reading the data properly
//         if (customer == customerDatabase.find(customer.getID()))
//         {
//             // cout << "Yes" << endl;
//         }
//         else
//         {
//             // cout << "No" << endl;
//         }
//     }
// }

void Store::buildMovieDatabase(const string &filename)
{
    ifstream infile(filename);
    string line;
    while (getline(infile, line))
    {
        char type, comma;
        int stock, year, releaseMonth;
        string stockStr, releaseMonthStr, director, title, majorActor, majorActorFname, majorActorLname;
        stringstream ss(line);
        ss >> type;
        if (type == 'D')
        {
            ss >> comma;
            getline(ss, stockStr, ',');
            stock = stoi(stockStr);
            getline(ss, director, ',');
            getline(ss, title, ',');
            ss >> year;

            // cout << "Type: " << type << endl;
            // cout << "stock: " << stock << endl;
            // cout << "director: " << director << endl;
            // cout << "title: " << title << endl;
            // cout << "year: " << year << endl;
            // cout << "\n\n";
        }
        if (type == 'C')
        {
            // cout << line << endl;
            ss >> comma;
            getline(ss, stockStr, ',');
            stock = stoi(stockStr);
            getline(ss, director, ',');
            getline(ss, title, ',');
            // getline(ss, majorActorFname);
            ss >> majorActorFname;
            ss >> majorActorLname;
            ss >> releaseMonthStr;
            releaseMonth = stoi(releaseMonthStr);
            ss >> year;
            // cout << "Type: " << type << endl;
            // cout << "stock: " << stock << endl;
            // cout << "director: " << director << endl;
            // cout << "title: " << title << endl;
            // cout << "majorActorFname: " << majorActorFname << endl;
            // cout << "majorActorLname: " << majorActorLname << endl;
            // cout << "releaseMonth: " << releaseMonthStr << endl;
            // cout << "year: " << year << endl;
            // cout << "\n\n";
        }
        if (type == 'F')
        {
        }
    }
}

void Store::processCommands(const string &filename)
{
}