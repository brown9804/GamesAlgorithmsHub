
#include <sstream>
#include "SinExcepcionesDinero.h"

using namespace GameMechanics;
using namespace std;
using namespace Player;

namespace Exception {
    NoMoneyException::NoMoneyException(double amountDue) : amountDue(amountDue) {
        stringstream messageCompose;
        messageCompose << "No tienes dinero, necesitas " << amountDue << " efectivo.";
        message = messageCompose.str();
    }

    bool NoMoneyException::payAmountDue(GameMechanics::Game *game, double amountDue, Participant *debitor,
                                        Participant *creditor) {
        int selection = 0;
        bool amountIsPaid = false;
        vector<string> displayMenu = {"Rastro", "Manejo de propiedades", "Pagando debito", "Declaro Bancarota"};

        cout << debitor->getName() << " Necesitas conseguir dinero!!" << endl;
        while (!amountIsPaid) {
            Util::displayMenu(displayMenu);
            selection = Util::readIntegerWithRange(0, (int) displayMenu.size() - 1);
            switch (selection) {
                case 0: {
                    Trade::tradePropertySellerKnown(game, debitor);
                    break;
                }
                case 1: {
                    game->manageProperties(debitor, game);
                    break;
                }
                case 2: {
                    amountIsPaid = payDebt(amountDue, debitor, creditor);
                    break;
                }
                case 3: {
                    return false;
                }
            }
        }
        return true;
    }

    bool NoMoneyException::payDebt(double amountDue, Participant *debitor, Participant *creditor) {
        try {
            debitor->getMoney().subtractBalance(amountDue);
            if (creditor != nullptr) {
                creditor->getMoney().addBalance(amountDue);
            }
            return true;
        } catch (NoMoneyException &exception) {
            cout << exception.message << endl;
            return false;
        }
    }
}
