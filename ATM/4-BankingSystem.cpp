#include <unordered_map>
#include <string>
#include "2-Account.cpp"
#include "3-Transaction.cpp"
using namespace std;

class BankingSystem {
private:
    unordered_map<string, Account*> accounts;
public:
    // Destructor to clean up dynamically allocated Account objects
    ~BankingSystem() {
        for (auto& pair : accounts) {
            delete pair.second;
        }
    }

    void createAccount(const string& accountNumber, double initialBalance) {
        accounts[accountNumber] = new Account(accountNumber, initialBalance);
    }

    // Returns a pointer to the Account corresponding to the given account number
    Account* getAccount(const string& accountNumber) {
        auto it = accounts.find(accountNumber);
        return (it != accounts.end()) ? it->second : nullptr;
    }

    // Processes a transaction by executing it
    void processTransaction(Transaction& transaction) {
        transaction.execute();
    }    
};
