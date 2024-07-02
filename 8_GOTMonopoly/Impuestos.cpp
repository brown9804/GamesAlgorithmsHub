

#include "Impuestos.h"
#include "SinExcepcionesDinero.h"
#include "Bancarota.h"
using namespace Exception;
using namespace std;

GameBoard::Tax::Tax(const string &name, const int &taxAmount) : Tile(name), taxAmount(taxAmount) {}

void GameBoard::Tax::action(Player::Participant *participant, GameMechanics::Game * game) {
    try {
        participant->getMoney().subtractBalance(taxAmount);
        game->setFreeParkingJackpot(game->getFreeParkingJackpot() + taxAmount);
    } catch (NoMoneyException & exception) {
        cout << exception.message << endl;
        bool isPlayerNotBankrupt = exception.payAmountDue(game, exception.amountDue, participant, nullptr);
        if (!isPlayerNotBankrupt) {
            GameMechanics::Bankruptcy::transferProperties(game, participant, nullptr);
        }
    }
}
