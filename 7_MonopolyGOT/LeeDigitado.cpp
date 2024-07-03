
#include "LeeDigitado.h"

using namespace std;

int Util::readIntegerWithRange(int lowerRange, int upperRange) {
    string number;
    while(true) {
        try {
            getline(cin, number);
            int givenNumber = stoi(number);
            if (givenNumber >= lowerRange && givenNumber <= upperRange) {
                return givenNumber;
            } else {
                cout << "Es inválido,no está en rango intente de nuevo" << endl;
            }
        }
        catch (invalid_argument error) {
            cout << "Intente otra vez" << endl;
        }
        catch (out_of_range) {
            cout << "Es inválido,no está en rango intente de nuevo." << endl;
        };
    }
}

string Util::readString() {
    string input;
    while (true) {
        getline(cin, input);
        if (!input.empty()) {
            return input;
        }
        cout << "Intente otra vez." << endl;
    }
}

double Util::readPositiveDoubleWithLimit(double limit) {
    string number;
    while(true) {
        try {
            getline(cin, number);
            double givenNumber = stod(number);
            if (givenNumber >= 0 && givenNumber <= limit) {
                return givenNumber;
            } else {
                cout << "Es inválido,no está en rango intente de nuevo." << endl;
            }
        }
        catch (invalid_argument error) {
            cout << "Intente otra vez" << endl;
        }
        catch (out_of_range) {
            cout << "Es inválido,no está en rango intente de nuevo." << endl;
        };
    }
}

void Util::pressEnterToContinue() {
    cout << "Presione Enter para continuar";
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}
