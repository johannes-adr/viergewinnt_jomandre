//
// Created by Johannes A. on 26.05.22.
//

#include "Board.h"

// Creates a new Board object and fills it with empty fields.
Board::Board(){
    m_fields[0].fill(Color::NONE);
    m_fields[1].fill(Color::NONE);
}

Board::~Board() = default;

// Return the lowest free field in the given column
int Board::getLowestNoneField(int col){
    for (int row = 0;row < FIELD_HEIGHT;row++){
        auto fieldAt = this->m_fields[row][col];
        if(fieldAt != Color::NONE){
            return row-1;
        }
    }
    return FIELD_HEIGHT-1;
}

// Returns a string representation of the board.
std::string Board::toString() {
    auto builder = "";
    auto board = &this->m_fields;
    for(int row = 0;row < Board::FIELD_HEIGHT;row++){
        for (int col = 0;col < Board::FIELD_WIDTH;col++){
            auto field = &board[row][col];
            builder+='O';
        }
        builder+='\n';
    }
    return builder;
}

// Returns true if the move was successful, false if the move was not possible
bool Board::play(int col){
    auto lowestNoneField = this->getLowestNoneField(col);
    if(lowestNoneField == -1){
        return false;
    }
    this->m_fields[lowestNoneField][col] = this->m_players[0]->getTeam();
    return true;
}

// Resets the board to its initial state
void Board::reset(){
    this->m_fields[0].fill(Color::NONE);
    this->m_fields[1].fill(Color::NONE);
}