
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Intercambio.h"
#include "SinExcepcionesPropiedad.h"
#include "SinExcepcionesDinero.h"

using namespace Exception;
using namespace Player;
using namespace std;

void GameMechanics::Trade::tradePropertyBuyerKnown(GameMechanics::Game *game, Participant *buyer) {
    Trade trade;
    cout << "¿Con quien quiere intercambiar?" << endl;
    Participant * seller = trade.determineTrader(game->getParticipantsPlaying(), buyer);
    try {

        vector<GameBoard::Property *> &allParticipantsProperties= seller->getParticipantProperties();
        Util::displayHousesForParticipant(seller);
        int indexOfHouseToBuy = Util::readIntegerWithRange(0, (int) allParticipantsProperties.size() - 1);
        trade.transactionTrade(buyer, seller, allParticipantsProperties[indexOfHouseToBuy]);
    } catch(NoPropertyException &exception) {
        cout << exception.message << " Cancelando intercambio." << endl;
        return;
    }
}

void GameMechanics::Trade::tradePropertySellerKnown(GameMechanics::Game *game, Participant *seller) {
    Trade trade;
    cout << "Alguien quiere intercambiar con usted " << seller->getName() << "?" << endl;
    Participant * buyer = trade.determineTrader(game->getParticipantsPlaying(), seller);
    try {

        vector<GameBoard::Property *> &allParticipantProperties = seller->getParticipantProperties();
        Util::displayHousesForParticipant(seller);
        int indexOfHouseToBuy = Util::readIntegerWithRange(0, (int) allParticipantProperties.size() - 1);
        trade.transactionTrade(buyer, seller, allParticipantProperties[indexOfHouseToBuy]);
    } catch(NoPropertyException &exception) {
        cout << exception.message << " Cancelando intercambio." << endl;
        return;
    }
}

Participant *GameMechanics::Trade::determineTrader(vector<Participant *> participants, Participant *trader) {
    participants.erase(remove(participants.begin(), participants.end(), trader), participants.end());
    Util::displayParticipants(participants);
    int indexOfParticipant = Util::readIntegerWithRange(0, (int) participants.size() - 1);
    return participants[indexOfParticipant];
}

void GameMechanics::Trade::transactionTrade(Participant *buyer, Participant *seller,
                                            GameBoard::Property *propertyForSale) {
    set<GameBoard::Property *> propertiesOffered;
    vector<string> displayTradeOptions = {"Ofrece nueva cantidad de dinero", "Ofrece propiedad(Puedes ofrecer varias propiedades)",
                                          "Hacer una transacción", "Quitar transacción"};
    double cashOffered = 0;
    int offerChoice = 0;

    cout << buyer->getName() << " solicitud para comprar " << propertyForSale->getName() << " para " << seller->getName()
         << "." << endl;
    while (offerChoice != 3) {
        cout << buyerOffer(buyer, cashOffered, propertiesOffered) << endl;
        Util::displayMenu(displayTradeOptions);
        offerChoice = Util::readIntegerWithRange(0, (int) displayTradeOptions.size() - 1);
        switch (offerChoice) {
            case 0: {
                cashOffered = offerCash(buyer);
                break;
            }
            case 1: {
                GameBoard::Property *property = offerProperty(buyer);
                if (property != nullptr) {
                    propertiesOffered.insert(property);
                }
                break;
            }
            case 2:  {
                if(makeTransaction(buyer, seller, cashOffered, propertiesOffered, propertyForSale)) {
                    return;
                }
                break;
            }
            default:
                return;
        }
    }
}

double GameMechanics::Trade::offerCash(Participant *buyer) {
    double highestOffer = buyer->getMoney().getBalance();
    cout << buyer->getName() << " la oferta mas alta es" << highestOffer << "." << endl;
    cout << "Digite la cantidad: ";
    return Util::readPositiveDoubleWithLimit(highestOffer);
}

GameBoard::Property *GameMechanics::Trade::offerProperty(Participant *buyer) {
    try {
        vector<GameBoard::Property *> &allParticipantProperty = buyer->getParticipantProperties();
        Util::displayHousesForParticipant(buyer);
        int indexOfHouseToOffer = Util::readIntegerWithRange(0, (int) allParticipantProperty.size() - 1);
        GameBoard::Property * property = allParticipantProperty[indexOfHouseToOffer];
        return property;
    } catch(NoPropertyException &exception) {
        cout << exception.message << " Cancelando la oferta de propiedad. (solo con efectivo)" << endl;
        return nullptr;
    }
}

bool GameMechanics::Trade::makeTransaction(Participant *buyer, Participant *seller, double cashOffered,
                                           set<GameBoard::Property *> propertiesOffered,
                                           GameBoard::Property *propertyForSale) {
    string input;
    cout << buyerOffer(buyer, cashOffered, propertiesOffered) << endl;
    cout << seller->getName() << " aceptas la oferta? (Y/n)" << endl;
    getline(cin, input);
    if (input[0] == 'y' || input[0] == 'Y') {
        // Add cash to seller
        try {
            if (cashOffered != 0) {
                buyer->getMoney().subtractBalance(cashOffered);
                seller->getMoney().addBalance(cashOffered);
            }
        } catch (NoMoneyException &noMoneyException) {
            // The NoMoneyException can never be triggered since user can only enter an amount
            // that he has.
            cout << noMoneyException.message << endl;
            return false;
        }
        // Set properties to new owner. Buyer offered properties to seller
        if (propertiesOffered.size() != 0) {
            for (auto &property : propertiesOffered) {
                property->setOwner(buyer);
                seller->addParticipantProperty(property);
                buyer->removeProperty(property);
            }
        }
        // Set property actually trade to new owner
        propertyForSale->setOwner(buyer);
        seller->removeProperty(propertyForSale);
        buyer->addParticipantProperty(propertyForSale);
        return true;
    } else {
        cout << "Oferta rechazada, ¿ofrece mas?" << endl;
        return false;
    }
}

string GameMechanics::Trade::buyerOffer(Participant *buyer, double cashOffered,
                                        set<GameBoard::Property *> &propertiesOffered) {
    stringstream buyerOffer;
    buyerOffer << buyer->getName() << " Ofrece: ";
    if (cashOffered == 0 && propertiesOffered.size() == 0) {
        buyerOffer << "Nada";
    } else {
        if (cashOffered != 0) {
            buyerOffer << "Cantidad de dinero: " << cashOffered;
        }
        if (propertiesOffered.size() != 0) {
            buyerOffer << " Propiedades: ";
            for (auto & property : propertiesOffered) {
                buyerOffer << property->getName() << ", ";
            }
            return buyerOffer.str().substr(0, buyerOffer.str().size() - 2);
        }
    }
    return buyerOffer.str();
}
