// Table.h
#ifndef TABLE_H
#define TABLE_H

#include <map>
#include <memory>
#include <vector>
#include "Order.h"
#include "Observer.h"
#include "Customer.h"

class Table {
public:
    Table(int id);
    void addOrder(int orderId, std::shared_ptr<Order> order, std::shared_ptr<Customer> customer);
    void notifyObservers(); // Memanggil notify untuk observer
    bool isTableEmpty() const;
    void addObserver(Observer* observer); // Menambahkan observer

private:
    int id; // ID meja
    std::map<int, std::pair<std::shared_ptr<Order>, std::shared_ptr<Customer>>> orders; // Pesanan
    std::vector<Observer*> observers; // Observer yang terdaftar
    
};

#endif // TABLE_H
