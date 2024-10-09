// Table.cpp
#include "Table.h"
#include <iostream>
using namespace std;

// Constructor untuk Table
Table::Table(int id) : id(id) {}

// Menambahkan order ke meja
void Table::addOrder(int orderId, std::shared_ptr<Order> order, std::shared_ptr<Customer> customer) {
    orders[orderId] = std::make_pair(order, customer);
    std::cout << "Order " << orderId << " added to table " << id << " for customer " << std::endl; // Menambahkan output
    notifyObservers(); // Notifikasi observer
}


// Menambahkan observer
void Table::addObserver(Observer* observer) {
    observers.push_back(observer);
}

// Notifikasi kepada semua observer
void Table::notifyObservers() {
    for (auto observer : observers) {
        observer->update();
    }
}
