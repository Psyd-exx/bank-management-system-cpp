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

    void createAccount(string username, string password, string name, float balance) {
        this->username = username;
        this->password = password;
        this->name = name;
        this->balance = balance;

        ofstream outFile("accounts.txt", ios::app);
        if (outFile.is_open()) {
            outFile << username << ":" << password << ":" << balance << ":" << name << std::endl;
            outFile.close();
        } else {
            cout << "File Not Found!\n";
        }
    }

    bool logIn(string username, string password) {
        ifstream inFile("accounts.txt");
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                size_t firstColonPos = line.find(":");
                size_t secondColonPos = line.find(":", firstColonPos + 1);
                string fileUsername = line.substr(0, firstColonPos);
                string filePassword = line.substr(firstColonPos + 1, secondColonPos - firstColonPos - 1);

                if (fileUsername == username && filePassword == password) {
                    return true;
                }
            }
            inFile.close();
        }
        return false;
    }

private:
    string username {};
    string password {};
    string name {};
    float balance {0.00};
    // bool loggedIn {false};
};

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
