using namespace std;

class Customer {
private:
    int id;
    string name;
    string email;
    string phoneNumber;

public:
    Customer(int id, string name, string email, string phoneNumber)
        : id(id), name(name), email(email), phoneNumber(phoneNumber) {}
    
    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getPhoneNumber() const { return phoneNumber; }
    
    // Setters
    void setName(const string& newName) { name = newName; }
    void setEmail(const string& newEmail) { email = newEmail; }
    void setPhoneNumber(const string& newPhone) { phoneNumber = newPhone; }
};
