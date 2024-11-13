//
// Created by Rylan Cody on 11/11/24. File contains class and prototype for user
//

#ifndef LIBRARYPROJECT_USER_H
#define LIBRARYPROJECT_USER_H

#include <vector>
#include "Book.h"
using namespace std;

class Book; //forward definition of Book class

//roles used to define what access each user is allowed to have
enum Role {
    MEMBER = 1, LIBRARIAN = 2, ADMIN = 3
};

class User {
public:
    //constructors
    User();
    User(string username, string password, string name, string email, vector<Book> borrowedBooks, Role role);
    User(User& copy);

    //destructors
    ~User();

    //accessors
    string getUsername(void) const;
    string getPassword(void) const;
    string getName(void) const;
    string getEmail(void) const;
    vector<Book> getBooks(void) const;
    Role getRole() const;

    //mutators
    void setUsername(string newUsername);
    void setPassword(string newPassword);
    void setName(string newName);
    void setEmail(string newEmail);
    void setBooks(vector<Book> newBooks);
    void setRole(Role newRole);

    //others
    friend std::istream& operator >> (istream& in, User& newUser);
    friend std::ostream& operator << (ostream& out, const User& user);

    void borrowBook(Book& book);
    void returnBook(Book& book);
private:
    string username; //Users username
    string password; //Users password
    string name; //users name
    string email; //users email
    vector<Book> borrowedBooks; //users books
    Role role; //users role in the system
};

#endif //LIBRARYPROJECT_USER_H
