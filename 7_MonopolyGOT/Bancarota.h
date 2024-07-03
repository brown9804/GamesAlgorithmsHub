

#ifndef MONOPOLY_BANKRUPTCY_H
#define MONOPOLY_BANKRUPTCY_H


#include "Participantes.h"
#include "Juego.h"
namespace GameMechanics {

    class Bankruptcy {
    public:

        static void transferProperties(GameMechanics::Game *game, Player::Participant *currentOwner,
                                       Player::Participant *newOwner);
    };
}


#endif
