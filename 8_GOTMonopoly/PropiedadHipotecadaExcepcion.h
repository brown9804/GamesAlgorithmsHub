
#ifndef MONOPOLY_HOUSEISALREADYMORTGAGEEXCEPTION_H
#define MONOPOLY_HOUSEISALREADYMORTGAGEEXCEPTION_H

#include <iostream>

namespace Exception {
    class PropertyIsAlreadyMortgageException {
    public:
        std::string message = "La casa ya está hipotecada!";
    };
}


#endif 
