#ifndef ORDERSTATE_H
#define ORDERSTATE_H

#include <string> // Untuk tipe data string

// Base class untuk status order
class OrderState {
public:
    // Fungsi virtual untuk mendapatkan status, akan di-override di subclass
    virtual std::string getStatus() = 0; 
};

// Kelas untuk status "Not Yet Taken"
class NotYetTaken : public OrderState {
public:
    // Mengembalikan string yang menyatakan status
    std::string getStatus() override; 
};

// Kelas untuk status "In Kitchen"
class InKitchen : public OrderState {
public:
    // Mengembalikan string yang menyatakan status
    std::string getStatus() override;
};

// Kelas untuk status "Served"
class Served : public OrderState {
public:
    // Mengembalikan string yang menyatakan status
    std::string getStatus() override;
};

#endif
