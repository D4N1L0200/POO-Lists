"""A classe deve ter atributos para armazenar o nome do titular da conta,
o número da conta e seu saldo e métodos para realizar as operações de depósito e saque.
Escrever um programa para testar a classe."""


class Account:
    """Class to represent a bank account."""

    next_id: int = 234

    def __init__(self, name: str) -> None:
        self.name: str = name
        self.uid: int = self.next_id
        Account.next_id += 1
        self.balance: float = 0

    def deposit(self, ammount: float) -> None:
        """Deposits a value into the account if it is valid (ammount > 0)."""
        if ammount <= 0:
            raise ValueError("Deposit value cannot be zero or less.")

        self.balance += ammount

    def withdraw(self, ammount: float) -> None:
        """Withdraws a value from the account if it is valid (ammount <= balance)."""
        if ammount <= 0:
            raise ValueError("Withdraw value cannot be zero or less.")
        if ammount > self.balance:
            raise ValueError(
                "Withdraw value cannot be greater than the account balance."
            )

        self.balance -= ammount


def test_account(name: str) -> None:
    """Test the Account class."""
    account: Account = Account(name)
    print(f"Name: {account.name.title()}")
    print(f"ID: {account.uid}")
    print(f"Balance: {account.balance}")

    try:
        print("Trying to withdraw 100.")
        account.withdraw(100)
    except ValueError:
        print("Could not withdraw from an empty balance.")

    try:
        print("Trying to withdraw 0.")
        account.withdraw(0)
    except ValueError:
        print("Could not withdraw zero.")

    try:
        print("Trying to withdraw -100.")
        account.withdraw(-100)
    except ValueError:
        print("Could not withdraw a negative value.")

    print("Depositing 200 to the balance.")
    account.deposit(200)
    print(f"Balance: {account.balance}")

    print("Withdrawing 150 from the balance.")
    account.withdraw(150)
    print(f"Balance: {account.balance}")

    try:
        print("Trying to deposit 0.")
        account.deposit(0)
    except ValueError:
        print("Could not deposit zero.")

    try:
        print("Trying to deposit -100.")
        account.deposit(-100)
    except ValueError:
        print("Could not deposit a negative value.")

    print("\n")

    print("Creating another account called 'Other'.")
    other_account: Account = Account("Other")
    print(f"{account.name}'s ID: {account.uid}")
    print(f"{other_account.name}'s ID: {other_account.uid}")


if __name__ == "__main__":
    test_account("Del")
