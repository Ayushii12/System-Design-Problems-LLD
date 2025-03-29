#include <iostream>
using namespace std;

class Ladder {
private:
    const int start;
    const int end;

public:
    Ladder(int start, int end) : start(start), end(end) {}

    // Getters
    int getStart() const { return start; }
    int getEnd() const { return end; }
};
