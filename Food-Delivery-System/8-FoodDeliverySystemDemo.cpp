#include "1-Customer.cpp"
#include "3-Restaurant.cpp"
#include "4-DeliveryAgent.cpp"
#include "5-OrderManager.cpp"
#include "5b-Order.cpp"
#include "7-FoodDeliverySystem.cpp"

int main() {
    // Get the singleton instance of the FoodDeliverySystem
    FoodDeliverySystem* system = FoodDeliverySystem::getInstance();

    // Register Customers
    Customer customer1(1, "Alice", "1234567890", "123 Main St");
    system->registerCustomer(customer1);

    // Register Restaurants
    Restaurant restaurant1(1, "Pizza Palace");
    restaurant1.addMenuItem(MenuItem(101, "Margherita Pizza", 10.99));
    restaurant1.addMenuItem(MenuItem(102, "Pepperoni Pizza", 12.99));
    system->registerRestaurant(restaurant1);

    // Register Delivery Agents
    DeliveryAgent agent1(1, "John Doe", "9876543210", true, "Downtown");
    system->registerDeliveryAgent(agent1);

    // Display available restaurants
    cout << "\n--- List of Available Restaurants ---\n";
    system->listRestaurants();

    // Display menu of a selected restaurant
    cout << "\n--- Menu for Restaurant: Pizza Palace ---\n";
    system->displayRestaurantMenu(1);

    // Create an order for the customer
    vector<MenuItem> orderedItems = { MenuItem(101, "Margherita Pizza", 10.99) };
    Order new_order = OrderManager::getInstance()->createOrder(1, 1, orderedItems); 

    // Process payment for the order
    system->processOrderPayment(new_order.getId(), new_order.getTotalAmount());

    // Assign a delivery agent
    system->assignDeliveryAgent(orderId);

    // Mark order as delivered (Simulation)
    system->markOrderDelivered(orderId);

    return 0;
}

