#include <iostream>
using namespace std;

class BankAccount {
public:
    float balance {0.00};
    string name {};
    string username {};
    string password {};

    bool checkAccountExists(string username);

    void createAccount(string username, string password, string name, float balance);

    bool logIn(string username, string password);

    void addFunds(float depositedMoney);

    void withdrawFunds(float withdrawnMoney);

    void transferMoney(string userToTransferTo, float moneyToTransfer);

    void changeName(string newName);

};