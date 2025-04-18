#include "3a-ItemCategory.cpp"

class MenuItem {
private:
    int id;
    string name;
    double price;
    string description;
    bool availability;
    ItemCategory category;

public:
    // Constructor
    MenuItem(int id, const string& name, double price, const string& description, bool availability, ItemCategory category)
        : id(id), name(name), price(price), description(description), availability(availability), category(category) {}

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    string getDescription() const { return description; }
    bool isAvailable() const { return availability; }
    ItemCategory getCategory() const { return category; }

    // Set Availability
    void setAvailability(bool status) { availability = status; }

    // Display Item details
    void displayItem() const {
        std::cout << "ID: " << id << " | Name: " << name << " | Price: $" << price
                  << " | Category: " << (category == ItemCategory::APPETIZER ? "Appetizer" :
                                          category == ItemCategory::MAIN_COURSE ? "Main Course" :
                                          category == ItemCategory::DESSERT ? "Dessert" : "Beverage")
                  << " | " << (availability ? "Available" : "Not Available")
                  << "\nDescription: " << description << std::endl;
    }
};
