#include <string>
using namespace std;

class Account {
private:
    const string accountNumber;
    double balance;

public:
    Account(const string& accountNumber, double balance)
        : accountNumber(accountNumber), balance(balance) {}

    // Getters
    string getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
    

    // Withdraws specified amount from the balance
    void debit(double amount) {
        balance -= amount;
    }

    // Adds the specified amount to balance
    void credit(double amount) {
        balance += amount;
    }
};
