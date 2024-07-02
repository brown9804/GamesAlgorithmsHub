
#ifndef MONOPOLY_PARKING_H
#define MONOPOLY_PARKING_H

#include "Titulo.h"
#include "Participantes.h"
#include "Juego.h"

namespace GameBoard {

    class Parking : public Tile {
    public:
        Parking(const std::string &name);

        void action(Player::Participant *participant, GameMechanics::Game * game) override;
    };
}
#endif
