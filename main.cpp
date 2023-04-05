#include <iostream>

using namespace std;

class BankAccount {

};

class Bank {

};

class Transaction {

};

int main()
{
    int userChoice {0};

    cout << "Welcome to Sinan's Bank Management System\n"
            "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";

    while (userChoice != 3) {
        cout << "\n[1] CREATE AN ACCOUNT\n";
        cout << "[2] LOG INTO AN EXISTING ACCOUNT\n";
        cout << "[3] EXIT\n";
        cout << "\nPlease input here: ";
        cin >> userChoice;

//        switch (userChoice){
//            case 1:
//
//            case 2:
//
//            default:
//
//        }
    }
    return 0;
}
