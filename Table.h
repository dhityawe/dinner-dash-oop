#ifndef TABLE_H
#define TABLE_H

#include <memory>
#include "Customer.h"

class Table {
    int number;
    std::unique_ptr<Customer> customer;

public:
    Table(int num);
    void assignCustomer(std::unique_ptr<Customer> cust);
    bool isAvailable() const;
    Customer* getCustomer() const;
};

#endif
