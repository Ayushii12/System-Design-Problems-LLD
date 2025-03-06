#include "5b-Reservation.cpp"

class ReservationManager {
private:
    static ReservationManager* instance;
    int nextReservationId;
    vector<Reservation> reservations;

    // Private constructor
    ReservationManager() : nextReservationId(1) {}

public:
    static ReservationManager* getInstance() {
        if (!instance) {
            instance = new ReservationManager();
        }
        return instance;
    }

    // Check if the table is available
    bool isTableAvailable(Table* table, const string& reservationTime) {
        for (const auto& reservation : reservations) {
            if (reservation.getTable() == table && reservation.getReservationTime() == reservationTime && reservation.getStatus() != ReservationStatus::CANCELLED) {
                return false;  // Table is already reserved at the same time
            }
        }
        return true;  // Table is available
    }

    // Create Reservation with table availability check
    Reservation createReservation(Table* table, const string& customerName, const string& contactInfo, int partySize, const string& reservationTime) {
        if (!isTableAvailable(table, reservationTime)) {
            cout << "Sorry, the table is already reserved at that time." << endl;
        }
        Reservation newReservation(nextReservationId++, table, customerName, contactInfo, partySize, reservationTime);
        reservations.push_back(newReservation);
        return newReservation;
    }

    // Cancel Reservation
    void cancelReservation(int reservationId) {
        for (auto& reservation : reservations) {
            if (reservation.getId() == reservationId) {
                reservation.setStatus(ReservationStatus::CANCELLED);
                cout << "Reservation " << reservationId << " has been cancelled." << std::endl;
                return;
            }
        }
        cout << "Reservation not found." << std::endl;
    }
};

// Initialize static instance
ReservationManager* ReservationManager::instance = nullptr;
