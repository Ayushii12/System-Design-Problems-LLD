#include <iostream>
#include "2-Piece.cpp"
#include "2a-King.cpp"
#include "2b-Queen.cpp"
#include "2c-Knight.cpp"
#include "2d-Bishop.cpp"
#include "2e-Rook.cpp"
#include "2f-Pawn.cpp"
using namespace std;

class Board {
private:
    Piece* board[8][8]; 

    void initializeBoard() {
        // Initialize all squares to nullptr first
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                board[i][j] = nullptr;

        // Initialize white pieces on row 0 and row 1
        board[0][0] = new Rook(WHITE, 0, 0);
        board[0][1] = new Knight(WHITE, 0, 1);
        board[0][2] = new Bishop(WHITE, 0, 2);
        board[0][3] = new Queen(WHITE, 0, 3);
        board[0][4] = new King(WHITE, 0, 4);
        board[0][5] = new Bishop(WHITE, 0, 5);
        board[0][6] = new Knight(WHITE, 0, 6);
        board[0][7] = new Rook(WHITE, 0, 7);
        for (int i = 0; i < 8; i++) {
            board[1][i] = new Pawn(WHITE, 1, i);
        }

        // Initialize black pieces on row 7 and row 6
        board[7][0] = new Rook(BLACK, 7, 0);
        board[7][1] = new Knight(BLACK, 7, 1);
        board[7][2] = new Bishop(BLACK, 7, 2);
        board[7][3] = new Queen(BLACK, 7, 3);
        board[7][4] = new King(BLACK, 7, 4);
        board[7][5] = new Bishop(BLACK, 7, 5);
        board[7][6] = new Knight(BLACK, 7, 6);
        board[7][7] = new Rook(BLACK, 7, 7);
        for (int i = 0; i < 8; i++) {
            board[6][i] = new Pawn(BLACK, 6, i);
        }
    }

public:
    Board() {
        initializeBoard();
    }

    // Destructor: clean up the dynamically allocated pieces
    ~Board() {
        for (int i = 0; i < 8; ++i){
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] != nullptr) {
                    delete board[i][j];
                    board[i][j] = nullptr;
                }
            }
        }
    }

    // Returns the piece at the given row and column. Returns nullptr if out-of-bounds
    Piece* getPiece(int row, int col) const {
        if (row < 0 || row >= 8 || col < 0 || col >= 8)
            return nullptr;
        return board[row][col];
    }

    // Sets the piece at the given row and column
    void setPiece(int row, int col, Piece* piece) {
        if (row >= 0 && row < 8 && col >= 0 && col < 8)
            board[row][col] = piece;
    }

    // A move is valid if:
    //   - The destination coordinates are within bounds
    //   - The destination square is either empty or occupied by an opponent's piece
    //   - The piece's canMove method returns true for the move
    bool isValidMove(Piece* piece, int destRow, int destCol) {
        if (piece == nullptr || destRow < 0 || destRow > 7 || destCol < 0 || destCol > 7) return false;
        Piece* destPiece = board[destRow][destCol];
        if ((destPiece == nullptr || destPiece->getColor() != piece->getColor()) && piece->canMove(this, destRow, destCol))
            return true;
        return false;
    }

    // Method for checkmate detection
    //   - If king is in check and has no valid move to make
    //   - King is in check if any 'opponent' piece can legally move to the 'king's square'
    //   - Simulate 'every' possible legal move for 'all' the pieces of that color
    //   - If no move can relieve the check, then the position is declared checkmate
    bool isCheckmate(Color color) {
        return false;
    }

    // Method for stale mate detection
    //   - The king is not in check but no legal move exists for any piece of that color 
    bool isStalemate(Color color) {
        return false;
    }
};
