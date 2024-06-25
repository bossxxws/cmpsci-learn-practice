class Queue:
    def __init__(self):
        self.__items = []

    def is_empty(self):
        return self.__items == []

    def enqueue(self, item):
        self.__items.append(item)

    def dequeue(self):
        if self.is_empty():
            raise IndexError("ERROR: The queue is empty!")
        return self.__items.pop(0)

    def size(self):
        return len(self.__items)

    def peek(self):
        if self.is_empty():
            raise IndexError("ERROR: The queue is empty!")
        return self.__items[len(self.__items) - 1]

    def __str__(self):
        return "Queue: {}".format(self.__items)

    def __len__(self):
        return len(self.__items)

    def clear(self):
        self.__items = []