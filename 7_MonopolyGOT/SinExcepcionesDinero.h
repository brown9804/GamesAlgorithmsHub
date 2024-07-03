
#ifndef MONOPOLY_NOMONEYEXCEPTION_H
#define MONOPOLY_NOMONEYEXCEPTION_H

#include <iostream>
#include "Participantes.h"
#include "Intercambio.h"
#include "Mover.h"

namespace Exception {

    class NoMoneyException {
    public:
        std::string message;

        double amountDue;

        NoMoneyException(double amountDue);

        bool payAmountDue(GameMechanics::Game *game, double amountDue, Player::Participant *debitor,
                          Player::Participant *creditor);


        bool payDebt(double amountDue, Player::Participant *debitor, Player::Participant *creditor);
    };
}

#endif
