class Seat {
private:
    string id;
    int row;
    int column;
    SeatType type;
    SeatStatus status;
    double price;

public:
    // Constructor
    Seat(const string& seat_id, int seat_row, int seat_column, 
         SeatType seat_type, SeatStatus seat_status, double seat_price)
        : id(seat_id), row(seat_row), column(seat_column), 
          type(seat_type), status(seat_status), price(seat_price) {}

    // Setter for status
    void setStatus(SeatStatus seat_status) { status = seat_status; }

    // Getters
    string getId() const { return id; }
    int getRow() const { return row; }
    int getColumn() const { return column; }
    SeatType getType() const { return type; }
    double getPrice() const { return price; }
    SeatStatus getStatus() const { return status; }

    // Display function
    void display() const {
        cout << "Seat ID: " << id << "\nRow: " << row << " Column: " << column
             << "\nPrice: $" << price << "\nStatus: " 
             << (status == SeatStatus::AVAILABLE ? "Available" : 
                 status == SeatStatus::BOOKED ? "Booked" : "Reserved") << endl;
    }
};
