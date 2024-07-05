"""A classe deve ter atributos para armazenar a distância em km e o tempo gasto
em horas e minutos da viagem realizada. A classe deve possuir método para calcular
a velocidade média atingida na viagem em km/h de acordo com a distância e o tempo gasto."""


class Trip:
    """Class to represent a trip."""

    def __init__(
        self, distance: float, hours_spent: float, minutes_spent: float
    ) -> None:
        self.distance: float = distance
        self.minutes_spent: float = minutes_spent + hours_spent * 60

    def calc_average_speed(self) -> float:
        """Returns the average speed for the trip."""
        return self.distance / (self.minutes_spent / 60)


def test_trip(distance: float, hours_spent: float, minutes_spent: float) -> None:
    """Test the Trip class."""
    trip: Trip = Trip(distance, hours_spent, minutes_spent)
    print(f"Distance: {trip.distance}Km")
    print(f"Minutes spent: {trip.minutes_spent}min")
    print(f"Average Speed: {trip.calc_average_speed()}Km/h")
    print("\n")


if __name__ == "__main__":
    test_trip(5, 5, 0)
    test_trip(20, 0, 20)
    test_trip(300, 4, 10)
