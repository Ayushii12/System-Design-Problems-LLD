#include <string>
#include <chrono>
using namespace std;

class FileVersion {
private:
    string content;
    long timestamp;  

public:
    // Constructor
    FileVersion(const string &content) : content(content) {
        timestamp = static_cast<long>(chrono::duration_cast<chrono::milliseconds>(
            chrono::system_clock::now().time_since_epoch()).count());
    }

    // Getter for content
    string getContent() const { return content; }

    // Getter for timestamp
    long getTimestamp() const { return timestamp; }
};
