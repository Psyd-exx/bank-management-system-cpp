#include "BankAccount.h"
#include <iostream>
#include <fstream>
#include <sstream>

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

void BankAccount ::createAccount(string username, string password, string name, float balance) {
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
            stringstream ss(line);
            string fileUsername, filePassword, balanceStr, fileName;

            getline(ss, fileUsername, ':');
            getline(ss, filePassword, ':');
            getline(ss, balanceStr, ':');
            getline(ss, fileName, ':');

            if (fileUsername == username && filePassword == password) {
                this->username = fileUsername;
                this->password = filePassword;
                this->name = fileName;
                this->balance = stod(balanceStr);
                return true;
            }
        }
        inFile.close();
    }
    return false;
}

void BankAccount :: addFunds(float depositedMoney) {
    fstream file("accounts.txt");
    ofstream tempFile("temp.txt");

    string fileUsername, filePassword, fileName, line;
    double fileBalance, amount;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, fileUsername, ':');
        getline(ss, filePassword, ':');
        ss >> fileBalance;
        getline(ss, fileName);
        fileName = fileName.substr(1);

        if (fileUsername == username) {
            this->balance += depositedMoney;
            tempFile << username << ":" << password << ":" << balance << ":" << name << endl;
        } else {
            tempFile << fileUsername << ":" << filePassword << ":" << fileBalance << ":" << fileName << "\n";
        }
    }
    file.close();
    tempFile.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
}

void BankAccount :: withdrawFunds(float withdrawnMoney) {
    fstream file("accounts.txt");
    ofstream tempFile("temp.txt");

    string fileUsername, filePassword, fileName, line;
    double fileBalance, amount;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, fileUsername, ':');
        getline(ss, filePassword, ':');
        ss >> fileBalance;
        getline(ss, fileName);
        fileName = fileName.substr(1);

        if (fileUsername == username) {
            this->balance -= withdrawnMoney;
            tempFile << username << ":" << password << ":" << balance << ":" << name << endl;
        } else {
            tempFile << fileUsername << ":" << filePassword << ":" << fileBalance << ":" << fileName << "\n";
        }
    }
    file.close();
    tempFile.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
}

void BankAccount :: transferMoney(string userToTransferTo, float moneyToTransfer) {
    fstream file("accounts.txt");
    ofstream tempFile("temp.txt");

    if (this->balance <= moneyToTransfer) {
        cout << "NOT ENOUGH MONEY TO TRANSFER\n";
        return;
    }

    this->balance -= moneyToTransfer;

    string fileUsername, filePassword, fileName, line;
    double fileBalance, amount;
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, fileUsername, ':');
        getline(ss, filePassword, ':');
        ss >> fileBalance;
        getline(ss, fileName);
        fileName = fileName.substr(1);

        if (fileUsername == userToTransferTo) {
            fileBalance += moneyToTransfer;
            tempFile << fileUsername << ":" << filePassword << ":" << fileBalance << ":" << fileName << "\n";
        } else if (fileUsername == this->username) {
            tempFile << username << ":" << password << ":" << balance << ":" << name << endl;
        } else {
            tempFile << fileUsername << ":" << filePassword << ":" << fileBalance << ":" << fileName << "\n";
        }
    }
    file.close();
    tempFile.close();

    remove("accounts.txt");
    rename("temp.txt", "accounts.txt");
}