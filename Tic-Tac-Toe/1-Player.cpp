#include <iostream>
using namespace std;

class Player {
private:
    string name;
    char symbol;

public:
    Player(const string& playerName, char playerSymbol) : name(playerName), symbol(playerSymbol) {}
    
    string getName() const {
        return name;
    }
    
    char getSymbol() const {
        return symbol;
    }
    
    void setName(const string& playerName) {
        name = playerName;
    }
    
    void setSymbol(char playerSymbol) {
        symbol = playerSymbol;
    }
};
