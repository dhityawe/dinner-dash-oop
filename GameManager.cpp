#include "GameManager.h"
#include "CustomerA.h"
#include "CustomerB.h"
#include <cstdlib>
#include <iostream>

GameManager::GameManager(int numTables) : totalTables(numTables) {
    for (int i = 1; i <= totalTables; i++)
        tables.emplace_back(i);
}

void GameManager::generateCustomer() {
    if (rand() % 2 == 0)
        customerQueue.push(std::unique_ptr<Customer>(new CustomerA()));
    else
        customerQueue.push(std::unique_ptr<Customer>(new CustomerB()));
}

void GameManager::assignTable() {
    if (customerQueue.empty()) return;

    for (Table& table : tables) {
        if (table.isAvailable()) {
            table.assignCustomer(std::move(customerQueue.front()));
            customerQueue.pop();
            std::cout << "Customer assigned to Table " << &table - &tables[0] + 1 << "\n";
            break;
        }
    }
}

void GameManager::processCustomerOrders() {
    for (Table& table : tables) {
        Customer* customer = table.getCustomer();
        if (customer) {
            char orderInput, serveInput;

            // Menunggu input dari pengguna untuk memesan
            std::cout << "Is the customer at Table " << &table - &tables[0] + 1 << " ready to order? (y/n): ";
            std::cin >> orderInput;
            if (orderInput == 'y' || orderInput == 'Y') {
                customer->makeOrder();
                waiter.notifyOrderReady();
                
                // Menunggu input dari pengguna untuk pesanan siap
                std::cout << "Is the order ready to serve to Table " << &table - &tables[0] + 1 << "? (y/n): ";
                std::cin >> serveInput;
                if (serveInput == 'y' || serveInput == 'Y') {
                    kitchen.prepareOrder();
                    customer->eat();
                    waiter.notifyPayment(customer);

                    // customer meninggalkan table
                    customer->leaving();

                    // Jika customer meninggalkan table, hapus customer dari table
                    if (customer->isLeaving()) {
                        table.assignCustomer(nullptr);
                        std::cout << "Customer left Table " << &table - &tables[0] + 1 << "\n";
                    }
                }
            }
        }
    }
}

void GameManager::run() {
    while (true) {
        generateCustomer();
        assignTable();
        
        // Tambahkan logika untuk memproses pesanan
        processCustomerOrders();

        // Logika untuk melanjutkan permainan atau keluar
        char continueInput;
        std::cout << "Continue to the next customer? (y/n): ";
        std::cin >> continueInput;
        if (continueInput == 'n' || continueInput == 'N') {
            break; // keluar dari loop
        }
    }
}
