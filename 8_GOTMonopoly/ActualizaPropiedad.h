
#ifndef MONOPOLY_UPGRADABLEPROPERTY_H
#define MONOPOLY_UPGRADABLEPROPERTY_H

#include "Juego.h"
#include "PreciosCasas.h"

namespace GameBoard {
    class UpgradableProperty: public Property {
    private:

        const int MAX_HOUSES = 4;

        const HousesPrice housesPrice;
        int currentHousesBuild = 0;
        void setCurrentHousesBuild(int currentHousesBuild);

        void addHouseToProperty(Player::Participant *participant);

        void removeHouseFromProperty(Player::Participant *participant);
    public:
        UpgradableProperty(const std::string &name, const double propertyPrice, const double rentCost,
                           const ColourType &colour, const GameBoard::HousesPrice housesPrice,
                           const double mortgage);

        const HousesPrice &getHousesPrice() const;

        int getCurrentHousesBuild() const;

        std::string getName();

        double getRentCost(GameMechanics::Game *game) override;

        void action(Player::Participant *participant, GameMechanics::Game * game) override;

        void doActionWithoutBeingOnProperty(GameMechanics::Game *game) override;

        std::string toString() override;
    };
}

#endif
