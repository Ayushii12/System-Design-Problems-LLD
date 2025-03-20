#include "2-Piece.cpp"
using namespace std;

class Move {
private:
    Piece piece;   
    int destRow;    
    int destCol;    

public:
    Move(Piece piece, int destRow, int destCol)
        : piece(piece), destRow(destRow), destCol(destCol) {}

    // Getters
    Piece getPiece() const { return piece; }
    int getDestRow() const { return destRow; }
    int getDestCol() const { return destCol; }
};
