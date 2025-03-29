#include <iostream>
#include <vector>
#include <string>
#include "1-Player.cpp"
#include "5-Dice.cpp"
#include "4-Board.cpp"
using namespace std;

class SnakeAndLadderGame {
private:
    Board board;
    vector<Player> players;
    Dice dice;
    int currentPlayerIndex;

public:
    // Constructor: takes a vector of player names and initializes the board, dice, and players
    SnakeAndLadderGame(const vector<string>& playerNames)
        : board(), dice(), currentPlayerIndex(0)
    {
        for (const auto &playerName : playerNames) {
            players.push_back(Player(playerName));
        }
    }
    
    // Plays the game until one of the players wins
    void play() {
        while (true) {
            Player &currentPlayer = players[currentPlayerIndex];   // Get the current player by reference to allow modification
            int diceRoll = dice.roll();
            int newPosition = currentPlayer.getPosition() + diceRoll;

            // Check if the new position lands on a snake or a ladder
            if (newPosition <= board.getBoardSize()) {
                currentPlayer.setPosition(board.getNewPositionAfterSnakeOrLadder(newPosition));
                cout << currentPlayer.getName() << " rolled a " << diceRoll 
                     << " and moved to position " << currentPlayer.getPosition() << endl;
            }
            
            if (currentPlayer.getPosition() == board.getBoardSize()) {
                cout << currentPlayer.getName() << " wins!" << endl;
                break;
            }
            
            // Update currentPlayerIndex for the next turn
            currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
        }
    }
};
