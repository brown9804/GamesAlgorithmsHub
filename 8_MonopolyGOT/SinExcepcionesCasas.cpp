
#include <sstream>
#include "SinExcepcionesCasas.h"

Exception::NoHouseException::NoHouseException(GameBoard::UpgradableProperty * property) {
    std::stringstream messageCompose;
    messageCompose << property->getName() << " no tienes casa! * indica cual propiedad tiene casas!";
    message = messageCompose.str();
}
