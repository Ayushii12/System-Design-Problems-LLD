#include <iostream>
#include "1-Player.cpp"
#include "2-Board.cpp"
using namespace std;

class Game {
private:
    Player* player1;
    Player* player2;
    Board board;
    Player* currentPlayer;

public:
    Game(const string& player1Name, const string& player2Name, char player1Symbol, char player2Symbol) {
        player1 = new Player(player1Name, player1Symbol);
        player2 = new Player(player2Name, player2Symbol);
        currentPlayer = player1;  // Player 1 starts the game
    }

    ~Game() {
        delete player1;
        delete player2;
    }

    void switchTurn() {
        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }

    bool validateMove(int row, int col) {
        if (board.makeMove(row, col, currentPlayer->getSymbol())) {
            return true;
        } else {
            cout << "Invalid move! Try again." << endl;
            return false;
        }
    }

    bool isGameOver() {
        if (board.checkWinner(currentPlayer->getSymbol())) {
            cout << "Player " << currentPlayer->getName() << " wins!" << endl;
            return true;
        }

        if (board.isFull()) {
            cout << "The game is a draw!" << endl;
            return true;
        }

        return false;
    }

    void printBoard() {
        board.displayBoard();
    }

    void playTurn(int row, int col) {
        if (validateMove(row, col)) {
            printBoard();
            if (isGameOver()) { return; }
            switchTurn();
        }
    }

    void startGame() {
        int row, col;
        while (!isGameOver()) {
            cout << "Player " << currentPlayer->getName() << "'s turn (" << currentPlayer->getSymbol() << "):" << endl;
            cout << "Enter row (0-2): ";
            cin >> row;
            cout << "Enter column (0-2): ";
            cin >> col;

            playTurn(row, col);
        }
    }
};
