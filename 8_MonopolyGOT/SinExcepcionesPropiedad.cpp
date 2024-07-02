
#include <sstream>
#include "SinExcepcionesPropiedad.h"
using namespace std;

namespace Exception {
    NoPropertyException::NoPropertyException(Player::Participant &participant) {
        stringstream messageCompose;
        messageCompose << participant.getName() << " No tienes propiedades!";
        message = messageCompose.str();
    }
}
