

#ifndef MONOPOLY_XORTI_H
#define MONOPOLY_XORTI_H

#include "Titulo.h"
#include "Participantes.h"
#include "Juego.h"

namespace GameBoard {

    class Xorti: public Tile {
    private:
        const int MAXIMUM_XORTI = 4;
        const int MAXIMUM_BIRTHDAY_PRICE = 100;
        const int MINIMUM_BIRTHDAY_PRICE = 10;
        const int MAXIMUM_PARKING_FINE = 150;
        const int MINIMUM_PARKING_FINE = 50;
        const int MAXIMUM_MEPA_FINE = 180;
        const int MINIMUM_MEPA_FINE = 40;

        void birthday(Player::Participant &participant, GameMechanics::Game * game);

        void parkingFine(Player::Participant &participant, GameMechanics::Game * game);

        void mepaFine(Player::Participant &participant, GameMechanics::Game * game);


        void moveToRandomPlace(Player::Participant &participant, GameMechanics::Game * game);

    public:
        Xorti(const std::string &name);

        void action(Player::Participant *participant, GameMechanics::Game * game) override;
    };
}
#endif
