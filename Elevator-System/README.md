# Elevator System

## Requirements
- The system should have multiple elevators each serving for multiple floors
- Users should be able to
  - Request elevator at any floor
  - Select a destination floor
- Each elevator should have a capacity limit and should not exceed it
- The system should efficiently handle the assignment of elevators to minimize the wait time
  - The system should prioritize requests based on
    - Direction of the request (up/down)
    - Proximity to the requested floor
- The system should be able to handle multiple requests concurrently

## Entities
- **Direction**: Enum that represents the directions of elevator movement (UP/DOWN)
- **Request**: Represents a user request for an elevator, with properties such as source floor and destination floor
- **Elevator**: Represents an individual elevator, with properties such as id, capacity, currentFloor, currentDirection, list of requests. Also provdes a method to process requests 
- **ElevatorManager**: Manages multiple elevators and handles user requests by finding the optimal elevator
- **ElevatorSystemDemo**: Entry point of the application and demonstrates the usage of the elevator system
