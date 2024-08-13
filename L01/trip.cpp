#include <iostream>


class Trip
{
private:
    double distance;
    double minutes;

public:
    Trip(double distance, double hours, double minutes)
    {
        this->distance = distance;
        this->minutes = (hours * 60) + minutes;
    }
    ~Trip() {}

    double get_distance()
    {
        return distance;
    }

    double get_minutes()
    {
        return minutes;
    }

    double get_avg_speed()
    {
        return distance / (minutes / 60.0);
    }
};

int main()
{
    Trip trip(300, 4, 10);

    std::cout << trip.get_distance() << "Km in " << trip.get_minutes() << " minutes with an average speed of " << trip.get_avg_speed() << "Km/h." << std::endl;

    return 0;
}