class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        self.count=0
    def get_data(self):
        return self.data
    def get_next(self):
        return self.next
    def set_data(self,new_data):
        self.data=new_data
    def set_next(self,new_next):
        self.next = new_next
    def count_node(self):
        cou=0
        cur=self
        while(cur):
            cou+=1
            cur=cur.get_next()
        return cou
    def get_size(self):
        size = 0
        current = self.head
        while current is not None:
            size += 1
            current = current.get_next()
        return size
def print_chain(Node):
    while not Node==None:
        print(Node.get_data(),end=" ")
        Node=Node.get_next()
    print()
n5=Node(15)
n6=Node(34)
n7=Node(12)
n8=Node(84)
n5.set_next(n6)
n6.set_next(n7)
n7.set_next(n8)
n5.set_next(None)
print_chain(n5)
print_chain(n8)
a,b,c = Node(1),Node(2),Node(3)
a.set_next(b)
b.set_next(c)
k=Node(None)
k.set_next(a)
sum=0
print(n6.count_node())
print(n6.get_size())
'''
while(k.next):
    k=k.get_next()
    v = k.get_data()
    sum=sum+v
print(sum)

'''