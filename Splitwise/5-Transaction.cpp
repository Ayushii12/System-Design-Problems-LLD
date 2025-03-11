#include <iostream>
#include <string>
#include "1-User.cpp"
using namespace std;

class Transaction {
private:
    int transactionId;
    User* sender;
    User* receiver;
    double amount;

public:
    // Constructor 
    Transaction(int transactionId, User* sender, User* receiver, double amount)
        : transactionId(transactionId), sender(sender), receiver(receiver), amount(amount) {}

    // Getter methods
    int getTransactionId() const { return transactionId; }
    User* getSender() const { return sender; }
    User* getReceiver() const { return receiver; }
    double getAmount() const { return amount; }
};
