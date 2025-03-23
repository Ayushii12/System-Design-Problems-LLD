#include <string>
#include "1a-Role.cpp"
using namespace std;

class User {
private:
    string username;
    string password;
    Role role;
    size_t storageQuota;  // Maximum storage allowed in bytes
    size_t usedStorage;   // Currently used storage in bytes

public:
    User(const string& username, const string& password, Role role)
        : username(username), password(password), role(role) {}

    // Getters
    string getUsername() const { return username; }
    Role getRole() const { return role; }
    size_t getStorageQuota() const { return storageQuota; }
    size_t getUsedStorage() const { return usedStorage; }
    
    // Authentication method
    bool authenticate(const string& password) const {
        return this->password == password;
    }

    // Check if a file of a given size can be uploaded
    bool canUpload(size_t fileSize) const {
        return (usedStorage + fileSize) <= storageQuota;
    }

    // Update the storage after uploading a file
    void addFile(size_t fileSize) {
        if (!canUpload(fileSize)) throw runtime_error("Storage quota exceeded");
        usedStorage += fileSize;
    }

    // Update the storage after deleting a file
    void deleteFile(size_t fileSize) {
        usedStorage -= fileSize;
    }
};
