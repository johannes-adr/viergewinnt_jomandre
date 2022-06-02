#include "Board.h"
#include "../Utils/Color.h"

//Constructor
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

void Board::print(){
    std::string a = "[■]";
    for (int row = 0; row < FIELD_HEIGHT; row++) {
        for (int col = 0; col < FIELD_WIDTH; col++) {
            auto color = m_fields[row][col];
            switch (color) {
                case NONE:
                    std::cout << white(a);
                    break;
                case RED:
                    std::cout << red(a);
                    break;
                case YELLOW:
                    std::cout << yellow(a);
                    break;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Returns true if the move was successful, false if the move was not possible
bool Board::play(unsigned int col, Player &p){
    auto w = this->m_fields[0].size();
    if(col >= w){
        std::cout << "Column outside of range " << w << std::endl;
        return false;
    }
    auto lowestNoneField = this->getLowestNoneField((int)col);
    if(lowestNoneField == -1){
        std::cout << "Column is full" << std::endl;
        return false;
    }

    this->m_fields[lowestNoneField][col] = p.getTeam();
    return true;
}

void Board::run(){
    this->isRunning = true;
    while(this->isRunning){
        //Two players in board
        auto missingPlayers = this->m_players.getRemainingSpace();
        if(missingPlayers != 0){
            throw std::runtime_error(std::to_string(missingPlayers) + " players missing");
        }
        for(const auto& p : this->m_players){
            p->play();
            this->print();
            if(this->checkWin())
                return;
        }
    }
}


void Board::stop() {
    this->isRunning = false;
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

// Adds the given player to the board
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



bool Board::checkWin() {

    auto winCondition = [](int yellow, int red){
        if(yellow == 4){
            return Color::YELLOW;
        }else if(red == 4){
            return Color::RED;
        }
        return Color::NONE;
    };

    auto winLogic = [&winCondition](int& yellow, int& red, Color& field){
        if(field == Color::NONE){
            red =0;
            yellow = 0;
        }else if(field == Color::RED){
            red++;
            yellow = 0;
        }else if(field == Color::YELLOW){
            yellow++;
            red = 0;
        }

        Color winner = winCondition(yellow,red);
        if(winner != Color::NONE){
            std::cout << (winner==Color::RED?"Red":"Yellow") << " won" << std::endl;
            return true;
        }
        return false;
    };

    auto b = this->m_fields;
    int rows = b.size();
    int cols = b[0].size();
    //Horizontal
    for(auto row= 0;row < rows;row++){
        int red = 0;
        int yellow = 0;
        for(auto col= 0;col < cols;col++){
            if(winLogic(yellow, red,b[row][col])){
                std::cout << "Horizontal: y" << row << std::endl;
                return true;
            }
        }
    }

    //Vertical
    for(auto col= 0;col < cols;col++){
        int red = 0;
        int yellow = 0;
        for(auto row= 0;row < rows;row++){
            if(winLogic(yellow, red,b[row][col])){
                std::cout << "Vertical: c" << col << std::endl;
                return true;
            }
        }
    }

    /*
     * DIAGONAL SEARCH NORTH-WEST TO SOUTH-EAST
     */

    //cursor moving from right to left, rowsearch from current column (left) top to bottom right
    for(auto col = cols;col >= 0;col--){
        auto localcol = col;
        int red = 0;
        int yellow = 0;
        for(auto localrow = 0;localrow < rows && localcol < cols;localrow++, localcol++){
            if(winLogic(yellow, red,b[localrow][localcol])){
                std::cout << "(left) top to bottom right/1: c" << localcol << " r" << localrow << std::endl;
                return true;
            }
        }
    }

    //cursor moving from top to bottom, rowsearch from current row (top) left to bottom right
    for(auto row = 0;row < rows;row++){
        auto localrow = row;
        int red = 0;
        int yellow = 0;
        for(auto localcol = 0;localcol < cols && localrow < rows;localrow++, localcol++){
            if(winLogic(yellow, red,b[localrow][localcol])){
                std::cout << "(top) left to bottom right/2: c" << localcol << " r" << localrow << std::endl;
                return true;
            }
        }
    }

    /*
     * DIAGONAL SEARCH NORTH-EAST TO SOUTH-WEST
     */

    //cursor moving from left to right, rowsearch from current column (right) to diagonal bottom left
    for(auto col = 0;col < cols;col++){
        auto localcol = col;
        int red = 0;
        int yellow = 0;
        for(auto localrow = 0;localrow < rows && localcol >= 0;localrow++, localcol--){
            if(winLogic(yellow, red,b[localrow][localcol])){
                std::cout << "(right) to diagonal bottom left/1: c" << localcol << " r" << localrow << std::endl;
                return true;
            }
        }
    }

    //cursor moving from top to bottom, rowsearch from current row (right) to bottom left
    for(auto row = 0;row < rows;row++){
        auto localrow = row;
        int red = 0;
        int yellow = 0;
        for(auto localcol = cols;localcol >= 0 && localrow < rows;localrow++, localcol--){
            if(winLogic(yellow, red,b[localrow][localcol])){
                std::cout << "(right) to diagonal bottom left/2: c" << localcol << " r" << localrow << std::endl;
                return true;
            }
        }
    }



    return false;
}
