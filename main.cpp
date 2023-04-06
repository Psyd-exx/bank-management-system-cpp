#include <iostream>
#include <fstream>

using namespace std;

class BankAccount {
public:
    bool checkAccountExists(string username) {
        ifstream inFile("accounts.txt");
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                if (line.contains(username)) {
                    return true;
                }
            }
            inFile.close();
        } else {
            cout << "File Not Found!\n";
        }
        return false;
    }

    void createAccount(string username, string name, float balance) {
        this->username = username;
        this->name = name;
        this->balance = balance;

        ofstream outFile("accounts.txt");
        if (outFile.is_open()) {
            outFile << username << ":" << name << ":" << balance << std::endl;
            outFile.close();
        } else {
            cout << "File Not Found!\n";
        }
    }

    void setUsername(string username) {
        this->username = username;
    }

    void setName(string name) {
        this->name = name;
    }

    void setBalance(float balance) {
        this->balance = balance;
    }

private:
    string username {};
    string name {};
    float balance {0.00};
};

class Bank {

};

class Transaction {

};

int main()
{
    int userChoice {0};
    string username {""};
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
                cout << "PLEASE INPUT YOUR NAME HERE: ";
                getline(cin, name);
                cout << "PLEASE INPUT THE INITIAL AMOUNT TO DEPOSIT HERE: ";
                cin >> balance;

                userAccount.createAccount(username, name, balance);

                cout << "\nAccount created successfully!\n";
                break;

            case 2:
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
