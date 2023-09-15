# Movie-Inventory-Tracking-System

This program will have 6 classes that will be used to automate and issue commands for a movie rental store inventory tracking system. The classes include: Transaction, Customer, Movie, ComedyMovie, DramaMovie, ClassicMovie, and Store.

The customer class will contain data about the customer and a list of their previous transactions.

The Movie class will contain data about a movie, and ClassicMovie will extend from the Movie class.

The store class will contain two hashmaps. One will hold Customer objects, and one will hold Movie objects.

With these classes implemented, the user will be able to input a file to the store object which builds the customer base. This file will include the customer ID, first name, and last name.

The user will also input a file to the store object which builds the movie database. This file will include information about the movie including Genre, stock, name of director, title, and year released. For classic movies, the major actor and release month will also be included.

After the customer and movie files are processed, the user can input a file containing commands they would like to issue.

These commands are:

 - Borrow (denoted as ‘B’): (stock – 1) for each item borrowed
 - Return (denoted as ‘R’): (stock + 1) for each item returned
 - Inventory (denoted as ‘I’): outputs the inventory of all the items in the store
 - History (denoted as ‘H’): outputs all the transactions of a customer

## Description of main:

In the main function, a Store object will be created. Once created, methods from Store can be called to input the data about the customers, the movies, and the commands. The store class will issue the commands while reading the commands file.

## Class Diagram

<img width="1086" alt="Design" src="https://github.com/K-Tech22/Movie-Inventory-Tracking-System/assets/125720478/1984346d-b4e5-4f45-b639-734393932e69">
