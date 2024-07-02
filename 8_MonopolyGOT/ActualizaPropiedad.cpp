
#include <sstream>
#include "ActualizaPropiedad.h"
#include "SinExcepcionesCasas.h"
#include "SinExcepcionesDinero.h"
#include "Bancarota.h"
#include "PropiedadSinHipotecaExcepcion.h"
#include "PropiedadHipotecadaExcepcion.h"

using namespace Exception;
using namespace std;

GameBoard::UpgradableProperty::UpgradableProperty(const string &name, const double propertyPrice, const double rentCost,
                                                  const ColourType &colour, const GameBoard::HousesPrice housesPrice,
                                                  const double mortgage) :
        Property(name, propertyPrice, rentCost, colour, mortgage), housesPrice(housesPrice) {}

string GameBoard::UpgradableProperty::getName() {
    string houseUpgrade;
    if (isPropertyMortgage()) {
        return Tile::getName() + " - Hipoteca";
    }
    for (int i = 0; i < getCurrentHousesBuild(); i++) {
        houseUpgrade += "*";
    }
    return Tile::getName() + houseUpgrade;
}

void GameBoard::UpgradableProperty::action(Player::Participant *participant, GameMechanics::Game * game) {
    if (getOwner() == nullptr) {
        noOwner(participant, game);
    } else if (getOwner() == participant) {
        // Upgrade hotel
        if (checkIfOwnerHasAllSameColour()) {
            addHouseToProperty(participant);
        } else {
            cout << "La mejora de la casa no está disponible actualmente. No tienes todas las propiedades. "
                    "de los mismos colores" << endl;
        }
    } else {
        payRent(participant, game);
    }
}

void GameBoard::UpgradableProperty::addHouseToProperty(Player::Participant *participant) {
    string input;

    if (isPropertyMortgage()) {
        cout << "Tienes todos los mismos colores de grupo, pero esta propiedad está hipotecada!" << endl;
    } else {
        cout << housesPrice << endl;
        cout << "Quieres actualizar la casa? (Y/n)" << endl;
        getline(cin, input);
        try {
            if (input[0] == 'y' || input[0] == 'Y') {
                int currentHouseBuild = getCurrentHousesBuild();
                // Limit of houses
                if (currentHouseBuild < MAX_HOUSES) {
                    participant->getMoney().subtractBalance(getHousesPrice().getPriceToUpgrade());
                    setCurrentHousesBuild(getCurrentHousesBuild() + 1);
                } else {
                    cout << "Limite máximo de casas." << endl;
                }
            }
        } catch (NoMoneyException &noMoneyException) {
            cout << noMoneyException.message << " Devolviendo al menu anterior." << endl;
        }
    }
}

void GameBoard::UpgradableProperty::removeHouseFromProperty(Player::Participant *participant) {
    double amount;
    string input;
    if (getCurrentHousesBuild() == 0) {
        throw NoHouseException(this);
    }
    amount = getHousesPrice().getPriceToUpgrade() / 2;
    cout << "¿Realmente quieres remover una casa? Usted recibirá la mitad del costo (" << amount
         << ")tomado para ser contruido. (Y/n)" << endl;
    getline(cin, input);
    if (input[0] == 'Y' || input[0] == 'y') {
        setCurrentHousesBuild(getCurrentHousesBuild() - 1);
        participant->getMoney().addBalance(getHousesPrice().getPriceToUpgrade() / 2);
    }
}

void GameBoard::UpgradableProperty::doActionWithoutBeingOnProperty(GameMechanics::Game *game) {
    vector<string> displayMenu = {"Detalles de propiedad", "Venta de casas", "Agrega hipoteca", "Remueve hipoteca",
                                  "Devolviendo al menu principal"};
    int selection;

    Util::displayMenu(displayMenu);
    selection = Util::readIntegerWithRange(0, (int) displayMenu.size() - 1);

    try {
        switch (selection) {
            case 0: {
                cout << toString() << endl;
                break;
            }
            case 1: {
                removeHouseFromProperty(getOwner());
                break;
            }
            case 2: {
                makePropertyMortgage(getOwner());
                break;
            }
            case 3: {
                removeMortgage(getOwner());
                break;
            }
            default:break;
        }
    } catch(NoHouseException & exception) {
        cout << exception.message << " Devolviendo al menu" << endl;
    } catch (PropertyIsNotMortgagedException &propertyNotMortgaged) {
        cout << propertyNotMortgaged.message << endl;
    } catch (PropertyIsAlreadyMortgageException &propertyIsMortgaged) {
        cout << propertyIsMortgaged.message << endl;
    }
}

double GameBoard::UpgradableProperty::getRentCost(GameMechanics::Game *game) {
    int currentHousesBuild = getCurrentHousesBuild();
    // If no hotel and does not own same colour properties
    if (currentHousesBuild == 0 && !checkIfOwnerHasAllSameColour()) {
        return rentCost;
    } else if (currentHousesBuild == 0) {
        // Owner has same colour properties but no house, thus pay double rent
        cout << "El propietario  " << getColourType() << " tiene todas las propiedades. Pague doble la renta!!" << endl;
        return rentCost * 2;
    } else {
        return getHousesPrice().getHouseRent(currentHousesBuild);
    }
}

string GameBoard::UpgradableProperty::toString() {
    stringstream displayProperty;
    displayProperty << "Nombre de la propiedad: " << getName();
    displayProperty << "\nPrecio de la propiedad: " << getPropertyPrice();
    displayProperty << "\nPropietario: ";
    if (getOwner() == nullptr) {
        displayProperty << "Banquero";
    } else {
        displayProperty << getOwner()->getName();
    }
    displayProperty << "\nValor de la hipoteca: " << getMortgagePrice();
    displayProperty << "\nTipo de color: " << Colour::getColourInString(getColourType());
    displayProperty << "\n" << getHousesPrice();
    return displayProperty.str();
}

void GameBoard::UpgradableProperty::setCurrentHousesBuild(int currentHousesBuild) {
    UpgradableProperty::currentHousesBuild = currentHousesBuild;
}

int GameBoard::UpgradableProperty::getCurrentHousesBuild() const {
    return currentHousesBuild;
}

const GameBoard::HousesPrice &GameBoard::UpgradableProperty::getHousesPrice() const {
    return housesPrice;
}
