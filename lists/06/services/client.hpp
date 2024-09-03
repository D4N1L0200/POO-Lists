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

class Client {
private:
    int id;
    string name;
    string email;
    string phone;

public:
    Client(int id, string name, string email, string phone);
    ~Client() = default;

    int getId();
    string getName();
    string getEmail();
    string getPhone();
    string getPrintable();  
    void setId(int id);
    void setName(string name);
    void setEmail(string email);
    void setPhone(string phone);
};

namespace Clients {
    extern vector<Client> clients;

    void insert(Client client);
    vector<Client> *getClients();
    int getClientsSize();
    bool existsById(int id);
    int getIdxById(int id);
    Client *getClientById(int id);
    void update(int id, Client client);
    void deleteById(int id);
    void print();
    void load();
    void save();
} // namespace Clients