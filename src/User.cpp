//
// Created by Rylan Cody on 11/11/24. file will contain all implementation for user class
//

#include "User.h"

//constructors
User::User() {
    this->username = "";
    this->password = "";
    this->name = "";
    this->email = "";
    this->borrowedBooks = std::vector<Book>();
    this->role = MEMBER;
}

User::User(string username, string password, string name, string email, vector<Book> borrowedBooks, Role role) {
    this->username = std::move(username);
    this->password = std::move(password);
    this->name = std::move(name);
    this->email = std::move(email);
    this->borrowedBooks = std::move(borrowedBooks);
    this->role = role;
}

User::User(User& copy) {
    this->username = copy.username;
    this->password = copy.password;
    this->name = copy.name;
    this->email = copy.email;
    this->borrowedBooks = copy.borrowedBooks;
    this->role = copy.role;
}

//destructor
User::~User() = default;

//accessors
string User::getUsername(void) const {
    return username;
}

string User::getPassword(void) const {
    return password;
}

string User::getName(void) const {
    return name;
}

string User::getEmail(void) const {
    return email;
}

vector<Book> User::getBooks(void) const {
    return borrowedBooks;
}

Role User::getRole() const {
    return role;
}

//mutators
void User::setUsername(string newUsername) {
    this->username = std::move(newUsername);
}

void User::setPassword(string newPassword) {
    this->password = std::move(newPassword);
}

void User::setName(string newName) {
    this->name = std::move(newName);
}

void User::setEmail(string newEmail) {
    this->email = std::move(newEmail);
}

void User::setBooks(vector<Book> newBooks) {
    this->borrowedBooks = std::move(newBooks);
}

void User::setRole(Role newRole) {
    this->role = newRole;
}

//others
std::istream& operator >> (istream& in, User& newUser) {
    string tempRole;
    cout << "Enter username: ";
    getline(in, newUser.username);

    cout << "Enter password: ";
    getline(in, newUser.password);

    cout << "Enter name: ";
    getline(in, newUser.name);

    cout << "Enter email: ";
    getline(in, newUser.email);

    cout << "Enter role: ";
    getline (in, tempRole);

    if (tempRole == "MEMBER") {
        newUser.role = MEMBER;
    }
    else if (tempRole == "LIBRARIAN") {
        newUser.role = LIBRARIAN;
    }
    else if (tempRole == "ADMIN") {
        newUser.role = ADMIN;
    }

    return in;
}


std::ostream& operator << (ostream& out, const User& user) {
    out << "Username: " << user.username << endl;
    out << "Password: " << user.password << endl;
    out << "Name: " << user.name << endl;
    out << "Email: " << user.email << endl;
    out << "Borrowed Books: ";
    if (user.borrowedBooks.empty()) {
        out << "None" << endl;
    }
    else {
        for (int i = 0; i < 5; i++) {
            out << user.borrowedBooks[i].getTitle() << "|";
        }
        out << endl;
    }

    out << "Role: ";
    switch(user.getRole())
    {
        case MEMBER:
            out << "MEMBER" << endl;
            break;
        case LIBRARIAN:
            out << "LIBRARIAN" << endl;
            break;
        case ADMIN:
            out << "ADMIN" << endl;
            break;
    }

    return out;
}

void User::borrowBook(Book& book) {
   if (book.getAvailability()) {
       book.checkOutBook(this);
       borrowedBooks.push_back(book);
   }
}

void User::returnBook(Book & book) {
    for (const auto& curBook : borrowedBooks) {
        if (book.getISBN() == curBook.getISBN()) {
            book.reShelfBook(this);
            borrowedBooks.erase(std::remove(borrowedBooks.begin(), borrowedBooks.end(), curBook), borrowedBooks.end());
            break;
        }
    }
}

