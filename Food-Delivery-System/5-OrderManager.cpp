#include "5b-Order.cpp"

class OrderManager {
private:
    static OrderManager* instance;
    int currentOrderId;
    sunordered_map<int, Order> orders;

    // Private constructor to enforce Singleton pattern
    OrderManager() : currentOrderId(0) {}

public:
    static OrderManager* getInstance() {
        if (instance == nullptr) {
            instance = new OrderManager();
        }
        return instance;
    }

    int generateOrderId() {
        return ++currentOrderId;
    }

    Order createOrder(Customer customer, Restaurant restaurant) {
        int orderId = generateOrderId();
        Order newOrder(orderId, customer, restaurant);
        orders[orderId] = newOrder;
        cout << "Order created with ID: " << orderId << "\n";
        return newOrder;
    }

    void cancelOrder(int orderId) {
        if (orders.find(orderId) != orders.end()) {
            orders[orderId].setStatus(OrderStatus::Cancelled);
            cout << "Order with ID " << orderId << " has been cancelled.\n";
        } else {
            cout << "Order with ID " << orderId << " not found.\n";
        }
    }

    void displayOrder(int orderId) {
        if (orders.find(orderId) != orders.end()) {
            orders[orderId].displayOrder();
        } else {
            cout << "Order with ID " << orderId << " not found.\n";
        }
    }
};

// Initialize the static instance to nullptr
OrderManager* OrderManager::instance = nullptr;
