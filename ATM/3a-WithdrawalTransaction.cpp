#include "2-Account.cpp"
#include "3-Transaction.cpp"
#include <string>
using namespace std;

class WithdrawalTransaction : public Transaction {
public:
    WithdrawalTransaction(const string& transactionId, Account& account, double amount)
        : Transaction(transactionId, account, amount) {}

    // Executes the withdrawal transaction by debiting the account
    void execute() override {
        account.debit(amount);
    }
};
