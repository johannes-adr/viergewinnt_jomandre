//
// Created by Johannes A. on 26.05.22.
//

#include "Board.h"

Board::Board(){
    m_fields.fill(Color::NONE);
}

Board::~Board() = default;

int Board::getLowestNoneField(int col){
    for (int row = 0;row < FIELD_HEIGHT;row++){
        auto fieldAt = this->m_fields[row][col];
        if(fieldAt != Color::NONE){
            return row-1;
        }
    }
    return FIELD_HEIGHT-1;
}

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

bool Board::play(int col){

}