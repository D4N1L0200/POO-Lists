from math import pi
import math


class Rectangle:
    def __init__(self, base, height):
        self.__base = 0
        self.__height = 0
        self.set_base(base)
        self.set_height(height)

    def set_base(self, base):
        if base > 0:
            self.__base = base
        else:
            raise ValueError("A base deve ser maior que zero.")

    def set_height(self, height):
        if height > 0:
            self.__height = height
        else:
            raise ValueError("A altura deve ser maior que zero.")

    def get_base(self):
        return self.__base

    def get_height(self):
        return self.__height

    def calc_area(self):
        return self.__base * self.__height

    def calc_diagonal(self):
        return math.sqrt(self.__base ** 2 + self.__height ** 2)


rectangle = Rectangle(6, 8)
print(f"D: {rectangle.calc_diagonal()}m")
