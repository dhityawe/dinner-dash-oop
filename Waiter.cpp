// Waiter.cpp
#include "Waiter.h"

// Implementasi fungsi update
void Waiter::update() {
    std::cout << "Waiter has been notified." << std::endl;
}

// Implementasi fungsi takeOrder
void Waiter::takeOrder(int tableID, std::shared_ptr<Order> order) {
    std::cout << "Taking order for table " << tableID << std::endl;
}

// Implementasi fungsi deliverOrder
void Waiter::deliverOrder(int tableID) {
    std::cout << "Delivering order to table " << tableID << std::endl;
}
