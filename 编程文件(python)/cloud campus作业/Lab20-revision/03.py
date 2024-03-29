class Stack:
    def __init__(self):
        self.__items = []
    def is_empty(self):
        return self.__items == []
    def push(self, item):
        self.__items.append(item)                
    def pop(self):
        if self.is_empty():
            raise IndexError('The stack is empty!')
        return self.__items.pop()
    def peek(self):
        if self.is_empty():
            raise IndexError('The stack is empty!')
        return self.__items[len(self.__items) - 1]
    def size(self):
        return len(self.__items)        
    def __str__(self):
        return 'Stack: ' + str(self.__items)
def longest_valid_brackets(my_string):
    stack = Stack()
    max_length = 0
    current_length = 0

    for i in range(len(my_string)):
        if my_string[i] == "(":
            stack.push(i)
        elif my_string[i] == ")":
            if not stack.is_empty():
                opening_index = stack.pop()
                current_length = i - opening_index + 1
                max_length = max(max_length, current_length)
            else:
                current_length = 0

    if max_length == 0:
        return -1
    else:
        return max_length - 2  
