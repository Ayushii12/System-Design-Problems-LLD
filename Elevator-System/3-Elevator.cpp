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
    int capacity;
    int currentFloor;
    Direction currentDirection;
    vector<Request> requests;

    // For synchronizing access
    mutex mtx;
    condition_variable cv;

public:
    Elevator(int id, int capacity)
        : id(id), capacity(capacity), currentFloor(1), currentDirection(UP) {}

    void addRequest(const Request& request) {
        unique_lock<mutex> lock(mtx);
        if (requests.size() < static_cast<size_t>(capacity)) {
            requests.push_back(request);
            cout << "Elevator " << id
                 << " added request: sourceFloor=" << request.getSourceFloor()
                 << ", destinationFloor=" << request.getDestinationFloor()
                 << endl;
            cv.notify_all();
        }
    }

    Request getNextRequest() {
        unique_lock<mutex> lock(mtx);
        while (requests.empty()) {
            cv.wait(lock);
        }
        Request req = requests.front();
        requests.erase(requests.begin());
        return req;
    }

    void processRequests() {
        while (true) {
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

        if (startFloor < endFloor) {
            currentDirection = UP;
            for (int i = startFloor; i <= endFloor; i++) {
                {
                    lock_guard<mutex> lock(mtx);
                    currentFloor = i;
                }
                cout << "Elevator " << id << " reached floor " << i << endl;
                this_thread::sleep_for(chrono::seconds(1)); // simulate movement
            }
        } else if (startFloor > endFloor) {
            currentDirection = DOWN;
            for (int i = startFloor; i >= endFloor; i--) {
                {
                    lock_guard<mutex> lock(mtx);
                    currentFloor = i;
                }
                cout << "Elevator " << id << " reached floor " << i << endl;
                this_thread::sleep_for(chrono::seconds(1)); // simulate movement
            }
        }
    }

public:
    void run() {
        processRequests();
    }

    int getCurrentFloor() {
        lock_guard<mutex> lock(mtx);
        return currentFloor;
    }
};
