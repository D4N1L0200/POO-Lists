#pragma once

#include <ctime>
#include <stdexcept>
#include <string>
#include <sstream>
#include <iomanip>
#include <array>

using std::string;

class Patient {
private:
    string name;
    string cpf;
    string phone;
    std::tm birthdate;

public:
    Patient(string name, string cpf, string phone, std::tm birthdate);
    ~Patient() = default;

    static std::array<int, 3> getDateDifference(std::tm birthdate);

    void setName(string name);
    void setCpf(string cpf);
    void setPhone(string phone);
    void setBirthdate(std::tm birthdate);

    string getName();
    string getCpf();
    string getPhone();
    std::tm getBirthdate();
    string getBirthdateFormatted();
    string getAge();
    string getInfo();
};
