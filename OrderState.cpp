#include "OrderState.h" // Memasukkan header file untuk OrderState

// Implementasi fungsi getStatus untuk status "Not Yet Taken"
std::string NotYetTaken::getStatus() {
    return "Not Yet Taken";
}

// Implementasi fungsi getStatus untuk status "In Kitchen"
std::string InKitchen::getStatus() {
    return "In Kitchen";
}

// Implementasi fungsi getStatus untuk status "Served"
std::string Served::getStatus() {
    return "Served";
}
