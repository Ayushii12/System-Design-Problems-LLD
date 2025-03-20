#include <iostream>
#include <cmath>
#include "2-Piece.cpp"
using namespace std;

class Queen : public Piece {
public:
    Queen(Color color, int row, int col) : Piece(color, row, col) {}

    // Queen moves like a rook or bishop
    bool canMove(int newRow, int newCol) override {
        int dRow = abs(newRow - row);
        int dCol = abs(newCol - col);
        return (newRow == row || newCol == col) || (dRow == dCol);
    }
};
