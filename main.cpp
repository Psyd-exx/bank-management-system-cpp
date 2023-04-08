#include <iostream>
#include "BankAccount.h"

using namespace std;

class Bank {

};

class Transaction {

};

int main()
{
    int userChoice {0};
    string username {""};
    string password {""};
    string name {""};
    float balance {0.00};
    BankAccount userAccount;

    cout << "Welcome to Sinan's Bank Management System\n"
            "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";

    while (userChoice != 3) {
        cout << "\n[1] CREATE AN ACCOUNT\n";
        cout << "[2] LOG INTO AN EXISTING ACCOUNT\n";
        cout << "[3] EXIT\n";
        cout << "\nPlease input here: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                cout << "PLEASE INPUT YOUR USERNAME HERE: ";
                cin >> username;
                cin.ignore();
                if (userAccount.checkAccountExists(username)) {
                    cout << "\nThis username already exists!\n"
                            "Please try again with a different username.\n";
                    break;
                }
                cout << "PLEASE INPUT YOUR PASSWORD HERE: ";
                cin >> password;
                cin.ignore();
                cout << "PLEASE INPUT YOUR NAME HERE: ";
                getline(cin, name);
                cout << "PLEASE INPUT THE INITIAL AMOUNT TO DEPOSIT HERE: ";
                cin >> balance;

                userAccount.createAccount(username, password, name, balance);

                cout << "\nAccount created successfully!\n";
                break;

            case 2:
                cout << "PLEASE INPUT YOUR USERNAME HERE: ";
                cin >> username;
                cout << "PLEASE INPUT YOUR PASSWORD HERE: ";
                cin >> password;
                if (!userAccount.logIn(username, password)) {
                    cout << "\nLog In Failed!\n";
                    break;
                }
                cout << "\nSuccessfully Logged In!\n";




                break;

            case 3:
                cout << "\nExiting Program";
                break;

            default:
                cout << "\nInvalid Command!";
                break;
        }
    }
    return 0;
}
