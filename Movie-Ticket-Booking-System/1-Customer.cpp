class Customer {
private:
    string id;
    string name;
    string email;
    string phone_number;

public:
    // Constructor
    Customer(const string& customer_id, const string& customer_name, 
             const string& customer_email, const string& customer_phone)
        : id(customer_id), name(customer_name), email(customer_email), phone_number(customer_phone) {}

    // Getters
    string getId() const { return id; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getPhoneNumber() const { return phone_number; }

    // Display function (Optional)
    void display() const {
        cout << "Customer ID: " << id << "\nName: " << name 
             << "\nEmail: " << email << "\nPhone: " << phone_number << endl;
    }
};
