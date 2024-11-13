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
    this->genre = "";
    this->availability = true;
    this->borrower = nullptr;
}

Book::Book(string title, string author, long ISBN, string genre, bool availability, User* borrower) {
    this->title = std::move(title);
    this->author = std::move(author);
    this->ISBN = ISBN;
    this->genre = std::move(genre);
    this->availability = availability;
    this->borrower = borrower;
}

Book::Book(const Book& copy) {
    this->title = copy.title;
    this->author = copy.author;
    this->ISBN = copy.ISBN;
    this->genre = copy.genre;
    this->availability = copy.availability;
    this->borrower = copy.borrower;
}

//destructor
Book::~Book() = default;

//accessors
string Book::getTitle(void) const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

long Book::getISBN() const {
    return ISBN;
}

string Book::getGenre() const {
    return genre;
}

bool Book::getAvailability() const {
    return availability;
}

User* Book::getBorrower() {
    return borrower;
}

//mutators
void Book::setTitle(string newTitle) {
    this->title = std::move(newTitle);
}

void Book::setAuthor(string newAuthor) {
    this->author = std::move(newAuthor);
}

void Book::setISBN(long newISBN) {
    this->ISBN = newISBN;
}

void Book::setGenre(string newGenre) {
    this->genre = std::move(newGenre);
}

void Book::setAvailability(bool newAvailability) {
    this->availability = newAvailability;
}

void Book::setBorrower(User* newBorrower) {
    this->borrower = newBorrower;
}

istream & operator >>(istream& in, Book*& newBook) {
    cout << "Enter book title: ";
    getline(in, newBook->title);

    cout << "Enter authors name: ";
    getline(in, newBook->author);

    cout << "Enter ISBN number: ";
    in >> newBook->ISBN;
    in.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter books genre: ";
    getline(in, newBook->genre);

    newBook->availability = true;

    return in;
}

ostream& operator <<(ostream& out, const Book& book) {
    out << "Title: " << book.title << endl;
    out << "Author: " << book.author << endl;
    out << "ISBN: " << book.ISBN << endl;
    out << "Genre: " << book.genre << endl;
    out << "Available? ";

    if (book.availability == 0 )
    {
        out << "False, ";
        out << "Borrower: " << book.borrower->getName() << endl;
    }
    else
    {
        out << "True, ";
    }


    return out;
}

void Book::checkOutBook(User* borrower) {
    if (this->availability) {
        this->availability = false;
        this->borrower = borrower;
    }
}

void Book::reShelfBook(User* borrower) {
    if (this->borrower = borrower) {
        this->availability = true;
        this->borrower = nullptr;
    }
}

