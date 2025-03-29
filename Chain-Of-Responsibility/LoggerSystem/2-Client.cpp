#include "1a-InfoLogProcessor.cpp"
#include "1b-ErrorLogProcessor.cpp"
#include "1c-DebugLogProcessor.cpp"

int main() {
    // Create the chain of log processors:
    //      InfoLogProcessor -> DebugLogProcessor -> ErrorLogProcessor -> nullptr
   LogProcessor logObject = new InfoLogProcessor(new DebugLogProcessor(new ErrorLogProcessor(nullptr)));

    // Logging calls; they will be handled by the appropriate processor in the chain
    logObject->log(LogProcessor::ERROR, "exception happens");
    logObject->log(LogProcessor::DEBUG, "need to debug this");
    logObject->log(LogProcessor::INFO, "just for info");

    // Clean up the chain. The destructor of the head will recursively delete the chain
    delete infoProcessor;

    return 0;
}
