#ifndef CUSTOMER_B_H
#define CUSTOMER_B_H

#include "Customer.h"

class CustomerB : public Customer {
public:
    CustomerB();
    void makeOrder() override; // Override makeOrder method
};

#endif // CUSTOMER_B_H
