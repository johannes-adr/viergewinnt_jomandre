#ifndef VIERGEWINNT_JOMANDRE_SMARTBOT_H
#define VIERGEWINNT_JOMANDRE_SMARTBOT_H

#include "../Player.h"

class SmartBot : public Player {
public:
    unsigned  int chooseColumn() override;
};

#endif //VIERGEWINNT_JOMANDRE_SMARTBOT_H