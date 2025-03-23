#include <string>
#include "1a-Role.cpp"
using namespace std;

class User {
private:
    string username;
    string password;
    Role role;

public:
    User(const string& username, const string& password, Role role)
        : username(username), password(password), role(role) {}

    // Getters
    string getUsername() const { return username; }
    Role getRole() const { return role; }
    
    // Authentication method
    bool authenticate(const string& password) const {
        return this->password == password;
    }
};
