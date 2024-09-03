#include <iostream>
#include <limits>
#include <string>

#include "client.hpp"
#include "service.hpp"

using std::string;

namespace IOUtil {
    static int inputIntMinMax(string prompt, int min, int max) {
        int inp;

        while (true) {
            std::cout << prompt;
            std::cin >> inp;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number.\n";
            } else {
                if (inp < min || inp > max) {
                    std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
                } else {
                    break;
                }
            }
        }

        return inp;
    }

    static int inputInt(string prompt) {
        int inp;

        while (true) {
            std::cout << prompt;
            std::cin >> inp;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number.\n";
            } else {
                break;
            }
        }

        return inp;
    }

    static double inputDouble(string prompt) {
        double inp;

        while (true) {
            std::cout << prompt;
            std::cin >> inp;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number.\n";
            } else {
                break;
            }
        }

        return inp;
    }

    static string inputStr(string prompt) {
        string inp;

        while (true) {
            std::cout << prompt;
            std::cin >> inp;
            // std::getline(std::cin, inp);

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please try again.\n";
            } else {
                break;
            }
        }

        return inp;
    }
} // namespace IOUtil

namespace UI {
    namespace UIClient {
        static int menu() {
            return IOUtil::inputIntMinMax("\n\tClient Manager\n1 - Create Client\n2 - Get Clients\n3 - Get Client By ID\n4 - Update Client\n5 - Delete Client\n6 - Exit\n> ", 1, 6);
        }

        static void main() {
            Clients::load();

            int op;
            while (op != 6) {
                op = menu();
                if (op == 1) {
                    std::cout << "\n\tClient Creator" << std::endl;
                    int id = IOUtil::inputInt("ID: ");
                    string name = IOUtil::inputStr("Name: ");
                    string email = IOUtil::inputStr("Email: ");
                    string phone = IOUtil::inputStr("Phone: ");

                    if (Clients::existsById(id)) {
                        std::cout << "Client already exists" << std::endl;
                        continue;
                    }

                    Client client = Client(id, name, email, phone);

                    Clients::insert(client);

                } else if (op == 2) {
                    int clientSize = Clients::getClientsSize();
                    if (clientSize == 0) {
                        std::cout << "No clients found" << std::endl;
                        continue;
                    }

                    std::cout << "\n\tClients" << std::endl;
                    Clients::print();

                } else if (op == 3) {
                    int clientSize = Clients::getClientsSize();
                    if (clientSize == 0) {
                        std::cout << "No clients found" << std::endl;
                        continue;
                    }

                    int id = IOUtil::inputInt("ID: ");

                    if (!Clients::existsById(id)) {
                        std::cout << "Client not found" << std::endl;
                        continue;
                    }

                    Client client = *Clients::getClientById(id);
                    std::cout << client.getPrintable() << std::endl;

                } else if (op == 4) {
                    int clientSize = Clients::getClientsSize();
                    if (clientSize == 0) {
                        std::cout << "No clients found" << std::endl;
                        continue;
                    }

                    int id = IOUtil::inputInt("ID: ");

                    if (!Clients::existsById(id)) {
                        std::cout << "Client not found" << std::endl;
                        continue;
                    }

                    Client client = *Clients::getClientById(id);

                    std::cout << "\n\tClient Updater" << std::endl;
                    string name = IOUtil::inputStr("Name: ");
                    string email = IOUtil::inputStr("Email: ");
                    string phone = IOUtil::inputStr("Phone: ");

                    client.setName(name);
                    client.setEmail(email);
                    client.setPhone(phone);

                    Clients::update(id, client);

                } else if (op == 5) {
                    int clientSize = Clients::getClientsSize();
                    if (clientSize == 0) {
                        std::cout << "No clients found" << std::endl;
                        continue;
                    }

                    int id = IOUtil::inputInt("ID: ");

                    if (!Clients::existsById(id)) {
                        std::cout << "Client not found" << std::endl;
                        continue;
                    }

                    Client client = *Clients::getClientById(id);
                    std::cout << "Deleting Client:\n"
                              << client.getPrintable() << std::endl;
                    Clients::deleteById(id);

                } else if (op == 6) {
                    break;
                }
            }
        }
    } // namespace UIClient

    namespace UIService {
        static int menu() {
            return IOUtil::inputIntMinMax("\n\tService Manager\n1 - Create Service\n2 - Get Services\n3 - Get Service By ID\n4 - Update Service\n5 - Delete Service\n6 - Exit\n> ", 1, 6);
        }
        static void main() {
            Services::load();

            int op;
            while (op != 6) {
                op = menu();
                if (op == 1) {
                    std::cout << "\n\tService Creator" << std::endl;
                    int id = IOUtil::inputInt("ID: ");
                    string name = IOUtil::inputStr("Description: ");
                    double email = IOUtil::inputDouble("Value (R$): ");
                    int phone = IOUtil::inputInt("Duration (Hrs): ");

                    if (Services::existsById(id)) {
                        std::cout << "Service already exists" << std::endl;
                        continue;
                    }

                    Service service = Service(id, name, email, phone);

                    Services::insert(service);

                } else if (op == 2) {
                    int ServiceSize = Services::getServicesSize();
                    if (ServiceSize == 0) {
                        std::cout << "No Services found" << std::endl;
                        continue;
                    }

                    std::cout << "\n\tServices" << std::endl;
                    Services::print();

                } else if (op == 3) {
                    int ServiceSize = Services::getServicesSize();
                    if (ServiceSize == 0) {
                        std::cout << "No Services found" << std::endl;
                        continue;
                    }

                    int id = IOUtil::inputInt("ID: ");

                    if (!Services::existsById(id)) {
                        std::cout << "Service not found" << std::endl;
                        continue;
                    }

                    Service Service = *Services::getServiceById(id);
                    std::cout << Service.getPrintable() << std::endl;

                } else if (op == 4) {
                    int ServiceSize = Services::getServicesSize();
                    if (ServiceSize == 0) {
                        std::cout << "No Services found" << std::endl;
                        continue;
                    }

                    int id = IOUtil::inputInt("ID: ");

                    if (!Services::existsById(id)) {
                        std::cout << "Service not found" << std::endl;
                        continue;
                    }

                    Service Service = *Services::getServiceById(id);

                    std::cout << "\n\tService Updater" << std::endl;
                    string description = IOUtil::inputStr("Description: ");
                    double value = IOUtil::inputDouble("Value (R$): ");
                    int duration = IOUtil::inputInt("Duration (Hrs): ");

                    Service.setDescription(description);
                    Service.setValue(value);
                    Service.setDuration(duration);

                    Services::update(id, Service);

                } else if (op == 5) {
                    int ServiceSize = Services::getServicesSize();
                    if (ServiceSize == 0) {
                        std::cout << "No Services found" << std::endl;
                        continue;
                    }

                    int id = IOUtil::inputInt("ID: ");

                    if (!Services::existsById(id)) {
                        std::cout << "Service not found" << std::endl;
                        continue;
                    }

                    Service Service = *Services::getServiceById(id);
                    std::cout << "Deleting Service:\n"
                              << Service.getPrintable() << std::endl;
                    Services::deleteById(id);

                } else if (op == 6) {
                    break;
                }
            }
        }
    } // namespace UIService

    namespace UIAppointment {
        static int menu() {
            return IOUtil::inputIntMinMax("\n\tAppointment Manager\n1 - Create Appointment\n2 - Get Appointments\n3 - Get Appointment By ID\n4 - Update Appointment\n5 - Delete Appointment\n6 - Exit\n> ", 1, 6);
        }
        static void main() {
            // Appointments::load();

            int op;
            while (op != 6) {
                op = menu();
                if (op == 1) {
                    std::cout << "Create Appointment" << std::endl;
                } else if (op == 2) {
                    std::cout << "Get Appointments" << std::endl;
                } else if (op == 3) {
                    std::cout << "Get Appointment By ID" << std::endl;
                } else if (op == 4) {
                    std::cout << "Update Appointment" << std::endl;
                } else if (op == 5) {
                    std::cout << "Delete Appointment" << std::endl;
                } else if (op == 6) {
                    break;
                }
            }
        }
    } // namespace UIAppointment

    static int menu() {
        return IOUtil::inputIntMinMax("\n\tMain UI\n1 - Client Manager\n2 - Service Manager\n3 - Appointment Manager\n4 - Exit\n> ", 1, 4);
    }

    static void main() {
        int op;
        while (op != 4) {
            op = menu();
            if (op == 1) {
                UIClient::main();
            } else if (op == 2) {
                UIService::main();
            } else if (op == 3) {
                UIAppointment::main();
            } else if (op == 4) {
                break;
            }
        }
    }
} // namespace UI
