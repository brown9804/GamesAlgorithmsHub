
#ifndef MONOPOLY_MONEY_H
#define MONOPOLY_MONEY_H

#include <iostream>

namespace Player {

    class Money {
    private:
        std::string owner;
        double balance;
    public:
        Money(std::string owner, double balance);

        double getBalance() const;

        void addBalance(double amount);

        void subtractBalance(double amount);
    };
}
#endif
