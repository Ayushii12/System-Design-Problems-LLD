#include <iostream>
#include <cmath>
#include "2-Piece.cpp"
using namespace std;

class Bishop : public Piece {
public:
    Bishop(Color color, int row, int col) : Piece(color, row, col) {}

    // Bishop moves diagonally
    bool canMove(int newRow, int newCol) override {
        int dRow = abs(newRow - row);
        int dCol = abs(newCol - col);
        return dRow == dCol;
    }
};
