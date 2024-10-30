#include "Waiter.h"

void Waiter::notifyOrderReady() {
    std::cout << "Waiter: The order is ready to be served.\n";
}

void Waiter::notifyPayment(Customer* customer) {
    if (customer) {
        std::cout << "Waiter: Customer has paid.\n";
    }
}
