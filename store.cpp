#include "store.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Store::Store()
{
    this->customerDatabase = HashTable<int, Customer *>();
    this->movieDatabase = HashTable<string, Movie *>();
}

void Store::buildCustomerDatabase(const string &filename)
{
    ifstream infile(filename);
    string text;
    while (infile.peek() != EOF)
    {
        getline(infile, text, ' ');
        int id = stoi(text);

        getline(infile, text, ' ');
        string firstName = text;

        getline(infile, text);
        string lastName = text;

        Customer *customer = new Customer(id, firstName, lastName);
        this->customerDatabase.insertItem(id, customer);

        // checking if the hashtable is being filled
        // cout << this->customerDatabase.find(id) << endl;
    }
}

void Store::buildMovieDatabase(const string &filename)
{
    ifstream infile(filename);
    string text;
    while (infile.peek() != EOF)
    {
        char type;
        int stock, month, year;
        string directorFName, directorLName, title, majorActorFName, majorActorLName, director, majorActor;

        getline(infile, text, ',');
        type = text.at(0);

        getline(infile, text, ',');
        stock = stoi(text);

        getline(infile, text, ' ');
        getline(infile, text, ' ');
        directorFName = text; //.substr(1, text.length());

        getline(infile, text, ',');
        directorLName = text; //.substr(1, text.length());

        director = directorFName + " " + directorLName;

        getline(infile, text, ',');
        title = text; //.substr(1, text.length());

        switch (type)
        {
        case 'C':
        {
            getline(infile, text, ' ');
            getline(infile, text, ' ');
            majorActorFName = text; //.substr(1, text.length());

            getline(infile, text, ' ');
            majorActorLName = text; //.substr(1, text.length());

            majorActor = majorActorFName + " " + majorActorLName;

            getline(infile, text, ' ');
            month = stoi(text);

            getline(infile, text);
            year = stoi(text);

            if (this->movieDatabase.find(title) == NULL)
            {
                ClassicMovie *movie = new ClassicMovie(stock, director, title, majorActor, month, year);
                this->movieDatabase.insertItem(title, movie);
            }
            else
            {
                ClassicMovie *movie = (ClassicMovie *)this->movieDatabase.find(title);
                movie->addMajorActor(majorActor, stock);
            }

            // checking if the hashtable is being filled
            this->movieDatabase.find(title)->display(0);
            cout << endl;
            break;
        }
        case 'F':
        {
            getline(infile, text);
            year = stoi(text);

            ComedyMovie *movie = new ComedyMovie(stock, director, title, year);

            if (this->movieDatabase.find(title) == NULL)
                this->movieDatabase.insertItem(title, movie);
            else
                this->movieDatabase.find(title)->incStockBy(stock);

            // checking if the hashtable is being filled
            this->movieDatabase.find(title)->display(0);
            cout << endl;
            break;
        }
        case 'D':
        {
            getline(infile, text);
            year = stoi(text);

            DramaMovie *movie = new DramaMovie(stock, director, title, year);

            if (this->movieDatabase.find(title) == NULL)
                this->movieDatabase.insertItem(title, movie);
            else
                this->movieDatabase.find(title)->incStockBy(stock);

            // checking if the hashtable is being filled
            this->movieDatabase.find(title)->display(0);
            cout << endl;
            break;
        }
        default:
            break;
        }
    }
}

void Store::processCommands(const string &filename)
{
    // ifstream infile(filename);
    fstream fileStream;
    fileStream.open(filename);
    while (fileStream.peek() != EOF)
    {
        char command;
        fileStream >> command;

        switch (command)
        {
        case 'I':
        {
            // TODO
            break;
        }
        case 'H':
        {
            int accountNumber;
            fileStream >> accountNumber;
            if (this->customerDatabase.find(accountNumber) != NULL)
                this->customerDatabase.find(accountNumber)->transactionHistory();
            else
            {
                cout << "ERROR: History Command Failed -- Customer " << accountNumber << " does not exist";
            }
            break;
        }
        case 'B':
        {
            int accountNumber;
            fileStream >> accountNumber;
            if (this->customerDatabase.find(accountNumber) == NULL)
            {
                cout << "ERROR: Borrow Transaction Failed -- Customer " << accountNumber << " does not exist";
                break;
            }

            char mediaType;
            fileStream >> mediaType;
            if (mediaType != 'D')
            {
                cout << "ERROR: " << mediaType << " Invalid Media Type. Try Again." << endl;
                break;
            }

            char genre;
            fileStream >> genre;

            switch (genre)
            {
            case 'F':
            {
                string title;
                getline(fileStream, title, ',');

                int year;
                fileStream >> year;
                break;
            }
            case 'D':
            {
                string director;
                getline(fileStream, director, ',');

                string title;
                getline(fileStream, title, ',');
                break;
            }
            case 'C':
            {
                int month;
                fileStream >> month;

                int year;
                fileStream >> year;

                string director;
                getline(fileStream, director);
                break;
            }
            default:
            {
                cout << "ERROR: " << genre << " Invalid Genre Type." << endl;
                break;
            }
            }

            break;
        }
        case 'R':
        {
            int accountNumber;
            fileStream >> accountNumber;

            if (this->customerDatabase.find(accountNumber) == NULL)
            {
                cout << "ERROR: Return Transaction Failed -- Customer " << accountNumber << " does not exist";
                break;
            }

            char mediaType;
            fileStream >> mediaType;

            if (mediaType != 'D')
            {
                cout << "ERROR: " << mediaType << " Invalid Media Type. Try Again." << endl;
                break;
            }

            char genre;
            fileStream >> genre;

            switch (genre)
            {
            case 'F':
            {
                string title;
                getline(fileStream, title, ',');

                int year;
                fileStream >> year;
                break;
            }
            case 'D':
            {
                string director;
                getline(fileStream, director, ',');

                string title;
                getline(fileStream, title, ',');
                break;
            }
            case 'C':
            {
                int month;
                fileStream >> month;

                int year;
                fileStream >> year;

                string director;
                getline(fileStream, director);
                break;
            }
            default:
            {
                cout << "ERROR: " << genre << " Invalid Genre Type." << endl;
                break;
            }
            }
            break;
        }
        default:
        {
            cout << "ERROR: " << command << " Invalid Transaction Type. Try Again." << endl;
        }
        }
    }
}