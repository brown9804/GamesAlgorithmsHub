
#ifndef MONOPOLY_PROPERTYISNOTMORTGAGEDEXCEPTION_H
#define MONOPOLY_PROPERTYISNOTMORTGAGEDEXCEPTION_H

#include <iostream>

namespace Exception {
    class PropertyIsNotMortgagedException {
    public:
        std::string message = "No esta hipotecada!";
    };
}
#endif
