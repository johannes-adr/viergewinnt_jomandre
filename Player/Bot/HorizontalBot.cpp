#include "HorizontalBot.h"

// Chooses each row of the board if it is possible to play there.
int HorizontalBot::chooseColumn() {
    if (auto board = this->m_board.lock()) {
        m_pointInRow++;
        while (board->getLowestNoneField(m_pointInRow) == -1) {
            if (m_pointInRow == 6){
                m_pointInRow = 0;
            } else {
                m_pointInRow++;
            }
        }
        return m_pointInRow;
    }
    return false;
}