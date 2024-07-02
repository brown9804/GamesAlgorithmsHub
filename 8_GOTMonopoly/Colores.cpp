
#include "Colores.h"
using namespace std;

namespace GameBoard {

    string Colour::getColourInString(ColourType colour) {
        switch (colour) {
            case Black:
                return "Negro";
            case White:
                return "Blanco";
            case Purple:
                return "Morado";
            case Light_Blue:
                return "Celeste";
            case Violet:
                return "Violeta";
            case Orange:
                return "Naranja";
            case Red:
                return "Rojo";
            case Yellow:
                return "Amarillo";
            case Dark_Green:
                return "Verde";
            case Dark_Blue:
                return "Azul";
            default:
                return "Check Colour";
        }
    }

    int Colour::getGroupColoursSize(const GameBoard::ColourType colourType) {
        map<GameBoard::ColourType, int>::iterator it = groupColourSize.find(colourType);
        return it->second;
    }

    std::map<GameBoard::ColourType, int> Colour::groupColourSize = {
            std::pair<ColourType, int> (Black, 4),
            std::pair<ColourType, int> (White, 2),
            std::pair<ColourType, int> (Purple, 2),
            std::pair<ColourType, int> (Light_Blue, 3),
            std::pair<ColourType, int> (Violet, 3),
            std::pair<ColourType, int> (Orange, 3),
            std::pair<ColourType, int> (Red, 3),
            std::pair<ColourType, int> (Yellow, 3),
            std::pair<ColourType, int> (Dark_Green, 3),
            std::pair<ColourType, int> (Dark_Blue, 2)
    };

}
