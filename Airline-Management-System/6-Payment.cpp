#include '6a-PaymentStatus.cpp'

class Payment {
private:
    string paymentId;
    string paymentMethod;
    double amount;
    PaymentStatus status;

public:
    // Constructor
    Payment(const std::string& paymentId, const std::string& paymentMethod, double amount)
        : paymentId(paymentId), paymentMethod(paymentMethod), amount(amount), status(PaymentStatus::PENDING) {}

    // Getter functions
    string getPaymentId() const { return paymentId; }
    string getPaymentMethod() const { return paymentMethod; }
    double getAmount() const { return amount; }
    PaymentStatus getStatus() const { return status; }

    // Process payment method
    void processPayment() {
        status = PaymentStatus::COMPLETED;
    }
};
