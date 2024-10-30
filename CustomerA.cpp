#include "CustomerA.h"

CustomerA::CustomerA() {
    levelEmotion = 150; // Inisialisasi level emosi
}

void CustomerA::makeOrder() {
    Customer::makeOrder(); // Panggil metode dari kelas induk
    std::cout << "Customer A has made an order.\n";
}
