#include <iostream>
#include <mutex>
#include <stdexcept>
using namespace std;

class CashDispenser {
private:
    int cashAvailable;
    mutex mtx;

public:
    CashDispenser(int initialCash) : cashAvailable(initialCash) {}

    // Dispenses cash in a thread-safe manner
    void dispenseCash(int amount) {
        lock_guard<mutex> lock(mtx); 
        if (amount > cashAvailable) {
            throw invalid_argument("Insufficient cash available in the ATM.");
        }
        cashAvailable -= amount;
        cout << "Cash dispensed: " << amount << endl;
    }
};
