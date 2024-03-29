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
        return self.__items.pop()

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

    def enqueue_list(self, a_list):
        for item in a_list:
            self.enqueue(item)

    def multi_dequeue(self, number):
        if len(self.__items) >= number:
            for _ in range(number):
                self.dequeue()
            return True
        else:
            return False