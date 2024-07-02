
#ifndef MONOPOLY_FILLBOARD_H
#define MONOPOLY_FILLBOARD_H

#include <vector>
#include "Titulo.h"
#include "Participantes.h"
#include "ActualizaPropiedad.h"
#include "Xorti.h"
#include "Impuestos.h"
#include "UtilidadPropiedad.h"
#include "Parqueo.h"
#include "LeeDigitado.h"
#include "Dice.h"
#include "Ferrocarril.h"
#include "Colores.h"

namespace GameMechanics {

    class FillBoard {
    private:
        const int MINIMUM_PLAYERS = 2;
        const int MAXIMUM_PLAYERS = 8;
    public:

        void fillGameBoard(std::vector<GameBoard::Tile *> &gameBoard);


        void determinePlayers(std::vector<Player::Participant *> &participantsPlaying);
    private:

        GameBoard::UpgradableProperty *createPurpleHouse(std::string houseName);

        GameBoard::RailRoad *createRailRoad(std::string houseName);

        GameBoard::UpgradableProperty *createLightBlueHouse(std::string houseName);

        GameBoard::UpgradableProperty *createVioletHouse(std::string houseName);

        GameBoard::UtilityProperty *createUtilityHouse(std::string houseName);

        GameBoard::UpgradableProperty *createOrangeHouse(std::string houseName);

        GameBoard::UpgradableProperty *createRedHouse(std::string houseName);

        GameBoard::UpgradableProperty *createYellowHouse(std::string houseName);

        GameBoard::UpgradableProperty *createDarkGreenHouse(std::string houseName);

        GameBoard::UpgradableProperty *createDarkBlueHouse(std::string houseName);
    };
}
#endif
