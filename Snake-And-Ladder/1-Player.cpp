#include <string>
using namespace std;

class Player {
private:
    const string name;
    int position;

public:
    Player(const string &name) : name(name), position(0) {}

    // Getters
    string getName() const { return name; }
    int getPosition() const { return position; }

    // Setters
    void setPosition(int position) {
        this->position = position;
    }
};
