class CircularQueue:
    def __init__(self, capacity=8):
        self.__items = [None] * capacity
        self.__front = 0
        self.__back = capacity - 1
        self.__count = 0

    def is_empty(self):
        return self.__count == 0

    def __str__(self):
        return f"{self.__items}, front:{self.__front}, back:{self.__back}, count:{self.__count}"