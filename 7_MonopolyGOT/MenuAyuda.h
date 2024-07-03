
#ifndef MONOPOLY_MENUHELPER_H
#define MONOPOLY_MENUHELPER_H

#include <iostream>
#include <vector>
#include "SinExcepcionesPropiedad.h"

namespace Util {

    void displayMenu(std::vector<std::string> &options);


    void displayParticipants(std::vector<Player::Participant *> participants);

    void displayHousesForParticipant(Player::Participant *participant);
}
#endif
