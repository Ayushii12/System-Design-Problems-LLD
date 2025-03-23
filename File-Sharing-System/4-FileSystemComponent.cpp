#include <string>
using namespace std;

class FileSystemComponent {
protected:
    string name;

public:
    FileSystemComponent(const string &name) : name(name) {}
    virtual ~FileSystemComponent() {}

    virtual string getName() const { return name; }

    virtual void setName(const string &newName) { name = newName; }

    // Composite Pattern Methods: for leaf nodes these should throw exceptions.
    virtual void add(FileSystemComponent* component) = 0;
    virtual void remove(FileSystemComponent* component) = 0;
    virtual FileSystemComponent* getChild(const string &name) = 0;
    virtual void display(const string &indent) const = 0;
};
