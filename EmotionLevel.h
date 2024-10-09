#ifndef EMOTIONLEVEL_H
#define EMOTIONLEVEL_H

class EmotionLevel {
public:
    EmotionLevel(int initialLevel = 5); // Konstruktor dengan level awal (default 5)
    
    void decreaseLevel(); // Mengurangi level emosi (misalnya setiap detik)
    int getLevel() const; // Mengambil nilai emosi saat ini
    
private:
    int level; // Nilai level emosi (1-5)
};

#endif // EMOTIONLEVEL_H
