#include "1-Color.cpp"
#include <iostream>
using namespace std;

class Piece {
protected:
    Color color;
    int row;
    int col;

public:
    Piece(Color color, int row, int col) : color(color), row(row), col(col) {}
    virtual ~Piece() {}

    // Getters
    Color getColor() const { return color; }
    int getRow() const { return row; }
    int getCol() const { return col; }

    // Setters
    void setColor(Color newColor) { color = newColor; }
    void setPosition(int r, int c) {
        row = r;
        col = c;
    }
    
    // Pure virtual method to check if the move is legal
    virtual bool canMove(int destRow, int destCol) = 0;
};
