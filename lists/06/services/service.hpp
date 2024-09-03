#pragma once

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "json.hpp"

using std::string;
using std::to_string;
using std::vector;
using json = nlohmann::json;

class Service {
private:
    int id;
    string description;
    double value;
    int duration;

public:
    Service(int id, string description, double value, int duration);
    ~Service() = default;

    int getId();
    string getDescription();
    double getValue();
    int getDuration();
    string getPrintable();
    void setId(int id);
    void setDescription(string description);
    void setValue(double value);
    void setDuration(int duration);
};

namespace Services {
    extern vector<Service> Services;

    void insert(Service Service);
    vector<Service> *getServices();
    int getServicesSize();
    bool existsById(int id);
    int getIdxById(int id);
    Service *getServiceById(int id);
    void update(int id, Service Service);
    void deleteById(int id);
    void print();
    void load();
    void save();
} // namespace Services