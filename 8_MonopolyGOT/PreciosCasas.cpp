
#include "PreciosCasas.h"

namespace GameBoard {
    HousesPrice::HousesPrice(int priceToUpgrade, int oneHouse, int secondHouse, int thirdHouse,
                                        int fourHouse) : priceToUpgrade(priceToUpgrade), oneHouse(oneHouse),
                                                         secondHouse(secondHouse), thirdHouse(thirdHouse),
                                                         fourHouse(fourHouse) {}

    int HousesPrice::getHouseRent(int numberOfHouse) const {
        if (numberOfHouse == 1) {
            return oneHouse;
        } else if (numberOfHouse == 2) {
            return secondHouse;
        } else if (numberOfHouse == 3) {
            return thirdHouse;
        } else {
            return fourHouse;
        }
    }

    std::ostream &operator<<(std::ostream &stream, const HousesPrice &housesPrice) {
        return stream << "Precios de las casas: Se inicia en una casa: " << housesPrice.oneHouse << ", "
                      << housesPrice.secondHouse << ", " << housesPrice.thirdHouse << ", "
                      << housesPrice.fourHouse << ". El precio sube " << housesPrice.priceToUpgrade;
    }

    int HousesPrice::getPriceToUpgrade() const {
        return priceToUpgrade;
    }
}
