#include <iostream>
using namespace std;

class Board {
private:
    vector<vector<char>> grid;

public:
    Board() : grid(3, vector<char>(3, ' ')) {}

    void displayBoard() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << grid[i][j];
                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "---------" << endl;
        }
    }

    bool makeMove(int row, int col, char symbol) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || grid[row][col] != ' ') {
            return false;
        }
        grid[row][col] = symbol;
        return true;
    }

    bool checkWinner(char symbol) const {
        for (int i = 0; i < 3; ++i) {
            if ((grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) ||
                (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol)) {
                return true;
            }
        }
        if ((grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) ||
            (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol)) {
            return true;
        }
        return false;
    }

    bool isFull() const {
        for (const auto& row : grid) {
            for (char cell : row) {
                if (cell == ' ') return false;
            }
        }
        return true;
    }
};
