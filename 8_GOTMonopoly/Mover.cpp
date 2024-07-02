
#include "Mover.h"
using namespace Player;
using namespace std;

void GameMechanics::Move::move(Game * game, Participant * participant, Dice *dice) {
    Move move;
    bool anotherTurnForPlayer = true;
    unsigned long totalParticipants = game->getParticipantsPlaying().size();
    int counter = 0;
    int newLocation;

    while (anotherTurnForPlayer) {
        game->setDiceCount(move.generateDiceCount(dice));
        anotherTurnForPlayer = move.checkDiceDouble(dice);
        if (counter == 2 && anotherTurnForPlayer) {
            cout << "Vas para la cárcel!!" << endl;
            participant->setCurrentPosition(JAIL_TILE);
            Util::pressEnterToContinue();
            break;
        }
        newLocation = move.determineParticipantLocation(game, participant, game->getDiceCount());
        // Get the Tile where the participant landed and do the tile action.
        game->getGameBoard()[newLocation]->action(participant, game);
        // If a player went bankrupt, he cannot have another turn thus stop moving.
        if (totalParticipants != game->getParticipantsPlaying().size()) {
            return;
        }
        counter++;
        Util::pressEnterToContinue();
    }
}

int GameMechanics::Move::determineParticipantLocation(Game * game, Participant *participant, int diceCount) {
    int newLocation = participant->getCurrentPosition() + diceCount;
    validateGoFunds(participant, newLocation);
    newLocation %= TOTAL_TILES;
    participant->setCurrentPosition(newLocation);
    cout << participant->getName() << " movido a la casilla "
         << game->getGameBoard()[newLocation]->getName()
         << endl;
    return newLocation;
}

void GameMechanics::Move::validateGoFunds(Participant *participant, int location) {
    if (location >= TOTAL_TILES) {
        cout << "se agregaron fondos!!" << endl;
        participant->getMoney().addBalance(GO_AMOUNT);
        Util::pressEnterToContinue();
    }
}

bool GameMechanics::Move::checkDiceDouble(GameMechanics::Dice *dice) {
    pair<int, int> * diceRoll = dice->getCurrentDiceRoll();
    if (diceRoll->first == diceRoll->second) {
        cout << "Vuelve a tirar los dados!!" << endl;
        return true;
    }
    return false;
}

int GameMechanics::Move::generateDiceCount(GameMechanics::Dice *dice) {
    pair<int,int> * diceRoll = dice->generateNewDiceRoll();
    cout << "DADOS: " << diceRoll->first << ", " << diceRoll->second << endl;
    return diceRoll->first + diceRoll->second;
}
