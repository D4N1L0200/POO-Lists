#include <iostream>
#include <vector>

#include "bingo.hpp"

int main()
{
    int amount = 10;
    Bingo bingo(amount);

    bingo.next();
    for (int i = 0; i < bingo.getDrawn()[0] - 1; ++i)
    {
        bingo.next();
    }

    std::vector<int> drawn = bingo.getDrawn();

    std::cout << "Drawn: ";
    for (const auto& num : drawn) {
        std::cout << num;
        if (&num != &drawn.back()) {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;

    return 0;
}
