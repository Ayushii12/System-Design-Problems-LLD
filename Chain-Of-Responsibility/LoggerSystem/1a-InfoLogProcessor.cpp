#include "1-LogProcessor.cpp"
#include <iostream>
#include <string>
using namespace std;

class InfoLogProcessor : public LogProcessor {
public:
    // Constructor calling the base class constructor
    InfoLogProcessor(LogProcessor* nextLoggerProcessor = nullptr)
        : LogProcessor(nextLoggerProcessor) {}

    // Override the log method to handle INFO log level
    void log(int logLevel, const string& message) override {
        if (logLevel == INFO) {
            cout << "INFO: " << message << endl;
        } else {
            LogProcessor::log(logLevel, message);   // Forward the message to the next logger in the chain
        }
    }
};
