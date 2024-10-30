#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

enum class CustomerState {
    Waiting,
    MakingOrder,
    Eating,
    Leaving
};

class Customer {
public:
    Customer();
    virtual ~Customer() = default;

    virtual void makeOrder();
    void eat();
    void decreaseEmotion();
    void leaving();
    bool isLeaving() const;

    CustomerState getState() const;

protected:
    int levelEmotion;
    CustomerState state;
};

#endif // CUSTOMER_H
