#include "1-LogProcessor.cpp"
#include <iostream>
#include <string>
using namespace std;

class ErrorLogProcessor : public LogProcessor {
public:
    // Constructor calling the base class constructor
    ErrorLogProcessor(LogProcessor* nextLoggerProcessor = nullptr)
        : LogProcessor(nextLoggerProcessor) {}

    // Override the log method to handle ERROR log level
    void log(int logLevel, const string& message) override {
        if (logLevel == ERROR) {
            cout << "ERROR: " << message << endl;
        } else {
            LogProcessor::log(logLevel, message);  // Forward the message to the next logger in the chain
        }
    }
};
