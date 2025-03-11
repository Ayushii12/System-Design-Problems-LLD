#include <iostream>
#include <string>
#include "1-User.cpp"
using namespace std;

class Split {
protected:
    User* user;     // The participant for whom the split is calculated
    double amount;  // The calculated amount that the user owes

public:
    Split(User* user) : user(user), amount(0.0) {}
    virtual ~Split() {}
    
    // Getter methods
    User* getUser() { return user; }
    double getAmount() { return amount; }

    // Pure virtual method to calculate the share based on the expense total
    virtual double calculateShare(double expenseTotal) = 0;
    
    // Virtual method to validate the split details
    virtual bool validate() { return true; }
};
