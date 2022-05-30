#ifndef VIERGEWINNT_JOMANDRE_RANDOMBOT_H
#define VIERGEWINNT_JOMANDRE_RANDOMBOT_H

#include <random>
#include "../Player.h"

class RandomBot : public Player {
public:
    int chooseColumn() override;
};

#endif //VIERGEWINNT_JOMANDRE_RANDOMBOT_H