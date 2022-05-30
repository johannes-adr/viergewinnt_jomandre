#include "VerticalBot.h"

// Tries to play at the current column, if the column is full it will try to play at the next column.
unsigned int VerticalBot::chooseColumn() {
    if(auto board = this->m_board.lock()) {
        while(board->getLowestNoneField(m_pointInRow) == -1){
            m_pointInRow++;
        }
        return m_pointInRow;
    }
    return false;
}
