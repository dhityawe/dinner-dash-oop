#include "EmotionLevel.h"

EmotionLevel::EmotionLevel(int initialLevel) : level(initialLevel) {}

// Mengurangi level emosi (misalnya, setiap detik)
void EmotionLevel::decreaseLevel() {
    if (level > 1) {
        level--; // Mengurangi emosi satu tingkat hingga minimum level 1
    }
}

// Mengambil nilai emosi saat ini
int EmotionLevel::getLevel() const {
    return level;
}
