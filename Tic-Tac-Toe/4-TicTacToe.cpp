#include <iostream>
#include "3-Game.cpp"

using namespace std;

int main() {
    string player1Name, player2Name;
    char player1Symbol, player2Symbol;

    cout << "Enter Player 1 name: ";
    cin >> player1Name;
    cout << "Enter Player 1 symbol (X/O): ";
    cin >> player1Symbol;

    // Ensure player1Symbol is either 'X' or 'O'
    while (player1Symbol != 'X' && player1Symbol != 'O') {
        cout << "Invalid symbol. Please enter X or O for Player 1: ";
        cin >> player1Symbol;
    }

    // Player 2 gets the opposite symbol
    player2Symbol = (player1Symbol == 'X') ? 'O' : 'X';

    cout << "Enter Player 2 name: ";
    cin >> player2Name;

    // Creating a Game instance with player names and their symbols
    Game game(player1Name, player2Name, player1Symbol, player2Symbol);

    // Start the game
    cout << "Game Start!" << endl;
    game.startGame();

    return 0;
}
