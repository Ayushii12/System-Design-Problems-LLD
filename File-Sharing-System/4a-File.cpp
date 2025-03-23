#include <string>
#include "2-Permissions.cpp"
#include "4-FileSystemComponent.cpp"
using namespace std;

class File : public FileSystemComponent {
private:
    string content;
    vector<FileVersion> versions;
    Permissions permissions;  // File-level permissions for this file.

public:
    // Constructor
    File(const string &name)
        : FileSystemComponent(name), content(""), permissions() {}

    // Composite Pattern Methods (overrides for a leaf node)
    string getName() const override {
        return name;
    }

    void setName(const string &newName) override {
        name = newName;
    }

    void add(FileSystemComponent* component) override {
        throw runtime_error("Cannot add to a file.");
    }

    void remove(FileSystemComponent* component) override {
        throw runtime_error("Cannot remove from a file.");
    }

    FileSystemComponent* getChild(const string &childName) override {
        throw runtime_error("Files do not contain children.");
    }

    void display(const string &indent) const override {
        cout << indent << "File: " << name << endl;
    }

    // File-Specific Methods
    void writeContent(const string &newContent) {
        content = newContent;
        versions.push_back(FileVersion(newContent));
    }

    string readContent() const {
        return content;
    }

    const vector<FileVersion>& getVersions() const {
        return versions;
    }

    const PermissionsDecorator& getPermissions() const {
        return permissions;
    }
};
