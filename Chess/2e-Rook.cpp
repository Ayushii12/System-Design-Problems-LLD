#include <iostream>
#include <cmath>
#include "2-Piece.cpp"
using namespace std;

class Rook : public Piece {
public:
    Rook(Color color, int row, int col) : Piece(color, row, col) {}

    // Rook moves horizontally or vertically
    bool canMove(int newRow, int newCol) override {
      return (newRow == row || newCol == col);
    }
};
