class Account:
    __next_id = 1

    def __init__(self, name):
        self.__name = ""
        self.set_name(name)
        self.__id = self.__next_id
        Account.__next_id += 1
        self.__balance = 0

    def set_name(self, name):
        if name:
            self.__name = name
        else:
            raise ValueError("O nome não pode ser vazio.")

    def set_balance(self, balance):
        if balance >= 0:
            self.__balance = balance
        else:
            raise ValueError("O saldo não pode ser negativo.")

    def get_name(self):
        return self.__name

    def get_balance(self):
        return self.__balance

    def get_id(self):
        return self.__id

    def deposit(self, amount):
        if amount > 0:
            self.__balance += amount

    def withdraw(self, amount):
        if self.__balance > amount > 0:
            self.__balance -= amount

    def __str__(self):
        return f"{self.__name.title()} (ID {self.__id}): R${self.__balance:.2f}"


account = Account("Del")
account.set_name("Igor")
account.set_balance(150)
print(f"Nome: {account.get_name().title()}") # Nome: Igor
print(f"ID: {account.get_id()}") # ID: 1
print(f"Saldo: R${account.get_balance():.2f}") # Saldo: R$150.00
