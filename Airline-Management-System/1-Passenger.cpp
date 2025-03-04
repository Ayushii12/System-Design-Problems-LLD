class Passenger {
private:
    string id;
    string name;
    string email;
    string phone_number;

public:
    // Constructor
    Passenger(const string& passenger_id, const string& passenger_name, 
             const string& passenger_email, const string& passenger_phone)
        : id(passenger_id), name(passenger_name), email(passenger_email), phone_number(passenger_phone) {}

    // Getters
    string getId() const { return id; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getPhoneNumber() const { return phone_number; }

    // Display function
    void display() const {
        cout << "Passenger ID: " << id << "\nName: " << name 
             << "\nEmail: " << email << "\nPhone: " << phone_number << endl;
    }
};
