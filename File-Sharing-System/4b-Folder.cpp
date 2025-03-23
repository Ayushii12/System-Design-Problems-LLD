#include <iostream>
#include <string>
#include <unordered_map>
#include "2-Permissions.cpp"
#include "4-FileSystemComponent.cpp"
using namespace std;

class Folder : public FileSystemComponent {
private:
    unordered_map<string, FileSystemComponent*> children;
    Permissions permissions;

public:
    Folder(const string &name)
        : FileSystemComponent(name), children(), permissions() {}

    // Clean up allocated children
    ~Folder() {
        for (auto &pair : children) {
            delete pair.second;
        }
    }

    // Getters
    string getName() const override { return name; }
    unordered_map<string, FileSystemComponent*>& getChildren() { return children; }
    Permissions& getPermissions() { return permissions; }

    // Setters
    void setName(const string &newName) override { name = newName; }

    // Add a component 
    void add(FileSystemComponent* component) override {
        children[component->getName()] = component;
    }

    // Remove a component 
    void remove(FileSystemComponent* component) override {
        children.erase(component->getName());
    }

    // Retrieve a child component by name
    FileSystemComponent* getChild(const string &childName) override {
        auto it = children.find(childName);
        if (it != children.end()) {
            return it->second;
        }
        return nullptr;
    }

    // Display the content of the folder
    void display(const string &indent) const override {
        cout << indent << "Folder: " << name << endl;
        for (const auto &pair : children) {
            pair.second->display(indent + "    ");
        }
    }
};
