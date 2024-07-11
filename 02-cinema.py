from datetime import time


class Entry:
    __available_days = ["segunda", "terça", "quarta", "quinta", "sexta", "sábado", "domingo"]

    def __init__(self, day, entry_time, is_student):
        self.__day = ""
        self.set_day(day)
        self.__time = entry_time
        self.__is_student = is_student

    def set_day(self, day):
        day = day.lower()
        if day in self.__available_days:
            self.__day = day
        else:
            raise ValueError("Dia não existente.")
        
    def get_day(self):
        return self.__day

    def set_time(self, time):
        self.__time = time
        
    def get_time(self):
        return self.__time.strftime("%H:%M")

    def set_student(self, is_student):
        self.__is_student = is_student
        
    def get_student(self):
        return self.__is_student

    def get_price(self):
        if self.__day == "quarta":
            return 8.0
        price = 16.0 if self.__day in ["segunda", "terça", "quinta"] else 20.0
        if 17 <= self.__time.hour:
            price *= 1.5
        if self.__is_student:
            price *= 0.5
        return price

    def __str__(self):
        return f"O preço do ingresso para {self.__day} de {self.get_time()} e{'' if self.__is_student else ' não'} estudante é R${self.get_price()}"



entry = Entry("Segunda", time(12, 10), True)
entry.set_day("Sexta")
entry.set_time(time(17, 30))
entry.set_student(False)
print(entry) # O preço do ingresso para sexta de 17:30 e não estudante é R$30.0
