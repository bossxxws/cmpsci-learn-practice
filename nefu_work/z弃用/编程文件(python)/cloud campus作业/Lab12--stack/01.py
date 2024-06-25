class Stack:
    def __init__(self):
        self.__items = []

    def is_empty(self):
        return self.__items == []

    def push(self, item):
        self.__items.append(item)

    def pop(self):
        if Stack.is_empty(self):
            raise IndexError("ERROR: The stack is empty!")
        else:
            return self.__items.pop()

    def peek(self):
        if Stack.is_empty(self):
            raise IndexError("ERROR: The stack is empty!")
        return self.__items[len(self.__items) - 1]