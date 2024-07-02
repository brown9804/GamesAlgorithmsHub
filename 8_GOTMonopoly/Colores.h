

#ifndef MONOPOLY_COLOURS_H
#define MONOPOLY_COLOURS_H

#include <iostream>
#include <map>

namespace GameBoard {
    enum ColourType {
        Black, White, Purple, Light_Blue, Violet, Orange, Red, Yellow, Dark_Green, Dark_Blue
    };

    class Colour {
    private:

        static std::map<GameBoard::ColourType, int> groupColourSize;
    public:

        static std::string getColourInString(ColourType colour);

        static int getGroupColoursSize(const GameBoard::ColourType colourType);
    };
}
#endif
