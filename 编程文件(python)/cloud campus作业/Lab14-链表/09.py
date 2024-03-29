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
    def __contains__(self, value):
        p=self
        while(p):#when the next is not empty
            if p.get_data() ==value:
                return True
            p=p.get_next()
        return False
    def get_sum(self):
        sum=0
        p=self
        while(p):
            sum=sum+p.get_data()
            p=p.get_next()
        return sum
def print_node_chain(node_of_chain):
    dum=node_of_chain
    while(dum):
        print(dum.get_data())
        dum=dum.get_next()
def create_node_chain(values):
    first=Node(values.pop(0))
    p=first
    while(values):
        p.set_next(Node(values.pop(0)))
        p=p.get_next()
    return first
def convert_to_list(first_node):
    res=[]
    k=first_node
    while(k):
        res.append(k.get_data())
        k=k.get_next()
    return res
node1 = Node('hello')
node2 = Node('world')
node3 = Node('goodbye')
node1.set_next(node2)
node2.set_next(node3)
print_node_chain(node1)
a_list = convert_to_list(node1)
a_list.append(100)
print_node_chain(node1)
print(a_list)
