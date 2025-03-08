#include "5a-OrderStatus.cpp"
#include "2b-MenuItem.cpp"
#include "1-Customer.cpp"
#include "3-Restaurant.cpp"

class Order {
private:
    int orderId;
    Customer customer;
    Restaurant restaurant;
    vector<MenuItem> items;
    double totalAmount;
    OrderStatus orderStatus;

public:
    Order(int id, Customer cust, Restaurant rest)
        : orderId(id), customer(cust), restaurant(rest), totalAmount(0.0), orderStatus(OrderStatus::Pending) {}

    void addItem(MenuItem item) {
        items.push_back(item);
        totalAmount += item.getPrice(); 
    }

    void setStatus(OrderStatus status) { orderStatus = status; }

    int getOrderId() const { return orderId; }
    OrderStatus getOrderStatus() const { return orderStatus; }
    double getTotalAmount() const { return totalAmount; }

    void displayOrder() {
        cout << "Order ID: " << orderId << "\n";
        cout << "Customer: " << customer.getName() << "\n";  
        cout << "Restaurant: " << restaurant.getName() << "\n";
        cout << "Items Ordered:\n";
        for (const auto& item : items) {
            item.displayItem();  
        }
        cout << "Total Amount: $" << totalAmount << "\n";
        cout << "Order Status: " << OrderStatus::statusToString(orderStatus) << "\n";
    }
};
