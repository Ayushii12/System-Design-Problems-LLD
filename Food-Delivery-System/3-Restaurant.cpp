#include "2a-ItemCategory.cpp"
#include "2b-MenuItem.cpp"
#include "2-menu.cpp"
using namespace std;

class Restaurant {
private:
    int id;
    string name;
    string address;
    string description;
    Menu menu;

public:
    Restaurant(int id, string name, string address, string description)
        : id(id), name(name), address(address), description(description) {}
    
    void addMenuItem(const MenuItem& item) {
        menu.addItem(item);
    }
    
    void displayMenu() const {
        menu.displayMenu();
    }
};
