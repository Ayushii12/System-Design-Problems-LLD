#include <iostream>
#include <thread>
#include <chrono>
#include "4-ElevatorManager.cpp"
using namespace std;

class ElevatorSystemDemo {
public:
    static void run() {
        ElevatorManager controller(3, 5);

        // Simulate incoming elevator requests
        controller.requestElevator(5, 10);
        controller.requestElevator(3, 7);
        controller.requestElevator(8, 2);
        controller.requestElevator(1, 9);
    }
};

int main() {
    ElevatorSystemDemo::run();

    // Prevent main from exiting immediately
    // Since we detached the threads in ElevatorManager, if main returns, the program ends. 
    // A simple way to keep it alive is an infinite loop or sleep.
    while (true) {
        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
