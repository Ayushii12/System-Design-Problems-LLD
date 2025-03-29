# Snake and Ladder Game

## Requirements
- The game should be played on a board, numbered from 1 to 100
- The game should have predefined snakes and ladders conncting certain cells
- The game should have a dice
- The players should take turns rolling the dice to determine no. of steps to move forward
  - After rolling a dice, if a player lands on a cell with the head of a snake, the player should slide down to the cell having the tail of the snake
  - After rolling a dice, if a player lands on a cell with the base of a ladder, the player should climb up to the cell having the top the ladder
- The game should support multiple players, each having their own piece
- The game should continue until one of the players win
- The game should handle multiple game sessions concurrently, allowing different groups of players to play independently

## Entities
- **Player**: Represents a player in the game with properties such as id & current position
- **Snake**: Represents a snake on the board, with properties for the start and end positions
- **Ladder**: Represents a ladder on the board, with properties for the start and end positions
- **Dice**: Represents a dice used in the game, with a method to roll the dice and return a random value between 1 and 6
- **Board**: Represents a game board, numbered from 1 to 100. It contains the positions of snakes and ladders. It has a method that returns the new position after encountering either snake or ladder
- **Game**: Represents a single game session. It initializes the game with a board, a list of players, and a dice. Provides a 'play' method, where players take turns rolling the dice and moving their positions on the board. It checks for snakes and ladders and updates the player's position accordingly. The game continues until a player reaches the final position on the board
- **GameManager**: Follows singleton pattern. Manages multiple game sessions. It maintains a list of active games and provides a method to start a new game with a list of player names. Each game is started in a separate thread to allow concurrent game sessions
- **GameDemo**: Demonstrates the usage of the game by creating an instance of the GameManager and handling multiple sessions of the game each having different set of players
