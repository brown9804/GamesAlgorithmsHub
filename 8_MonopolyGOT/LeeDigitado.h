
#ifndef MONOPOLY_READINPUT_H
#define MONOPOLY_READINPUT_H

#include <iostream>
#include <limits>

namespace Util {


    int readIntegerWithRange(int lowerRange, int upperRange);

    double readPositiveDoubleWithLimit(double limit);

    std::string readString();

    void pressEnterToContinue();
}
#endif 
