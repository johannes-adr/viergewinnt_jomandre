#pragma once
#include "../Utils/Misc.h"
#include "../Player/Player.h"
#include <memory>
#include <array>
#include <map>
#include "../Utils/StackVec.h"
class Player;

class Board {
public:
    constexpr static int FIELD_HEIGHT{7};
    constexpr static int FIELD_WIDTH{6};

    Board();
    ~Board();

    Color teamOfPlayer(Player &p);
    virtual bool play(int col, Player &p);
    int getLowestNoneField(int col);
    void reset();

    std::string toString();

    static Color addPlayer(std::shared_ptr<Board>& board, std::shared_ptr<Player>& player);
private:
    std::array<std::array<Color, FIELD_WIDTH>, FIELD_HEIGHT> m_fields{};
    StackVec<std::shared_ptr<Player>,2> m_players{};
};