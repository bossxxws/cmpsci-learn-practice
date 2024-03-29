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