// Example: Payment Strategy System
// Let's say we have different payment methods (Credit Card, Paypal, etc.), and we want to allow users to choose their payment strategy dynamically.

#include<bits/stdc++.h>
using namespace std;

// Strategy Interface
class PaymentStrategy{
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() = default;
};

// Concrete Strategy 1: Credit card payment
class CreditCardPayment : public PaymentStrategy{
public:
    void pay(int amount) override {
        cout << "Paid $" << amount << " using Credit Card" << endl;
    }
};

// Concrete Strategy 2: Paypal Payment
class PaypalPayment : public PaymentStrategy{
public:
    void pay(int amount) override{
        cout << "Paid $" << amount << " using Paypal" << endl;
    }
};

// Context Class
class PaymentContext{
private:
    unique_ptr<PaymentStrategy> strategy;

public:
    void setStrategy(unique_ptr<PaymentStrategy> s){
        strategy = move(s);
    }

    void processPayment(int amount){
        if(strategy){
            strategy -> pay(amount);
        }else{
            cout << "No payment strategy selected" << endl;
        }
    }
};

int main(){
    PaymentContext paymentContext;

    paymentContext.setStrategy(make_unique<CreditCardPayment>());
    paymentContext.processPayment(100);

    paymentContext.setStrategy(make_unique<PaypalPayment>());
    paymentContext.processPayment(200);

    return 0;
}