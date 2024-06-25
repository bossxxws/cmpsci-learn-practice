class Stack:
    def __init__(self,k=[]):
        self.__items = k

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
    def push_list(self, a_list):
        while(a_list):
            self.__items.append(a_list[0])
            a_list.pop(0)
    def multi_pop(self, number):
        if self.__len__()>=number:
            while(number>0):
                self.__items.pop()
                number=number-1
            return True
        else:
            return False
    def copy(self):
        s=[]
        for i in range(self.__len__()):
            s.append(self.__items[i])
        a=Stack(s)
        return a
    def __str__(self):
        return f"Stack: {self.__items}"
my_stack = Stack()
for i in range(4,7):
    my_stack.push(i)
result = my_stack.copy()
result.push('s')
print(my_stack)
print(result)