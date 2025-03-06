#include "6b-Payment.cpp"

class PaymentProcessor {
private:
    static PaymentProcessor* instance;
    unordered_map<int, Payment> payments;
    
    // Private constructor for Singleton
    PaymentProcessor() {}

public:
    static PaymentProcessor* getInstance() {
        if (!instance) {
            instance = new PaymentProcessor();
        }
        return instance;
    }

    // Create a new payment and store it
    void createPayment(int paymentId, double amount) {
        Payment payment(paymentId, amount, PaymentStatus::PENDING);
        payments[paymentId] = payment;
        cout << "Payment created with ID: " << paymentId << endl;
    }

    // Method to process payment
    Payment processPayment(int paymentId, double amount) {
        if (payments.find(paymentId) == payments.end()) {
            cout << "Payment ID not found!" << endl;
            return;
        }
        Payment& payment = payments[paymentId];  
        if (payment.getStatus() == PaymentStatus::COMPLETED) {
            cout << "Payment ID " << paymentId << " is already completed." << endl;
            return;
        }
        PaymentStatus newStatus = (payment.getAmount() > 0) ? PaymentStatus::COMPLETED : PaymentStatus::FAILED;
        payment.setStatus(newStatus);
        return payment;
    }
};

// Initialize static instance
PaymentProcessor* PaymentProcessor::instance = nullptr;
