#include <iostream>
#include <string>
#include "1-Card.cpp"
#include "2-Account.cpp"
#include "3-Transaction.cpp"
#include "3a-WithdrawalTransaction.cpp"
#include "3b-DepositTransaction.cpp"
#include "4-BankingSystem.cpp"
#include "5-CashDispenser.cpp"
using namespace std;

class ATMDemo {
public:
    static void run() {
        // Create the BankingService instance
        BankingService bankingService;
        
        // Create the CashDispenser instance with an initial cash amount
        CashDispenser cashDispenser(10000);
        
        // Create the ATM instance using the BankingService and CashDispenser
        ATM atm(bankingService, cashDispenser);
        
        // Create sample accounts
        bankingService.createAccount("1234567890", 1000.0);
        bankingService.createAccount("9876543210", 500.0);
        
        // Perform ATM operations
        Card card("1234567890", "1234");
        atm.authenticateUser(card);
        
        double balance = atm.checkBalance("1234567890");
        cout << "Account balance: " << balance << endl;
        
        atm.withdrawCash("1234567890", 500.0);
        atm.depositCash("9876543210", 200.0);
        
        balance = atm.checkBalance("1234567890");
        cout << "Updated account balance: " << balance << endl;
    }
};

int main() {
    ATMDemo::run();
    return 0;
}
