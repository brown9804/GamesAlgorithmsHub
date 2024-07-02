
#ifndef MONOPOLY_TILE_H
#define MONOPOLY_TILE_H
#include <iostream>
#include "Colores.h"

namespace Player {
    class Participant;
}

namespace GameMechanics {
    class Game;
}

namespace GameBoard {
    class Tile {
    private:

        const std::string name;
    public:
        Tile(const std::string &name);


        virtual std::string getName();
\
        virtual void action(Player::Participant * participant, GameMechanics::Game * game);

        virtual ~Tile();
    };
}

#endif
