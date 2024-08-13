from datetime import time


class Entry:
    def __init__(self, day, entry_time, is_student):
        self.day = day.lower()
        self.time = entry_time
        self.is_student = is_student

    def get_price(self):
        if self.day == "quarta":
            return 8.0
        price = 16.0 if self.day in ["segunda", "terça", "quinta"] else 20.0
        if 17 <= self.time.hour:
            price *= 1.5
        if self.is_student:
            price *= 0.5
        return price


def test_entry(day, entry_time, is_student):
    entry = Entry(day, entry_time, is_student)
    print(
        f"O preço do ingresso para {entry.day} de {entry.time.strftime("%H:%M")} e{"" if entry.is_student else " não"} estudante é R${entry.get_price()}"
    )


test_entry("Segunda", time(12, 10), True)  # 8.0
test_entry("Terça", time(12, 10), False)  # 16.0
test_entry("Quinta", time(17, 30), True)  # 12.0
test_entry("Segunda", time(17, 30), False)  # 24.0
test_entry("Quarta", time(12, 10), True)  # 8.0
test_entry("Quarta", time(17, 30), False)  # 8.0
test_entry("Sexta", time(12, 10), True)  # 10.0
test_entry("Sábado", time(12, 10), False)  # 20.0
test_entry("Sábado", time(17, 30), True)  # 15.0
test_entry("Domingo", time(17, 30), False)  # 30.0
