#include "client.hpp"

Client::Client(int id, string name, string email, string phone) {
    this->setId(id);
    this->setName(name);
    this->setEmail(email);
    this->setPhone(phone);
}

int Client::getId() {
    return this->id;
}

string Client::getName() {
    return this->name;
}

string Client::getEmail() {
    return this->email;
}

string Client::getPhone() {
    return this->phone;
}

string Client::getPrintable() {
    return this->name + " (" + to_string(this->id) + ")" + " - " + this->email + " - " + this->phone;
}

void Client::setId(int id) {
    this->id = id;
}

void Client::setName(string name) {
    this->name = name;
}

void Client::setEmail(string email) {
    this->email = email;
}

void Client::setPhone(string phone) {
    this->phone = phone;
}

namespace Clients {
    std::vector<Client> clients = {};

    void insert(Client client) {
        clients.push_back(client);
        save();
    }

    vector<Client> *getClients() {
        return &clients;
    }

    int getClientsSize() {
        return clients.size();
    }

    bool existsById(int id) {
        for (Client c : clients) {
            if (c.getId() == id)
                return true;
        }

        return false;
    }

    int getIdxById(int id) {
        for (int i = 0; i < clients.size(); i++) {
            if (clients[i].getId() == id)
                return i;
        }

        throw;
    }

    Client *getClientById(int id) {
        int idx = getIdxById(id);

        return &clients[idx];
    }

    void update(int id, Client client) {
        int idx = getIdxById(id);

        clients[idx] = client;
        save();
    }

    void deleteById(int id) {
        int idx = getIdxById(id);

        clients.erase(clients.begin() + idx);
        save();
    }

    void print() {
        for (Client c : clients)
            std::cout << c.getPrintable() << std::endl;
    }

    void load() {
        std::ifstream f("lists/06/services/data/clients.json");

        if (!f.is_open()) {
            std::cerr << "Could not open the file!" << std::endl;
            return;
        }

        json data;

        try {
            data = json::parse(f);
        } catch (json::parse_error &e) {
            std::cerr << "Parse error: " << e.what() << std::endl;
            return;
        }

        for (json client : data) {
            Client c(client["id"], client["name"], client["email"], client["phone"]);
            Clients::insert(c);
        }
    }

    void save() {
        std::ofstream f("lists/06/services/data/clients.json");

        if (!f.is_open()) {
            std::cerr << "Could not open the file!" << std::endl;
            return;
        }

        json data;

        for (Client c : clients) {
            json cdata;
            cdata["id"] = c.getId();
            cdata["name"] = c.getName();
            cdata["email"] = c.getEmail();
            cdata["phone"] = c.getPhone();

            data[to_string(c.getId())] = cdata;
        }

        f << data.dump(4) << std::endl;
    }
} // namespace Clients
