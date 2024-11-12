#include <iostream>
#include "Book.h"
#include "User.h"
using namespace std;

int main(void)
{
    Book myBook;

    cin >> myBook;

    User myUser;

    cin >> myUser;

    myUser.borrowBook(myBook);

    cout << myBook;

    cout << myUser;

    return 0;
}