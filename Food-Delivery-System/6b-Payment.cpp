class Payment {
private:
    int paymentId;
    double amount;
    PaymentStatus status;

public:
    // Constructor
    Payment(int id, double amount, PaymentStatus status)
        : paymentId(id), amount(amount), status(status) {}

    // Getters and Setters
    int getPaymentId() const { return paymentId; }
    double getAmount() const { return amount; }
    PaymentStatus getStatus() const { return status; }

    void setPaymentId(int id) { paymentId = id; }
    void setAmount(double amt) { amount = amt; }
    void setStatus(PaymentStatus stat) { status = stat; }
};
