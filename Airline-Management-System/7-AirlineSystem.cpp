#include <memory>
#include <ctime>
#include "1-Passenger.cpp"
#include "2-Aircraft.cpp"
#include "3-Seat.cpp"
#include "4-Flight.cpp"
#include "4b-SearchFlights.cpp"
#include "5b-BookingManager.cpp"
#include "6b-PaymentProcessor.cpp"

class AirlineManagementSystem {
private:
    vector<Flight> flights;
    vector<Aircraft> aircrafts;
    FlightSearch flightSearch;
    BookingManager& bookingManager;
    PaymentProcessor& paymentProcessor;

public:
    // Constructor
    AirlineManagementSystem()
        : flightSearch(flights),
          bookingManager(BookingManager::getInstance()),
          paymentProcessor(PaymentProcessor::getInstance()) {}

    // Add a flight to the system
    void addFlight(const Flight& flight) {
        flights.push_back(flight);
    }

    // Add an aircraft to the system
    void addAircraft(const Aircraft& aircraft) {
        aircrafts.push_back(aircraft);
    }

    // Search for flights based on source, destination, and date
    vector<Flight> searchFlights(const string& source, const string& destination, const tm& date) {
        return flightSearch.searchFlights(source, destination, date);
    }

    // Book a flight
    Booking bookFlight(Flight& flight, Passenger& passenger, Seat& seat, double price) {
        return bookingManager.createBooking(flight, passenger, seat, price);
    }

    // Cancel a booking
    void cancelBooking(const string& bookingNumber) {
        bookingManager.cancelBooking(bookingNumber);
    }

    // Process a payment
    void processPayment(Payment& payment) {
        paymentProcessor.processPayment(payment);
    }
};
