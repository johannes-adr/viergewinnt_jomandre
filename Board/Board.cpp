#include "Board.h"

// Creates a new Board object and fills it with empty fields.
Board::Board() {
    this->reset();
}

// Destructor
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
    std::string builder;
    for (int row = 0; row < FIELD_HEIGHT; row++) {
        for (int col = 0; col < FIELD_WIDTH; col++) {
            auto color = m_fields[row][col];
            switch (color) {
                case NONE:
                    builder += "[ ]";
                    break;
                case RED:
                    builder += "[R]";
                    break;
                case YELLOW:
                    builder += "[Y]";
                    break;
            }
        }
        builder += "\n";
    }
    return builder;
}



// Returns true if the move was successful, false if the move was not possible
bool Board::play(int col, Player &p){
    auto lowestNoneField = this->getLowestNoneField(col);
    if(lowestNoneField == -1){
        return false;
    }
    this->m_fields[lowestNoneField][col] = p.getTeam();
    return true;
}

// Resets the board to its initial state
void Board::reset(){
    for (int i = 0; i < FIELD_HEIGHT; i++) {
        for (int j = 0; j < FIELD_WIDTH; j++) {
            m_fields[i][j] = Color::NONE;
        }
    }
}

// Returns the team of the given player
Color Board::teamOfPlayer(Player &p) {
    int index = -1;
    for(int i = 0;i < this->m_players.length();i++){
        auto res = this->m_players.getAt(i).unwrap();
        if (p.equals(*res)){
            index = i;
        }
    }

    if(index==0){
        return Color::RED;
    }else if(index==1){
        return Color::YELLOW;
    }
    return Color::NONE;
}

Color Board::addPlayer(std::shared_ptr<Board>& board,std::shared_ptr<Player>& player) {
    auto index = board->m_players.push(player);
    if(index != -1){
        player->setBoard(std::weak_ptr(board));
        return board->teamOfPlayer(*player);
    }
    return NONE;
}

bool Board::removePlayer(Player *p) {
    for(int i = 0;i < this->m_players.length();i++){
        auto res = this->m_players.getAt(i).unwrap();
        if (p->equals(*res)){
            this->m_players.swapRemoveAt(i);
            return true;
        }
    }
    return false;
}
