#include "3a-SeatType.cpp"
#include "3b-SeatStatus.cpp"

class Seat {
private:
    string seatNumber;
    SeatType type;
    SeatStatus status;

public:
    // Constructor
    Seat(const string& seatNumber, SeatType type)
        : seatNumber(seatNumber), type(type), status(SeatStatus::AVAILABLE) {}

    // Getter functions
    string getSeatNumber() const { return seatNumber; }
    SeatType getType() const { return type; }
    SeatStatus getStatus() const { return status; }

    // Function to reserve the seat
    void reserve() {
        status = SeatStatus::RESERVED;
    }

    // Function to release the seat
    void release() {
        status = SeatStatus::AVAILABLE;
    }

    // Function to display seat information
    void displayInfo() const {
        std::cout << "Seat Number: " << seatNumber << "\n";
        std::cout << "Seat Type: " << (type == SeatType::ECONOMY ? "Economy" : 
                                       type == SeatType::PREMIUM_ECONOMY ? "Premium_Economy" : 
                                       type == SeatType::BUSINESS ? "Business": "First Class") << "\n";
        std::cout << "Seat Status: " << (status == SeatStatus::AVAILABLE ? "Available" : "Reserved") << "\n";
    }
};
