#include "HumanPlayer.h"

int HumanPlayer::chooseColumn() {
    int col;
    std::cout << "Choose column: ";
    std::cin >> col;
    std::cout << std::endl;
    return col;
}