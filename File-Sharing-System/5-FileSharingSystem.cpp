#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <iostream>
using namespace std;

class FileSharingSystem {
private:
    static FileSharingSystem* instance;
    unordered_map<User*, Folder*> userRoots;  // Map each registered user to their root folder (their file hierarchy)
    FileSharingSystem() {}

public:
    // Get the singleton instance
    static FileSharingSystem* getInstance() {
        if (instance == nullptr) {
            instance = new FileSharingSystem();
        }
        return instance;
    }

    // Register a new user by creating their root folder
    void registerUser(User* user) {
        if (userRoots.find(user) == userRoots.end()) {
            Folder* root = new Folder(user->getUsername() + "_root");
            userRoots[user] = root;
        }
    }

    // Retrieve a user's root folder
    Folder* getUserRoot(User* user) {
        if (userRoots.find(user) == userRoots.end())
            throw runtime_error("User not registered");
        return userRoots[user];
    }

    // Add a file for a user in the specified folder path (folderPath is relative to the user's root) 
    void addFile(User* user, const string& folderPath, const string& fileName, size_t fileSize) {
        Folder* root = getUserRoot(user);
        vector<string> segments = splitPath(folderPath);
        Folder* targetFolder = root;
        if (!segments.empty()) {
            FileSystemComponent* comp = findComponent(root, segments, 0);
            if (!comp)
                throw runtime_error("Folder path not found");
            targetFolder = dynamic_cast<Folder*>(comp);
            if (!targetFolder)
                throw runtime_error("Path is not a folder");
        }
        // Check storage quota.
        if (!user->canUpload(fileSize))
            throw runtime_error("Storage quota exceeded");
        File* newFile = new File(fileName);
        user->addFile(fileSize);
        targetFolder->add(newFile);
    }

    // Recursive helper to find a component by 'path segments'
    FileSystemComponent* findComponent(Folder* current, const vector<string>& segments, size_t index) {
        if (index >= segments.size()) return current;
        FileSystemComponent* child = current->getChild(segments[index]);
        if (!child) return nullptr;
        if (index == segments.size() - 1) return child;
        Folder* childFolder = dynamic_cast<Folder*>(child);
        if (!childFolder) return nullptr;   // Only folders have children.
        return findComponent(childFolder, segments, index + 1);
    }

    // Add a folder for a user at the specified folder path
    void addFolder(User* user, const string& folderPath, const string& folderName) {
        Folder* root = getUserRoot(user);
        vector<string> segments = splitPath(folderPath);
        Folder* targetFolder = root;
        if (!segments.empty()) {
            FileSystemComponent* comp = findComponent(root, segments, 0);
            if (!comp) throw runtime_error("Folder path not found");
            targetFolder = dynamic_cast<Folder*>(comp);
            if (!targetFolder) throw runtime_error("Path is not a folder");
        }
        Folder* newFolder = new Folder(folderName);
        targetFolder->add(newFolder);
    }

    // Rename a file or folder given its full path
    void renameComponent(User* user, const string& path, const string& newName) {
        Folder* root = getUserRoot(user);
        vector<string> segments = splitPath(path);
        if (segments.empty())
            throw runtime_error("Invalid path");
        FileSystemComponent* comp = findComponent(root, segments, 0);
        if (!comp)
            throw runtime_error("Component not found");
        comp->setName(newName);
    }

    // Delete a file or folder from the user's hierarchy.
    // If a file is deleted, fileSize must be provided to update storage usage
    void deleteComponent(User* user, const string& path, size_t fileSize = 0) {
        Folder* root = getUserRoot(user);
        vector<string> segments = splitPath(path);
        if (segments.empty()) throw runtime_error("Invalid path");
        // Get the parent folder and the name of the component to delete.
        string compName = segments.back();
        segments.pop_back();
        Folder* parent = root;
        if (!segments.empty()) {
            FileSystemComponent* comp = findComponent(root, segments, 0);
            if (!comp) throw runtime_error("Parent folder not found");
            parent = dynamic_cast<Folder*>(comp);
            if (!parent) throw runtime_error("Parent is not a folder");
        }
        FileSystemComponent* compToDelete = parent->getChild(compName);
        if (!compToDelete) throw runtime_error("Component not found");
        // If it's a file, update storage usage.
        File* filePtr = dynamic_cast<File*>(compToDelete);
        if (filePtr) {
            user->deleteFile(fileSize);
        }
        parent->remove(compToDelete);
        delete compToDelete;
    }

    // Update permissions for a file or folder 
    void updatePermissions(User* user, const string& path, User* targetUser, PermissionType newPermission) {
        Folder* root = getUserRoot(user);
        vector<string> segments = splitPath(path);
        FileSystemComponent* comp = findComponent(root, segments, 0);
        if (!comp)
            throw runtime_error("Component not found");
        // Both File and Folder support permissions.
        Folder* folderPtr = dynamic_cast<Folder*>(comp);
        if (folderPtr) {
            folderPtr->getPermissions().setPermission(targetUser, newPermission);
            return;
        }
        File* filePtr = dynamic_cast<File*>(comp);
        if (filePtr) {
            filePtr->getPermissions().setPermission(targetUser, newPermission);
            return;
        }
        throw runtime_error("Component does not support permissions update");
    }

    // Update file content (which creates a new version) and adjust storage usage
    // fileSizeDiff is the difference in size (positive if increased, negative if decreased)
    void updateFileContent(User* user, const string& filePath, const string& newContent, int fileSizeDiff) {
        Folder* root = getUserRoot(user);
        vector<string> segments = splitPath(filePath);
        FileSystemComponent* comp = findComponent(root, segments, 0);
        if (!comp)
            throw runtime_error("File not found");
        File* filePtr = dynamic_cast<File*>(comp);
        if (!filePtr)
            throw runtime_error("Not a file");
        filePtr->writeContent(newContent);
        if (fileSizeDiff > 0) {
            if (!user->canUpload(fileSizeDiff))
                throw runtime_error("Storage quota exceeded");
            user->addFile(fileSizeDiff);
        } else if (fileSizeDiff < 0) {
            user->deleteFile(static_cast<size_t>(-fileSizeDiff));
        }
    }

    // Recursive helper for searching components by name
    void searchRecursive(FileSystemComponent* comp, const string& name, vector<FileSystemComponent*>& results) {
        if (comp->getName().find(name) != string::npos) results.push_back(comp);
        Folder* folderPtr = dynamic_cast<Folder*>(comp);
        if (folderPtr) {
            unordered_map<string, FileSystemComponent*>& children = folderPtr->getChildren();
            for (auto &pair : children) {
                searchRecursive(pair.second, name, results);
            }
        }
    }

    // Search for files and folders by name within a user's hierarchy
    vector<FileSystemComponent*> search(User* user, const string& name) {
        vector<FileSystemComponent*> results;
        Folder* root = getUserRoot(user);
        searchRecursive(root, name, results);
        return results;
    }
};

// Initialize the singleton instance pointer
FileSharingSystem* FileSharingSystem::instance = nullptr;
