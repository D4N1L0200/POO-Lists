#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

class Bingo
{
private:
    std::vector<int> balls;
    std::vector<int> drawn;

public:
    Bingo(int ballAmount);
    ~Bingo() = default;

    int next();

    std::vector<int> getDrawn();
};