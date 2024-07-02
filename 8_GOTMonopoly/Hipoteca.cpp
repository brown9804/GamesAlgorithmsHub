
#include "Hipoteca.h"
#include "Participantes.h"
#include "PropiedadHipotecadaExcepcion.h"
#include "SinExcepcionesDinero.h"
#include "PropiedadSinHipotecaExcepcion.h"
using namespace Exception;
using namespace std;

GameBoard::Mortgage::Mortgage(double mortgagePrice) : mortgagePrice(mortgagePrice) {}

bool GameBoard::Mortgage::isPropertyMortgage() const {
    return propertyMortgage;
}

double GameBoard::Mortgage::getMortgagePrice() const {
    return mortgagePrice;
}

void GameBoard::Mortgage::makePropertyMortgage(Player::Participant *participant) {
    string input;

    if (isPropertyMortgage()) {
        throw PropertyIsAlreadyMortgageException();
    }

    cout << "Vas a recibir " << getMortgagePrice() << "por hipotecar esta casa. Acepta? (Y/n)" << endl;
    getline(cin, input);

    if (input[0] == 'Y' || input[0] == 'y') {
        participant->getMoney().addBalance(mortgagePrice);
        propertyMortgage = true;
    }
}

void GameBoard::Mortgage::removeMortgage(Player::Participant *participant) {
    string input;
    double amount = mortgagePrice * INTEREST_PERCENTAGE;

    if (!isPropertyMortgage()) {
        throw PropertyIsNotMortgagedException();
    }

    cout << "Quitar la hipoteca le va a costar: " << amount << ". Acepta? (Y/n)" << endl;
    getline(cin, input);

    try {
        if (input[0] == 'Y' || input[0] == 'y') {
            participant->getMoney().subtractBalance(amount);
            propertyMortgage = false;
        }
    } catch (NoMoneyException &exception) {
        cout << exception.message << " Devolviendo al menú anterior." << endl;
    }
}
