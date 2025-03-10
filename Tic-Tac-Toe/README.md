# Tic-Tac-Toe

## Requirements
- The game should have a user interface to display the **3X3 board**
- The system should allow the **two** players to **take turns** to place symbols (**X** or **O**) on the board
- The system should **validate** player moves to ensure they are **legal**
- The first player to get three of their symbols in a row (**horizontally, vertically, or diagonally**) wins the game
- If all the cells on the grid are filled and no player has won, the game ends in a **draw**
  
## Entities
- **Player**: Represents a player in the game, with properties such as name and a symbol (X or O)
- **Board**: Represents a board in the game, with a 3X3 grid. It provides methods to make moves, check for a winner, and check if the board is full
- **Game**: Manages the game flow and player turns. It prvides methods to handle player turns, validate moves, and determine the game result
- **TicTacToe**: Main class that creates instances of the players and the game
