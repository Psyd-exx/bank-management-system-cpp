#include <iostream>
#include "BankAccount.h"

using namespace std;

class Transaction {
};

int main()
{
    int userChoice {0};
    int loggedInUserChoice {0};
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

                while (loggedInUserChoice != 4) {
                    cout << "\n##### WELCOME " << userAccount.username << "! #####\n";
                    cout << "ACCOUNT NAME: " << userAccount.name << "\n";
                    cout << "ACCOUNT BALANCE: " << userAccount.balance << "\n";
                    cout << "=-=-=-=-=-=-=-=-=-=-=-=\n";
                    cout << "[1] ADD FUNDS\n";
                    cout << "[2] TRANSFER MONEY\n";
                    cout << "[3] WITHDRAW MONEY\n";
                    cout << "[4] LOG OUT\n";
                    cout << "\nPlease input here: ";
                    cin >> loggedInUserChoice;
                    string userToTransfer;

                    switch (loggedInUserChoice) {
                        case 1:
                            float moneyToDeposit;
                            cout << "HOW MUCH WOULD YOU LIKE TO DEPOSIT?: \n";
                            cin >> moneyToDeposit;
                            userAccount.addFunds(moneyToDeposit);
                            moneyToDeposit = 0;
                            break;

                        case 2:
                            float moneyToTransfer;
                            cout << "INPUT THEIR USERNAME: ";
                            cin >> userToTransfer;
                            cout << "HOW MUCH WOULD YOU LIKE TO TRANSFER?: ";
                            cin >> moneyToTransfer;
                            userAccount.transferMoney(userToTransfer, moneyToTransfer);
                            break;

                        case 3:
                            float moneyToWithdraw;
                            cout << "HOW MUCH WOULD YOU LIKE TO WITHDRAW?: \n";
                            cin >> moneyToWithdraw;
                            userAccount.withdrawFunds(moneyToWithdraw);
                            moneyToWithdraw = 0;
                            break;

                        case 4:
                            break;
                    }
                }
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
