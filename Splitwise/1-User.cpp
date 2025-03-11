#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class User {
private:
    int id;
    string name;
    string email;
    unordered_map<int, double> balances;  // Balances with other users {Key: other user's ID, Value: balance amount}

public:
    // Constructor 
    User(int id, const string &name, const string &email)
        : id(id), name(name), email(email) {}

    // Getter methods
    int getId() const { return id; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    const unordered_map<int, double>& getBalances() const { return balances; }

    // Setter methods
    void setName(const string &newName) { name = newName; }
    void setEmail(const string &newEmail) { email = newEmail; }

    // Updates the balance with other user
    // Positive amount means otherUserId owes money to this user
    // Negative amount means this user owes money to otherUSerId
    void updateBalance(int otherUserId, double amount) {
        balances[otherUserId] += amount;
    }
};
