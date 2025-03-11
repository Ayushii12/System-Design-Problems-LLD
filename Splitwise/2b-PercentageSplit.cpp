#include "2-Split.cpp"  
using namespace std;

class PercentageSplit : public Split {
private:
    double percentage;  
public:
    PercentageSplit(User* user, double percentage)
        : Split(user), percentage(percentage) {}

    // Calculates the share based on the given percentage
    double calculateShare(double expenseTotal) override {
        amount = (percentage / 100.0) * expenseTotal;
        return amount;
    }

    // Validation: ensure the percentage is between 0 and 100
    bool validate() override {
        return (percentage >= 0 && percentage <= 100);
    }
};
