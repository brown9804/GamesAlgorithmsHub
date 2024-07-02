
#ifndef MONOPOLY_PARTICIPANT_H
#define MONOPOLY_PARTICIPANT_H

#include <vector>
#include <iostream>
#include <map>
#include "Dinero.h"
#include "Colores.h"
#include <algorithm>

namespace GameBoard {
    class Property;
}

namespace Player {

    class Participant {
    private:
        const double MONEY_TO_START = 1500;
        int participantId;
        int currentPosition = 0;
        std::string name;


        Money money = Money(name, MONEY_TO_START);

        std::vector<GameBoard::Property *> participantProperties;
    public:
        Participant(int participantId, const std::string &name);

        std::string getName()const;

        int getCurrentPosition()const;

        void setCurrentPosition(int currentPosition);

        Money & getMoney();

        std::vector<GameBoard::Property *> & getParticipantProperties();

        void addParticipantProperty(GameBoard::Property *property);

        void removeProperty(GameBoard::Property *property);

        int getSameGroupColourPropertiesAmount(GameBoard::ColourType colourType);

        std::string toString();

        bool operator==(const Participant &rhs);
    };
}
#endif
