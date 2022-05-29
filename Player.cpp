//
// Created by Johannes A. on 26.05.22.
//
#pragma once
#include "Player.h"

// Creates a new player with the given id
Player::Player() = default;

Player::~Player() = default;

// Returns the team of the player
Color Player::getTeam() {
    if(auto board = this->m_board.lock()) {

    }else{
        printf("Unable to upgrade weak reference of board - player");
    }
}

// Gives up the game
bool Player::giveUp() {

}