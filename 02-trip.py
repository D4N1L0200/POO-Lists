class Trip:
    def __init__(self, distance, hours, minutes):
        self.__distance = 0
        self.set_distance(distance)
        self.__minutes = 0
        self.set_time(hours, minutes)

    def set_distance(self, distance):
        if distance > 0:
            self.__distance = distance
        else:
            raise ValueError("A distância deve ser maior que zero.")

    def set_time(self, hours=0, minutes=0):
        new_minutes = minutes + hours * 60
        if new_minutes > 0:
            self.__minutes = new_minutes
        else:
            raise ValueError("O tempo deve ser maior que zero.")

    def get_distance(self):
        return self.__distance

    def get_minutes(self):
        return self.__minutes

    def calc_avg(self):
        return self.__distance / (self.__minutes / 60)


trip = Trip(300, 4, 10)
trip.set_distance(400)
trip.set_time(hours=5, minutes=20)
print(f"Distância: {trip.get_distance()}Km") # Distância: 400Km
print(f"Minutos: {trip.get_minutes()}") # Minutos: 320
