#include <iostream>
#include <string>

using namespace std;

class Tag {
private:
    int id;
    string name;

public:
    // Constructor
    Tag(int id, const string& name) : id(id), name(name) {}

    // Getters
    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    // Setter
    void setName(const string& newName) {
        name = newName;
    }
};
