

#ifndef MONOPOLY_HOUSES_H
#define MONOPOLY_HOUSES_H

#include <iostream>

namespace GameBoard {
    class HousesPrice {
    private:
        // To access private variable
        friend std::ostream& operator<<(std::ostream& stream, const HousesPrice& housesPrice);
        const int priceToUpgrade;
        const int oneHouse;
        const int secondHouse;
        const int thirdHouse;
        const int fourHouse;
    public:
        HousesPrice(int priceToUpgrade, int oneHouse, int secondHouse, int thirdHouse, int fourHouse);

        int getHouseRent(int numberOfHouse) const;

        int getPriceToUpgrade() const;
    };
}
#endif 
