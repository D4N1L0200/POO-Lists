#include "bill.hpp"

Bill::Bill(string barcode, std::tm emissionDate, std::tm expiryDate, float price) {
    this->barcode = barcode;
    this->emissionDate = emissionDate;
    this->expiryDate = expiryDate;
    this->price = price;
    this->paid = 0.0f;
    this->status = UNPAID;
}

void Bill::pay(float value) {
    int remaining = this->price - this->paid;

    if (this->status != PAID) {
        this->paid += value;

        if (value < remaining) {
            this->status = PAYING;
        } else if (value == remaining) {
            this->status = PAID;
        } else {
            this->status = OVERPAID;
        }
    }
}

string Bill::getPaid() {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << this->paid;
    return ss.str();
}

string Bill::getPrice() {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << this->price;
    return ss.str();
}

string Bill::getStatus() {
    switch (this->status) {
        case UNPAID:
            return "Unpaid";
        case PAYING:
            return "Paying";
        case PAID:
            return "Paid";
        case OVERPAID:
            return "Overpaid";
        default:
            return "Unknown";
    }
}

string Bill::getInfo() {
    return "(" + this->barcode + ") " +
           this->getPaid() + "/" + this->getPrice() + " [" + this->getStatus() + "]";
}
