class Aircraft {
private:
    string tailNumber;
    string model;
    int totalSeats;

public:
    // Constructor
    Aircraft(const string& tailNumber, const string& model, int totalSeats)
        : tailNumber(tailNumber), model(model), totalSeats(totalSeats) {}

    // Getter functions
    string getTailNumber() const { return tailNumber; }
    string getModel() const { return model; }
    int getTotalSeats() const { return totalSeats; }
};
