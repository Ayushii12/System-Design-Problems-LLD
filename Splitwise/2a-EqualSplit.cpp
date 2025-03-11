#include "2-Split.cpp"  
using namespace std;

class EqualSplit : public Split {
private:
    int totalParticipants;  // Total number of participants in the expense
public:
    EqualSplit(User* user, int totalParticipants)
        : Split(user), totalParticipants(totalParticipants) {}

    // Divides the total expense equally among participants
    double calculateShare(double expenseTotal) override {
        if(totalParticipants <= 0) return 0;
        amount = expenseTotal / totalParticipants;
        return amount;
    }

    // Validation: simply checks that the number of participants is positive
    bool validate() override {
        return (totalParticipants > 0);
    }
};
