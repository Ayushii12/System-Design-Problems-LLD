#include "1-Customer.cpp"
#include "3-Restaurant.cpp"
#include "4-DeliveryAgent.cpp"
#include "5-OrderManager.cpp"
#include "6-PaymentProcessor.cpp"

using namespace std;

class FoodDeliverySystem {
private:
    static FoodDeliverySystem* instance;
    unordered_map<int, Customer> customers;
    unordered_map<int, Restaurant> restaurants;
    vector<DeliveryAgent> deliveryAgents;
    OrderManager* orderManager;
    PaymentProcessor* paymentProcessor;

    // Private constructor for Singleton
    FoodDeliverySystem() {
        orderManager = OrderManager::getInstance();
        paymentProcessor = PaymentProcessor::getInstance();
    }

public:
    static FoodDeliverySystem* getInstance() {
        if (!instance) {
            instance = new FoodDeliverySystem();
        }
        return instance;
    }

    // Register customers
    void registerCustomer(const Customer& customer) {
        customers[customer.getId()] = customer;
    }

    // Register restaurants
    void registerRestaurant(const Restaurant& restaurant) {
        restaurants[restaurant.getId()] = restaurant;
    }

    // Register delivery agents
    void registerDeliveryAgent(const DeliveryAgent& agent) {
        deliveryAgents.push_back(agent);
    }

    // List available restaurants
    void listRestaurants() {
        cout << "Available Restaurants:\n";
        for (const auto& pair : restaurants) {
            cout << "ID: " << pair.first << " | Name: " << pair.second.getName() << endl;
        }
    }

    // Display menu for a given restaurant
    void displayRestaurantMenu(int restaurantId) {
        if (restaurants.find(restaurantId) == restaurants.end()) {
            cout << "Restaurant not found!" << endl;
            return;
        }
        restaurants[restaurantId].displayMenu();
    }

    // Assign a delivery agent
    void assignDeliveryAgent(int orderId) {
        for (auto& agent : deliveryAgents) {
            if (agent.isAvailable()) {
                cout << "Order ID: " << orderId << " assigned to Delivery Agent: " << agent.getName() << endl;
                agent.setAvailability(false); // Mark agent as unavailable
                return;
            }
        }
        cout << "No available delivery agents at the moment." << endl;
    }

    // Process order payment
    void processOrderPayment(int orderId, double amount) {
        cout << "Processing payment for Order ID: " << orderId << endl;
        paymentProcessor->createPayment(orderId, amount);
        Payment payment = paymentProcessor->processPayment(orderId, amount);
        if (payment.getStatus() == PaymentStatus::COMPLETED) {
            cout << "Payment successful for Order ID: " << orderId << endl;
        } else {
            cout << "Payment failed for Order ID: " << orderId << endl;
        }
    }

    // Simulate marking an order as delivered
    void markOrderDelivered(int orderId) {
        cout << "Order ID: " << orderId << " has been delivered successfully!" << endl;
    }
};

// Initialize Singleton instance
FoodDeliverySystem* FoodDeliverySystem::instance = nullptr;
