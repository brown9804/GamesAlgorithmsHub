
#include "Ferrocarril.h"
#include "SinExcepcionesDinero.h"
#include "Bancarota.h"
#include <math.h>
using namespace Exception;
using namespace std;

GameBoard::RailRoad::RailRoad(const string &name, const double propertyPrice,
                              const double rentCost, const ColourType &colour, const double mortgage)
        : NonUpgradableProperty(name, propertyPrice, rentCost, colour, mortgage) {}


double GameBoard::RailRoad::getRentCost(GameMechanics::Game *game) {
    int numberOfRailRoad = getOwner()->getSameGroupColourPropertiesAmount(getColourType());
    cout << "El propietario tiene en total " << numberOfRailRoad << " ferrocarril(es)" << endl;
    return pow(2, (double) numberOfRailRoad - 1) * 25;
}
