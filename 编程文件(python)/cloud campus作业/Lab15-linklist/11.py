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
class LinkedList:
    def __init__(self):
        self.__head = None

    def add(self, value):
        new_node = Node(value)
        new_node.set_next(self.__head)
        self.__head = new_node

    def size(self):
        count = 0
        current = self.__head
        while current is not None:
            count += 1
            current = current.get_next()
        return count

    def get_head(self):
        return self.__head
    
    def clear(self):
        self.__head=None
    def is_empty(self):
        if self.__head==None:
            return True
        else:
            return False
    def __len__(self):
        count = 0
        current = self.__head
        while current is not None:
            count += 1
            current = current.get_next()
        return count

    def __str__(self):
        values = []
        current = self.__head
        while current is not None:
            values+=[str(current.get_data())]
            current = current.get_next()
        return '[' + ', '.join(values) + ']'
    def __contains__(self, search_value):
        cur=self.__head
        while cur :
            if cur.get_data()==search_value:
                return True
            else:
                cur=cur.get_next()
        return False
    def __getitem__(self, index):
        cur=self.__head
        cou=0
        while cou!=index:
            cur=cur.get_next()
            cou+=1
        return cur.get_data()
    def add_all(self, a_list):
        for i in a_list:
            self.add(i)
    def get_min_odd(self):
        min=999
        cur=self.__head
        while cur:
            if cur.get_data()%2!=0 and cur.get_data()<min:
                min =cur.get_data()
            cur=cur.get_next()
        return min
    def reverse(self):
        pre=None
        cur=self.__head
        while cur :
            tem=cur.get_next()
            cur.set_next(pre)
            pre=cur
            cur=tem
        self.__head = pre
    def __iter__(self):
        return LinkedListIterator(self.__head)
class LinkedListIterator:
    def __init__(self, head):
        self.__head=head
        self.__current=self.__head
    def __next__(self):
        if self.__current:
          tem=self.__current.get_data()
          self.__current=self.__current.get_next()
          return tem
        else:
            raise StopIteration
values = LinkedList()
values.add('cherry')
values.add('banana')
values.add('apple')
for value in values:
    print(value)
