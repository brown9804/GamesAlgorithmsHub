
#ifndef MONOPOLY_TAX_H
#define MONOPOLY_TAX_H

#include "Titulo.h"
#include "Participantes.h"
#include "Juego.h"

namespace GameBoard {
    class Tax: public Tile {
    private:

        const int taxAmount;
    public:
        Tax(const std::string &name, const int &taxAmount);

        void action(Player::Participant *participant, GameMechanics::Game * game) override;
    };
}
#endif
