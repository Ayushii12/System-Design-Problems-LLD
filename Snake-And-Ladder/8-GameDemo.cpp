#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include "7-GameManager.cpp"
using namespace std;

class GameDemo {
public:
    static void run() {
        GameManager* gameManager = GameManager::getInstance();

        // Start game 1
        vector<string> players1 = {"Player 1", "Player 2", "Player 3"};
        gameManager->startNewGame(players1);

        // Start game 2
        vector<string> players2 = {"Player 4", "Player 5"};
        gameManager->startNewGame(players2);
    }
};

int main() {
    GameDemo::run();
    // Allow some time for the detached game threads to run
    this_thread::sleep_for(chrono::seconds(10));
    return 0;
}
