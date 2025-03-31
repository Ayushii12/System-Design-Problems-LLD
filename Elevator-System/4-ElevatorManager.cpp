#include <iostream>
#include <vector>
#include <thread>
#include <memory>
#include <climits>    
#include <cmath>  
#include "3-Elevator.cpp"
using namespace std;

class ElevatorManager {
private:
    // Store each Elevator in a vector of smart pointers for easy thread-safety and lifetime management
    vector<unique_ptr<Elevator>> elevators;

public:
    ElevatorManager(int numElevators, int capacity) {
        // Create each Elevator, start its 'run' method in a separate thread
        for (int i = 0; i < numElevators; i++) {
            auto elevatorPtr = make_unique<Elevator>(i + 1, capacity);
            // Start the elevator's main loop on a detached thread
            thread(&Elevator.run, elevatorPtr.get()).detach();
            // Now store the elevator in our vector
            elevators.push_back(move(elevatorPtr));
        }
    }

    // Request an Elevator
    void requestElevator(int sourceFloor, int destinationFloor) {
        Elevator* optimalElevator = findOptimalElevator(sourceFloor, destinationFloor);
        // Create a new Request and add it to the chosen Elevator
        if (optimalElevator) {
            Request req(sourceFloor, destinationFloor);
            optimalElevator->addRequest(req);
        }
    }

private:
    // Find the Elevator that is currently closest to the source floor
    Elevator* findOptimalElevator(int sourceFloor, int destinationFloor) {
        Elevator* optimalElevator = nullptr;
        int minDistance = INT_MAX;
        for (auto& elevatorPtr : elevators) {
            int distance = abs(sourceFloor - elevatorPtr->getCurrentFloor());
            if (distance < minDistance) {
                minDistance = distance;
                optimalElevator = elevatorPtr.get();
            }
        }
        return optimalElevator;
    }
};
