#include <iostream>
#include <string>

#include <sstream>
#include <iomanip>

using std::string;

class Time
{
public:
    int hours;
    int minutes;

    Time() : hours(0), minutes(0) {}
    Time(int hours, int minutes)
    {
        if (0 <= hours <= 24 and 0 <= minutes <= 60)
        {
            this->hours = hours;
            this->minutes = minutes;
        }
        else
            throw;
    }
    ~Time() {}
};

class Entry
{
private:
    string day;
    Time time;
    bool is_student;

public:
    Entry(string day, Time time, bool is_student)
    {
        this->day = day;
        this->time = time;
        this->is_student = is_student;
    }
    ~Entry() {}

    string get_day()
    {
        return this->day;
    }

    Time get_time()
    {
        return this->time;
    }

    int get_hour()
    {
        return this->time.hours;
    }

    int get_minutes()
    {
        return this->time.minutes;
    }

    bool get_is_student()
    {
        return this->is_student;
    }

    string get_formatted_time()
    {
        std::ostringstream oss;

        oss << std::setfill('0') << std::setw(2) << this->time.hours << ":"
            << std::setfill('0') << std::setw(2) << this->time.minutes;

        return oss.str();
    }

    double get_price()
    {
        if (this->day == "Wednesday")
            return 8.0;

        double price = 0;

        if (this->day == "Monday" or this->day == "Tuesday" or this->day == "Thursday")
            price = 16.0;
        else
            price = 20.0;

        if (this->time.hours >= 17)
            price *= 1.5;

        if (this->is_student)
            price *= 0.5;

        return price;
    }
};

void test_entry(string weekday, Time time, bool is_student)
{
    Entry entry(weekday, time, is_student);

    string student = "";

    if (!entry.get_is_student())
        student = " not";

    std::cout
        << "The price for " << entry.get_day()
        << " at " << entry.get_formatted_time()
        << " and" << student
        << " student is R$" << entry.get_price() << std::endl;
}

int main()
{
    test_entry("Monday", Time(12, 10), true);     // 8.0
    test_entry("Tuesday", Time(12, 10), false);   // 16.0
    test_entry("Thursday", Time(17, 30), true);   // 12.0
    test_entry("Monday", Time(17, 30), false);    // 24.0
    test_entry("Wednesday", Time(12, 10), true);  // 8.0
    test_entry("Wednesday", Time(17, 30), false); // 8.0
    test_entry("Friday", Time(12, 10), true);     // 10.0
    test_entry("Saturday", Time(12, 10), false);  // 20.0
    test_entry("Saturday", Time(17, 30), true);   // 15.0
    test_entry("Sunday", Time(17, 30), false);    // 30.0

    return 0;
}