#include <iostream>
#include <string>
#include <vector>
#include <cmath>   
#include "1-User.cpp"
#include "2-Split.cpp"
using namespace std;

class Expense {
private:
    int id;
    double amount;
    string description;
    User* paidBy;             // The user who paid for the expense
    vector<Split*> splits;    // List of splits associated with this expense

public:
    // Constructor 
    Expense(int id, double amount, const string &description, User* paidBy)
        : id(id), amount(amount), description(description), paidBy(paidBy) {}

    // Destructor: free the allocated splits 
    ~Expense() {
        for (auto split : splits) { delete split; }
    }

    // Getter methods
    int getId() const { return id; }
    double getAmount() const { return amount; }
    string getDescription() const { return description; }
    User* getPaidBy() const { return paidBy; }
    const vector<Split*>& getSplits() const { return splits; }

    // Add a split to this expense
    void addSplit(Split* split) {
        splits.push_back(split);
    }

    // Validate the expense by ensuring that the sum of split amounts equals the total expense
    // A small tolerance is used to account for floating-point precision issues
    bool validate() {
        double totalSplitAmount = 0;
        for (auto split : splits) {
            totalSplitAmount += split->getAmount();
        }
        return (fabs(totalSplitAmount - amount) < 0.001);
    }
};
