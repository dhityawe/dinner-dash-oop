#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Customer.h"
#include "Waiter.h"
#include "Kitchen.h"
#include "Table.h"
#include <queue>
#include <memory>
#include <vector>

class GameManager {
public:
    GameManager(int numTables);
    
    void generateCustomer(); // Generate customer randomly
    void assignTable(); // Assign customer to table
    void processCustomerOrders(); // Process customer orders
    void run(); // Main game loop

private:
    int totalTables;
    std::queue<std::unique_ptr<Customer>> customerQueue; // Queue of customers
    std::vector<Table> tables; // List of tables
    Waiter waiter; // Waiter object
    Kitchen kitchen; // Kitchen object
};

#endif // GAMEMANAGER_H
