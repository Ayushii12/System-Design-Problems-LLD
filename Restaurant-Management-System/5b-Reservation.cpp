#include "5a-ReservationStatus.cpp"
#include "2-Table.cpp"

class Reservation {
private:
    int id;
    Table* table;
    string customerName;
    string contactInfo;
    int partySize;
    string reservationTime;
    ReservationStatus status;

public:
    // Constructor
    Reservation(int id, Table* table, const string& customerName, const string& contactInfo, int partySize, const string& reservationTime)
        : id(id), table(table), customerName(customerName), contactInfo(contactInfo), partySize(partySize), reservationTime(reservationTime), status(ReservationStatus::CONFIRMED) {}

    // Getters
    int getId() const { return id; }
    string getCustomerName() const { return customerName; }
    string getContactInfo() const { return contactInfo; }
    int getPartySize() const { return partySize; }
    string getReservationTime() const { return reservationTime; }
    ReservationStatus getStatus() const { return status; }

    // Set Status
    void setStatus(ReservationStatus newStatus) { status = newStatus; }
};
