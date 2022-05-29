//
// Created by André on 27.05.2022.
//

#include "HumanPlayer.h"

// Try to play at a given position.
bool HumanPlayer::play(int position, Board &board) {
    bool check = board.play(position);
    if (check) {
        return true;
    }
    return false;
}