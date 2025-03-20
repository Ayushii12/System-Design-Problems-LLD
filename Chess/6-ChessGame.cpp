#include <iostream>
#include "1-Color.cpp"
#include "3-Move.cpp"
#include "4-Board.cpp"
#include "5-Player.cpp"
using namespace std;

class ChessGame {
private:
    Board board;           
    Player white;          
    Player black;          
    Color currentTurn;     

public:
    ChessGame() 
        : board(), white(WHITE), black(BLACK), currentTurn(WHITE) {}

    void startGame() {
        while (true) {
            Player* currentPlayer = (currentTurn == WHITE) ? &white : &black;
            cout << "\nPlayer " << (currentTurn == WHITE ? "White" : "Black") << "'s turn." << endl;

            // Prompt the player for move input: source and destination coordinates
            int sourceRow, sourceCol, destRow, destCol;
            cout << "Enter source row, source col, destination row, destination col: ";
            cin >> sourceRow >> sourceCol >> destRow >> destCol;

            // Validate that there is a piece at the source location & that the piece belongs to the current player
            Piece* piece = board.getPiece(sourceRow, sourceCol);
            
            if (piece == nullptr) {
                cout << "No piece at the source location. Try again." << endl;
                continue;
            }
            if (piece->getColor() != currentTurn) {
                cout << "That piece does not belong to you. Try again." << endl;
                continue;
            }

            // Create a Move object using the piece and the destination coordinates.
            Move move(*piece, destRow, destCol);
            try {
                currentPlayer->makeMove(board, move);
            } catch (runtime_error& ex) {
                // If move is invalid, display the error and prompt again.
                cout << "Error: " << ex.what() << endl;
                continue;
            }

            // After the move, check if the opponent is in checkmate or stalemate
            Color opponentColor = (currentTurn == WHITE) ? BLACK : WHITE;
            if (board.isCheckmate(opponentColor)) {
                cout << "Checkmate! " << (currentTurn == WHITE ? "White wins!" : "Black wins!") << endl;
                break;
            }
            if (board.isStalemate(opponentColor)) {
                cout << "Stalemate! Draw." << endl;
                break;
            }

            // Switch turns
            currentTurn = opponentColor;
        }
    }
};

int main() {
    ChessGame game;
    game.startGame();
    return 0;
}
