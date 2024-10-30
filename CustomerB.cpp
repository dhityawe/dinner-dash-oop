#include "CustomerB.h"

CustomerB::CustomerB() {
    levelEmotion = 100; // Inisialisasi level emosi
}

void CustomerB::makeOrder() {
    Customer::makeOrder(); // Panggil metode dari kelas induk
    std::cout << "Customer B has made an order.\n";
}
