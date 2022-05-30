#include "Player.h"

#include <utility>

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
bool Player::play() {
    if(auto board = this->m_board.lock()) {
        for (int i = 0; i < 10000; i++) {
            unsigned int position = this->chooseColumn();
            if (board->play(position, *this);) {
                return true;
            }
        }
        throw std::runtime_error("Unable to play");
    }
    printf("Unable to get reference to board from player (play)\n");
    return false;
}

void Player::setBoard(std::weak_ptr<Board> b) {
    if(auto board = this->m_board.lock()) {
        board->removePlayer(this);
    }
    this->m_board = std::move(b);
}
