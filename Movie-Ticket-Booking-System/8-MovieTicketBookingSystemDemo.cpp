#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
#include "MovieTicketBookingSystem.cpp"
#include "Movie.cpp"
#include "Theater.cpp"
#include "Show.cpp"
#include "User.cpp"
#include "Seat.cpp"
#include "Booking.cpp"

using namespace std;

class MovieTicketBookingDemo {
public:
    static void run() {
        MovieTicketBookingSystem& bookingSystem = MovieTicketBookingSystem::getInstance();

        // Add movies
        Movie movie1("M1", "Movie 1", "Description 1", 120);
        Movie movie2("M2", "Movie 2", "Description 2", 135);
        bookingSystem.addMovie(movie1);
        bookingSystem.addMovie(movie2);

        // Add theaters
        Theater theater1("T1", "Theater 1", "Location 1", vector<Show>());
        Theater theater2("T2", "Theater 2", "Location 2", vector<Show>());
        bookingSystem.addTheater(theater1);
        bookingSystem.addTheater(theater2);

        // Add shows
        Show show1("S1", movie1, theater1, time(0), time(0) + movie1.getDurationInMinutes() * 60, createSeats(10, 10));
        Show show2("S2", movie2, theater2, time(0), time(0) + movie2.getDurationInMinutes() * 60, createSeats(8, 8));
        bookingSystem.addShow(show1);
        bookingSystem.addShow(show2);

        // Book tickets
        User user("U1", "John Doe", "john@example.com");
        vector<Seat*> selectedSeats = { show1.getSeats()["1-5"], show1.getSeats()["1-6"] };
        Booking* booking = bookingSystem.bookTickets(user, show1, selectedSeats);
        if (booking != nullptr) {
            cout << "Booking successful. Booking ID: " << booking->getId() << endl;
            bookingSystem.confirmBooking(booking->getId());
        } else {
            cout << "Booking failed. Seats not available." << endl;
        }

        // Cancel booking
        bookingSystem.cancelBooking(booking->getId());
        cout << "Booking canceled. Booking ID: " << booking->getId() << endl;
    }

private:
    static map<string, Seat*> createSeats(int rows, int columns) {
        map<string, Seat*> seats;
        for (int row = 1; row <= rows; row++) {
            for (int col = 1; col <= columns; col++) {
                string seatId = to_string(row) + "-" + to_string(col);
                SeatType seatType = (row <= 2) ? SeatType::PREMIUM : SeatType::NORMAL;
                double price = (seatType == SeatType::PREMIUM) ? 150.0 : 100.0;
                Seat* seat = new Seat(seatId, row, col, seatType, price, SeatStatus::AVAILABLE);
                seats[seatId] = seat;
            }
        }
        return seats;
    }
};

int main() {
    MovieTicketBookingDemo::run();
    return 0;
}
