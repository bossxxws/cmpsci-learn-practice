class Node:
    def __init__(self, data, next=None):
        self.__data = data
        self.__next = next

    def __str__(self):
        return str(self.__data)

    def get_data(self):
        return self.__data

    def get_next(self):
        return self.__next

    def set_data(self, new_data):
        self.__data = new_data

    def set_next(self, new_next):
        self.__next = new_next
    def add_after(self, value):
        newnode=Node(value)
        next=self.get_next()
        self.set_next(newnode)
        newnode.set_next(next)
    def remove_after(self):
        next=self.get_next().get_next()
        self.set_next(next)

node1 = Node('hello')
node2 = Node('world')
node3 = Node('happy')
node4 = Node('coding')
node1.set_next(node2)
node2.set_next(node3)
node3.set_next(node4)
node2.remove_after()
print(node1)
print(node1.get_next())
print(node1.get_next().get_next())