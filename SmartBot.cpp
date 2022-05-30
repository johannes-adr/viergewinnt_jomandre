#include "SmartBot.h"

int SmartBot::chooseColumn() {
    if(auto board = this->m_board.lock()) {
        return board->getLowestNoneField(0);
    }
    return -1;
}