#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <atomic>
#include <time.h>
#include "1-Card.cpp"
#include "2-Account.cpp"
#include "3-Transaction.cpp"
#include "3a-WithdrawalTransaction.cpp"
#include "3b-DepositTransaction.cpp"
#include "4-BankingSystem.cpp"
#include "5-CashDispenser.cpp"
using namespace std;

class ATM {
private:
    BankingSystem& bankingSystem;
    CashDispenser& cashDispenser;
    static atomic<long> transactionCounter;

public:
    ATM(BankingSystem& bankingSystem, CashDispenser& cashDispenser)
        : bankingSystem(bankingSystem), cashDispenser(cashDispenser) {}

    void authenticateUser(const Card& card) {
        cout << "Please enter PIN for card " << card.getCardNumber() << ": ";
        string inputPin;
        cin >> inputPin;
        if (inputPin == card.getPin()) cout << "Authentication successful." << endl;
        else cout << "Authentication failed." << endl;
    }

    // Returns the account balance for the provided account number
    double checkBalance(const string& accountNumber) {
        Account* account = bankingSystem.getAccount(accountNumber);
        return account ? account->getBalance() : 0.0;
    }

    // Performs a withdrawal by creating a WithdrawalTransaction
    void withdrawCash(const string& accountNumber, double amount) {
        Account* account = bankingSystem.getAccount(accountNumber);
        if (account == nullptr || account->getBalance() < amount) {
            cout << "Error: Insufficient balance." << endl;
            return;
        }
        WithdrawalTransaction transaction(generateTransactionId(), *account, amount);
        bankingSystem.processTransaction(transaction);
        cashDispenser.dispenseCash(static_cast<int>(amount));
    }

    // Performs a deposit by creating a DepositTransaction
    void depositCash(const string& accountNumber, double amount) {
        Account* account = bankingSystem.getAccount(accountNumber);
        if (account == nullptr) {
            cout << "Error: Account not found." << endl;
            return;
        }
        DepositTransaction transaction(generateTransactionId(), *account, amount);
        bankingSystem.processTransaction(transaction);
    }

private:
    // Generates a unique transaction ID using an atomic counter and current timestamp
    string generateTransactionId() {
        long transactionNumber = transactionCounter.fetch_add(1) + 1;
        // Get current time as timestamp in format "yyyyMMddHHmmss"
        auto now = chrono::system_clock::now();
        time_t now_time = chrono::system_clock::to_time_t(now);
        struct tm local_tm;
        localtime_s(&local_tm, &now_time);
        char buffer[15]; // "yyyyMMddHHmmss" = 14 chars + null terminator.
        strftime(buffer, sizeof(buffer), "%Y%m%d%H%M%S", &local_tm);
        string timestamp(buffer);
        ostringstream oss;
        oss << "TXN" << timestamp << setw(10) << setfill('0') << transactionNumber;
        return oss.str();
    }
};

// Definition of the static atomic transaction counter.
atomic<long> ATM::transactionCounter(0);
