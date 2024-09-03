from datetime import datetime
import json


class Game:
    def __init__(self, g_id: int, name: str, company: str, date: datetime):
        self.__id = 0
        self.__name = ""
        self.__company = ""
        self.__date = datetime.now()

        self.set_id(g_id)
        self.set_name(name)
        self.set_company(company)
        self.set_date(date)

    def set_id(self, g_id: int):
        if g_id and isinstance(g_id, int):
            self.__id = g_id

    def set_name(self, name: str):
        if name and isinstance(name, str):
            self.__name = name

    def set_company(self, company: str):
        if company and isinstance(company, str):
            self.__company = company

    def set_date(self, date: datetime):
        if date and isinstance(date, datetime):
            self.__date = date

    def get_id(self):
        return self.__id

    def get_name(self):
        return self.__name

    def get_company(self):
        return self.__company

    def get_date(self):
        return self.__date

    def __str__(self):
        return f"{self.get_id()} - {self.get_name()} - {self.get_company()} - {self.get_date().strftime("%d/%m/%Y")}"


class Games:
    games: list[Game] = []

    @classmethod
    def load_games(cls):
        cls.games = []
        try:
            with open("games.json", "r") as f:
                games = json.load(f)
        except FileNotFoundError:
            return

        for g_id, g in games.items():
            game = Game(
                int(g_id),
                g["name"],
                g["company"],
                datetime.strptime(g["date"], "%d/%m/%Y"),
            )
            cls.games.append(game)

    @classmethod
    def save_games(cls):
        data = {}
        cls.games.sort(key=lambda g: g.get_id())
        for g in cls.games:
            data[g.get_id()] = {
                "name": g.get_name(),
                "company": g.get_company(),
                "date": g.get_date().strftime("%d/%m/%Y"),
            }

        with open("games.json", "w") as f:
            json.dump(data, f)

    @classmethod
    def add_game(cls, game: Game):
        cls.games.append(game)
        print("\tAdded game:")
        print(game)
        cls.save_games()

    @classmethod
    def list_games(cls):
        if not cls.games:
            print("No games found.")
            return

        print("\tID - Name - Company - Date")
        for g in cls.games:
            print(g)

    @classmethod
    def list_games_by_id(cls, g_id: int):
        if not cls.games:
            print("No games found.")
            return

        for g in cls.games:
            if g.get_id() == g_id:
                print("\tID - Name - Company - Date")
                print(g)
                return

        print("Game not found.")

    @classmethod
    def list_games_by_company(cls, company: str):
        if not cls.games:
            print("No games found.")
            return

        company_games = []
        for g in cls.games:
            if g.get_company() == company:
                company_games.append(g)

        if not company_games:
            print("No games found.")
            return

        print("\tID - Name - Company - Date")
        for g in company_games:
            print(g)

    @classmethod
    def list_games_by_date(cls):
        if not cls.games:
            print("No games found.")
            return

        cls.games.sort(key=lambda g: g.get_date())

        print("\tID - Name - Company - Date")
        for g in cls.games:
            print(g)

        cls.games.sort(key=lambda g: g.get_id())

    @classmethod
    def update_game(cls, game: Game):
        if not cls.games:
            print("No games found.")
            return

        for g in cls.games:
            if g.get_id() == game.get_id():
                g.set_name(game.get_name())
                g.set_company(game.get_company())
                g.set_date(game.get_date())
                print("\tUpdated game:")
                print(game)
        cls.save_games()

    @classmethod
    def delete_game(cls, g_id: int):
        if not cls.games:
            print("No games found.")
            return

        for g in cls.games:
            if g.get_id() == g_id:
                cls.games.remove(g)
                print("\tDeleted game:")
                print(g)
                cls.save_games()
                return

        print("Game not found.")


class UI:
    @staticmethod
    def main():
        Games.load_games()

        while True:
            op = UI.menu()
            if op == 1:
                UI.add_game()
            if op == 2:
                UI.list_games()
            if op == 3:
                UI.list_games_by_id()
            if op == 4:
                UI.list_games_by_company()
            if op == 5:
                UI.list_games_by_date()
            if op == 6:
                UI.update_game()
            if op == 7:
                UI.delete_game()
            if op == 8:
                UI.create_example()
            if op == 9:
                break

    @staticmethod
    def menu():
        inp = 0
        while inp < 1 or inp > 9:
            inp = input(
                """
1 - Add game
2 - List games
3 - List games by id
4 - List games by company
5 - List games by release date
6 - Update game
7 - Delete game
8 - Create example JSON
9 - Exit
> """
            )

            if not inp.isdigit():
                print("Invalid input. Please enter a number.")
                inp = 0
            else:
                inp = int(inp)

        return inp

    @staticmethod
    def game_input():
        if not Games.games:
            next = 1
        else:
            next = Games.games[-1].get_id() + 1

        g_id = input(f"Id (Leave empty for {next}): ")

        if g_id == "":
            g_id = next
            print(f"Id set to {g_id}.")
        elif not g_id.isdigit():
            print("Invalid input. Id must be an integer.")
            return

        name = input("Name: ")

        if not name:
            print("Invalid input. Name cannot be empty.")
            return

        company = input("Company: ")

        if not company:
            print("Invalid input. Company cannot be empty.")
            return

        date = input("Date (DD/MM/YYYY): ")

        try:
            date = datetime.strptime(date, "%d/%m/%Y")
        except ValueError:
            print("Invalid date. Date must be in the format DD/MM/YYYY.")
            return

        return Game(int(g_id), name, company, date)

    @staticmethod
    def add_game():
        game = UI.game_input()

        if not game:
            return

        Games.add_game(game)

    @staticmethod
    def list_games():
        Games.list_games()

    @staticmethod
    def list_games_by_id():
        g_id = input("Id: ")

        if not g_id.isdigit():
            print("Id must be an integer.")
            return

        Games.list_games_by_id(int(g_id))

    @staticmethod
    def list_games_by_company():
        company = input("Company: ")

        if not company:
            print("Invalid input. Company cannot be empty.")
            return

        Games.list_games_by_company(company)

    @staticmethod
    def list_games_by_date():
        Games.list_games_by_date()

    @staticmethod
    def update_game():
        game = UI.game_input()

        if not game:
            return

        Games.update_game(game)

    @staticmethod
    def delete_game():
        g_id = input("id: ")

        if not g_id.isdigit():
            print("id must be an integer")
            return

        Games.delete_game(int(g_id))

    @staticmethod
    def create_example():
        example = {
            "1": {"name": "God of War", "company": "Capcom", "date": "17/03/2007"},
            "2": {"name": "God of War 2", "company": "Capcom", "date": "28/04/2013"},
            "3": {"name": "God of War 3", "company": "Capcom", "date": "04/11/2010"},
            "4": {"name": "Minecraft", "company": "Mojang", "date": "10/07/2010"},
            "5": {"name": "Terraria", "company": "ReLogic", "date": "22/06/2004"},
            "6": {
                "name": "Minecraft Legends",
                "company": "Mojang",
                "date": "06/02/2022",
            },
        }

        with open("games.json", "w") as f:
            json.dump(example, f, indent=4)

        Games.load_games()

        print("Example JSON created and loaded.")


if __name__ == "__main__":
    print("\tTry '8' first to create some games.")
    UI.main()
