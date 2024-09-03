#include "Service.hpp"

Service::Service(int id, string description, double value, int duration) {
    this->setId(id);
    this->setDescription(description);
    this->setValue(value);
    this->setDuration(duration);
}

int Service::getId() {
    return this->id;
}

string Service::getDescription() {
    return this->description;
}

double Service::getValue() {
    return this->value;
}

int Service::getDuration() {
    return this->duration;
}

string Service::getPrintable() {
    return this->description + " (" + to_string(this->id) + ")" + " - R$" + to_string(this->value) + " / " + to_string(this->duration) + "h";
}

void Service::setId(int id) {
    this->id = id;
}

void Service::setDescription(string description) {
    this->description = description;
}

void Service::setValue(double value) {
    this->value = value;
}

void Service::setDuration(int duration) {
    this->duration = duration;
}

namespace Services {
    std::vector<Service> Services = {};

    void insert(Service Service) {
        Services.push_back(Service);
        save();
    }

    vector<Service> *getServices() {
        return &Services;
    }

    int getServicesSize() {
        return Services.size();
    }

    bool existsById(int id) {
        for (Service c : Services) {
            if (c.getId() == id)
                return true;
        }

        return false;
    }

    int getIdxById(int id) {
        for (int i = 0; i < Services.size(); i++) {
            if (Services[i].getId() == id)
                return i;
        }

        throw;
    }

    Service *getServiceById(int id) {
        int idx = getIdxById(id);

        return &Services[idx];
    }

    void update(int id, Service Service) {
        int idx = getIdxById(id);

        Services[idx] = Service;
        save();
    }

    void deleteById(int id) {
        int idx = getIdxById(id);

        Services.erase(Services.begin() + idx);
        save();
    }

    void print() {
        for (Service c : Services)
            std::cout << c.getPrintable() << std::endl;
    }

    void load() {
        std::ifstream f("lists/06/services/data/services.json");

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

        for (json service : data) {
            Service s(service["id"], service["description"], service["value"], service["duration"]);
            Services::insert(s);
        }
    }

    void save() {
        std::ofstream f("lists/06/services/data/Services.json");

        if (!f.is_open()) {
            std::cerr << "Could not open the file!" << std::endl;
            return;
        }

        json data;

        for (Service s : Services) {
            json sdata;
            sdata["id"] = s.getId();
            sdata["description"] = s.getDescription();
            sdata["value"] = s.getValue();
            sdata["duration"] = s.getDuration();

            data[to_string(s.getId())] = sdata;
        }

        f << data.dump(4) << std::endl;
    }
} // namespace Services
