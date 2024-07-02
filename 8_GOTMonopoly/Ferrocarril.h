
#ifndef MONOPOLY_RAILROAD_H
#define MONOPOLY_RAILROAD_H

#include "PropiedadNoActualizada.h"

namespace GameBoard {

    class RailRoad: public NonUpgradableProperty {
    public:
        RailRoad(const std::string &name, const double propertyPrice, const double rentCost, const ColourType &colour,
                 const double mortgage);

        double getRentCost(GameMechanics::Game *game) override;
    };
}
#endif
