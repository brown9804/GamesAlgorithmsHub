
#include "Juego.h"
#include "Tablero.h"
#include "SinExcepcionesPropiedad.h"
#include "PropiedadHipotecadaExcepcion.h"
using namespace Exception;
using namespace std;
using namespace Player;

GameMechanics::Game::Game() {
    FillBoard fillBoard;
    fillBoard.fillGameBoard(gameBoard);
    fillBoard.determinePlayers(participantsPlaying);
}

void GameMechanics::Game::play() {
    Dice dice;
    unsigned long size;
    unsigned long round = 0;
    vector<string> displayMenu = {"Intercambio", "Manejo de propiedades", "Perfil del jugador", "Mover"};

    while (true) {
        cout << "| Ronda: " << ++round << " |" << endl;

        for (vector<Player::Participant>::size_type i = 0; i != participantsPlaying.size(); i++) {
            size = participantsPlaying.size();

            cout << "\033[1;31m" << participantsPlaying[i]->getName() << "\n su turno." << "\033[0m" << endl;
            int selection = 0;

            while (selection != (int) displayMenu.size() - 1) {
                Util::displayMenu(displayMenu);
                selection = Util::readIntegerWithRange(0, (int) displayMenu.size() - 1);
                switch (selection) {
                    case 0: {
                        Trade::tradePropertyBuyerKnown(this, participantsPlaying[i]);
                        break;
                    }
                    case 1: {
                        manageProperties(participantsPlaying[i], this);
                        break;
                    }
                    case 2: {
                        cout << participantsPlaying[i]->toString() << endl;
                        break;
                    }
                    default:break;
                }
            }

            Move::move(this, participantsPlaying[i], &dice);

            if (size != participantsPlaying.size()) {
                i--;
            }
        }

        if (participantsPlaying.size() == 1) {
            break;
        }
        cout << "Nueva ruta!!" << endl;
        Util::pressEnterToContinue();
    }
    cout << "Felicidades " << participantsPlaying[0]->getName() << " has ganado!" << endl;
}

void GameMechanics::Game::manageProperties(Participant *participant, GameMechanics::Game *game) {
    string input;
    try {
        std::vector<GameBoard::Property *> &properties = participant->getParticipantProperties();
        Util::displayHousesForParticipant(participant);
        int sellBuildingPropertyIndex = Util::readIntegerWithRange(0, (int) properties.size() - 1);
        GameBoard::Property * property = properties[sellBuildingPropertyIndex];
        property->doActionWithoutBeingOnProperty(game);
    } catch (NoPropertyException &exception) {
        cout << exception.message << " Devolviendo a la pantalla principal" << endl;
    }
}

vector<Participant *> &GameMechanics::Game::getParticipantsPlaying() {
    return participantsPlaying;
}

int GameMechanics::Game::getDiceCount() const {
    return diceCount;
}

double GameMechanics::Game::getFreeParkingJackpot() const {
    return freeParkingJackpot;
}

void GameMechanics::Game::setFreeParkingJackpot(double freeParkingJackpot) {
    Game::freeParkingJackpot = freeParkingJackpot;
}

const vector<GameBoard::Tile *> &GameMechanics::Game::getGameBoard() const {
    return gameBoard;
}

void GameMechanics::Game::setDiceCount(int diceCount) {
    Game::diceCount = diceCount;
}

GameMechanics::Game::~Game() {
    for (auto &tile : gameBoard) {
        delete tile;
    }
    for (auto &participant : participantsPlaying) {
        delete participant;
    }
}
