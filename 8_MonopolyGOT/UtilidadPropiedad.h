

#ifndef MONOPOLY_SPECIALPROPERTY_H
#define MONOPOLY_SPECIALPROPERTY_H

#include "Juego.h"
#include "PropiedadNoActualizada.h"

namespace GameBoard {

    class UtilityProperty: public NonUpgradableProperty {
    private:
        const double OWNER_OWNS_BOTH_UTILITY_COST = 10;
    public:
        UtilityProperty(const std::string &name, const double propertyPrice, const double rentCost,
                        const ColourType &colour, const double mortgage);

        double getRentCost(GameMechanics::Game *game) override;
    };
}
#endif
