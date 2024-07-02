

#include "Propiedad.h"
#include "SinExcepcionesDinero.h"
#include "Bancarota.h"

using namespace Exception;
using namespace std;
using namespace Player;
using namespace GameMechanics;

GameBoard::Property::Property(const string &name, const double propertyPrice,
                              const double rentCost, const ColourType colour, const double mortgage)
        : Tile(name), Mortgage(mortgage), propertyPrice(propertyPrice), rentCost(rentCost), colour(colour){}


void GameBoard::Property::noOwner(Participant *participant, GameMechanics::Game * game) {
    int choice = 0;
    vector<string> noOwnerChoice = {"Detalles de propiedad", "Comprar propiedad", "Es subastado por banco"};

    cout << getName() << " Propiedad en venta por: "<< getPropertyPrice()
         << "!!\nOpciones disponibles: " << endl;
    try {
        while (choice == 0) {
            Util::displayMenu(noOwnerChoice);
            choice = Util::readIntegerWithRange(0, (int) noOwnerChoice.size() - 1);
            if (choice == 0) {
                cout << toString() << endl;
            } else if (choice == 1) {
                buyProperty(participant);
            } else {
                auctionHouse(game);
            }
        }
    } catch (NoMoneyException & exception) {
        cout << exception.message << " Esta casa será subastada" << endl;
        auctionHouse(game);
    }
}

void GameBoard::Property::buyProperty(Participant *participant) {
    try {
        participant->getMoney().subtractBalance(propertyPrice);
        participant->addParticipantProperty(this);
        setOwner(participant);
    } catch (NoMoneyException &exception) {
        throw NoMoneyException(exception.amountDue);
    }
}

void GameBoard::Property::auctionHouse(GameMechanics::Game * game) {
    double currentBid = -1;
    Participant * bidder = nullptr;
    Participant * tempBidder = nullptr;
    string input = "y";

    cout << "Subasta " << getName() << "." << endl;

    while (input[0] == 'Y' || input[0] == 'y')  {
        if (currentBid != -1) {
            cout << "Oferta actual: " << currentBid << endl;
        }
        tempBidder = selectBidder(game->getParticipantsPlaying(), bidder);
       double highestAmount = tempBidder->getMoney().getBalance();
        cout << tempBidder->getName() << " La oferta mas alta es: " << highestAmount << "." <<endl;
        cout << "Ingrese una cantidad mayor o igual que cero: ";
        double amount = Util::readPositiveDoubleWithLimit(tempBidder->getMoney().getBalance());

        if (amount > currentBid) {
            currentBid = amount;
            bidder = tempBidder;
        } else {
            cout << "Es menor que la oferta, no se acepta." << endl;
        }
        cout << "Continua apostando? (Y/n)" << endl;
        getline(cin, input);
    }

    bidder->getMoney().subtractBalance(currentBid);
    bidder->addParticipantProperty(this);
    setOwner(bidder);
    cout << "Felicidades " << bidder->getName() << " por comprar " << getName() << endl;
}

Participant * GameBoard::Property::selectBidder(vector<Participant *> participants, Participant *currentBidder) {

    if (currentBidder != nullptr) {
        participants.erase(remove(participants.begin(), participants.end(), currentBidder), participants.end());
    }
    Util::displayParticipants(participants);
    cout << "Seleccione el número de jugador para apostar" << endl;
    int participantIndex = Util::readIntegerWithRange(0, (int) participants.size() - 1);
    return participants[participantIndex];
}

bool GameBoard::Property::checkIfOwnerHasAllSameColour() {
    return getOwner()->getSameGroupColourPropertiesAmount(getColourType()) == Colour::getGroupColoursSize(getColourType());
}

string GameBoard::Property::getName() {
    if (isPropertyMortgage()) {
        return Tile::getName() + " - Hipoteca";
    }
    return Tile::getName();
}

const GameBoard::ColourType &GameBoard::Property::getColourType() const {
    return colour;
}

double GameBoard::Property::getPropertyPrice() const {
    return propertyPrice;
}

Participant* GameBoard::Property::getOwner() {
    return owner;
}

void GameBoard::Property::setOwner(Participant *owner) {
    Property::owner = owner;
}

void GameBoard::Property::payRent(Participant *participant, GameMechanics::Game *game) {
    double amount = getRentCost(game);

    if (isPropertyMortgage()) {
        cout << "Propiedad esta hipotecada, no hay trato de renta." << endl;
        return;
    }

    try {
        participant->getMoney().subtractBalance(amount);
        getOwner()->getMoney().addBalance(amount);
    } catch (NoMoneyException & exception) {
        cout << exception.message << endl;
        bool isPlayerNotBankrupt = exception.payAmountDue(game, exception.amountDue, participant, getOwner());
        if (!isPlayerNotBankrupt) {
            Bankruptcy::transferProperties(game, participant, getOwner());
        }
    }
}
