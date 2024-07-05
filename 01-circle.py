"""A classe deve ter um atributo raio para armazenar a dimensão da figura e
métodos para calcular sua área e sua circunferência.
Escrever um programa para testar a classe."""

from math import pi


class Circle:
    """Class to represent a circle."""

    def __init__(self, radius: float) -> None:
        self.radius: float = radius

    def calc_area(self) -> float:
        """Returns the area of the circle."""
        return pi * self.radius**2

    def calc_circumference(self) -> float:
        """Returns the circumference of the circle."""
        return 2 * pi * self.radius


def test_circle(radius: float) -> None:
    """Test the Circle class."""
    circle: Circle = Circle(radius)
    print(f"Radius: {circle.radius}m")
    print(f"Area: {circle.calc_area()}m²")
    print(f"Circumference: {circle.calc_circumference()}m")
    print("\n")


if __name__ == "__main__":
    test_circle(1)
    test_circle(57)
    test_circle(324)
