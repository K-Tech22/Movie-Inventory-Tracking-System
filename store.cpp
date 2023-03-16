#include "store.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/**
 * Constructor
 *
 * @pre none
 * @post Customer and Movie hashmaps will be initialized
 */
Store::Store()
{
    this->customerDatabase = new HashTable<Customer *>();
    this->movieDatabase = new HashTable<Movie *>();
}

/**
 * buildCustomerDatabase
 *
 * @pre Customer data in file passed is formatted properly
 * @post Customer data is stored in store customer hashmap
 */
void Store::buildCustomerDatabase(const string &filename)
{
    ifstream infile(filename);
    string text;
    while (infile.peek() != EOF)
    {
        getline(infile, text, ' ');
        string id = text;

        getline(infile, text, ' ');
        string lastName = text;

        getline(infile, text);
        string firstName = text;

        Customer *customer = new Customer(stoi(id), firstName, lastName);
        this->customerDatabase->insert(id, customer);

        // checking if the hashtable is being filled
        // cout << this->customerDatabase.find(id) << endl;
    }
}

/**
 * buildMovieDatabase
 *
 * @pre Movie data in file passed is formatted properly
 * @post Movie data will be stored in store movie hashmap
 */
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
        title = text.substr(1, text.length());

        switch (type)
        {
        case 'C': // BUILDING CLASSIC MOVIE
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
            string key = to_string(month) + to_string(year);
            if (this->movieDatabase->get(key) == NULL)
            {
                ClassicMovie *movie = new ClassicMovie(stock, director, title, majorActor, month, year);

                this->movieDatabase->insert(key, movie);
            }
            else
            {
                ClassicMovie *movie = (ClassicMovie *)this->movieDatabase->get(key);
                movie->addMajorActor(majorActor, stock);
            }

            // checking if the hashtable is being filled
            // this->movieDatabase->get(key)->display(0);
            // cout << endl;
            break;
        }
        case 'F': // BUILDING COMEDY MOVIE
        {
            getline(infile, text);
            year = stoi(text);

            string key = title + to_string(year);

            ComedyMovie *movie = new ComedyMovie(stock, director, title, year);

            if (this->movieDatabase->get(key) == NULL)
                this->movieDatabase->insert(key, movie);
            else
                this->movieDatabase->get(key)->incStockBy(stock);

            // checking if the hashtable is being filled
            // this->movieDatabase->get(key)->display(0);
            // cout << endl;
            break;
        }
        case 'D': // BUILDING DRAMA MOVIE
        {
            getline(infile, text);
            year = stoi(text);

            string key = director + title;

            DramaMovie *movie = new DramaMovie(stock, director, title, year);

            if (this->movieDatabase->get(key) == NULL)
                this->movieDatabase->insert(key, movie);
            else
                this->movieDatabase->get(key)->incStockBy(stock);

            // checking if the hashtable is being filled
            // this->movieDatabase->get(key)->display(0);
            // cout << endl;
            break;
        }
        default:
        {
            string restOfLine;
            getline(infile, restOfLine);
            break;
        }
        }
    }
}

/**
 * processCommands
 *
 * @pre Commands in file passed are formatted properly
 * @post Commands will be issued and store data will be updated accordingly
 */
void Store::processCommands(const string &filename)
{
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
            this->displayInventoryHelper();
            break;
        }
        case 'H':
        {
            this->displayHistoryHelper(fileStream);
            break;
        }
        case 'B':
        {
            this->processBorrowHelper(fileStream);
            break;
        }
        case 'R':
        {
            this->processReturnHelper(fileStream);
            break;
        }
        default:
        {
            string restOfLine;
            getline(fileStream, restOfLine);
            cout << "ERROR: " << command << " Invalid Transaction Type. Try Again." << endl;
        }
        }
    }
}

/**
 * displayInventoryHelper
 *
 * @pre none
 * @post Inventory of store will be displayed to console
 */
void Store::displayInventoryHelper()
{
    vector<Movie *> movies = this->movieDatabase->getAll();

    cout << "---------------------------" << endl;
    cout << "Comedies:" << endl
         << endl;
    cout << "  Genre  Media                              Title            Director   Year  Stock" << endl;
    for (int i = 0; i < movies.size(); i++)
    {
        if (movies.at(i)->getType() == 'F')
        {
            movies.at(i)->display(6);
        }
    }
    cout << endl;

    cout << "---------------------------" << endl;
    cout << "Classics:" << endl
         << endl;
    cout << "  Genre  Media                              Title            Director   Year  Stock" << endl;
    for (int i = 0; i < movies.size(); i++)
    {
        if (movies.at(i)->getType() == 'C')
        {
            movies.at(i)->display(6);
        }
    }
    cout << endl;

    cout << "---------------------------" << endl;
    cout << "Dramas:" << endl
         << endl;
    cout << "  Genre  Media                              Title            Director   Year  Stock" << endl;
    for (int i = 0; i < movies.size(); i++)
    {
        if (movies.at(i)->getType() == 'D')
        {
            movies.at(i)->display(6);
        }
    }
    cout << endl;
}

/**
 * displayHistoryHelper
 *
 * @pre fileStream must be at a point to receive data for processing a history command
 * @post History command will be issued and displayed to console
 */
void Store::displayHistoryHelper(fstream &fileStream)
{
    int accountNumber;
    if (fileStream.eof())
        return;
    fileStream >> accountNumber;
    if (this->customerDatabase->get(to_string(accountNumber)) != NULL)
    {
        cout << endl
             << "History for " << this->customerDatabase->get(to_string(accountNumber))->getFirstName();
        cout << " " << this->customerDatabase->get(to_string(accountNumber))->getLastName() << ":" << endl;
        this->customerDatabase->get(to_string(accountNumber))->transactionHistory();
    }
    else
    {
        string restOfLine;
        getline(fileStream, restOfLine);
        cout << "ERROR: History Command Failed -- Customer " << accountNumber << " does not exist" << endl;
    }
}

/**
 * processBorrowHelper
 *
 * @pre fileStream must be at a point to receive data for a borrow command
 * @post Borrow command will be issued and update store inventory
 */
void Store::processBorrowHelper(fstream &fileStream)
{
    int accountNumber;
    fileStream >> accountNumber;

    if (this->customerDatabase->get(to_string(accountNumber)) == NULL)
    {
        string restOfLine;
        getline(fileStream, restOfLine);
        cout << "ERROR: Borrow Transaction Failed -- Customer " << accountNumber << " does not exist" << endl;
        return;
    }

    char mediaType;
    fileStream >> mediaType;
    if (mediaType != 'D')
    {
        string restOfLine;
        getline(fileStream, restOfLine);
        cout << "ERROR: " << mediaType << " Invalid Media Type. Try Again." << endl;
        return;
    }

    char genre;
    fileStream >> genre;

    switch (genre)
    {
    case 'F':
    {
        string title;
        getline(fileStream, title, ' ');
        getline(fileStream, title, ',');

        int year;
        fileStream >> year;

        string key = title + to_string(year);
        if (this->movieDatabase->get(key) == NULL)
        {
            cout << "ERROR: Borrow Transaction Failed -- Movie does not Exist in the Inventory" << endl;
            break;
        }

        if (!this->movieDatabase->get(key)->borrow(1))
        {
            cout << "ERROR: Borrow Transaction Failed -- Not enough in the Stock" << endl;
        }
        else
        {
            Transaction newTransaction(mediaType, 'B', *this->movieDatabase->get(key));
            this->customerDatabase->get(to_string(accountNumber))->addTransaction(newTransaction);
        }
        break;
    }
    case 'D':
    {
        string director;
        getline(fileStream, director, ' ');
        getline(fileStream, director, ',');

        string title;
        getline(fileStream, title, ' ');
        getline(fileStream, title, ',');

        string key = director + title;
        if (this->movieDatabase->get(key) == NULL)
        {
            cout << "ERROR: Borrow Transaction Failed -- Movie does not Exist in the Inventory" << endl;
            break;
        }

        if (!this->movieDatabase->get(key)->borrow(1))
        {
            cout << "ERROR: Borrow Transaction Failed -- Not enough in the Stock" << endl;
        }
        else
        {
            Transaction newTransaction(mediaType, 'B', *this->movieDatabase->get(key));
            this->customerDatabase->get(to_string(accountNumber))->addTransaction(newTransaction);
        }
        break;
    }
    case 'C':
    {
        int month;
        fileStream >> month;

        int year;
        fileStream >> year;

        string actor;
        getline(fileStream, actor, ' ');
        getline(fileStream, actor, '\r');

        string key = to_string(month) + to_string(year);
        if (this->movieDatabase->get(key) == NULL)
        {
            cout << "ERROR: Borrow Transaction Failed -- Movie does not Exist in the Inventory" << endl;
            break;
        }
        ClassicMovie *movie = (ClassicMovie *)this->movieDatabase->get(key);
        if (!(movie->removeStock(actor, 1)))
        {
            cout << "ERROR: Borrow Transaction Failed -- Not enough in the Stock" << endl;
        }
        else
        {
            Transaction newTransaction(mediaType, 'B', *this->movieDatabase->get(key));
            this->customerDatabase->get(to_string(accountNumber))->addTransaction(newTransaction);
        }

        break;
    }
    default:
    {
        string restOfLine;
        getline(fileStream, restOfLine);
        // cout << "ERROR: " << genre << " Invalid Genre Type." << endl;
        break;
    }
    }
}

/**
 * processReturnHelper
 *
 * @pre fileStream must be at a point to receive data for a return command
 * @post Return command will be issued and update store inventory
 */
void Store::processReturnHelper(fstream &fileStream)
{
    int accountNumber;
    fileStream >> accountNumber;

    if (this->customerDatabase->get(to_string(accountNumber)) == NULL)
    {
        string restOfLine;
        getline(fileStream, restOfLine);
        cout << "ERROR: Return Transaction Failed -- Customer " << accountNumber << " does not exist" << endl;
        return;
    }

    char mediaType;
    fileStream >> mediaType;

    if (mediaType != 'D')
    {
        string restOfLine;
        getline(fileStream, restOfLine);
        cout << "ERROR: " << mediaType << " Invalid Media Type. Try Again." << endl;
        return;
    }

    char genre;
    fileStream >> genre;

    switch (genre)
    {
    case 'F':
    {
        string title;
        getline(fileStream, title, ' ');
        getline(fileStream, title, ',');

        int year;
        fileStream >> year;

        string key = title + to_string(year);
        if (this->movieDatabase->get(key) == NULL)
        {
            cout << "ERROR: Return Transaction Failed -- Movie does not Exist in the Inventory" << endl;
            break;
        }

        this->movieDatabase->get(key)->incStockBy(1);
        Transaction newTransaction(mediaType, 'R', *this->movieDatabase->get(key));
        this->customerDatabase->get(to_string(accountNumber))->addTransaction(newTransaction);
        break;
    }
    case 'D':
    {
        string director;
        getline(fileStream, director, ' ');
        getline(fileStream, director, ',');

        string title;
        getline(fileStream, title, ' ');
        getline(fileStream, title, ',');

        string key = director + title;
        if (this->movieDatabase->get(key) == NULL)
        {
            cout << "ERROR: Return Transaction Failed -- Movie does not Exist in the Inventory" << endl;
            break;
        }

        this->movieDatabase->get(key)->incStockBy(1);
        Transaction newTransaction(mediaType, 'R', *this->movieDatabase->get(key));
        this->customerDatabase->get(to_string(accountNumber))->addTransaction(newTransaction);
    }
    case 'C':
    {
        int month;
        fileStream >> month;

        int year;
        fileStream >> year;

        string actor;
        getline(fileStream, actor, ' ');
        getline(fileStream, actor, '\r');

        string key = to_string(month) + to_string(year);
        if (this->movieDatabase->get(key) == NULL)
        {
            cout << "ERROR: Return Transaction Failed -- Movie does not Exist in the Inventory" << endl;
            break;
        }
        ClassicMovie *movie = (ClassicMovie *)this->movieDatabase->get(key);
        movie->addMajorActor(actor, 1);
        Transaction newTransaction(mediaType, 'R', *this->movieDatabase->get(key));
        this->customerDatabase->get(to_string(accountNumber))->addTransaction(newTransaction);
        break;
    }
    default:
    {
        string restOfLine;
        getline(fileStream, restOfLine);
        cout
            << "ERROR: " << genre << " Invalid Genre Type." << endl;
        break;
    }
    }
}