#include "5a-OrderStatus.cpp"
#include "2b-MenuItem.cpp"

class Order {
private:
    int id;
    Table* table;
    vector<MenuItem> items;
    double totalAmount;
    OrderStatus status;

public:
    // Constructor
    Order(int id, Table* table, const vector<MenuItem>& items)
        : id(id), table(table), items(items), status(OrderStatus::PENDING) {
        calculateTotal();
    }

    // Calculate total amount
    void calculateTotal() {
        totalAmount = 0.0;
        for (const auto& item : items) {
            totalAmount += item.getPrice();
        }
    }

    // Getters
    int getId() const { return id; }
    double getTotalAmount() const { return totalAmount; }
    OrderStatus getStatus() const { return status; }

    // Set Order Status
    void setStatus(OrderStatus newStatus) { status = newStatus; }

    // Display Order Details
    void displayOrder() const {
        std::cout << "Order ID: " << id << " | Table No: " << table->getTableNo()
                  << " | Total: $" << totalAmount << " | Status: "
                  << (status == OrderStatus::PENDING ? "Pending" :
                      status == OrderStatus::PREPARING ? "Preparing" :
                      status == OrderStatus::READY ? "Ready" :
                      status == OrderStatus::COMPLETED ? "Completed" : "Cancelled")
                  << std::endl;
    }
};
