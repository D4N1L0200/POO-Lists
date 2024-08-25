#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "json.hpp"

using json = nlohmann::json;
using std::string;
using std::to_string;
using std::vector;

class Client
{
private:
    int id;
    string name;

public:
    Client(int id, string name) : id(id), name(name) {}
    ~Client() {}

    int getId()
    {
        return this->id;
    }

    string getName()
    {
        return this->name;
    }

    string getPrintable()
    {
        return this->name + " (" + to_string(this->id) + ")";
    }

    void setName(string name)
    {
        this->name = name;
    }
};

namespace Clients
{
    vector<Client> clients = {};

    void insert(Client client)
    {
        clients.push_back(client);
    }

    vector<Client> *getClients()
    {
        return &clients;
    }

    int getIdxById(int id)
    {
        for (int i = 0; i < clients.size(); i++)
        {
            if (clients[i].getId() == id)
                return i;
        }

        throw;
    }

    Client *getClientById(int id)
    {
        int idx = getIdxById(id);

        return &clients[idx];
    }

    void update(int id, Client client)
    {
        int idx = getIdxById(id);

        clients[idx] = client;
    }

    void deleteById(int id)
    {
        int idx = getIdxById(id);

        clients.erase(clients.begin() + idx);
    }

    void print()
    {
        for (Client c : clients)
            std::cout << c.getPrintable() << std::endl;
    }
}

int main()
{
    {
        Client del(44, "Del");
        Client dan(16, "Dan");

        Clients::insert(del);
        Clients::insert(dan);
    }

    Clients::print();

    std::cout << std::endl;

    {
        Client del = *Clients::getClientById(44);

        del.setName("Dani");

        Clients::update(44, del);
    }

    Clients::deleteById(16);

    Clients::print();

    // std::ifstream f("clients.json");
    // json data = json::parse(f);

    // // create a JSON object
    // json j = {
    //     {"pi", 3.141},
    //     {"happy", true},
    //     {"name", "Niels"},
    //     {"nothing", nullptr},
    //     {
    //         "answer", {
    //             {"everything", 42}
    //         }
    //     },
    //     {"list", {1, 0, 2}},
    //     {
    //         "object", {
    //             {"currency", "USD"},
    //             {"value", 42.99}
    //         }
    //     }
    // };

    // add new values
    // data["new"]["key"]["value"] = {"another", "list"};

    // count elements
    // auto s = data.size();
    // data["size"] = s;

    // pretty print with indent of 4 spaces
    // std::cout << std::setw(4) << data << '\n';
}