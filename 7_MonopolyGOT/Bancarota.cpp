
#include "Bancarota.h"
#include <algorithm>
using namespace Player;
using namespace std;

void GameMechanics::Bankruptcy::transferProperties(GameMechanics::Game * game, Player::Participant *currentOwner, Player::Participant *newOwner) {
    vector<Participant *> &participantsPlaying = game->getParticipantsPlaying();
    vector<GameBoard::Property *> &participantProperties = currentOwner->getParticipantProperties();
    double moneyAmount = currentOwner->getMoney().getBalance();

    participantsPlaying.erase(remove(participantsPlaying.begin(), participantsPlaying.end(), currentOwner),
                              participantsPlaying.end());

    if (participantsPlaying.size() != 1) {
        cout << "Borrando " << currentOwner->getName() << " los sombrantes." << endl;
        if (moneyAmount > 0 && newOwner != nullptr) {
            newOwner->getMoney().addBalance(moneyAmount);
        }

        for (auto &property : participantProperties) {
            if (newOwner == nullptr) {
                property->auctionHouse(game);
            } else {
                cout << "Transfiriendo " << property->getName() << " a " << newOwner->getName() << endl;
                newOwner->addParticipantProperty(property);
                currentOwner->removeProperty(property);
            }
        }
    }
    cout << "Gracias por jugar " << currentOwner->getName() << "!!" << endl;
    delete currentOwner;
}
