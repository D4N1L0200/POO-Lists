class Trip:
    def __init__(self, distance, hours, minutes):
        self.distance = distance
        self.minutes = minutes + hours * 60

    def calc_avg(self):
        return self.distance / (self.minutes / 60)


trip = Trip(300, 4, 10)
print(
    f"{trip.distance}Km em {trip.minutes} minutos com uma velocidade media de {trip.calc_avg()}Km/h."
)  # 300Km em 250 minutos com uma velocidade media de 72.0Km/h.
