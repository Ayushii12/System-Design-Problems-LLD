#include <ctime> // For time handling

class Flight {
private:
    std::string flightNumber;
    std::string source;
    std::string destination;
    std::time_t departureTime;
    std::time_t arrivalTime;
    std::vector<Seat> availableSeats;

public:
    // Constructor
    Flight(const string& flightNumber, const string& source, const string& destination, 
           time_t departureTime, time_t arrivalTime)
        : flightNumber(flightNumber), source(source), destination(destination), 
          departureTime(departureTime), arrivalTime(arrivalTime) {}

    // Getter functions
    string getFlightNumber() const { return flightNumber; }
    string getSource() const { return source; }
    string getDestination() const { return destination; }
    time_t getDepartureTime() const { return departureTime; }
    time_t getArrivalTime() const { return arrivalTime; }
    const vector<Seat>& getAvailableSeats() const { return availableSeats; }

    // Function to add seats to the flight
    void addSeat(const Seat& seat) {
        availableSeats.push_back(seat);
    }

    // Function to display flight information
    void displayInfo() const {
        cout << "Flight Number: " << flightNumber << "\n";
        cout << "Source: " << source << "\n";
        cout << "Destination: " << destination << "\n";
        cout << "Departure Time: " << ctime(&departureTime);
        cout << "Arrival Time: " << ctime(&arrivalTime);
        cout << "Available Seats: " << availableSeats.size() << "\n";
    }
};
