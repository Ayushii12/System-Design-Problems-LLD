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

    // To reserve the seat
    void reserve() {
        status = SeatStatus::RESERVED;
    }

    // To release the seat
    void release() {
        status = SeatStatus::AVAILABLE;
    }
};
