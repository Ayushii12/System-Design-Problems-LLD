#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include "1-Direction.cpp"
#include "2-Request.cpp"
using namespace std;

class Elevator {
private:
    int id;
    int capacity;  // Maximum no. of requests (i.e. trips) the elevator can queue at a time
    int currentFloor;
    Direction currentDirection;
    vector<Request> requests;
    mutex mtx;  // A mutex lock that protects shared data (such as currentFloor and requests)
    condition_variable cv; // A synchronization primitive that allows threads to wait and be notified when a condition (e.g., new request added) changes

public:
    Elevator(int id, int capacity)
        : id(id), capacity(capacity), currentFloor(1), currentDirection(UP) { }

    int getCurrentFloor() {
        lock_guard<mutex> lock(mtx);
        return currentFloor;
    }

    void addRequest(const Request& request) {
        unique_lock<mutex> lock(mtx);
        if (requests.size() < static_cast<size_t>(capacity)) {
            requests.push_back(request);
            cout << "Elevator " << id
                 << " added request: sourceFloor=" << request.getSourceFloor()
                 << ", destinationFloor=" << request.getDestinationFloor()
                 << endl;
            cv.notify_all(); // To wake any threads waiting for new requests
        }
    }

    Request getNextRequest() {
        unique_lock<mutex> lock(mtx);
        while(requests.empty()) {
            cv.wait(lock);  // Block untill a new request arrives
        }
        Request req = requests.front();
        requests.erase(requests.begin());
        return req;
    }

    void processRequests() {
        while (true){
            // Process all queued requests
            while (!requests.empty()) {
                unique_lock<mutex> lock(mtx);
                Request req = getNextRequest();
                processRequest(req);
            }
            // If no requests remain, wait until a new one arrives
            unique_lock<mutex> lock(mtx);
            cv.wait(lock);
        }
    }

private:
    void processRequest(const Request& request) {
        int startFloor = currentFloor;
        int endFloor = request.getDestinationFloor();

        // Iterates floor by floor until the elevator reaches endFloor, updating currentFloor
        if (startFloor < endFloor) {
            currentDirection = Direction.UP;
            for (int i = startFloor; i <= endFloor; i++) {
                {
                    lock_guard<mutex> lock(mtx);
                    currentFloor = i;
                }
                this_thread::sleep_for(chrono::seconds(1)); // To simulate the time taken to travel to the next floor
            }
        } else if (startFloor > endFloor) {
            currentDirection = Direction.DOWN;
            for (int i = startFloor; i >= endFloor; i--) {
                {
                    lock_guard<mutex> lock(mtx);
                    currentFloor = i;
                }
                this_thread::sleep_for(chrono::seconds(1)); // To simulate the time taken to travel to the next floor
            }
        }
    }

public:
    void run() {
        processRequests();
    }
};
