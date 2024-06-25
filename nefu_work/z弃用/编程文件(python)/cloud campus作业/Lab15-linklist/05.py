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
