#include "GameManager.h"

int main() {
    srand(static_cast<unsigned int>(time(0))); // Untuk mengacak customer
    GameManager game(4); // Misalkan ada 4 meja
    game.run(); // Memulai permainan
    return 0;
}
