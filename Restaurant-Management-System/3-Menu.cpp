#include "3a-ItemCategory.cpp"
#include "3b-MenuItem.cpp"

class Menu {
private:
    vector<MenuItem> items;

public:
    // Add Item
    void addItem(const MenuItem& item) { items.push_back(item); }

    // Display Menu
    void displayMenu() const {
        std::cout << "\n--- Restaurant Menu ---" << std::endl;
        for (const auto& item : items) {
            item.displayItem();
            std::cout << "----------------------" << std::endl;
        }
    }
};
