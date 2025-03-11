#include "2-Split.cpp"  
using namespace std;

class ExactSplit : public Split {
private:
    double exactAmount;  
public:
    ExactSplit(User* user, double exactAmount)
        : Split(user), exactAmount(exactAmount) {}

    // For an exact split, the provided amount is used directly
    double calculateShare(double expenseTotal) override {
        amount = exactAmount;
        return amount;
    }

    // Validation: ensure that the exact amount is not negative
    bool validate() override {
        return (exactAmount >= 0);
    }
};
