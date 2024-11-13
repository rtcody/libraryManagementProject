#include <iostream>
#include "Book.h"
#include "User.h"
#include "AVLTree.hpp"
using namespace std;

int main(void)
{
    Book myBook("The Shining", "Stephen King", 1234567890, "Horror", true, nullptr);
    User myUser;
    cout << myBook;

    cin >> myUser;


    auto* myNode = new AVLNode<Book>(myBook);

    auto* myTree = new AVLTree<Book>(myNode);

    myUser.borrowBook(myTree->getRoot()->getData());

    cout << myTree->getRoot()->getData();

    myUser.returnBook(myTree->getRoot()->getData());

    cout << myTree->getRoot()->getData();

    return 0;
}