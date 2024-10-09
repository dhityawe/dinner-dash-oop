// Waiter.h
#ifndef WAITER_H
#define WAITER_H

#include "Observer.h"
#include "Order.h" 
#include <iostream>
#include <memory>

class Waiter : public Observer {
public:
    void update() override; // Deklarasi update
    void takeOrder(int tableID, std::shared_ptr<Order> order); // Deklarasi takeOrder
    void deliverOrder(int tableID); // Deklarasi deliverOrder
};

#endif // WAITER_H
