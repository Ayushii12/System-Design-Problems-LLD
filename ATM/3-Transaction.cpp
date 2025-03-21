#include <string>
#include "2-Account.cpp"
using namespace std;

class Transaction {
protected:
    const string transactionId;
    Account& account;
    const double amount;

public:
    Transaction(const string& transactionId, Account& account, double amount)
        : transactionId(transactionId), account(account), amount(amount) {}

    // Pure virtual function to execute the transaction
    virtual void execute() = 0;
};
