#include <vector>
#include "2-Snake.cpp"
#include "3-Ladder.cpp"
using namespace std;

class Board {
private:
    static const int BOARD_SIZE = 100;
    vector<Snake> snakes;
    vector<Ladder> ladders;

    void initializeSnakesAndLadders() {
        // Initialize snakes
        snakes.push_back(Snake(16, 6));
        snakes.push_back(Snake(48, 26));
        snakes.push_back(Snake(64, 60));
        snakes.push_back(Snake(93, 73));

        // Initialize ladders
        ladders.push_back(Ladder(1, 38));
        ladders.push_back(Ladder(4, 14));
        ladders.push_back(Ladder(9, 31));
        ladders.push_back(Ladder(21, 42));
        ladders.push_back(Ladder(28, 84));
        ladders.push_back(Ladder(51, 67));
        ladders.push_back(Ladder(80, 99));
    }
    
public:
    Board() {
        initializeSnakesAndLadders();
    }

    // Getters
    int getBoardSize() { return BOARD_SIZE; }

    // Returns the new position of a player after encountering a snake or ladder
    int getNewPositionAfterSnakeOrLadder(int position) {
        for (auto &snake : snakes) {
            if (snake.getStart() == position)
                return snake.getEnd();
        }
        for (auto &ladder : ladders) {
            if (ladder.getStart() == position)
                return ladder.getEnd();
        }
        return position;
    }
};
