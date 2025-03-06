#include "1-Staff.cpp"
#include "2-Table.cpp"
#include "3b-MenuItem.cpp"
#include "3-Menu.cpp"
#include "4a-OrderStatus.cpp"
#include "4b-Order.cpp"
#include "4-OrderManager.cpp"
#include "5a-ReservationStatus.cpp"
#include "5b-Reservation.cpp"
#include "5-ReservationManager.cpp"
#include "6a-PaymentStatus.cpp"
#include "6b-Payment.cpp"
#include "6-PaymentProcessor.cpp"
#include <iostream>
#include <vector>
using namespace std;

class RestaurantManagementSystem {
private:
    static RestaurantManagementSystem* instance;
    vector<Table> tables;
    Menu menu;
    vector<Staff> staff;
    OrderManager* orderManager;
    ReservationManager* reservationManager;
    PaymentProcessor* paymentProcessor;

    // Private constructor
    RestaurantManagementSystem() {
        orderManager = OrderManager::getInstance();
        reservationManager = ReservationManager::getInstance();
        paymentProcessor = PaymentProcessor::getInstance();
    }

public:
    static RestaurantManagementSystem* getInstance() {
        if (!instance) {
            instance = new RestaurantManagementSystem();
        }
        return instance;
    }

    // Add Table
    void addTable(const Table& table) { tables.push_back(table); }

    // Add Menu Item
    void addMenuItem(const MenuItem& item) { menu.addItem(item); }

    // Display Menu
    void displayMenu() const { menu.displayMenu(); }

    // Add Staff Member
    void addStaff(const Staff& staffMember) { staff.push_back(staffMember); }

    // Place an Order
    Order placeOrder(Table* table, const vector<MenuItem>& items) {
        return orderManager->createOrder(table, items);
    }

    // Cancel an Order
    void cancelOrder(int orderId) { orderManager->cancelOrder(orderId); }

    // Make a Reservation
    Reservation makeReservation(Table* table, const string& customerName, const string& contactInfo, int partySize, const string& reservationTime) {
        return reservationManager->createReservation(table, customerName, contactInfo, partySize, reservationTime);
    }

    // Cancel a Reservation
    void cancelReservation(int reservationId) { reservationManager->cancelReservation(reservationId); }

    // Process Payment
    void processPayment(int orderId) {
        Order* order = getOrderById(orderId);
        if (order == nullptr) {
            cout << "Invalid Order ID. Payment cannot be processed." << endl;
            return;
        }
        double amount = order->getTotalAmount();
        // Create a payment record first
        Payment payment(orderId, amount, PaymentStatus::PENDING);
        paymentProcessor->addPayment(payment);
        // Now process it
        paymentProcessor->processPayment(orderId);
    }
};

// Initialize static instance
RestaurantManagementSystem* RestaurantManagementSystem::instance = nullptr;
