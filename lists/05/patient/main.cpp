#include <iostream>

#include "patient.hpp"

std::tm createBD(std::array<int, 3> date) {
    std::tm birthdate = {};
    birthdate.tm_mday = date[0];
    birthdate.tm_mon = date[1] - 1;
    birthdate.tm_year = date[2] - 1900;

    return birthdate;
}

int main() {
    std::tm birthdate = createBD({1, 4, 2007});

    Patient patient("Del", "000.000.000-00", "+00 (00) 00000-0000", birthdate);

    std::cout << patient.getInfo() << std::endl;

    return 0;
}