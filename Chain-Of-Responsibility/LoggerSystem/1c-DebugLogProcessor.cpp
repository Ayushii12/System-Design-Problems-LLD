#include "1-LogProcessor.cpp"
#include <iostream>
#include <string>
using namespace std;

class DebugLogProcessor : public LogProcessor {
public:
    // Constructor calling the base class constructor
    DebugLogProcessor(LogProcessor* nextLoggerProcessor = nullptr)
        : LogProcessor(nextLoggerProcessor) {}

    // Override the log method to handle DEBUG log level
    void log(int logLevel, const string& message) override {
        if (logLevel == DEBUG) {
            cout << "DEBUG: " << message << endl;
        } else {
            LogProcessor::log(logLevel, message);    // Forward the message to the next logger in the chain
        }
    }
};
