// Kitchen.h
#ifndef KITCHEN_H
#define KITCHEN_H

#include <vector>
#include "Observer.h"

class Kitchen {
public:
    void addObserver(Observer* observer); // Menambahkan observer
    void notify(); // Notifikasi ke semua observer

private:
    std::vector<Observer*> observers; // Daftar observer
};

#endif // KITCHEN_H
