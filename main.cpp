#include <iostream>
#include "BankAccount.h"

using namespace std;

class Transaction
{
public:
    string user;
    string description;
    long amount;
    Transaction* next;

    Transaction(string user, string description, long amount)
    {
        this->user = user;
        this->description = description;
        this->amount = amount;
        next = NULL;
    }
};

class TransactionList
{
private:
    Transaction* head;
public:
    TransactionList()
    {
        head = NULL;
    }

    void addTransaction(string user, string desc, long amt)
    {
        Transaction* newTransaction = new Transaction(user, desc, amt);
        if (head == NULL) {
            head = newTransaction;
        } else {
            Transaction* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newTransaction;
        }
    }

    void displayTransactions()
    {
        Transaction* current = head;
        while (current != NULL) {
            cout << "\n================================\n";
            cout << "Sent to: " << current->user << endl;
            cout << "Description: " << current->description << endl;
            cout << "Amount: " << current->amount << endl;
            cout << "================================\n";
            current = current->next;
        }
    }
};

int main()
{
    int userChoice {0};
    int loggedInUserChoice {0};
    string username {""};
    string password {""};
    string name {""};
    long balance {0};
    BankAccount userAccount;
    TransactionList transactionList;

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

            cout << "\n>> WELCOME " << userAccount.username << "!\n";
            while (loggedInUserChoice != 6) {
                cout << "\n####### LOGGED IN AS: " << userAccount.username << " #######\n";
                cout << "ACCOUNT NAME: " << userAccount.name << "\n";
                cout << "ACCOUNT BALANCE: " << userAccount.balance << "\n";
                cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "[1] ADD FUNDS\n";
                cout << "[2] TRANSFER MONEY\n";
                cout << "[3] VIEW VOLATILE TRANSACTIONS\n";
                cout << "[4] CHANGE NAME\n";
                cout << "[5] WITHDRAW MONEY\n";
                cout << "[6] LOG OUT\n";
                cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
                cout << "Please input here: ";

                cin >> loggedInUserChoice;
                string userToTransfer;
                string description;
                string newName;

                switch (loggedInUserChoice) {
                case 1:
                    long moneyToDeposit;
                    cout << "HOW MUCH WOULD YOU LIKE TO DEPOSIT?: ";
                    cin >> moneyToDeposit;
                    userAccount.addFunds(moneyToDeposit);
                    moneyToDeposit = 0;
                    break;

                case 2:
                    long moneyToTransfer;
                    cout << "INPUT THEIR USERNAME: ";
                    cin >> userToTransfer;
                    cout << "HOW MUCH WOULD YOU LIKE TO TRANSFER?: ";
                    cin >> moneyToTransfer;
                    cout << "REASON FOR TRANSFER: ";
                    cin >> description;

                    transactionList.addTransaction(userToTransfer, description, moneyToTransfer);
                    userAccount.transferMoney(userToTransfer, moneyToTransfer);
                    break;

                case 3:
                    transactionList.displayTransactions();
                    break;

                case 4:
                    cin.ignore();
                    cout << "INPUT NAME HERE: ";
                    getline(cin, name);
                    userAccount.changeName(name);
                    break;

                case 5:
                    long moneyToWithdraw;
                    cout << "HOW MUCH WOULD YOU LIKE TO WITHDRAW?: ";
                    cin >> moneyToWithdraw;
                    userAccount.withdrawFunds(moneyToWithdraw);
                    moneyToWithdraw = 0;
                    break;

                case 6:
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