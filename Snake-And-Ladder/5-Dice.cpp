#include <cstdlib>
#include <ctime>
using namespace std;

class Dice {
private:
    static const int MIN_VALUE = 1;
    static const int MAX_VALUE = 6;

public:
    // Constructor seeds the random number generator
    Dice() {
        srand(static_cast<unsigned int>(time(0)));
    }

    // Generates a random number between MIN_VALUE and MAX_VALUE (inclusive)
    int roll() {
        return (rand() % MAX_VALUE) + MIN_VALUE;
    }
};
