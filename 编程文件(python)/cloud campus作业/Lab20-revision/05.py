class Dealership:
    def __init__(self, name):
        self.__name = name
        self.__stock = []

    def get_name(self):
        return self.__name

    def add_car(self, car):
        if isinstance(car, Car):
            self.__stock.append(car)
        else:
            raise ValueError("This dealership only sells cars!")

    def total_value_of_stock(self):
        total_value = 0
        for car in self.__stock:
            total_value += car.get_price()
        return total_value

