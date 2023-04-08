#include "BankAccount.h"
#include <iostream>
#include <fstream>

bool BankAccount ::checkAccountExists(std::string username)
{
    ifstream inFile("accounts.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            if (line.find(username) != string::npos) {
                return true;
            }
        }
        inFile.close();
    } else {
        cout << "File Not Found!\n";
    }
    return false;
}

void BankAccount ::createAccount(std::string username, std::string password, std::string name, float balance) {
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

bool BankAccount :: logIn(string username, string password) {
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