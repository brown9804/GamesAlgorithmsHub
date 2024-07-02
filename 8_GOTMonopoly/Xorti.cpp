
#include "Xorti.h"
#include "SinExcepcionesDinero.h"
#include "Bancarota.h"
using namespace Exception;
using namespace std;
using namespace GameMechanics;

GameBoard::Xorti::Xorti(const string &name) : Tile(name) {}

void GameBoard::Xorti::action(Player::Participant * participant, GameMechanics::Game * game) {
    int xorti = rand() % MAXIMUM_XORTI;
    try {
        if (xorti == 0) {
            birthday(*participant, game);
        } else if (xorti == 1) {
            parkingFine(*participant, game);
        } else if (xorti == 2) {
            mepaFine(*participant, game);
        } else {
            moveToRandomPlace(*participant, game);
        }
    } catch (NoMoneyException & exception) {
        cout << exception.message << endl;

        bool isPlayerNotBankrupt = exception.payAmountDue(game, exception.amountDue, participant, nullptr);

        if (!isPlayerNotBankrupt) {
            Bankruptcy::transferProperties(game, participant, nullptr);
        }
    }
}

void GameBoard::Xorti::birthday(Player::Participant &participant, GameMechanics::Game * game) {
    double birthdayMoney = rand() % (MAXIMUM_BIRTHDAY_PRICE - MINIMUM_BIRTHDAY_PRICE) + MINIMUM_BIRTHDAY_PRICE;
    std::cout << "Es tu celebracion tome " << birthdayMoney << " un regalo de todos." << std::endl;

    for (auto &player : game->getParticipantsPlaying()) {
        if (player == &participant) {
            continue;
        }
        try {
            player->getMoney().subtractBalance(birthdayMoney);
            participant.getMoney().addBalance(birthdayMoney);
        } catch (NoMoneyException &noMoneyException) {
            cout << noMoneyException.message << endl;
            bool isPlayerNotBankrupt = noMoneyException.payAmountDue(game, noMoneyException.amountDue, player, &participant);
            if (!isPlayerNotBankrupt) {
                Bankruptcy::transferProperties(game, player, &participant);
            }
        }
    }
}

void GameBoard::Xorti::parkingFine(Player::Participant &participant, GameMechanics::Game * game) {
    double parkingFine = rand() % (MAXIMUM_PARKING_FINE - MINIMUM_PARKING_FINE) + MINIMUM_PARKING_FINE;
    std::cout << "Te estacionaste en el lugar de un profesor! Fuiste multado " << parkingFine << "." << std::endl;
    try {
        participant.getMoney().subtractBalance(parkingFine);
        game->setFreeParkingJackpot(game->getFreeParkingJackpot() + parkingFine);
    } catch (NoMoneyException & noMoneyException) {
        throw NoMoneyException(noMoneyException.amountDue);
    }
}

void GameBoard::Xorti::mepaFine(Player::Participant &participant, GameMechanics::Game * game) {
    double mepaFine = rand() % (MAXIMUM_MEPA_FINE - MINIMUM_MEPA_FINE) + MINIMUM_MEPA_FINE;
    double totalFine = mepaFine * participant.getParticipantProperties().size();
    std::cout << "MEPA te multó !!! Fuiste multado en total: " << totalFine << ". Tienes en total "
              << participant.getParticipantProperties().size() << " edificios... cada edificio fue multado "
              << mepaFine << "." << std::endl;
    // If participant does not have enough money, handle the exception in action method
    try {
        participant.getMoney().subtractBalance(totalFine);
        game->setFreeParkingJackpot(game->getFreeParkingJackpot() + totalFine);
    } catch (NoMoneyException & noMoneyException) {
        throw NoMoneyException(noMoneyException.amountDue);
    }
}

void GameBoard::Xorti::moveToRandomPlace(Player::Participant &participant, GameMechanics::Game * game) {
    participant.setCurrentPosition(rand() % GameMechanics::TOTAL_TILES);
    std::cout << "¡Te movieron a una ubicación aleatoria! Nueva ubicación es: "
              << game->getGameBoard()[participant.getCurrentPosition()]->getName() << std::endl;
}
