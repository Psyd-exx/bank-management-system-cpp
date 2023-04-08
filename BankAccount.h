#include <iostream>
using namespace std;

class BankAccount {
public:
    bool checkAccountExists(string username);

    void createAccount(string username, string password, string name, float balance);

    bool logIn(string username, string password);

private:
    string username {};
    string password {};
    string name {};
    float balance {0.00};
};