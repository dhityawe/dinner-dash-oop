#ifndef WAITER_H
#define WAITER_H

#include <iostream>
#include <vector>
#include "Customer.h"

class Waiter {
public:
    void notifyOrderReady(); // Notifikasi ketika pesanan siap
    void notifyPayment(Customer* customer); // Notifikasi ketika pelanggan membayar
};

#endif // WAITER_H
