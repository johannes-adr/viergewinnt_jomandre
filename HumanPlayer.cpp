//
// Created by André on 27.05.2022.
//

#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(int id, Color team)
: Player(id, team)
{
}

HumanPlayer::~HumanPlayer() = default;

// Try to play at a given position.
bool HumanPlayer::play(int position, Board &board) {
    bool check = board.play(position);
    if (check) {
        return true;
    }
    return false;
}

// Gives up the game
bool HumanPlayer::giveUp() {
    return true;
}

// Returns the team of the player
Color HumanPlayer::getTeam() {
    return m_team;
}