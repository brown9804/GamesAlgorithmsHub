
#ifndef MONOPOLY_DICE_H
#define MONOPOLY_DICE_H

#include <utility>
namespace GameMechanics {

    class Dice {
    private:
        const int MINIMUM_DICE = 1;
        const int MAXIMUM_DICE = 6;
        std::pair<int, int> diceRoll;
    public:

        std::pair<int, int> *generateNewDiceRoll();

        std::pair<int, int> *getCurrentDiceRoll();
    };
}
#endif 
