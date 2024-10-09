// Kitchen.cpp
#include "Kitchen.h"

// Menambahkan observer ke daftar
void Kitchen::addObserver(Observer* observer) {
    observers.push_back(observer);
}

// Notifikasi ke semua observer
void Kitchen::notify() {
    for (auto observer : observers) {
        observer->update();
    }
}
