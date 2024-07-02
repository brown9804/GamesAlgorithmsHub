
#ifndef MONOPOLY_NONUPGRADABLEPROPERTY_H
#define MONOPOLY_NONUPGRADABLEPROPERTY_H

#include "Propiedad.h"

namespace GameBoard {
    class NonUpgradableProperty : public Property {
    public:
        NonUpgradableProperty(const std::string &name, const double propertyPrice, const double rentCost,
                              const ColourType &colour, const double mortgage);

        void action(Player::Participant *participant, GameMechanics::Game *game) override;


        void doActionWithoutBeingOnProperty(GameMechanics::Game * game) override;


        std::string toString();
    };
}
#endif
