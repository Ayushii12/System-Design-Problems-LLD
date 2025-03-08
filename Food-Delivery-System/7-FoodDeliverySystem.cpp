#include "1-Customer.cpp"
#include "3-Restaurant.cpp"
#include "4-DeliveryAgent.cpp"

class FoodDeliverySystem {
private:
    static FoodDeliverySystem* instance;
    unordered_map<int, Customer> customers;
    unordered_map<int, Restaurant> restaurants;
    unordered_map<int, DeliveryAgent> deliveryAgents;

    // Private constructor for Singleton pattern
    FoodDeliverySystem() {}

public:
    // Get the single instance of the system
    static FoodDeliverySystem* getInstance() {
        if (instance == nullptr) {
            instance = new FoodDeliverySystem();
        }
        return instance;
    }

    // Register a new customer
    void registerCustomer(Customer customer) {
        customers[customer.getId()] = customer;
        cout << "Customer " << customer.getName() << " registered successfully.\n";
    }

    // Register a new restaurant
    void registerRestaurant(Restaurant restaurant) {
        restaurants[restaurant.getId()] = restaurant;
        cout << "Restaurant " << restaurant.getName() << " registered successfully.\n";
    }

    // Register a new delivery agent
    void registerDeliveryAgent(DeliveryAgent agent) {
        deliveryAgents[agent.getId()] = agent;
        cout << "Delivery Agent " << agent.getName() << " registered successfully.\n";
    }

    // Retrieve all available restaurants
    void listRestaurants() {
        if (restaurants.empty()) {
            cout << "No restaurants available.\n";
            return;
        }
        cout << "Available Restaurants:\n";
        for (const auto& pair : restaurants) {
            cout << " - " << pair.second.getName() << "\n";
        }
    }

    // Retrieve menu of a specific restaurant
    void displayRestaurantMenu(int restaurantId) {
        if (restaurants.find(restaurantId) != restaurants.end()) {
            restaurants[restaurantId].displayMenu();
        } else {
            cout << "Restaurant not found.\n";
        }
    }

    // Assign a delivery agent to an order
    void assignDeliveryAgent(int orderId) {
        if (orders.find(orderId) == orders.end()) {
            cout << "Order ID " << orderId << " not found.\n";
            return;
        }
        for (auto& pair : deliveryAgents) {
            DeliveryAgent& agent = pair.second;
            if (agent.isAvailable()) {
                orders[orderId].setStatus(OrderStatus::OutForDelivery);
                agent.setAvailability(false); 
                cout << "Order ID " << orderId << " is assigned to Delivery Agent: " 
                          << agent.getName() << " (" << agent.getPhoneNumber() << ")\n";
                return;
            }
        }
        cout << "No available delivery agents at the moment.\n";
      }
};

// Initialize the Singleton instance to nullptr
FoodDeliverySystem* FoodDeliverySystem::instance = nullptr;
