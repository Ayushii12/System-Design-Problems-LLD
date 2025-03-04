#include <iostream>
#include <mutex>
#include "6-Payment.cpp"

class PaymentProcessor {
private:
    static PaymentProcessor* instance;
    static mutex instanceMutex;

    // Private constructor to enforce singleton pattern
    PaymentProcessor() {}

public:
    // Get the singleton instance (thread-safe)
    static PaymentProcessor* getInstance() {
        lock_guard<std::mutex> lock(instanceMutex);
        if (instance == nullptr) {
            instance = new PaymentProcessor();
        }
        return instance;
    }

    // Process payment
    void processPayment(Payment& payment) {
        payment.processPayment();
    }
};

// Initialize static variables
PaymentProcessor* PaymentProcessor::instance = nullptr;
mutex PaymentProcessor::instanceMutex;
