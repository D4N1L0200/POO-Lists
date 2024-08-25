#include <iostream>

const double pi = 3.1415926535897932384626433832795;

class Circle
{
private:
    double radius;
public:
    Circle(double radius) {
        this->radius = radius;
    }
    ~Circle() {}

    double get_area() {
        return pi * radius * radius;
    }

    double get_circumference() {
        return 2 * pi * radius;
    }
};

int main()
{
    Circle circle(3);

    std::cout << "A: " << circle.get_area() << "m^2" << std::endl;
    std::cout << "C: " << circle.get_circumference() << "m" << std::endl;

    return 0;
}
