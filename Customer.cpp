#include "Customer.h"

// Konstruktor default
Customer::Customer() : name(""), emotion(5) {}

// Konstruktor dengan nama pelanggan
Customer::Customer(const std::string& name) : name(name), emotion(5) {}

// Update emosi pelanggan seiring berjalannya waktu
void Customer::updateEmotion() {
    emotion.decreaseLevel();
}

// Mendapatkan tingkat emosi saat ini
int Customer::getEmotionLevel() const {
    return emotion.getLevel();
}
