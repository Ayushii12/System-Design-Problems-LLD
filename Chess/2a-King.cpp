#include <iostream>
#include <cmath>
#include "2-Piece.cpp"

using namespace std;

class King : public Piece {
public:
    King(Color color, int row, int col) : Piece(color, row, col) {}

    // King can move one square in any direction
    bool canMove(int destRow, int destCol) override {
        int dRow = abs(destRow - row);
        int dCol = abs(destCol - col);
        return (dRow <= 1 && dCol <= 1);
    }
};
