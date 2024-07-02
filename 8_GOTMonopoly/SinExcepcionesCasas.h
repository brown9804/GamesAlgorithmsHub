
#ifndef MONOPOLY_NOHOUSEEXCEPTION_H
#define MONOPOLY_NOHOUSEEXCEPTION_H


#include "ActualizaPropiedad.h"

namespace Exception {
    class NoHouseException {
    public:
        std::string message;

        NoHouseException(GameBoard::UpgradableProperty * property);
    };
}

#endif
