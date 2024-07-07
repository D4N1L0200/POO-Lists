class Account:
    next_id = 1

    def __init__(self, name):
        self.name = name
        self.uid = self.next_id
        Account.next_id += 1
        self.balance = 0

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount

    def withdraw(self, amount):
        if self.balance > amount > 0:
            self.balance -= amount

    def __str__(self):
        return f"{self.name.title()} (ID {self.uid}): R${self.balance:.2f}"


account = Account("Del")
account.deposit(200)
account.withdraw(150)
print(account)  # Del (ID 1): R$50.00

other = Account("Other")
print(other)  # Other (ID 2): R$0.00
