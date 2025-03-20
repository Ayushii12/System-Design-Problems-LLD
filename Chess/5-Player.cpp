#include "1-Color.cpp"
#include "2-Piece.cpp"
#include "3-Move.cpp"
#include "4-Board.cpp"
using namespace std;

class Player {
private:
    Color color; // The player's color
public:
    Player(Color color) : color(color) {}

    Color getColor() const { return color; }

    // Attempts to make a move on the board
    //     - If the move is valid, the piece is moved; otherwise, an exception is thrown
    void makeMove(Board& board, Move& move){
        Piece& piece = move.getPiece();
        int destRow = move.getDestRow();
        int destCol = move.getDestCol();
  
        if (board.isValidMove(&piece, destRow, destCol)) {
            int sourceRow = piece.getRow();
            int sourceCol = piece.getCol();
            
            board.setPiece(sourceRow, sourceCol, nullptr);  // Remove the piece from its source position
            board.setPiece(destRow, destCol, &piece);
            piece.setPosition(destRow, destCol);
        }else{
            throw runtime_error("Invalid move!");
        }
    }
};







