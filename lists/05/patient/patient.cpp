#include "patient.hpp"

Patient::Patient(string name, string cpf, string phone, std::tm birthdate) {
    if (name.empty() || cpf.empty() || phone.empty()) {
        throw std::invalid_argument("Patient must have all fields filled");
    }

    this->setName(name);
    this->setCpf(cpf);
    this->setPhone(phone);
    this->setBirthdate(birthdate);
}

std::array<int, 3> Patient::getDateDifference(std::tm birthdate) {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int years = ltm->tm_year - birthdate.tm_year;
    int months = ltm->tm_mon - birthdate.tm_mon;
    int days = ltm->tm_mday - birthdate.tm_mday;
    if (days < 0) {
        months--;
        days += 30;
    }
    if (months < 0) {
        years--;
        months += 12;
    }

    return {years, months, days};
}

void Patient::setName(string name) {
    if (name.empty()) {
        throw std::invalid_argument("Patient must have a name");
    }

    this->name = name;
}

void Patient::setCpf(string cpf) {
    if (cpf.empty()) {
        throw std::invalid_argument("Patient must have a CPF");
    }

    this->cpf = cpf;
}

void Patient::setPhone(string phone) {
    if (phone.empty()) {
        throw std::invalid_argument("Patient must have a phone");
    }

    this->phone = phone;
}

void Patient::setBirthdate(std::tm birthdate) {
    std::array<int, 3> date = getDateDifference(birthdate);

    int years = date[0];
    int months = date[1];
    int days = date[2];

    if (years < 0 || months < 0 || days < 0) {
        throw std::invalid_argument("Patient must have a valid birthdate");
    }
    if (birthdate.tm_mon < 0 || birthdate.tm_mon > 11) {
        throw std::invalid_argument("Patient must have a valid birthdate");
    }
    if (birthdate.tm_mday < 1 || birthdate.tm_mday > 31) {
        throw std::invalid_argument("Patient must have a valid birthdate");
    }

    this->birthdate = birthdate;
}

string Patient::getName() {
    return this->name;
}

string Patient::getCpf() {
    return this->cpf;
}

string Patient::getPhone() {
    return this->phone;
}

std::tm Patient::getBirthdate() {
    return this->birthdate;
}

string Patient::getBirthdateFormatted() {
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << birthdate.tm_mday << "/"
       << std::setw(2) << std::setfill('0') << birthdate.tm_mon + 1 << "/"
       << birthdate.tm_year + 1900;
    return ss.str();
}

string Patient::getAge() {
    std::array<int, 3> date = getDateDifference(birthdate);

    int years = date[0];
    int months = date[1];
    int days = date[2];

    std::stringstream ss;
    ss << years << " years, " << months << " months and " << days << " days";
    return ss.str();
}

string Patient::getInfo() {
    return this->name + " - " + this->cpf +
           " - " + this->phone +
           " - " + this->getBirthdateFormatted() +
           " - " + this->getAge();
}
