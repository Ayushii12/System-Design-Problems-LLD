#include "1-Customer.cpp"
#include "3-Restaurant.cpp"
#include "4-DeliveryAgent.cpp"
#include "5-OrderManager.cpp"
#include "5b-Order.cpp"
#include "7-FoodDeliverySystem.cpp"

int main() {
    // Get the instance of the food delivery system (Singleton)
    FoodDeliverySystem* system = FoodDeliverySystem::getInstance();
    
    // Register customers
    Customer customer1(1, "Alice", "1234567890", "123 Main St");
    system->registerCustomer(customer1);

    Customer customer2(2, "Bob", "9876543210", "456 Elm St");
    system->registerCustomer(customer2);

    // Register restaurants
    Restaurant restaurant1(1, "Pasta Palace");
    Restaurant restaurant2(2, "Burger Haven");

    // Add menu items
    restaurant1.addMenuItem(MenuItem(101, "Spaghetti", 10.99));
    restaurant1.addMenuItem(MenuItem(102, "Lasagna", 12.99));
    
    restaurant2.addMenuItem(MenuItem(201, "Cheeseburger", 8.99));
    restaurant2.addMenuItem(MenuItem(202, "Fries", 3.99));

    // Register restaurants in system
    system->registerRestaurant(restaurant1);
    system->registerRestaurant(restaurant2);

    // List available restaurants
    system->listRestaurants();

    // Display menu for a restaurant
    system->displayRestaurantMenu(1); 

    // Register delivery agents
    DeliveryAgent agent1(1, "John Doe", "555-1111", true, "Downtown");
    DeliveryAgent agent2(2, "Jane Smith", "555-2222", true, "Uptown");

    system->registerDeliveryAgent(agent1);
    system->registerDeliveryAgent(agent2);

    // Create an order
    OrderManager* orderManager = OrderManager::getInstance();
    vector<MenuItem> orderItems = { MenuItem(101, "Spaghetti", 10.99), MenuItem(102, "Lasagna", 12.99) };
    int orderId = orderManager->createOrder(customer1, restaurant1, orderItems);

    // Assign a delivery agent
    system->assignDeliveryAgent(orderId);

    // Simulate order delivery
    system->markOrderDelivered(orderId);

    return 0;
}
