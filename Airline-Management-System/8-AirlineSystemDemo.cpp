#include <ctime>
#include "1-Passenger.cpp"
#include "2-Aircraft.cpp"
#include "3-Seat.h"
#include "3a-SeatType.h"
#include "4-Flight.h"
#include "5-Booking.h"
#include "5b-BookingManager.h"
#include "6-Payment.h"
#include "6b-PaymentProcessor.h"
#include "7-AirlineSystem.cpp"

class AirlineManagementSystemDemo {
public:
    static void run() {
        AirlineManagementSystem airlineManagementSystem;

        // Create passenger
        Passenger passenger1("U001", "John Doe", "john@example.com", "1234567890");

        // Create flight 1
        time_t now = time(0);
        tm departureTime1 = *localtime(&now);
        departureTime1.tm_mday += 1; // Departure in 1 day
        tm arrivalTime1 = departureTime1;
        arrivalTime1.tm_hour += 2;
        
        Flight flight1("F001", "New York", "London", departureTime1, arrivalTime1);
        airlineManagementSystem.addFlight(flight1);

        // Create flight 2
        tm departureTime2 = *localtime(&now);
        departureTime2.tm_mday += 3; // Departure in 3 days
        tm arrivalTime2 = departureTime2;
        arrivalTime2.tm_hour += 5;

        Flight flight2("F002", "Paris", "Tokyo", departureTime2, arrivalTime2);
        airlineManagementSystem.addFlight(flight2);

        // Create aircrafts
        Aircraft aircraft1("A001", "Boeing 747", 300);
        airlineManagementSystem.addAircraft(aircraft1);
        Aircraft aircraft2("A002", "Airbus A380", 500);
        airlineManagementSystem.addAircraft(aircraft2);

        // Search flights
        vector<Flight> searchResults = airlineManagementSystem.searchFlights("New York", "London", departureTime1);
        for (const auto& flight : searchResults) {
            cout << "Flight: " << flight.getFlightNumber() << " - " << flight.getSource() << " to " << flight.getDestination() << endl;
        }

        Seat seat("25A", SeatType::ECONOMY);

        // Book a flight
        Booking booking = airlineManagementSystem.bookFlight(flight1, passenger1, seat, 100);
        if (booking.getBookingNumber() != "") {
            cout << "Booking successful. Booking ID: " << booking.getBookingNumber() << endl;
        } else {
            cout << "Booking failed." << endl;
        }

        // Cancel a booking
        airlineManagementSystem.cancelBooking(booking.getBookingNumber());
        cout << "Booking cancelled." << endl;
    }
};

int main() {
    AirlineManagementSystemDemo::run();
    return 0;
}
