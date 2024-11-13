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

class User; //forward definition of user

class Book {
public:
    //book constructors
    Book(void);
    Book(string title, string author, long ISBN, string genre, bool availability, User* borrower);
    Book(const Book& copy);

//book destructor
    ~Book();

    //accessors
    string getTitle() const;
    string getAuthor(void) const;
    long getISBN(void) const;
    string getGenre(void) const ;
    bool getAvailability(void) const;
    User* getBorrower(void);

    //mutators
    void setTitle(string newTitle);
    void setAuthor(string newAuthor);
    void setISBN(long newISBN);
    void setGenre(string newGenre);
    void setAvailability(bool newAvailability);
    void setBorrower(User* newBorrower);

    //others
    friend std::istream& operator >>(istream& in, Book*& newBook);
    friend std::ostream& operator <<(ostream& out, const Book& book);
    bool operator ==(const Book& other) {
        return this->ISBN == other.ISBN;
    }

    void checkOutBook(User* borrower);
    void reShelfBook(User* borrower);

private:
    string title; //title of the book
    string author; //author of the book
    long ISBN; //ISBN of the book, used as key in AVL tree
    string genre; //genre of the book
    bool availability; //availability of the book, true if available, false otherwise
    User* borrower; //pointer to the user that is currently borrowing book, null if not checked out (available)
};

#endif //LIBRARYPROJECT_BOOK_H
