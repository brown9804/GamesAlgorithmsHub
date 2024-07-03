
#include <sstream>
#include "Propiedad.h"
#include "PropiedadNoActualizada.h"
#include "PropiedadHipotecadaExcepcion.h"
#include "PropiedadSinHipotecaExcepcion.h"
using namespace std;

GameBoard::NonUpgradableProperty::NonUpgradableProperty(const string &name, const double propertyPrice,
                                                        const double rentCost, const ColourType &colour,
                                                        const double mortgage) : Property(name, propertyPrice,
                                                                                          rentCost, colour,
                                                                                          mortgage) {}

void GameBoard::NonUpgradableProperty::doActionWithoutBeingOnProperty(GameMechanics::Game * game) {
    vector<string> displayMenu = {"Mostrando los detalles de las casas", "Propiedad hipotecada", "Quitar hipoteca", "Devolverse"};
    int index;

    try {
        Util::displayMenu(displayMenu);
        index = Util::readIntegerWithRange(0, (int) displayMenu.size() - 1);

        switch(index) {
            case 0: {
                cout << toString() << endl;
                break;
            }
            case 1: {
                makePropertyMortgage(getOwner());
                break;
            }
            case 2: {
                removeMortgage(getOwner());
                break;
            }
            default:break;
        }
    } catch (Exception::PropertyIsNotMortgagedException &propertyNotMortgaged) {
        cout << propertyNotMortgaged.message << endl;
    } catch (Exception::PropertyIsAlreadyMortgageException &propertyIsMortgaged) {
        cout << propertyIsMortgaged.message << endl;
    }
}

string GameBoard::NonUpgradableProperty::toString() {
    stringstream displayProperty;
    displayProperty << "Nombre de la propiedad: " << getName();
    displayProperty << "\nPrecio de la propiedad: " << getPropertyPrice();
    displayProperty << "\nPropietario: ";
    if (getOwner() == nullptr) {
        displayProperty << "Banquero";
    } else {
        displayProperty << getOwner()->getName();
    }
    displayProperty << "\nvalor de la hipoteca: " << getMortgagePrice();
    displayProperty << "\nTipo de color: " << Colour::getColourInString(getColourType());
    displayProperty << "\nNo has contruido casas";
    return displayProperty.str();
}

void GameBoard::NonUpgradableProperty::action(Player::Participant *participant, GameMechanics::Game *game) {
    if (getOwner() == nullptr) {
        noOwner(participant, game);
    } else if (!(getOwner() == participant)) {
        payRent(participant, game);
    }
}
