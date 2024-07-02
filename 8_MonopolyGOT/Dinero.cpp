
#include "Dinero.h"
#include "LeeDigitado.h"
#include "SinExcepcionesDinero.h"
using namespace Exception;

Player::Money::Money(std::string owner, double balance) : owner(owner), balance(balance) {}

double Player::Money::getBalance() const {
    return balance;
}

void Player::Money::addBalance(double amount) {
    std::cout << owner << " su dinero es: " << balance << ". Se agregará: " << amount << std::endl;
    Money::balance += amount;
}

void Player::Money::subtractBalance(double amount) {
    double checkIfInDebt = getBalance() - amount;
    if (checkIfInDebt < 0) {
        throw NoMoneyException(amount);
    }
    std::cout << owner << " su dinero es: " << balance << ". Se restará: " << amount << std::endl;
    Money::balance -= amount;
}
