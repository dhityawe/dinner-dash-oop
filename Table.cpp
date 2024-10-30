#include "Table.h"

Table::Table(int num) : number(num), customer(nullptr) {}

void Table::assignCustomer(std::unique_ptr<Customer> cust) {
    customer = std::move(cust);
}

bool Table::isAvailable() const { return !customer; }

Customer* Table::getCustomer() const { return customer.get(); }
