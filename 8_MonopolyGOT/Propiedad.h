
#ifndef MONOPOLY_PROPERTY_H
#define MONOPOLY_PROPERTY_H

#include "Titulo.h"
#include "LeeDigitado.h"
#include "MenuAyuda.h"
#include "Hipoteca.h"

namespace GameBoard {

    class Property: public Tile, public Mortgage {
    private:
        const double propertyPrice;

        Player::Participant * owner = nullptr;
    protected:
        const double rentCost;
    private:
        const ColourType colour;


        Player::Participant * selectBidder(std::vector<Player::Participant *> participants,
                                           Player::Participant *currentBidder);
    protected:

        void noOwner(Player::Participant *participant, GameMechanics::Game * game);

        void buyProperty(Player::Participant *participant);
    public:
        Property(const std::string &name, const double propertyPrice, const double rentCost,
                 const ColourType colour, const double mortgage);

        Player::Participant * getOwner();


        std::string getName();

        void setOwner(Player::Participant *owner);

        double getPropertyPrice() const;

        const ColourType &getColourType() const;

        virtual double getRentCost(GameMechanics::Game * game) = 0;


        virtual void action(Player::Participant *participant, GameMechanics::Game * game) = 0;


        void payRent(Player::Participant *participant, GameMechanics::Game * game);


        virtual void doActionWithoutBeingOnProperty(GameMechanics::Game * game) = 0;


        virtual std::string toString() = 0;


        void auctionHouse(GameMechanics::Game * game);

        bool checkIfOwnerHasAllSameColour();
    };
}

#endif
