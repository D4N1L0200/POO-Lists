from math import pi


class Circle:
    def __init__(self, radius):
        self.radius = radius

    def calc_area(self):
        return pi * self.radius**2

    def calc_circumference(self):
        return 2 * pi * self.radius


circle = Circle(3)
print(f"A: {circle.calc_area():.2f}m²")  # A: 28.27m²
print(f"C: {circle.calc_circumference():.2f}m")  # C: 18.85m
