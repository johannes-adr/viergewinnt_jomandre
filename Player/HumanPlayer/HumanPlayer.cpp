#include "HumanPlayer.h"

unsigned int HumanPlayer::chooseColumn() {
    unsigned int col;
    std::cout << "Choose column: ";
    std::cin >> col;
    std::cout << std::endl;
    return col;
}