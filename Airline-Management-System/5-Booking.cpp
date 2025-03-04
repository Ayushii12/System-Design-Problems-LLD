#include "4-Flight.cpp"
#include "1-Passenger.cpp"
#include "3-Seat.cpp"
#include "5a-BookingStatus.cpp"

class Booking {
private:
    string bookingNumber;
    Flight flight;
    Passenger passenger;
    Seat selected_seat;
    double price;
    BookingStatus status;

public:
    // Constructor
    Booking(const string& bookingNumber, const Flight& flight, const Passenger& passenger, 
            const Seat& seat, double price)
        : bookingNumber(bookingNumber), flight(flight), passenger(passenger), 
          selected_seat(eat), price(price), status(BookingStatus::CONFIRMED) {}

    // Getter functions
    string getBookingNumber() const { return bookingNumber; }
    Flight getFlight() const { return flight; }
    Passenger getPassenger() const { return passenger; }
    Seat getSeat() const { return selected_seat; }
    double getPrice() const { return price; }
    BookingStatus getStatus() const { return status; }

    // To cancel the booking
    void cancel() {
        status = BookingStatus::CANCELLED;
    }
};
