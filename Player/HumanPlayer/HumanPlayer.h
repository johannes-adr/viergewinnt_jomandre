#ifndef VIERGEWINNT_JOMANDRE_HUMANPLAYER_H
#define VIERGEWINNT_JOMANDRE_HUMANPLAYER_H
#pragma once

#include "../Player.h"
#include <iostream>

class HumanPlayer : public Player {
public:
    unsigned int chooseColumn() override;
};

#endif //VIERGEWINNT_JOMANDRE_HUMANPLAYER_H