#include <fstream>
#include "Monopoly.h"
#include "Juego.h"
using namespace std;

void Monopoly::start() {
    vector<string> displayMenu = {"Juego", "Guía del juego", "Salir"};
    int selection = 0;

    cout << "Bienvenido a Mono\033[1;31mOOP\033[0moly de Games of Thrones!" << endl;
    while (selection != (int) displayMenu.size() - 1) {
        Util::displayMenu(displayMenu);
        selection = Util::readIntegerWithRange(0, (int) displayMenu.size() - 1);
        switch (selection) {
            case 0: {
                play();
                break;
            }
            case 1: {
                userManual();
                break;
            }
            default:break;
        }
    }
}

void Monopoly::play() {
    GameMechanics::Game game;
    game.play();
}

void Monopoly::userManual() {
    vector<string> displayMenu = {"Objetivo del juego", "Preparación", "El banco", "El juego", "Jugar!!", "Compra de propiedades",
                                  "Pago de renta", "Xorti", "Impuestos", "Parqueo Gratis", "Casas", "Vender propiedades",
                                  "Hipotecas", "Bancarota", "Devolverse"};
    int selection = 0;
    cout << "El menú incluye las reglas del monopolio clásico con algunas modificaciones para que su temática sea de Juego de Trones. "
            "\nsi se omite un capitulo, es porque las reglas son las mismas." << endl;

    while (true) {
        Util::displayMenu(displayMenu);
        selection = Util::readIntegerWithRange(0, (int) displayMenu.size() - 1);
        if (selection == (int) displayMenu.size() - 1) {
            break;
        }
        readFromFile(selection);
        Util::pressEnterToContinue();
    }
}

void Monopoly::readFromFile(int chapterNumber) {
    ifstream file("UserManual.txt");
    string readFromFile;
    int counter = 0;
    if (file) {
        while (getline(file, readFromFile)) {
            // Print the specific chapter
            if (counter == chapterNumber) {
                cout << readFromFile << endl;
            }
            // Each chapter is marked with an empty line
            if (readFromFile.empty()) {
                counter++;
            }
        }
    } else {
        cout << "Error al abrir el archivo!" << endl;
    }
    // Close file
    file.close();
}
