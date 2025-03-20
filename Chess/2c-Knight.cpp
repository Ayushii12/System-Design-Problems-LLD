#include <iostream>
#include <cmath>
#include "2-Piece.cpp"
using namespace std;

class Knight : public Piece {
public:
    Knight(Color color, int row, int col) : Piece(color, row, col) {}

    // Knight moves in an 'L' shape
    bool canMove(int newRow, int newCol) override {
        int dRow = abs(newRow - row);
        int dCol = abs(newCol - col);
        return (dRow == 2 && dCol == 1) || (dRow == 1 && dCol == 2);
    }
};
