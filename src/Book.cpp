//
// Created by Rylan Cody on 11/11/24. file contains implementation of book class
//

#include "Book.h"

#include <utility>

//constructors
Book::Book() {
    this->title = "";
    this->author = "";
    this->ISBN = -1; //-1 denotes that a book has not been fully instantiated here
    this->availability = true;
    //this->borrower = nullptr;
}

Book::Book(string title, string author, int ISBN, string genre, bool availability) {
    this->title = std::move(title);
    this-> author = std::move(author);
    this->ISBN = ISBN;
    this->genre = std::move(genre);
    this->availability = availability;
    //this->borrower = borrower;
}

Book::Book(Book& copy) {
    this->title = copy.title;
    this->author = copy.author;
    this->ISBN = copy.ISBN;
    this->genre = copy.genre;
    this->availability = copy.availability;
    //this->borrower = copy.borrower;
}

//destructor
Book::~Book() {
    /*string tempTitle = title;

    if (borrower != nullptr)
    {
        delete borrower;
    }

    cout << tempTitle << " deleted successfully" << endl;*/
}




