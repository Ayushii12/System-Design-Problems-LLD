#include <iostream>
#include <cmath>
#include "2-Piece.cpp"

using namespace std;

class Queen : public Piece {
public:
    Queen(Color color, int row, int col) : Piece(color, row, col) {}

    // Queen moves like a rook or bishop
    bool canMove(int destRow, int destCol) override {
        int dRow = abs(destRow - row);
        int dCol = abs(destCol - col);
        return (destRow == row || destCol == col) || (dRow == dCol);
    }
};
