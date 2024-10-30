#ifndef CUSTOMER_A_H
#define CUSTOMER_A_H

#include "Customer.h"

class CustomerA : public Customer {
public:
    CustomerA();
    void makeOrder() override; // Override makeOrder method
};

#endif // CUSTOMER_A_H
