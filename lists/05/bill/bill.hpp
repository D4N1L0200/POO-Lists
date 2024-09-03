#pragma once

#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>

using std::string;

enum BillStatus {
    UNPAID,
    PAYING,
    PAID,
    OVERPAID
};

class Bill {
private:
    string barcode;
    std::tm emissionDate;
    std::tm expiryDate;
    std::tm payDate;
    float price;
    float paid;
    BillStatus status;

public:
    Bill(string barcode, std::tm emissionDate, std::tm expiryDate, float price);
    ~Bill() = default;

    void pay(float value);
    string getPrice();
    string getPaid();
    string getStatus();
    string getInfo();
};
