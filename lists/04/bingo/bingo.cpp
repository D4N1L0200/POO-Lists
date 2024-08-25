#include "bingo.hpp"

Bingo::Bingo(int ballAmount) {
    this->balls.reserve(ballAmount);
    this->drawn.reserve(ballAmount);

    for (int i = 0; i < ballAmount; ++i) {
        this->balls.push_back(i + 1);
    }

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(balls.begin(), balls.end(), std::default_random_engine(seed));
}

int Bingo::next() {
    if (this->balls.empty())
        return -1;

    int ball = this->balls.back();
    this->balls.pop_back();
    this->drawn.push_back(ball);

    return ball;
}

std::vector<int> Bingo::getDrawn() {
    return this->drawn;
}
