# Chess

## Requirements
- The system should have **8X8 board**, with alternating black and white squares
- The system should support **2 players**
- Each player should have **16 pieces**: King, Queen, 2 Knights, 2 Bishops, 2 Rooks, 8 Pawns
- The system should allow the players to make **alternate moves**
- The system should **validate the moves** (legal moves & illegal moves) based on standard chess rules
- The system should actively check for **checkmate** and **stalemate** situations
- The system should declare the **result of the game** (Black won, White won, Draw)

## Entities
- **Player**: Represents a player in the game and has a method to make a move on the board
- **Board**: Represents the chess board and manages the placement of pieces. It provides methods to get and set pieces on the board, check the validity of moves, and determine checkmate and stalemate conditions
- **Piece**: An abstract base class representing a chess piece. It contains common attributes such as color, row, and column, and declares an abstract method canMove to be implemented by each specific piece class
  -  **King, Queen, Rook, Bishop, Knight, Pawn**: Extends the Piece class and implements their respective movement logic in the canMove method 
- **ChessGame**: Orchestrates the overall game flow. It initializes the board, handles player turns, and determines the game result
