

#ifndef MONOPOLY_MORTGAGES_H
#define MONOPOLY_MORTGAGES_H


namespace Player {
    class Participant;
}

namespace GameBoard {

    class Mortgage {
    private:
        bool propertyMortgage = false;
        double mortgagePrice;
        const double INTEREST_PERCENTAGE = 1.1;
    public:
        Mortgage(double mortgagePrice);
        bool isPropertyMortgage() const;
        double getMortgagePrice() const;


        void makePropertyMortgage(Player::Participant* participant);

        void removeMortgage(Player::Participant* participant);
    };
}
#endif
