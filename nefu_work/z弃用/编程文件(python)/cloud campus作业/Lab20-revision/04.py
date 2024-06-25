class Car:
    def __init__(self, make, model, year, price=10000):
        self.__make = make
        self.__model = model
        self.__year = year
        self.__price = price

    def __str__(self):
        return f"{self.__year} {self.__make} {self.__model}, ${self.__price}"

    def get_make(self):
        return self.__make

    def get_model(self):
        return self.__model

    def get_year(self):
        return self.__year

    def get_price(self):
        return self.__price

    def set_price(self, price):
        if price >= 0:
            self.__price = price


vitz = Car("Toyota", "Vitz", 2009, 8000)
print(vitz.get_make())
print(vitz.get_model())
print(vitz.get_year())
print(vitz.get_price())
vitz.set_price(0)
print(vitz.get_price())
vitz.set_price(12000)
print(vitz.get_price())