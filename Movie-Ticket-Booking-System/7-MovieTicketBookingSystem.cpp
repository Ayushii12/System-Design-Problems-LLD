#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <mutex>
#include <atomic>
#include <chrono>
#include <sstream>
#include "Movie.cpp"      
#include "Theater.cpp"   
#include "Show.cpp"        
#include "Booking.cpp"     
#include "Seat.cpp"       
#include "User.cpp"        
#include "BookingStatus.cpp" 

class MovieTicketBookingSystem {
private:
    std::vector<Movie> movies;
    std::vector<Theater> theaters;
    std::map<std::string, Show> shows;
    std::map<std::string, Booking> bookings;

    // Define static members 
    static MovieTicketBookingSystem* instance;
    static const std::string BOOKING_ID_PREFIX;
    static std::long bookingCounter;
    static std::mutex mtx;

    MovieTicketBookingSystem() {}

public:
    // Singleton pattern
    static MovieTicketBookingSystem* getInstance() {
        if (instance == nullptr) {
            instance = new MovieTicketBookingSystem();
        }
        return instance;
    }

    // Add movie
    void addMovie(const Movie& movie) {
        movies.push_back(movie);
    }

    // Add theater
    void addTheater(const Theater& theater) {
        theaters.push_back(theater);
    }

    // Add show
    void addShow(const Show& show) {
        shows[show.getId()] = show;
    }

    // Get list of movies
    std::vector<Movie> getMovies() const {
        return movies;
    }

    // Get list of theaters
    std::vector<Theater> getTheaters() const {
        return theaters;
    }

    // Get show by ID
    Show getShow(const std::string& showId) const {
        return shows.at(showId);
    }

    // Book tickets
    Booking bookTickets(const User& user, const Show& show, const std::vector<Seat>& selectedSeats) {
        std::lock_guard<std::mutex> lock(mtx);  // Locking for thread safety
        if (areSeatsAvailable(show, selectedSeats)) {
            markSeatsAsBooked(show, selectedSeats);
            double totalPrice = calculateTotalPrice(selectedSeats);
            std::string bookingId = generateBookingId();
            Booking booking(bookingId, user, show, selectedSeats, totalPrice, BookingStatus::PENDING);
            bookings[bookingId] = booking;
            return booking;
        }
        return Booking("", user, show, {}, 0.0, BookingStatus::CANCELLED);  // Return empty booking if failed
    }

    // Confirm booking
    void confirmBooking(const std::string& bookingId) {
        std::lock_guard<std::mutex> lock(mtx);
        auto it = bookings.find(bookingId);
        if (it != bookings.end() && it->second.getStatus() == BookingStatus::PENDING) {
            it->second.setStatus(BookingStatus::CONFIRMED);
        }
    }

    // Cancel booking
    void cancelBooking(const std::string& bookingId) {
        std::lock_guard<std::mutex> lock(mtx);
        auto it = bookings.find(bookingId);
        if (it != bookings.end() && it->second.getStatus() != BookingStatus::CANCELLED) {
            it->second.setStatus(BookingStatus::CANCELLED);
            markSeatsAsAvailable(it->second.getShow(), it->second.getSeats());
        }
    }

private:
    // Check if seats are available
    bool areSeatsAvailable(const Show& show, const std::vector<Seat>& selectedSeats) const {
        for (const Seat& seat : selectedSeats) {
            auto it = show.getSeats().find(seat.getId());
            if (it == show.getSeats().end() || it->second.getStatus() != SeatStatus::AVAILABLE) {
                return false;
            }
        }
        return true;
    }

    // Mark seats as booked
    void markSeatsAsBooked(Show& show, const std::vector<Seat>& selectedSeats) {
        for (const Seat& seat : selectedSeats) {
            auto& showSeat = show.getSeats()[seat.getId()];
            showSeat.setStatus(SeatStatus::BOOKED);
        }
    }

    // Calculate total price of selected seats
    double calculateTotalPrice(const std::vector<Seat>& selectedSeats) const {
        double total = 0.0;
        for (const Seat& seat : selectedSeats) {
            total += seat.getPrice();
        }
        return total;
    }

    // Generate a unique booking ID
    std::string generateBookingId() {
        long bookingNumber = bookingCounter++;
        auto now = std::chrono::system_clock::now();
        auto timestamp = std::chrono::system_clock::to_time_t(now);
        std::tm* timeInfo = std::localtime(&timestamp);

        std::ostringstream oss;
        oss << BOOKING_ID_PREFIX << (1900 + timeInfo->tm_year) << (1 + timeInfo->tm_mon) << timeInfo->tm_mday
            << timeInfo->tm_hour << timeInfo->tm_min << timeInfo->tm_sec
            << std::setw(6) << std::setfill('0') << bookingNumber;
        return oss.str();
    }

    // Mark seats as available
    void markSeatsAsAvailable(Show& show, const std::vector<Seat>& seats) {
        for (const Seat& seat : seats) {
            auto& showSeat = show.getSeats()[seat.getId()];
            showSeat.setStatus(SeatStatus::AVAILABLE);
        }
    }
};

// Initialize static members
MovieTicketBookingSystem* MovieTicketBookingSystem::instance = nullptr;
const std::string MovieTicketBookingSystem::BOOKING_ID_PREFIX = "BKG";
std::long MovieTicketBookingSystem::bookingCounter(0);
std::mutex MovieTicketBookingSystem::mtx;
