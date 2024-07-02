
#include <map>
#include "Tablero.h"

using namespace GameBoard;
using namespace std;

void GameMechanics::FillBoard::fillGameBoard(vector<Tile *> &gameBoard) {
    gameBoard.push_back(new Tile("Salida"));
    gameBoard.push_back(createPurpleHouse("El Torrion de Craster"));
    gameBoard.push_back(new Xorti("EL TRONO DE HIERRO"));
    gameBoard.push_back(createPurpleHouse("Asidero de los primeros hombre"));
    gameBoard.push_back(new Tax("El consejero de la moneda... Pague", 200));

    gameBoard.push_back(createRailRoad("Casa Lannister"));

    gameBoard.push_back(createLightBlueHouse("El Torrion de Craster"));
    gameBoard.push_back(new Xorti("Fuerte de noche"));
    gameBoard.push_back(createLightBlueHouse("Valar Morghulis"));
    gameBoard.push_back(createLightBlueHouse("Villa Topo"));
    gameBoard.push_back(new Tile("Visita la cárcel"));

    gameBoard.push_back(createVioletHouse("La posada de la encrucijada"));
    gameBoard.push_back(createUtilityHouse("Vaes Dothrak"));
    gameBoard.push_back(createVioletHouse("Redwaste"));
    gameBoard.push_back(createVioletHouse("Quarth"));

    gameBoard.push_back(createRailRoad("Pentos"));

    gameBoard.push_back(createOrangeHouse("Baratheon"));
    gameBoard.push_back(new Xorti("Eyrie"));
    gameBoard.push_back(createOrangeHouse("El trono de hierro"));
    gameBoard.push_back(createOrangeHouse("Dragonstone"));
    gameBoard.push_back(new Parking("Parqueo financiado"));

    gameBoard.push_back(createRedHouse("Harrenhal"));
    gameBoard.push_back(new Xorti("Moat Cailin"));
    gameBoard.push_back(createRedHouse("Valar Morghulis"));
    gameBoard.push_back(createRedHouse("El fuerte terror"));

    gameBoard.push_back(createRailRoad("Casa Frey"));

    gameBoard.push_back(createYellowHouse("Casa Targaryen"));
    gameBoard.push_back(createYellowHouse("Astapor"));
    gameBoard.push_back(createUtilityHouse("Yunkai"));
    gameBoard.push_back(createYellowHouse("El fuerte terror"));
    gameBoard.push_back(new Tile("Cárcel!"));

    gameBoard.push_back(createDarkGreenHouse("Meereen"));
    gameBoard.push_back(createDarkGreenHouse("Castillo Black"));
    gameBoard.push_back(new Xorti("Pyke"));
    gameBoard.push_back(createDarkGreenHouse("El trono de hierro"));

    gameBoard.push_back(createRailRoad("Invernalia"));

    gameBoard.push_back(new Xorti("Casa Stark"));
    gameBoard.push_back(createDarkBlueHouse("Braavos"));
    gameBoard.push_back(new Tax("Mano del rey", 100));
    gameBoard.push_back(createDarkBlueHouse("Desembarco del rey"));
}

void GameMechanics::FillBoard::determinePlayers(vector<Player::Participant *> &participantsPlaying) {
    cout << "Digite la cantidad de jugadores (2 to 8): ";
    int totalPlayers = Util::readIntegerWithRange(MINIMUM_PLAYERS, MAXIMUM_PLAYERS);
    for (int i = 0; i < totalPlayers; i++) {
        cout << "Participante " << i << ", ingrese su nombre: ";
        string participantName = Util::readString();
        participantsPlaying.push_back(new Player::Participant(i, participantName));
    }
}

UpgradableProperty* GameMechanics::FillBoard::createPurpleHouse(string houseName) {
    HousesPrice purpleHousePrice(50, 10, 30, 90, 160);
    return new UpgradableProperty(houseName, 60, 2, Purple, purpleHousePrice, 30);
}

GameBoard::RailRoad* GameMechanics::FillBoard::createRailRoad(string houseName) {
    return new RailRoad(houseName, 200, 25, Black, 100);
}

GameBoard::UpgradableProperty* GameMechanics::FillBoard::createLightBlueHouse(string houseName) {
    HousesPrice lightBlueHousePrice(50, 30, 90, 270, 400);
    return new UpgradableProperty(houseName, 100, 6, Light_Blue, lightBlueHousePrice, 50);
}

GameBoard::UpgradableProperty* GameMechanics::FillBoard::createVioletHouse(string houseName) {
    HousesPrice violetHousePrice(100, 50, 150, 450, 625);
    return new UpgradableProperty(houseName, 140, 10, Violet, violetHousePrice, 70);
}

GameBoard::UtilityProperty* GameMechanics::FillBoard::createUtilityHouse(string houseName) {
    return new UtilityProperty(houseName, 150, 4, White, 75);
}

GameBoard::UpgradableProperty* GameMechanics::FillBoard::createOrangeHouse(string houseName) {
    HousesPrice orangeHousePrice(100, 70, 200, 550, 750);
    return new UpgradableProperty(houseName, 180, 14, Orange, orangeHousePrice, 90);
}

GameBoard::UpgradableProperty* GameMechanics::FillBoard::createRedHouse(string houseName) {
    HousesPrice redHousePrice(150, 90, 250, 700, 875);
    return new UpgradableProperty(houseName, 220, 18, Red, redHousePrice, 110);
}

GameBoard::UpgradableProperty* GameMechanics::FillBoard::createYellowHouse(string houseName) {
    HousesPrice yellowHousePrice(150, 110, 330, 800, 975);
    return new UpgradableProperty(houseName, 260, 22, Yellow, yellowHousePrice, 130);
}

GameBoard::UpgradableProperty* GameMechanics::FillBoard::createDarkGreenHouse(string houseName) {
    HousesPrice darkGreenHousePrice(200, 130, 390, 900, 1100);
    return new UpgradableProperty(houseName, 300, 26, Dark_Green, darkGreenHousePrice, 150);
}

GameBoard::UpgradableProperty* GameMechanics::FillBoard::createDarkBlueHouse(string houseName) {
    HousesPrice darkBlueHousePrice(200, 200, 600, 1400, 1700);
    return new UpgradableProperty(houseName, 350, 35, Dark_Blue, darkBlueHousePrice, 175);
}
