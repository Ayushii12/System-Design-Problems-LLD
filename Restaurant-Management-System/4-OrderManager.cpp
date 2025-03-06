#include "2-Table.cpp"
#include "4b-Order.cpp"

class OrderManager {
private:
    static OrderManager* instance;
    int nextOrderId;
    vector<Order> orders;

    // Private constructor
    OrderManager() : nextOrderId(1) {}

public:
    static OrderManager* getInstance() {
        if (!instance) {
            instance = new OrderManager();
        }
        return instance;
    }

    // Create Order
    Order createOrder(Table* table, const vector<MenuItem>& items) {
        Order newOrder(nextOrderId++, table, items);
        orders.push_back(newOrder);
        return newOrder;
    }

    // Cancel Order
    void cancelOrder(int orderId) {
        for (auto& order : orders) {
            if (order.getId() == orderId) {
                order.setStatus(OrderStatus::CANCELLED);
                cout << "Order " << orderId << " has been cancelled." << std::endl;
                return;
            }
        }
        cout << "Order not found." << std::endl;
    }
};

// Initialize static instance
OrderManager* OrderManager::instance = nullptr;
