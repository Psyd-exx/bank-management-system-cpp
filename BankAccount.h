#include <iostream>
using namespace std;

class BankAccount
{
public:
    long balance {0};
    string name {};
    string username {};
    string password {};

    bool checkAccountExists(string username);

    void createAccount(string username, string password, string name, long balance);

    bool logIn(string username, string password);

    void addFunds(long depositedMoney);

    void withdrawFunds(long withdrawnMoney);

    void transferMoney(string userToTransferTo, long moneyToTransfer);

    void changeName(string newName);

};