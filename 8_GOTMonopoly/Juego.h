

#ifndef MONOPOLY_GAME_H
#define MONOPOLY_GAME_H

#include <vector>
#include <map>
#include "Titulo.h"
#include "Dice.h"
#include "Propiedad.h"
#include "Intercambio.h"
#include "Mover.h"

namespace GameMechanics {
    const double GO_AMOUNT = 200;
    const int TOTAL_TILES = 40;
    const int JAIL_TILE = 10;

    class Game {
    private:

        std::vector<GameBoard::Tile *> gameBoard;

        std::vector<Player::Participant *> participantsPlaying;

        double freeParkingJackpot = 0;

        int diceCount;
    public:

        Game();

        virtual ~Game();

        std::vector<Player::Participant *> &getParticipantsPlaying();

        const std::vector<GameBoard::Tile *> &getGameBoard() const;

        int getDiceCount() const;

        void setDiceCount(int diceCount);

        double getFreeParkingJackpot() const;

        void setFreeParkingJackpot(double freeParkingJackpot);

        void play();

        void manageProperties(Player::Participant* participant, GameMechanics::Game *game);
    };
}
#endif
