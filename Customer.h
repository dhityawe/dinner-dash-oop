#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "EmotionLevel.h" // Tambahkan EmotionLevel

class Customer {
public:
    Customer(); // Konstruktor default
    Customer(const std::string& name); // Konstruktor dengan parameter
    
    void updateEmotion(); // Memanggil fungsi untuk mengurangi emosi
    int getEmotionLevel() const; // Mendapatkan tingkat emosi saat ini

private:
    std::string name; // Nama pelanggan
    EmotionLevel emotion; // Instance EmotionLevel
};

#endif // CUSTOMER_H
