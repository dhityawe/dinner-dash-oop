#include "Kitchen.h"
#include "Waiter.h"
#include "Customer.h"
#include "Order.h"
#include "Table.h"
#include <chrono>
#include <thread> // Untuk simulasi waktu berjalan

int main() {
    Kitchen kitchen; // Membuat objek Kitchen
    Waiter waiter; // Membuat objek Waiter
    kitchen.addObserver(&waiter); // Menambahkan Waiter sebagai observer

    Customer customer("John Doe"); // Membuat Customer dengan nama
    std::shared_ptr<Order> order1 = std::make_shared<Order>(); // Order pertama tanpa spesifik menu
    Table table1(1); // Meja 1
    table1.addOrder(1, order1, std::make_shared<Customer>(customer)); // Menambahkan order ke meja

    waiter.takeOrder(1, order1); // Waiter mengambil order

    // Simulasi waktu berjalan dan update emosi pelanggan
    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulasi 1 detik
        customer.updateEmotion(); // Mengurangi emosi pelanggan
        std::cout << "Emotion level: " << customer.getEmotionLevel() << std::endl;

        if (customer.getEmotionLevel() == 1) {
            std::cout << "Customer is very unhappy!" << std::endl;
        }
    }

    waiter.deliverOrder(1); // Waiter mengantarkan order

    return 0;
}
