#pragma once
#include "Player.h"

// Creates a new player with the given id
Player::Player() = default;

// Destructor
Player::~Player() = default;

// Returns the team of the player
Color Player::getTeam() {
    if(auto board = this->m_board.lock()) {
        return board->teamOfPlayer(*this);
    }else {
        printf("Unable to upgrade weak reference of board - player");
    }
    return NONE;
}

// Gives up the game, currently not implemented
bool Player::giveUp() {
    return false;
}

// Try to play at a given position.
bool Player::play(int position) {
    if(auto board = this->m_board.lock()) {
        bool check = board->play(position);
        if (check) {
            return true;
        }
    }
    return false;
}
