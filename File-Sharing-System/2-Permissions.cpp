#include <unordered_map>
#include "1-User.cpp"          
#include "2a-PermissionType.cpp"
using namespace std;

class Permissions {
private:
    unordered_map<User*, PermissionType> userPermissions;

public:
    // Constructor 
    Permissions() : userPermissions() {}

    // Set permission for a user
    void setPermission(User* user, PermissionType permissionType) {
        userPermissions[user] = permissionType;
    }

    // Get permission for a user
    PermissionType getPermission(User* user) const {
        auto it = userPermissions.find(user);
        if (it != userPermissions.end()) {
            return it->second;
        }
        return NONE;
    }
};
