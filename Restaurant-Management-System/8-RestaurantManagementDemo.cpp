#include "RestaurantManagementSystem.cpp"

class RestaurantManagementDemo {
public:
    static void runDemo() {
        // Step 1: Initialize Restaurant System
        RestaurantManagementSystem* system = RestaurantManagementSystem::getInstance();

        // Step 2: Add Menu Items
        system->addMenuItem(MenuItem(1, "Pasta", 12.99, "Delicious creamy pasta", true, ItemCategory::MAIN_COURSE));
        system->addMenuItem(MenuItem(2, "Cheesecake", 6.99, "Classic New York cheesecake", true, ItemCategory::DESSERT));
        system->addMenuItem(MenuItem(3, "Lemonade", 3.50, "Freshly squeezed lemonade", true, ItemCategory::BEVERAGE));

        // Step 3: Display Menu
        cout << "\nDisplaying Menu:\n";
        system->getMenu();

        // Step 4: Create a Table
        Table table1(1, 4); // Table with 4 seats
        system->addTable(&table1);

        // Step 5: Place an Order
        vector<MenuItem> orderedItems = {system->getMenuItemById(1), system->getMenuItemById(3)};
        Order order = system->placeOrder(&table1, orderedItems);
        cout << "\nOrder placed:\n";
        order.displayOrder();

        // Step 6: Make a Reservation
        Reservation reservation = system->makeReservation(&table1, "John Doe", "123-456-7890", 2, "7:00 PM");
        cout << "\nReservation made for " << reservation.getCustomerName() << " at " << reservation.getReservationTime() << endl;

        // Step 7: Process Payment for the Order
        cout << "\nProcessing Payment...\n";
        system->processPayment(order.getId());

        // Step 8: Update Order Status
        cout << "\nUpdating Order Status to COMPLETED...\n";
        system->updateOrderStatus(order.getId(), OrderStatus::COMPLETED);

        // Step 9: Add a Staff Member
        system->addStaff(Staff(1, "Alice", "Waiter"));
        cout << "\nAdded staff member Alice (Waiter).\n";

        
    }
};

// Run the demo
int main() {
    RestaurantManagementDemo::runDemo();
    return 0;
}
