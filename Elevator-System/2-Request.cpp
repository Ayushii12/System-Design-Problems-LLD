#include <iostream>
using namespace std;

class Request {
private:
    int sourceFloor;
    int destinationFloor;

public:
    Request(int sourceFloor, int destinationFloor)
        : sourceFloor(sourceFloor), destinationFloor(destinationFloor) {}

    // Getters
    int getSourceFloor() const { return sourceFloor; }
    int getDestinationFloor() const { return destinationFloor; }
};
