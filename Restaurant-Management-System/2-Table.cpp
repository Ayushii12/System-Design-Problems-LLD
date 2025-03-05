#include "2a-TableStatus.cpp"

class Table {
private:
    int tableNo;
    int capacity;
    TableStatus status;

public:
    // Constructor
    Table(int tableNo, int capacity, TableStatus status)
        : tableNo(tableNo), capacity(capacity), status(status) {}

    // Getters
    int getTableNo() const { return tableNo; }
    int getCapacity() const { return capacity; }
    TableStatus getStatus() const { return status; }

    // Setters
    void setStatus(TableStatus newStatus) { status = newStatus; }
};
