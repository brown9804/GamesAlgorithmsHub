
#ifndef MONOPOLY_MOVE_H
#define MONOPOLY_MOVE_H

#include "Juego.h"

namespace GameMechanics {

    class Move {
    private:

        int determineParticipantLocation(Game * game, Player::Participant *participant, int diceCount);

        void validateGoFunds(Player::Participant *participant, int location);


        int generateDiceCount(Dice *dice);


        bool checkDiceDouble(Dice *dice);
    public:

        static void move(Game * game, Player::Participant *participant, Dice *dice);
    };
}


#endif
