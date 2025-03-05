class Staff {
private:
    int id;
    string name;
    string role;

public:
    // Constructor
    Staff(int id, const string& name, const string& role)
        : id(id), name(name), role(role) {}

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    string getRole() const { return role; }

    // Setters
    void setName(const string& newName) { name = newName; }
    void setRole(const string& newRole) { role = newRole; }
};
