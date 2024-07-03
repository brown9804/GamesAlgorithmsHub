
#ifndef MONOPOLY_NOHOUSESEXCEPTION_H
#define MONOPOLY_NOHOUSESEXCEPTION_H

#include "Participantes.h"

namespace Exception {
    class NoPropertyException {
    public:
        std::string message;

        NoPropertyException(Player::Participant &participant);
    };
}


#endif
