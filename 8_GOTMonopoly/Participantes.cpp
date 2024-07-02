

#include <sstream>
#include "Participantes.h"
#include "SinExcepcionesPropiedad.h"
#include "Propiedad.h"
using namespace Exception;
using namespace std;

namespace Player {
    Participant::Participant(int participantId, const string &name) : participantId(participantId),
                                                                      name(name) {}

    string Participant::getName()const {
        return name;
    }

    Money & Participant::getMoney() {
        return money;
    }

    vector<GameBoard::Property *> & Participant::getParticipantProperties() {
        return participantProperties;
    }

    void Participant::addParticipantProperty(GameBoard::Property *property) {
        participantProperties.push_back(property);
    }

    int Participant::getCurrentPosition()const {
        return currentPosition;
    }

    void Participant::setCurrentPosition(int currentPosition) {
        Participant::currentPosition = currentPosition;
    }

    int Participant::getSameGroupColourPropertiesAmount(const GameBoard::ColourType colourType) {
        int counter = 0;
        for (auto const &property : participantProperties) {
            if (property->getColourType() == colourType) {
                counter++;
            }
        }
        return counter;
    }

    void Participant::removeProperty(GameBoard::Property *property) {
        participantProperties.erase(remove(participantProperties.begin(), participantProperties.end(), property),
                                    participantProperties.end());
    }

    string Participant::toString() {
        stringstream properties;
        string displayProperties;

        properties << "\nPropiedades actuales: ";
        if (getParticipantProperties().size() == 0) {
            properties << "No tienes nada!";
            displayProperties = properties.str();
        } else {
            for (auto &property : getParticipantProperties()) {
                properties << property->getName() << ", ";
            }
            displayProperties = properties.str().substr(0, properties.str().size() - 2);
        }
        stringstream message;
        message << getName() << " esta en la casilla " << getCurrentPosition() << "\n"
                                                  << "Balance de dinero actual " << getMoney().getBalance()
                                                  << displayProperties;
        return message.str();
    }

    bool Participant::operator==(const Participant &rhs) {
        return this->participantId == rhs.participantId;
    }
}
