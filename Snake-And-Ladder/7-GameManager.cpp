#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include "6-Game.cpp"
using namespace std;

class GameManager {
private:
    static GameManager* instance;
    vector<Game*> games;
    static mutex mtx;  // mutex to ensure thread-safe instance creation

    // Private constructor to enforce singleton pattern
    GameManager() {}

public:
    // Delete copy constructor and assignment operator
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;

    // Returns the singleton instance of GameManager
    static GameManager* getInstance() {
        lock_guard<mutex> lock(mtx);
        if (instance == nullptr) {
            instance = new GameManager();
        }
        return instance;
    }

    // Starts a new game on a separate thread
    void startNewGame(const vector<string>& playerNames) {
        Game* game = new Game(playerNames);
        games.push_back(game);
        // Start the game in a new thread and detach it
        thread t([game]() { game->play(); });
        t.detach();
    }

    // Destructor cleans up allocated game objects
    ~GameManager() {
        for (auto game : games) {
            delete game;
        }
    }
};

// Initialize static members
GameManager* GameManager::instance = nullptr;
mutex GameManager::mtx;
