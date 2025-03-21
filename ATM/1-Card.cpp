#include <string>
using namespace std;

class Card {
private:
    const string cardNumber;
    const string pin;

public:
    Card(const string& cardNumber, const string& pin)
        : cardNumber(cardNumber), pin(pin) {}

    // Getters
    string getCardNumber() const { return cardNumber; }
    string getPin() const { return pin; }
};
