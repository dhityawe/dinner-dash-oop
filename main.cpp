#include "Kitchen.h"
#include "Waiter.h"
#include "Customer.h"
#include "Order.h"
#include "Table.h"
#include <chrono>
#include <thread> // Untuk simulasi waktu berjalan
#include <iostream>

int main() {
    Kitchen kitchen; // Membuat objek Kitchen
    Waiter waiter; // Membuat objek Waiter
    kitchen.addObserver(&waiter); // Menambahkan Waiter sebagai observer

    // Membuat 3 meja
    Table table1(1);
    Table table2(2);
    Table table3(3);

    // Menambahkan Waiter sebagai observer untuk semua meja
    table1.addObserver(&waiter);
    table2.addObserver(&waiter);
    table3.addObserver(&waiter);

    int money = 0; // Uang yang dimiliki pemain
    bool gameOver = false;

    // Meminta input user untuk menaruh pelanggan di meja
    std::cout << "Enter the table number to seat the customer (1-3): ";
    int tableNumber;
    std::cin >> tableNumber;

    // Membuat pelanggan
    Customer customer("John Doe");

    // Menaruh pelanggan di meja yang dipilih
    std::shared_ptr<Order> order1 = std::make_shared<Order>(); // order
    do {
        if (tableNumber == 1) {
            table1.addOrder(1, order1, std::make_shared<Customer>(customer));
        } else if (tableNumber == 2) {
            table2.addOrder(1, order1, std::make_shared<Customer>(customer));
        } else if (tableNumber == 3) {
            table3.addOrder(1, order1, std::make_shared<Customer>(customer));
        } else {
            std::cout << "Invalid table number!" << std::endl;
        }
    } while(tableNumber >= 4);

    // Simulasi waktu berjalan dan update emosi pelanggan
    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulasi 1 detik
        customer.updateEmotion(); // Mengurangi emosi pelanggan
        std::cout << "Emotion level: " << customer.getEmotionLevel() << std::endl;

        if (customer.getEmotionLevel() == 1) {
            std::cout << "Customer is very unhappy!" << std::endl;
        }
    }

    // Waiter mengambil order
    waiter.takeOrder(1, order1);

    // Meminta input user untuk mengantarkan makanan
    std::cout << "Enter the table number to deliver the order (1-3): ";
    std::cin >> tableNumber;

    // Validasi apakah ada pelanggan di meja yang dipilih
    if (tableNumber == 1 && !table1.isTableEmpty()) {
        waiter.deliverOrder(1);
        money += 10; // Tambahkan uang jika pesanan berhasil diantarkan
        std::cout << "Order delivered! You earned $10. Total money: $" << money << std::endl;
    } else if (tableNumber == 2 && !table2.isTableEmpty()) {
        waiter.deliverOrder(2);
        money += 10;
        std::cout << "Order delivered! You earned $10. Total money: $" << money << std::endl;
    } else if (tableNumber == 3 && !table3.isTableEmpty()) {
        waiter.deliverOrder(3);
        money += 10;
        std::cout << "Order delivered! You earned $10. Total money: $" << money << std::endl;
    } else {
        std::cout << "Game Over! No customer at table " << tableNumber << "!" << std::endl;
        gameOver = true;
    }

    if (!gameOver) {
        std::cout << "Congratulations! You completed the task successfully." << std::endl;
    }

    return 0;
}
