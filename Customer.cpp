#include "Customer.h"

Customer::Customer() : levelEmotion(100), state(CustomerState::Waiting) {}

void Customer::makeOrder() {
    state = CustomerState::MakingOrder;
    std::cout << "Customer is making an order.\n";
}

void Customer::eat() {
    state = CustomerState::Eating;
    std::cout << "Customer is eating.\n";
}

void Customer::decreaseEmotion() {
    levelEmotion -= 10; // Contoh pengurangan emosi
    if (levelEmotion <= 0) {
        state = CustomerState::Leaving;
        std::cout << "Customer is leaving due to low emotion.\n";
    }
}

bool Customer::isLeaving() const {
    return state == CustomerState::Leaving;
}

CustomerState Customer::getState() const {
    return state;
}
