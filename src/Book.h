//
// Created by Rylan Cody on 11/11/24. File will contain the class and prototypes for Book class
//

#ifndef LIBRARYPROJECT_BOOK_H
#define LIBRARYPROJECT_BOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include "User.h"

using namespace std;


class Book {
public:
    //book constructors
    Book(void);
    Book(string title, string author, int ISBN, string genre, bool availability);
    Book(Book& copy);

    //book destructor
    ~Book();

    //accessors
    string getTitle(void);
    string getAuthor(void);
    int getISBN(void);
    string getGenre(void);
    bool getAvailability(void);
    //User* getBorrower(void);

    //mutators
    void setTitle(string newTitle);
    void setAuthor(string newAuthor);
    void setISBN(int newISBN);
    void setGenre(string newGenre);
    void setAvailability(bool newAvailability);
    //void setBorrower(User* newBorrower);

private:
    string title; //title of the book
    string author; //author of the book
    int ISBN; //ISBN of the book, used as key in AVL tree
    string genre; //genre of the book
    bool availability; //availability of the book, true if available, false otherwise
    //User* borrower; //pointer to the user that is currently borrowing book, null if not checked out (available)
};



#endif //LIBRARYPROJECT_BOOK_H
