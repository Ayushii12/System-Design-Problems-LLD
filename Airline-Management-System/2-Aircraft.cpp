class Aircraft {
private:
    string tailNumber;
    string model;
    int totalSeats;

public:
    // Constructor
    Aircraft(const std::string& tailNumber, const std::string& model, int totalSeats)
        : tailNumber(tailNumber), model(model), totalSeats(totalSeats) {}

    // Getter functions
    std::string getTailNumber() const {
        return tailNumber;
    }

    std::string getModel() const {
        return model;
    }

    int getTotalSeats() const {
        return totalSeats;
    }

    // Function to display aircraft information
    void displayInfo() const {
        cout << "Aircraft Information:\n";
        cout << "Tail Number: " << tailNumber << "\n";
        cout << "Model: " << model << "\n";
        cout << "Total Seats: " << totalSeats << "\n";
    }
};
