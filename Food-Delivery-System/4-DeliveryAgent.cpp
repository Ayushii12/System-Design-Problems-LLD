class DeliveryAgent {
private:
    int id;
    string name;
    string phoneNumber;
    bool availability;
    string location;

public:
    DeliveryAgent(int id, string name, string phoneNumber, bool availability, string location)
        : id(id), name(name), phoneNumber(phoneNumber), availability(availability), location(location) {}
    
    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    string getPhoneNumber() const { return phoneNumber; }
    bool isAvailable() const { return availability; }
    string getLocation() const { return location; }
    
    // Setters
    void setName(const string& newName) { name = newName; }
    void setPhoneNumber(const string& newPhone) { phoneNumber = newPhone; }
    void setAvailability(bool status) { availability = status; }
    void setLocation(const string& newLocation) { location = newLocation; }
};
