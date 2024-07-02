
#ifndef MONOPOLY_TRADE_H
#define MONOPOLY_TRADE_H

#include "Juego.h"
#include <set>

namespace GameMechanics {

    class Trade {
    private:

        Player::Participant *determineTrader(std::vector<Player::Participant *> participants,
                                             Player::Participant *trader);

        void transactionTrade(Player::Participant *buyer, Player::Participant *seller,
                              GameBoard::Property *propertyForSale);

        double offerCash(Player::Participant *buyer);


        GameBoard::Property * offerProperty(Player::Participant *buyer);

        bool makeTransaction(Player::Participant *buyer, Player::Participant *seller,
                             double cashOffered, std::set<GameBoard::Property *> propertiesOffered,
                             GameBoard::Property *propertyForSale);

        std::string buyerOffer(Player::Participant *buyer, double cashOffered,
                          std::set<GameBoard::Property *> &propertiesOffered);
    public:

        static void tradePropertyBuyerKnown(Game *game, Player::Participant *buyer);

        static void tradePropertySellerKnown(Game *game, Player::Participant *seller);
    };
}


#endif
