#include "2-Account.cpp"
#include "3-Transaction.cpp"
#include <string>
using namespace std;

class DepositTransaction : public Transaction {
public:
    DepositTransaction(const string& transactionId, Account& account, double amount)
        : Transaction(transactionId, account, amount) {}

    // Executes the deposit transaction by crediting the account
    void execute() override {
        account.credit(amount);
    }
};
