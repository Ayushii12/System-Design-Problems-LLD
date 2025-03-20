#include <iostream>
#include <cmath>
#include "2-Piece.cpp"
using namespace std;

class Pawn : public Piece {
public:
    Pawn(Color color, int row, int col) : Piece(color, row, col) {}

    // Pawn can move
    //    - White pawn, either 1 move upwards or 2 moves upwards (if first move)
    //    - Black pawn, either 1 move downwards or 2 moves downwards (if first move)
    //    - 1 move diagonally, to capture an opponent's piece at the destination square
    bool canMove(Board* board, int newRow, int newCol) override {
        int rowDiff = newRow - row;
        int colDiff = abs(newCol - col);

        if (color == WHITE) {
            // Standard one-step forward move
            if (rowDiff == 1 && colDiff == 0) return true;
            // Two-step forward move from the starting row (assumed row 1 for white pawns)
            if (row == 1 && rowDiff == 2 && colDiff == 0) return true;
            // Diagonal capture
            if (rowDiff == 1 && colDiff == 1 && board->getPiece(newRow, newCol) != nullptr) return true;
        }else {
            // Standard one-step forward move
            if (rowDiff == -1 && colDiff == 0) return true;
            // Two-step forward move from the starting row (assumed row 6 for black pawns)
            if (row == 6 && rowDiff == -2 && colDiff == 0) return true;
            // Diagonal capture
            if (rowDiff == -1 && colDiff == 1 && board->getPiece(newRow, newCol) != nullptr) return true;
        }

        return false;
    }
};
