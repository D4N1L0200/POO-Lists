#include <iostream>
#include <string>

using std::string;

class Account {
private:
    string name;
    int id;
    double balance;

    static int next_id;

public:
    Account(string name) {
        this->name = name;
        this->id = next_id;
        next_id++;
        this->balance = 0.0;
    }
    ~Account() {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }

    double get_balance() {
        return balance;
    }

    int get_id() {
        return id;
    }

    string get_name() {
        return name;
    }
};

void show_account(Account account) {
    std::cout << account.get_name() << " (ID " << account.get_id() << "): R$" << account.get_balance() << std::endl;
}

int Account::next_id = 1;

int main() {
    Account account("Del");

    show_account(account);

    account.deposit(200.0);
    account.withdraw(50.0);

    show_account(account);

    Account other("Other");

    show_account(other);

    return 0;
}
