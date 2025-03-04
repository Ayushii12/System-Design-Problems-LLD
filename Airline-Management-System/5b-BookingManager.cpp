#include <mutex>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <atomic>
#include "1-Passenger.cpp"
#include "4-Flight.cpp"
#include "5-Booking.cpp"

class BookingManager {
private:
    static BookingManager* instance;
    static mutex instanceMutex;
    unordered_map<string, Booking> bookings;
    atomic<int> bookingCounter;

    // Private constructor for Singleton
    BookingManager() : bookingCounter(0) {}

public:
    // Get the singleton instance (thread-safe)
    static BookingManager* getInstance() {
        lock_guard<mutex> lock(instanceMutex);
        if (instance == nullptr) {
            instance = new BookingManager();
        }
        return instance;
    }

    // Create a new booking
    Booking createBooking(const Flight& flight, const Passenger& passenger, const Seat& seat, double price) {
        string bookingNumber = generateBookingNumber();
        Booking booking(bookingNumber, flight, passenger, seat, price);
        bookings[bookingNumber] = booking;
        return booking;
    }

    // Cancel a booking
    void cancelBooking(const string& bookingNumber) {
        if (bookings.find(bookingNumber) != bookings.end()) {
            bookings[bookingNumber].cancel();
        }
    }

private:
    // Generate a unique booking number with timestamp
    string generateBookingNumber() {
        int bookingId = bookingCounter.fetch_add(1) + 1;

        // Get current time
        time_t now = std::time(nullptr);
        tm* localTime = std::localtime(&now);

        // Format timestamp as "yyyyMMddHHmmss"
        ostringstream oss;
        oss << "BKG" 
            << (localTime->tm_year + 1900) 
            << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1)
            << std::setw(2) << std::setfill('0') << localTime->tm_mday
            << std::setw(2) << std::setfill('0') << localTime->tm_hour
            << std::setw(2) << std::setfill('0') << localTime->tm_min
            << std::setw(2) << std::setfill('0') << localTime->tm_sec
            << std::setw(6) << std::setfill('0') << bookingId;

        return oss.str();
    }
};

// Initialize static variables
BookingManager* BookingManager::instance = nullptr;
mutex BookingManager::instanceMutex;
