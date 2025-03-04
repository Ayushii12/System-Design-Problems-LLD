#include <iostream>
#include <string>
#include <vector>
#include "Show.cpp"    
#include "Seat.cpp"    
#include "Customer.cpp"    
#include "BookingStatus.cpp" 


class Booking {
private:
    std::string id;
    Customer customer;
    Show show;
    std::vector<Seat> selected_seats; 
    double totalPrice;
    BookingStatus status;    

public:
    // Constructor
    Booking(const std::string& booking_id, const Customer& booking_user, const Show& booking_show, 
            const std::vector<Seat>& booking_seats, double booking_totalPrice, BookingStatus booking_status)
        : id(booking_id), customer(booking_user), show(booking_show), selected_seats(booking_seats), 
          totalPrice(booking_totalPrice), status(booking_status) {}

    // Set the booking status
    void setStatus(BookingStatus newStatus) {
        status = newStatus;
    }

    // Getters
    std::string getId() const { return id; }
    Customer getUser() const { return customer; }
    Show getShow() const { return show; }
    std::vector<Seat> getSeats() const { return selected_seats; }
    double getTotalPrice() const { return totalPrice; }
    BookingStatus getStatus() const { return status; }
};
