#include <string>
#include <iostream>

class LogProcessor {
public:
    static const int INFO = 1;
    static const int DEBUG = 2;
    static const int ERROR = 3;

protected:
    // Pointer to the next logger in the chain
    LogProcessor* nextLoggerProcessor;

public:
    // Constructor initializes the chain of loggers
    LogProcessor(LogProcessor* loggerProcessor = nullptr){
        nextLoggerProcessor = loggerProcessor;
    } 

    // Declare a pure virtual destructor to make this class abstract
    virtual ~LogProcessor() = 0;

    // Virtual log method which can be overridden by derived classes
    // By default, it forwards the message to the next logger in the chain
    virtual void log(int logLevel, const std::string& message) {
        if (nextLoggerProcessor != nullptr) {
            nextLoggerProcessor->log(logLevel, message);
        }
    }
};
