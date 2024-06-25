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
    def __len__(self):
        return len(self.__items)
    def clear(self):
        for i in range(self.__len__()):
            self.__items.pop()
    def __str__(self):
        return f"Stack: {self.__items}"
