#include <string>
using namespace std;

class FileSystemComponent {
protected:
    string name;

public:
    FileSystemComponent(const string &name) : name(name) {}

    virtual ~FileSystemComponent() {}

    // Getters
    string getName() const { return name; }

    // Setter for the component name (added for renaming functionality)
    void setName(const string &newName) { name = newName; }

    // Pure virtual function to get the size of the component
    //     - For a file, it returns the file size
    //     - For a folder, it may return the cumulative size of its children (all the files and other folders inside this folder)
    virtual size_t getSize() const = 0;
};
