from math import pi


class Circle:
    def __init__(self, radius):
        self.__radius = 0
        self.set_radius(radius)

    def set_radius(self, radius):
        if radius > 0:
            self.__radius = radius
        else:
            raise ValueError("O raio deve ser maior que zero.")

    def get_radius(self):
        return self.__radius

    def calc_area(self):
        return pi * self.__radius**2

    def calc_circumference(self):
        return 2 * pi * self.__radius


circle = Circle(3)
circle.set_radius(5)
print(f"R: {circle.get_radius()}m") # 5m
