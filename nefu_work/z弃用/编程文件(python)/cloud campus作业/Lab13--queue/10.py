class CircularQueue:
    def __init__(self, capacity=8):
        self.__items = [None] * capacity
        self.__front = 0
        self.__back = capacity - 1
        self.__count = 0

    def is_empty(self):
        return self.__count == 0

    def is_full(self):
        return self.__count == len(self.__items)

    def enqueue(self, item):
        if self.is_full():
            raise IndexError("ERROR: The queue is full.")

        self.__back = (self.__back + 1) % len(self.__items)
        self.__items[self.__back] = item
        self.__count += 1

    def dequeue(self):
        if self.is_empty():
            raise IndexError("ERROR: The queue is empty.")

        item = self.__items[self.__front]
        self.__front = (self.__front + 1) % len(self.__items)
        self.__count -= 1

        return item

    def print_all(self):
        if self.is_empty():
            return

        index = self.__front
        for _ in range(self.__count):
            print(self.__items[index], end=" ")
            index = (index + 1) % len(self.__items)
        print()

    def __str__(self):
        return f"{self.__items}, front:{self.__front}, back:{self.__back}, count:{self.__count}"