#include <iostream>

#include "bill.hpp"

int main() {
    Bill bill("675103265", std::tm(), std::tm(), 100.0f);

    std::cout  << bill.getInfo() << std::endl;

    bill.pay(25.0f);

    std::cout  << bill.getInfo() << std::endl;

    bill.pay(75.0f);

    std::cout  << bill.getInfo() << std::endl;

    return 0;
}
